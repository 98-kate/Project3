#include <stdio.h>
#include <stdlib.h>
#include "champion.h"
#include <time.h>
#include <assert.h>

struct Champion* createChampion()
{
     struct Champion *newChamp = (Champion*)malloc(sizeof(Champion));
     if(newChamp == NULL) return 0;
     int choice = (rand()%4);

     switch(choice)
     {
         case 0:
             newChamp->role = MAGE;
             newChamp->level = rand()%(8)+1;
             break;
         case 1:
             newChamp->role = FIGHTER;
             newChamp->level = rand()%(5)+2;
             break;
         case 2:
             newChamp->role = SUPPORT;
             newChamp->level = rand()%(4)+3;
             break;
         case 3:
             newChamp->role = TANK;
             newChamp->level = rand()%(4)+6;
             break;
     }
     if(newChamp != NULL) newChamp->next = NULL;
     return newChamp;
}

struct Champion* addChampion(Champion *head, Champion *c)
{
    Champion *headtemp = head;
    if(head == NULL)
    {
       head = c;
       return head;
    }

    if (c->level >= head->level)
    {
        c->next = head;
        head = c;
        return head;
    }
    else
    {
        while (headtemp->next != NULL && c->level < headtemp->next->level)
        {
            headtemp = headtemp->next;
        }
        c->next = headtemp->next;
        headtemp->next = c;
    }
    return head;
}

struct Champion* buildChampionList(int n)
{
    int i;
    struct Champion *newhead = NULL;

    for(i = 0; i < n; i++)
    {
        struct Champion *newc = createChampion();
        newhead = addChampion(newhead,newc);
    }
    return newhead;
}

void printChampionList(Champion *head)
{
    struct Champion *current = head;

    while (current != NULL)
    {
          printf("%c%d ",((current->role == MAGE ? 'M' : current->role == FIGHTER ? 'F' : current->role == SUPPORT ? 'S': 'T')),current->level);
          current = current->next;
    }
    printf("\n");
}

struct Champion* removeChampion(Champion *head)
{
    if(head != NULL)
    {
        Champion *toDelete = head;
        head = head->next;
        free(toDelete);
    }
    return head;
}

struct Champion* destroyChampionList(Champion *head)
{
    Champion* destroylist = head;
    while(head != NULL)
    {
        destroylist = destroylist->next;
        free(head);
        head = destroylist;
    }
    return NULL;
}