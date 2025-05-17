#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 10

// Initialize seating arrangement (0 = Available, 1 = Booked)
int seats[ROWS][COLS];

// Function to display the seating layout
void displaySeats() {
    printf("\n---- Movie Theatre Seating Layout ----\n");
    printf("   ");
    for (int j = 0; j < COLS; j++)
        printf("%d ", j + 1);
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%c |", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 0)
                printf(" O ");  // Available
            else
                printf(" X ");  // Booked
        }
        printf("\n");
    }
    printf("--------------------------------------\n");
}

// Function to book a seat
void bookSeat() {
    char row;
    int col;
    printf("Enter seat to book (e.g., A5): ");
    scanf(" %c%d", &row, &col);

    int rowIndex = row - 'A';
    int colIndex = col - 1;

    if (rowIndex >= 0 && rowIndex < ROWS && colIndex >= 0 && colIndex < COLS) {
        if (seats[rowIndex][colIndex] == 0) {
            seats[rowIndex][colIndex] = 1;
            printf("Seat %c%d successfully booked.\n", row, col);
        } else {
            printf("Seat %c%d is already booked. Try another seat.\n", row, col);
        }
    } else {
        printf("Invalid seat selection. Please try again.\n");
    }
}

// Function to cancel a booking
void cancelSeat() {
    char row;
    int col;
    printf("Enter seat to cancel (e.g., A5): ");
    scanf(" %c%d", &row, &col);

    int rowIndex = row - 'A';
    int colIndex = col - 1;

    if (rowIndex >= 0 && rowIndex < ROWS && colIndex >= 0 && colIndex < COLS) {
        if (seats[rowIndex][colIndex] == 1) {
            seats[rowIndex][colIndex] = 0;
            printf("Seat %c%d successfully canceled.\n", row, col);
        } else {
            printf("Seat %c%d is not booked.\n", row, col);
        }
    } else {
        printf("Invalid seat selection. Please try again.\n");
    }
}

// Function to check seat availability
void checkSeat() {
    char row;
    int col;
    printf("Enter seat to check (e.g., A5): ");
    scanf(" %c%d", &row, &col);

    int rowIndex = row - 'A';
    int colIndex = col - 1;

    if (rowIndex >= 0 && rowIndex < ROWS && colIndex >= 0 && colIndex < COLS) {
        if (seats[rowIndex][colIndex] == 0) {
            printf("Seat %c%d is available.\n", row, col);
        } else {
            printf("Seat %c%d is already booked.\n", row, col);
        }
    } else {
        printf("Invalid seat selection. Please try again.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. View Seating Layout\n2. Book a Seat\n3. Cancel a Booking\n4. Check Seat Availability\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelSeat();
                break;
            case 4:
                checkSeat();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}