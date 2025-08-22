//****************************** UnitTest *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : FileWrite.cpp
// Summary  : Unit testing for File Write
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

//********************************.FILEWRITETC1.*******************************
//Purpose   : Test case 1 for fileOperWrite
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Valid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEWRITE, FILEWRITETC1)
{
    FILE *pstFileHandle = NULL;
    uint8 pucData[64] = "Test Data\r\n";
    uint32 ulLength = 0;

    ulLength = strlen((int8*)pucData);
    ASSERT_FALSE(fileOperWrite(pstFileHandle, pucData, ulLength));
}

//********************************.FILEWRITETC2.*******************************
//Purpose   : Test case 2 for fileOperWrite
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Invalid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEWRITE, FILEWRITETC2)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 *pucData = NULL;
    uint32 ulLength = 64;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_WRITE);
    ASSERT_FALSE(fileOperWrite(pstFileHandle, pucData, ulLength));
}

//********************************.FILEWRITETC3.*******************************
//Purpose   : Test case 3 for fileOperWrite
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Valid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEWRITE, FILEWRITETC3)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 pucData[64] = "Test Data\r\n";
    uint32 ulLength = 0;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_WRITE);
    ASSERT_FALSE(fileOperWrite(pstFileHandle, pucData, ulLength));
}

//********************************.FILEWRITETC4.*******************************
//Purpose   : Test case 4 for fileOperWrite
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Valid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEWRITE, FILEWRITETC4)
{
    FILE *pstFileHandle = NULL;
    uint8 pucData[64] = "Test Data\r\n";
    uint32 ulLength = 0;

    ASSERT_FALSE(fileOperWrite(pstFileHandle, pucData, ulLength));
}

//********************************.FILEWRITETC5.*******************************
//Purpose   : Test case 5 for fileOperWrite
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Invalid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEWRITE, FILEWRITETC5)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 *pucData = NULL;
    uint32 ulLength = 0;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_WRITE);
    ASSERT_FALSE(fileOperWrite(pstFileHandle, pucData, ulLength));
}

//********************************.FILEWRITETC6.*******************************
//Purpose   : Test case 6 for fileOperWrite
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Invalid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEWRITE, FILEWRITETC6)
{
    FILE *pstFileHandle = NULL;
    uint8 *pucData = NULL;
    uint32 ulLength = 64;

    ASSERT_FALSE(fileOperWrite(pstFileHandle, pucData, ulLength));
}

//********************************.FILEWRITETC7.*******************************
//Purpose   : Test case 7 for fileOperWrite
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Invalid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEWRITE, FILEWRITETC7)
{
    FILE *pstFileHandle = NULL;
    uint8 *pucData = NULL;
    uint32 ulLength = 0;

    ASSERT_FALSE(fileOperWrite(pstFileHandle, pucData, ulLength));
}

//********************************.FILEWRITETC8.*******************************
//Purpose   : Test case 8 for fileOperWrite
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Valid
//            ulLength - Valid
//*****************************************************************************
// TEST(FILEWRITE, FILEWRITETC8)
// {
//     FILE *pstFileHandle = NULL;
//     uint8 pucFileName[64] = "TestFile.txt";
//     uint8 pucData[64] = "Test Data\r\n";
//     uint32 ulLength = 64;

//     ulLength = strlen((int8*)pucData);
//     fileOperOpen(&pstFileHandle, pucFileName, FOPEN_WRITE);
//     fileOperClose(pstFileHandle);
//     ASSERT_FALSE(fileOperWrite(pstFileHandle, pucData, ulLength));
// }

//********************************.FILEWRITETC1.*******************************
//Purpose   : Test case 1 for fileOperWrite
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return true, fail - function return false
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Valid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEWRITE, FILEWRITETC9)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 pucData[64] = "Test Data\r\n";
    uint32 ulLength = 0;

    ulLength = strlen((int8*)pucData);
    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_WRITE);
    ASSERT_TRUE(fileOperWrite(pstFileHandle, pucData, ulLength));
}

// EOF