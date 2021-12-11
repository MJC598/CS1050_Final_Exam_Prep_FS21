//
// Created by matt on 12/11/21.
//

#include "battle.h"

#define MONSTER_FILENAME "../../monsters1.txt"
#define PLAYER_FILENAME "../../players.txt"

int main(void){
    int numPlayers;
    Player *players = readPlayersIntoArray(PLAYER_FILENAME, MONSTER_FILENAME, &numPlayers);
    char *playerName = whoLeavesFirst(players, numPlayers);

    (strcmp("Chris", playerName) == 0) ?
        puts("Test 1 Passed: Who Leaves First") :
        puts("Test 1 Failed: Who Leaves First");

    char *player1Name = whoPlaysFirst(players, numPlayers, MOST_EXPERIENCE);
    (strcmp("JimR", player1Name) == 0) ?
        puts("Test 2 Passed: Who Plays First Experience") :
        puts("Test 2 Failed: Who Plays First Experience");


    char *testPlayer = whoPlaysFirst(players, numPlayers, LEAVES_LAST);
    (strcmp("Alicia", testPlayer) == 0) ?
        puts("Test 3 Passed: Who Leaves Last") :
        puts("Test 3 Failed: Who Leaves Last");

    char *player2Name = players[8].name;
    (strcmp("Dan", player2Name) == 0) ?
        puts("Test 4 Passed: Who Plays Next") :
        puts("Test 4 Failed: Who Plays Next");

    char *battleWinner = battle(players, numPlayers, "JimR", "Dan");
    (strcmp("JimR", battleWinner) == 0) ?
        puts("Test 5 Passed: Who Wins") :
        puts("Test 5 Failed: Who Wins");


    freePlayers(players);

    return 0;
}

