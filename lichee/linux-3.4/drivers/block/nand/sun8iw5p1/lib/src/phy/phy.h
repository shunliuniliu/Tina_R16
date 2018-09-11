
#ifndef _PHY_H
#define _PHY_H

#include "mbr.h"
#include "../physic/nand_type.h"

#define PHY_RESERVED_BLOCK_RATIO      256
#define MAX_PHY_RESERVED_BLOCK        64
#define MIN_PHY_RESERVED_BLOCK        8
#define MIN_PHY_RESERVED_BLOCK_V2     0

#define FACTORY_BAD_BLOCK_SIZE               2048
#define PHY_PARTITION_BAD_BLOCK_SIZE         4096
#define PARTITION_BAD_BLOCK_SIZE             4096

#define MBR_DATA_SIZE

//==========================================================
struct _nand_phy_partition;

struct _nand_super_block{
    unsigned short  Block_NO;
    unsigned short  Chip_NO;
};

struct _nand_disk{
	unsigned int		size;
	//unsigned int offset;
	unsigned int		type;
	unsigned  char      name[PARTITION_NAME_SIZE];
};

struct _partition{
	struct _nand_disk nand_disk[MAX_PART_COUNT_PER_FTL];
	unsigned int size;
	unsigned int cross_talk;
	unsigned int attribute;
    struct _nand_super_block start;
    struct _nand_super_block end;
	//unsigned int offset;
};

struct _bad_block_list{
	struct _nand_super_block  super_block;
	struct _nand_super_block* next;

};


typedef union{
    unsigned char ndata[4096];
    PARTITION_MBR data;
}_MBR;

typedef union{
    unsigned char ndata[2048+512];
    struct _partition data[MAX_PARTITION];
}_PARTITION;

typedef union{
    unsigned char ndata[512];
    struct __NandStorageInfo_t data;
}_NAND_STORAGE_INFO;

typedef union{
    unsigned char ndata[2048];
    struct _nand_super_block data[512];
}_FACTORY_BLOCK;

typedef union{
    unsigned char ndata[1024];
    unsigned char data[1024];
}_NAND_SPECIAL_INFO;



struct _boot_info{
	unsigned int magic;
	unsigned int len;
	unsigned int sum;

	unsigned int no_use_block_by_super;
	unsigned int uboot_start_block;
	unsigned int uboot_next_block;
	unsigned int logic_start_block_by_single;
	unsigned int nand_specialinfo_page;
	unsigned int nand_specialinfo_offset;
    unsigned int nouse[128-9];

	_MBR mbr;                               //4k               offset 0.5k
	_PARTITION partition;                   //2.5k             offset 4.5k
	_NAND_STORAGE_INFO storage_info;        //0.5k             offset 7k
	_FACTORY_BLOCK  factory_block;          //2k               offset 7.5k
	_NAND_SPECIAL_INFO  nand_special_info;  //1k               offset 9.5k

};

//ȫ��flash����
struct _nand_info{
	unsigned short                  type;
    unsigned short                  SectorNumsPerPage;
    unsigned short                  BytesUserData;
    unsigned short                  PageNumsPerBlk;
	unsigned short                  BlkPerChip;
    unsigned short                  ChipNum;
	unsigned short                  FirstBuild;
	unsigned short                  new_bad_page_addr;
	unsigned long long              FullBitmap;
	struct _nand_super_block        mbr_block_addr;
	struct _nand_super_block        bad_block_addr;
	struct _nand_super_block        new_bad_block_addr;
	struct _nand_super_block        no_used_block_addr;
	//struct _bad_block_list*         new_bad_block_addr;
    struct _nand_super_block*       factory_bad_block;
    struct _nand_super_block*       new_bad_block;
	unsigned char*                  temp_page_buf;
    unsigned char*                  mbr_data;
	struct _nand_phy_partition*     phy_partition_head;
	struct _partition               partition[MAX_PARTITION];
	unsigned short                  partition_nums;
	unsigned short                  cache_level;
	unsigned short                  capacity_level;

	unsigned short                  mini_free_block_first_reserved;
	unsigned short                  mini_free_block_reserved;	

    unsigned int 					MaxBlkEraseTimes;
	unsigned int 					EnableReadReclaim;

	unsigned int 					read_claim_interval;

	struct _boot_info*              boot;
};

//==========================================================
//nand phy partition ���ʽӿ�

struct _nand_phy_partition{
    unsigned short                  PartitionNO;
    unsigned short                  CrossTalk;
    unsigned short                  SectorNumsPerPage;
    unsigned short                  BytesUserData;
    unsigned short                  PageNumsPerBlk;
	unsigned short                  TotalBlkNum;          //include bad block
    unsigned short                  GoodBlockNum;
	unsigned short                  FullBitmapPerPage;
	unsigned short                  FreeBlock;
	unsigned int                    Attribute;
	unsigned int                    TotalSectors;
    struct _nand_super_block        StartBlock;
    struct _nand_super_block        EndBlock;
	struct _nand_info*              nand_info;
	struct _nand_super_block*       factory_bad_block;
    struct _nand_super_block*       new_bad_block;
	struct _nand_phy_partition*     next_phy_partition;
	struct _nand_disk*              disk;

	int (*page_read)(unsigned short nDieNum, unsigned short nBlkNum, unsigned short nPage, unsigned short SectBitmap, void *pBuf, void *pSpare);
	int (*page_write)(unsigned short nDieNum, unsigned short nBlkNum, unsigned short nPage, unsigned short SectBitmap, void *pBuf, void *pSpare);
    int (*block_erase)(unsigned short nDieNum, unsigned short nBlkNum);
};

//==========================================================
//nand partition ���ʽӿ�

struct _nand_partition_page{
    unsigned short  Page_NO;
    unsigned short  Block_NO;
};

struct _physic_par{
    struct _nand_partition_page	 phy_page;
    unsigned short               page_bitmap;
    unsigned char*               main_data_addr;
    unsigned char*               spare_data_addr;
};

//nand partition
struct _nand_partition{
	char                            name[32];
    unsigned short                  sectors_per_page;
    unsigned short                  spare_bytes;
    unsigned short                  pages_per_block;
    unsigned short                  total_blocks;
    unsigned short                  bytes_per_page;
    unsigned int                    bytes_per_block;
    unsigned short                  full_bitmap;
	unsigned long long              cap_by_sectors;
	unsigned long long              cap_by_bytes;
	unsigned long long              total_by_bytes;
	struct _nand_phy_partition*     phy_partition;

    int (*nand_erase_superblk)(struct _nand_partition* nand,struct _physic_par *p);
    int (*nand_read_page)(struct _nand_partition* nand,struct _physic_par *p);
    int (*nand_write_page)(struct _nand_partition* nand,struct _physic_par *p);
    int (*nand_is_blk_good)(struct _nand_partition* nand,struct _physic_par *p);
    int (*nand_mark_bad_blk)(struct _nand_partition* nand,struct _physic_par *p);
};
#endif /*_PHY_H*/
