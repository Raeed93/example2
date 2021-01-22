################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/MusicBox.cpp \
../Sources/Note.cpp \
../Sources/Tune.cpp \
../Sources/delay.cpp \
../Sources/ftfl.cpp \
../Sources/hardware.cpp \
../Sources/i2c.cpp \
../Sources/spi.cpp \
../Sources/usbdmError.cpp 

OBJS += \
./Sources/MusicBox.o \
./Sources/Note.o \
./Sources/Tune.o \
./Sources/delay.o \
./Sources/ftfl.o \
./Sources/hardware.o \
./Sources/i2c.o \
./Sources/spi.o \
./Sources/usbdmError.o 

CPP_DEPS += \
./Sources/MusicBox.d \
./Sources/Note.d \
./Sources/Tune.d \
./Sources/delay.d \
./Sources/ftfl.d \
./Sources/hardware.d \
./Sources/i2c.d \
./Sources/spi.d \
./Sources/usbdmError.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -g3 -O0 -ffunction-sections -fdata-sections -fno-rtti -Wall -Wextra -DDEBUG_BUILD -I"C:/Users/100477260/Desktop/Embedded MC/Labs/MusicBox1 2/MusicBox1/Sources" -I"C:/Users/100477260/Desktop/Embedded MC/Labs/MusicBox1 2/MusicBox1/Project_Headers" -fno-exceptions -std=gnu++17 -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  -o "$@" $<
	@echo 'Finished building: $<'
	@echo ' '


