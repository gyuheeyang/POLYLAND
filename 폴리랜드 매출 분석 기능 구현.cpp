#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//저장 되어있는 파일 읽기   	
	FILE *filePointer = fopen("report1.csv", "r");
	int count=0 , i; 
	int todayDate, ticketArr[30],ticketTimeArr[30],ageGroupArr[30],ticketNumberArr[30],totalPriceArr[30],treatmentGroupArr[30] = {0};
	
	
	while (fscanf(filePointer,"%d,%d,%d,%d,%d,%d,%d", &todayDate,&ticketArr[count],&ticketTimeArr[count],&ageGroupArr[count],
					&ticketNumberArr[count],&totalPriceArr[count],&treatmentGroupArr[count])!= -1 ){
					count++;						
	}
	
	
	for (int i = 0; i < count; i ++){
			printf("%d,%d,%d,%d,%d,%d,%d\n", todayDate,ticketArr[i],ticketTimeArr[i],ageGroupArr[i],ticketNumberArr[i],
					totalPriceArr[i],treatmentGroupArr[i]);
	}
	
	

	fclose(filePointer);

	return 0;
}
