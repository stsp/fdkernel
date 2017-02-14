/****************************************************************/
/*                                                              */
/*                          version.h                           */
/*                                                              */
/*                  Common version information                  */
/*                                                              */
/*                      Copyright (c) 1997                      */
/*                      Pasquale J. Villani                     */
/*                      All Rights Reserved                     */
/*                                                              */
/* This file is part of DOS-C.                                  */
/*                                                              */
/* DOS-C is free software; you can redistribute it and/or       */
/* modify it under the terms of the GNU General Public License  */
/* as published by the Free Software Foundation; either version */
/* 2, or (at your option) any later version.                    */
/*                                                              */
/* DOS-C is distributed in the hope that it will be useful, but */
/* WITHOUT ANY WARRANTY; without even the implied warranty of   */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    */
/* the GNU General Public License for more details.             */
/*                                                              */
/* You should have received a copy of the GNU General Public    */
/* License along with DOS-C; see the file COPYING.  If not,     */
/* write to the Free Software Foundation, 675 Mass Ave,         */
/* Cambridge, MA 02139, USA.                                    */
/****************************************************************/

/* The version the kernel reports as compatible with */
/* The version of DOS kernel reported as compatible with to */
/* applications - major.minor.revision                      */
/* DOS version 7.10 with FAT32 support or 6.22 otherwise    */
#ifdef WITHFAT32
#define MAJOR_RELEASE   7
#define MINOR_RELEASE   10
#else
#define MAJOR_RELEASE   6
#define MINOR_RELEASE   22
#endif

/* The actual kernel revision */
#ifdef OEM_DOSC
/* 3000+REVISION_SEQ = 3.REVISION_SEQ */
#define REVISION_SEQ    0       /* returned in BL by int 21 function 30 */
#define OEM_ID          0xdc    /* FreeDOS, returned in BH by int 21 30 */
#define OEM_NAME "DOS-C"
#define OEM_BUILD "3."
#else
/* 2000+REVISION_SEQ = 2.REVISION_SEQ */
#define REVISION_SEQ    42      /* returned in BL by int 21 function 30 */
#define OEM_ID          0xfd    /* FreeDOS, returned in BH by int 21 30 */
#define OEM_NAME "FreeDOS"
#define OEM_BUILD "20"
#endif


/* Used for version information displayed to user at boot (& stored in os_release string) */
#ifndef KERNEL_VERSION
#define KERNEL_VERSION "- VCS " /* Version Control System, e.g. SVN,GIT,... */
#endif


/* actual version string, displayed at signon & via FD int 21h/ax=33FFh */
#define KVS(v,s,o,n,b) n " kernel " v "(build " b #s " OEM:" #o ") [compiled " __DATE__ "]\n"
#define xKVS(v,s,o,n,b) KVS(v,s,o,n,b)
#define KERNEL_VERSION_STRING xKVS(KERNEL_VERSION, REVISION_SEQ, OEM_ID, OEM_NAME, OEM_BUILD)

