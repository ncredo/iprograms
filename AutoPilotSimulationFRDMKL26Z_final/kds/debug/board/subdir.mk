################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/board.c \
C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/gpio_pins.c \
C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/hardware_init.c \
C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/pin_mux.c 

OBJS += \
./board/board.o \
./board/gpio_pins.o \
./board/hardware_init.o \
./board/pin_mux.o 

C_DEPS += \
./board/board.d \
./board/gpio_pins.d \
./board/hardware_init.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/board.o: C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/board.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL26Z128VLH4 -DFRDM_KL26Z -DFREEDOM -I../../../../../../platform/osa/inc -I../../../../../../platform/utilities/inc -I../../../../../../platform/CMSIS/Include -I../../../../../../platform/devices -I../../../../../../platform/devices/MKL26Z4/include -I../../../../../../platform/devices/MKL26Z4/startup -I../../../../../../platform/hal/inc -I../../../../../../platform/drivers/inc -I../../../../../../platform/system/inc -I../../../../../../platform/drivers/src/i2c -I../.. -I../../../.. -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

board/gpio_pins.o: C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/gpio_pins.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL26Z128VLH4 -DFRDM_KL26Z -DFREEDOM -I../../../../../../platform/osa/inc -I../../../../../../platform/utilities/inc -I../../../../../../platform/CMSIS/Include -I../../../../../../platform/devices -I../../../../../../platform/devices/MKL26Z4/include -I../../../../../../platform/devices/MKL26Z4/startup -I../../../../../../platform/hal/inc -I../../../../../../platform/drivers/inc -I../../../../../../platform/system/inc -I../../../../../../platform/drivers/src/i2c -I../.. -I../../../.. -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

board/hardware_init.o: C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/hardware_init.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL26Z128VLH4 -DFRDM_KL26Z -DFREEDOM -I../../../../../../platform/osa/inc -I../../../../../../platform/utilities/inc -I../../../../../../platform/CMSIS/Include -I../../../../../../platform/devices -I../../../../../../platform/devices/MKL26Z4/include -I../../../../../../platform/devices/MKL26Z4/startup -I../../../../../../platform/hal/inc -I../../../../../../platform/drivers/inc -I../../../../../../platform/system/inc -I../../../../../../platform/drivers/src/i2c -I../.. -I../../../.. -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

board/pin_mux.o: C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/pin_mux.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL26Z128VLH4 -DFRDM_KL26Z -DFREEDOM -I../../../../../../platform/osa/inc -I../../../../../../platform/utilities/inc -I../../../../../../platform/CMSIS/Include -I../../../../../../platform/devices -I../../../../../../platform/devices/MKL26Z4/include -I../../../../../../platform/devices/MKL26Z4/startup -I../../../../../../platform/hal/inc -I../../../../../../platform/drivers/inc -I../../../../../../platform/system/inc -I../../../../../../platform/drivers/src/i2c -I../.. -I../../../.. -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


