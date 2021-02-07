#include "architech.h"
#include <stdlib.h>
#include <stdio.h>
#define OVERFLOW 1
#define DIVIDE_NULL 2
#define NOBOUNDS 3
#define NOIMPULSES 4
#define WRONG_COMMAND 5
int *Ram = sc_memoryInit();
int Register = sc_regInit();
int Accumulator;
int Command_counter;
int Registers[]={Register, Accumulator, Command_counter};
int *sc_memoryInit()
{
    int *arr;
    arr = (int *)calloc(100, sizeof(int));
    if (arr == NULL)
    {
        exit(-1);
    }
    return arr;
}

int sc_memorySet(int address, int value)
{
    if (address < 0 && address > 99)
    {
        return false;
    }
    Ram[address] = value;
    return true;
}

int sc_memoryGet(int address, int *value)
{
    if (address < 0 && address > 99)
    {
        return false;
    }
    value = &Ram[address];
    return true;
}

int sc_memorySave(char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        return false;
    }
    fwrite(Ram, sizeof(int), 100, file);
    fclose(file);
    return true;
}

int sc_memoryLoad(char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        return false;
    }
    fread(Ram, sizeof(int), 100, file);
    fclose(file);
    return true;
}

int sc_regInit(void)
{
    return 0;
}

int sc_regSet(int register, int value)
{
    if (value != DIVIDE_NULL && value != NOBOUNDS && value != NOIMPULSES && value != OVERFLOW && value != WRONG_COMMAND)
    {
        return false;
    }
    Register = Register | (1 << (value - 1));
    return true;
}

int sc_regGet(int register, int *value)
{
    if (*value != DIVIDE_NULL && *value != NOBOUNDS && *value != NOIMPULSES && *value != OVERFLOW && *value != WRONG_COMMAND)
    {
        return false;
    }

    return (Register >> (*value - 1)) & 0x1;
}

int sc_commandEncode (int command, int operand, int * value){
    
}

int sc_commandDecode (int value, int * command, int * operand){

}