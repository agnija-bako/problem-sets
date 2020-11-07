#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//Restore all images from a memory card

//SOLUTION

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check if file is not provided
    if (argc != 2)
    {
        printf("Usage: ./restore image");
        return 1;
    }

    //Open file
    FILE *file = fopen(argv[1], "r");
    //Make sure file is not null
    if (file == NULL)
    {
        return 1;
    }

    char *filename = malloc(8);
    BYTE buffer[512];
    int count = 0;
    FILE *img;

    //Read file into the to buffer array while there is data in the file
    while (fread(buffer, 512, 1, file) > 0)
    {
        //Check if a new jpg starts
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If it's not the first jpg in the file, close the prevoius
            if (count != 0)
            {
                fclose(img);
            }

            //Print jpg name into a string
            sprintf(filename, "%03i.jpg", count);
            //Open a new file
            img = fopen(filename, "w");
            //Write a new image file to create the new jpg
            fwrite(buffer, 512, 1, img);
            //Update jpg file count
            count = count + 1;

        }
        else
        {
            //If the first jpg hasn't been found yet, keep looking
            if (count == 0)
            {
                continue;
            }

            //If the first has already been found, keep writing
            else
            {
                fwrite(buffer, 512, 1, img);
            }

        }
    }

    fclose(img);
    fclose(file);
    free(filename);
}
