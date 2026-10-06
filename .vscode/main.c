#include <stdio.h>

int main()
{
    int scores[5];
    int sum = 0;
    float average;

    printf("Enter 5 exam scores:\n");

    // Input loop: taking values from user
    for (int i = 0; i < 5; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &scores[i]);
        sum += scores[i]; // sum = sum + scores[i]
    }

    // Type casting to float for accurate decimal division
    average = (float)sum / 5;

    printf("\n--- Results ---\n");
    printf("Total score: %d\n", sum);
    printf("Average score: %.2f\n", average);

    return 0 ;
}