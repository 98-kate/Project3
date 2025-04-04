#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

int main(int argc, char *argv[])
{
    int numOfChamps;

    srand(time(NULL));

    if(argc<2)
    {
        printf("Error: Command line argument doesn't exist");
        return -1;
    }
    else
    {
        numOfChamps = atoi(argv[1]);
        if(numOfChamps <= 0)
        {
            printf("Error: Number is less than 0");
            return 1;
        }
    }

    printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN =============\n\n");
    struct Champion *p1 = buildChampionList(numOfChamps);
    struct Champion *p2 = buildChampionList(numOfChamps);

    int length1 = 0, length2 = 0;
    int loop = 1;
    int roundNumber = 0;
    struct Champion *p1len = p1;
    struct Champion *p2len = p2;

    while(p1len != NULL && p2len != NULL)
    {
        length1++;
        length2++;
        p1len = p1len->next;
        p2len = p2len->next;
    }

    while(loop)
    {
        if(p1 == NULL || p2 == NULL)
        {
            loop = 0;
            break;
        }

        printf("\n----- ROUND %d -----\n", ++roundNumber);
        printf("Player 1: ");
        printChampionList(p1);
        printf("Player 2: ");
        printChampionList(p2);
        struct Champion *Role1 = p1;
        struct Champion *Role2 = p2;
        int lvl1 = p1->level;
        int lvl2 = p2->level;

     switch (Role1->role)
     {
        case MAGE:
            switch (Role2->role)
            {
                case MAGE:
                    printf("Player 1 is a MAGE and Player 2 is a MAGE\n");
                    if(lvl1 > lvl2) {
                        printf("Player 1 (MAGE) wins and gains a new champion.\n");
                        printf("Player 2 (MAGE) loses the next champion.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2); 
                        p1 = addChampion(p1, createChampion());
                        p2 = removeChampion(p2);
                        break;
                    } else if(lvl1 < lvl2){
                        printf("Player 1 (MAGE) loses the next champion.\n");
                        printf("Player 2 (MAGE) wins and gains a new champion.\n");
                        p1 = removeChampion(p1);
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        p2 = addChampion(p2, createChampion());
                        break;
                    }
                    else{
                       printf("Nothing happens - no penalty or reward.\n");
                       p1 = removeChampion(p1);
                       p2 = removeChampion(p2);
                       break;
                    }
                    break;
                case FIGHTER:
                    printf("Player 1 is a MAGE and Player 2 is a FIGHTER\n");
                    if (lvl1 > lvl2) {
                        printf("Player 1 (MAGE) wins and gains a new champion.\n");
                        printf("Player 2 (FIGHTER) loses but with no penalty.\n");
                        p1 = removeChampion(p1);
                        p1 = addChampion(p1, createChampion());
                        p2 = removeChampion(p2);
                        break;
                    } else if(lvl1 < lvl2){
                        printf("Player 1 (MAGE) loses the next champion.\n");
                        printf("Player 2 (FIGHTER) wins but with no reward.\n");
                        p1 = removeChampion(p1);
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        break;
                    }else{
                        printf("Nothing happens - no penalty or reward.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        length1--;
                        length2--;
                        break;
                    }
                    break;
                case SUPPORT:
                    printf("Player 1 is a MAGE and Player 2 is a SUPPORT\n");
                    if (lvl1 > lvl2) {
                        printf("Player 1 (MAGE) wins and gains a new champion.\n");
                        printf("Player 2 (SUPPORT) loses two champions.\n");
                        p1 = removeChampion(p1);
                        p1 = addChampion(p1, createChampion());
                        p2 = removeChampion(p2);
                        p2 = removeChampion(p2);
                        p2 = removeChampion(p2);
                        break;
                    } else if(lvl1 < lvl2){
                        printf("Player 1 (MAGE) loses one champion.\n");
                        printf("Player 2 (SUPPORT) wins and gains two new champions.\n");
                        p1 = removeChampion(p1);
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        p2 = addChampion(p2, createChampion());
                        p2 = addChampion(p2, createChampion());
                        break;
                    }else {
                        printf("Nothing happens - no penalty or reward.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        break;
                    }
                    break;
                case TANK:
                    printf("Player 1 is a MAGE and Player 2 is a TANK\n");
                    printf("Player 1 (MAGE) wins and gains a new champion.\n");
                    printf("Player 2 (TANK) loses one champion.\n");
                    p1 = removeChampion(p1);
                    p2 = removeChampion(p2);
                    p1 = addChampion(p1, createChampion());
                    break;
            }
            break;
        case FIGHTER:
            switch (Role2->role) {
                case MAGE:
                    printf("Player 1 is a FIGHTER and Player 2 is a MAGE\n");
                    if (lvl1> lvl2) {
                        printf("Player 1 (FIGHTER) wins but gains no reward.\n");
                        printf("Player 2 (MAGE) loses one champion.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        p2 = removeChampion(p2);
                        break;
                    } else if(lvl1 < lvl2) {
                        printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                        printf("Player 2 (MAGE) wins and gains a champion.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        p2 = addChampion(p2, createChampion());
                        break;
                    }else{
                           printf("Nothing happens - no penalty or reward.\n");
                            p1 = removeChampion(p1);
                            p2 = removeChampion(p2);
                            break;
                    }
                    break;
                case FIGHTER:
                    printf("Player 1 is a FIGHTER and Player 2 is a FIGHTER\n");
                    printf("Both players win one new champion.\n");
                    p1 = removeChampion(p1);
                    p2 = removeChampion(p2);
                    p1 = addChampion(p1, createChampion());
                    p2 = addChampion(p2, createChampion());
                    break;
                case SUPPORT:
                    printf("Player 1 is a FIGHTER and Player 2 is a SUPPORT\n");
                    if (lvl1 > lvl2) {
                        printf("Player 1 (FIGHTER) wins but gains no reward.\n");
                        printf("Player 2 (SUPPORT) loses one champion.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        p2 = removeChampion(p2);
                        break;
                    } else if(lvl1 < lvl2){
                        printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                        printf("Player 2 (SUPPORT) wins and gains a champion.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        p2 = addChampion(p2, createChampion());
                        break;
                    }else{
                        printf("Nothing happens - no penalty or reward.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        break;
                    }
                    break;
                case TANK:
                    printf("Player 1 is a FIGHTER and Player 2 is a TANK\n");
                    printf("Player 1 (FIGHTER) wins and gains a new champion.\n");
                    printf("Player 2 (TANK) loses but with no penalty.\n");
                    p1 = removeChampion(p1);
                    p2 = removeChampion(p2);
                    p1 = addChampion(p1, createChampion());
                    break;
            }
            break;
        case SUPPORT:
            switch (Role2->role) {
                case MAGE:
                    printf("Player 1 is a SUPPORT and Player 2 is a MAGE\n");
                    if (lvl1> lvl2) {
                        printf("Player 1 (SUPPORT) wins and gains two new champions.\n");
                        printf("Player 2 (MAGE) loses one champion.\n");
                        p1 = removeChampion(p1);
                        p1 = addChampion(p1, createChampion());
                        p1 = addChampion(p1, createChampion());
                        p2 = removeChampion(p2);
                        p2 = removeChampion(p2);
                        break;
                    } else if(lvl1 < lvl2){
                        printf("Player 1 (SUPPORT) loses two champions.\n");
                        printf("Player 2 (MAGE) wins and gains a new champion.\n");
                        p1 = removeChampion(p1);
                        p1 = removeChampion(p1);
                        p1 = removeChampion(p1);
                        length1 = length1 - 3;
                        p2 = removeChampion(p2);
                        p2 = addChampion(p2, createChampion());
                        break;
                    }else{
                        printf("Nothing happens - no penalty or reward.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        break;
                    }
                    break;
                case FIGHTER:
                    printf("Player 1 is a SUPPORT and Player 2 is a FIGHTER\n");
                    if (lvl1 > lvl2)
                    {
                        printf("Player 1 (SUPPORT) wins and gains a new champion.\n");
                        printf("Player 2 (FIGHTER) loses but with no penalty.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        p1 = addChampion(p1, createChampion());
                        break;
                    }
                    else if(lvl1 < lvl2)
                    {
                        printf("Player 1 (SUPPORT) loses one champion.\n");
                        printf("Player 2 (FIGHTER) wins but gains no reward.\n");
                        p1 = removeChampion(p1);
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        break;
                    }
                    else
                    {
                        printf("Nothing happens - no penalty or reward.\n");
                        p1 = removeChampion(p1);
                        p2 = removeChampion(p2);
                        break;
                    } break;
                case SUPPORT:
                    printf("Player 1 is a SUPPORT and Player 2 is a SUPPORT\n");
                    printf("Both players lose the next champion.\n");
                    p1 = removeChampion(p1);
                    p1 = removeChampion(p1);
                    p2 = removeChampion(p2);
                    p2 = removeChampion(p2);
                    break;
                case TANK:
                    printf("Player 1 is a SUPPORT and Player 2 is a TANK\n");
                    printf("Player 1 (SUPPORT) loses but with no penalty.\n");
                    printf("Player 2 (TANK) wins and gains a new champion.\n");
                    p1 = removeChampion(p1);
                    p2 = removeChampion(p2);
                    p2 = addChampion(p2, createChampion());
                    break;
            }    break;
        case TANK:
            switch (Role2->role)
            {
                case MAGE:
                    printf("Player 1 is a TANK and Player 2 is a MAGE\n");
                    printf("Player 1 (TANK) loses one champion.\n");
                    printf("Player 2 (MAGE) wins and gains a new champion.\n");
                    p1 = removeChampion(p1);
                    p2 = removeChampion(p2);
                    p2 = addChampion(p2, createChampion());
                    break;
                case FIGHTER:
                    printf("Player 1 is a TANK and Player 2 is a FIGHTER\n");
                    printf("Player 1 (TANK) loses but with no penalty.\n");
                    printf("Player 2 (FIGHTER) wins and gains a new champion.\n");
                    p1 = removeChampion(p1);
                    p2 = removeChampion(p2);
                    p2 = addChampion(p2, createChampion());
                    break;
                case SUPPORT:
                    printf("Player 1 is a TANK and Player 2 is a SUPPORT\n");
                    printf("Player 1 (TANK) wins and gains a new champion.\n");
                    printf("Player 2 (SUPPORT) loses but with no penalty.\n");
                    p1 = removeChampion(p1);
                    p2 = removeChampion(p2);
                    p1 = addChampion(p1, createChampion());
                    break;
                case TANK:
                    printf("Player 1 is a TANK and Player 2 is a TANK\n");
                    printf("Nothing happens - no penalty or reward.\n");
                    p1 = removeChampion(p1);
                    p2 = removeChampion(p2);
                    break;
            }
            break;
     }

    }
    printf("\n=========== GAME OVER ===========\n");
    
    printf("Player 1 ending champion list: ");
    printChampionList(p1);
    printf("Player 2 ending champion list: ");
    printChampionList(p2);
    
    if (p1 == NULL && p2 == NULL)
    {
        printf("\nTIE -- Both players ran out of champions.\n");
    }
    else if(p1 == NULL)
    {
        printf("\nPlayer 1 ran out of champions. Player 2 wins.\n");
    }
    else
    {
        printf("\nPlayer 2 ran out of champions. Player 1 wins.\n");
    }
    destroyChampionList(p1);
    destroyChampionList(p2);

    return 0;
}