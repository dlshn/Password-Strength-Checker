#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool has_uppercase(const char *password) {
    while (*password) {
        if (isupper(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

bool has_lowercase(const char *password) {
    while (*password) {
        if (islower(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

bool has_digit(const char *password) {
    while (*password) {
        if (isdigit(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

bool has_special_char(const char *password) {
    while (*password) {
        if (!isalnum(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

bool is_common_word(const char *password) {
    // Add more common words as needed
    const char *common_words[] = { "password", "123456", "qwerty", "admin" };
    int num_common_words = sizeof(common_words) / sizeof(common_words[0]);

    for (int i = 0; i < num_common_words; i++) {
        if (strcmp(password, common_words[i]) == 0) {
            return true;
        }
    }
    return false;
}

int calculate_strength_score(const char *password) {
    int strength_score = 0;
    int min_length = 8;

    if (strlen(password) >= min_length) {
        strength_score++;
    }
    if (has_uppercase(password)) {
        strength_score++;
    }
    if (has_lowercase(password)) {
        strength_score++;
    }
    if (has_digit(password)) {
        strength_score++;
    }
    if (has_special_char(password)) {
        strength_score++;
    }
    if (!is_common_word(password)) {
        strength_score++;
    }

    return strength_score;
}

int main() {
    char password[100];
    int strength_score;

    printf("Enter your password: ");
    scanf("%s", password);

    strength_score = calculate_strength_score(password);

    if (strength_score >= 5) {
        printf("Your password is very strong!\n");
    } else if (strength_score >= 3) {
        printf("Your password is strong.\n");
    } else if (strength_score >= 1) {
        printf("Your password is weak. Please consider improving it.\n");
    } else {
        printf("Your password is very weak. Please choose a stronger password.\n");
    }

    return 0;
}
