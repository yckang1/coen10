//Yicheng Kang
//COEN10 Lab 7
//Tuesday 5:15-8

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
	int schedule[5] = {0,0,0,0,0};
	int counter=0;
	int time;
	int ans;
	int i;
	char letter;
	char lessons[5][20];
	char name[20];

	while(1) {
		printf("WELCOME TO WINTER IS COMMING INC\n");
		printf("Menu\n 1 = Schedule a lesson\n 2 = Cancel a lesson\n 3 = List schedule\n 4 = Show names starting with a letter\n 9 = Quit\n");
		scanf("%d", &ans);
		switch(ans) {
			case 1:
				if(counter == 5) {
					printf("There are no available spots right now. Please come back tomorrow.\n\n");
				}
				else {
					printf("Can I get a name for the appointment?\n\n");
					scanf("%s", &name);
					strcpy(lessons[counter], name);
					printf("Great! %s has a lesson scheduled at %dPM.\n\n\n\n", name, counter+1);
					counter++;
				}
				break;

			case 2:
				if(counter == 0) {
					printf("There are currently no scheduled lessons.\n\n\n\n");
					break;
				}
				else {
					printf("What name was the lesson for? \n\n");
					scanf("%s", &name);
					for(i = 0; i < 5; i++) {
						if(strcmp(lessons[i], name) == 0) {
							lessons[i][0] = '\0';
							printf("%s has cancelled the lesson at %dPM. \n\n\n\n", name, i + 1);
							counter--;
							break;
						}
					}
					if(i == 5) {
						printf("There isn't a lesson under that name.\n\n");
					}
					else {
						for(;i < counter; i++) {
							strcpy(lessons[i], lessons[i+1]);
							printf("The scheduled lesson under the name %s has been moved from %dPM to %dPM.\n\n", lessons[i], i+2, i+1);
						}
						strcpy(lessons[i], "");
					}
				}
				break;
				

			case 3:
				printf("There are currently %d lesson(s) signed up for today.\n\n", counter);
				for(i = 0; i < counter; i++) {
					printf("%dPM - %s\n", i + 1, lessons[i]);
				}
				for(i = counter; i < 5; i++) {
					printf("%dPM - Free\n", i + 1);
				}
				break;
			
			case 4:
				if(counter == 0) {
					printf("There are currently no scheduled lessons.\n\n\n\n");
				}
				else {
					getchar();
					printf("What does the name start with?\n\n");
					scanf(" %c", &letter);
					for(i = 0; i < counter; i++) {
						if(lessons[i][0] == letter) {
							printf("%s has scheduled a lesson!\n\n", lessons[i]);
						}
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

