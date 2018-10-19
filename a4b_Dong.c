/* Wei Dong Fall 2018 CS3335*/
#include<stdio.h>
#include <stdlib.h>
int main(){
	int hours=0;
	int minutes=0;
	puts("Enter your time: ");
	scanf("%d:%d",&hours,&minutes);
	
	//read file and check if the file is valid
	FILE* ifp;
	ifp = fopen("flights.txt","r");
	if(ifp == NULL){
		fprintf(stderr,"The file cannot be open.\n");
		exit(1);
	}
	
	//display when a user excit 24-hours format
	int departTime = hours*60+minutes;
	if(departTime>1440){
		puts("Wrong Input, Please check you input and re-try");
	}
	
	/*
	 * this read the first line - no use
	 */
	char c [100];
	fscanf(ifp,"%[^\n]", c);
	
	/*
	 * while loop read the departure time and arrive time
	 * convert them into totalTime and store in flightRecord
	 */

	int input,index=0;
	int flightRecord[20];
	int totalTime=0;
	char semico;
	while(fscanf(ifp,"%d",&input) != EOF)
	{
		totalTime = input*60;
		semico = fgetc(ifp);
		fscanf(ifp,"%d",&input);
		totalTime = totalTime + input;
		flightRecord[index]=totalTime;
		totalTime=0;
		index++;
	}
	//to search for cloest flight time
	int i =0;
	while(i<index)
	{
			//work for searching next available flight
			if(i%2==0 && departTime <= flightRecord[i]){
				int arrTime = flightRecord[i+1];
				int arrHour = arrTime/60;
				int arrmin = arrTime%60;
				
				int depTime = flightRecord[i];
				int depHours = depTime/60;
				int depMinutes = depTime%60;
				printf("Cloest departure time from A is %d:%d and arriving at %d:%d in B\n",depHours,depMinutes,arrHour,arrmin);
				break;
			}
			//when user search for mid-night flight it will print the first flight in the morning
			else if(i%2==0&&departTime > flightRecord[index-2]){
				int arrTime = flightRecord[1];
				int arrHour = arrTime/60;
				int arrmin = arrTime%60;
				
				int depTime = flightRecord[0];
				int depHours = depTime/60;
				int depMinutes = depTime%60;
				printf("Cloest departure time from A is %d:%d and arriving at %d:%d in B\n",depHours,depMinutes,arrHour,arrmin);
				break;
			}
			i++;
	}
	
	fclose(ifp);
	return 1;
}