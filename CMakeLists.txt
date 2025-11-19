cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME STM32_Cmake_STD_Template)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cmake)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
        # Add user sources here
        Core/Src/app.c
        User/APP/letter-shell/src/shell.c
        User/APP/letter-shell/src/shell_ext.c
        User/APP/letter-shell/extensions/shell_enhance/shell_cmd_group.c
        User/APP/MultiButton/multi_button.c
        User/APP/MultiTimer/MultiTimer.c
        User/APP/modbus/modbus_host.c
        User/APP/modbus/modbus_slave.c
        User/BSP/src/bsp_ext_io.c
        User/BSP/src/bsp_uart_fifo.c
        User/BSP/src/bsp_led.c
        User/BSP/src/bsp_timer.c
        User/BSP/src/bsp_key.c
        User/BSP/src/bsp_user_lib.c
        User/BSP/bsp_msg.c
        User/BSP/bsp.c
        User/SEGGER/RTT/RTT/SEGGER_RTT.c
        User/SEGGER/RTT/RTT/SEGGER_RTT_printf.c
        User/SEGGER/RTT/Syscalls/SEGGER_RTT_Syscalls_GCC.c
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        # Add user defined include paths
        User/APP
        User/APP/letter-shell/src
        User/APP/letter-shell/extensions/shell_enhance
        User/APP/MultiButton
        User/APP/MultiTimer
        User/APP/modbus
        User/BSP
        User/BSP/inc
        User/SEGGER/RTT/RTT
        User/SEGGER/RTT/Config
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cmake

    # Add user defined libraries
)

# Build Hex file after building ELF
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex
        $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
        $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/${CMAKE_PROJECT_NAME}.hex
)
