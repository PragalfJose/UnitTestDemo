//****************************** UnitTest *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : FileClose.cpp
// Summary  : Unit testing for File Close
// Note     : None
// Author   : Pragalf T Jose
// Date     : 20/08/2025
//
//*****************************************************************************
//******************************* Include Files *******************************
// my_module_test.cpp
#include "gtest/gtest.h"

// Include the C header using extern "C"
extern "C" 
{
    #ifndef STUB
    #include "FileOperation.h"
    #else
    #include "FileOperationStub.h"
    #endif
}

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*********************** Class Method Implementations ************************

//*******************************.FILECLOSETC1.********************************
//Purpose   : Test case 1 for fileOperClose
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//*****************************************************************************
TEST(FILECLOSE, FILECLOSETC1)
{
    FILE *pstFileHandle = NULL;

    ASSERT_FALSE(fileOperClose(pstFileHandle));
}

//*******************************.FILECLOSETC2.********************************
//Purpose   : Test case 2 for fileOperClose
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//*****************************************************************************
TEST(FILECLOSE, FILECLOSETC2)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_WRITE);

    ASSERT_TRUE(fileOperClose(pstFileHandle));
}

// EOF