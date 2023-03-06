#include "bep_flashModel.h"
#include "bep_flashInterface.h"

static U8 *g_pbFlashModeBaseAddr;  // 虚拟Flash基地址
static U64 g_lFlashBusyTimeTotal;  // Flash总共的busy时间
static U32 g_dFlashBusyTimeRemain;  // Flash处于busy状态下剩余的busy时间
 
/******************************************** Flash固有属性底层函数 *********************************/
static void flhModel_init(void)
{
    g_pbFlashModeBaseAddr = (U8 *) malloc(FLASH_MODEL_SIZE);
}

static void flhModel_exit(void)
{
    free(g_pbFlashModeBaseAddr);
}

static void flhModel_writeData(U8 *pbAddr, U32 dByteSize, U32 dOffs)
{
    memcpy(g_pbFlashModeBaseAddr + dOffs, pbAddr, dByteSize);
}

static void flhModel_GetData(U8 *pbAddr, U32 dByteSize, U32 dOffs)
{
    memcpy(pbAddr, g_pbFlashModeBaseAddr + dOffs, dByteSize);
}

/******************************************** Flash对外接口函数 *********************************/
void flhModel_SendCmd(E_FLASH_CMD_TYPE eCmdType, void *pCmd)
{
    switch (eCmdType)
    {
        case FLASH_CMD_TYPE_READ:
        {
            g_dFlashBusyTimeRemain = FLASH_MODEL_NORMAL_READ_BUSY_TIME_US;
        }
        break;

        case FLASH_CMD_TYPE_WRITE:
        {
            g_dFlashBusyTimeRemain = FLASH_MODEL_NORMAL_WRITE_BUSY_TIME_US;
        }
        break;

        case FLASH_CMD_TYPE_ERASE:
        {
            g_dFlashBusyTimeRemain = FLASH_MODEL_NORMAL_ERASE_BUSY_TIME_US;
        }
        break;
        
        default:
            break;
    }
}

E_FLASH_STATE flhModel_CheckState(void)
{
    if (g_dFlashBusyTimeRemain == 0)
    {
        return FLASH_STATE_IDLE;
    }
    else
    {
        return FLASH_STATE_BUSY;
    }
}

void flhModel_GetData(U8 *pbDestAddr, U32 dByteSize)
{
    
}

