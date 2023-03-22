#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int* plus_one(int* digits, int digitsSize, int returnSize) {
	int* arr = calloc(returnSize, sizeof(int));
	
	int sum = 0;
	int over = 1;
	
	for(int i = digitsSize -1; i >= 0; i--) {
		sum = over + digits[i];
		over = sum / 10;
		sum = sum % 10;
		arr[i] = sum;
	}
	
	if(over == 1) arr[0] = 1;
	return arr;
}

void test_equals_i_arr(int* arr, int result[], int length){
	int j = 0;
	int index = 0;
	for(int i = 0; i  < length; i++){
		if(arr[i] > result[i]) {
			j = 1;
			break;
		} else if (arr[i] < result[i]){
			j = 2;
			break;
		}
		index++;
	}
	
	
	if(j == 0){
		printf("Test pass.\n");
	} else if(j == 1) {
		printf("Your answer does not match, the value is too large at index: [%d].\n", index);
	} else if(j == 2) {
		printf("Your answer does not match, the value is too small at index: [%d].\n", index);
	}
}


void main(){
	int digits[] = {1, 2, 3};
	int digitsSize = 3;
	int result[] = {1, 2, 4};
	int length = 3;
	
	int* answer = plus_one(digits, digitsSize, length);
	test_equals_i_arr(answer, result, 3);
	free(answer);
	
	int digits_one[] = {1, 2, 9};
	digitsSize = 3;
	int result_one[] = {1, 3, 0};
	length = 3;
	
	answer = plus_one(digits_one, digitsSize, length);
	test_equals_i_arr(answer, result_one, 3);
	free(answer);
	
	int digits_two[] = {9, 9, 9};
	digitsSize = 3;
	int result_two[] = {1, 0, 0, 0};
	length = 4;
	
	answer = plus_one(digits_two, digitsSize, length);
	test_equals_i_arr(answer, result_two, 3);
	free(answer);
}
