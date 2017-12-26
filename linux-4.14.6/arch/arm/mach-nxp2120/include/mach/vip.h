//------------------------------------------------------------------------------
//
// VIP device header file
// Copyright (C) Nexell Co. 2010
//
// module     :
// File       :
// Description:
// Author     :
// Export     :
// History    :
//------------------------------------------------------------------------------
#ifndef __NX_VIP_DEV_H__
#define __NX_VIP_DEV_H__

#define	VIP_MAX_MODULE		2
#define	VIP_MAX_PORT		2
#define	VIP_MAX_DECODER		2

enum {
	VIP_CLIPPER		= 0,
	VIP_DECIMATOR	= 1
};

#define	VIP_ROTATE_ENABLE	(1<<0)
#define	VIP_H_FLIP_ENABLE	(1<<1)
#define	VIP_V_FLIP_ENABLE	(1<<2)

struct vip_param {
	int				port;		/* 0, 1 */
	int				outdev;		/* Clipper = 0, Decimator = 1 */
	unsigned int	fourcc;		/* 420, 422, 444, YUYV */
	int				left;		/* clip left  , note> multiple 16, must be less than horizontal active width */
	int				top;		/* clip top    */
	int				right;		/* clip right , note> multiple 16, must be less than horizontal active width */
	int				bottom;		/* clip bottom */
	int				scale_w;	/* scale down width , note> multiple 16 */
	int				scale_h;	/* scale down height */
	unsigned int	rotate;		/* 0 = none,
								 * VIP_ROTATE_ENABLE = 90 rotate,
								 * VIP_H_FLIP_ENABLE = vertical flip,
								 * VIP_V_FLIP_ENABLE = horizontal flip */
};

struct vip_prop {
	int				interlace;
	int				video_type; /* Video type : -1=unknown, 0=NTSC, 1=PAL, 2 = others */
	int 			h_active;		/* horizontal active width */
	int 			v_active;	/* vertical active height  */
	unsigned int 	fps;		/* frame per second */
};

struct vip_buffer {
	/* In : buffer address */
	unsigned int	lu_a;
	unsigned int	cb_a;
	unsigned int	cr_a;
	unsigned int	lu_s;
	unsigned int	cb_s;
	unsigned int	cr_s;
	/* Out: buffer status */
	int				v_type;		/* Video type 0=NTSC, 1=PAL, 2 = others */
	int				h_cnt;		/* horizontal count value */
	int				v_cnt;		/* vertical count value */
	long long		timestamp;	/* unit: msec*/
};

/*------------------------------------------------------------------------------
 * Macro: IoCTL
 */
#include "ioc_magic.h"

enum {
	IOCTL_VIP_DEV_INIT		= _IO(IOC_NX_MAGIC,  1),
	IOCTL_VIP_DEV_EXIT		= _IO(IOC_NX_MAGIC,  2),
	IOCTL_VIP_DEV_RUN		= _IO(IOC_NX_MAGIC,  3),
	IOCTL_VIP_DEV_STOP		= _IO(IOC_NX_MAGIC,  4),
	IOCTL_VIP_DEV_WAIT		= _IO(IOC_NX_MAGIC,  5),

	IOCTL_VIP_BUF_PREPARE	= _IO(IOC_NX_MAGIC,  6),
	IOCTL_VIP_BUF_UPDATE	= _IO(IOC_NX_MAGIC,  7),

	IOCTL_VIP_VID_GET_PROP	= _IO(IOC_NX_MAGIC,  8),	/* get current video property */

	IOCTL_VIP_VID_SET_PORT	= _IO(IOC_NX_MAGIC,  9),
	IOCTL_VIP_VID_GET_PORT	= _IO(IOC_NX_MAGIC, 10),

	IOCTL_VIP_VID_SET_TYPE	= _IO(IOC_NX_MAGIC, 11),	/* select video type, ex> -1=unknown, 0=NTSC, 1=PAL */
	IOCTL_VIP_VID_GET_TYPE	= _IO(IOC_NX_MAGIC, 12),	/* get current video type, ex> -1=unknown, 0=NTSC, 1=PAL */

	IOCTL_VIP_VID_SET_DEC	= _IO(IOC_NX_MAGIC, 13),	/* select video decoder */
	IOCTL_VIP_VID_GET_DEC	= _IO(IOC_NX_MAGIC, 14),	/* get current video decoder num */
};

#endif // __NX_VIP_DEV_H__

