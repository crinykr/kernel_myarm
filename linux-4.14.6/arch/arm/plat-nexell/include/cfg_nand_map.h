
static struct mtd_partition partition_map[] = {
	{
         .name       = "Bootloader",
         .offset     = 0,
         .size       = (256 * SZ_1K),
    },
    {
         .name       = "nand.kernel",
         .offset     = (256 * SZ_1K),
         .size       = (4 * SZ_1M) - (256 * SZ_1K),
    },
    {
         .name       = "nand.rootfs",
         .offset     = (4 * SZ_1M),
         .size       = (4 * SZ_1M),
    },
    {
         .name       = "nand.data",
         .offset     = MTDPART_OFS_APPEND,
         .size       = MTDPART_SIZ_FULL,
    },
};
