################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/RandomNumberGenerator.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/RandomNumberGenerator.d \
./source/semihost_hardfault.d 

OBJS += \
./source/RandomNumberGenerator.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFRDM_K64F -DFREEDOM -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_RandomNumberGenerator\source" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_RandomNumberGenerator\drivers" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_RandomNumberGenerator\utilities" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_RandomNumberGenerator\device" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_RandomNumberGenerator\component\uart" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_RandomNumberGenerator\component\lists" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_RandomNumberGenerator\CMSIS" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_RandomNumberGenerator\board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/RandomNumberGenerator.d ./source/RandomNumberGenerator.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

