#include<stdio.h>
int main()
{
	//권종  
	int ticket; //이용권 종류 
	int ticket_time; //1day after4
	int birthday; //주민번호 
	int treatment; //우대사항 
	int today = 220316 ; //오늘 날짜   
	 
	//티켓가격 
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
	 
	printf("권종을 선택하세요.\n1.종합이용권\n2.파크이용권\n"); 
	scanf("%d", &ticket);
	printf("1Day와 After4 중 하나를 선택하세요.\n1.1Day\n2.After4\n");
	scanf("%d", &ticket_time);
	printf("주민번호 앞자리를 입력하세요.\n");
	scanf("%d", &birthday);
	printf("우대사항을 선택하세요.\n1.없음(나이 우대는 자동처리)\n2.장애인\n3.국가유공자\n4.휴가장병\n5.임산부\n6.다둥이행복카드\n");
	scanf("%d", &treatment);
    
	
	
	//만 나이 계산  
	int today_year = (today/ 10000) + 100 ;
	int birth_year = birthday/ 10000;
	int year_dif = today_year - birth_year;
	
	int today_mmdd = today-(today/10000)*10000;
	int birth_mmdd = birthday -(birthday/10000)*10000;
	
	int age; //만 나이  
	 
	if (birth_mmdd <= today_mmdd){
		age = year_dif +1; 
	}
	else { 
		age = year_dif ;
	}
	
	if (age > 100){
		age = age - 100;
	}
	
	

	//나이 그룹  
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
	
	
	
	//1day 티켓 가격  
	int price; 
	
	//종합이용권, 1day, 우대사항 없음
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
	
	
	
	//종합이용권, after4, 우대사항 없음
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
		
	
	//파크이용권, day1, 우대사항 없음 
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
	
	//파크이용권, after4, 우대사항 없음
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
	
	printf("만 나이: %d\n나이그룹: %d\n가격: %d", age, age_group, price);
	
	
	return 0;
 } 
