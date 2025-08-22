//****************************** UnitTest *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : FileOperationStub.c
// Summary  : Sample stub functions for file operation
// Note     : None
// Author   : Pragalf T Jose
// Date     : 20/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "FileOperationStub.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

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
bool fileOperOpen(FILE **ppstFilePtr, uint8* pucFileName, FILEACCESS enAccess)
{
    bool blReturn = false;
    
    return blReturn;

}

//*******************************.fileOperClose.*******************************
//Purpose   : Close a file
//Inputs    : pucFileName - File name
//Inputs    : enAccess - File open mode
//Outputs   : ppstFilePtr - Pointer to opened file
//Return    : true - File Close Success, false - Failed to Close file
//Notes     : None
//*****************************************************************************
bool fileOperClose(FILE* pstFilePtr)
{
    bool blReturn = false;
    
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
    
    return blReturn;
    
}