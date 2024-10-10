#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Define ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

// Function to clear the screen and move cursor to top-left
void clear_screen() {
    printf("\033[2J");    // Clear the entire screen
    printf("\033[H");     // Move cursor to home position
}

// Function to draw a bordered header
void draw_header() {
    printf(BLUE "+------------------------------------------+\n" RESET);
    printf(BLUE "|" RESET "          " MAGENTA "Brute Force Simulator" BLUE "          |\n" RESET);
    printf(BLUE "+------------------------------------------+\n" RESET);
}

// Function to draw a bordered footer
void draw_footer() {
    printf(BLUE "+------------------------------------------+\n" RESET);
}

// Function to evaluate password strength (optional enhancement)
void evaluate_password_strength(const char *password) {
    int length = strlen(password);
    // Simple strength evaluation based on length
    printf("\nPassword Strength Evaluation:\n");
    if(length < 4) {
        printf(RED "Strength: Very Weak\n" RESET);
    }
    else if(length < 6) {
        printf(YELLOW "Strength: Weak\n" RESET);
    }
    else if(length < 8) {
        printf(CYAN "Strength: Moderate\n" RESET);
    }
    else {
        printf(GREEN "Strength: Strong\n" RESET);
    }
}

// Function to increment the current password guess
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

    // If all combinations for current length are exhausted, increase length
    if (strlen(password) < max_length) {
        memset(password, charset[0], strlen(password));
        password[strlen(password)] = charset[0];
        password[strlen(password) + 1] = '\0';
        return 1;
    }

    // All combinations exhausted
    return 0;
}

int main() {
    char target_password[100];
    char charset[] = "abcdefghijklmnopqrstuvwxyz";
    int charset_size = strlen(charset);
    int max_length;
    char guess[100] = "";
    int attempts = 0;
    clock_t start_time, end_time;

    // Clear the screen and draw the header
    clear_screen();
    draw_header();

    // Input Section
    printf("\nEnter the target password (lowercase letters only): ");
    scanf("%s", target_password);
    printf("Enter the maximum password length to attempt: ");
    scanf("%d", &max_length);

    // Evaluate password strength (optional)
    evaluate_password_strength(target_password);

    // Initialize guess with first character
    guess[0] = charset[0];
    guess[1] = '\0';

    start_time = clock();

    // Cracking Loop
    while (1) {
        attempts++;

        // Compare guess with target
        if (strcmp(guess, target_password) == 0) {
            end_time = clock();
            double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            printf(GREEN "\nPassword cracked: %s\n" RESET, guess);
            printf(GREEN "Total attempts: %d\n" RESET, attempts);
            printf(GREEN "Time taken: %.2f seconds\n" RESET, time_taken);
            break;
        }

        // Generate next guess
        if (!increment_password(guess, max_length, charset, charset_size)) {
            printf(RED "\nFailed to crack the password within the given parameters.\n" RESET);
            break;
        }

        // Optional: Display progress every 100000 attempts
        if (attempts % 100000 == 0) {
            // Move cursor to a specific position (e.g., bottom of the screen)
            // Here, we simply overwrite the current line
            printf(YELLOW "Attempts: %d, Current guess: %s\r" RESET, attempts, guess);
            fflush(stdout);
        }
    }

    // Draw the footer
    draw_footer();

    return 0;
}
