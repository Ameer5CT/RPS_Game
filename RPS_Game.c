#include <stdio.h>

#define MAX_PLAYERS 10
#define MAX_PLAYER_NAME 11
#define SCORES_COLUMNS 2

int main() {
	int choice;
	char players[MAX_PLAYERS][MAX_PLAYER_NAME] = {0};
	int scores[MAX_PLAYERS][SCORES_COLUMNS] = {0};
	int players_number = 0;
	int i, player1, player2, player1_choice, player2_choice, loop;
	int win, lose, total;
	float win_percentage;
	
	printf("\n ==============================");
    printf("\n ||                          ||");
    printf("\n ||    Rock Paper Scissor    ||");
    printf("\n ||                          ||");
    printf("\n ==============================");
    printf("\n");
	
	do {
		printf("\n\n ****** MAIN MENU ******");
        printf("\n [1] Enter players names");
        printf("\n [2] New game");
        printf("\n [3] Show scores & Statistics");
        printf("\n [4] Exit");
        
        printf("\n\n Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
        	case 1:
        		printf("\n How many players are there (Max 10): ");
        		scanf("%d", &players_number);
        		
        		if(players_number < 2 || players_number > 10) {
        			printf("\n !!! The number of players should be between 2 and 10 !!!");
        			continue;
				}
        		
        		for(i = 0; i < players_number; i++) {
        			printf(" Player no.%d name: ", i + 1);
        			scanf("%10s", players[i]);
				}
        		break;
        	case 2:
        		if(players_number == 0) {
        			printf("\n !!! You didn't add any players yet !!!");
        			continue;
				}
        		
        		printf("\n Who gonna play?");
        		for(i = 0; i < players_number; i++) {
        			printf("\n [%d] %s", i + 1, players[i]);
				}
				printf("\n Enter your choice: ");
				scanf("%d", &player1);
				player1--;
				
				printf("\n Against who?");
        		for(i = 0; i < players_number; i++) {
        			if (i == player1) {
        				printf("\n [%d] *****", i + 1);
        				continue;
					}
        			printf("\n [%d] %s", i + 1, players[i]);
				}
				printf("\n Enter your choice: ");
				scanf("%d", &player2);
				player2--;
				
				if (player1 == player2) {
					printf("\n !!! You can't play against yourself !!!");
					break;
				}
				
				loop = 1;
				do {
					printf("\n ****** %s choose one ******", players[player1]);
					printf("\n [1] Rock");
	        		printf("\n [2] Paper");
	        		printf("\n [3] Scissor");
	        		
	        		printf("\n Enter your choice: ");
					scanf("%d", &player1_choice);
					
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					
					printf("\n ****** %s choose one ******", players[player2]);
					printf("\n [1] Rock");
	        		printf("\n [2] Paper");
	        		printf("\n [3] Scissor");
	        		
	        		printf("\n Enter your choice: ");
					scanf("%d", &player2_choice);
					
					if (player1_choice == player2_choice) {
						printf("\n !!! You both choose the same thing, Try again !!!");
						continue;
					}
					
					if (player1_choice == 1 && player2_choice == 3) {
						printf("\n\t\t\t\t !!! %s Win !!!", players[player1]);
						scores[player1][0]++;
						scores[player1][1]++;
						scores[player2][1]++;
					} else if (player1_choice == 2 && player2_choice == 1) {
						printf("\n\t\t\t\t !!! %s Win !!!", players[player1]);
						scores[player1][0]++;
						scores[player1][1]++;
						scores[player2][1]++;
					} else if (player1_choice == 3 && player2_choice == 2) {
						printf("\n\t\t\t\t !!! %s Win !!!", players[player1]);
						scores[player1][0]++;
						scores[player1][1]++;
						scores[player2][1]++;
					} else {
						printf("\n\t\t\t\t !!! %s Win !!!", players[player2]);
						scores[player2][0]++;
						scores[player2][1]++;
						scores[player1][1]++;
					}
					
					loop = 0;
				} while(loop);
        		break;
        	case 3:
        		if(players_number == 0) {
        			printf("\n !!! You didn't add any players yet !!!");
        			continue;
				}
        		
        		printf("\n Player     \tWin \tLose \tTotal \tWin_percentage");
        		
        		for (i = 0; i < players_number; i++) {
        			win = scores[i][0];
        			lose = scores[i][1] - scores[i][0];
        			total = scores[i][1];
        			if(scores[i][1] != 0){
        				win_percentage = (float) win/total * 100;
					} else {
						win_percentage = 0;
					}
					
        			printf("\n %10s \t%d \t%d \t%d \t%f", players[i], win, lose, total, win_percentage);
				}
        		break;
        	case 4:
        		break;
        	default:
        		printf("\n !!! Invalid input !!!");
		}
	} while(choice != 4);
	
	return 0;
}
