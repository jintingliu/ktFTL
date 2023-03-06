#ifndef __BEP_FLASHINTERFACE_H__
#define __BEP_FLASHINTERFACE_H__

#include "common.h"

typedef enum
{
    FLASH_STATE_IDLE,
    FLASH_STATE_BUSY
}E_FLASH_STATE;

typedef enum
{
    FLASH_STATE_ECC_FAIL,
    FLASH_STATE_ECC_PASS,
    FLASH_STATE_ECC_ALL_FF,
    FLASH_STATE_ECC_ALL_00
}E_FLASH_ECC_STATE;

typedef enum
{
    FLASH_CMD_TYPE_READ,
    FLASH_CMD_TYPE_WRITE,
    FLASH_CMD_TYPE_ERASE
}E_FLASH_CMD_TYPE;

typedef struct
{
    U16 wBlockNum;
    U16 wPageOffs;
}T_FLASH_CMD_READ;

typedef struct
{
    U16 wBlockNum;
    U16 wPageOffs;
}T_FLASH_CMD_WRITE;

typedef struct
{
    U16 wBlockNum;
}T_FLASH_CMD_ERASE;


typedef struct
{
    void (*SendCmd)(E_FLASH_CMD_TYPE eCmdType, void *pCmd);
    E_FLASH_STATE (*CheckState)(void);
    void (*GetData)(U8 *pbDestAddr, U32 dByteSize);
}T_FLASH_INTERFACE;


#endif

