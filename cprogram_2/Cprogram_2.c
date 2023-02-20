/*
Taylor Slade
KU ID: 3079517
purpose: lab 3 part two
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ScoringPlays(int Num){
    int TD_2, TDFG, TD, safety, FG;
    for (TD_2=0; TD_2 <= Num/8; TD_2++){
        for (TDFG = 0; TDFG<=Num/7; TDFG++){
            for (TD = 0; TD <= Num/6; TD++){
                for (FG = 0; FG <= Num/3; FG++){
                    for (safety = 0; safety <= Num/2; safety++){
                        if (TD_2*8 + TDFG*7 + TD*6 + safety*2 + FG*3 == Num){
                            printf("%d TD + 2 pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", TD_2, TDFG, TD, FG, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int final_score;
    while(1){
    printf("\nEnter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &final_score);
    if (final_score < 2){
        break;
    }
    ScoringPlays(final_score);
    }
}