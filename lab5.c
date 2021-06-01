/* Yicheng Kang, Lab 5, Tuesday 5:15-8pm */
#include <stdio.h>
int main(void) {
	srand((int) time(NULL));
	int score = 0;
	int answer = 0;
	int input = 0;
	int n1 = 0;
	int n2 = 0;
	int a;

	for(a = 0; a < 10; a++) {
		n1 = rand() % 13;
		n2 = rand() % 13;
		answer = n1 * n2;

		printf("What is %d x %d?\n", n1, n2);
		scanf("%d", &input);

		if(answer == input) {
			score++;
			printf("Your answer was correct! \n");
		}
		else {
			printf("Not this time, the correct answer was %d.\n", answer);
		}
	}
	int result = (score*100)/10;
	printf("Your final score is %d% \n", result);
}
