#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main()
{
	//   report.csv �ҷ����� 	
	FILE *fp = fopen("report.csv", "r");
	const int  MAX = 100;
	int count= 0;
	
	//���ڿ� ���� �Ҵ� report ù �� 7ĭ ���� ó�� ���� ���� 
	char *strCategory =(char *)malloc(sizeof(char)*MAX);	
	for(int i = 0;i< 7; i++){
		fscanf(fp, "%s\t", strCategory);
	}

	//�Էº�  
	int todayDate[MAX], ticketArr[MAX],ticketTimeArr[MAX],ageGroupArr[MAX],ticketNumberArr[MAX],totalPriceArr[MAX],treatmentGroupArr[MAX];
	while (fscanf(fp,"%d, %d,%d,%d,%d,%d,%d",&todayDate[count], &ticketArr[count],&ticketTimeArr[count],&ageGroupArr[count],
					&ticketNumberArr[count],&totalPriceArr[count],&treatmentGroupArr[count])!= -1 ){
					count++;						
	}
	fclose(fp);

	//��º�  
	printf("=====================report.csv=====================\n");
	printf ("%7s %5s %5s %5s %5s %5s %7s\n", "��¥","����","�ð�","����","����","�ݾ�","������"); 
	for (int i = 0; i < count; i++){
			printf("%d %5d %5d %5d %5d %5d %3d\n",todayDate[i],ticketArr[i],ticketTimeArr[i],ageGroupArr[i],ticketNumberArr[i],
					totalPriceArr[i],treatmentGroupArr[i]);
	}
	printf("====================================================\n");
	

	return 0;
}
