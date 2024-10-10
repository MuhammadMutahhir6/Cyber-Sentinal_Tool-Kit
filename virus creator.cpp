#include <stdio.h>

int main() {
    // Open a file in binary write mode
    FILE *file = fopen("testfile.exe", "wb");

    // Check if the file is opened successfully
    if (!file) {
        printf("Error: Unable to create file.\n");
        return 1;
    }

    // Define the virus signature as bytes (example: VirusB's signature)
    unsigned char virus_signature[] = { 0xBA, 0xDC, 0x0F, 0xFE, 0xE0, 0xDD, 0xF0, 0x0D };

    // Write the virus signature to the file
    fwrite(virus_signature, sizeof(virus_signature), 1, file);

    // Close the file
    fclose(file);

    printf("File created successfully.\n");
    return 0;
}
