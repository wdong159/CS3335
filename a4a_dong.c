/* Wei Dong 3335 Fall 2018*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    int ch;
	int items[10000];
    /*  open the file for reading */
    fptr = fopen("Numbers.txt", "r");
    if (fptr == NULL)
    {
        fprintf(stderr,"Cannot open file \n");
        exit(1);
    }
    
    int total=0,low=0,high=0,i=0;
    
    /*
     * whille seach for highest and lowest number
     * store all the number into array
     */
    while (fscanf(fptr, "%d",&ch) != EOF)
    {
    	if(i==0)
    	{
    		low=ch;
    		high=ch;
    	}
		items[i]=ch;
		if(ch<low) low=ch;
		if(ch>high) high=ch;
        total+=ch;
        i++;
    }
	
	/*
	 * bubble sort
	 */
    int size = sizeof(items)/sizeof(items[0]);
    int number=0;
    for(int k=0; k<size-1; k++){
    	for(int l=0;l<size-k-1;l++)
    	{
    		if(items[l]>items[l+1])
    		{
    		number = items[l];
			items[l] = items[l+1];
			items[l+1] = number;
			}
    	}
    }
    /*
     * diaply highest lowest median average
     */
	int median = items[size/2]+items[(size/2)-1];
    printf("Highest = %d\t Lowest =%d\t Average =%d\t Median =%d",high,low,total/i,median/2);
    
    /*
     * display the range from 0 to 9999
     */
    printf("\nRange:\t\t");
    int range=0;
    for(int b =0; b<10;b++)
    {
    	printf("%d-",range);
    	range+=999;
    	printf("%d\t     ",range);
    	range++;
    }
    
    /*
     * dispaly count numbers
     */
    printf("\nCount Numbers:  ");	
	/*instead of using so many if statemen
	  The main idea is find the INDEX that is lower than 1000 but higher than previous index
	  once index is found print it and reset the index and increment 1000
	*/
	
	int abc=2;//default 2 bc counting is non zero integer and the loop start at 1
	int cbd=1000;
	for(int a=1;a<size;a++){
		if(items[a-1]<items[a]<items[a+1]&&items[a+1]<cbd)
		{
			abc++;
		}
		else
		{
				printf("%d\t\t",abc);
				cbd+=1000;
				abc =1;//reset to 1
		}
	}//end of display count for loop
    printf("\n");//new line
    fclose(fptr);
    
    return 0;
}