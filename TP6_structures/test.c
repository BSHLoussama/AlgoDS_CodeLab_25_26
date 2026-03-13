# include <stdio.h>

# pragma pack(0)  // directive (pre-processor)          pack(1) = (packing == True)
struct abc
{   
    char a;
    int c;
    char b;
};

// 60 * 2 = 120
int main()
{
    struct abc var1;
    int tmp;

    printf("The size of var1 is : %d", sizeof(struct abc));

    tmp = var1.c; // 2 cycles for packing; 1 cycle for padding
    // cpus don't read byte by byte, cpus read by words (1 word = 32bit in 32bit cpus)
    // 32bit = 4 bytes
    
    return 0;
}


// padding (mem = 12 bytes, cpu = 1 cycle for every field) e.g: = int takes 1 cycle
// packing (mem = 6 bytes, cpu >= 1 cycle for every field) e.g: = int takes 2 cyles