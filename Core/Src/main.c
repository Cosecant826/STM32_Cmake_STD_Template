#include "bsp.h"			/* 底层硬件驱动 */
/*
*********************************************************************************************************
*	函 数 名: main
*	功能说明: c程序入口
*	形    参：无
*	返 回 值: 错误代码(无需处理)
*********************************************************************************************************
*/
int main(void)
{
    uint8_t ucKeyCode;
    int16_t count = 0;
    uint8_t fRefresh = 0;

    /*
        ST固件库中的启动文件已经执行了 SystemInit() 函数，该函数在 system_stm32f4xx.c 文件，主要功能是
    配置CPU系统的时钟，内部Flash访问时序，配置FSMC用于外部SRAM
    */
    bsp_Init(); /* 硬件初始化 */

    fRefresh = 0;
    /* 主程序大循环 */
    while (1)
    {
        bsp_Idle(); /* CPU空闲时执行的函数，在 bsp.c */

        /* 摇杆左右键（上下键）控制LED流动 */
        if (fRefresh)
        {
            fRefresh = 0;

#if 1	/* 可以用 printf打印数据到串口 */
            printf("count = %6d \r", count);
            fflush(stdout); /* 强制立即输出到串口 */
#else	/* 也可以用 sprintf先输出到一个buf，然后在发送到串口 */
            {
                char buf[64];

                sprintf(buf, "count = %6d \r", count);

                comSendBuf(COM1, (uint8_t*)buf, strlen(buf));
            }
#endif
        }

        /* 处理按键事件 */
        ucKeyCode = bsp_GetKey();
        if (ucKeyCode > 0)
        {
            /* 有键按下 */
            switch (ucKeyCode)
            {
            case JOY_DOWN_L: /* 摇杆LEFT键按下, 控制LED显示流动 */
                count -= 10;
                fRefresh = 1;
                break;

            case JOY_DOWN_R: /* 摇杆RIGHT键按下 */
                count += 10;
                fRefresh = 1;
                break;

            case JOY_DOWN_U: /* 摇杆UP键按下 */
                count++;
                fRefresh = 1;
                break;

            case JOY_DOWN_D: /* 摇杆DOWN键按下 */
                count--;
                fRefresh = 1;
                break;

            case JOY_DOWN_OK: /* 摇杆OK键按下 */
                count *= 2;
                fRefresh = 1;
                break;

            default:
                break;
            }
        }
    }
}
