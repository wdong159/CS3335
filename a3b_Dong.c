/*Wei Dong, CS3335, Fall 2018*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char rot_encry(int start,int end,int index, int rotation){
	index +=rotation;
	
	if(index<=end&&index>=start){
		return index;
	}

	else if(index >end){
		index -= start; //exceed to end so subtract start
		index %= 26;	//get the reminder
		index += start;	//add the start
		return index;
	}
}


int main(){
 
	char string[31];
	
	puts("Enter you text: ");
	fgets(string,31,stdin);//read input from user with empty space
 	int rotation,i;
 	puts("Enter how many rotation amount: ");
 	scanf("%i",&rotation);
 	char copy_string[31];
	
	while(string[i]!='\0'){
		char c = string[i];
		int index = c;//get the character index in USACII
		
		//check the char uppercase or lowercaes
		if( (c>='A' && c<='Z')){
			copy_string[i]=rot_encry(65,90,index,rotation);
		}
		else if((c>='a' && c<='z')){
			copy_string[i]=rot_encry(97,122,index,rotation);
		}

		//if empty do nothing
		else if(c == ' ')
			copy_string[i]=string[i];
		
		printf("%c ",copy_string[i]);
	i++;
	}
	printf("\n");
	
	return 0;
}