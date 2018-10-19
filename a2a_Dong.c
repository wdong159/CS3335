/*Wei Dong, CS3335, Fall 2018*/
#include <stdio.h>

void main(){
	long int input;
	int k=0;
	int r=0;
	int index=0;
	int frequency[2][10];
	
	//asking user input
	puts("Enter an integers:");
	scanf("%i",&input);
	
	//store input into array
	int copy = input;
	
	//case where input equals to zero
	while(copy == 0){
		k=1;
		break;
	}
	while(copy>0){
		int digits =copy%10;
		copy /= 10;
		k++;
	}
	int int_size[k];
	
	while(input>0){
		int_size[r]=input%10;
		input/=10;
		r++;
	}

	//numerical order from 0 to 9
	 for(int i =0; i<1; i++){
			for(int g =0; g<10; g++){
				frequency[i][g]=index;
				index++;
				printf("%i ",frequency[i][g]);
			}
		}
	puts("\n");
	
	//increment the frequency
	for(int i =1; i<2; i++){
			for(int g =0; g<k; g++){
				int assign = int_size[g];
				frequency[i][assign]++;
			}
	}
	
	//display the output
	for(int i =1; i<2; i++){
			for(int g =0; g<10; g++){
				printf("%i ",frequency[i][g]);
			}
	}
	puts("\n");
	

}