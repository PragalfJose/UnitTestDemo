//****************************** UnitTest *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : FileSize.cpp
// Summary  : Unit testing for File Size
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

//********************************.FILESIZETC1.********************************
//Purpose   : Test case 1 for fileOperGetSize
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            ulFileSize - Invalid
//*****************************************************************************
TEST(FILESIZE, FILESIZETC1)
{
    FILE *pstFileHandle = NULL;
    uint32 *ulFileSize = NULL;

    ASSERT_FALSE(fileOperGetSize(pstFileHandle, ulFileSize));
}

//********************************.FILESIZETC2.********************************
//Purpose   : Test case 2 for fileOperGetSize
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            ulFileSize - Invalid
//*****************************************************************************
TEST(FILESIZE, FILESIZETC2)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint32 *ulFileSize = NULL;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_READ);
    ASSERT_FALSE(fileOperGetSize(pstFileHandle, ulFileSize));
}

//********************************.FILESIZETC1.********************************
//Purpose   : Test case 1 for fileOperGetSize
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            ulFileSize - Valid
//*****************************************************************************
TEST(FILESIZE, FILESIZETC3)
{
    FILE *pstFileHandle = NULL;
    uint32 ulFileSize = 0;

    ASSERT_FALSE(fileOperGetSize(pstFileHandle, &ulFileSize));
}

//********************************.FILESIZETC1.********************************
//Purpose   : Test case 1 for fileOperGetSize
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return true, fail - function return false
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            ulFileSize - Valid
//*****************************************************************************
TEST(FILESIZE, FILESIZETC4)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint32 ulFileSize = 0;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_READ);
    ASSERT_TRUE(fileOperGetSize(pstFileHandle, &ulFileSize));
}

// EOF