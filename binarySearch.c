#include<stdio.h>
#define TRUE 1
#define FALSE 0

int binary(int array[], int low, int high, int input){

	if(high>=low){
		int middle = low + (high-low)/2;
		
		if(input == array[middle])
			return middle;
	
		else if(input>array[middle])
			return binary(array,middle-1,high,input);
			
		else
			return binary(array,low,middle+1,input);

	}

	return 0;
}

int main(){
	int input;
	int order[] = {1,2,3,4,5,6,7,8,9,10,22,44,55,62,78,97};
	puts("Enter the number you are search for: ");
	scanf("%d",&input);
	int high = sizeof(order)/sizeof(order[0]);
	int result = binary(order,0,high-1,input);
	
	(result == -1)? printf("Element is not present in array") 
                 : printf("Element is present at index %d\n", result); 
	return 1;
}