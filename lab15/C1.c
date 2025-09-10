// 74. Write a program to simulate music player application using suitable data 
// structure. There is no estimation about number of music files to be managed by 
// the music player. Your program should support all the basic music player 
// operations to play and manage the playlist. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    char songName[100];
    struct Node* next;
};

struct Node* createNode(char* songName) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->songName, songName);
    newNode->next = NULL;
    return newNode;
}

void addToPlaylist(struct Node** head, char* songName) {
    struct Node* newNode = createNode(songName);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point to itself
    } else {
        struct Node* curr = *head;
        while (curr->next != *head) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = *head; // New node points to head
    }
}

void displayPlaylist(struct Node* head) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Node* curr = head;
    do {
        printf("%s -> ", curr->songName);
        curr = curr->next;
    } while (curr != head);
    printf("(back to start)\n");
}

void playSong(struct Node* head, char* songName) {
    if (head == NULL) {
        printf("Playlist is empty. Cannot play song.\n");
        return;
    }
    struct Node* curr = head;
    do {
        if (strcmp(curr->songName, songName) == 0) {
            printf("Playing: %s\n", curr->songName);
            return;
        }
        curr = curr->next;
    } while (curr != head);
    printf("Song '%s' not found in the playlist.\n", songName);
}

void shufflePlaylist(struct Node** head) {
    if (*head == NULL || (*head)->next == *head) {
        return; // No need to shuffle if empty or only one song
    }
    
    struct Node* curr = *head;
    struct Node* prev = NULL;
    int count = 0;

    // Count the number of songs
    do {
        count++;
        prev = curr;
        curr = curr->next;
    } while (curr != *head);

    // Shuffle logic (simple random shuffle)
    for (int i = 0; i < count; i++) {
        int randIndex = rand() % count;
        struct Node* temp = *head;
        for (int j = 0; j < randIndex; j++) {
            temp = temp->next;
        }
        printf("Shuffled song: %s\n", temp->songName);
    }
}

void deleteSong(struct Node** head, char* songName) {
    if (*head == NULL) {
        printf("Playlist is empty. Cannot delete song.\n");
        return;
    }
    
    struct Node* curr = *head;
    struct Node* prev = NULL;

    do {
        if (strcmp(curr->songName, songName) == 0) {
            if (prev == NULL) { // Deleting head
                if (curr->next == *head) { // Only one node
                    free(curr);
                    *head = NULL;
                } else {
                    struct Node* last = *head;
                    while (last->next != *head) {
                        last = last->next;
                    }
                    last->next = curr->next; // Update last node's next
                    *head = curr->next; // Update head
                    free(curr);
                }
            } else {
                prev->next = curr->next; // Bypass the current node
                free(curr);
            }
            printf("Deleted song: %s\n", songName);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != *head);

    printf("Song '%s' not found in the playlist.\n", songName);
}

void playNext(struct Node** head) {
    if (*head == NULL) {
        printf("Playlist is empty. Cannot play next song.\n");
        return;
    }
    
    struct Node* curr = *head;
    printf("Playing next song: %s\n", curr->songName);
    *head = curr->next; // Move head to next song
}

void playPrevious(struct Node** head) {
    if (*head == NULL) {
        printf("Playlist is empty. Cannot play previous song.\n");
        return;
    }
    
    struct Node* curr = *head;
    struct Node* prev = NULL;

    // Find the last node
    while (curr->next != *head) {
        prev = curr;
        curr = curr->next;
    }

    // Now curr is the last node, and prev is the second last
    printf("Playing previous song: %s\n", prev->songName);
    *head = prev; // Move head to previous song
}

void createPlaylist(struct Node** head) {
    *head = NULL; // Initialize the playlist as empty
}


int main() {

    struct Node* playlist = NULL;
    int choice;
    char songName[100];


    printf("\nMusic Player Menu:\n");
    printf("0. Create Playlist\n");
        printf("1. Add Song to Playlist\n");
        printf("2. Display Playlist\n");
        printf("3. Play Song\n");
        printf("4. Shuffle Playlist\n");
        printf("5. Delete Song\n");
        printf("6. Play Next Song\n");
        printf("7. Play Previous Song\n");
        printf("8. Exit\n");

    while (true) {

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                fgets(songName, sizeof(songName), stdin);
                songName[strcspn(songName, "\n")] = 0; // Remove newline character
                addToPlaylist(&playlist, songName);
                break;
            case 2:
                displayPlaylist(playlist);
                break;
            case 3:
                printf("Enter song name to play: ");
                fgets(songName, sizeof(songName), stdin);
                songName[strcspn(songName, "\n")] = 0; // Remove newline character
                playSong(playlist, songName);
                break;
            case 4:
                shufflePlaylist(&playlist);
                break;
            case 5:
                printf("Enter song name to delete: ");
                fgets(songName, sizeof(songName), stdin);
                songName[strcspn(songName, "\n")] = 0; // Remove newline character
                deleteSong(&playlist, songName);
                break;
            case 6:
                playNext(&playlist);
                break;
            case 7:
                playPrevious(&playlist);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}