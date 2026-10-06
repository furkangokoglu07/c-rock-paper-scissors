#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hamleleri ASCII sembolü olarak ekrana basan yardımcı fonksiyon
void printChoice(int choice) {
    if (choice == 1) {
        printf("    _______\n");
        printf("---'   ____)\n");
        printf("      (_____)\n");
        printf("      (_____)\n");
        printf("      (____)\n");
        printf("---.__(___)\n");
        printf("      [ROCK]\n");
    } else if (choice == 2) {
        printf("    _______\n");
        printf("---'   ____)____\n");
        printf("          ______)\n");
        printf("          _______)\n");
        printf("         _______)\n");
        printf("---.__________)\n");
        printf("      [PAPER]\n");
    } else if (choice == 3) {
        printf("    _______\n");
        printf("---'   ____)____\n");
        printf("          ______)\n");
        printf("       __________)\n");
        printf("      (____)\n");
        printf("---.__(___)\n");
        printf("     [SCISSORS]\n");
    }
}

int main(void) {
    int userChoice;
    int computerChoice;
    int userScore = 0;
    int computerScore = 0;
    const int targetScore = 3; // Ilk 3 yapan kazanir

    srand(time(NULL));

    printf("==========================================\n");
    printf("   ROCK - PAPER - SCISSORS TOURNAMENT    \n");
    printf("        First to 3 points wins!          \n");
    printf("==========================================\n");
    printf("1: Rock | 2: Paper | 3: Scissors | 0: Exit\n\n");

    while (1) {
        printf("Enter your choice (1, 2, 3 or 0): ");
        scanf("%d", &userChoice);

        // Kullanici cikmak isterse
        if (userChoice == 0) {
            printf("\nYou quit the tournament.\n");
            break;
        }

        // Hatali giris kontrolu
        if (userChoice < 1 || userChoice > 3) {
            printf("Invalid choice! Please enter 1, 2, or 3.\n\n");
            continue;
        }

        // Bilgisayarin rastgele secimi (1-3)
        computerChoice = (rand() % 3) + 1;

        printf("\n--- YOU CHOSE --- \n");
        printChoice(userChoice);

        printf("\n--- COMPUTER CHOSE ---\n");
        printChoice(computerChoice);
        printf("\n");

        // Tur kazananini belirleme
        if (userChoice == computerChoice) {
            printf(">> It's a tie this round!\n");
        } else if ((userChoice == 1 && computerChoice == 3) || 
                   (userChoice == 2 && computerChoice == 1) || 
                   (userChoice == 3 && computerChoice == 2)) {
            printf(">> You won this round!\n");
            userScore++;
        } else {
            printf(">> Computer won this round!\n");
            computerScore++;
        }

        printf("------------------------------------------\n");
        printf("CURRENT SCORE -> You: %d | Computer: %d\n", userScore, computerScore);
        printf("------------------------------------------\n\n");

        // Sampiyonluk kontrolu (Ilk 3 puana ulasan)
        if (userScore == targetScore) {
            printf("******************************************\n");
            printf("  CONGRATULATIONS! YOU WON THE MATCH!    \n");
            printf("******************************************\n");
            break;
        } else if (computerScore == targetScore) {
            printf("******************************************\n");
            printf("   GAME OVER! COMPUTER WON THE MATCH!     \n");
            printf("******************************************\n");
            break;
        }
    }

    return 0;
