/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
#include <string.h>
// SDK Included Files
#include "board.h"
#include "fsl_tpm_driver.h"
#include "fsl_debug_console.h"
#include "accel.h"
#include "gpio_pins.h"

//chemin vers le fichier qui contient les declarations des fonctions de l'utilisateurs
#include "C:\Freescale\KSDK_1.3.0\examples\frdmkl26z\demo_apps\bubble_level_tpm\kds\operations.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * @brief Main demo function.
 */

volatile bool isButtonPress = false;
/*!
 * @brief Interrupt service fuction of switch.
 *
 * This function toogles LED1
 */

int main(void) {

	tpm_general_config_t driverInfo;
	accel_dev_t accDev;
	accel_dev_interface_t accDevice;
	accel_sensor_data_t accelData;
	accel_i2c_interface_t i2cInterface;
	tpm_pwm_param_t yAxisParams;
	tpm_pwm_param_t xAxisParams;
	int16_t xData, yData;
	int16_t xAngle, yAngle;
	int16_t xAngleDutyCycle, yAngleDutyCycle;
	//gpio_input_pin_user_config_t boutton;
	xAxisParams.mode = kTpmEdgeAlignedPWM;
	xAxisParams.edgeMode = kTpmHighTrue;
	xAxisParams.uFrequencyHZ = 100000u;
	xAxisParams.uDutyCyclePercent = 0u;

	yAxisParams.mode = kTpmEdgeAlignedPWM;
	yAxisParams.edgeMode = kTpmHighTrue;
	yAxisParams.uFrequencyHZ = 100000u;
	yAxisParams.uDutyCyclePercent = 0u;

	// Register callback func for I2C
	i2cInterface.i2c_init = I2C_DRV_MasterInit;
	i2cInterface.i2c_read = I2C_DRV_MasterReceiveDataBlocking;
	i2cInterface.i2c_write = I2C_DRV_MasterSendDataBlocking;

	accDev.i2c = &i2cInterface;
	accDev.accel = &accDevice;

	accDev.slave.baudRate_kbps = BOARD_ACCEL_BAUDRATE;
	accDev.slave.address = BOARD_ACCEL_ADDR;
	accDev.bus = BOARD_ACCEL_I2C_INSTANCE;

	// Define gpio input pin config structure SW.
	gpio_input_pin_user_config_t inputPin[] = { { .pinName = BOARD_SW_GPIO,
			.config.isPullEnable = true,
#if FSL_FEATURE_PORT_HAS_PULL_SELECTION
			.config.pullSelect = kPortPullUp,
#endif
#if FSL_FEATURE_PORT_HAS_PASSIVE_FILTER
			.config.isPassiveFilterEnabled = false,
#endif
#if FSL_FEATURE_PORT_HAS_DIGITAL_FILTER
			.config.isDigitalFilterEnabled = false,
#endif
			.config.interrupt = kPortIntFallingEdge, }, { .pinName =
	GPIO_PINS_OUT_OF_RANGE, } };

	// Define gpio output pin config structure LED1.
	gpio_output_pin_user_config_t outputPin[] = { { .pinName = kGpioLED1,
			.config.outputLogic = 0,
#if FSL_FEATURE_PORT_HAS_SLEW_RATE
			.config.slewRate = kPortFastSlewRate,
#endif
#if FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH
			.config.driveStrength = kPortHighDriveStrength,
#endif
			}, { .pinName = GPIO_PINS_OUT_OF_RANGE, } };

	// Initialize standard SDK demo application pins.
	hardware_init();

	// Accel device driver utilizes the OSA, so initialize it.
	OSA_Init();

	// Init LED1, Switch.
	GPIO_DRV_Init(inputPin, outputPin);

	// Turn LED1 on.
	GPIO_DRV_ClearPinOutput(kGpioLED1);

	// Print the initial banner.
	PRINTF("Bubble Level Demo!\r\n\r\n");

	// Initialize the Accel.
	accel_init(&accDev);

	// Prepare memory for initialization.
	memset(&driverInfo, 0, sizeof(driverInfo));

	// Init TPM.
	TPM_DRV_Init(BOARD_BUBBLE_TPM_INSTANCE, &driverInfo);

	// Set clock for TPM.
	TPM_DRV_SetClock(BOARD_BUBBLE_TPM_INSTANCE, kTpmClockSourceModuleClk,
			kTpmDividedBy2);

	// Initialize LED1
	LED1_EN;

	// Main loop.  Get sensor data and update duty cycle for the TPM timer.
	while (1) {
		// Wait 5 ms in between samples (accelerometer updates at 200Hz).
		OSA_TimeDelay(5);

		// Get new accelerometer data.
		accDev.accel->accel_read_sensor_data(&accDev, &accelData);

		// Init PWM module with updated configuration.
		TPM_DRV_PwmStart(BOARD_BUBBLE_TPM_INSTANCE, &xAxisParams,
		BOARD_TPM_X_CHANNEL);
		TPM_DRV_PwmStart(BOARD_BUBBLE_TPM_INSTANCE, &yAxisParams,
		BOARD_TPM_Y_CHANNEL);

		// Get the X and Y data from the sensor data structure.fxos_data
		xData = (int16_t) ((accelData.data.accelXMSB << 8)
				| accelData.data.accelXLSB);
		yData = (int16_t) ((accelData.data.accelYMSB << 8)
				| accelData.data.accelYLSB);

		// Convert raw data to angle (normalize to 0-90 degrees).  No negative angles.
		xAngle = (int16_t) (xData * 0.011);
		yAngle = (int16_t) (yData * 0.011);

		//on teste si l'angle de tangage depasse 45 pour allumer le temoins vert
		if (xAngle > 45 || xAngle < -45) {
			tangage(&xAngle, &xAngleDutyCycle, &yAngleDutyCycle);
		}

		//on teste si l'angle de roulis depasse 45 pour allumer le temoins vert
		else if (yAngle > 45 || yAngle < -45) {
			roulis(&yAngle, &xAngleDutyCycle, &yAngleDutyCycle);
		}

		//on teste si l'angle de tangage (ou) l'angle de roulis est comprise entre 5 degree et 45 degree et si cette condition
		//est valide on allume les deux LED (Rouge et Bleu) sinon on allume la lumiere rouge qui correspond au tangage
		else if ((xAngle >= 5 && xAngle <= 45)
				|| (xAngle <= -5 && xAngle >= -45)) {
			if ((yAngle >= 5 && yAngle <= 45)
					|| (yAngle <= -5 && yAngle >= -45)) {
				tangageRoulis1(&yAngle, &xAngle, &xAngleDutyCycle,
						&yAngleDutyCycle);
			} else {
				tangageRoulis2(&yAngle, &xAngle, &xAngleDutyCycle,
						&yAngleDutyCycle);
			}
		}

		//on teste si l'angle de roulis (ou) l'angle de tangage est comprise entre 5 degree et 45 degree et si cette condition
		//est valide on allume les deux LED (Rouge et Bleu) sinon on allume la lumiere bleu qui correspond au tangage
		else if ((yAngle >= 5 && yAngle <= 45)
				|| (yAngle <= -5 && yAngle >= -45)) {
			if ((xAngle >= 5 && xAngle <= 45)
					|| (xAngle <= -5 && xAngle >= -45)) {
				roulisTangage1(&yAngle, &xAngle, &xAngleDutyCycle,
						&yAngleDutyCycle);
			} else {
				roulisTangage2(&yAngle, &xAngle, &xAngleDutyCycle,
						&yAngleDutyCycle);
			}
		}

		//on teste si les angles de roulis et de tangage est inferieur a 5 degrees pour allumer le temoins blanche
		else if (xAngle < 5 && yAngle < 5) {
			bienAligner(&yAngle, &xAngle, &xAngleDutyCycle, &yAngleDutyCycle);
		}

		// Update pwm duty cycle
		xAxisParams.uDutyCyclePercent = 100 - xAngleDutyCycle;
		yAxisParams.uDutyCyclePercent = 100 - yAngleDutyCycle;
	}
}

void BOARD_SW_IRQ_HANDLER(void) {
	// Clear external interrupt flag.
	GPIO_DRV_ClearPinIntFlag(BOARD_SW_GPIO);
	// Change state of button.
	isButtonPress = true;
	// Toggle LED1.
	//GPIO_DRV_TogglePinOutput(kGpioLED1);
}
