#ifndef _TYPE_H
#define _TYPE_H

#define ULONG unsigned long
#define UINT  unsigned int
#define USHORT unsigned short
#define UCHAR unsigned char

#define LONG long
#define INT  int
#define SHORT short
#define CHAR char

#define UINT32 unsigned long
#define UINT16 unsigned short
#define UINT8 unsigned char

#define PUINT32 unsigned long*
#define PUINT16 unsigned short*
#define PUINT8 unsigned char*

#define UINT_64 unsigned long long
#define UINT_32 unsigned long
#define UINT_16 unsigned short
#define UINT_8 unsigned char

#define INT32  long
#define INT16  short
#define INT8  char

#define PINT32  long*
#define PINT16  short*
#define PINT8  char*
#define PVOID  void*

#define INT_32  long
#define INT_16  short
#define INT_8  char

#define PULONG ULONG*
#define PUCHAR UCHAR*

#define DWORD ULONG

#ifndef NULL
#define NULL  0
#endif

#define BOOL  bool
#define BOOLEAN bool


#if !defined(TRUE)
    #define TRUE true
#endif

#if !defined(FALSE)
    #define FALSE false
#endif

#define IN
#define OUT

#define TCHAR char

#define CString char*

#define LPSTR   char*
#define LPCTSTR char*

#define DLL_FUNC

#define TEXT

#define BIT(n)                          ((UINT_32) 1 << (n))
#define BITS(m,n)                       (~(BIT(m)-1) & ((BIT(n) - 1) | BIT(n)))


#ifndef RX_ANT_
#define RX_ANT_
typedef enum {
    AGC_RX_ANT_SEL,
    MPDU_RX_ANT_SEL,
    FIXED_0,
    FIXED_1
} RX_ANT_SEL;
#endif

#endif
