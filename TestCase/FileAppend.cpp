//****************************** UnitTest *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : FileAppend.cpp
// Summary  : Unit testing for File Append
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

//*******************************.FILEAPPENDTC1.*******************************
//Purpose   : Test case 1 for fileOperAppend
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Valid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEAPPEND, FILEAPPENDTC1)
{
    FILE *pstFileHandle = NULL;
    uint8 pucData[64] = "Test Data\r\n";
    uint32 ulLength = 0;

    ulLength = strlen((int8*)pucData);
    ASSERT_FALSE(fileOperAppend(pstFileHandle, pucData, ulLength));
}

//*******************************.FILEAPPENDTC2.*******************************
//Purpose   : Test case 2 for fileOperAppend
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Invalid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEAPPEND, FILEAPPENDTC2)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 *pucData = NULL;
    uint32 ulLength = 64;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_APPEND);
    ASSERT_FALSE(fileOperAppend(pstFileHandle, pucData, ulLength));
}

//*******************************.FILEAPPENDTC3.*******************************
//Purpose   : Test case 3 for fileOperAppend
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Valid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEAPPEND, FILEAPPENDTC3)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 pucData[64] = "Test Data\r\n";
    uint32 ulLength = 0;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_APPEND);
    ASSERT_FALSE(fileOperAppend(pstFileHandle, pucData, ulLength));
}

//*******************************.FILEAPPENDTC4.*******************************
//Purpose   : Test case 4 for fileOperAppend
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Valid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEAPPEND, FILEAPPENDTC4)
{
    FILE *pstFileHandle = NULL;
    uint8 pucData[64] = "Test Data\r\n";
    uint32 ulLength = 0;

    ASSERT_FALSE(fileOperAppend(pstFileHandle, pucData, ulLength));
}

//*******************************.FILEAPPENDTC5.*******************************
//Purpose   : Test case 5 for fileOperAppend
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Invalid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEAPPEND, FILEAPPENDTC5)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 *pucData = NULL;
    uint32 ulLength = 0;

    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_APPEND);
    ASSERT_FALSE(fileOperAppend(pstFileHandle, pucData, ulLength));
}

//*******************************.FILEAPPENDTC6.*******************************
//Purpose   : Test case 6 for fileOperAppend
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Invalid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEAPPEND, FILEAPPENDTC6)
{
    FILE *pstFileHandle = NULL;
    uint8 *pucData = NULL;
    uint32 ulLength = 64;

    ASSERT_FALSE(fileOperAppend(pstFileHandle, pucData, ulLength));
}

//*******************************.FILEAPPENDTC7.*******************************
//Purpose   : Test case 7 for fileOperAppend
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucData - Invalid
//            ulLength - Invalid
//*****************************************************************************
TEST(FILEAPPEND, FILEAPPENDTC7)
{
    FILE *pstFileHandle = NULL;
    uint8 *pucData = NULL;
    uint32 ulLength = 0;

    ASSERT_FALSE(fileOperAppend(pstFileHandle, pucData, ulLength));
}

//*******************************.FILEAPPENDTC8.*******************************
//Purpose   : Test case 8 for fileOperAppend
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Valid
//            ulLength - Valid
//*****************************************************************************
// TEST(FILEAPPEND, FILEAPPENDTC8)
// {
//     FILE *pstFileHandle = NULL;
//     uint8 pucFileName[64] = "TestFile.txt";
//     uint8 pucData[64] = "Test Data\r\n";
//     uint32 ulLength = 64;

//     ulLength = strlen((int8*)pucData);
//     fileOperOpen(&pstFileHandle, pucFileName, FOPEN_APPEND);
//     fileOperClose(pstFileHandle);
//     ASSERT_FALSE(fileOperAppend(pstFileHandle, pucData, ulLength));
// }

//*******************************.FILEAPPENDTC9.*******************************
//Purpose   : Test case 9 for fileOperAppend
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return true, fail - function return false
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucData - Valid
//            ulLength - Valid
//*****************************************************************************
TEST(FILEAPPEND, FILEAPPENDTC9)
{
    FILE *pstFileHandle = NULL;
    uint8 pucFileName[64] = "TestFile.txt";
    uint8 pucData[64] = "Test Data\r\n";
    uint32 ulLength = 0;

    ulLength = strlen((int8*)pucData);
    fileOperOpen(&pstFileHandle, pucFileName, FOPEN_APPEND);
    ASSERT_TRUE(fileOperAppend(pstFileHandle, pucData, ulLength));
}

// EOF