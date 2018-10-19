/*Wei Dong, CS3335, Fall 2018*/
#include <stdio.h>

//convert binary to integer
void binaryToInt(int binaryNum){
	int i,index, power = 2,total=0,number=0;;
	int binarycopy = binaryNum;
	
	//two while for finding total number in the integer and split the integer
	while(binarycopy!=0){
		binarycopy/=10;
		index++;
	}
	int binaryArray[index];
	while(binaryNum>0){
		binaryArray[i]=binaryNum%10;
		binaryNum/=10;
		i++;
	}
	//get array size
	int get_size = sizeof(binaryArray)/sizeof(binaryArray[0]);
	
	//binart form 1 == 1
	if(binaryArray[0]==1){
		total+=1;
	}
	
	//value to the power of two bc its binary form e.g. 100 is equal to 0*2 + 0*4 + 1*8
	for(int r = 1; r<get_size ; r++){
		number = binaryArray[r];
		total = total + power*number;
		power *=2;
	}
	
	//display the output
	for(int r = get_size-1; r>=0; r--)
		printf("%i ",binaryArray[r]);	
	
	printf(" is the binart for integer number: %i \n", total);
}

//integer to binary
void intToBinary(int input){
	int copy = input;
	int i = 0,extra = 0;
	
	while(copy!=0){
		int digits =copy%10;
		copy /= 2;
		extra++;
	}
	
	int binary[extra];
	while(input>0){
		binary[i] = input%2;
		input/=2;
		i++;
	}
	
	//get array size
	int size = sizeof(binary)/sizeof(binary[0]);
	
	//display array
	for(int r = size-1; r>=0; r--){
		printf("%i ", binary[r]);
	}
}

void main(){
	int input;
	puts("Enter an integer (integer to binary form): ");
	scanf("%i",&input);

	printf("\nThe binary for integer: %i is \n",input);
	//convert integer to binary form
	intToBinary(input);
	
	puts("\n");
	
	int binaryNum;
	puts("Enter an binary form:");
	scanf("%i",&binaryNum);
	binaryToInt(binaryNum);
}

