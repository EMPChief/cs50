#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        // Print error message if the program does not receive the correct number of command-line
        // arguments
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the forensic image file specified on the command line
    char *input_filename = argv[1];
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        // Print error message if the forensic image file cannot be opened
        printf("Could not open file.\n");
        return 1;
    }

    // Initialize variables
    bool jpeg_file_open = false;     // Flag to track whether a JPEG file is currently being written
    int jpeg_image_index = 0;        // Counter to keep track of the number of JPEG images found
    uint8_t buffer[MAX_BUFFER_SIZE]; // Buffer to store blocks of image data
    char jpeg_file_name[8];          // Array to store the names of JPEG files
    FILE *current_jpeg_file = NULL;  // Pointer to the current JPEG file being written

    size_t num_bytes_read; // Variable to store the number of bytes read

    // Read the forensic image file block by block
    while ((num_bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, input_file)) > 0)
    {
        // Check if this block marks the start of a JPEG image
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If so, close the current JPEG file if it is open
            if (jpeg_file_open)
            {
                fclose(current_jpeg_file);
            }

            // Open a new JPEG file
            sprintf(jpeg_file_name, "%03i.jpg", jpeg_image_index); // Generate file name for the JPEG image
            current_jpeg_file = fopen(jpeg_file_name, "w");        // Open the new JPEG file
            if (current_jpeg_file == NULL)
            {
                // Print error message if the JPEG file cannot be created
                printf("Could not create %s.\n", jpeg_file_name);
                fclose(input_file);
                return 3;
            }

            jpeg_image_index++; // Increment the JPEG image index
            jpeg_file_open = true;
        }

        // Write the current block to the current JPEG file if one is open
        if (jpeg_file_open)
        {
            fwrite(buffer, 1, num_bytes_read, current_jpeg_file);
        }
    }

    // Close the forensic image file and the last JPEG file if open
    fclose(input_file);
    if (jpeg_file_open)
    {
        fclose(current_jpeg_file);
    }

    // Exit the program with status code 0 (success) if no errors were encountered
    return 0;
}
