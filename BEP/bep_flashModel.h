#ifndef __BEP_FLASHMODEL_H__
#define __BEP_FLASHMODEL_H__

#include "common.h"

/**
 * @brief Flash Size 相关的参数
 * 
 */
#define FLASH_MODEL_PLANE_IN_CHIP 2
#define FLASH_MODEL_BLOCK_IN_CHIP 128
#define FLASH_MODEL_TLC_PAGE_IN_BLOCK 192
#define FLASH_MODEL_SLC_PAGE_IN_BLOCK 64
#define FLASH_MODEL_DATA_BYTE_IN_PAGE 16384
#define FLASH_MODEL_USER_BYTE_IN_PAGE 32

#define FLASH_MODEL_SIZE (FLASH_MODEL_BLOCK_IN_CHIP * FLASH_MODEL_SLC_PAGE_IN_BLOCK * (FLASH_MODEL_DATA_BYTE_IN_PAGE + FLASH_MODEL_USER_BYTE_IN_PAGE))

/**
 * @brief Flash 操作时间
 * 
 */
#define FLASH_MODEL_NORMAL_READ_BUSY_TIME_US 65
#define FLASH_MODEL_NORMAL_WRITE_BUSY_TIME_US 1200
#define FLASH_MODEL_NORMAL_ERASE_BUSY_TIME_US 5000

/**
 * @brief Flash 命令队列
 * 
 */
#define FLASH_MODEL_CMD_QUE_LEN 8

typedef struct
{   
    struct
    {
        /* data */
    }item[FLASH_MODEL_CMD_QUE_LEN];

    U16 wHead;
    U16 wTail;
    U16 wLen;
}T_FLASH_CMD_QUE;


#endif

