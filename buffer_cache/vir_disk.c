#include <string.h>
#include "myheader.h"

// total disk size = 1024 * 256 = 256 KiB
struct storage
{
    unsigned short device_num; // file system number
    char disk[TOTAL_BLOCKS][BLOCK_SIZE];
};

void storage_init(int device_num)
{
    struct storage vdisk1;
    vdisk1.device_num = device_num;
    memset(vdisk1.disk, 0 , BLOCK_SIZE * TOTAL_BLOCKS);
}

// block 0 - reserved - super block
// block 1 - reserved - disk inode list block
// blocks 2 - 255 - usable blocks
