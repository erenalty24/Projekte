#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rd() {
    int rem;
A:
    rem = rand() % 7;
    if (rem == 0) {
        goto A;
    } else {
        return rem;
    }
}

void displaychart(int curp, const char player[4]) {
    int i, j, t, c, sft = 0, diceres;

    if (curp == 100) {
        printf("*****Congratulations*****\n\n\nPlayer %s wins\n", player);
        scanf("%*s");
        exit(0);
    }

    for (i = 10; i > 0; i--) {
        t = i - 1;
        if ((sft % 2) == 0) {
            c = 0;
            for (j = 10; j >= 1; j--) {
                diceres = (i * j) + (t * c++);

                if (curp == diceres)
                    printf("%s\t", player);
                else
                    printf("%d\t", diceres);
            }
            sft++;
        } else {
            c = 9;
            for (j = 1; j <= 10; j++) {
                diceres = (i * j) + (t * c--);

                if (curp == diceres)
                    printf("%s\t", player);
                else
                    printf("%d\t", diceres);
            }
            sft++;
        }
        printf("\n\n");
    }
    printf("--------------------------------------------------------------------------------\n");
}

int main() {
    int currentPlayer = 1; // Assuming there are two players
    char players[2][4] = {"P1", "P2"}; // Adjust the size as needed

    // Example usage:
    displaychart(42, players[currentPlayer - 1]); // Display the chart for player 1 with current position 42

    return 0;
}
