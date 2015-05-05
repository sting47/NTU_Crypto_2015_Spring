#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Enable both ECB and CBC mode. Note this can be done before including aes.h or at compile-time.
// E.g. with GCC by using the -D flag: gcc -c aes.c -DCBC=0 -DECB=1
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
    output.open("ans1-2.txt");
    uint8_t in[]  = {0x18, 0x89, 0x74, 0x16, 0xb1, 0x4e, 0x8d, 0x53, 0x9a, 0x8f, 0xfc, 0x23, 0x49, 0x0a, 0x39, 0xb8};
    uint8_t buffer[16];
    int three[16];
    for (int i = 0; i < 16; i++) // calculate 3^0, 3^1, ..., 3^15
    {
        three[i] = pow(3, i);
    }
    uint8_t key[16];
    for (int i = 0; i < pow(3, 16); i++) // try the 3^16 possibilities
    {
        if ( i % 3000000 == 0 ) { cout << "Still processing...please wait" << endl; }
        int yushu, chu;
        chu = i / three[15];
        yushu = i % three[15];
        switch(chu)
        {
            case 0 :
            {
                key[0] = 0x43; // C
                break;
            }
            case 1 :
            {
                key[0] = 0x4e; // N
                break;
            }
            case 2 :
            {
                key[0] = 0x53; // S
                break;
            }
        }
        for (int j = 1; j < 16; j++)
        {
            chu = yushu / three[15-j];
            yushu = yushu % three[15-j];
            switch(chu)
            {
                case 0 :
                {
                    key[j] = 0x43;
                    break;
                }
                case 1 :
                {
                    key[j] = 0x4e;
                    break;
                }
                case 2 :
                {
                    key[j] = 0x53;
                    break;
                }
            }
        }
        // cout << key << endl;
        AES128_ECB_decrypt(in, key, buffer);
        if ( buffer[0]==0x43 && buffer[1]==0x4e && buffer[2]==0x53 ) // compare the buffer first 3 characters
        {
            for (int x = 0; x < 16; x++)
            {
              output << buffer[x];
            }
            output << endl;
            break;
        }
    }
    output.close();
}
