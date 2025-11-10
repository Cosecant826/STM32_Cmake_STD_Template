# 项目介绍

​	本项目是由STM32CUBEMX生成的HAL库版本Cmake工程修改而来的标准库版本Cmake工程，经测试编译通过。
工程基于安富莱STM32-V6开发板，程序功能基于安富莱的“不一样的流水灯”例程，经测试现象正常。

# 程序功能

1. 串口接收字符控制板载LED翻转，对应关系如下

|字符|对应LED|
|----|----|
|'1'|LED1|
|'2'|LED2|
|'3'|LED3|
|'4'|LED4|
2. 串口打印变量数值，五向按键控制变量数值变化，对应关系如下

|按键|变量数值变化|
|----|----|
|JOY_L|-10|
|JOY_R|+10|
|JOY_U|+1|
|JOY_D|-1|
|JOY_OK|\*2|



# 主要修改

参考[Driver_CMakeLists](https://github.com/Cosecant826/STM32_Cmake_STD_Template/blob/master/cmake/stm32cmake/CMakeLists.txt)文件及[Project_CMakeLists](https://github.com/Cosecant826/STM32_Cmake_STD_Template/blob/master/CMakeLists.txt)文件
