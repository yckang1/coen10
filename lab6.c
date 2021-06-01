//Yicheng Kang, COEN10 Lab 6, Tuesday 5:15-8

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int schedule[5] = {0,0,0,0,0};
	int counter=0;
	int time;
	int ans;
	int i;

	while(1) {
		printf("WELCOME TO WINTER IS COMMING INC\n");
		printf("Menu\n 1 = Schedule a lesson\n 2 = Cancel a lesson\n 3 = List schedule\n 9 = Quit\n");
		scanf("%d", &ans);
		switch(ans) {
			case 1:
				if(counter == 5) {
					printf("There are no available spots right now. Please come back tomorrow.\n\n");
				}

				for(i=0; i<5; i++) {
					if(schedule[i] == 0) {
						schedule[i]++;
						counter++;
						printf("Your scheduled lesson is at %dPM.\n", i + 1);
						printf("Total number of lessons: %d.\n\n\n\n", counter);
						break;
					}
				}
				break;

			case 2:
				if(counter == 0) {
					printf("There are currently no scheduled lessons.\n\n\n\n");
					break;
				}
				printf("What time is your lesson?\n");
				scanf("%d", &time);
				if(schedule[time-1] == 1) {
					schedule[time-1] = 0;
					counter--;
					printf("Great! Your lesson at %d has been cancelled.\n\n\n\n", time);
					break;
				}
				else {
					printf("There aren't any lessons scheduled at this time\n\n\n\n");
				}
				break;
				

			case 3:
				if(schedule[0]==0 && schedule[1]==0 && schedule[2]==0 && schedule[3]==0 && schedule[4]==0)
					printf("All times are available today!\n\n\n\n");
				else {
					for(i=0; i<5; i++) {
						if(schedule[i] == 0) {
							printf("%dPM - Free\n", i + 1);
						}
						else
							printf("%dPM - Lesson\n", i + 1);
					}
				}
				break;
			
			case 9:
				return 0;

			default:
				printf("Bad Option\n\n\n\n");
		}
	}
}	

