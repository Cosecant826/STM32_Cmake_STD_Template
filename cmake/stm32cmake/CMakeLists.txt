cmake_minimum_required(VERSION 3.22)
# Enable CMake support for ASM and C languages
enable_language(C ASM)
# STM32CubeMX generated symbols (macros)
set(CMAKE_Defines_Syms
        USE_STDPERIPH_DRIVER
        STM32F429_439xx
        $<$<CONFIG:Debug>:DEBUG>
)

# STM32CubeMX generated include paths
set(CMAKE_Include_Dirs
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CMSIS/Device/ST/STM32F4xx/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CMSIS/Include
)

# STM32CubeMX generated application sources
set(CMAKE_Application_Src
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/stm32f4xx_it.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/sysmem.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/syscalls.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f429_439xx.s
)

# STM32 HAL/LL Drivers
set(STM32_Drivers_Src
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/misc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cec.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dfsdm.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma2d.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dsi.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash_ramfunc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fmc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fmpi2c.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_lptim.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_ltdc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_qspi.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sai.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spdifrx.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.c
)

# Drivers Midllewares


# Link directories setup
set(CMAKE_LINK_DIRS

)
# Project static libraries
set(CMAKE_LINK_LIBS
        STM32_Drivers
        ${TOOLCHAIN_LINK_LIBRARIES}

)
# Interface library for includes and symbols
add_library(stm32cmake INTERFACE)
target_include_directories(stm32cmake INTERFACE ${CMAKE_Include_Dirs})
target_compile_definitions(stm32cmake INTERFACE ${CMAKE_Defines_Syms})

# Create STM32_Drivers static library
add_library(STM32_Drivers OBJECT)
target_sources(STM32_Drivers PRIVATE ${STM32_Drivers_Src})
target_link_libraries(STM32_Drivers PUBLIC stm32cmake)


# Add STM32CubeMX generated application sources to the project
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_Application_Src})

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_LINK_DIRS})

# Add libraries to the project
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_LINK_LIBS})

# Add the map file to the list of files to be removed with 'clean' target
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES ${CMAKE_PROJECT_NAME}.map)

# Validate that STM32CubeMX code is compatible with C standard
if ((CMAKE_C_STANDARD EQUAL 90) OR (CMAKE_C_STANDARD EQUAL 99))
    message(ERROR "Generated code requires C11 or higher")
endif ()
