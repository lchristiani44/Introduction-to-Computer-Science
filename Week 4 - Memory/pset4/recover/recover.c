#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2) //
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *recover_file = fopen(argv[1], "r");
    if (recover_file == NULL)
    {
        return 2;
    }

    uint8_t buffer[];

    while (fread(&buffer, sizeof(buffer), 512, recover_file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (000.jpg == NULL)
            {
                sprintf(filename, "%03i.jpg", i); // sprintf print to a string
                FILE *img = fopen(filename, "w");
            }
            else
            {
                FILE *img = fclose(filename);
                sprintf(filename, "%03i.jpg", i + 1);
                FILE *img = fopen(filename, "w");
            }
        }
    }
}