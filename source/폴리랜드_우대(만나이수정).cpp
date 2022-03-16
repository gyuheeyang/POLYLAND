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
	const int standard_day1_adult = 59000; 
	const int standard_day1_teen = 52000; 
	const int standard_day1_kid = 47000; 
	const int standard_day1_baby = 15000; 
	const int standard_day1_senior = 15000; 
	
	const int standard_after4_adult = 48000; 
	const int standard_after4_teen = 42000; 
	const int standard_after4_kid = 36000; 
	const int standard_after4_baby = 15000; 
	const int standard_after4_senior = 15000; 
	
	const int park_day1_adult = 56000; 
	const int park_day1_teen = 50000; 
	const int park_day1_kid = 46000; 
	const int park_day1_baby = 15000; 
	const int park_day1_senior = 15000;
	
	const int park_after4_adult = 45000; 
	const int park_after4_teen = 40000; 
	const int park_after4_kid = 35000; 
	const int park_after4_baby = 15000;  
	
	const int park_after4_senior = 15000;  
	 
	printf("������ �����ϼ���.\n1.�����̿��\n2.��ũ�̿��\n"); 
	scanf("%d", &ticket);
	printf("1Day�� After4 �� �ϳ��� �����ϼ���.\n1.1Day\n2.After4\n");
	scanf("%d", &ticket_time);
	printf("�ֹι�ȣ ���ڸ��� �Է��ϼ���.\n");
	scanf("%d", &birthday);
	printf("�������� �����ϼ���.\n1.����(���� ���� �ڵ�ó��)\n2.�����\n3.����������\n4.�ް��庴\n5.�ӻ��\n6.�ٵ����ູī��\n");
	scanf("%d", &treatment);
    
	
	
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
	
	
	
	//1day Ƽ�� ����  
	int price; 
	
	//�����̿��, 1day, ������ ����
	if(ticket == 1 && ticket_time== 1 && treatment== 1 && age_group== 1) 
	{
		price = standard_day1_adult;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 1 && age_group== 2)
	{
		price = standard_day1_teen;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 1 && age_group== 3)
	{
		price = standard_day1_kid;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 1 && age_group== 4)
	{
		price = standard_day1_baby;
	}
    else if (ticket == 1 && ticket_time== 1 && treatment== 1 && age_group== 5)
	{
		price = standard_day1_senior;
	}
	
	
	
	//�����̿��, after4, ������ ����
	if(ticket == 1 && ticket_time== 2 && treatment== 1 && age_group== 1) 
	{
		price = standard_after4_adult; 
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 1 && age_group== 2)
	{
		price = standard_after4_teen;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 1 && age_group== 3)
	{
		price = standard_after4_kid;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 1 && age_group== 4)
	{
		price = standard_after4_baby;
	}
    else if (ticket == 1 && ticket_time== 2 && treatment== 1 && age_group== 5)
	{
		price = standard_after4_senior;
	}
		
	
	//��ũ�̿��, day1, ������ ���� 
	if(ticket == 2 && ticket_time== 1 && treatment== 1 && age_group== 1) 
	{
		price = park_day1_adult;
	}
	else if (ticket == 2 && ticket_time== 1 && treatment== 1 && age_group== 2)
	{
		price = park_day1_teen;
	}
	else if (ticket == 2 && ticket_time== 1 && treatment== 1 && age_group== 3)
	{
		price = park_day1_kid;
	}
	else if (ticket == 2 && ticket_time== 1 && treatment== 1 && age_group== 4)
	{
		price = park_day1_baby;
	}
    else if (ticket == 2 && ticket_time== 1 && treatment== 1 && age_group== 5)
	{
		price = park_day1_senior;
	}
	
	//��ũ�̿��, after4, ������ ����
	if(ticket == 2 && ticket_time== 2 && treatment== 1 && age_group== 1) 
	{
		price = park_after4_adult;
	}
	else if (ticket == 2 && ticket_time== 2 && treatment== 1 && age_group== 2)
	{
		price = park_after4_teen;
	}
	else if (ticket == 2 && ticket_time== 2 && treatment== 1 && age_group== 3)
	{
		price = park_after4_kid;
	}
	else if (ticket == 2 && ticket_time== 2 && treatment== 1 && age_group== 4)
	{
		price = park_after4_baby;
	}
    else if (ticket == 2 && ticket_time== 2 && treatment== 1 && age_group== 5)
	{
		price = park_after4_senior;
	} 
	
	
	//������ 
	const float treatment_disabled = 0.5;	//����� (����,��ũ)
	const float treatment_national = 0.5;	//���������� (����,��ũ) 
	const float treatment_military = 0.51;	//�ް��庴 (����) 
	const float treatment_pregnant = 0.5;	//�ӻ�� (����) 
	const float treatment_multichild = 0.7;	//�ٵ��� �ູ ī�� (����) 
	
	//�����̿��, 1day, ������ 2.����� 
		if(ticket == 1 && ticket_time== 1 && treatment== 2 && age_group== 1) 
	{
		price = standard_day1_adult*treatment_disabled;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 2 && age_group== 2)
	{
		price = standard_day1_teen*treatment_disabled;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 2 && age_group== 3)
	{
		price = standard_day1_kid*treatment_disabled;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 2 && age_group== 4)
	{
		price = standard_day1_baby*treatment_disabled;
	}
    else if (ticket == 1 && ticket_time== 1 && treatment== 2 && age_group== 5)
	{
		price = standard_day1_senior*treatment_disabled;
	}
	
	// �����̿��, after4, ������ 2.����� 
	if(ticket == 1 && ticket_time== 2 && treatment== 2 && age_group== 1) 
	{
		price = standard_after4_adult*treatment_disabled; 
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 2 && age_group== 2)
	{
		price = standard_after4_teen*treatment_disabled;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 2 && age_group== 3)
	{
		price = standard_after4_kid*treatment_disabled;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 2 && age_group== 4)
	{
		price = standard_after4_baby*treatment_disabled;
	}
    else if (ticket == 1 && ticket_time== 2 && treatment== 2 && age_group== 5)
	{
		price = standard_after4_senior*treatment_disabled;
	}
	
	//��ũ�̿��, day1, ������ 2.�����
	if(ticket == 2 && ticket_time== 1 && treatment== 2 && age_group== 1) 
	{
		price = park_day1_adult*treatment_disabled; 
	}
	else if (ticket == 2 && ticket_time== 1 && treatment== 2 && age_group== 2)
	{
		price = park_day1_teen*treatment_disabled; 
	}
	else if (ticket == 2 && ticket_time== 1 && treatment== 2 && age_group== 3)
	{
		price = park_day1_kid*treatment_disabled; 
	}
	else if (ticket == 2 && ticket_time== 1 && treatment== 2 && age_group== 4)
	{
		price = park_day1_baby*treatment_disabled; 
	}
    else if (ticket == 2 && ticket_time== 1 && treatment== 2 && age_group== 5)
	{
		price = park_day1_senior*treatment_disabled; 
	}
	
	//��ũ�̿��, after4,  ������ 2.�����
	if(ticket == 2 && ticket_time== 2 && treatment== 2 && age_group== 1) 
	{
		price = park_after4_adult*treatment_disabled; 
	}
	else if (ticket == 2 && ticket_time== 2 && treatment== 2 && age_group== 2)
	{
		price = park_after4_teen*treatment_disabled; 
	}
	else if (ticket == 2 && ticket_time== 2 && treatment== 2 && age_group== 3)
	{
		price = park_after4_kid*treatment_disabled; 
	}
	else if (ticket == 2 && ticket_time== 2 && treatment== 2 && age_group== 4)
	{
		price = park_after4_baby*treatment_disabled; 
	}
    else if (ticket == 2 && ticket_time== 2 && treatment== 2 && age_group== 5)
	{
		price = park_after4_senior*treatment_disabled; 
	} 
	////////////////////////////////////////////////////////////////////////////////


	//�����̿��, 1day, ������ 3. ����������  
		if(ticket == 1 && ticket_time== 1 && treatment== 3 && age_group== 1) 
	{
		price = standard_day1_adult*treatment_national;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 3 && age_group== 2)
	{
		price = standard_day1_teen*treatment_national;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 3 && age_group== 3)
	{
		price = standard_day1_kid*treatment_national;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 3 && age_group== 4)
	{
		price = standard_day1_baby*treatment_national;
	}
    else if (ticket == 1 && ticket_time== 1 && treatment== 3 && age_group== 5)
	{
		price = standard_day1_senior*treatment_national;
	}
	
	// �����̿��, after4, ������ 3.����������  
	if(ticket == 1 && ticket_time== 2 && treatment== 3 && age_group== 1) 
	{
		price = standard_after4_adult*treatment_national; 
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 3 && age_group== 2)
	{
		price = standard_after4_teen*treatment_national;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 3 && age_group== 3)
	{
		price = standard_after4_kid*treatment_national;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 3 && age_group== 4)
	{
		price = standard_after4_baby*treatment_national;
	}
    else if (ticket == 1 && ticket_time== 2 && treatment== 3 && age_group== 5)
	{
		price = standard_after4_senior*treatment_national;
	}
	
	//��ũ�̿��, day1, ������ 3.����������  
	if(ticket == 2 && ticket_time== 1 && treatment== 3 && age_group== 1) 
	{
		price = park_day1_adult*treatment_national; 
	}
	else if (ticket == 2 && ticket_time== 1 && treatment== 3 && age_group== 2)
	{
		price = park_day1_teen*treatment_national; 
	}
	else if (ticket == 2 && ticket_time== 1 && treatment== 3 && age_group== 3)
	{
		price = park_day1_kid*treatment_national; 
	}
	else if (ticket == 2 && ticket_time== 1 && treatment== 3 && age_group== 4)
	{
		price = park_day1_baby*treatment_national; 
	}
    else if (ticket == 2 && ticket_time== 1 && treatment== 3 && age_group== 5)
	{
		price = park_day1_senior*treatment_national; 
	}
	
	//��ũ�̿��, after4,  ������ 3. ����������  
	if(ticket == 2 && ticket_time== 2 && treatment== 3 && age_group== 1) 
	{
		price = park_after4_adult*treatment_national; 
	}
	else if (ticket == 2 && ticket_time== 2 && treatment== 3 && age_group== 2)
	{
		price = park_after4_teen*treatment_national; 
	}
	else if (ticket == 2 && ticket_time== 2 && treatment== 3 && age_group== 3)
	{
		price = park_after4_kid*treatment_national; 
	}
	else if (ticket == 2 && ticket_time== 2 && treatment== 3 && age_group== 4)
	{
		price = park_after4_baby*treatment_national; 
	}
    else if (ticket == 2 && ticket_time== 2 && treatment== 3 && age_group== 5)
	{
		price = park_after4_senior*treatment_national; 
	} 
	///////////////////////////////////////////////////////////////////////////////
	
	//�����̿��, 1day, ������ 4. �ް��庴
	 	if(ticket == 1 && ticket_time== 1 && treatment== 4 && age_group== 1) 
	{
		price = standard_day1_adult*treatment_military;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 4 && age_group== 2)
	{
		price = standard_day1_teen*treatment_military;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 4 && age_group== 3)
	{
		price = standard_day1_kid*treatment_military;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 4 && age_group== 4)
	{
		price = standard_day1_baby*treatment_military;
	}
    else if (ticket == 1 && ticket_time== 1 && treatment== 4 && age_group== 5)
	{
		price = standard_day1_senior*treatment_military;
	}
	
	// �����̿��, after4, ������ 4.�ް��庴  
	if(ticket == 1 && ticket_time== 2 && treatment== 4 && age_group== 1) 
	{
		price = standard_after4_adult*treatment_military; 
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 4 && age_group== 2)
	{
		price = standard_after4_teen*treatment_military;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 4 && age_group== 3)
	{
		price = standard_after4_kid*treatment_military;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 4 && age_group== 4)
	{
		price = standard_after4_baby*treatment_military;
	}
    else if (ticket == 1 && ticket_time== 2 && treatment== 4 && age_group== 5)
	{
		price = standard_after4_senior*treatment_military;
	} 	
	///////////////////////////////////////////////////////////////////////////////
	//�����̿��, 1day, ������ 5.�ӻ�� 
	if(ticket == 1 && ticket_time== 1 && treatment== 5 && age_group== 1) 
	{
		price = standard_day1_adult*treatment_pregnant;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 5 && age_group== 2)
	{
		price = standard_day1_teen*treatment_pregnant;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 5 && age_group== 3)
	{
		price = standard_day1_kid*treatment_pregnant;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 5 && age_group== 4)
	{
		price = standard_day1_baby*treatment_pregnant;
	}
    else if (ticket == 1 && ticket_time== 1 && treatment== 5 && age_group== 5)
	{
		price = standard_day1_senior*treatment_pregnant;
	}
	
	// �����̿��, after4, ������ 5.�ӻ��
	if(ticket == 1 && ticket_time== 2 && treatment== 5 && age_group== 1) 
	{
		price = standard_after4_adult*treatment_pregnant; 
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 5 && age_group== 2)
	{
		price = standard_after4_teen*treatment_pregnant;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 5 && age_group== 3)
	{
		price = standard_after4_kid*treatment_pregnant;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 5 && age_group== 4)
	{
		price = standard_after4_baby*treatment_pregnant;
	}
    else if (ticket == 1 && ticket_time== 2 && treatment== 5 && age_group== 5)
	{
		price = standard_after4_senior*treatment_pregnant;
	} 	 
	////////////////////////////////////////////////////////////////////////////
	//�����̿��, 1day, ������ 6.�ٵ��� �ູ ī��
	if(ticket == 1 && ticket_time== 1 && treatment== 6 && age_group== 1) 
	{
		price = standard_day1_adult*treatment_multichild;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 6 && age_group== 2)
	{
		price = standard_day1_teen*treatment_multichild;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 6 && age_group== 3)
	{
		price = standard_day1_kid*treatment_multichild;
	}
	else if (ticket == 1 && ticket_time== 1 && treatment== 6 && age_group== 4)
	{
		price = standard_day1_baby*treatment_multichild;
	}
    else if (ticket == 1 && ticket_time== 1 && treatment== 6 && age_group== 5)
	{
		price = standard_day1_senior*treatment_multichild;
	}
	
	// �����̿��, after4, ������ 6.�ٵ��� �ູ ī��
	if(ticket == 1 && ticket_time== 2 && treatment== 6 && age_group== 1) 
	{
		price = standard_after4_adult*treatment_multichild; 
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 6 && age_group== 2)
	{
		price = standard_after4_teen*treatment_multichild;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 6 && age_group== 3)
	{
		price = standard_after4_kid*treatment_multichild;
	}
	else if (ticket == 1 && ticket_time== 2 && treatment== 6 && age_group== 4)
	{
		price = standard_after4_baby*treatment_multichild;
	}
    else if (ticket == 1 && ticket_time== 2 && treatment== 6 && age_group== 5)
	{
		price = standard_after4_senior*treatment_multichild;
	} 	 	 
	
	printf("�� ����: %d\n���̱׷�: %d\n������%d�Դϴ�.\n�����մϴ�. ", age, age_group, price);
	
	
	return 0;
 } 
