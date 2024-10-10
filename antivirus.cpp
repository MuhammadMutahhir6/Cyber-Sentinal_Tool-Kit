#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file and convert it into a hex string
char* read_file_as_hex(const char* filepath) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        printf("Unable to open file %s\n", filepath);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char*)malloc(length);
    fread(buffer, 1, length, file);
    fclose(file);

    // Allocate space for hex string (2 characters per byte)
    char *hex_string = (char*)malloc(2 * length + 1);
    for (long i = 0; i < length; i++) {
        sprintf(&hex_string[i * 2], "%02X", (unsigned char)buffer[i]);
    }
    hex_string[2 * length] = '\0';
    free(buffer);

    return hex_string;
}

// Function to check the file content against virus signatures
int check_for_virus(const char* hex_string, const char* signature) {
    if (strstr(hex_string, signature) != NULL) {
        return 1;  // Virus detected
    }
    return 0;  // No virus found
}

void scan_file(const char* filepath, const char* signature_file) {
    // Read the file contents as hex
    char *file_hex = read_file_as_hex(filepath);
    if (!file_hex) {
        return;
    }

    // Open the signature database file
    FILE *sig_file = fopen(signature_file, "r");
    if (!sig_file) {
        printf("Unable to open signature file\n");
        free(file_hex);
        return;
    }

    char line[256];
    int virus_found = 0;

    // Read each signature from the signature file
    while (fgets(line, sizeof(line), sig_file)) {
        // Remove the newline character from the line
        line[strcspn(line, "\n")] = 0;

        // Extract virus name and signature
        char *virus_name = strtok(line, ":");
        char *signature = strtok(NULL, ":");

        // Check if the signature is present in the file
        if (check_for_virus(file_hex, signature)) {
            printf("Virus detected: %s\n", virus_name);
            virus_found = 1;
            break;
        }
    }

    if (!virus_found) {
        printf("No viruses found in the file.\n");
    }

    fclose(sig_file);
    free(file_hex);
}

int main() {
    // File to be scanned and signature database
    const char *file_to_scan = "testfile.exe";
    const char *signature_file = "signatures.txt";

    printf("Scanning file: %s\n", file_to_scan);
    scan_file(file_to_scan, signature_file);

    return 0;
}
