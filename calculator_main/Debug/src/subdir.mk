################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp 

OBJS += \
./src/main.o 

CPP_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/CPlTestat/calculator" -I"/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/CPlTestat/SegmentDisplay" -I"/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/CPlTestat/pocketcalculator" -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


