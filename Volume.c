// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define some important structures
typedef uint8_t BYTE;
typedef int16_t TWO_BYTES;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files
    FILE *input = fopeny(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    BYTE Header[HEADER_SIZE];

    // TODO: Copy header from input file to output file
    fread(Header, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(Header, sizeof(BYTE), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    TWO_BYTES buffer;

    while (fread(&buffer, sizeof(TWO_BYTES), 1, input) == 1)
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(TWO_BYTES), 1, output);
    }

    // Close files
    fclose(input);

    fclose(output);
}
