//****************************** UnitTest *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : FileOpen.cpp
// Summary  : Unit testing for File Open
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

//********************************.FILEOPENTC1.********************************
//Purpose   : Test case 1 for fileOperOpen
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucFileName - Invalid
//            enAccess - Valid
//*****************************************************************************
TEST(FILEOPEN, FILEOPENTC1)
{
    uint8 *pucFileName = NULL;
    FILE *pstFileHandle = NULL;
    FILEACCESS enAccess = FOPEN_WRITE;

    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_READ;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_APPEND;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_WRITEPLUS;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_READPLUS;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_APPENDPLUS;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
}

//********************************.FILEOPENTC2.********************************
//Purpose   : Test case 2 for fileOperOpen
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucFileName - Valid
//            enAccess - Valid
//*****************************************************************************
TEST(FILEOPEN, FILEOPENTC2)
{
    uint8 pucFileName[64] = "TestFile.txt";
    FILE *pstFileHandle;
    FILEACCESS enAccess = FOPEN_WRITE;

    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_READ;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_APPEND;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_WRITEPLUS;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_READPLUS;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_APPENDPLUS;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
}

//********************************.FILEOPENTC3.********************************
//Purpose   : Test case 3 for fileOperOpen
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucFileName - Valid
//            enAccess - Invalid
//*****************************************************************************
TEST(FILEOPEN, FILEOPENTC3)
{
    uint8 pucFileName[64] = "TestFile.txt";
    FILE *pstFileHandle = NULL;
    uint32 ulAccess = 7;

    ASSERT_FALSE(fileOperOpen(&pstFileHandle, 
                              pucFileName, 
                              static_cast<FILEACCESS>(ulAccess)));
    ulAccess = -1;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, 
                              pucFileName, 
                              static_cast<FILEACCESS>(ulAccess)));
}

//********************************.FILEOPENTC4.********************************
//Purpose   : Test case 4 for fileOperOpen
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucFileName - Invalid
//            enAccess - Valid
//*****************************************************************************
TEST(FILEOPEN, FILEOPENTC4)
{
    uint8 *pucFileName = NULL;
    FILE *pstFileHandle;
    FILEACCESS enAccess = FOPEN_WRITE;

    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_READ;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_APPEND;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_WRITEPLUS;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_READPLUS;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
    enAccess = FOPEN_APPENDPLUS;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName, enAccess));
}

//********************************.FILEOPENTC5.********************************
//Purpose   : Test case 5 for fileOperOpen
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucFileName - Valid
//            enAccess - Invalid
//*****************************************************************************
TEST(FILEOPEN, FILEOPENTC5)
{
    uint8 pucFileName[64] = "TestFile.txt";
    FILE *pstFileHandle;
    uint32 ulAccess = 7;

    ASSERT_FALSE(fileOperOpen(&pstFileHandle, 
                              pucFileName, 
                              static_cast<FILEACCESS>(ulAccess)));
    ulAccess = -1;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, 
                              pucFileName, 
                              static_cast<FILEACCESS>(ulAccess)));
}

//********************************.FILEOPENTC6.********************************
//Purpose   : Test case 6 for fileOperOpen
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucFileName - Invalid
//            enAccess - Invalid
//*****************************************************************************
TEST(FILEOPEN, FILEOPENTC6)
{
    uint8 *pucFileName = NULL;
    FILE *pstFileHandle = NULL;
    uint32 ulAccess = 7;

    ASSERT_FALSE(fileOperOpen(&pstFileHandle, 
                              pucFileName, 
                              static_cast<FILEACCESS>(ulAccess)));
    ulAccess = -1;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, 
                              pucFileName, 
                              static_cast<FILEACCESS>(ulAccess)));
}

//********************************.FILEOPENTC7.********************************
//Purpose   : Test case 7 for fileOperOpen
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Test function with, 
//            pstFileHandle - Invalid
//            pucFileName - Invalid
//            enAccess - Invalid
//*****************************************************************************
TEST(FILEOPEN, FILEOPENTC7)
{
    uint8 *pucFileName = NULL;
    FILE *pstFileHandle;
    uint32 ulAccess = 7;

    ASSERT_FALSE(fileOperOpen(&pstFileHandle, 
                              pucFileName, 
                              static_cast<FILEACCESS>(ulAccess)));
    ulAccess = -1;
    ASSERT_FALSE(fileOperOpen(&pstFileHandle, 
                              pucFileName, 
                              static_cast<FILEACCESS>(ulAccess)));
}

//********************************.FILEOPENTC8.********************************
//Purpose   : Test case 8 for fileOperOpen
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return false, fail - function return true
//Notes     : Open a non existing file in Read Mode,Test function with, 
//            pstFileHandle - Valid
//            pucFileName - Valid
//            enAccess - Valid 
//*****************************************************************************
TEST(FILEOPEN, FILEOPENTC8)
{
    uint8 pucFileName[64] = "TestReadFile.txt";
    FILE *pstFileHandle = NULL;
    FILEACCESS enAccess = FOPEN_READ;

    ASSERT_FALSE(fileOperOpen(&pstFileHandle, pucFileName,  enAccess));
}

//********************************.FILEOPENTC9.********************************
//Purpose   : Test case 9 for fileOperOpen
//Inputs    : None
//Outputs   : None
//Return    : Pass - function return true, fail - function return false
//Notes     : Test function with, 
//            pstFileHandle - Valid
//            pucFileName - Valid
//            enAccess - Valid
//*****************************************************************************
TEST(FILEOPEN, FILEOPENTC9)
{
    uint8 pucFileName[64] = "TestFile.txt";
    FILE *pstFileHandle = NULL;
    FILEACCESS enAccess = FOPEN_WRITE;

    ASSERT_TRUE(fileOperOpen(&pstFileHandle, pucFileName,  enAccess));
}

// EOF