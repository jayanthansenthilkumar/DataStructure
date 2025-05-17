#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char data[MAX][100];
    int top;
} Stack;

// Initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push operation
void push(Stack *s, char *str) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push more items.\n");
        return;
    }
    strcpy(s->data[++(s->top)], str);
}

// Pop operation
char *pop(Stack *s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->data[(s->top)--];
}

// Peek operation
char *peek(Stack *s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->data[s->top];
}

int main() {
    Stack undoStack, redoStack;
    init(&undoStack);
    init(&redoStack);

    char currentState[100] = "Initial State";
    char input[100];
    int choice;

    while (1) {
        printf("\nCurrent State: %s\n", currentState);
        printf("1. Edit\n2. Undo\n3. Redo\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline character

        switch (choice) {
            case 1: // Edit operation
                printf("Enter new state: ");
                fgets(input, 100, stdin);
                input[strcspn(input, "\n")] = 0;  // Remove newline
                
                push(&undoStack, currentState);   // Save current state for undo
                strcpy(currentState, input);      // Update the current state
                init(&redoStack);                 // Clear redo stack
                break;

            case 2: // Undo operation
                if (!isEmpty(&undoStack)) {
                    push(&redoStack, currentState); // Save current state for redo
                    strcpy(currentState, pop(&undoStack));
                } else {
                    printf("Nothing to undo.\n");
                }
                break;

            case 3: // Redo operation
                if (!isEmpty(&redoStack)) {
                    push(&undoStack, currentState); // Save current state for undo
                    strcpy(currentState, pop(&redoStack));
                } else {
                    printf("Nothing to redo.\n");
                }
                break;

            case 4: // Exit
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}