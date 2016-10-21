################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Test.cpp 

OBJS += \
./src/Test.o 

CPP_DEPS += \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/Test.o: ../src/Test.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/02/calculator/calculator" -I"/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/02/calculator/calculator_test/cute" -I"/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/pocketcalculator" -I"/Users/muriele/Meine_Sachen/CevelopWorkspace/SegmentDisplay" -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/Test.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


