#include <iostream>
#include <fstream>
#include <stdint.h>
#include <algorithm>

using namespace std;

uint8_t buf1[4];
uint8_t buf2[4];

int main(int argc, char* argv[])
{
    FILE* f1, * f2;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");

    uint8_t n1 = 0, n2 = 0;
    fread(buf1, sizeof(char), 4, f1);
    fread(buf2, sizeof(char), 4, f2);
    reverse(buf1, buf1 + 4);
    reverse(buf2, buf2 + 4);

    uint32_t p = *(reinterpret_cast<uint32_t*>(&buf1));
    uint32_t p2 = *(reinterpret_cast<uint32_t*>(&buf2));
    uint32_t r = p + p2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", p,p,p2,p2,r,r);
}


