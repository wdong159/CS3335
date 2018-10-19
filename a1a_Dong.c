/*Wei Dong, CS3335, Fall 2018*/
#include <stdio.h>

#define transmission 4000
#define messageSize 16000

void calTime(float overhead,float packetSize,float *time){
	*time = (packetSize + overhead)/transmission;	
}

void delayTime(float time, float packetSize, float *endTime){
	*endTime = time*(2+ (messageSize/packetSize));
}

void main(){

	float overhead;
	int packetSize = 4000;
	float list[6];
	
	char fileSize;
	char fileBit;
	
	puts("File size: b,kb,mb,gb...");
	puts("Enter the how many bytes of overhead and what is the file Size:");
	scanf("%f %c%c",&overhead, &fileSize,&fileBit);
	
	printf("The overhead bits is: %.2f%c%c\n",overhead,fileSize,fileBit);
	
	if(fileSize=='k'){
		overhead *=1000;
	}
	else if(fileSize=='m'){
		overhead *=1000000;
	}
	else if(fileSize=='g'){
		overhead *=1000000000;
	}
	for(int i =0; i<6; i++){
		
	float time;
	calTime(overhead, packetSize,&time);
	
	float endTime;
	delayTime(time, packetSize,&endTime);
	
	list[i]=endTime;
	
	printf("The End to End deley is: %4.2f second.\n",list[i]);
	packetSize /=2;	
	}

}