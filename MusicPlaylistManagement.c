#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    char artist[100];
    struct Song* next;
    struct Song* prev;
} Song;

Song* head = NULL;
Song* current = NULL;

Song* createSong(char title[], char artist[]) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->next = NULL;
    newSong->prev = NULL;
    return newSong;
}

void addSong(char title[], char artist[]) {
    Song* newSong = createSong(title, artist);
    if (head == NULL) {
        head = newSong;
        current = head;
    } else {
        Song* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newSong;
        newSong->prev = temp;
    }
    printf("Song added: %s - %s\n", title, artist);
}

void deleteSong(char title[]) {
    Song* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next)
                temp->next->prev = temp->prev;

            if (current == temp)
                current = head;

            free(temp);
            printf("Song deleted: %s\n", title);
            return;
        }
        temp = temp->next;
    }
    printf("Song not found: %s\n", title);
}

void displayPlaylist() {
    Song* temp = head;
    if (!temp) {
        printf("Playlist is empty.\n");
        return;
    }
    printf("\nPlaylist:\n");
    while (temp != NULL) {
        printf("Title: %s | Artist: %s\n", temp->title, temp->artist);
        temp = temp->next;
    }
}

void playNext() {
    if (current && current->next) {
        current = current->next;
        printf("Now playing: %s by %s\n", current->title, current->artist);
    } else {
        printf("You are at the end of the playlist.\n");
    }
}

void playPrevious() {
    if (current && current->prev) {
        current = current->prev;
        printf("Now playing: %s by %s\n", current->title, current->artist);
    } else {
        printf("You are at the start of the playlist.\n");
    }
}

int main() {
    int choice;
    char title[100], artist[100];

    do {
        printf("\n--- Music Playlist Menu ---\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Play Next Song\n");
        printf("5. Play Previous Song\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
        case 1:
            printf("Enter song title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;

            printf("Enter artist name: ");
            fgets(artist, sizeof(artist), stdin);
            artist[strcspn(artist, "\n")] = 0;

            addSong(title, artist);
            break;

        case 2:
            printf("Enter title of song to delete: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;
            deleteSong(title);
            break;

        case 3:
            displayPlaylist();
            break;

        case 4:
            playNext();
            break;

        case 5:
            playPrevious();
            break;

        case 6:
            printf("Exiting playlist manager...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}