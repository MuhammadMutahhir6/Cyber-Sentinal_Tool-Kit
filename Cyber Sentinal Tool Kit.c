#include <stdio.h>          // Standard input/output library for functions like printf, scanf
#include <string.h>         // String manipulation functions like strcmp, strcpy
#include <time.h>           // Time-related functions for logging timestamps
#include <stdlib.h>         // Standard library functions for memory allocation, process control
#include <unistd.h>         // UNIX standard functions for sleep and usleep
#include <ctype.h>          // Character type functions like tolower, isalpha, isdigit
#include <math.h>

// ANSI Color Codes for terminal output (used to add colors and text styles)
#define RESET     "\033[0m"      // Resets all attributes
#define RED       "\033[0;31m"   // Red text
#define GREEN     "\033[0;32m"   // Green text
#define YELLOW    "\033[0;33m"   // Yellow text
#define BLUE      "\033[0;34m"   // Blue text
#define CYAN      "\033[0;36m"   // Cyan text
#define MAGENTA   "\033[0;35m"   // Magenta text
#define BOLD      "\033[1m"       // Bold text
#define UNDERLINE "\033[4m"       // Underlined text
#define BOLD_RED "\033[1;31m" // Bold red text

// Define constants for login system and file paths
#define MAX_ATTEMPTS 3             // Maximum number of login attempts
#define LOCKOUT_TIME 10            // Lockout duration in seconds after max attempts
#define MAX_WORD_LENGTH 100        // Maximum length for password inputs
#define FEEDBACK_FILE "feedback.txt" // File to store user feedback

// Function to load settings from file (Removed theme-related settings)
void load_settings() {
    // No settings to load since themes are removed
}

// Function to save settings to file (Removed theme-related settings)
void save_settings() {
    // No settings to save since themes are removed
}

// Utility function to clear the terminal screen
void clear_screen() {
    printf("\033[2J\033[H"); // ANSI escape codes to clear screen and move cursor to home position
}

// Fixed color definitions for message types using previously defined ANSI codes
#define SUCCESS GREEN    // Success messages will be in green
#define ERROR RED        // Error messages will be in red
#define WARNING YELLOW   // Warning messages will be in yellow
#define INFO BLUE        // Informational messages will be in blue

// Function to display the introductory information with group and university details
void display_intro() {
    // Define color codes for a professional appearance
    const char *COLOR_BLUE   = "\033[34m"; // Blue
    const char *COLOR_WHITE  = "\033[37m"; // White
    const char *COLOR_GRAY   = "\033[90m"; // Bright Black (Gray)
    const char *COLOR_GREEN  = "\033[32m"; // Green
    const char *COLOR_RESET  = "\033[0m";  // Reset to default

    const int terminal_width = 80; // Set terminal width for centering

    // Header content
    const char *header[] = {
        "  ===============================================  ",
        " ||                                             || ",
        " ||            WELCOME TO OUR PROGRAM           || ",
        " ||                                             || ",
        "  ===============================================  "
    };
    const int header_lines = sizeof(header) / sizeof(header[0]);
    const int delay = 150000; // Delay between lines (0.15 seconds)

    // Clear the terminal screen
    clear_screen();

    // Display header with animation
    for (int i = 0; i < header_lines; i++) {
        // Calculate padding for horizontal centering
        int padding = (terminal_width - strlen(header[i])) / 2;
        // Determine color based on line index
        const char *color = (i == 0 || i == header_lines - 1) ? COLOR_GRAY : COLOR_BLUE;
        // Print each line with the assigned color and padding
        printf("%s%*s%s%s\n", 
            color,          // Apply assigned color
            padding, "",    // Center horizontally with padding
            header[i], 
            COLOR_RESET    // Reset color after the line
        );
        fflush(stdout);
        usleep(delay);
    }

    // Pause after the header animation
    usleep(500000);

    // Centered university and subject details
     printf("\n");
    printf("%*s%s+-----------------------------------------------+%s\n", 
           (terminal_width - 49) / 2, "", COLOR_GRAY, COLOR_RESET);
    printf("%*s| %sUniversity Name:%s  %sFast Nuces                  %s|\n", 
           (terminal_width - 49) / 2, "",
           COLOR_WHITE, COLOR_RESET,
           COLOR_GREEN, COLOR_GRAY);
    printf("%*s| %sSubject:%s          %sProgramming Fundamentals    %s|\n", 
           (terminal_width - 49) / 2, "",
           COLOR_WHITE, COLOR_RESET,
           COLOR_GREEN, COLOR_GRAY);
    printf("%*s| %sTeacher Name:%s     %sNoman Hanif                 %s|\n", 
           (terminal_width - 49) / 2, "",
           COLOR_WHITE, COLOR_RESET,
           COLOR_GREEN, COLOR_GRAY);
    printf("%*s| %sSection:%s          %sBCY-1A                      %s|\n", 
           (terminal_width - 49) / 2, "",
           COLOR_WHITE, COLOR_RESET,
           COLOR_GREEN, COLOR_GRAY);
    printf("%*s%s+-----------------------------------------------+%s\n", 
           (terminal_width - 49) / 2, "", COLOR_GRAY, COLOR_RESET);

    // Pause before displaying group members
    usleep(500000);

    // Centered group members
    printf("\n");
    printf("%*s%s+-----------------------------------------------+%s\n", 
           (terminal_width - 49) / 2, "", COLOR_GRAY, COLOR_RESET);
    printf("%*s| %sGroup Members:%s                                %s|\n", 
           (terminal_width - 49) / 2, "",
           COLOR_WHITE, COLOR_RESET,
           COLOR_GRAY);
    printf("%*s|                                               |\n", 
           (terminal_width - 49) / 2, "");
    printf("%*s| %sHasnain Memon%s    %s(24k-2001)%s                   %s|\n", 
           (terminal_width - 49) / 2, "",
           COLOR_GREEN, COLOR_RESET,
           COLOR_WHITE, COLOR_RESET,
           COLOR_GRAY);
    fflush(stdout);
    usleep(delay);
    printf("%*s| %sMuhammad Mutahir%s %s(24k-2005)%s                   %s|\n", 
           (terminal_width - 49) / 2, "",
           COLOR_GREEN, COLOR_RESET,
           COLOR_WHITE, COLOR_RESET,
           COLOR_GRAY);
    printf("%*s%s+-----------------------------------------------+%s\n", 
           (terminal_width - 49) / 2, "", COLOR_GRAY, COLOR_RESET);

    // Pause before exit prompt
    usleep(500000);

    // Centered prompt to continue
    printf("\n");
    printf("%*s%sPress ENTER to continue...%s\n", 
           (terminal_width - 26) / 2, "", 
           COLOR_WHITE, COLOR_RESET);
    getchar(); // Wait for user to press Enter
}

// Function to display the ASCII art banner for the program
void display_banner() {
    const char *ascii_art[] = {
        "   ____      _               ____             _   _            _ ",
        "  / ___|   _| |__   ___ _ __/ ___|  ___ _ __ | |_(_)_ __   ___| |",
        " | |  | | | | '_ \\ / _ \\ '__\\___ \\ / _ \\ '_ \\| __| | '_ \\ / _ \\ |",
        " | |__| |_| | |_) |  __/ |   ___) |  __/ | | | |_| | | | |  __/ |",
        "  \\____\\__, |_.__/_\\___|_|  |____/ \\___|_| |_|\\__|_|_| |_|\\___|_|",
        "       |___/    |_   _|__   ___ | | |/ (_) |_                    ",
        "                  | |/ _ \\ / _ \\| | ' /| | __|                   ",
        "                  | | (_) | (_) | | . \\| | |_                     ",
        "                  |_|\\___/ \\___/|_|_|\\_\\_|\\__|    ",
    };

    // Professional and consistent color palette
    const char *colors[] = {
        "\033[34m", // Blue
        "\033[37m", // White
        "\033[90m", // Bright Black (Gray)
        "\033[36m", // Cyan
        "\033[32m"  // Green
    };

    int num_lines = sizeof(ascii_art) / sizeof(ascii_art[0]);
    int delay = 150000; // Delay between lines (0.15 seconds)
    int color_count = sizeof(colors) / sizeof(colors[0]);

    // Clear screen and move cursor to top-left
    printf("\033[2J\033[H");

    // Add vertical spacing for centering
    printf("\n\n\n");

    for (int i = 0; i < num_lines; i++) {
        // Apply professional color gradient
        printf("%s%*s%s%s\n", 
            colors[i % color_count], // Cycle through professional colors
            20, "",                   // Center horizontally with 20 spaces
            ascii_art[i], 
            "\033[0m");               // Reset color after each line
        fflush(stdout);               // Flush the output buffer
        usleep(delay);                // Delay for animation
    }

    // Footer styling with consistent color
    printf("\033[37m"); // White text for footer
    printf("\n%*s==========================================================================\n", 10, "");
    printf("  \033[32m%*sWelcome to the Program! Enjoy the Experience!\033[0m\n", 20, ""); // Footer message with green color

    usleep(700000); // Pause for a moment before finishing
    printf("\033[0m"); // Reset text attributes
}

// Function to display a progress bar in the terminal
void show_progress_bar(int percentage) {
    int width = 50; // Total width of the progress bar
    int pos = (percentage * width) / 100; // Calculate position of the progress
    printf("["); // Start of progress bar
    for (int i = 0; i < width; ++i) { // Loop to fill the progress bar
        if (i < pos) printf("=");      // Filled part
        else if (i == pos) printf(">"); // Current position
        else printf(" ");               // Unfilled part
    }
    printf("] %d%%\r", percentage); // End of progress bar with percentage
    fflush(stdout); // Flush the output buffer to display immediately
}

// Function to display a spinner animation in the terminal
void show_spinner() {
    const char spinner_chars[] = {'|', '/', '-', '\\'}; // Spinner characters
    static int spinner_index = 0; // Static index to keep track of spinner state
    printf("%c", spinner_chars[spinner_index]); // Display current spinner character
    fflush(stdout); // Flush the output buffer to display immediately
    spinner_index = (spinner_index + 1) % 4; // Update spinner index cyclically
}

// Confirmation prompt function to confirm critical actions
int confirm_action_prompt(const char *action) {
    char response[10]; // Buffer to store user response
    // Prompt the user with a warning message
    printf("%s%sWARNING%s: Are you sure you want to %s? (y/n): ", WARNING, BOLD, RESET, action);
    scanf("%s", response); // Read user input
    // Clear input buffer to remove any remaining characters
    while (getchar() != '\n');
    if (tolower(response[0]) == 'y') { // Check if response starts with 'y' or 'Y'
        return 1; // User confirmed
    }
    return 0; // User did not confirm
}

// Function to play a beep sound using ASCII Bell character
void play_beep() {
    printf("\a"); // ASCII Bell character
    fflush(stdout); // Flush the output buffer to ensure the beep is played
}

// Function to display the help section with instructions
void display_help() {
    clear_screen(); // Clear the terminal screen

    const int padding = 20; // Center alignment for the box

    // Display help header
    printf("\n");
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");
    printf("%s%*s|                  %sHelp Section%s                  %s|\n", 
           CYAN, padding, "", BOLD, RESET, CYAN);
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");

    // Display help instructions
    printf("%*s| %-48s|\n", padding, "", "1. Select a tool by entering its number.");
    printf("%*s| %-48s|\n", padding, "", "2. Follow the on-screen prompts.");
    printf("%*s| %-48s|\n", padding, "", "3. Refer to documentation for issues.");
    printf("%*s| %-48s|\n", padding, "", "4. To exit, select 'Exit' from the menu.");
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");

    // Prompt to return to the main menu
    printf("\n");
    printf("%*s\033[1;33mPress ENTER to return to the main menu...\033[0m\n", 
           (80 - 42) / 2, ""); // Center the prompt
    getchar(); // Wait for user to press Enter
}

// Function to get a valid menu choice from the user with input validation
int get_valid_choice(int min, int max) {
    int choice; // Variable to store user's choice
    int attempts = 0; // Counter for user attempts

    while (1) { // Infinite loop until a valid choice is entered
        // Display prompt
        printf("\n");
        printf("%s%*s+---------------------------------------------+\n", CYAN, 20, "");
        printf("%s%*s| %sChoose an option (%d-%d):%s                     %s|\n", 
               CYAN, 20, "", BOLD, min, max, RESET, CYAN);
        printf("%s%*s+---------------------------------------------+\n", CYAN, 20, "");

        if (scanf("%d", &choice) != 1) { // Input validation: Check if integer
            while (getchar() != '\n'); // Clear buffer
            printf("%s%*s| %s[ERROR]%s Invalid input! Please enter a valid number. %s|\n", 
                   BOLD_RED, 20, "", BOLD_RED, RESET, CYAN);
            printf("%s%*s+---------------------------------------------+\n", CYAN, 20, "");
            attempts++;
            continue; // Restart loop
        }

        if (choice < min || choice > max) { // Range validation
            printf("%s%*s| %s[ERROR]%s Choice out of range! Enter a number (%d-%d). %s|\n", 
                   BOLD_RED, 20, "", BOLD_RED, RESET, min, max, CYAN);
            printf("%s%*s+---------------------------------------------+\n", CYAN, 20, "");
            attempts++;
        } else {
            while (getchar() != '\n'); // Clear buffer
            break; // Valid input, exit loop
        }
    }

    // Display success message and return choice
    printf("%s%*s| %s[INFO]%s You selected option %d after %d attempt(s).%s        %s|\n", 
           CYAN, 20, "", CYAN, RESET, choice, attempts, RESET, CYAN);
    printf("%s%*s+---------------------------------------------+\n", CYAN, 20, "");
    return choice;
}

// Function to get user input with a prompt and an optional example
void get_input(char *buffer, size_t size, const char *prompt, const char *example) {
    printf("%s%s%s", INFO, prompt, RESET); // Print the prompt with informational color
    if (example != NULL && strlen(example) > 0) { // If an example is provided
        printf(" (%s): ", example); // Print the example
    } else {
        printf(": "); // Otherwise, just print a colon
    }
    if (fgets(buffer, size, stdin) != NULL) { // Read user input safely
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character from input
    } else {
        buffer[0] = '\0'; // Set buffer to empty string if input fails
    }
}

// Function to display a user-friendly exit message and collect feedback
void user_exit() {
    clear_screen(); // Clear the terminal screen

    const int padding = 20; // Center alignment for the box

    // Display exit message
    printf("\n");
    printf("%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
    printf("%s%*s|                                                  |\n", GREEN, padding, "");
    printf("%s%*s|   %sThank you for using the program! Goodbye!%s      %s|\n", 
           GREEN, padding, "", BOLD, RESET, GREEN);
    printf("%s%*s|                                                  |\n", GREEN, padding, "");
    printf("%s%*s+--------------------------------------------------+\n", GREEN, padding, "");

    // Prompt for feedback
    printf("\n");
    printf("%*sWould you like to provide feedback? (y/n): ", (80 - 42) / 2, "");
    char response[10]; // Buffer to store user response
    scanf("%s", response); // Read user input

    // Clear input buffer to remove any remaining characters
    while (getchar() != '\n');

    if (tolower(response[0]) == 'y') { // Check if response starts with 'y' or 'Y'
        char feedback[512]; // Buffer to store user feedback

        // Get user feedback with a centered prompt
        get_input(feedback, sizeof(feedback), 
                  "\033[1;33mEnter your feedback:", "e.g., The program is very useful");

        FILE *fb = fopen(FEEDBACK_FILE, "a"); // Open feedback file in append mode
        if (fb) { // Check if file opened successfully
            time_t current_time = time(NULL); // Get current time
            char *time_str = ctime(&current_time); // Convert time to string
            time_str[strcspn(time_str, "\n")] = 0; // Remove newline
            fprintf(fb, "[%s] %s\n", time_str, feedback); // Write feedback with timestamp
            fclose(fb); // Close the feedback file

            // Print success message
            printf("\n");
            printf("%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
            printf("%s%*s|   %sSUCCESS:%s Thank you for your feedback!            %s|\n", 
                   GREEN, padding, "", BOLD, RESET, GREEN);
            printf("%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
        } else { // If feedback file couldn't be opened
            printf("\n");
            printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
            printf("%s%*s|   %sERROR:%s Unable to save feedback.                  %s|\n", 
                   ERROR, padding, "", BOLD, RESET, ERROR);
            printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        }
    }

    printf("\n");
    exit(0); // Terminate the program
}

// Function to check if the entered password matches the correct password
int check_password(const char *input_password) {
    const char *correct_password = " "; // Define the correct password
    return strcmp(input_password, correct_password) == 0; // Return 1 if passwords match, else 0
}

// Function to display the login header
void display_header() {
    // Define color codes for a professional appearance
    const char *COLOR_BLUE        = "\033[34m";  // Blue
    const char *COLOR_BOLD_BLUE   = "\033[1;34m"; // Bold Blue
    const char *COLOR_GRAY        = "\033[90m";  // Bright Black (Gray)
    const char *COLOR_RESET       = "\033[0m";   // Reset to default

    const int padding = 20; // Center alignment for header

    // Header box with animation
    printf("\n");
    printf("%s%*s+--------------------------------------------------+%s\n", 
           COLOR_GRAY, padding, "", COLOR_RESET);
    printf("%s%*s|                                                  |%s\n", 
           COLOR_GRAY, padding, "", COLOR_RESET);
    printf("%s%*s|      %sWelcome to the Secure Login System%s          |%s\n", 
           COLOR_GRAY, padding, "", COLOR_BOLD_BLUE, COLOR_RESET, COLOR_GRAY);
    printf("%s%*s|                                                  |%s\n", 
           COLOR_GRAY, padding, "", COLOR_RESET);
    printf("%s%*s+--------------------------------------------------+%s\n", 
           COLOR_GRAY, padding, "", COLOR_RESET);
}

void display_success() {
    // Define color codes for a professional appearance
    const char *COLOR_BLUE        = "\033[34m";  // Blue
    const char *COLOR_BOLD_BLUE   = "\033[1;34m"; // Bold Blue
    const char *COLOR_WHITE       = "\033[37m";  // White
    const char *COLOR_GRAY        = "\033[90m";  // Bright Black (Gray)
    const char *COLOR_RESET       = "\033[0m";   // Reset to default

    const int padding = 20; // Center alignment for the box

    // Clear the terminal screen
    clear_screen();

    // Success message box with consistent color palette
    printf("\n");
    printf("%s%*s+--------------------------------------------------+%s\n", 
           COLOR_GRAY, padding, "", COLOR_RESET);
    printf("%s%*s|                                                  |%s\n", 
           COLOR_GRAY, padding, "", COLOR_RESET);
    printf("%s%*s|       %sLOGIN SUCCESSFUL! WELCOME%s                  |%s\n", 
           COLOR_GRAY, padding, "", COLOR_BOLD_BLUE, COLOR_RESET, COLOR_GRAY);
    printf("%s%*s|                                                  |%s\n", 
           COLOR_GRAY, padding, "", COLOR_RESET);
    printf("%s%*s+--------------------------------------------------+%s\n", 
           COLOR_GRAY, padding, "", COLOR_RESET);

    // Animated transition indicating session loading
    printf("\n");
    printf("%s%*s| %sINFO%s: %sLoading your session", 
           COLOR_GRAY, padding, "", COLOR_WHITE, COLOR_RESET, COLOR_BLUE);
    fflush(stdout); // Flush the output buffer to display immediately

    for (int i = 0; i < 3; i++) { // Loop to display dots
        usleep(500000); // 0.5 seconds delay
        printf(".");
        fflush(stdout); // Flush to show the dots one by one
    }
    printf(" |\n"); // Close the info line
    printf("%s%*s+--------------------------------------------------+%s\n", 
           COLOR_GRAY, padding, "", COLOR_RESET);

    sleep(1); // Additional delay before proceeding
}

// Function to handle the login system with attempts and lockout mechanism
void login_system() {
    char password[100];    // Buffer to store user-entered password
    int attempts = 0;      // Counter for login attempts
    time_t lockout_start;  // Variable to store lockout start time

    const char *COLOR_ERROR = "\033[31m";  // Red
    const char *COLOR_WARNING = "\033[33m"; // Yellow
    const char *COLOR_SUCCESS = "\033[32m"; // Green
    const char *COLOR_BOLD = "\033[1m";     // Bold
    const char *COLOR_RESET = "\033[0m";    // Reset to default

    const int padding = 20; // Padding for center alignment
    const int terminal_width = 80; // Approximate terminal width for alignment

    clear_screen();       // Clear the terminal screen
    display_header();     // Display the login header

    while (1) { // Infinite loop until successful login
        if (attempts >= MAX_ATTEMPTS) { // Check if max attempts exceeded
            time_t current_time = time(NULL); // Get current time
            int lockout_duration = (int)(current_time - lockout_start); // Calculate lockout duration

            if (lockout_duration < LOCKOUT_TIME) { // If still within lockout period
                printf("\n%*s%sERROR%s: Too many failed attempts! Locked out for %d seconds.%s\n", 
                       padding, "", COLOR_ERROR, COLOR_RESET, LOCKOUT_TIME - lockout_duration, COLOR_RESET);
                sleep(1); // Wait for 1 second before the next attempt
                continue; // Continue to the next iteration
            } else { // If lockout period has ended
                printf("\n%*s%sSUCCESS%s: Lockout period over. You can try again.%s\n",
                       padding, "", COLOR_SUCCESS, COLOR_RESET, COLOR_RESET);
                attempts = 0; // Reset the attempts counter
            }
        }

        // Prompt the user to enter the password
        printf("\n%*s%sEnter your password: %s", padding, "", COLOR_BOLD, COLOR_RESET);
        get_input(password, sizeof(password), "", "");

        if (check_password(password)) { // Check if password is correct
            printf("\n%*s%sSUCCESS%s: Access Granted! Welcome to the system.%s\n",
                   padding, "", COLOR_SUCCESS, COLOR_RESET, COLOR_RESET);
            display_success(); // Display success animation
            break; // Exit the loop upon successful login
        } else { // If password is incorrect
            attempts++; // Increment the attempts counter
            play_beep(); // Play a beep sound as feedback
            printf("\n%*s%sWARNING%s: Incorrect password! %d attempt(s) remaining.%s\n",
                   padding, "", COLOR_WARNING, COLOR_RESET, MAX_ATTEMPTS - attempts, COLOR_RESET);
            if (attempts >= MAX_ATTEMPTS) { // If max attempts reached
                printf("\n%*s%sERROR%s: Too many failed attempts! Locking out for %d seconds...%s\n",
                       padding, "", COLOR_ERROR, COLOR_RESET, LOCKOUT_TIME, COLOR_RESET);
                lockout_start = time(NULL); // Record the start time of lockout
            }
        }
    }
}

// Function to increment the password guess based on the given character set
int increment_password(char *password, int max_length, const char *charset, int charset_size) {
    int i = strlen(password) - 1; // Start from the last character of the current guess

    while (i >= 0) { // Loop until the first character
        int pos = strchr(charset, password[i]) - charset; // Find the position of current character in charset
        if (pos < charset_size - 1) { // If not the last character in charset
            password[i] = charset[pos + 1]; // Increment the character
            return 1; // Successful increment
        } else { // If it's the last character in charset
            password[i] = charset[0]; // Reset to first character
            i--; // Move to the previous character
        }
    }

    if (strlen(password) < max_length) { // If current guess length is less than max_length
        size_t len = strlen(password); // Get current length
        memset(password, charset[0], len + 1); // Reset all characters to first charset character
        password[len + 1] = '\0'; // Null-terminate the string
        return 1; // Successful increment
    }

    return 0; // Failed to increment (max length reached)
}

// Function to simulate a brute-force attack on a target password
void brute_force_simulator() {
    clear_screen(); // Clear the terminal screen

    const int padding = 20; // Center alignment for the header and content

    // Header for the simulator
    printf("\n");
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");
    printf("%s%*s|     %sBrute Force Attack Simulator%s                 %s|\n", 
           CYAN, padding, "", BOLD, RESET, CYAN);
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");

    char target_password[100]; // Buffer to store the target password
    char charset[] = "abcdefghijklmnopqrstuvwxyz"; // Character set to use for guessing
    int charset_size = strlen(charset); // Size of the character set
    int max_length; // Maximum password length to attempt
    char guess[100] = ""; // Buffer to store the current guess
    unsigned long long attempts = 0; // Counter for the number of attempts
    unsigned long long total_combinations = 0; // Total combinations possible
    clock_t start_time, end_time; // Variables to store start and end times

    // Prompt the user to enter the target password and maximum length
    get_input(target_password, sizeof(target_password), 
              "                    \033[1;33mEnter the target password\033[0m", "lowercase letters only");

    // Input validation: Ensure the target password contains only lowercase letters from the charset
    for (int i = 0; i < strlen(target_password); i++) {
        if (!islower(target_password[i])) {
            printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
            printf("%s%*s|   %sERROR:%s Password must contain lowercase letters only.%s|\n", 
                   ERROR, padding, "", BOLD, RESET, ERROR);
            printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
            printf("\n%*sPress ENTER to return to menu...", padding, "");
            getchar(); // Wait for user to press Enter
            return; // Exit the function due to invalid input
        }
    }

    printf("\n%*s%sEnter the maximum password length to attempt (up to 20): %s", 
           padding, "", CYAN, RESET);
    if (scanf("%d", &max_length) != 1 || max_length <= 0 || max_length > 20) { // Validate input
        printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("%s%*s|   %sERROR:%s Invalid password length.                %s|\n", 
               ERROR, padding, "", BOLD, RESET, ERROR);
        printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        while (getchar() != '\n'); // Clear input buffer
        printf("\n%*sPress ENTER to return to menu...", padding, "");
        getchar(); // Wait for user to press Enter
        return; // Exit the function due to invalid input
    }
    while (getchar() != '\n'); // Clear input buffer

    // Ensure the target password length does not exceed max_length
    if (strlen(target_password) > max_length) {
        printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("%s%*s|   %sERROR:%s Target password length exceeds max length.%s|\n", 
               ERROR, padding, "", BOLD, RESET, ERROR);
        printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("\n%*sPress ENTER to return to menu...", padding, "");
        getchar(); // Wait for user to press Enter
        return;
    }

    // Compute total combinations incrementally
    unsigned long long power = 1; // Store the current power of charset_size
    for (int i = 1; i <= max_length; i++) {
        power *= charset_size; // Calculate charset_size^i
        total_combinations += power; // Add to total_combinations
    }

    printf("\n%*s%sINFO%s: Starting brute-force simulation...\n", padding, "", CYAN, RESET);
    sleep(1); // Wait for 1 second before starting

    guess[0] = charset[0]; // Initialize the first character of the guess
    guess[1] = '\0'; // Null-terminate the guess string
    start_time = clock(); // Record the start time

    // Main brute force loop
    while (1) {
        attempts++; // Increment the attempts counter

        // Check if the current guess matches the target password
        if (strcmp(guess, target_password) == 0) {
            end_time = clock(); // Record the end time
            double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Calculate time taken
            printf("\n%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
            printf("%s%*s|   %sSUCCESS:%s Password cracked: %s                 %s|\n", 
                   GREEN, padding, "", BOLD, RESET, guess, GREEN);
            printf("%s%*s|   %sSUCCESS:%s Total attempts: %llu            %s|\n", 
                   GREEN, padding, "", BOLD, RESET, attempts, GREEN);
            printf("%s%*s|   %sSUCCESS:%s Time taken: %.2f seconds             %s|\n", 
                   GREEN, padding, "", BOLD, RESET, time_taken, GREEN);
            printf("%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
            printf("\n%*sPress ENTER to return to menu...", padding, "");
            getchar(); // Wait for user to press Enter
            break; // Exit the loop upon success
        }

        // Attempt to increment the guess
        if (!increment_password(guess, max_length, charset, charset_size)) {
            printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
            printf("%s%*s|   %sERROR:%s Failed to crack the password.          %s|\n", 
                   ERROR, padding, "", BOLD, RESET, ERROR);
            printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
            printf("\n%*sPress ENTER to return to menu...", padding, "");
            getchar(); // Wait for user to press Enter
            break; // Exit the loop upon failure
        }

        // Show progress percentage every 100,000 attempts
        if (attempts % 100000 == 0) {
            double progress_percentage = ((double)attempts / total_combinations) * 100;
            if (progress_percentage > 100.0) progress_percentage = 100.0; // Cap at 100%
            printf("\r%*s%sINFO%s: Progress: %.2f%%", padding, "", CYAN, RESET, progress_percentage);
            fflush(stdout); // Ensure immediate display
        }
    }
    printf("\n%*sPress ENTER to return to menu...", padding, "");
    getchar(); // Wait for user to press Enter
}

// Tool 2: Basic File Encryption Tool (XOR Encryption)
void file_encryption_tool() {
    clear_screen(); // Clear the terminal screen

    const int padding = 20; // Center alignment for the header and content

    // Header for the tool
    printf("\n");
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");
    printf("%s%*s|     %sBasic File Encryption Tool%s                   %s|\n", 
           CYAN, padding, "", BOLD, RESET, CYAN);
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");

    char input_file[100], output_file[100], key[100]; // Buffers for filenames and encryption key
    FILE *infile, *outfile; // File pointers for input and output files
    unsigned char buffer; // Buffer to store file data
    int key_length, i = 0; // Variables for key length and iteration

    // Prompt the user to enter input file name, output file name, and encryption key
    get_input(input_file, sizeof(input_file), "                     \033[1;33mEnter input file name\033[0m", "e.g., input.txt");
    get_input(output_file, sizeof(output_file), "                     \033[1;33mEnter output file name\033[0m", "e.g., encrypted.bin");
    get_input(key, sizeof(key), "                     \033[1;33mEnter encryption key\033[0m", "e.g., mykey");

    // Input validation: Ensure the key is not empty
    if (strlen(key) == 0) {
        printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("%s%*s|   %sERROR:%s Encryption key cannot be empty.        %s|\n", 
               ERROR, padding, "", BOLD, RESET, ERROR);
        printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("\n%*sPress ENTER to return to menu...", padding, "");
        getchar(); // Wait for user to press Enter
        return;
    }

    key_length = strlen(key); // Calculate the length of the encryption key
    infile = fopen(input_file, "rb"); // Open the input file in binary read mode
    outfile = fopen(output_file, "wb"); // Open the output file in binary write mode

    if (!infile || !outfile) { // Check if files were opened successfully
        printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("%s%*s|   %sERROR:%s Could not open files.                 %s|\n", 
               ERROR, padding, "", BOLD, RESET, ERROR);
        printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        if (infile) fclose(infile);
        if (outfile) fclose(outfile);
        printf("\n%*sPress ENTER to return to menu...", padding, "");
        getchar(); // Wait for user to press Enter
        return; // Exit the function due to error
    }

    printf("\n%*s%sINFO%s: Encrypting file...\n", padding, "", CYAN, RESET);
    while (fread(&buffer, 1, 1, infile)) { // Read one byte at a time from the input file
        buffer ^= key[i % key_length];  // XOR the byte with the key character
        fwrite(&buffer, 1, 1, outfile); // Write the encrypted byte to the output file
        i++; // Increment the counter
    }

    printf("\n%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
    printf("%s%*s|   %sSUCCESS:%s File encryption completed.            %s|\n", 
           GREEN, padding, "", BOLD, RESET, GREEN);
    printf("%s%*s+--------------------------------------------------+\n", GREEN, padding, "");

    fclose(infile); // Close the input file
    fclose(outfile); // Close the output file
    printf("\n%*sPress ENTER to return to menu...", padding, "");
    getchar(); // Wait for user to press Enter
}

// Tool 3: Basic File Decryption Tool (XOR Decryption)
void file_decryption_tool() {
    clear_screen(); // Clear the terminal screen

    const int padding = 20; // Center alignment for the header and content

    // Header for the tool
    printf("\n");
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");
    printf("%s%*s|     %sBasic File Decryption Tool%s                   %s|\n", 
           CYAN, padding, "", BOLD, RESET, CYAN);
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");

    char input_file[100], output_file[100], key[100]; // Buffers for filenames and decryption key
    FILE *infile, *outfile; // File pointers for input and output files
    unsigned char buffer; // Buffer to store file data
    int key_length, i = 0; // Variables for key length and iteration

    // Prompt the user to enter encrypted file name, output file name, and decryption key
    get_input(input_file, sizeof(input_file), "                     \033[1;33mEnter encrypted file name\033[0m", "e.g., encrypted.bin");
    get_input(output_file, sizeof(output_file), "                     \033[1;33mEnter output file name\033[0m", "e.g., decrypted.txt");
    get_input(key, sizeof(key), "                     \033[1;33mEnter decryption key\033[0m", "e.g., mykey");

    // Input validation: Ensure the key is not empty
    if (strlen(key) == 0) {
        printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("%s%*s|   %sERROR:%s Decryption key cannot be empty.        %s|\n", 
               ERROR, padding, "", BOLD, RESET, ERROR);
        printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("\n%*sPress ENTER to return to menu...", padding, "");
        getchar(); // Wait for user to press Enter
        return;
    }

    key_length = strlen(key); // Calculate the length of the decryption key
    infile = fopen(input_file, "rb"); // Open the encrypted file in binary read mode
    outfile = fopen(output_file, "wb"); // Open the output file in binary write mode

    if (!infile || !outfile) { // Check if files were opened successfully
        printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("%s%*s|   %sERROR:%s Could not open files.                 %s|\n", 
               ERROR, padding, "", BOLD, RESET, ERROR);
        printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        if (infile) fclose(infile);
        if (outfile) fclose(outfile);
        printf("\n%*sPress ENTER to return to menu...", padding, "");
        getchar(); // Wait for user to press Enter
        return; // Exit the function due to error
    }

    printf("\n%*s%sINFO%s: Decrypting file...\n", padding, "", CYAN, RESET);
    while (fread(&buffer, 1, 1, infile)) { // Read one byte at a time from the encrypted file
        buffer ^= key[i % key_length];  // XOR the byte with the key character to decrypt
        fwrite(&buffer, 1, 1, outfile); // Write the decrypted byte to the output file
        i++; // Increment the counter
    }

    printf("\n%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
    printf("%s%*s|   %sSUCCESS:%s File decryption completed.            %s|\n", 
           GREEN, padding, "", BOLD, RESET, GREEN);
    printf("%s%*s+--------------------------------------------------+\n", GREEN, padding, "");

    fclose(infile); // Close the encrypted file
    fclose(outfile); // Close the output file
    printf("\n%*sPress ENTER to return to menu...", padding, "");
    getchar(); // Wait for user to press Enter
}

// Tool 4: Password Generator
void password_generator() {
    clear_screen(); // Clear the terminal screen

    const int padding = 20; // Center alignment for the header and content

    // Header for the tool
    printf("\n");
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");
    printf("%s%*s|     %sPassword Generator%s                        %s|\n", 
           CYAN, padding, "", BOLD, RESET, CYAN);
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");

    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"; // Character set for password generation
    int length, charset_size = strlen(charset); // Variables for password length and charset size
    char password[100]; // Buffer to store the generated password

    // Prompt the user to enter the desired password length
    printf("\n%*s%sEnter the desired password length (8-64):%s ", padding, "", CYAN, RESET);
    if (scanf("%d", &length) != 1 || length < 8 || length > 64 || length >= sizeof(password)) { // Validate input
        printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("%s%*s|   %sERROR:%s Invalid password length.                %s|\n", 
               ERROR, padding, "", BOLD, RESET, ERROR);
        printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        while (getchar() != '\n'); // Clear input buffer
        printf("\n%*sPress ENTER to return to menu...", padding, "");
        getchar(); // Wait for user to press Enter
        return; // Exit the function due to invalid input
    }
    while (getchar() != '\n'); // Clear input buffer

    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = 0; i < length; i++) { // Loop to generate each character of the password
        password[i] = charset[rand() % charset_size]; // Select a random character from the charset
    }
    password[length] = '\0'; // Null-terminate the password string

    printf("\n%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
    printf("%s%*s|   %sSUCCESS:%s Generated password:                  %s|\n", 
           GREEN, padding, "", BOLD, RESET, GREEN);
    printf("%s%*s|   %s%-48s%s|\n", GREEN, padding, "", password, GREEN);
    printf("%s%*s+--------------------------------------------------+\n", GREEN, padding, "");

    // Feature: Prompt user to save the password
    printf("\n%*sWould you like to save this password to a file? (y/n): ", padding, "");
    char save_choice[10];
    if (fgets(save_choice, sizeof(save_choice), stdin) && tolower(save_choice[0]) == 'y') {
        FILE *file = fopen("generated_passwords.txt", "a");
        if (file) {
            fprintf(file, "Generated Password: %s\n", password);
            fclose(file);
            printf("\n%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
            printf("%s%*s|   %sSUCCESS:%s Password saved to 'generated_passwords.txt'. %s|\n", 
                   GREEN, padding, "", BOLD, RESET, GREEN);
            printf("%s%*s+--------------------------------------------------+\n", GREEN, padding, "");
        } else {
            printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
            printf("%s%*s|   %sERROR:%s Unable to save the password.          %s|\n", 
                   ERROR, padding, "", BOLD, RESET, ERROR);
            printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        }
    }

    printf("\n%*sPress ENTER to return to menu...", padding, "");
    getchar(); // Wait for user to press Enter
}

// Tool 5: Password Strength Checker
void password_strength_checker() {
    clear_screen(); // Clear the terminal screen

    const int padding = 20; // Center alignment for the header and content

    // Header for the tool
    printf("\n");
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");
    printf("%s%*s|     %sPassword Strength Checker%s                  %s|\n", 
           CYAN, padding, "", BOLD, RESET, CYAN);
    printf("%s%*s+--------------------------------------------------+\n", CYAN, padding, "");

    char password[100]; // Buffer to store the password to check
    int length, has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0; // Variables to check password strength criteria

    // Prompt the user to enter the password to check
    get_input(password, sizeof(password), "                     \033[1;33mEnter your password\033[0m", "");

    length = strlen(password); // Calculate the length of the password

    // Input validation: Ensure password is not empty
    if (length == 0) {
        printf("\n%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("%s%*s|   %sERROR:%s Password cannot be empty.               %s|\n", 
               ERROR, padding, "", BOLD, RESET, ERROR);
        printf("%s%*s+--------------------------------------------------+\n", ERROR, padding, "");
        printf("\n%*sPress ENTER to return to menu...", padding, "");
        getchar();
        return;
    }

    for (int i = 0; i < length; i++) { // Loop through each character to check criteria
        if (isupper((unsigned char)password[i])) has_upper = 1; // Check for uppercase letters
        else if (islower((unsigned char)password[i])) has_lower = 1; // Check for lowercase letters
        else if (isdigit((unsigned char)password[i])) has_digit = 1; // Check for digits
        else if (ispunct((unsigned char)password[i])) has_special = 1; // Check for special characters
    }

    // Inform the user about the password strength
    printf("\n%*s%sPassword Strength:%s ", padding, "", GREEN, RESET);
    if (length >= 8 && has_upper && has_lower && has_digit && has_special) {
        printf("%sStrong%s\n", GREEN, RESET); // Strong password
    } else if (length >= 6 && ((has_upper && has_lower) || (has_digit && has_special))) {
        printf("%sModerate%s\n", YELLOW, RESET); // Moderate password
    } else {
        printf("%sWeak%s\n", RED, RESET); // Weak password
    }

    // Additional feature: Suggest improvements for weak or moderate passwords
    if (length < 8 || !has_upper || !has_lower || !has_digit || !has_special) {
        printf("\n%*s%sSuggestions to improve your password:%s\n", padding, "", CYAN, RESET);
        if (length < 8) printf("%*s- Increase the password length to at least 8 characters.\n", padding, "");
        if (!has_upper) printf("%*s- Include at least one uppercase letter (A-Z).\n", padding, "");
        if (!has_lower) printf("%*s- Include at least one lowercase letter (a-z).\n", padding, "");
        if (!has_digit) printf("%*s- Include at least one digit (0-9).\n", padding, "");
        if (!has_special) printf("%*s- Include at least one special character (!@#$%%^&*).\n", padding, "");
    }

    printf("\n%*sPress ENTER to return to menu...", padding, "");
    getchar(); // Wait for user to press Enter
}

// Function to display the tools menu with descriptions
void display_tools_menu() {
    clear_screen(); // Clear the terminal screen
    display_banner(); // Display the ASCII art banner

    // Decorative header
    printf("\n\n");
    printf("%s%*s+---------------------------------------------+\n", CYAN, 20, "");
    printf("%s%*s| %s%sSelect a Tool to Use%s                        %s|\n", CYAN, 20, "", BOLD, CYAN, RESET, CYAN);
    printf("%s%*s+---------------------------------------------+\n", CYAN, 20, "");

    // Menu options with descriptions
    printf("%s%*s| %-44s|\n", CYAN, 20, "", "Tool Description");
    printf("%*s+--------------------------------------------------------------------------+\n", 20, "");
    printf("%*s| %s1.%s  Brute Force Attack Simulator        - Simulate brute-force attacks   %s|\n", 
           20, "", CYAN, RESET, CYAN);
    printf("%*s| %s2.%s  Basic File Encryption Tool          - Encrypt files using XOR        %s|\n", 
           20, "", CYAN, RESET, CYAN);
    printf("%*s| %s3.%s  Basic File Decryption Tool          - Decrypt files using XOR        %s|\n", 
           20, "", CYAN, RESET, CYAN);
    printf("%*s| %s4.%s  Password Generator                  - Generate strong passwords      %s|\n", 
           20, "", CYAN, RESET, CYAN);
    printf("%*s| %s5.%s  Password Strength Checker           - Check the strength of passwords%s|\n", 
           20, "", CYAN, RESET, CYAN);
    printf("%*s| %s6.%s  Help                                - View help instructions         %s|\n", 
           20, "", CYAN, RESET, CYAN);
    printf("%*s| %s7.%s  Exit                                - Exit the program               %s|\n", 
           20, "", CYAN, RESET, CYAN);
    printf("%*s+--------------------------------------------------------------------------+\n", 20, "");

    // Footer with instructions
    printf("%s%*s| %sEnter the corresponding number to proceed.%s  %s|\n", 
           CYAN, 20, "", BOLD, RESET, CYAN);
    printf("%s%*s+---------------------------------------------+\n", CYAN, 20, "");
    printf("%s", RESET); // Reset text attributes
}

// Function to handle user selection and execute the corresponding tool
void handle_choice(int choice) {
    switch (choice) { // Switch-case to handle different tool selections
        case 1:
            brute_force_simulator(); // Execute Brute Force Attack Simulator
            break;
        case 2:
            file_encryption_tool(); // Execute Basic File Encryption Tool
            break;
        case 3:
            file_decryption_tool(); // Execute Basic File Decryption Tool
            break;
        case 4:
            password_generator(); // Execute Password Generator
            break;
        case 5:
            password_strength_checker(); // Execute Password Strength Checker
            break;
        case 6:
            display_help(); // Display the help section
            break;
        case 7:
            user_exit(); // Exit the program
            break;
        default:
            // Handle invalid menu choices
            printf("%s%sERROR%s: Invalid choice! Please choose a valid tool.\n", ERROR, BOLD, RESET);
            sleep(1); // Wait for 1 second before returning to menu
    }
}

// Main function: Entry point of the program
int main() {
    load_settings(); // Load settings (theme-related settings removed)

    display_intro(); // Display introductory information

    login_system(); // Handle user login

    // Infinite loop to continuously display the tools menu and handle user selections
    while (1) {
        display_tools_menu(); // Display the tools menu
        int choice = get_valid_choice(1, 7); // Get a valid choice from the user within the range 1-7
        handle_choice(choice); // Execute the corresponding tool based on user choice
    }

    return 0; // Return 0 to indicate successful program termination
}
