################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mbedtls/port/ksdk/aes_alt.c \
../mbedtls/port/ksdk/des_alt.c \
../mbedtls/port/ksdk/ecp_alt.c \
../mbedtls/port/ksdk/ecp_alt_ksdk.c \
../mbedtls/port/ksdk/ecp_curves_alt.c \
../mbedtls/port/ksdk/ksdk_mbedtls.c 

C_DEPS += \
./mbedtls/port/ksdk/aes_alt.d \
./mbedtls/port/ksdk/des_alt.d \
./mbedtls/port/ksdk/ecp_alt.d \
./mbedtls/port/ksdk/ecp_alt_ksdk.d \
./mbedtls/port/ksdk/ecp_curves_alt.d \
./mbedtls/port/ksdk/ksdk_mbedtls.d 

OBJS += \
./mbedtls/port/ksdk/aes_alt.o \
./mbedtls/port/ksdk/des_alt.o \
./mbedtls/port/ksdk/ecp_alt.o \
./mbedtls/port/ksdk/ecp_alt_ksdk.o \
./mbedtls/port/ksdk/ecp_curves_alt.o \
./mbedtls/port/ksdk/ksdk_mbedtls.o 


# Each subdirectory must supply rules for building sources it contributes
mbedtls/port/ksdk/%.o: ../mbedtls/port/ksdk/%.c mbedtls/port/ksdk/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DPRINTF_ADVANCED_ENABLE=1 -DPRINTF_FLOAT_ENABLE=1 -DFREESCALE_KSDK_BM -DMBEDTLS_CONFIG_FILE='"ksdk_mbedtls_config.h"' -DFRDM_K64F -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\source" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\drivers" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\mmcau" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\mbedtls\include" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\mbedtls\library" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\mbedtls\port\ksdk" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\utilities" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\device" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\component\uart" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\component\serial_manager" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\component\lists" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\CMSIS" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\board" -I"C:\Users\josue\Documents\MCUXpressoIDE_11.6.0_8187\workspace\FRDMK64F_CHACHA20\frdmk64f\mbedtls_examples\mbedtls_benchmark" -O0 -fno-common -g3 -fomit-frame-pointer -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-mbedtls-2f-port-2f-ksdk

clean-mbedtls-2f-port-2f-ksdk:
	-$(RM) ./mbedtls/port/ksdk/aes_alt.d ./mbedtls/port/ksdk/aes_alt.o ./mbedtls/port/ksdk/des_alt.d ./mbedtls/port/ksdk/des_alt.o ./mbedtls/port/ksdk/ecp_alt.d ./mbedtls/port/ksdk/ecp_alt.o ./mbedtls/port/ksdk/ecp_alt_ksdk.d ./mbedtls/port/ksdk/ecp_alt_ksdk.o ./mbedtls/port/ksdk/ecp_curves_alt.d ./mbedtls/port/ksdk/ecp_curves_alt.o ./mbedtls/port/ksdk/ksdk_mbedtls.d ./mbedtls/port/ksdk/ksdk_mbedtls.o

.PHONY: clean-mbedtls-2f-port-2f-ksdk

