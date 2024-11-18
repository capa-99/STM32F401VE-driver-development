################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/Src/STM32F401VE_SPI_driver.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/Src/STM32F401VE_SPI_driver.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/Src/STM32F401VE_SPI_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/Src/%.o Drivers/STM32F4xx_HAL_Driver/Src/%.su Drivers/STM32F4xx_HAL_Driver/Src/%.cyclo: ../Drivers/STM32F4xx_HAL_Driver/Src/%.c Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src

clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src:
	-$(RM) ./Drivers/STM32F4xx_HAL_Driver/Src/STM32F401VE_SPI_driver.cyclo ./Drivers/STM32F4xx_HAL_Driver/Src/STM32F401VE_SPI_driver.d ./Drivers/STM32F4xx_HAL_Driver/Src/STM32F401VE_SPI_driver.o ./Drivers/STM32F4xx_HAL_Driver/Src/STM32F401VE_SPI_driver.su

.PHONY: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Src

