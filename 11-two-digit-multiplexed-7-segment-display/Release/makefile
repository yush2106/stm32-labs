################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 11-two-digit-multiplexed-7-segment-display
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
11-two-digit-multiplexed-7-segment-display.elf \

MAP_FILES += \
11-two-digit-multiplexed-7-segment-display.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
11-two-digit-multiplexed-7-segment-display.list \

OBJCOPY_BIN += \
11-two-digit-multiplexed-7-segment-display.bin \


# All Target
all: main-build

# Main-build Target
main-build: 11-two-digit-multiplexed-7-segment-display.elf secondary-outputs

# Tool invocations
11-two-digit-multiplexed-7-segment-display.elf 11-two-digit-multiplexed-7-segment-display.map: $(OBJS) $(USER_OBJS) D:\STM32\Lab\11-two-digit-multiplexed-7-segment-display\STM32L476RGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "11-two-digit-multiplexed-7-segment-display.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\STM32\Lab\11-two-digit-multiplexed-7-segment-display\STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="11-two-digit-multiplexed-7-segment-display.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

11-two-digit-multiplexed-7-segment-display.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "11-two-digit-multiplexed-7-segment-display.list"
	@echo 'Finished building: $@'
	@echo ' '

11-two-digit-multiplexed-7-segment-display.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "11-two-digit-multiplexed-7-segment-display.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 11-two-digit-multiplexed-7-segment-display.bin 11-two-digit-multiplexed-7-segment-display.elf 11-two-digit-multiplexed-7-segment-display.list 11-two-digit-multiplexed-7-segment-display.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
