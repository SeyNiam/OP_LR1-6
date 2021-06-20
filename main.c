#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#endif

#define N 3
#define K 3

#include <stdio.h>

int main() {
	int endFlag = 1; //a flag that stops the application
	int Arr[N][K] = { 0 }; //array of integer numbers
	int minNumI = 0; //number of the string with the minimum element
	int equal = 0; //flag of equality of the array

	//a global cycle that prevents the program from endting without the user's desire
	do {
		//a cycle for reading characters from a stream associated with the keyboard
		printf("Please type down your array:\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < K; j++) {
				scanf("%d", &Arr[i][j]);
			}
		}

		int min = Arr[0][0]; //first element is chosen as minimum

		//checking if all elements are equal
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < K; j++) {
				if (Arr[i][j] == min) {
					equal = 1; //sets equality flag to 1 if every element so far was equal to each other
				}
				else {
					equal = 0; //sets equality flag to 0 and exits from the loop
					break;
				}
			}
			if (equal == 0) { //exits from the loop if equality flag if 0
				break;
			}
		}

		//if not all the elements in the array are equal
		if (equal == 0) {
			//finding the minimum element ant its position
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < K; j++) {
					if (Arr[i][j] < min) {
						minNumI = i;
						min = Arr[i][j];
					}
				}
			}

			//setting every line after the minimum element to zero
			for (int i = minNumI + 1; i < N; i++) {
				for (int j = 0; j < K; j++) {
					Arr[i][j] = 0;
				}
			}

			//output of the result
			printf("Your new array is:\n");
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < K; j++) {
					printf("%d ", Arr[i][j]);
				}
				printf("\n");
			}
		}
		else { //if all the elements in the array are equal
			printf("\nAll the elements in the array are equal.\n");
		}		

		//resetting the variables
		endFlag = 1;
		memset(&Arr[0][0], 0, sizeof(Arr)); //filling the array with the specified characters
		minNumI = 0;

		//suggesting to user to run program again or exit.
		printf("\nPlease choose from the following:\n\t1 - Count again.\n\t2 - Exit.\n");
		scanf("%d", &endFlag);
		switch (endFlag) {
		case 1: endFlag = 1; break;
		case 2: endFlag = 0; break;
		default: printf("Incorrect answer. The program will be closed."); endFlag = 0; break;
		}
	} while (endFlag); //if flag is 0, then exiting out of cycle 
	return 0;
}
