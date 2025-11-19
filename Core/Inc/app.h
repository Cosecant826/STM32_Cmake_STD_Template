#ifndef APP_H
#define APP_H

// #define MODBUS_MODE_HOST
#define MODBUS_MODE_SLAVE

typedef enum
{
    ENABLE_ALL,
    ENABLE_ESSENTIAL,
}EVENTS_ENABLE_E;

#include "bsp.h"
#include "shell.h"
#include "MultiTimer.h"
#include "multi_button.h"
#include "modbus_host.h"
#include "modbus_slave.h"


void bsp_InitMultiButtons(void);
void bsp_InitMultiTimers(void);
void userShellInit(void);
void ShellIdle(void);
#endif //APP_H