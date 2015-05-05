#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
using namespace std;

// Enable both ECB and CBC mode. Note this can be done before including aes.h or at compile-time.
// E.g. with GCC by using the -D flag: gcc -aes.c -DCBC=0 -DECB=1
#define CBC 0
#define ECB 1

#include "aes.h"

static void test_decrypt_ecb(void);

int main(void)
{
    test_decrypt_ecb();
    
    return 0;
}

static void test_decrypt_ecb(void)
{
    ofstream output;
    output.open("ans1-1.txt");
    char tmp_key[] = "CNS~CNS!CNS?CNS!";
    uint8_t key[sizeof(tmp_key)-1];
    for (int i = 0; i < sizeof(tmp_key); i++)
    {
       if(tmp_key[i] == '\n') key[i] = '\0';
       key[i] = tmp_key[i];
    }
    uint8_t in[]  = {0x4e, 0x17, 0xb6, 0xff, 0xd2, 0x2c, 0x19, 0xdb, 0x31, 0xa4, 0x7d, 0xf6, 0x63, 0xd3, 0x17, 0x63};
    uint8_t out[] = {0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a};
    uint8_t buffer[16];

    AES128_ECB_decrypt(in, key, buffer);

    for (int i = 0; i < 16; i++)
    {
        output << buffer[i];
    }
    output << endl;
    output.close();
}