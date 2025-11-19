# 项目介绍

​	本项目是由STM32CUBEMX生成的HAL库版本Cmake工程修改而来的标准库版本Cmake工程，经测试编译通过。
工程基于安富莱STM32-V6开发板，使用安富莱电子编写的bsp驱动。移植了letter-shell,MultiButton,MultiTimer,包含了modbus主从机功能。

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
3. letter-shell命令行功能

|自定义命令|参数|功能说明|
|:--:|:--:|:--:|
|get|-|获取modbus_buf_ptr指向的值|
|set|uint8_t val|设置modbus_buf_ptr指向的值为val|
|mb_dec|-|modbus_buf_ptr指针减一|
|mb_inc|-|modbus_buf_ptr指针加一|
|mb|uint8_t _code<br/>uint16_t _reg_addr<br/> uint16_t _num|_code:功能码<br/>_reg_addr:寄存器地址<br/>_num:多寄存器或多线圈操作时 _num为(寄存器/线圈)数量，单个时为发送的值|
|mbs|-|打印从机寄存器值|
|tog|uint8_t _no|翻转指示灯|
|reboot|-|重启系统|

4.   reboot命令代码实现

     ```c
     void reboot(void)
     {
         shellClear();
         bsp_DelayMS(20);
         NVIC_SystemReset();
     }
     ```

# 主要修改

参考[Project_CMakeLists](https://github.com/Cosecant826/STM32_Cmake_STD_Template/blob/master/CMakeLists.txt)文件

```c
void bsp_Init(void)
{
    /* MultiButton初始化 */
    bsp_InitMultiButtons();
    /* MultiTimer初始化 */
    bsp_InitMultiTimers();
    /* letter-shell初始化 */
    userShellInit();
}

void bsp_RunPer1ms(void) { button_ticks(); }

void bsp_Idle(void)
{
#ifdef MODBUS_MODE_HOST
    MODH_Poll();
#elif defined MODBUS_MODE_SLAVE
    MODS_Poll();
#endif
    ShellIdle();
    multiTimerYield();
}
```

