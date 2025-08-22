//********************************* Stub **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Stub.h
// Summary  : Stub for unit testing
// Note     : None
// Author   : Pragalf T Jose
// Date     : 14/08/2025
//
//*****************************************************************************
#ifndef _FILE_OPERATION_STUB_H
#define _FILE_OPERATION_STUB_H

//******************************* Include Files *******************************
#include "Common.h"

//******************************* Global Types ********************************
typedef enum _FILEACCESS_
{
    FOPEN_WRITE, 
    FOPEN_READ,
    FOPEN_APPEND,
    FOPEN_WRITEPLUS,
    FOPEN_READPLUS,
    FOPEN_APPENDPLUS
}FILEACCESS;

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
bool fileOperOpen(FILE **ppstFilePtr, 
                       uint8* pucFileName, 
                       FILEACCESS enAccess);
bool fileOperClose(FILE* pstFilePtr);
bool fileOperAppend(FILE* pstFilePtr, uint8* pucData, uint32 ulLength);
bool fileOperWrite(FILE* pstFilePtr, uint8* pucData, uint32 ulLength);
bool fileOperRead(FILE* pstFilePtr, uint8* pucData, uint32 ulLength);
bool fileOperGetSize(FILE* pstFilePtr, uint32* pulLength);

//*********************** Inline Method Implementations ***********************

#endif // _FILE_OPERATION_STUB_H
// EOF
