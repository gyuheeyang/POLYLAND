#include<stdio.h>
int main()
{
	//����  
	int ticket; //�̿�� ���� 
	int ticket_time; //1day after4
	int birthday; //�ֹι�ȣ 
	int treatment; //������ 
	int today = 220316 ; //���� ��¥   
	 
	//Ƽ�ϰ��� 
	const int STANDARD_DAY1_ADULT = 59000; 
	const int STANDARD_DAY1_TEEN = 52000; 
	const int STANDARD_DAY1_KID = 47000; 
	const int STANDARD_DAY1_BABY = 15000; 
	const int STANDARD_DAY1_SENIOR = 47000; 
	
	const int STANDARD_AFTER4_ADULT= 48000; 
	const int STANDARD_AFTER4_TEEN = 42000; 
	const int STANDARD_AFTER4_KID  = 36000; 
	const int STANDARD_AFTER4_BABY  = 15000; 
	const int STANDARD_AFTER4_SENIOR  = 36000; 
	
	const int PARK_DAY1_ADULT = 56000; 
	const int PARK_DAY1_TEEN = 50000; 
	const int PARK_DAY1_KID = 46000; 
	const int PARK_DAY1_BABY = 15000; 
	const int PARK_DAY1_SENIOR = 46000;
	
	const int PARK_AFTER4_ADULT = 45000; 
	const int PARK_AFTER4_TEEN = 40000; 
	const int PARK_AFTER4_KID = 35000; 
	const int PARK_AFTER4_BABY = 15000;  
	const int PARK_AFTER4_SENIOR = 35000;  
	 
	
	
	//�� ���� ���  
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
	
	//������ 
	const float TREATMENT_DISABLED = 0.5;	//����� (����,��ũ)
	const float TREATMENT_NATIONAL = 0.5;	//���������� (����,��ũ) 
	const float TREATMENT_MILITARY = 0.51;	//�ް��庴 (����) 
	const float TREATMENT_PREGNANT = 0.5;	//�ӻ�� (����) 
	const float TREATMENT_MULTICHILD = 0.7;	//�ٵ��� �ູ ī�� (����) 
	
	
	//1day Ƽ�� ����  
	int price; 
	int isExit;
	
	do{
			//ȭ����� 
			printf("������ �����ϼ���.\n1.�����̿��\n2.��ũ�̿��\n"); 
			scanf("%d", &ticket);
			printf("1Day�� After4 �� �ϳ��� �����ϼ���.\n1.1Day\n2.After4\n");
			scanf("%d", &ticket_time);
			printf("�ֹι�ȣ ���ڸ��� �Է��ϼ���.\n");
			scanf("%d", &birthday);
			printf("�������� �����ϼ���.\n1.����(���� ���� �ڵ�ó��)\n2.�����\n3.����������\n4.�ް��庴\n5.�ӻ��\n6.�ٵ����ູī��\n");
			scanf("%d", &treatment);

			
			if (ticket == 1){				//�����̿��, 1day, ������ ����
				if (ticket_time ==1){     
					if(treatment == 1){
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
						else if (age_group ==5){
							price = STANDARD_DAY1_SENIOR;
						}	
					}
				
					if(treatment ==2){		//�����̿��, 1day, ������ 2.����� 
						if(age_group ==1){
							price = STANDARD_DAY1_ADULT*TREATMENT_DISABLED;
						}
						else if(age_group ==2){
							price = STANDARD_DAY1_TEEN*TREATMENT_DISABLED;
						}
						else if(age_group ==3){
							price = STANDARD_DAY1_KID*TREATMENT_DISABLED;
						}
						else if(age_group ==4){
							price = STANDARD_DAY1_BABY*TREATMENT_DISABLED;
						}
						else if(age_group ==5 ){
							price = STANDARD_DAY1_SENIOR*TREATMENT_DISABLED;
						}
					}
					if(treatment ==3){		//�����̿��, 1day, ������ 3.���������� 
						if(age_group ==1){
							price = STANDARD_DAY1_ADULT*TREATMENT_NATIONAL;
						}
						else if(age_group ==2){
							price = STANDARD_DAY1_TEEN*TREATMENT_NATIONAL;
						}
						else if(age_group ==3){
							price = STANDARD_DAY1_KID*TREATMENT_NATIONAL;
						}
						else if(age_group ==4){
							price = STANDARD_DAY1_BABY*TREATMENT_NATIONAL;
						}
						else if(age_group ==5 ){
							price = STANDARD_DAY1_SENIOR*TREATMENT_NATIONAL;
						}
					}
					if(treatment==4){		//�����̿��, 1day, ������ 4. �ް��庴  
						if(age_group ==1){
							price = STANDARD_DAY1_ADULT*TREATMENT_MILITARY;
						}
						else if(age_group ==2){
							price = STANDARD_DAY1_TEEN*TREATMENT_MILITARY;
						}
						else if(age_group ==3){
							price = STANDARD_DAY1_KID*TREATMENT_MILITARY;
						}
						else if(age_group ==4){
							price = STANDARD_DAY1_BABY*TREATMENT_MILITARY;
						}
						else if(age_group ==5 ){
							price = STANDARD_DAY1_SENIOR*TREATMENT_MILITARY;
						}
					}
					if(treatment==5){		//�����̿��, 1day, ������ 5. �ӻ��  
						if(age_group ==1){
							price = STANDARD_DAY1_ADULT*TREATMENT_PREGNANT;
						}
						else if(age_group ==2){
							price = STANDARD_DAY1_TEEN*TREATMENT_PREGNANT;
						}
						else if(age_group ==3){
							price = STANDARD_DAY1_KID*TREATMENT_PREGNANT;
						}
						else if(age_group ==4){
							price = STANDARD_DAY1_BABY*TREATMENT_PREGNANT;
						}
						else if(age_group ==5 ){
							price =  STANDARD_DAY1_SENIOR*TREATMENT_PREGNANT;
						}
					} 
					if(treatment ==6){		//�����̿��, 1day, ������ 6.�ٵ���  
						if(age_group ==1){
							price = STANDARD_DAY1_ADULT*TREATMENT_MULTICHILD; 
						}
						else if(age_group ==2){
							price = STANDARD_DAY1_TEEN*TREATMENT_MULTICHILD; 
						}
						else if(age_group ==3){
							price = STANDARD_DAY1_KID*TREATMENT_MULTICHILD; 
						}
						else if(age_group ==4){
							price = STANDARD_DAY1_BABY*TREATMENT_MULTICHILD; 
						}
						else if(age_group ==5 ){
							price =  STANDARD_DAY1_SENIOR*TREATMENT_MULTICHILD; 
						}
					} 
				}
				
				if (ticket_time ==2){		//�����̿��, after4, ������ ����
					if(treatment ==1){
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
						else if(age_group ==5){
							price = STANDARD_AFTER4_SENIOR;
						}
					}
					if(treatment ==2){		// �����̿��, after4, ������ 2.����� 
						if(age_group ==1){
							price = STANDARD_AFTER4_ADULT*TREATMENT_DISABLED; 
						}
						else if(age_group ==2){
							price = STANDARD_AFTER4_TEEN*TREATMENT_DISABLED;
						}
						else if(age_group ==3){
							price = STANDARD_AFTER4_KID*TREATMENT_DISABLED;
						}
						else if(age_group ==4){
							price = STANDARD_AFTER4_BABY*TREATMENT_DISABLED;
						}
						else if(age_group ==5 ){
							price = STANDARD_AFTER4_SENIOR*TREATMENT_DISABLED;
						}
					}
					if(treatment ==3){		//�����̿��, after4, ������ 3.���������� 
						if(age_group ==1){
							price = STANDARD_AFTER4_ADULT*TREATMENT_NATIONAL;
						}
						else if(age_group ==2){
							price = STANDARD_AFTER4_TEEN*TREATMENT_NATIONAL;
						}
						else if(age_group ==3){
							price = STANDARD_AFTER4_KID*TREATMENT_NATIONAL;
						}
						else if(age_group ==4){
							price = STANDARD_AFTER4_BABY*TREATMENT_NATIONAL;
						}
						else if(age_group ==5 ){
							price = STANDARD_AFTER4_SENIOR*TREATMENT_NATIONAL;
						}
					}
					if(treatment==4){		//�����̿��, after4, ������ 4. �ް��庴  
						if(age_group ==1){
							price = STANDARD_AFTER4_ADULT*TREATMENT_MILITARY;
						}
						else if(age_group ==2){
							price = STANDARD_AFTER4_TEEN*TREATMENT_MILITARY;
						}
						else if(age_group ==3){
							price = STANDARD_AFTER4_KID*TREATMENT_MILITARY;
						}
						else if(age_group ==4){
							price = STANDARD_AFTER4_BABY*TREATMENT_MILITARY;
						}
						else if(age_group ==5 ){
							price = STANDARD_AFTER4_SENIOR*TREATMENT_MILITARY;
						}
					}
					if(treatment==5){		//�����̿��, after4, ������ 5. �ӻ��  
						if(age_group ==1){
							price = STANDARD_AFTER4_ADULT*TREATMENT_PREGNANT;
						}
						else if(age_group ==2){
							price = STANDARD_AFTER4_TEEN*TREATMENT_PREGNANT;
						}
						else if(age_group ==3){
							price = STANDARD_AFTER4_KID*TREATMENT_PREGNANT;
						}
						else if(age_group ==4){
							price = STANDARD_AFTER4_BABY*TREATMENT_PREGNANT;
						}
						else if(age_group ==5 ){
							price = STANDARD_AFTER4_SENIOR*TREATMENT_PREGNANT;
						}
					} 
					if(treatment ==6){		//�����̿��, after4, ������ 6.�ٵ���  
						if(age_group ==1){
							price = STANDARD_AFTER4_ADULT*TREATMENT_MULTICHILD; 
						}
						else if(age_group ==2){
							price = STANDARD_AFTER4_TEEN*TREATMENT_MULTICHILD; 
						}
						else if(age_group ==3){
							price = STANDARD_AFTER4_KID*TREATMENT_MULTICHILD; 
						}
						else if(age_group ==4){
							price = STANDARD_AFTER4_BABY*TREATMENT_MULTICHILD; 
						}
						else if(age_group ==5 ){
							price = STANDARD_AFTER4_SENIOR*TREATMENT_MULTICHILD; 
						}
					} 
				} 
	
	
			if (ticket ==2){				//��ũ�̿��, day1, ������ ���� 
				if (ticket_time ==1){
					if (treatment ==1){
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
						else if(age_group ==5){
							price = PARK_DAY1_SENIOR;
						}
					}
					if(treatment ==2){		//��ũ�̿��, day1, ������ 2.����� 
						if(age_group ==1){
							price = PARK_DAY1_ADULT*TREATMENT_DISABLED; 
						}
						else if(age_group ==2){
							price = PARK_DAY1_TEEN*TREATMENT_DISABLED;
						}
						else if(age_group ==3){
							price = PARK_DAY1_KID*TREATMENT_DISABLED;
						}
						else if(age_group ==4){
							price = PARK_DAY1_BABY*TREATMENT_DISABLED;
						}
						else if(age_group ==5 ){
							price = PARK_DAY1_SENIOR*TREATMENT_DISABLED;
						}
					}
					if(treatment ==3){		//��ũ�̿��, day1, ������ 3.����������  
						if(age_group ==1){
							price = PARK_DAY1_ADULT*TREATMENT_NATIONAL; 
						}
						else if(age_group ==2){
							price = PARK_DAY1_TEEN*TREATMENT_NATIONAL;
						}
						else if(age_group ==3){
							price = PARK_DAY1_KID*TREATMENT_NATIONAL;
						}
						else if(age_group ==4){
							price = PARK_DAY1_BABY*TREATMENT_NATIONAL;
						}
						else if(age_group ==5 ){
							price = PARK_DAY1_SENIOR*TREATMENT_NATIONAL;
						}
					}	
				}
				if (ticket_time==2){		//��ũ�̿��, after4, ������ ����
					if (treatment ==1){
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
						else if(age_group==4){
							price = PARK_AFTER4_SENIOR;
						}
					}
					if(treatment ==2){		//��ũ�̿��, after4,  ������ 2.�����
						if(age_group ==1){
							price = PARK_AFTER4_ADULT*TREATMENT_DISABLED;
						}
						else if(age_group ==2){
							price = PARK_AFTER4_TEEN*TREATMENT_DISABLED;
						}
						else if(age_group ==3){
							price = PARK_AFTER4_KID*TREATMENT_DISABLED;
						}
						else if(age_group ==4){
							price = PARK_AFTER4_BABY*TREATMENT_DISABLED;
						}
						else if(age_group ==5 ){
							price = PARK_AFTER4_SENIOR*TREATMENT_DISABLED;
						}	
					}
					if(treatment ==3){		//��ũ�̿��, after4, ������ 3.����������  
						if(age_group ==1){
							price = PARK_AFTER4_ADULT*TREATMENT_NATIONAL; 
						}
						else if(age_group ==2){
							price = PARK_AFTER4_TEEN*TREATMENT_NATIONAL;
						}
						else if(age_group ==3){
							price = PARK_AFTER4_KID*TREATMENT_NATIONAL;
						}
						else if(age_group ==4){
							price = PARK_AFTER4_BABY*TREATMENT_NATIONAL;
						}
						else if(age_group ==5 ){
							price = PARK_AFTER4_SENIOR*TREATMENT_NATIONAL;
						}
					}
				}
			} 
		}
		printf("�� ����: %d\n���̱׷�: %d\n������ %d�Դϴ�.\n�����մϴ�. ", age, age_group, price);
		printf("��� �߱� �Ͻðڽ��ϱ�?\n1.Ƽ�Ϲ߱�\n2.����\n");
		scanf("%d",&isExit); 	
			
	}
	while (isExit <2);
		
	
	return 0;
}

	
	
	
	
 
