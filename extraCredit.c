/*Wei Dong CS3335 Fall 2018 */

#include<stdio.h>
#define TRUE 1

//return how many number are in the input
int getindex(int x)
{
	if(x==0)
	{
		return 1;
	}
	else{
		int index=0;
		while(x>0){
			x=x/10;
			index++;
		}
	return index;
	}

}

//print the seven segments
void printDigit(int numbers[][7],int size)
{
		//divid 7 segment into 3 for loop
		//each loop display the on segment
		
		//this loop print the top layer
		for(int i=0; i<size; i++){
			//int x = numbers[i][0];
			if(TRUE == numbers[i][0])
				printf(" __");
			else
				printf("   ");
				
			printf("\t");
		}
		printf("\n");
	
		//this loop print the middle layer
		for(int i=0; i<size; i++){
			
			//for f
			if(TRUE == numbers[i][5]) printf("|");
			else printf(" ");
			
			//for g
			if(TRUE == numbers[i][6]) printf("__");
			else printf("  ");
			
			//for b
			if(TRUE == numbers[i][1])printf("|");
			else printf(" ");
			
			//space between each numbers
			printf("\t");
		}
		printf("\n");

		//this loop print the bottom layer
		for(int i=0; i<size; i++){
			
			//for f
			if(TRUE == numbers[i][4]) printf("|");
			else printf(" ");
			
			//for g
			if(TRUE == numbers[i][3]) printf("__");
			else printf("  ");
			
			//for b
			if(TRUE == numbers[i][2])printf("|");
			else printf(" ");
			
			//space between each numbers
			printf("\t");
		}
		printf("\n");
}
 int main()
{
	int x=0;
	// 1 represent on and 0 represent off
	// convert all the segment into sequences
	int segments [10][7]= {
	 // a  b  c  d  e  f  g
	  { 1, 1, 1, 1, 1, 1, 0},  // 0
	  { 0, 1, 1, 0, 0, 0, 0},  // 1
	  { 1, 1, 0, 1, 1, 0, 1},  // 2
	  { 1, 1, 1, 1, 0, 0, 1},  // 3
	  { 0, 1, 1, 0, 0, 1, 1},  // 4
	  { 1, 0, 1, 1, 0, 1, 1},  // 5
	  { 1, 0, 1, 1, 1, 1, 1},  // 6
	  { 1, 1, 1, 0, 0, 0, 0},  // 7
	  { 1, 1, 1, 1, 1, 1, 1},  // 8
	  { 1, 1, 1, 1, 0, 1, 1},  // 9
	};
	puts("Enter a number: ");
	scanf("%d",&x);

	int size = getindex(x);
	int numbers[size][7];
	int h=size;
	int remainder=0;
	
	//case where x is 0
	if(x ==0)
		for(int i =0; i <=6; i++){ numbers[0][i]=segments[0][i];}
	
	//case where x is not 0
	else{
		while(x>0){
			
			remainder = x%10;
			x/=10;
			h--;
			
			for(int i =0; i <=6; i++){ numbers[h][i]=segments[remainder][i];}
		}
	}
	printDigit(numbers,size);
    return 0;
}