#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

const int BLOCKSIZE = 512;

typedef uint8_t BYTE;

int Error()
    {
        printf("Usage ./recover image\n");
        return 1;
    }

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return Error();
    }

    FILE* InputFile = fopen(argv[1], "r");

    if (InputFile == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    BYTE memory[BLOCKSIZE];

    char output_file_name[8];
    int counter = 0;

    FILE* OutputFile = NULL;

    while (fread(memory, sizeof(BYTE), BLOCKSIZE, InputFile) == BLOCKSIZE)
    {
        if (memory[0] == 0xff && memory[1] == 0xd8 && memory[2] == 0xff && (memory[3] & 0xf0) == 0xe0)
        {
            if (OutputFile != NULL)
            {
                fclose(OutputFile);
            }

            sprintf(output_file_name, "%03i.jpg", counter);
            OutputFile = fopen(output_file_name, "w");

            counter++;
        }


        if (OutputFile != NULL)
        {
            fwrite(memory, sizeof(memory), 1, OutputFile);
        }
    }
    
    if (feof(InputFile) != 0)
    {
        fclose(InputFile);
        fclose(OutputFile);
    }

    return 0;
}