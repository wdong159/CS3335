/*Wei Dong, CS3335, Fall 2018*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int generate(){
	//generate random numbers
	int num = rand()%100;
	if(num != 0){
		num +=1;
	}
	return num;
}

void GuessNum(int Max){
	
	int guess;
	
	int ranNum = generate();//generate a random numbers
	//loop for user interaction
	for(int i=0; i<Max;i++){
	
	puts("Guess a numbers");
	
	scanf("%3i",&guess);
	
	if(guess == ranNum){
		puts("congralation, You guess the right numbers");
		break;
	}
	else if(guess < ranNum){
		puts("Too Low, try again");
	}
	else if(guess > ranNum){
		puts("Too high, try again");
	}
	printf("You still have: %3i of trails\n",Max-(i+1));
	if(i==(Max-1)){
		printf("\nThe random number is:%i\n",ranNum);
		puts("You had use all of trails, Failed");
	}
		
	}
	
}
int main(void){
	int Max = 10;
	srand(time(NULL));
	GuessNum(Max);//guess number
	return 0;
}