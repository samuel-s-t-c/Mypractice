
prog:     file format elf64-x86-64
prog
architecture: i386:x86-64, flags 0x00000150:
HAS_SYMS, DYNAMIC, D_PAGED
start address 0x00000000000004f0

Program Header:
    PHDR off    0x0000000000000040 vaddr 0x0000000000000040 paddr 0x0000000000000040 align 2**3
         filesz 0x00000000000001f8 memsz 0x00000000000001f8 flags r--
  INTERP off    0x0000000000000238 vaddr 0x0000000000000238 paddr 0x0000000000000238 align 2**0
         filesz 0x000000000000001c memsz 0x000000000000001c flags r--
    LOAD off    0x0000000000000000 vaddr 0x0000000000000000 paddr 0x0000000000000000 align 2**21
         filesz 0x0000000000000810 memsz 0x0000000000000810 flags r-x
    LOAD off    0x0000000000000df0 vaddr 0x0000000000200df0 paddr 0x0000000000200df0 align 2**21
         filesz 0x0000000000000228 memsz 0x0000000000000230 flags rw-
 DYNAMIC off    0x0000000000000e00 vaddr 0x0000000000200e00 paddr 0x0000000000200e00 align 2**3
         filesz 0x00000000000001c0 memsz 0x00000000000001c0 flags rw-
    NOTE off    0x0000000000000254 vaddr 0x0000000000000254 paddr 0x0000000000000254 align 2**2
         filesz 0x0000000000000044 memsz 0x0000000000000044 flags r--
EH_FRAME off    0x00000000000006b4 vaddr 0x00000000000006b4 paddr 0x00000000000006b4 align 2**2
         filesz 0x0000000000000044 memsz 0x0000000000000044 flags r--
   STACK off    0x0000000000000000 vaddr 0x0000000000000000 paddr 0x0000000000000000 align 2**4
         filesz 0x0000000000000000 memsz 0x0000000000000000 flags rw-
   RELRO off    0x0000000000000df0 vaddr 0x0000000000200df0 paddr 0x0000000000200df0 align 2**0
         filesz 0x0000000000000210 memsz 0x0000000000000210 flags r--

Dynamic Section:
  NEEDED               libc.so.6
  INIT                 0x00000000000004b8
  FINI                 0x00000000000006a4
  INIT_ARRAY           0x0000000000200df0
  INIT_ARRAYSZ         0x0000000000000008
  FINI_ARRAY           0x0000000000200df8
  FINI_ARRAYSZ         0x0000000000000008
  GNU_HASH             0x0000000000000298
  STRTAB               0x0000000000000348
  SYMTAB               0x00000000000002b8
  STRSZ                0x000000000000007d
  SYMENT               0x0000000000000018
  DEBUG                0x0000000000000000
  PLTGOT               0x0000000000200fc0
  RELA                 0x00000000000003f8
  RELASZ               0x00000000000000c0
  RELAENT              0x0000000000000018
  FLAGS                0x0000000000000008
  FLAGS_1              0x0000000008000001
  VERNEED              0x00000000000003d8
  VERNEEDNUM           0x0000000000000001
  VERSYM               0x00000000000003c6
  RELACOUNT            0x0000000000000003

Version References:
  required from libc.so.6:
    0x09691a75 0x00 02 GLIBC_2.2.5

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .interp       0000001c  0000000000000238  0000000000000238  00000238  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  1 .note.ABI-tag 00000020  0000000000000254  0000000000000254  00000254  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  2 .note.gnu.build-id 00000024  0000000000000274  0000000000000274  00000274  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .gnu.hash     0000001c  0000000000000298  0000000000000298  00000298  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .dynsym       00000090  00000000000002b8  00000000000002b8  000002b8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .dynstr       0000007d  0000000000000348  0000000000000348  00000348  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  6 .gnu.version  0000000c  00000000000003c6  00000000000003c6  000003c6  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  7 .gnu.version_r 00000020  00000000000003d8  00000000000003d8  000003d8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  8 .rela.dyn     000000c0  00000000000003f8  00000000000003f8  000003f8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  9 .init         00000017  00000000000004b8  00000000000004b8  000004b8  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 10 .plt          00000010  00000000000004d0  00000000000004d0  000004d0  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 11 .plt.got      00000008  00000000000004e0  00000000000004e0  000004e0  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 12 .text         000001b2  00000000000004f0  00000000000004f0  000004f0  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 13 .fini         00000009  00000000000006a4  00000000000006a4  000006a4  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 14 .rodata       00000004  00000000000006b0  00000000000006b0  000006b0  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 15 .eh_frame_hdr 00000044  00000000000006b4  00000000000006b4  000006b4  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 16 .eh_frame     00000118  00000000000006f8  00000000000006f8  000006f8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 17 .init_array   00000008  0000000000200df0  0000000000200df0  00000df0  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 18 .fini_array   00000008  0000000000200df8  0000000000200df8  00000df8  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 19 .dynamic      000001c0  0000000000200e00  0000000000200e00  00000e00  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 20 .got          00000040  0000000000200fc0  0000000000200fc0  00000fc0  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 21 .data         00000018  0000000000201000  0000000000201000  00001000  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 22 .bss          00000008  0000000000201018  0000000000201018  00001018  2**0
                  ALLOC
 23 .comment      0000002b  0000000000000000  0000000000000000  00001018  2**0
                  CONTENTS, READONLY
SYMBOL TABLE:
0000000000000238 l    d  .interp	0000000000000000              .interp
0000000000000254 l    d  .note.ABI-tag	0000000000000000              .note.ABI-tag
0000000000000274 l    d  .note.gnu.build-id	0000000000000000              .note.gnu.build-id
0000000000000298 l    d  .gnu.hash	0000000000000000              .gnu.hash
00000000000002b8 l    d  .dynsym	0000000000000000              .dynsym
0000000000000348 l    d  .dynstr	0000000000000000              .dynstr
00000000000003c6 l    d  .gnu.version	0000000000000000              .gnu.version
00000000000003d8 l    d  .gnu.version_r	0000000000000000              .gnu.version_r
00000000000003f8 l    d  .rela.dyn	0000000000000000              .rela.dyn
00000000000004b8 l    d  .init	0000000000000000              .init
00000000000004d0 l    d  .plt	0000000000000000              .plt
00000000000004e0 l    d  .plt.got	0000000000000000              .plt.got
00000000000004f0 l    d  .text	0000000000000000              .text
00000000000006a4 l    d  .fini	0000000000000000              .fini
00000000000006b0 l    d  .rodata	0000000000000000              .rodata
00000000000006b4 l    d  .eh_frame_hdr	0000000000000000              .eh_frame_hdr
00000000000006f8 l    d  .eh_frame	0000000000000000              .eh_frame
0000000000200df0 l    d  .init_array	0000000000000000              .init_array
0000000000200df8 l    d  .fini_array	0000000000000000              .fini_array
0000000000200e00 l    d  .dynamic	0000000000000000              .dynamic
0000000000200fc0 l    d  .got	0000000000000000              .got
0000000000201000 l    d  .data	0000000000000000              .data
0000000000201018 l    d  .bss	0000000000000000              .bss
0000000000000000 l    d  .comment	0000000000000000              .comment
0000000000000000 l    df *ABS*	0000000000000000              crtstuff.c
0000000000000520 l     F .text	0000000000000000              deregister_tm_clones
0000000000000560 l     F .text	0000000000000000              register_tm_clones
00000000000005b0 l     F .text	0000000000000000              __do_global_dtors_aux
0000000000201018 l     O .bss	0000000000000001              completed.7697
0000000000200df8 l     O .fini_array	0000000000000000              __do_global_dtors_aux_fini_array_entry
00000000000005f0 l     F .text	0000000000000000              frame_dummy
0000000000200df0 l     O .init_array	0000000000000000              __frame_dummy_init_array_entry
0000000000000000 l    df *ABS*	0000000000000000              main.c
0000000000000000 l    df *ABS*	0000000000000000              sum.c
0000000000000000 l    df *ABS*	0000000000000000              crtstuff.c
000000000000080c l     O .eh_frame	0000000000000000              __FRAME_END__
0000000000000000 l    df *ABS*	0000000000000000              
0000000000200df8 l       .init_array	0000000000000000              __init_array_end
0000000000200e00 l     O .dynamic	0000000000000000              _DYNAMIC
0000000000200df0 l       .init_array	0000000000000000              __init_array_start
00000000000006b4 l       .eh_frame_hdr	0000000000000000              __GNU_EH_FRAME_HDR
0000000000200fc0 l     O .got	0000000000000000              _GLOBAL_OFFSET_TABLE_
00000000000006a0 g     F .text	0000000000000002              __libc_csu_fini
0000000000000000  w      *UND*	0000000000000000              _ITM_deregisterTMCloneTable
0000000000201000  w      .data	0000000000000000              data_start
0000000000201010 g     O .data	0000000000000008              array
0000000000201018 g       .data	0000000000000000              _edata
00000000000006a4 g     F .fini	0000000000000000              _fini
0000000000000000       F *UND*	0000000000000000              __libc_start_main@@GLIBC_2.2.5
0000000000201000 g       .data	0000000000000000              __data_start
0000000000000000  w      *UND*	0000000000000000              __gmon_start__
0000000000201008 g     O .data	0000000000000000              .hidden __dso_handle
0000000000000614 g     F .text	000000000000001b              sum
00000000000006b0 g     O .rodata	0000000000000004              _IO_stdin_used
0000000000000630 g     F .text	0000000000000065              __libc_csu_init
0000000000201020 g       .bss	0000000000000000              _end
00000000000004f0 g     F .text	000000000000002b              _start
0000000000201018 g       .bss	0000000000000000              __bss_start
00000000000005fa g     F .text	000000000000001a              main
0000000000201018 g     O .data	0000000000000000              .hidden __TMC_END__
0000000000000000  w      *UND*	0000000000000000              _ITM_registerTMCloneTable
0000000000000000  w    F *UND*	0000000000000000              __cxa_finalize@@GLIBC_2.2.5
00000000000004b8 g     F .init	0000000000000000              _init


