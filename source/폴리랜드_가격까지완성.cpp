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
		age = year_dif +1; 
	}
	else { 
		age = year_dif ;
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
	
	printf("�� ����: %d\n���̱׷�: %d\n����: %d", age, age_group, price);
	
	
	return 0;
 } 
