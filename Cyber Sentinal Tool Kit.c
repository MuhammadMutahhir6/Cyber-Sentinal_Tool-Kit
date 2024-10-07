#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep and usleep functions

// ANSI Color Codes for terminal output
#define RESET   "\033[0m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define CYAN    "\033[0;36m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

// Define MAX_ATTEMPTS and LOCKOUT_TIME for login system
#define MAX_ATTEMPTS 3
#define LOCKOUT_TIME 10
#define MAX_WORD_LENGTH 100

// Function to log actions to a file
void log_action(const char *action) {
    FILE *log_file = fopen("program_log.txt", "a");
    if (log_file) {
        time_t current_time = time(NULL);
        fprintf(log_file, "[%s] %s\n", ctime(&current_time), action);
        fclose(log_file);
    }
}

// Utility Functions
void clear_screen() {
    printf("\033[2J\033[H");
}

void display_intro() {
    clear_screen();
    printf(GREEN "=====================================\n" RESET);
    printf(CYAN "University Name: " GREEN "Fast Nuces\n" RESET);
    printf(CYAN "Subject: " GREEN "Programming Fundamentals\n" RESET);
    printf(CYAN "Teacher Name: " GREEN "Noman Hanif\n" RESET);
    printf(GREEN "=====================================\n" RESET);
    printf(CYAN "Group Members:\n" RESET);
    printf(CYAN "Hasnain Memon   (24k-2001)\n" RESET);
    printf(CYAN "Muhammad Mutahir (24k-2005)\n" RESET);
    printf(GREEN "=====================================\n" RESET);
    printf("\n\nPress ENTER to continue...");
    getchar();  // Wait for user to press Enter
    log_action("Displayed intro");
}

void display_banner() {
    printf(GREEN "=====================================\n" RESET);
    printf(CYAN  "      All-in-One Kali Linux Tools    \n" RESET);
    printf(GREEN "=====================================\n" RESET);
}

void loading_animation() {
    for (int i = 0; i < 3; i++) {
        printf(GREEN "." RESET);
        fflush(stdout);
        usleep(500000);  // 0.5 seconds delay
    }
    printf("\n");
}

// Login Functions
int check_password(const char *input_password) {
    const char *correct_password = "password123";
    return strcmp(input_password, correct_password) == 0;
}

void display_header() {
    printf(GREEN "====================================================\n" RESET);
    printf(CYAN "         Welcome to the Secure Login System         \n" RESET);
    printf(GREEN "====================================================\n" RESET);
}

void display_success() {
    clear_screen();
    printf(GREEN "====================================================\n" RESET);
    printf(GREEN "              LOGIN SUCCESSFUL! WELCOME              \n" RESET);
    printf(GREEN "====================================================\n" RESET);
    loading_animation();
    log_action("Login successful");
}

// Main menu of tools
void display_tools_menu() {
    clear_screen();
    display_banner();
    printf(YELLOW "Select a tool to use:\n" RESET);
    printf(CYAN "1. Brute Force Attack Simulator\n" RESET);
    printf(CYAN "2. Basic File Encryption Tool\n" RESET);
    printf(CYAN "3. Basic File Decryption Tool\n" RESET);
    printf(CYAN "4. Dictionary Attack Tool\n" RESET);  // Updated Dictionary Tool
    printf(CYAN "5. Password Generator\n" RESET);
    printf(CYAN "6. Password Strength Checker\n" RESET);
    printf(CYAN "7. HexSecure: Secure Your Files\n" RESET);
    printf(CYAN "8. Secure File Eraser (Shredder)\n" RESET);
    printf(CYAN "9. Binary File Creator (Virus Creator)\n" RESET);
    printf(YELLOW "10. Exit\n" RESET);
    printf(GREEN "\nChoose a tool (1-10): " RESET);
    log_action("Displayed tools menu");
}

void login_system() {
    char password[100];
    int attempts = 0;
    time_t lockout_start;

    clear_screen();
    display_header();

    while (1) {
        if (attempts >= MAX_ATTEMPTS) {
            time_t current_time = time(NULL);
            int lockout_duration = (int)(current_time - lockout_start);

            if (lockout_duration < LOCKOUT_TIME) {
                printf(RED "Too many failed attempts! You are locked out for %d seconds.\n" RESET, LOCKOUT_TIME - lockout_duration);
                sleep(1);
                continue;
            } else {
                printf(GREEN "Lockout period is over. You can try again.\n" RESET);
                attempts = 0;
            }
        }

        printf(BLUE "\nEnter your password: " RESET);
        scanf("%s", password);

        if (check_password(password)) {
            display_success();
            break;
        } else {
            attempts++;
            printf(YELLOW "Incorrect password! You have %d attempt(s) remaining.\n" RESET, MAX_ATTEMPTS - attempts);
            if (attempts >= MAX_ATTEMPTS) {
                printf(RED "Too many failed attempts! Locking out for %d seconds...\n" RESET, LOCKOUT_TIME);
                lockout_start = time(NULL);
            }
        }
    }
}

// Tool 1: Simple Brute Force Attack Simulator
int increment_password(char *password, int max_length, const char *charset, int charset_size) {
    int i = strlen(password) - 1;

    while (i >= 0) {
        int pos = strchr(charset, password[i]) - charset;
        if (pos < charset_size - 1) {
            password[i] = charset[pos + 1];
            return 1;
        } else {
            password[i] = charset[0];
            i--;
        }
    }

    if (strlen(password) < max_length) {
        memset(password, charset[0], strlen(password));
        password[strlen(password)] = charset[0];
        password[strlen(password) + 1] = '\0';
        return 1;
    }

    return 0;
}

void brute_force_simulator() {
    clear_screen();
    printf(GREEN "Brute Force Attack Simulator\n" RESET);

    char target_password[100];
    char charset[] = "abcdefghijklmnopqrstuvwxyz";
    int charset_size = strlen(charset);
    int max_length;
    char guess[100] = "";
    int attempts = 0;
    clock_t start_time, end_time;

    printf("\nEnter the target password (lowercase letters only): ");
    scanf("%s", target_password);
    printf("Enter the maximum password length to attempt: ");
    scanf("%d", &max_length);

    guess[0] = charset[0];
    guess[1] = '\0';
    start_time = clock();

    while (1) {
        attempts++;

        if (strcmp(guess, target_password) == 0) {
            end_time = clock();
            double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            printf(GREEN "\nPassword cracked: %s\n" RESET, guess);
            printf(GREEN "Total attempts: %d\n" RESET, attempts);
            printf(GREEN "Time taken: %.2f seconds\n" RESET, time_taken);
            break;
        }

        if (!increment_password(guess, max_length, charset, charset_size)) {
            printf(RED "\nFailed to crack the password within the given parameters.\n" RESET);
            break;
        }

        if (attempts % 100000 == 0) {
            printf(YELLOW "Attempts: %d, Current guess: %s\r" RESET, attempts, guess);
            fflush(stdout);
        }
    }
    log_action("Brute Force Attack Simulator executed");
    printf("\nPress enter to return to menu...");
    getchar(); getchar();
}

// Tool 2: Basic File Encryption Tool (XOR Encryption)
void file_encryption_tool() {
    clear_screen();
    printf(GREEN "Basic File Encryption Tool\n" RESET);

    char input_file[100], output_file[100], key[100];
    FILE *infile, *outfile;
    unsigned char buffer;
    int key_length, i = 0;

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);
    printf("Enter encryption key: ");
    scanf("%s", key);

    key_length = strlen(key);
    infile = fopen(input_file, "rb");
    outfile = fopen(output_file, "wb");

    if (!infile || !outfile) {
        printf(RED "Error: Could not open files.\n" RESET);
        return;
    }

    while (fread(&buffer, 1, 1, infile)) {
        buffer ^= key[i % key_length];  // XOR with key
        fwrite(&buffer, 1, 1, outfile);
        i++;
    }

    fclose(infile);
    fclose(outfile);
    printf(GREEN "File encryption completed.\n" RESET);
    log_action("File Encryption Tool executed");
    printf("\nPress enter to return to menu...");
    getchar(); getchar();
}

// Tool: File Decryption Tool (XOR Decryption)
void file_decryption_tool() {
    clear_screen();
    printf(GREEN "Basic File Decryption Tool\n" RESET);

    char input_file[100], output_file[100], key[100];
    FILE *infile, *outfile;
    unsigned char buffer;
    int key_length, i = 0;

    printf("Enter encrypted file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);
    printf("Enter decryption key: ");
    scanf("%s", key);

    key_length = strlen(key);
    infile = fopen(input_file, "rb");
    outfile = fopen(output_file, "wb");

    if (!infile || !outfile) {
        printf(RED "Error: Could not open files.\n" RESET);
        return;
    }

    while (fread(&buffer, 1, 1, infile)) {
        buffer ^= key[i % key_length];  // XOR with key to decrypt
        fwrite(&buffer, 1, 1, outfile);
        i++;
    }

    fclose(infile);
    fclose(outfile);
    printf(GREEN "File decryption completed.\n" RESET);
    log_action("File Decryption Tool executed");
    printf("\nPress enter to return to menu...");
    getchar(); getchar();
}

// Tool 3: Dictionary Attack Tool
void dictionary_password_crack() {
    clear_screen();
    printf(GREEN "Dictionary Password Crack\n" RESET);
}

void loadingAnimation() {
    printf(YELLOW "\n[INFO] Loading dictionary" RESET);
    fflush(stdout);
    for (int i = 0; i < 5; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

void dictionary_attack_tool() {
    char enteredPassword[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE *file;
    
    // Print welcome banner
    dictionary_password_crack();
    
    // Prompt user to enter a password
    printf(CYAN BOLD "\nEnter the password you want to crack: " RESET);
    scanf("%s", enteredPassword);
    
    // Simulate loading process
    loadingAnimation();
    
    // Open the dictionary file
    file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf(RED BOLD "\nError: Could not open dictionary file.\n" RESET);
        return;
    }

    // Search through dictionary
    printf(CYAN BOLD "\n[INFO] Searching for the password...\n\n" RESET);
    sleep(1);  // Simulating search time

    while (fgets(word, sizeof(word), file) != NULL) {
        // Remove newline character from the word, if any
        word[strcspn(word, "\n")] = '\0';

        // Compare entered password with dictionary words
        if (strcmp(enteredPassword, word) == 0) {
            printf(GREEN BOLD "\n[SUCCESS] Password found: " RESET UNDERLINE "%s\n" RESET, word);
            fclose(file);getch();
            return;
        }

        // Displaying each checked word (for user excitement)
        printf(YELLOW "[CHECKING] " RESET "Attempting: %s\n", word);
        sleep(1);  // Simulating delay for more realism
    }

    // If no password match is found
    printf(RED BOLD "\n[FAILURE] Password not found in the dictionary.\n" RESET);

    fclose(file);
    printf("\nPress enter to return to menu...");
    getchar(); getchar();
}

// Tool 4: Password Generator
void password_generator() {
    clear_screen();
    printf(GREEN "Password Generator\n" RESET);

    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    int length, charset_size = strlen(charset);
    char password[100];

    printf("Enter the desired password length: ");
    scanf("%d", &length);

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_size];
    }
    password[length] = '\0';

    printf(GREEN "Generated password: %s\n" RESET, password);
    log_action("Password Generator executed");
    printf("\nPress enter to return to menu...");
    getchar(); getchar();
}

// Tool 5: Password Strength Checker
void password_strength_checker() {
    clear_screen();
    printf(GREEN "Password Strength Checker\n" RESET);

    char password[100];
    int length, has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    printf("Enter password to check strength: ");
    scanf("%s", password);

    length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') has_upper = 1;
        if (password[i] >= 'a' && password[i] <= 'z') has_lower = 1;
        if (password[i] >= '0' && password[i] <= '9') has_digit = 1;
        if (strchr("!@#$%^&*()", password[i])) has_special = 1;
    }

    printf(GREEN "Password Strength: " RESET);
    if (length >= 8 && has_upper && has_lower && has_digit && has_special)
        printf(GREEN "Strong\n" RESET);
    else if (length >= 6 && ((has_upper && has_lower) || (has_digit && has_special)))
        printf(YELLOW "Moderate\n" RESET);
    else
        printf(RED "Weak\n" RESET);

    log_action("Password Strength Checker executed");
    printf("\nPress enter to return to menu...");
    getchar(); getchar();
}

// Tool 6: HexSecure - Secure Your Files with Signature-Based Detection
char* read_file_as_hex(const char* filepath) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        printf(RED "Unable to open file %s\n" RESET);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char*)malloc(length);
    fread(buffer, 1, length, file);
    fclose(file);

    char *hex_string = (char*)malloc(2 * length + 1);
    for (long i = 0; i < length; i++) {
        sprintf(&hex_string[i * 2], "%02X", (unsigned char)buffer[i]);
    }
    hex_string[2 * length] = '\0';
    free(buffer);

    return hex_string;
}

int check_for_virus(const char* hex_string, const char* signature) {
    return (strstr(hex_string, signature) != NULL);
}

void scan_file(const char* filepath, const char* signature_file) {
    char *file_hex = read_file_as_hex(filepath);
    if (!file_hex) {
        return;
    }

    FILE *sig_file = fopen(signature_file, "r");
    if (!sig_file) {
        printf(RED "Unable to open signature file\n" RESET);
        free(file_hex);
        return;
    }

    char line[256];
    int virus_found = 0;

    while (fgets(line, sizeof(line), sig_file)) {
        line[strcspn(line, "\n")] = 0;

        char *virus_name = strtok(line, ":");
        char *signature = strtok(NULL, ":");

        if (check_for_virus(file_hex, signature)) {
            printf(RED "Virus detected: %s\n" RESET, virus_name);
            virus_found = 1;
            break;
        }
    }

    if (!virus_found) {
        printf(GREEN "No viruses found in the file.\n" RESET);
    }

    fclose(sig_file);
    free(file_hex);
}

void hexsecure() {
    clear_screen();
    printf(GREEN "HexSecure: Secure Your Files\n" RESET);

    char file_to_scan[100], signature_file[100];
    printf("Enter the file to scan: ");
    scanf("%s", file_to_scan);
    printf("Enter the signature file (database): ");
    scanf("%s", signature_file);

    scan_file(file_to_scan, signature_file);

    log_action("HexSecure: Secure Your Files executed");
    printf("\nPress enter to return to menu...");
    getchar(); getchar();
}

// Tool 7: Secure File Eraser (Shredder)
void secure_file_eraser() {
    clear_screen();
    printf(GREEN "Secure File Eraser (Shredder)\n" RESET);

    char file_to_erase[100];
    printf("Enter the file to securely erase: ");
    scanf("%s", file_to_erase);

    FILE *file = fopen(file_to_erase, "wb");
    if (!file) {
        printf(RED "Error: Unable to open file for erasing.\n" RESET);
        return;
    }

    // Overwrite file with random data multiple times
    for (int pass = 0; pass < 3; pass++) {
        fseek(file, 0, SEEK_SET);
        for (int i = 0; i < 1000; i++) {  // Simulated overwrite
            char random_data = rand() % 256;
            fwrite(&random_data, sizeof(char), 1, file);
        }
    }

    fclose(file);
    remove(file_to_erase);
    printf(GREEN "File erased securely.\n" RESET);

    log_action("Secure File Eraser (Shredder) executed");
    printf("\nPress enter to return to menu...");
    getchar(); getchar();
}

// Tool 8: Binary File Creator (Virus Creator)
void binary_file_creator() {
    clear_screen();
    printf(GREEN "Binary File Creator (Virus Creator)\n" RESET);

    FILE *file = fopen("testfile.exe", "wb");

    if (!file) {
        printf(RED "Error: Unable to create file.\n" RESET);
        return;
    }

    unsigned char virus_signature[] = { 0xBA, 0xDC, 0x0F, 0xFE, 0xE0, 0xDD, 0xF0, 0x0D };

    fwrite(virus_signature, sizeof(virus_signature), 1, file);
    fclose(file);

    printf(GREEN "File created successfully.\n" RESET);
    log_action("Binary File Creator (Virus Creator) executed");
    printf("\nPress enter to return to menu...");
    getchar(); getchar();
}

int main() {
    display_intro();  // Show introduction with group and university info
    login_system();

    while (1) {
        display_tools_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                brute_force_simulator();
                break;
            case 2:
                file_encryption_tool();
                break;
            case 3:
                file_decryption_tool();
                break;
            case 4:
                dictionary_attack_tool();  // Call the new Dictionary Attack Tool here
                break;
            case 5:
                password_generator();
                break;
            case 6:
                password_strength_checker();
                break;
            case 7:
                hexsecure();
                break;
            case 8:
                secure_file_eraser();
                break;
            case 9:
                binary_file_creator();
                break;
            case 10:
                printf(GREEN "\nExiting program. Goodbye!\n" RESET);
                log_action("Program exited");
                exit(0);
                break;
            default:
                printf(RED "Invalid choice! Please choose a valid tool.\n" RESET);
                log_action("Invalid tool choice");
        }
    }

    return 0;
}
