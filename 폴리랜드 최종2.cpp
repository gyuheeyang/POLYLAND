#include<stdio.h>

int main()
{
	
	//������ ����  
	const int STANDARD_DAY1_ADULT = 59000; const int STANDARD_DAY1_TEEN = 52000; const int STANDARD_DAY1_KID = 47000; const int STANDARD_DAY1_BABY = 15000; const int STANDARD_DAY1_SENIOR = 47000; 	
	const int STANDARD_AFTER4_ADULT= 48000; const int STANDARD_AFTER4_TEEN = 42000; const int STANDARD_AFTER4_KID  = 36000; const int STANDARD_AFTER4_BABY  = 15000; const int STANDARD_AFTER4_SENIOR  = 36000; 
	const int PARK_DAY1_ADULT = 56000; const int PARK_DAY1_TEEN = 50000; const int PARK_DAY1_KID = 46000; const int PARK_DAY1_BABY = 15000; const int PARK_DAY1_SENIOR = 46000;
	const int PARK_AFTER4_ADULT = 45000; const int PARK_AFTER4_TEEN = 40000; const int PARK_AFTER4_KID = 35000; const int PARK_AFTER4_BABY = 15000;  const int PARK_AFTER4_SENIOR = 35000;  
	 
	/*������ 
	const float TREATMENT_DISABLED = 0.5;	//����� (����,��ũ)
	const float TREATMENT_NATIONAL = 0.5;	//���������� (����,��ũ) 
	const float TREATMENT_MILITARY = 0.51;	//�ް��庴 (����) 
	const float TREATMENT_PREGNANT = 0.5;	//�ӻ�� (����) 
	const float TREATMENT_MULTICHILD = 0.7;	//�ٵ��� �ູ ī�� (����)  
	 */
	//////////////���� ����////////////////
	 
	//����  
	int ticket; //�̿�� ���� 
	int ticket_time; //1day after4
	int birthday; //�ֹι�ȣ 
	int treatment; //������ 
	int ticket_number; //Ƽ�� ����  
	int price = 0; 
	int totalPrice = 0; 
	int isExit;
	
	int index = 0; //�ֹ� ���� �迭 Ž���� (position) 
	int array[100][5] = {0}; //�ֹ� ���� ����
	
	for(;;){
		do{
			printf("������ �����ϼ���.\n1.�����̿��\n2.��ũ�̿��\n"); 
			scanf("%d", &ticket);
			if (ticket ==1 || ticket==2)
			continue;
			printf("�ٽ� �������ּ���.\n");
		} while (!(ticket ==1 || ticket ==2));
		array[index][0] = ticket; //�迭 0��°  
		
		do{
			printf("1Day�� After4 �� �ϳ��� �����ϼ���.\n1.1Day\n2.After4\n");
			scanf("%d", &ticket_time);
			if (ticket_time ==1 || ticket_time ==2)
			continue;
			printf("�ٽ� �������ּ���.\n");
		}while (!(ticket_time ==1 || ticket_time ==2));
		array[index][1] = ticket_time; //�迭 1��° 
		
		printf("�ֹι�ȣ �� 6�ڸ��� �Է��ϼ���.\n");
		scanf("%d", &birthday);
	
		do{	
			printf("��� �ֹ��Ͻðڽ��ϱ�?  (�ִ� 10��)\n");
			scanf("%d",&ticket_number) ;
			if(ticket_number <= 10)
			continue; 
			printf("�ٽ� �������ּ���.\n");
		}while (!(ticket_number <= 10));
		array[index][2] = ticket_number; //�迭 2��° 
		
		do{
			printf("�������� �����ϼ���.\n1.����(���� ���� �ڵ�ó��)\n2.�����\n3.����������\n4.�ް��庴\n5.�ӻ��\n6.�ٵ����ູī��\n");
			scanf("%d", &treatment);
			if(treatment == 1 || treatment == 2 || treatment == 3 || treatment == 4 || treatment == 5 || treatment == 6 )
			continue;
			printf("�ٽ� �������ּ���.\n");	
		}while(!(treatment == 1 || treatment == 2 || treatment == 3 || treatment == 4 || treatment == 5 || treatment == 6 ) );
		array[index][3] = treatment; //�迭 3��°  
		
		
		int discount;  
		
		switch (treatment){
			case (1):
				discount = 1; //������ ���� �����Ƿ� 1-0=1 
				break;
			case (2):
				discount =0.5;//1-0.5
				break;
			case (3):
				discount =0.5; //1 -0.5
				break;
			case (4):
				discount =0.51; //1- 0.49
				 break;
			case (5):
				discount =0.5; //1 -0.5
				break;
			case (6):
				discount =0.7; //1- 0.3
				 break;
		}
		
	
		///������ ��� 
		int today = 220316 ; //���� ��¥  
		int today_year = (today/ 10000) + 100 ;
		int birth_year = birthday/ 10000;
		int year_dif = today_year - birth_year;
		int today_mmdd = today-(today/10000)*10000;
		int birth_mmdd = birthday -(birthday/10000)*10000;
		
		int age; //�� ����  
		if (birth_mmdd <= today_mmdd){
			age = year_dif ; 
		}
		else { 
			age = year_dif -1 ;
		}
		if (age > 100){
			age = age - 100;
		} 
		
		//���� �׷�  
		//���� �׷� 
		int age_group;
		
		if (18 <=age && age <65)
		{
			age_group =1; //adult
		}
		if (13<= age && age <18)
		{
			age_group =2; //teen
		}
		if (3 <= age && age < 12) 
		{
			age_group =3; //kid
		}
		if (0 <= age && age < 2 )
		{
			age_group =4; //baby
		}
		if (65 < age) 
		{
			age_group =5; //senior
		}
		array[index][4] = age_group; //�迭 �׹�°
		
		///////////////////////////////////////////////////////////////
		if (ticket == 1){				//�����̿��, 1day
			if (ticket_time ==1){     
				if(age_group ==1){
					price = STANDARD_DAY1_ADULT;
				}
				else if (age_group ==2){
					price = STANDARD_DAY1_TEEN;
				}	
				else if (age_group ==3){
					price = STANDARD_DAY1_KID;
				}
				else if (age_group ==4){
					price = STANDARD_DAY1_BABY;
				}
				else {
					price = STANDARD_DAY1_SENIOR;
				}	
			} 	
			else if (ticket_time ==2){		//�����̿��, after4
				if(age_group ==1){
					price = STANDARD_AFTER4_ADULT; 
				}
				else if(age_group ==2){
					price = STANDARD_AFTER4_TEEN;
				}
				else if(age_group ==3){
					price = STANDARD_AFTER4_KID;
				}
				else if(age_group ==4){
					price = STANDARD_AFTER4_BABY;
				}
				else {
					price = STANDARD_AFTER4_SENIOR;
				}
			}	
		}
		else{				//��ũ�̿��, day1
			if (ticket_time ==1){
				if(age_group ==1){
					price = PARK_DAY1_ADULT;
				}
				else if(age_group ==2){
					price =PARK_DAY1_TEEN;
				}
				else if(age_group ==3){
					price = PARK_DAY1_KID;
				}
				else if(age_group ==4){
					price = PARK_DAY1_BABY;
				}
				else{
					price = PARK_DAY1_SENIOR;
				}
			}
			else if (ticket_time==2){		//��ũ�̿��, after4
				if (age_group ==1){
					price = PARK_AFTER4_ADULT;
				}
				else if(age_group==2){
					price = PARK_AFTER4_TEEN;
				}
				else if(age_group==3){
					price = PARK_AFTER4_KID;
				}
				else if(age_group==4){
					price = PARK_AFTER4_BABY;
				}
				else {
					price = PARK_AFTER4_SENIOR;
				}
			}	
		}
		
		
		//����*����*Ƽ�ϼ�  
		totalPrice = price * discount * ticket_number;
		array[index][5] = totalPrice;
		
		printf("�� ����: %d\n���̱׷�: %d\n������ %d�Դϴ�.\n�����մϴ�. ", age, age_group, totalPrice);
		printf("��� �߱� �Ͻðڽ��ϱ�?\n1.Ƽ�Ϲ߱�\n2.����\n");
		scanf("%d",&isExit); 	
		
		if (isExit ==2){
			printf("�߱� ����\n");
			printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","�̿�� ����","�̿� �ð�","�߱� ����","��� ����","����","����� �Ѿ�");
			printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s","(����/��ũ)","(1Day/After4)"," (��) ","(1-6)","(��°) ","(��)");
			break;
		}
		else {
		index++;
		}
	}
	//�ݺ� �Է� ������ ���� ���� 
	for (int i=0; i<=index;i ++){	
		for (int j=0;j<6;j++){
			printf("%10d\t",array[i][j]);
			}
		printf("\n");
	}

	int sum = 0;
	
	for (int i=0;i<=index;i++){
		sum += array[i][5];
	}	
	
	printf("����� �Ѿ��� %d�Դϴ�.",sum);
	
		
return 0;	
}










