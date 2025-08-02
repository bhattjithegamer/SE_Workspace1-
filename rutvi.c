#include <stdio.h>

// Function declarations
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error! Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

// Function to display menu
void displayMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("================\n");
}

int main() {
    int choice;
    float num1, num2, result;

    while (1) { // Loop for multiple operations
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting Calculator. Thank you!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please select a valid option (1-5).\n");
            continue;
        }

        // Taking user inputs for numbers
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);

        // Performing operation based on user choice
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result of Addition: %.2f\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result of Subtraction: %.2f\n", result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result of Multiplication: %.2f\n", result);
                break;
            case 4:
                result = divide(num1, num2);
                if (num2 != 0) // Only display result if division is valid
                    printf("Result of Division: %.2f\n", result);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
