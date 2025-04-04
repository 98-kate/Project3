#ifndef CHAMPION_H
#define CHAMPION_H
#include <stdio.h>
#include <stdlib.h>

typedef enum{
    MAGE,
    FIGHTER,
    SUPPORT,
    TANK
}ChampionRole;

typedef struct Champion
{
    int level;
    ChampionRole role;
    struct Champion* next;
}Champion;

struct Champion* createChampion();
struct Champion* addChampion(Champion *head, Champion*c);
struct Champion* removeChampion(Champion *head);
struct Champion* buildChampionList(int n);
struct Champion* destroyChampionList(Champion *head);
void printChampionList(Champion *head);
#endif
