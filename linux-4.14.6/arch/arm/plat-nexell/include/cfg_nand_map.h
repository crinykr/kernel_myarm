
static struct mtd_partition partition_map[] = {
	{
         .name       = "Bootloader",
         .offset     = 0,
         .size       = (256 * SZ_1K),           //(1024*1024),
         //.mask_flags = MTD_CAP_NANDFLASH,
    },

        {
         .name       = "nand.kernel",
         .offset     = (256 * SZ_1K),           //MTDPART_OFS_APPEND,
         .size       = (4 * SZ_1M) - (256 * SZ_1K), //(60*SZ_1M),
         //.mask_flags = MTD_CAP_NANDFLASH,
    },

        {
         .name       = "nand.rootfs",
         .offset     = (4 * SZ_1M),             //MTDPART_OFS_APPEND,
#if !defined(CONFIG_CAMERA1_OV7675)
		 .size       = (20 * SZ_1M),             //(60*SZ_1M),
#else
		 .size       = (8 * SZ_1M),             //(60*SZ_1M),
#endif
    },
        {
         .name       = "nand.userfs",
#if !defined(CONFIG_CAMERA1_OV7675)
#if !defined(CONFIG_MOST2120_UBIFS_DATA)
         .offset     = MTDPART_OFS_APPEND,
         .size       = MTDPART_SIZ_FULL,
#else
  #if defined(CONFIG_MODEL_RK_HIT_N)
		 .offset     = (24 * SZ_1M),
		 .size       = (104 * SZ_1M),
  #else
    #if defined(CONFIG_MODEL_RK_HIT_V4) || defined(CONFIG_MODEL_RK_HIT_L) || defined(CONFIG_MODEL_RK_HIT_SUPERNOVA)
           .offset     = (24 * SZ_1M),
           .size       = ((56+128) * SZ_1M),
    #else
           .offset     = (24 * SZ_1M),
           .size       = (56 * SZ_1M),
    #endif
#endif
#endif
#else
		   .offset     = (12 * SZ_1M),
		   .size       = ((56+128) * SZ_1M),
#endif
    },
#if defined(CONFIG_MOST2120_UBIFS_DATA)
    {
         .name       = "nand.data",                      //"userdata",
         .offset     = MTDPART_OFS_APPEND,
         .size       = MTDPART_SIZ_FULL,
    },
#endif
};
