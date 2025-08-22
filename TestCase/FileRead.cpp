//****************************** UnitTest *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : FileRead.cpp
// Summary  : Unit testing for File Read
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

//********************************.FILEREADTC1.********************************
//Purpose   : Test case 1 for fileOperRead
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Valid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEREAD, FILEREADTC1)
{
    FILE *pstFileHandle = NULL;
    uint8 pucData[64] = {0};
    uint32 ulLength = 8;

    ASSERT_FALSE(fileOperRead(pstFileHandle, pucData, ulLength));
}

//********************************.FILEREADTC2.********************************
//Purpose   : Test case 2 for fileOperRead
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Invalid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEREAD, FILEREADTC2)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 *pucData = NULL;
    uint32 ulLength = 8;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_READ);
    ASSERT_FALSE(fileOperRead(pstFileHandle, pucData, ulLength));
}

//********************************.FILEREADTC3.********************************
//Purpose   : Test case 3 for fileOperRead
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Valid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEREAD, FILEREADTC3)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 pucData[64] = {0};
    uint32 ulLength = 0;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_READ);
    ASSERT_FALSE(fileOperRead(pstFileHandle, pucData, ulLength));
}

//********************************.FILEREADTC4.********************************
//Purpose   : Test case 4 for fileOperRead
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Valid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEREAD, FILEREADTC4)
{
    FILE *pstFileHandle = NULL;
    uint8 pucData[64] = {0};
    uint32 ulLength = 0;

    ASSERT_FALSE(fileOperRead(pstFileHandle, pucData, ulLength));
}

//********************************.FILEREADTC5.********************************
//Purpose   : Test case 5 for fileOperRead
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Invalid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEREAD, FILEREADTC5)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 *pucData = NULL;
    uint32 ulLength = 0;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_READ);
    ASSERT_FALSE(fileOperRead(pstFileHandle, pucData, ulLength));
}

//********************************.FILEREADTC6.********************************
//Purpose   : Test case 6 for fileOperRead
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Invalid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEREAD, FILEREADTC6)
{
    FILE *pstFileHandle = NULL;
    uint8 *pucData = NULL;
    uint32 ulLength = 8;

    ASSERT_FALSE(fileOperRead(pstFileHandle, pucData, ulLength));
}

//********************************.FILEREADTC7.********************************
//Purpose   : Test case 7 for fileOperRead
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Invalid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEREAD, FILEREADTC7)
{
    FILE *pstFileHandle = NULL;
    uint8 *pucData = NULL;
    uint32 ulLength = 0;

    ASSERT_FALSE(fileOperRead(pstFileHandle, pucData, ulLength));
}

//********************************.FILEREADTC8.********************************
//Purpose   : Test case 1 for fileOperRead
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Valid
//            ulLength - Valid
//*****************************************************************************
// TEST(FILEREAD, FILEREADTC8)
// {
//     FILE *pstFileHandle = NULL;
//     uint8 pucFileName[64] = "TestFile.txt";
//     uint8 pucData[64] = {0};
//     uint32 ulLength = 8;

//     fileOperOpen(&pstFileHandle, pucFileName, FOPEN_READ);
//     fileOperClose(pstFileHandle);
//     ASSERT_FALSE(fileOperRead(pstFileHandle, pucData, ulLength));
// }

//********************************.FILEREADTC9.********************************
//Purpose   : Test case 9 for fileOperRead
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return true, fail - function return false
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Valid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEREAD, FILEREADC9)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 pucData[64] = "Test Data For Read\r\n";
    uint32 ulLength = 8;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_WRITE);
    fileOperWrite(pstFileHandle, pucData, strlen((int8*)pucData));
    fileOperClose(pstFileHandle);

    memset(pucData, 0x00, sizeof(pucData));
    pstFileHandle = NULL;
    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_READ);
    ASSERT_TRUE(fileOperRead(pstFileHandle, pucData, ulLength));
}

// EOF