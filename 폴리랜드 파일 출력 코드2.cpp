#include<stdio.h>
#include<time.h> //�ð�, ��¥�� ���� �Լ��� ������ ���� 

int main()
{
	//������ ����  
	const int STANDARD_DAY1_ADULT = 59000, STANDARD_DAY1_TEEN = 52000, STANDARD_DAY1_KID = 47000, STANDARD_DAY1_BABY = 15000, STANDARD_DAY1_SENIOR = 47000, 
			  STANDARD_AFTER4_ADULT= 48000, STANDARD_AFTER4_TEEN = 42000, STANDARD_AFTER4_KID  = 36000, STANDARD_AFTER4_BABY  = 15000, STANDARD_AFTER4_SENIOR  = 36000, 
			  PARK_DAY1_ADULT = 56000, PARK_DAY1_TEEN = 50000, PARK_DAY1_KID = 46000, PARK_DAY1_BABY = 15000, PARK_DAY1_SENIOR = 46000,
			  PARK_AFTER4_ADULT = 45000, PARK_AFTER4_TEEN = 40000, PARK_AFTER4_KID = 35000, PARK_AFTER4_BABY = 15000, PARK_AFTER4_SENIOR = 35000;  

	//����  
	int ticket; //�̿�� ���� 
	int ticketTime; //1day after4
	int birthday; //�ֹι�ȣ 
	int ageGroup;
	int treatment; //������ 
	int ticketNumber; //Ƽ�� ����  
	int price = 0; 
	int totalPrice = 0; 
	int finalPrice = 0;
	int again;
	int newOrder; 
	int counter = 0; //�ֹ� ���� �迭 Ž���� (position) 
	int today;
	int age;
	int todayDate;
	float discount;  //int����  flaot���� ������  
	int treatmentGroup;
	
	//�ð� �ҷ����� 
	time_t timer;
	struct tm* t; //struct tm ����ü �ȿ��� int �� �� �ִ� ex) int tm_min; int tm_hour; int tm_year; ���  
	timer = time(NULL); // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �����Ͽ� ��������� ��
	t = localtime(&timer); // �������� ���� ����ü�� �ֱ�

	do{ //���� �մ� �ޱ� ���� do while �ݺ�  
		int ticketArr[20] = {0}, ticketTimeArr[20] = {0}, treatmentArr[20] = {0}, ticketNumberArr[20] = {0},
			priceArr[20] = {0}, totalPriceArr[20] = {0} , ageGroupArr[20] = {0} , treatmentGroupArr[20]= {0};
			// �ʱ�ȭ ���ؼ� do while �� �ȿ� ����  
		do{ 
			printf("�Ե����� ��ǥ �ý���");
			do{
				printf("\n������ �����ϼ���.\n1.�����̿��\n2.��ũ�̿��\n"); 
				scanf("%d", &ticket);
				if (ticket ==1 || ticket==2)
				continue;
				printf("�ٽ� �������ּ���.\n");
			} while (!(ticket ==1 || ticket ==2));
			
			do{
				printf("1Day�� After4 �� �ϳ��� �����ϼ���.\n1.1Day\n2.After4\n");
				scanf("%d", &ticketTime);
				if (ticketTime ==1 || ticketTime ==2)
				continue;
				printf("�ٽ� �������ּ���.\n");
			}while (!(ticketTime ==1 || ticketTime ==2));
				
			printf("�ֹι�ȣ �� 6�ڸ��� �Է��ϼ���.\n");
			scanf("%d", &birthday);
				
			do{
				printf("�������� �����ϼ���.\n1.����(���� ���� �ڵ�ó��)\n2.�����\n3.����������\n4.�ް��庴\n5.�ӻ��\n6.�ٵ����ູī��\n");
				scanf("%d", &treatment);
				if(treatment == 1 || treatment == 2 || treatment == 3 || treatment == 4 || treatment == 5 || treatment == 6 )
				continue;
				printf("�ٽ� �������ּ���.\n");	
			}while(!(treatment == 1 || treatment == 2 || treatment == 3 || treatment == 4 || treatment == 5 || treatment == 6 ) );		
			
	
			do{	
				printf("��� �ֹ��Ͻðڽ��ϱ�?  (�ִ� 10��)\n");
				scanf("%d",&ticketNumber) ;
				if(ticketNumber <= 10)
				continue; 
				printf("�ٽ� �������ּ���.\n");
			}while (!(ticketNumber <= 10));
			

			//�ð� �Է� 
			todayDate= (t->tm_year + 1900)*10000 + (t->tm_mon + 1)*100 + t->tm_mday;  
			// ���� ���� 20220101 ���·� �����ϱ� ����  
			
			///������ ��� 
			//todayDate: 20220323
			today = todayDate- 20000000 + 1000000; //ex)220323 + 1000000 
			//birthday = 951127 
		
			//�� ����  
			age = (today-birthday)/10000;
			if (age > 100){
				age = age - 100;
			} 
	
			//���� �׷�
			if (18 <=age && age <65){
				ageGroup =1; //adult
			}
			else if (13<= age && age <18){
				ageGroup =2; //teen
			}
			else if (3 <= age && age < 12){
				ageGroup =3; //kid
			}
			else if (0 <= age && age < 2 ){
				ageGroup =4; //baby
			}
			else {    //(65 < age) ������  
				ageGroup =5; //senior
			}
	
				
				if (ticket == 1){				//�����̿��, 1day
					if (ticketTime ==1){     
						if(ageGroup ==1){
							price = STANDARD_DAY1_ADULT;
						}
						else if (ageGroup ==2){
							price = STANDARD_DAY1_TEEN;
						}	
						else if (ageGroup ==3){
							price = STANDARD_DAY1_KID;
						}
						else if (ageGroup ==4){
							price = STANDARD_DAY1_BABY;
						}
						else {
							price = STANDARD_DAY1_SENIOR;
						}	
					} 	
					else if (ticketTime ==2){		//�����̿��, after4
						if(ageGroup ==1){
							price = STANDARD_AFTER4_ADULT; 
						}
						else if(ageGroup ==2){
							price = STANDARD_AFTER4_TEEN;
						}
						else if(ageGroup ==3){
							price = STANDARD_AFTER4_KID;
						}
						else if(ageGroup ==4){
							price = STANDARD_AFTER4_BABY;
						}
						else {
							price = STANDARD_AFTER4_SENIOR;
						}
					}	
				}
				else{				//��ũ�̿��, day1
					if (ticketTime ==1){
						if(ageGroup ==1){
							price = PARK_DAY1_ADULT;
						}
						else if(ageGroup ==2){
							price =PARK_DAY1_TEEN;
						}
						else if(ageGroup ==3){
							price = PARK_DAY1_KID;
						}
						else if(ageGroup ==4){
							price = PARK_DAY1_BABY;
						}
						else{
							price = PARK_DAY1_SENIOR;
						}
					}
					else if (ticketTime==2){		//��ũ�̿��, after4
						if (ageGroup ==1){
							price = PARK_AFTER4_ADULT;
						}
						else if(ageGroup==2){
							price = PARK_AFTER4_TEEN;
						}
						else if(ageGroup==3){
							price = PARK_AFTER4_KID;
						}
						else if(ageGroup==4){
							price = PARK_AFTER4_BABY;
						}
						else {
							price = PARK_AFTER4_SENIOR;
						}
					}	
				}
				
				//������ ����
				
			
				switch (treatment){
					case (1):
						discount = 1; //������ ���� �����Ƿ� 1-0=1 
						treatmentGroup =1;
						break;
					case (2):
						discount =0.5;//1-0.5
						treatmentGroup =2;
						break;
					case (3):
						discount =0.5; //1 -0.5
						treatmentGroup =3;
						break;
					case (4):
						discount =0.51; //1- 0.49
						treatmentGroup =4;
						 break;
					case (5):
						discount =0.5; //1 -0.5
						treatmentGroup =5;
						break;
					case (6):
						discount =0.7; //1- 0.3
						treatmentGroup =6;
						 break;
				}		 
				
				//�������� 
				totalPrice =  price*ticketNumber*discount;  
		
				if (totalPrice == 0){
					printf("\n���� ���� �Դϴ�.\n");
				}
				else {
					printf ("\n%d����  �ѱݾ��� %d�� �Դϴ�.\n",ticketNumber, totalPrice) ;
				}
		
				//���û��� ��, ��Ŀ� ���
				ticketArr[counter] = ticket;
				ticketTimeArr[counter] = ticketTime ;
				treatmentArr[counter] = treatment;
				ticketNumberArr[counter] = ticketNumber;
				priceArr[counter] = price;
				totalPriceArr[counter] = totalPrice;
				treatmentGroupArr[counter] = treatmentGroup;
				ageGroupArr[counter] = ageGroup;
				finalPrice += totalPrice;
				//counter�� 1�߰�, �ʱⰪ�� 0 
				counter++; 
		
				//�̾ �������� ���� 
				printf("\n�̾ �̿���� �����Ͻðڽ��ϱ�?\n1.��\n2.�ƴϿ�\n");
				scanf("%d",&again); 
			}while(again == 1);
		
			
			/////���Ϸ� ����ϴ� �κ� ����, printf�� ���� 
			FILE *filePointer = fopen("report.csv","a");	 
			fprintf(filePointer, "��¥, ����, �����ð�, ����, ����, ����, ������\n");
			
			// ������ ���  
			printf("����/��ũ\t1day/after\t����\t�ż�\t����\t������\n");
			for (int i =0; i<counter; i++){				
				fprintf(filePointer,"%d,%d,%d,%d,%d,%d,%d\n",
								todayDate,ticketArr[i],ticketTimeArr[i],ageGroupArr[i],ticketNumberArr[i],totalPriceArr[i],treatmentGroupArr[i]);	
				
				switch (ticketArr[i]) {
				case 1:
					printf("\t�����̿��");
					break;
				case 2:
					printf("\t��ũ�̿��");
					break;
				default:
					break;
				}
				switch (ticketTimeArr[i]) {
				case 1:
					printf("\t1day");
					break;
				case 2:
					printf("\tAfter4");
					break;
				default:
					break;
				}
				switch (ageGroupArr[i]) {  
					case 1:
						printf("\t��  ��");
						break;
					case 2:
						printf("\tû�ҳ�");
						break;
					case 3:
						printf("\t���");
						break;
					case 4:
						printf("\t��  ��");
						break;
					case 5:
						printf("\t��  ��");
						break;
					default:
						break;
				}	
			
				printf("%d�� %d��",ticketNumberArr[i], totalPriceArr[i]) ; //�ż�   
					
				switch (treatmentGroupArr[i]) {
					case 1:
						printf("%s\n","������ ����");
						break;
					case 2:
						printf("%s\n","����� ���");
						break;
					case 3:
						printf("%s\n","���������� ���");
						break;
					case 4:
						printf("%s\n","�ް��庴 ���");
						break;
					case 5:
						printf("%s\n","�ӻ�� ���");
						break;
					case 6:
						printf("%s\n","�ٵ��� �ູī�� ���");
						break;
					default:
						break;
				}		
		}
		printf("\n����� �Ѿ��� %d�� �Դϴ�.", finalPrice);

		printf("\n���ο� �ֹ��� �ްڽ��ϱ�?\n1.��\n2.����\n");
		scanf("%d", &newOrder);
		 
		fclose(filePointer);
		
		counter = 0; 
		finalPrice = 0;	
	}while (newOrder == 1);
	
	return 0; 
}

