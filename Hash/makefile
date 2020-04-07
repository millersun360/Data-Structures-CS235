  # the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  INCLUDES = -I../

  # the build target executable:
  TARGET = main

  all: $(TARGET)

  $(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS)  $(INCLUDES) $(TARGET).cpp
  clean:
	$(RM) -rf *.o *.out *.dSYM
#
