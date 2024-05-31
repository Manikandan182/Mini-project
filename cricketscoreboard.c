#include <stdio.h>

struct Team {
    char name[20];
    int runs;
    int wickets;
    float overs;
};

// Function to initialize team details
void initializeTeam(struct Team *team, char *name) {
    strcpy(team->name, name);
    team->runs = 0;
    team->wickets = 0;
    team->overs = 0.0;
}

// Function to update team score
void updateScore(struct Team *team, int runs, int wickets, float overs) {
    team->runs += runs;
    team->wickets += wickets;
    team->overs = overs;
}

// Function to display team score
void displayScore(struct Team team) {
    printf("%s - %d/%d in %.1f overs\n", team.name, team.runs, team.wickets, team.overs);
}

int main() {
    struct Team team1, team2;
    char team1Name[20], team2Name[20];
    int runs, wickets;
    float overs;

    printf("Enter name of Team 1: ");
    scanf("%s", team1Name);
    printf("Enter name of Team 2: ");
    scanf("%s", team2Name);

    initializeTeam(&team1, team1Name);
    initializeTeam(&team2, team2Name);

    printf("\n--- %s Batting ---\n", team1Name);
    printf("Enter runs scored: ");
    scanf("%d", &runs);
    printf("Enter wickets lost: ");
    scanf("%d", &wickets);
    printf("Enter overs bowled: ");
    scanf("%f", &overs);
    updateScore(&team1, runs, wickets, overs);

    printf("\n--- %s Batting ---\n", team2Name);
    printf("Enter runs scored: ");
    scanf("%d", &runs);
    printf("Enter wickets lost: ");
    scanf("%d", &wickets);
    printf("Enter overs bowled: ");
    scanf("%f", &overs);
    updateScore(&team2, runs, wickets, overs);

    printf("\n--- Match Summary ---\n");
    displayScore(team1);
    displayScore(team2);

    return 0;
}
