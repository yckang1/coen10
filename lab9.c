//Yicheng Kang
//Lab 8, COEN10L, 11/17/20
//Tuesday 5:15-8pm

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10
#define SIZE 20

char words[MAX][SIZE];
int length[MAX] = {0,0,0,0,0,0,0,0,0,0};
int number = 0;

void input(void);
void reverse(void);
void uppercase(void);
void info(void);
void output(void);

int main(void) {
	input();
	reverse();
	uppercase();
	info();
	return 0;
}

void input(void) {
	int i, j, k, x;
	char temp[SIZE];
	printf("Please enter 10 words below\n");
	for(i = 0; i < 10; i++) {
		x = scanf("%s", words[i]);
		if(words[i][0] != '\0')
			number++;
		if(x < 1)
			break;
	}
	fflush(stdin);
	for(i = 0; i < number; i++) {
		for(j = i + 1; j < number; j++) {
			strcpy(temp, words[j]);
			if(strcasecmp(words[i], words[j]) > 0) {
				for(k = j; k > i; k--) {
					strcpy(words[k], words[k-1]);
				}
				strcpy(words[i], temp);
			}
		}
	}
	printf("These are your words put in alphabetical order!\n");
	output();
	return;
}

void reverse(void) {
	int i = 0;
	int j = number -1;
	char temp[SIZE];
	while(i<j) {
		strcpy(temp, words[i]);
		strcpy(words[i], words[j]);
		strcpy(words[j], temp);
		i++;
		j--;
	}
	printf("These are your words put in reverse order!\n");
	output();
	return;
}

void uppercase(void) {
	int i;
	char *p;
	for(i = 0; i < number; i++) {
		p = words[i];
		while(*p != '\0') {
			if(islower((int)*p)) {
				*p = toupper((int)*p);
			}
			p++;
		}
		length[i] = strlen(words[i]);
	}
	printf("These are your words put in uppercase!\n");
	output();
	return;
}

void info(void) {
	int shortest = 0;
	int longest = 0;
	int average = 0;
	int i = 0;
	int notletter[10] = {0,0,0,0,0,0,0,0,0,0};
	while(i<number) {
		average += length[i];
		if(! isalpha((int) words[i][0]))
			notletter[i] = 1;
		if(length[i] > length[longest])
			longest = i;
		else if(length[i] < length[shortest])
			shortest = i;
		i++;
	}
	average /= number;
	printf("\n");
	printf("The shortest word is %s.\n", words[shortest]);
	printf("The longest word is %s.\n", words[longest]);
	printf("The average length of the words is %d.\n", average);
	printf("These words don't start with a letter: \n");
	for(i = 0; i < 10; i++) {
		if(notletter[i] == 1)
			printf("%s\n", words[i]);
	}
	return;
}

void output(void) {
	int i;
	for(i = 0; i < number; i++) {
		printf("%s\n", words[i]);
	}
	return;
}
