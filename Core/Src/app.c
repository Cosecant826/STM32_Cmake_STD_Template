#include "app.h"

/*********************************************************************************************************
 *	                                   移植Letter-Shell
 *********************************************************************************************************
 */

Shell shell;
char shellBuffer[512];

/**
 * @brief 用户shell写
 *
 * @param data 数据
 * @param len 数据长度
 *
 * @return short 实际写入的数据长度
 */
short userShellWrite(char *data, unsigned short len)
{
    comSendBuf(COM1, (uint8_t *)data, len);
    // HAL_UART_Transmit(&huart1, (uint8_t *)data, len, 0x1FF);
    return len;
}

/**
 * @brief 用户shell读
 *
 * @param data 数据
 * @param len 数据长度
 *
 * @return short 实际读取到
 */
short userShellRead(char *data, unsigned short len)
{
    uint8_t result = 0;
    while (len-- > 0U)
    {
        if (comGetChar(COM1, (uint8_t *)data++))
        {
            result++;
        }
    }
    return result;
}

/**
 * @brief 用户shell初始化
 *
 */
void userShellInit(void)
{
    shell.write = userShellWrite;
    shell.read = userShellRead;
    shellInit(&shell, shellBuffer, sizeof(shellBuffer));
}

void ShellIdle() { shellTask(&shell); }

void reboot(void)
{
    shellClear();
    bsp_DelayMS(20);
    NVIC_SystemReset();
}

uint8_t modbus_buf[256];
uint8_t *modbus_buf_ptr = modbus_buf;
SHELL_EXPORT_VAR(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_VAR_INT), mb_ptr, &modbus_buf_ptr, 测试指针变量);

uint8_t get_mb_char(void)
{
    printf("%d\r\n", *modbus_buf_ptr);
    return *modbus_buf_ptr;
}

SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN, get,
                 get_mb_char, 获取modbus_buf_ptr指向的值);

uint8_t set_mb_char(uint8_t val)
{
    *modbus_buf_ptr = val;
    return *modbus_buf_ptr;
}

SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN, set,
                 set_mb_char, 设置modbus_buf_ptr指向的值);

uint8_t mb_ptr_dec(void)
{
    modbus_buf_ptr--;
    return (uint8_t)(modbus_buf_ptr - modbus_buf);
}

SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN, mb_dec,
                 mb_ptr_dec, modbus_buf_ptr指针减一);

uint8_t mb_ptr_inc(void)
{
    modbus_buf_ptr++;
    return (uint8_t)(modbus_buf_ptr - modbus_buf);
}

SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN, mb_inc,
                 mb_ptr_inc, modbus_buf_ptr指针加一);

static void modbus_send(uint8_t _code, uint16_t _reg_addr, uint16_t _num)
{
    bsp_PutMsg(MSG_MODS, 0);

    switch (_code)
    {
        case 1:
            // if (MODH_ReadParam_01H(REG_D01, 4) == 1);
            if (MODH_ReadParam_01H(_reg_addr, _num) == 1)
                printf("操作成功\r\n");
            else
                printf("失败\r\n");
            break;

        case 2:
            // if (MODH_ReadParam_02H(REG_T01, 3) == 1);
            if (MODH_ReadParam_02H(_reg_addr, _num) == 1)
                printf("操作成功\r\n");
            else
                printf("失败\r\n");
            break;

        case 3:
            // if (MODH_ReadParam_03H(REG_P01, 2) == 1);
            if (MODH_ReadParam_03H(_reg_addr, _num) == 1)
                printf("操作成功\r\n");
            else
                printf("失败\r\n");
            break;

        case 4:
            // if (MODH_ReadParam_04H(REG_A01, 1) == 1);
            if (MODH_ReadParam_04H(_reg_addr, _num) == 1)
                printf("操作成功\r\n");
            else
                printf("失败\r\n");
            break;

        case 5:
            // if (MODH_WriteParam_05H(REG_D01, 1) == 1);
            if (MODH_WriteParam_05H(_reg_addr, _num) == 1)
                printf("操作成功\r\n");
            else
                printf("失败\r\n");
            break;

        case 6:
            // if (MODH_WriteParam_06H(REG_P01, 1) == 1);
            if (MODH_WriteParam_06H(_reg_addr, _num) == 1)
                printf("操作成功\r\n");
            else
                printf("失败\r\n");
            break;

        case 15:
            // if (MODH_WriteParam_0FH(REG_P01, 2, buf) == 1);
            if (MODH_WriteParam_0FH(_reg_addr, _num, modbus_buf_ptr) == 1)
                printf("操作成功\r\n");
            else
                printf("失败\r\n");
            break;

        case 16:
            // if (MODH_WriteParam_10H(REG_P01, 2, buf) == 1);
            if (MODH_WriteParam_10H(_reg_addr, _num, modbus_buf_ptr) == 1)
                printf("操作成功\r\n");
            else
                printf("失败\r\n");
            break;

        default: /* 其它的键值不处理 */
            break;
    }
}

SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN, mb,
                 modbus_send, ModBus通信);

static void print_modbus_slave(void)
{
    shellPrint(&shell, "Modbus Slave Regs:\r\n");
    shellPrint(&shell, " D01=%x\r\n", g_tVarS.D01);
    shellPrint(&shell, " D02=%x\r\n", g_tVarS.D02);
    shellPrint(&shell, " D03=%x\r\n", g_tVarS.D03);
    shellPrint(&shell, " D04=%x\r\n", g_tVarS.D04);
    shellPrint(&shell, " P01=%d\r\n", g_tVarS.P01);
    shellPrint(&shell, " P02=%d\r\n", g_tVarS.P02);
    shellPrint(&shell, " A01=%d\r\n", g_tVarS.A01);
}

SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN, mbs,
                 print_modbus_slave, 打印从机寄存器值);
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN, tog,
                 bsp_LedToggle, 翻转指示灯);
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC) | SHELL_CMD_DISABLE_RETURN, reboot,
                 reboot, 重启系统);

/*********************************************************************************************************
 *	                                   移植MultiButton
 *********************************************************************************************************
 */
#define MAX_BUTTONS 8

static Button Buttons[MAX_BUTTONS];

typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;
} ButtonGPIO_T;

static ButtonGPIO_T s_taButtonGPIOs[MAX_BUTTONS] = {
    {GPIO_PORT_K1, GPIO_PIN_K1}, {GPIO_PORT_K2, GPIO_PIN_K2}, {GPIO_PORT_K3, GPIO_PIN_K3}, {GPIO_PORT_K4, GPIO_PIN_K4},
    {GPIO_PORT_K5, GPIO_PIN_K5}, {GPIO_PORT_K6, GPIO_PIN_K6}, {GPIO_PORT_K7, GPIO_PIN_K7}, {GPIO_PORT_K8, GPIO_PIN_K8}};

uint8_t read_button_gpio(uint8_t button_id)
{
    return (s_taButtonGPIOs[button_id - 1].port->IDR & s_taButtonGPIOs[button_id - 1].pin);
}

// Generic event handler that shows button info
static void generic_event_handler(Button *btn, const char *event_name)
{
    if (1)
    {
        shellPrint(&shell, "\r\nButton %d: %s (repeat: %d, pressed: %s)", btn->button_id, event_name,
                   button_get_repeat_count(btn), button_is_pressed(btn) ? "Yes" : "No");
    }
    else
    {
        printf("Button %d: %s\n", btn->button_id, event_name);
    }
}

static void btn1_handler(Button *btn)
{
    switch (button_get_event(btn))
    {
        case BTN_SINGLE_CLICK:
            break;

        case BTN_DOUBLE_CLICK:
            printf("\r\nButton 1 double clicked!");
            break;

        case BTN_LONG_PRESS_START:
            break;
        default:
            break;
    }
}

static void btn2_handler(Button *btn)
{
    switch (button_get_event(btn))
    {
        case BTN_PRESS_UP:
            generic_event_handler(btn, "Press UP");
            break;
        default:
            break;
    }
}

static BtnCallback get_event_handler(uint8_t button_id)
{
    switch (button_id)
    {
        case 1:
            return btn1_handler;
        case 2:
            return btn2_handler;
        default:
            return NULL;
    }
}

// Initialize a single button with all event handlers
static void init_button(int index, uint8_t button_id, uint8_t active_level, EVENTS_ENABLE_E events_enable)
{
    button_init(&Buttons[index], read_button_gpio, active_level, button_id);

    if (events_enable == ENABLE_ALL)
    {
        button_attach(&Buttons[index], BTN_PRESS_DOWN, get_event_handler(button_id));
        button_attach(&Buttons[index], BTN_PRESS_UP, get_event_handler(button_id));
        button_attach(&Buttons[index], BTN_SINGLE_CLICK, get_event_handler(button_id));
        button_attach(&Buttons[index], BTN_DOUBLE_CLICK, get_event_handler(button_id));
        button_attach(&Buttons[index], BTN_LONG_PRESS_START, get_event_handler(button_id));
        button_attach(&Buttons[index], BTN_LONG_PRESS_HOLD, get_event_handler(button_id));
        button_attach(&Buttons[index], BTN_PRESS_REPEAT, get_event_handler(button_id));
    }
    else
    {
        // Only essential events
        button_attach(&Buttons[index], BTN_SINGLE_CLICK, get_event_handler(button_id));
        button_attach(&Buttons[index], BTN_DOUBLE_CLICK, get_event_handler(button_id));
        button_attach(&Buttons[index], BTN_LONG_PRESS_START, get_event_handler(button_id));
    }

    button_start(&Buttons[index]);
}

// Initialize all buttons
void bsp_InitMultiButtons(void)
{
    init_button(0, 1, 0, ENABLE_ESSENTIAL);
    init_button(1, 2, 0, ENABLE_ALL);
}

/*********************************************************************************************************
 *	                                   移植MultiTimer
 *********************************************************************************************************
 */

MultiTimer timer1;

uint32_t PlatformTicksGetFunc(void) { return bsp_GetRunTime(); }

void timer1_callback(MultiTimer *timer, void *userData) { multiTimerStart(&timer1, 1000, timer1_callback, NULL); }

void bsp_InitMultiTimers(void)
{
    multiTimerInstall(PlatformTicksGetFunc);
    multiTimerStart(&timer1, 1000, timer1_callback, NULL);
}
