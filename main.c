#include <stdio.h>
#include <stdlib.h>

#define TOTAL_LEVELS 5
#define MAX_LIVES 3

int stackGuardianDefeated = 0;
int queueGuardianDefeated = 0;
int citadelRewardClaimed = 0;
int forestRewardClaimed = 0;

typedef struct {
    char name[30];
    int lives;
    int score;
    int level;
    int xp;
    int coins;
    int maxLevelUnlocked;
} Player;
void unlockNextLevel(Player *player, int completedLevel);
void loseLife(Player *player);

void showTitle(void) {
    printf("\n");
    printf("================================================\n");
    printf("          ALGORITHM APOCALYPSE\n");
    printf("             THE FALL OF THE CORE\n");
    printf("================================================\n");
    printf(" Five guardians. One corrupted world.\n");
    printf(" One final algorithm.\n");
    printf("================================================\n");
}

void showStory(void) {
    printf("\n========== THE APOCALYPSE BEGINS ==========\n");
    printf("The year is 2099.\n\n");
    printf("The Algorithm Core has been corrupted.\n");
    printf("Five guardians control the digital world.\n");
    printf("Data is disordered. Paths are lost.\n\n");
    printf("You are the last Algorithm Guardian.\n");
    printf("Master five DSA challenges and restore the Core!\n");
    printf("===========================================\n");
}

void showMap(void) {
    printf("\n============== WORLD MAP ==============\n");
    printf(" [1] Sorting Wasteland\n");
    printf(" [2] Searching Ruins\n");
    printf(" [3] Stack & Queue Citadel\n");
    printf(" [4] Linked-List Forest\n");
    printf(" [5] Graph Abyss\n");
    printf(" [F] The Algorithm Core\n");
    printf("=======================================\n");
}


void showStatus(Player *player) {
    printf("\n");
    printf("========================================\n");
    printf("       GUARDIAN STATUS - DARK REALM\n");
    printf("========================================\n");

    printf("Guardian       : %s\n", player->name);

    printf("Lives          : ");
    for (int i = 0; i < player->lives; i++) {
        printf("<3 ");
    }
    if (player->lives <= 0) {
        printf("NONE");
    }

    printf("\nScore          : %d\n", player->score);
    printf("Experience     : %d XP\n", player->xp);
    printf("Dark Coins     : %d\n", player->coins);

    printf("Current Level  : %d / 5\n",
           player->level > 5 ? 5 : player->level);

    printf("Highest Unlocked: %d / 5\n",
           player->maxLevelUnlocked);

    if (player->xp >= 500) {
        printf("Guardian Rank  : CORE GUARDIAN\n");
    } else if (player->xp >= 250) {
        printf("Guardian Rank  : SHADOW HUNTER\n");
    } else if (player->xp >= 100) {
        printf("Guardian Rank  : RUNE KEEPER\n");
    } else {
        printf("Guardian Rank  : APPRENTICE\n");
    }

    printf("========================================\n");
}

void loseLife(Player *player) {
    if (player->lives > 0) {
        player->lives--;

        printf("\nWRONG ANSWER! You lost one life.\n");
        printf("Remaining lives: ");

        for (int i = 0; i < player->lives; i++) {
            printf("<3 ");
        }

        if (player->lives == 0) {
            printf("NONE");
        }

        printf("\n");

        if (player->lives == 0) {
            printf("\n");
            printf("====================================\n");
            printf("       GAME OVER, GUARDIAN!\n");
            printf(" The Algorithm Core has fallen...\n");
            printf(" Final Score: %d\n", player->score);
            printf("====================================\n");
        }
    }
}

/* ========== LEVEL 1: SORTING WASTELAND ========== */

#ifdef _WIN32
#include <windows.h>
#define GAME_DELAY() Sleep(250)
#else
#include <time.h>
#define GAME_DELAY() do { \
    struct timespec ts = {0, 250000000L}; \
    nanosleep(&ts, NULL); \
} while (0)
#endif

void showArray(int a[], int n) {
    printf("\n  ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", a[i]);
    }
    printf("\n");
}

void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n, int *comparisons,
                int *swaps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;

            printf("\nComparing %d and %d...\n",
                   a[j], a[j + 1]);

            if (a[j] > a[j + 1]) {
                swapValues(&a[j], &a[j + 1]);
                (*swaps)++;

                printf("Guardian attack! Values swapped.\n");
            } else {
                printf("No swap needed.\n");
            }

            showArray(a, n);
            GAME_DELAY();
        }
    }
}

void insertionSort(int a[], int n, int *comparisons,
                   int *swaps) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0) {
            (*comparisons)++;

            printf("\nComparing %d with %d...\n",
                   a[j], key);

            if (a[j] > key) {
                a[j + 1] = a[j];
                (*swaps)++;
                j--;
                showArray(a, n);
                GAME_DELAY();
            } else {
                break;
            }
        }

        a[j + 1] = key;
        showArray(a, n);
    }
}

int partitionArray(int a[], int low, int high,
                   int *comparisons, int *swaps) {
    int pivot = a[high];
    int i = low - 1;

    printf("\nPivot selected: %d\n", pivot);

    for (int j = low; j < high; j++) {
        (*comparisons)++;

        printf("Comparing %d with pivot %d\n",
               a[j], pivot);

        if (a[j] <= pivot) {
            i++;

            if (i != j) {
                swapValues(&a[i], &a[j]);
                (*swaps)++;
            }

            showArray(a, high + 1);
            GAME_DELAY();
        }
    }

    if (i + 1 != high) {
        swapValues(&a[i + 1], &a[high]);
        (*swaps)++;
    }

    showArray(a, high + 1);
    return i + 1;
}

void quickSort(int a[], int low, int high,
               int *comparisons, int *swaps) {
    if (low < high) {
        int pivotIndex = partitionArray(
            a, low, high, comparisons, swaps);

        quickSort(a, low, pivotIndex - 1,
                  comparisons, swaps);

        quickSort(a, pivotIndex + 1, high,
                  comparisons, swaps);
    }
}

void sortingWasteland(Player *player) {
        if (player->lives <= 0) {
        printf("\nGAME OVER! You have no lives remaining.\n");
        return;
    }
    int a[] = {42, 17, 89, 23, 5, 61};
    int n = sizeof(a) / sizeof(a[0]);
    int comparisons = 0;
    int swaps = 0;
    int choice;

    printf("\n");
    printf("================================================\n");
    printf("           LEVEL 1: SORTING WASTELAND\n");
    printf("================================================\n");
    printf("THE SORTING BEAST has corrupted the data!\n");
    printf("Restore the correct order to damage the beast.\n");

    printf("\nCorrupted array:\n");
    showArray(a, n);
      
    int answer;
    int correctAnswers = 0;

    printf("\n========== GUARDIAN TRIAL ==========\n");
    printf("Answer at least 2 out of 3 questions to fight!\n");

    /* QUESTION 1 */
    printf("\nQ1. Which sorting algorithm compares adjacent elements?\n");
    printf("1. Binary Search\n");
    printf("2. Bubble Sort\n");
    printf("3. Depth-First Search\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 2) {
        printf("Correct! +1 trial point.\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("\nGAME OVER! The Guardian has fallen.\n");
            return;
        }
    }

    /* QUESTION 2 */
    printf("\nQ2. Which algorithm inserts each element into its correct position?\n");
    printf("1. Insertion Sort\n");
    printf("2. BFS\n");
    printf("3. Linear Search\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 1) {
        printf("Correct! +1 trial point.\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("\nGAME OVER! The Guardian has fallen.\n");
            return;
        }
    }

    /* QUESTION 3 */
    printf("\nQ3. Which sorting algorithm uses a pivot to partition elements?\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Quick Sort\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 3) {
        printf("Correct! +1 trial point.\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("\nGAME OVER! The Guardian has fallen.\n");
            return;
        }
    }

    printf("\nTrial result: %d / 3 correct answers.\n",
           correctAnswers);

    if (correctAnswers < 2) {
        printf("TRIAL FAILED! You need at least 2 correct answers.\n");
        printf("Return and try again when you are ready.\n");
        return;
    }

    printf("TRIAL PASSED! You may choose your sorting weapon.\n");


    printf("\nChoose your sorting weapon:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Quick Sort\n");
    printf("0. Retreat to Main Menu\n");
    printf("Choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        return;
    }

    if (choice == 0) {
        printf("You retreat to prepare for battle.\n");
        return;
    }

    if (choice < 1 || choice > 3) {
        printf("Invalid weapon selection!\n");
        return;
    }

    printf("\nThe Sorting Beast awakens!\n");
    printf("Algorithm execution begins...\n");
    GAME_DELAY();

    switch (choice) {
        case 1:
            bubbleSort(a, n, &comparisons, &swaps);
            break;

        case 2:
            insertionSort(a, n, &comparisons, &swaps);
            break;

        case 3:
            quickSort(a, 0, n - 1,
                      &comparisons, &swaps);
            break;
    }

    printf("\n========== BATTLE RESULTS ==========\n");
    printf("Final array: ");
    showArray(a, n);

    printf("Comparisons : %d\n", comparisons);
    printf("Swaps/shifts: %d\n", swaps);

    if (comparisons > 0) {
        printf("Guardian score: %d points\n",
               100 + (n * 20) - comparisons);
    }

    player->score += 100 + (n * 20) - comparisons;
    player->level = 2;
    unlockNextLevel(player, 1);

    printf("\nTHE SORTING BEAST HAS BEEN DEFEATED!\n");
    printf("Level 1 complete! You earned points.\n");
    printf("Current score: %d\n", player->score);
    printf("The Searching Ruins await...\n");
    printf("====================================\n");
}

/* ========== LEVEL 2: SEARCHING RUINS ========== */

int linearSearch(int a[], int n, int target,
                 int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;

        printf("\nSearching position %d: %d\n",
               i + 1, a[i]);

        GAME_DELAY();

        if (a[i] == target) {
            return i;
        }
    }

    return -1;
}

int binarySearch(int a[], int n, int target,
                 int *comparisons) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        (*comparisons)++;

        printf("\nRange: %d to %d\n", low + 1, high + 1);
        printf("Checking middle element: %d\n", a[mid]);

        GAME_DELAY();

        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            printf("Target is larger. Search right half.\n");
            low = mid + 1;
        } else {
            printf("Target is smaller. Search left half.\n");
            high = mid - 1;
        }
    }

    return -1;
}

void searchingRuins(Player *player) {
        if (player->lives <= 0) {
        printf("\nGAME OVER! You have no lives remaining.\n");
        return;
    }
    int unsorted[] = {34, 12, 67, 5, 91, 23, 48};
    int sorted[] = {5, 12, 23, 34, 48, 67, 91};
    int choice, target, comparisons = 0;
    int result = -1;
    int n = 7;


    printf("\n");
    printf("================================================\n");
    printf("             LEVEL 2: SEARCHING RUINS\n");
    printf("================================================\n");
    printf("The Searcher has hidden the Core Key!\n");
    printf("Locate the target to unlock the next region.\n");
    
    int answer;
    int correctAnswers = 0;

    printf("\n========== SEARCHER'S TRIAL ==========\n");
    printf("Answer at least 2 out of 3 questions to proceed.\n");

    /* QUESTION 1 */
    printf("\nQ1. Which search checks elements one by one?\n");
    printf("1. Binary Search\n");
    printf("2. Linear Search\n");
    printf("3. Quick Sort\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 2) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER! No lives remaining.\n");
            return;
        }
    }

    /* QUESTION 2 */
    printf("\nQ2. Binary Search requires which type of data?\n");
    printf("1. Sorted data\n");
    printf("2. Randomly shuffled data\n");
    printf("3. A linked list only\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 1) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER! No lives remaining.\n");
            return;
        }
    }

    /* QUESTION 3 */
    printf("\nQ3. What is the worst-case time complexity of Linear Search?\n");
    printf("1. O(1)\n");
    printf("2. O(log n)\n");
    printf("3. O(n)\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 3) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER! No lives remaining.\n");
            return;
        }
    }

    printf("\nTrial score: %d / 3\n", correctAnswers);

    if (correctAnswers < 2) {
        printf("TRIAL FAILED! You need at least 2 correct answers.\n");
        printf("Return to the main menu and try again later.\n");
        return;
    }

    printf("TRIAL PASSED! The Searcher permits you to proceed.\n");


    printf("\nChoose your search technique:\n");
    printf("1. Linear Search (unsorted data)\n");
    printf("2. Binary Search (sorted data)\n");
    printf("0. Return to Main Menu\n");
    printf("Choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        return;
    }

    if (choice == 0) {
        return;
    }

    if (choice != 1 && choice != 2) {
        printf("Invalid technique.\n");
        return;
    }

    if (choice == 1) {
        printf("\nUnsorted artifacts:\n");
        showArray(unsorted, n);
        printf("Choose a target from the array: ");

        if (scanf("%d", &target) != 1) {
            printf("Invalid target.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            return;
        }

        result = linearSearch(
            unsorted, n, target, &comparisons);
    } else {
        printf("\nSorted artifacts:\n");
        showArray(sorted, n);
        printf("Choose a target from the array: ");

        if (scanf("%d", &target) != 1) {
            printf("Invalid target.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            return;
        }

        result = binarySearch(
            sorted, n, target, &comparisons);
    }

   
    printf("\n========== SEARCH RESULTS ==========\n");

    if (result != -1) {
        printf("Artifact found at position %d!\n", result + 1);
        printf("Comparisons: %d\n", comparisons);
        printf("You defeated the Searcher!\n");

        player->score += 100 + (n * 10) - comparisons;
        player->level = 3;
        unlockNextLevel(player, 2);

        printf("Reward: %d points added to your score.\n",
               100 + (n * 10) - comparisons);
        printf("Total score: %d\n", player->score);
        printf("The Stack & Queue Citadel is unlocked!\n");

    } else {
        printf("Artifact not found!\n");
        printf("The Searcher escapes. You lose one life.\n");
        loseLife(player);

        if (player->lives <= 0) {
            printf("The Searcher has defeated you!\n");
            printf("Restart the game to try again.\n");
        }
    }

    printf("=====================================\n");
}



/* ========== LEVEL 3: STACK & QUEUE CITADEL ========== */

#define STRUCT_CAPACITY 5

typedef struct {
    int data[STRUCT_CAPACITY];
    int top;
} Stack;

typedef struct {
    int data[STRUCT_CAPACITY];
    int front;
    int rear;
    int count;
} Queue;

void initStack(Stack *s) {
    s->top = -1;
}

int push(Stack *s, int value) {
    if (s->top == STRUCT_CAPACITY - 1) {
        return 0;
    }

    s->data[++s->top] = value;
    return 1;
}

int pop(Stack *s, int *value) {
    if (s->top == -1) {
        return 0;
    }

    *value = s->data[s->top--];
    return 1;
}

void displayStack(const Stack *s) {
    printf("\nStack (top to bottom):\n");

    if (s->top == -1) {
        printf("[ Empty ]\n");
        return;
    }

    for (int i = s->top; i >= 0; i--) {
        printf("| %d |\n", s->data[i]);
    }

    printf("-----\n");
}

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int enqueue(Queue *q, int value) {
    if (q->count == STRUCT_CAPACITY) {
        return 0;
    }

    q->rear = (q->rear + 1) % STRUCT_CAPACITY;
    q->data[q->rear] = value;
    q->count++;
    return 1;
}

int dequeue(Queue *q, int *value) {
    if (q->count == 0) {
        return 0;
    }

    *value = q->data[q->front];
    q->front = (q->front + 1) % STRUCT_CAPACITY;
    q->count--;
    return 1;
}

void displayQueue(const Queue *q) {
    printf("\nQueue (front to rear):\n");

    if (q->count == 0) {
        printf("[ Empty ]\n");
        return;
    }

    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % STRUCT_CAPACITY;
        printf("[%d]", q->data[index]);

        if (i < q->count - 1) {
            printf(" <- ");
        }
    }

    printf("\n");
}

void stackChallenge(void) {
    Stack s;
    int value;
    initStack(&s);

    printf("\n========== STACK TOWER ==========\n");
    printf("The gate requires the correct LIFO sequence.\n");
    printf("Perform these operations:\n");
    printf("PUSH 10, PUSH 20, PUSH 30, POP\n");

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    displayStack(&s);

    pop(&s, &value);
    printf("\nRemoved by POP: %d\n", value);
    displayStack(&s);

    if (s.top == 1 &&
        s.data[0] == 10 && s.data[1] == 20) {
        printf("STACK GATE UNLOCKED!\n");
    }
}

void queueChallenge(void) {
    Queue q;
    int value;
    initQueue(&q);

    printf("\n========== QUEUE BRIDGE ==========\n");
    printf("Rescue people in FIFO order.\n");

    enqueue(&q, 101);
    enqueue(&q, 102);
    enqueue(&q, 103);

    displayQueue(&q);

    dequeue(&q, &value);
    printf("\nRescued first: %d\n", value);
    displayQueue(&q);

    if (value == 101 && q.count == 2) {
        printf("QUEUE BRIDGE UNLOCKED!\n");
    }
}

void stackQueueCitadel(Player *player) {
        if (player->lives <= 0) {
        printf("\nGAME OVER! No lives remaining.\n");
        return;
    }
    int choice;

    printf("\n");
    printf("================================================\n");
    printf("          LEVEL 3: STACK & QUEUE CITADEL\n");
    printf("================================================\n");
    printf("Two guardians block your path.\n");
    printf("Master LIFO and FIFO to pass the Citadel.\n");
    
    int answer;
    int correctAnswers = 0;

    printf("\n========== CITADEL TRIAL ==========\n");
    printf("Answer at least 2 of 3 questions to proceed.\n");

    /* QUESTION 1 */
    printf("\nQ1. What does LIFO mean?\n");
    printf("1. Last In, First Out\n");
    printf("2. First In, First Out\n");
    printf("3. Last In, Last Out\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 1) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER!\n");
            return;
        }
    }

    /* QUESTION 2 */
    printf("\nQ2. Which data structure follows FIFO?\n");
    printf("1. Stack\n");
    printf("2. Queue\n");
    printf("3. Binary Search Tree\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 2) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER!\n");
            return;
        }
    }

    /* QUESTION 3 */
    printf("\nQ3. In a circular queue, how is the next index calculated?\n");
    printf("1. index + 1 only\n");
    printf("2. index - 1\n");
    printf("3. (index + 1) %% capacity\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 3) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER!\n");
            return;
        }
    }

    printf("\nTrial result: %d / 3\n", correctAnswers);

    if (correctAnswers < 2) {
        printf("TRIAL FAILED! You need at least 2 correct answers.\n");
        return;
    }

    printf("TRIAL PASSED! Choose your Citadel challenge.\n");


    printf("\n1. Stack Tower\n");
    printf("2. Queue Bridge\n");
    printf("0. Retreat\n");
    printf("Choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        return;
    }

   switch (choice) {
    case 1:
        stackChallenge();
        stackGuardianDefeated = 1;
        break;

    case 2:
        queueChallenge();
        queueGuardianDefeated = 1;
        break;

    case 0:
        return;

    default:
        printf("Invalid choice.\n");
        return;
}

   printf("\n========== CITADEL PROGRESS ==========\n");
printf("Stack Guardian: %s\n",
       stackGuardianDefeated ? "DEFEATED" : "STILL ACTIVE");
printf("Queue Guardian: %s\n",
       queueGuardianDefeated ? "DEFEATED" : "STILL ACTIVE");

if (stackGuardianDefeated &&
    queueGuardianDefeated &&
    !citadelRewardClaimed) {
    printf("\nBoth guardians have been defeated!\n");

    player->level = 4;
    unlockNextLevel(player, 3);

    player->score += 100;
    player->xp += 100;
    player->coins += 25;
    citadelRewardClaimed = 1;

    printf("Citadel reward: +100 score, +100 XP, +25 coins!\n");
} else if (citadelRewardClaimed) {
    printf("\nCitadel reward has already been claimed.\n");
} else {
    printf("\nDefeat the other guardian to unlock Level 4.\n");
}

printf("Current score: %d\n", player->score);
}
/* ================= LEVEL 4: LINKED-LIST FOREST ================= */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Create a new node dynamically */
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert a node at the end */
Node *insertEnd(Node *head, int value) {
    Node *newNode = createNode(value);

    if (newNode == NULL) {
        return head;
    }

    if (head == NULL) {
        return newNode;
    }

    Node *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

/* Display every node */
void displayList(Node *head) {
    Node *current = head;

    printf("\nMemory Chain: ");

    if (current == NULL) {
        printf("EMPTY");
    }

    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

/* Delete the first node containing the given value */
Node *deleteValue(Node *head, int value, int *deleted) {
    Node *current = head;
    Node *previous = NULL;

    *deleted = 0;

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return head;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    *deleted = 1;

    return head;
}

/* Reverse the linked list */
Node *reverseList(Node *head) {
    Node *previous = NULL;
    Node *current = head;
    Node *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

/* Release all dynamically allocated memory */
void freeList(Node *head) {
    Node *current = head;

    while (current != NULL) {
        Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

/* Main gameplay for Level 4 */
void linkedListForest(Player *player) {
        if (player->lives <= 0) {
        printf("\nGAME OVER! No lives remaining.\n");
        return;
    }
    Node *head = NULL;
    int choice;
    int value;
    int deleted;
    int inserted = 0;
    int removed = 0;
    int reversed = 0;
    int running = 1;

    printf("\n");
    printf("========================================\n");
    printf("       LEVEL 4: LINKED-LIST FOREST\n");
    printf("========================================\n");
    printf("The memory chains are broken!\n");
    printf("Restore the chain to unlock the exit.\n");
    
    int answer;
    int correctAnswers = 0;

    printf("\n========== FOREST TRIAL ==========\n");
    printf("Answer at least 2 out of 3 questions to proceed.\n");

    /* QUESTION 1 */
    printf("\nQ1. What does a linked-list node usually contain?\n");
    printf("1. Data and a pointer to the next node\n");
    printf("2. Only an array index\n");
    printf("3. Only a sorting algorithm\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 1) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER!\n");
            return;
        }
    }

    /* QUESTION 2 */
    printf("\nQ2. Which pointer is updated to reverse a linked list?\n");
    printf("1. Only the head pointer\n");
    printf("2. Each node's next pointer\n");
    printf("3. No pointers need updating\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 2) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER!\n");
            return;
        }
    }

    /* QUESTION 3 */
    printf("\nQ3. What does free(node) help accomplish?\n");
    printf("1. Sorts the linked list\n");
    printf("2. Creates a new node\n");
    printf("3. Releases dynamically allocated memory\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 3) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER!\n");
            return;
        }
    }

    printf("\nTrial result: %d / 3\n", correctAnswers);

    if (correctAnswers < 2) {
        printf("TRIAL FAILED! You need at least 2 correct answers.\n");
        return;
    }

    printf("TRIAL PASSED! Entering the Linked-List Forest...\n");


    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    displayList(head);

    while (running) {
        printf("\n----------- FOREST ACTIONS -----------\n");
        printf("1. Insert a memory node\n");
        printf("2. Delete a corrupted node\n");
        printf("3. Traverse the memory chain\n");
        printf("4. Reverse the memory chain\n");
        printf("5. Check mission progress\n");
        printf("0. Leave the forest\n");
        printf("--------------------------------------\n");
        printf("Choose your action: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Clear invalid input */
            }

            continue;
        }

        switch (choice) {
             case 1: {
                printf("Enter the value for the new node: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid value. Try again.");

                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {
                        /* Clear invalid input */
                    }

                    break;
                }

                int countBefore = 0;
                int countAfter = 0;
                Node *current = head;

                while (current != NULL) {
                    countBefore++;
                    current = current->next;
                }

                head = insertEnd(head, value);

                current = head;
                while (current != NULL) {
                    countAfter++;
                    current = current->next;
                }

                if (countAfter > countBefore) {
                    printf("Memory node inserted successfully!\n");
                    inserted = 1;
                    displayList(head);
                } else {
                    printf("Insertion failed. Try again.\n");
                }

                break;
            }
            case 2:
                printf("Enter the corrupted value to delete: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid value. Try again.\n");

                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {
                        /* Clear invalid input */
                    }

                    break;
                }

                head = deleteValue(head, value, &deleted);

                if (deleted) {
                    printf("Corrupted node removed successfully!\n");
                    removed = 1;
                } else {
                    printf("That value was not found in the chain.\n");
                }

                displayList(head);
                break;

            case 3:
                printf("\nTraversing every memory node...\n");
                displayList(head);
                printf("Traversal complete!\n");
                break;

            case 4:
                head = reverseList(head);
                reversed = 1;

                printf("\nMemory chain reversed!\n");
                displayList(head);
                break;

            case 5:
                printf("\n========== MISSION STATUS ==========\n");
                printf("Insert a node:  %s\n",
                       inserted ? "COMPLETE" : "PENDING");
                printf("Delete a node:  %s\n",
                       removed ? "COMPLETE" : "PENDING");
                printf("Reverse chain:  %s\n",
                       reversed ? "COMPLETE" : "PENDING");

                
                if (inserted && removed && reversed) {
                    printf("\nAll three forest missions completed!\n");
                    printf("The exit portal is now unlocked!\n");

                    if (!forestRewardClaimed) {
                        player->score += 100;
                        forestRewardClaimed = 1;
                    }

                    player->level = 5;
                    unlockNextLevel(player, 4);
                    running = 0;

                } else {
                    printf("\nComplete all three missions to unlock the exit.\n");
                }
                break;


            case 0:
                printf("\nYou leave the forest without completing the mission.\n");
                running = 0;
                break;

            default:
                printf("Invalid choice! Choose an action from the menu.\n");
        }
    }

    freeList(head);

    printf("\nAll allocated memory has been released.\n");

    if (player->level == 5) {
    printf("\nLinked-List Guardian defeated!\n");
    printf("Current Score: %d\n", player->score);
    printf("The Graph Abyss awaits you...\n");
}
}

/* ========== LEVEL 5: GRAPH ABYSS ========== */

#define GRAPH_SIZE 6

const char *graphNames[GRAPH_SIZE] = {
    "Entrance",
    "Crystal Bridge",
    "Echo Cavern",
    "Shadow Gate",
    "Core Bridge",
    "Algorithm Core"
};

const int graph[GRAPH_SIZE][GRAPH_SIZE] = {
    {0, 4, 2, 0, 0, 0},
    {4, 0, 1, 5, 0, 0},
    {2, 1, 0, 8, 10, 0},
    {0, 5, 8, 0, 2, 6},
    {0, 0, 10, 2, 0, 3},
    {0, 0, 0, 6, 3, 0}
};

/* Breadth-First Search */
void graphBFS(int start) {
    int visited[GRAPH_SIZE] = {0};
    int queue[GRAPH_SIZE];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS exploration order:\n");

    while (front < rear) {
        int current = queue[front++];
        printf("%s", graphNames[current]);

        if (front < rear) {
            printf(" -> ");
        }

        for (int i = 0; i < GRAPH_SIZE; i++) {
            if (graph[current][i] > 0 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\nBFS complete!\n");
}

/* Depth-First Search helper */
void graphDFSVisit(int current, int visited[], int *first) {
    visited[current] = 1;

    if (!(*first)) {
        printf(" -> ");
    }

    printf("%s", graphNames[current]);
    *first = 0;

    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (graph[current][i] > 0 && !visited[i]) {
            graphDFSVisit(i, visited, first);
        }
    }
}

/* Depth-First Search */
void graphDFS(int start) {
    int visited[GRAPH_SIZE] = {0};
    int first = 1;

    printf("\nDFS exploration order:\n");
    graphDFSVisit(start, visited, &first);
    printf("\nDFS complete!\n");
}

/* Dijkstra's Shortest-Path Algorithm */
void graphDijkstra(int start, int target) {
    const int INF = 1000000;
    int distance[GRAPH_SIZE];
    int visited[GRAPH_SIZE] = {0};
    int parent[GRAPH_SIZE];

    for (int i = 0; i < GRAPH_SIZE; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }

    distance[start] = 0;

    for (int count = 0; count < GRAPH_SIZE; count++) {
        int current = -1;
        int smallest = INF;

        for (int i = 0; i < GRAPH_SIZE; i++) {
            if (!visited[i] && distance[i] < smallest) {
                smallest = distance[i];
                current = i;
            }
        }

        if (current == -1) {
            break;
        }

        visited[current] = 1;

        for (int i = 0; i < GRAPH_SIZE; i++) {
            if (graph[current][i] > 0 && !visited[i]) {
                int newDistance =
                    distance[current] + graph[current][i];

                if (newDistance < distance[i]) {
                    distance[i] = newDistance;
                    parent[i] = current;
                }
            }
        }
    }

    if (distance[target] == INF) {
        printf("\nNo path exists to the destination.\n");
        return;
    }

    int path[GRAPH_SIZE];
    int pathLength = 0;
    int current = target;

    while (current != -1 && pathLength < GRAPH_SIZE) {
        path[pathLength++] = current;
        current = parent[current];
    }

    printf("\nShortest path to the Algorithm Core:\n");

    for (int i = pathLength - 1; i >= 0; i--) {
        printf("%s", graphNames[path[i]]);

        if (i > 0) {
            printf(" -> ");
        }
    }

    printf("\nTotal travel cost: %d\n", distance[target]);
}

/* Level 5 gameplay */
void graphAbyss(Player *player) {
    if (player->lives <= 0) {
        printf("\nGAME OVER! No lives remaining.\n");
        return;
    }

    int answer;
    int correctAnswers = 0;

    printf("\n========================================\n");
    printf("          LEVEL 5: GRAPH ABYSS\n");
    printf("========================================\n");
    printf("The Algorithm Core is corrupted!\n");
    printf("Master three graph algorithms to restore it.\n");

    /* Final Guardian Trial */
    printf("\n========== FINAL GUARDIAN TRIAL ==========\n");
    printf("Answer at least 2 of 3 questions to proceed.\n");

    printf("\nQ1. What does BFS stand for?\n");
    printf("1. Binary Function Search\n");
    printf("2. Breadth-First Search\n");
    printf("3. Backward File Sorting\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 2) {
        correctAnswers++;
        printf("Correct!\n");
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER!\n");
            return;
        }
    }

    printf("\nQ2. Which algorithm explores deeply before backtracking?\n");
    printf("1. DFS\n");
    printf("2. BFS\n");
    printf("3. Bubble Sort\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 1) {
        correctAnswers++;
        printf("Correct!\n");
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER!\n");
            return;
        }
    }

    printf("\nQ3. Which algorithm finds shortest paths with non-negative edge weights?\n");
    printf("1. DFS\n");
    printf("2. Insertion Sort\n");
    printf("3. Dijkstra's Algorithm\n");
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to menu.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (answer == 3) {
        correctAnswers++;
        printf("Correct!\n");
    } else {
        loseLife(player);
        if (player->lives <= 0) {
            printf("GAME OVER!\n");
            return;
        }
    }

    printf("\nTrial result: %d / 3\n", correctAnswers);

    if (correctAnswers < 2) {
        printf("TRIAL FAILED! The Graph Abyss remains sealed.\n");
        return;
    }

    printf("TRIAL PASSED! Entering the Graph Abyss.\n");

    int choice;
    int bfsDone = 0;
    int dfsDone = 0;
    int dijkstraDone = 0;
    int running = 1;

    while (running) {
        printf("\n------------- GRAPH ABYSS -------------\n");
        printf("1. BFS - Explore level by level\n");
        printf("2. DFS - Explore deeply\n");
        printf("3. Dijkstra - Find the cheapest route\n");
        printf("4. Mission status\n");
        printf("0. Return to main menu\n");
        printf("---------------------------------------\n");
        printf("Choose your algorithm: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }

        if (player->lives <= 0) {
            printf("GAME OVER! No lives remaining.\n");
            return;
        }

        switch (choice) {
            case 1:
                graphBFS(0);

                if (!bfsDone) {
                    bfsDone = 1;
                    player->score += 50;
                    printf("+50 points!\n");
                } else {
                    printf("BFS mission already completed.\n");
                }
                break;

            case 2:
                graphDFS(0);

                if (!dfsDone) {
                    dfsDone = 1;
                    player->score += 50;
                    printf("+50 points!\n");
                } else {
                    printf("DFS mission already completed.\n");
                }
                break;

            case 3:
                graphDijkstra(0, GRAPH_SIZE - 1);

                if (!dijkstraDone) {
                    dijkstraDone = 1;
                    player->score += 50;
                    printf("+50 points!\n");
                } else {
                    printf("Dijkstra mission already completed.\n");
                }
                break;

            case 4:
                printf("\n========== FINAL MISSION ==========\n");
                printf("BFS exploration: %s\n",
                       bfsDone ? "COMPLETE" : "PENDING");
                printf("DFS exploration: %s\n",
                       dfsDone ? "COMPLETE" : "PENDING");
                printf("Shortest path: %s\n",
                       dijkstraDone ? "COMPLETE" : "PENDING");

                if (bfsDone && dfsDone && dijkstraDone) {
                    printf("\nAll graph missions completed!\n");
                    printf("THE ALGORITHM CORE IS RESTORED!\n");
                    printf("YOU HAVE DEFEATED THE FINAL GUARDIAN!\n");

                    player->level = 6;
                    player->score += 100;
                    player->xp += 150;
                    player->coins += 50;
                    running = 0;
                } else {
                    printf("\nComplete all three algorithms to win.\n");
                }
                break;

            case 0:
                running = 0;
                printf("Leaving the Graph Abyss...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    printf("\nCurrent score: %d\n", player->score);

    if (player->level == 6) {
        printf("\n**************************************\n");
        printf("       ALGORITHM APOCALYPSE WON!\n");
        printf(" The Algorithm Core shines once more!\n");
        printf("**************************************\n");
    }
}
void unlockNextLevel(Player *player, int completedLevel) {
    int nextLevel = completedLevel + 1;

    if (nextLevel <= 5 &&
        nextLevel > player->maxLevelUnlocked) {

        player->maxLevelUnlocked = nextLevel;

        printf("\n*** NEW REGION UNLOCKED! ***\n");
        printf("You have unlocked Level %d!\n", nextLevel);
    }
}

int main(void) {
    Player player = {"Guardian", MAX_LIVES, 0, 1, 0, 0, 1};
    int choice;

    showTitle();
    showStory();

    printf("\nEnter your guardian name (no spaces): ");
    if (scanf("%29s", player.name) != 1) {
        printf("Could not read the player name.\n");
        return 1;
    }

    do {
        printf("\n");
        
       printf("\n============= MAIN MENU =============\n");
printf("1. Level 1 - Sorting Wasteland\n");

if (player.maxLevelUnlocked >= 2)
    printf("2. Level 2 - Searching Ruins [UNLOCKED]\n");
else
    printf("2. Level 2 - Searching Ruins [LOCKED]\n");

if (player.maxLevelUnlocked >= 3)
    printf("3. Level 3 - Stack & Queue Citadel [UNLOCKED]\n");
else
    printf("3. Level 3 - Stack & Queue Citadel [LOCKED]\n");

printf("4. Player Status\n");

if (player.maxLevelUnlocked >= 4)
    printf("5. Level 4 - Linked-List Forest [UNLOCKED]\n");
else
    printf("5. Level 4 - Linked-List Forest [LOCKED]\n");

if (player.maxLevelUnlocked >= 5)
    printf("6. Level 5 - Graph Abyss [UNLOCKED]\n");
else
    printf("6. Level 5 - Graph Abyss [LOCKED]\n");

printf("0. Exit Game\n");
printf("======================================\n");
printf("Enter your choice: ");


        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Clear invalid input */
            }
            continue;
        }
                if (player.lives <= 0) {
            printf("\nGAME OVER! No lives remaining.\n");
            break;
        }

        
switch (choice) {
    case 1:
        sortingWasteland(&player);
        break;

    case 2:
        if (player.maxLevelUnlocked >= 2)
            searchingRuins(&player);
        else
            printf("\nLOCKED! Defeat the Sorting Wasteland guardian first.\n");
        break;

    case 3:
        if (player.maxLevelUnlocked >= 3)
            stackQueueCitadel(&player);
        else
            printf("\nLOCKED! Complete the Searching Ruins first.\n");
        break;

    case 4:
        showStatus(&player);
        break;

    case 5:
        if (player.maxLevelUnlocked >= 4)
            linkedListForest(&player);
        else
            printf("\nLOCKED! Complete the Stack & Queue Citadel first.\n");
        break;

    case 6:
        if (player.maxLevelUnlocked >= 5)
            graphAbyss(&player);
        else
            printf("\nLOCKED! Complete the Linked-List Forest first.\n");
        break;

    case 0:
        printf("\nGoodbye, %s. The Core awaits!\n",
               player.name);
        break;

    default:
        printf("Invalid choice. Choose 0 to 6.\n");
}

} while (choice != 0);

return 0;
}