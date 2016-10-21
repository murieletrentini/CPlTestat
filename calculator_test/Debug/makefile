################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: calculator_test

dependents:
	-cd /Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/02/calculator/calculator/Debug && $(MAKE) clean all
	-cd /Users/muriele/Meine_Sachen/CevelopWorkspace/SegmentDisplay/Debug && $(MAKE) clean all
	-cd /Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/pocketcalculator/Debug && $(MAKE) clean all

# Tool invocations
calculator_test: $(OBJS) $(USER_OBJS) /Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/02/calculator/calculator/Debug/libcalculator.a /Users/muriele/Meine_Sachen/CevelopWorkspace/SegmentDisplay/Debug/libSegmentDisplay.a /Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/pocketcalculator/Debug/libpocketcalculator.a
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C++ Linker'
	g++ -L"/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/pocketcalculator/Debug" -L"/Users/muriele/Meine_Sachen/CevelopWorkspace/SegmentDisplay/Debug" -L"/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/02/calculator/calculator/Debug" -o "calculator_test" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(CPP_DEPS)$(C_DEPS) calculator_test
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/02/calculator/calculator/Debug/libcalculator.a:
/Users/muriele/Meine_Sachen/CevelopWorkspace/SegmentDisplay/Debug/libSegmentDisplay.a:
/Users/muriele/GoogleDrive/HSR/Module/3HS16/CPl/Uebungen/pocketcalculator/Debug/libpocketcalculator.a:

-include ../makefile.targets
