//****************************** UnitTest *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : FileOperation.c
// Summary  : File operation function. Wrapper unctions for basic file 
//            functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 14/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "FileOperation.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************
static int8 pcFileOpenMode[6][16] = 
{
    {"w"}, 
    {"r"}, 
    {"a"},
    {"w+"},
    {"r+"}, 
    {"a+"}
};

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*******************************.fileOperOpen.********************************
//Purpose   : Open a file
//Inputs    : pucFileName - File name
//Inputs    : enAccess - File open mode
//Outputs   : ppstFilePtr - Pointer to opened file
//Return    : true - File open Success, false - Failed to open file
//Notes     : None
//*****************************************************************************
bool fileOperOpen(FILE** ppstFilePtr, uint8* pucFileName, FILEACCESS enAccess)
{
    bool blReturn = false;
    
    if((NULL == *ppstFilePtr) && 
       (NULL != pucFileName) && 
       (enAccess >= FOPEN_WRITE) && 
       (enAccess <= FOPEN_APPENDPLUS))
    {
        *ppstFilePtr = fopen((int8*)pucFileName, pcFileOpenMode[enAccess]);

        if(NULL != *ppstFilePtr)
        {
            blReturn = true;
        }
    }
    
    return blReturn;
}

//*******************************.fileOperClose.*******************************
//Purpose   : Close a file
//Inputs    : pucFileName - File name
//Inputs    : enAccess - File open mode
//Outputs   : ppstFilePtr - Pointer to opened file
//Return    : true - File close Success, false - Failed to close file
//Notes     : None
//*****************************************************************************
bool fileOperClose(FILE* pstFilePtr)
{
    bool blReturn = false;
    
    if(NULL != pstFilePtr)
    {
        if(ZERO == fclose(pstFilePtr))
        {
            blReturn = true;
        }
    }

    return blReturn;
}

//*******************************.fileOperAppend.******************************
//Purpose   : Append data to a file
//Inputs    : pstFilePtr - File pointer
//Inputs    : pucData - Input data
//Inputs    : ulLength - Data length
//Outputs   : None
//Return    : true - File append Success, false - Failed to append data to file
//Notes     : None
//*****************************************************************************
bool fileOperAppend(FILE* pstFilePtr, uint8* pucData, uint32 ulLength)
{
    bool blReturn = false;
    
    if((NULL != pstFilePtr) && (NULL != pucData) && (ulLength > ZERO))
    {
        if(fwrite(pucData, sizeof(uint8), ulLength, pstFilePtr) == ulLength)
        {
            blReturn = true;
        }
    }

    return blReturn;
}

//*******************************.fileOperWrite.*******************************
//Purpose   : Write data to a file
//Inputs    : pstFilePtr - File pointer
//Inputs    : pucData - Input data
//Inputs    : ulLength - Data length
//Outputs   : None
//Return    : true - File write Success, false - Failed to write to file
//Notes     : None
//*****************************************************************************
bool fileOperWrite(FILE* pstFilePtr, uint8* pucData, uint32 ulLength)
{
    bool blReturn = false;
    
    if((NULL != pstFilePtr) && (NULL != pucData) && (ulLength > ZERO))
    {
        if(fwrite(pucData, sizeof(uint8), ulLength, pstFilePtr) == ulLength)
        {
            blReturn = true;
        }
    }

    return blReturn;
}

//*******************************.fileOperRead.********************************
//Purpose   : Read data from a file
//Inputs    : pstFilePtr - File pointer
//Inputs    : ulLength - Data length
//Outputs   : pucData - data read from file
//Return    : true - File read Success, false - Failed to read from file
//Notes     : None
//*****************************************************************************
bool fileOperRead(FILE* pstFilePtr, uint8* pucData, uint32 ulLength)
{
    bool blReturn = false;
    
    if((NULL != pstFilePtr) && (NULL != pucData) && (ulLength > ZERO))
    {
        if(fread(pucData, sizeof(uint8), ulLength, pstFilePtr) == ulLength)
        {
            blReturn = true;
        }
    }

    return blReturn;
}

//*****************************.fileOperGetSize.*******************************
//Purpose   : Get file size
//Inputs    : pstFilePtr - File pointer
//Outputs   : pulLength - size of file
//Return    : true - Got File size, false - Failed to get fil size
//Notes     : None
//*****************************************************************************
bool fileOperGetSize(FILE* pstFilePtr, uint32* pulLength)
{
    bool blReturn = false;
    
    if((NULL != pstFilePtr) && (NULL != pulLength))
    {
        fseek(pstFilePtr, 0, SEEK_END);
        *pulLength = ftell(pstFilePtr);
        blReturn = true;
    }

    return blReturn;
}