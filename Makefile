# Compiler
CXX = g++
CC = gcc

# List of all sub directories
SUBDIR = FileOperation TestCase
STUBDIR = FileOperationStub Common
# List of all include directories with header file
INCDIR = FileOperation TestCase Common

# Flags with include path
CXXFLAGS = -O0 -g -Wall -Werror -Wextra $(foreach D,$(INCDIR),-I$(D))
STUBFLAG = $(foreach D,$(STUBDIR),-I$(D))
#gtest library
LDFLAGS  = -lgtest_main -lgtest
LPATH = -L /usr/local/lib

# Sources
CSOURCES = $(foreach D,$(SUBDIR),$(wildcard $(D)/*.c))
STUBSOURCES = $(foreach D,$(STUBDIR),$(wildcard $(D)/*.c))
CPPSOURCES = $(foreach D,$(SUBDIR),$(wildcard $(D)/*.cpp))
file_names = $(notdir $(CSOURCES))

OBJECTS = $(patsubst %.c,%.o,$(file_names))

VPATH = .:Common:FileOperation:FileOperationStub

# Output target
TARGET = testcase_File
TARGET_STUB = teststub_File

# Build rule
all : $(TARGET)

$(TARGET): Object $(CPPSOURCES)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(CPPSOURCES) -o $(TARGET) $(LDFLAGS)

stub : $(STUBSOURCES) $(CPPSOURCES)
	$(CC) -c $(STUBFLAG) $(STUBSOURCES) -D STUB -o FileOperationStub.o
	$(CXX) $(STUBFLAG) FileOperationStub.o $(CPPSOURCES) -D STUB -o $(TARGET_STUB) $(LDFLAGS)

Object : $(OBJECTS)
# 	$(CC) -c $(CXXFLAGS) $(CSOURCES) -o FileOperation.o
%.o : %.c
	$(CC) $(CXXFLAGS) -c $^ -o $@
	
# Run tests
run: $(TARGET)
	./$(TARGET)

# Clean
clean:
	rm -f $(TARGET)
	rm -f $(TARGET_STUB)
	rm -f Result
	find . -type f -name "*.o" -delete
	