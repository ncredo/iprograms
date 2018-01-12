################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/accel.c \
C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/fsl_i2c_irq.c \
C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/fxos_api.c \
C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/main.c \
C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/mma8451_api.c 

OBJS += \
./source/accel.o \
./source/fsl_i2c_irq.o \
./source/fxos_api.o \
./source/main.o \
./source/mma8451_api.o 

C_DEPS += \
./source/accel.d \
./source/fsl_i2c_irq.d \
./source/fxos_api.d \
./source/main.d \
./source/mma8451_api.d 


# Each subdirectory must supply rules for building sources it contributes
source/accel.o: C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/accel.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL26Z128VLH4 -DFRDM_KL26Z -DFREEDOM -I../../../../../../platform/osa/inc -I../../../../../../platform/utilities/inc -I../../../../../../platform/CMSIS/Include -I../../../../../../platform/devices -I../../../../../../platform/devices/MKL26Z4/include -I../../../../../../platform/devices/MKL26Z4/startup -I../../../../../../platform/hal/inc -I../../../../../../platform/drivers/inc -I../../../../../../platform/system/inc -I../../../../../../platform/drivers/src/i2c -I../.. -I../../../.. -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/fsl_i2c_irq.o: C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/fsl_i2c_irq.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL26Z128VLH4 -DFRDM_KL26Z -DFREEDOM -I../../../../../../platform/osa/inc -I../../../../../../platform/utilities/inc -I../../../../../../platform/CMSIS/Include -I../../../../../../platform/devices -I../../../../../../platform/devices/MKL26Z4/include -I../../../../../../platform/devices/MKL26Z4/startup -I../../../../../../platform/hal/inc -I../../../../../../platform/drivers/inc -I../../../../../../platform/system/inc -I../../../../../../platform/drivers/src/i2c -I../.. -I../../../.. -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/fxos_api.o: C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/fxos_api.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL26Z128VLH4 -DFRDM_KL26Z -DFREEDOM -I../../../../../../platform/osa/inc -I../../../../../../platform/utilities/inc -I../../../../../../platform/CMSIS/Include -I../../../../../../platform/devices -I../../../../../../platform/devices/MKL26Z4/include -I../../../../../../platform/devices/MKL26Z4/startup -I../../../../../../platform/hal/inc -I../../../../../../platform/drivers/inc -I../../../../../../platform/system/inc -I../../../../../../platform/drivers/src/i2c -I../.. -I../../../.. -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/main.o: C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL26Z128VLH4 -DFRDM_KL26Z -DFREEDOM -I../../../../../../platform/osa/inc -I../../../../../../platform/utilities/inc -I../../../../../../platform/CMSIS/Include -I../../../../../../platform/devices -I../../../../../../platform/devices/MKL26Z4/include -I../../../../../../platform/devices/MKL26Z4/startup -I../../../../../../platform/hal/inc -I../../../../../../platform/drivers/inc -I../../../../../../platform/system/inc -I../../../../../../platform/drivers/src/i2c -I../.. -I../../../.. -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/mma8451_api.o: C:/Freescale/KSDK_1.3.0/examples/frdmkl26z/demo_apps/bubble_level_tpm/mma8451_api.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL26Z128VLH4 -DFRDM_KL26Z -DFREEDOM -I../../../../../../platform/osa/inc -I../../../../../../platform/utilities/inc -I../../../../../../platform/CMSIS/Include -I../../../../../../platform/devices -I../../../../../../platform/devices/MKL26Z4/include -I../../../../../../platform/devices/MKL26Z4/startup -I../../../../../../platform/hal/inc -I../../../../../../platform/drivers/inc -I../../../../../../platform/system/inc -I../../../../../../platform/drivers/src/i2c -I../.. -I../../../.. -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


