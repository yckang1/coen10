//Yicheng Kang
//COEN10 Lab 8
//Tuesday 5:15-8

#include <stdio.h>
#include <string.h>

	int sizes[5] = {0,0,0,0,0};
	int counter=0;
	const int SIZE = 5;
	char lessons[5][20];
	char numbers[5][20];

	void request(void);
	void cancel(void);
	void list(void);
	void letter(void);
	void group(void);

	int main(void)
	{
		int i;
		int ans;
		for(i=0;i<SIZE;i++)
		{
			lessons[i][0] = '\0';
		}
		while(1)
		{
			printf("WELCOME TO WINTER IS COMMING INC\n");
			printf("Menu\n 1 = Schedule a lesson\n 2 = Cancel a lesson\n 3 = List schedule\n 4 = Show names starting with a letter\n 5 = Show names for a specified number of your group\n 9 = Quit\n");
			scanf("%d", &ans);
			switch(ans)
			{
				case 1:
					request();
					break;
				case 2:
					cancel();
					break;
				case 3:
					list();
					break;
				case 4:
					letter();
					break;
				case 5:
					group();
					break;
				case 9:
					return 0;
				default:
					printf("Bad input!\n\n\n\n");
			}
		}
	}


	void request(void)
	{
		int i;
		int groupsize;
		char name[20];
		char usernumber[20];
		if(counter == 5)
		{
			printf("There are no available spots right now. Please come back tomorrow.\n\n");
		}
		else
		{
			i=counter-1;
			printf("Can I get a name for the appointment?\n\n");
			scanf("%s", &name);
			if(counter != 0) {
				i=0;
				while(i<counter)
				{
					if(strcmp(name, lessons[i]) == 0)
					{
						printf("This name is already taken, please choose a different name.\n\n");
						scanf("%s", &name);
						i=0;
					}
					else
					{
						i++;
					}
				}
			}
			strcpy(lessons[counter], name);
			printf("Please enter your phone number.\n\n");
			scanf("%s", &usernumber);
			strcpy(numbers[counter], usernumber);
			do
			{
				printf("Please enter the size of your group, anywhere from 1 to 4.\n\n");
				scanf("%d", &groupsize);
				sizes[counter] = groupsize;
			}
			while (groupsize<1 || groupsize>4);
				printf("%s with a group of %d has signed up for a lesson at %dPM.\n\n\n\n", name, groupsize, counter+1);
				counter++;
				return;
		}
	}


	void cancel(void)
	{
		int i;
		char name[20];
		if(counter == 0)
		{
			printf("There are currently no scheduled lessons.\n\n\n\n");
		}
		else
		{
			printf("What name was the lesson for? (case sensitive) \n\n");
			scanf("%s", &name);
			for(i = 0; i < SIZE; i++)
			{
				if(strcmp(lessons[i], name) == 0)
				{
					printf("To %s: %s has cancelled the lesson at %dPM.\n\n", numbers[i], name, i+1);
					lessons[i][0] = '\0';
					numbers[i][0] = '\0';
					sizes[i] = 0;
					counter--;
					break;
				}
			}
			if(i == SIZE)
			{
				printf("There isn't a lesson under that name.\n\n");
			}
			else
			{
				for(;i < counter; i++)
				{
					strcpy(lessons[i], lessons[i+1]);
					strcpy(numbers[i], numbers[i+1]);
					sizes[i] = sizes[i+1];
					printf("To %s: The scheduled lesson under the name %s has been moved from %dPM to %dPM.\n\n", numbers[i], lessons[i], i+2, i+1);
				}
				lessons[i][0] = '0';
			}
		}
		return;
	}
		

	void list(void)
	{
		int i;
		printf("There are currently %d lesson(s) signed up for today.\n\n", counter);
		for(i = 0; i < counter; i++)
		{
			printf("%dPM - %s, Phone number: %s, Group of %d\n", i + 1, lessons[i], numbers[i], sizes[i]);
		}
		for(i = counter; i < SIZE; i++)
		{
			printf("%dPM - Free\n", i + 1);
		}
		return;
	}

	
	void letter(void)
	{
		int i;
		char letter;
		if(counter == 0)
		{
			printf("There are currently no scheduled lessons.\n\n\n\n");
			return;
		}
		printf("What does the name start with?\n\n");
		scanf(" %c", &letter);
		for(i = 0; i < counter; i++)
		{
			if(lessons[i][0] == letter)
			{
				printf("%s has scheduled a lesson at %dPM!\n\n", lessons[i], i+1);
			}
		}
		return;
	}


	void group(void)
	{
		int i;
		int groupsize;
		if(counter == 0)
		{
			printf("There are currently no scheduled lessons.\n\n\n\n");
			return;
		}
		do {
			printf("What was the size of your group?\n\n");
			scanf("%d", &groupsize);
		} while (groupsize < 1 || groupsize > 4);
		for(i = 0; i < counter; i++)
		{
			if(groupsize == sizes[i])
			{
				printf("%s with a group size of %d has a lesson scheduled at %dPM.\n\n\n\n", lessons[i], groupsize, i+1);	
			}
		}
		return;
	}
