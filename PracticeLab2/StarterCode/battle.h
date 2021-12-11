//
// Created by matt on 12/11/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef CS1050_FINAL_EXAM_PREP_FS21_BATTLE_H
#define CS1050_FINAL_EXAM_PREP_FS21_BATTLE_H

typedef enum{
    MOST_EXPERIENCE,
    LEAST_EXPERIENCE,
    LEAVES_FIRST,
    LEAVES_LAST
}PlayOrder;

//Optional Struct
typedef struct data{
    char monster[256];
    char attack[256];
}Data;

typedef struct player{
    char name[256];
    int gamesPlayed;
    char time[8];
    char monster[256];
    char attack[256];
}Player;


Player *readPlayersIntoArray(const char *playerFilename, const char *monsterFilename, int *numPlayers);

char *whoHasMostExperience(Player *players, int numPlayers);
char *whoHasLeastExperience(Player *players, int numPlayers);
char *whoLeavesFirst(Player *players, int numPlayers);
char *whoLeavesLast(Player *players, int numPlayers);

char *whoPlaysFirst(Player *players, int numPlayers, PlayOrder playOrder);
char *battle(Player *players, int numPlayers, char *player1Name, char *player2Name);

void freePlayers(Player *players);

#endif //CS1050_FINAL_EXAM_PREP_FS21_BATTLE_H
