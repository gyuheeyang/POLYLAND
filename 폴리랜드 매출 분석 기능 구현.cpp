#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main()
{
	//   report.csv 불러오기 	
	FILE *fp = fopen("report.csv", "r");
	const int  MAX = 100;
	int count= 0;
	
	//문자열 동적 할당 report 첫 줄 7칸 저장 처리 하지 않음 
	char *strCategory =(char *)malloc(sizeof(char)*MAX);	
	for(int i = 0;i< 7; i++){
		fscanf(fp, "%s\t", strCategory);
	}

	//입력부  
	int todayDate[MAX], ticketArr[MAX],ticketTimeArr[MAX],ageGroupArr[MAX],ticketNumberArr[MAX],totalPriceArr[MAX],treatmentGroupArr[MAX];
	while (fscanf(fp,"%d, %d,%d,%d,%d,%d,%d",&todayDate[count], &ticketArr[count],&ticketTimeArr[count],&ageGroupArr[count],
					&ticketNumberArr[count],&totalPriceArr[count],&treatmentGroupArr[count])!= -1 ){
					count++;						
	}
	fclose(fp);

	//출력부  
	printf("=====================report.csv=====================\n");
	printf ("%7s %5s %5s %5s %5s %5s %7s\n", "날짜","권종","시간","연령","수량","금액","우대사항"); 
	for (int i = 0; i < count; i++){
			printf("%d %5d %5d %5d %5d %5d %3d\n",todayDate[i],ticketArr[i],ticketTimeArr[i],ageGroupArr[i],ticketNumberArr[i],
					totalPriceArr[i],treatmentGroupArr[i]);
	}
	printf("====================================================\n");
	

	return 0;
}
