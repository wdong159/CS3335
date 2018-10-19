/*Wei Dong, CS3335, Fall 2018*/

#include<stdio.h>
#include <stdlib.h>

/*void storeValue(int *magic_squre, int row, int col,int i){
	*magic_squre[row][col]=i;
}
*/
void main(int argc, char *argv[]){
	
	int value = atoi(argv[1]);
	int row =value-1, col =value/2 + 1;
	
	if(value %2 !=0 && value >= 1 && value <= 15){
		int magic_squre[value][value];
		
		//make all the index equal to zero
		//some how they were some random number if i dont declear it
		for(int i =0 ; i<value; i++){
			for(int r=0; r<value;r++)
				magic_squre[i][r]=0;
		}
		
		//assign the first number to start with
		magic_squre[0][value/2]=1;
		
		//this loop will run value square of times
		int times = value*value;
		for(int i =2; i<=times; i++){
			
			//if index is not occupied
			if(magic_squre[row][col]==0){
				
				//assign value
				magic_squre[row][col]=i;
				//check row
				if(row < value && row !=0)
					row--;
				else if(row ==0)
					row =value-1;
				
				//check col
				if(col==0 || col <value-1)
					col++;
				else if(col ==value-1)
					col =0;
			}
		
			//if index is already occupied
			else if(magic_squre[row][col]!=0){
				
				//the magic squre is like walking up to a stair once you hit something you drop from your position - circle or cycle
				//check row ONLY because if start at the bottom
				//this if statement solve some wired situation
				if(row==value-1){
					row=1;
					col=value;
				}

				//increment by 2 because we decrement it in the previous if statement
				else
					row+=2;

				col--;
				//assign value
				//storeValue(&magic_squre,row,col,i);
				magic_squre[row][col]=i;
				
				//after assgining check row
				if(row < value && row !=0)
					row--;
				else if(row ==0)
					row =value-1;
				
				//check col
				if(col==0 || col <value-1)
					col++;
				else if(col ==value-1)
					col =0;
					
			}
		}
		int sum =0;
		
		for(int i =0 ; i<value; i++){
			sum+=*magic_squre[i];
			for(int r=0; r<value;r++)
				printf("%d  ",magic_squre[i][r]);
				printf("\n");
	}
	
		printf("n = %d(magic value = %d)\n",value,sum);
	}//end of if

	else
		printf("The number: %d is invalid range.\n",value);
	
}