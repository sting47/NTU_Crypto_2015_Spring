#CC           = avr-gcc
#CFLAGS       = -Wall -mmcu=atmega16 -Os -Wl,-Map,test.map
#OBJCOPY      = avr-objcopy
CC           = gcc
CCC	     = g++
#CFLAGS       = -Wall -Os -Wl,-Map,test.map
#OBJCOPY      = objcopy

# include path to AVR library
INCLUDE_PATH = /usr/lib/avr/include
# splint static check
#SPLINT       = splint test.c aes.c -I$(INCLUDE_PATH) +charindex -unrecog

.SILENT:
.PHONY:  lint clean

code1-1.o : code1-1.cpp
	$(CCC) -c code1-1.cpp -o code1-1.o

code1-2.o : code1-2.cpp
	$(CCC) -c code1-2.cpp -o code1-2.o

aes.o : aes.h aes.c
	# compiling aes.c
	$(CCC) -c aes.c -o aes.o

code1-1.out : aes.o code1-1.o
	$(CCC) aes.o code1-1.o -o code1-1.out

code1-2.out : aes.o code1-2.o
	$(CCC) aes.o code1-2.o -o code1-2.out

code2-1.out : code2-1.cpp
	$(CCC) -std=c++11 -o code2-1.out code2-1.cpp

code2-2.out : code2-2.cpp
	$(CCC) -std=c++11 -o code2-2.out code2-2.cpp

code2-2_BG.out : code2-2_BG.cpp
	$(CCC) -std=c++11 -o code2-2_BG.out code2-2_BG.cpp

code3-1.out : code3-1.cpp
	$(CCC) -std=c++11 -o code3-1.out code3-1.cpp
code3-2.out : code3-2.cpp
	$(CCC) -std=c++11 -o code3-2.out code3-2.cpp

clean:
	rm -f *.OBJ *.LST *.o *.gch *.out *.hex *.map
