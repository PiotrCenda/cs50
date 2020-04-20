#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    //check if input is alright
    if (argc != 2)
    {
        fprintf("Usage: ./recover image\n");
        return 1;
    }

    //open card.raw and check is it is not Null
    char *card = argv[1];
    FILE *file_pointer = fopen(card, "r");

    if (file_pointer == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", card);
        return 2;
    }

    BYTE buffer[512];
    int image_number = 0;
    char *outfile_name[8];
    FILE *outfile_pointer = NULL;

    while (true)
    {
        // read a block of the memory from card
        size_t bytes_read = fread(buffer, sizeof(BYTE), 512, file_pointer);

        // break out of the loop when we reach the end of the card
        if (bytes_read == 0 && feof(file_pointer) != 0)
        {
            break;
        }

        //checking if it's jpg
        bool if_jpg;
        if_jpg = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        //if it's jpg and we have had jpg already
        if (if_jpg && outfile_pointer != NULL)
        {
            fclose(outfile_pointer);
            image_number++;
        }

        // if we found jpg, we  open new file for writing
        if (if_jpg)
        {
            sprintf(filename, "%03i.jpg", image_number);
            outfile_pointer = fopen(filename, "w");
        }

        // write anytime we have an open file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytes_read, outfile_pointer);
        }
    }

    // close last jpeg file
    fclose(outfile_pointer);

    // close infile
    fclose(file_pointer);

    return 0;
}
