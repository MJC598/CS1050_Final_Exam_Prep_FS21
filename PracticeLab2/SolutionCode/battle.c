//
// Created by matt on 12/11/21.
//

#include "battle.h"

Player *readPlayersIntoArray(const char *playerFilename, const char *monsterFilename, int *numPlayers){
    FILE *fm = fopen(monsterFilename, "r");
    if(fm == NULL) return NULL;

    // Monster data part copied from practice lab 1. Shoulda put in a helper function but ehh
    int numMonsters;
    Data *dataArray;
    if(fscanf(fm, "%d", &numMonsters) != 0){
        dataArray = (Data *)malloc(sizeof(Data) * (numMonsters));

    }
    else{
        fclose(fm);
        return NULL;
    }
    int i;
    for(i=0; i<numMonsters; i++){
        fscanf(fm, "%s %s", dataArray[i].monster, dataArray[i].attack);
    }
    fclose(fm);
    // End copied monster part


    FILE *fp = fopen(playerFilename, "r");
    if(fp == NULL) return NULL;
    Player *players;
    if(fscanf(fp, "%d", numPlayers) != 0){
        //I really oughta error check malloc but I'm lazy. This does not fly in 2050 lol
        players = (Player *)malloc(sizeof(Player) * (*numPlayers));
    }
    else{
        fclose(fp);
        free(dataArray);
        return NULL;
    }
    int index;
    for(i=0; i<*numPlayers; i++){
        fscanf(fp, "%s %d %s %d", players[i].name, &players[i].gamesPlayed, players[i].time, &index);
        strcpy(players[i].monster, dataArray[index].monster);
        strcpy(players[i].attack, dataArray[index].attack);
    }
    fclose(fp);
    free(dataArray);
    return players;
}

char *whoHasMostExperience(Player *players, int numPlayers){
    int i;
    if(players == NULL){
        return NULL;
    }

    int j = 0;
    for(i = 1; i < numPlayers; i++){
        if(players[i].gamesPlayed > players[j].gamesPlayed){
            j = i;
        }
    }
    return players[j].name;
}

char *whoHasLeastExperience(Player *players, int numPlayers){
    int i;
    if(players == NULL){
        return NULL;
    }

    int j = 0;
    for(i = 1; i < numPlayers; i++){
        if(players[i].gamesPlayed < players[j].gamesPlayed){
            j = i;
        }
    }
    return players[j].name;
}

char *whoLeavesFirst(Player *players, int numPlayers){
    int i;
    if(players == NULL){
        return NULL;
    }
    int j = 0;
    for(i = 1; i < numPlayers; i++){
        if(strcmp(players[i].time, players[j].time) < 0){
            j = i;
        }
    }
    return players[j].name;
}

char *whoLeavesLast(Player *players, int numPlayers){
    int i;
    if(players == NULL){
        return NULL;
    }
    int j = 0;
    for(i = 1; i < numPlayers; i++){
        if(strcmp(players[i].time, players[j].time) > 0){
            j = i;
        }
    }
    return players[j].name;
}

char *whoPlaysFirst(Player *players, int numPlayers, PlayOrder playOrder){
    switch(playOrder) {
        case 0:
            return whoHasMostExperience(players, numPlayers);
        case 1:
            return whoHasLeastExperience(players, numPlayers);
        case 2:
            return whoLeavesFirst(players, numPlayers);
        case 3:
            return whoLeavesLast(players, numPlayers);
        default:
            return NULL;
    }
}

char *battle(Player *players, int numPlayers, char *player1Name, char *player2Name){
    int p1 = 0;
    int p2 = 0;

    int i;
    for(i = 0; i < numPlayers; i++){
        if(strcmp(player1Name, players[i].name) == 0){
            p1 = i;
        }
        else if(strcmp(player2Name, players[i].name) == 0) {
            p2 = i;
        }
    }
    if(strcmp(players[p1].attack, players[p2].attack) < 0){
        return players[p2].name;
    }
    return players[p1].name;

}

void freePlayers(Player *players){
    free(players);
    players = NULL;
}
