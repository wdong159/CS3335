#include <stdio.h>

void bubble(int unSort[], int size){
	int temp;
	
	for(int i=0; i<size-1; i++){
		
		for(int j=0; j<size-i-1; j++){
			if(unSort[j]>unSort[j+1]){
				temp = unSort[j];
				unSort[j] = unSort[j+1];
				unSort[j+1] = temp;
			}
		}
	}
	
	for(int i =0; i<size;i++){
				printf("%d ",unSort[i]);
	}
	
}


void recBubble(int unSort[],int size){
	
	if(size ==1)
		return;
	int temp;
	
	for(int j=0;j<size-1;j++){
		if(unSort[j]>unSort[j+1]){
			temp = unSort[j];
			unSort[j] = unSort[j+1];
			unSort[j+1] = temp;
		}
	}
			printf("%d ", unSort[size-1]);
	recBubble(unSort,size-1);
	
}

int main(){
	int unSort[] = {123,1231,231,231,2,3,12,3,1,23,5,25,26235,26,6};
	int size = sizeof(unSort)/sizeof(unSort[0]);
	int *p;
	p=unSort;
	
	printf("The following is the unsort array in: \n");
	for(;p<&unSort[size];)
		printf("%d ",*p++);
	
	printf("\nthe following is the bubble sort array:\n");
	bubble(unSort,size);

	printf("\n");
	recBubble(unSort,size);
		
	return 0;
}