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
	 
	
	
	//만 나이 계산  
	int today_year = (today/ 10000) + 100 ;
	int birth_year = birthday/ 10000;
	int year_dif = today_year - birth_year;
	
	int today_mmdd = today-(today/10000)*10000;
	int birth_mmdd = birthday -(birthday/10000)*10000;
	
	int age; //만 나이  
	 
	if (birth_mmdd <= today_mmdd){
		age = year_dif ; 
	}
	else { 
		age = year_dif -1 ;
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
	
	//우대사항 
	const float TREATMENT_DISABLED = 0.5;	//장애인 (종합,파크)
	const float TREATMENT_NATIONAL = 0.5;	//국가유공자 (종합,파크) 
	const float TREATMENT_MILITARY = 0.51;	//휴가장병 (종합) 
	const float TREATMENT_PREGNANT = 0.5;	//임산부 (종합) 
	const float TREATMENT_MULTICHILD = 0.7;	//다둥이 행복 카드 (종합) 
	
	
	//1day 티켓 가격  
	int price; 
	int isExit;
	
	do{
			//화면출력 
			printf("권종을 선택하세요.\n1.종합이용권\n2.파크이용권\n"); 
			scanf("%d", &ticket);
			printf("1Day와 After4 중 하나를 선택하세요.\n1.1Day\n2.After4\n");
			scanf("%d", &ticket_time);
			printf("주민번호 앞자리를 입력하세요.\n");
			scanf("%d", &birthday);
			printf("우대사항을 선택하세요.\n1.없음(나이 우대는 자동처리)\n2.장애인\n3.국가유공자\n4.휴가장병\n5.임산부\n6.다둥이행복카드\n");
			scanf("%d", &treatment);

			
			if (ticket == 1){				//종합이용권, 1day, 우대사항 없음
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
				
					if(treatment ==2){		//종합이용권, 1day, 우대사항 2.장애인 
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
					if(treatment ==3){		//종합이용권, 1day, 우대사항 3.국가유공자 
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
					if(treatment==4){		//종합이용권, 1day, 우대사항 4. 휴가장병  
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
					if(treatment==5){		//종합이용권, 1day, 우대사항 5. 임산부  
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
					if(treatment ==6){		//종합이용권, 1day, 우대사항 6.다둥이  
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
				
				if (ticket_time ==2){		//종합이용권, after4, 우대사항 없음
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
					if(treatment ==2){		// 종합이용권, after4, 우대사항 2.장애인 
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
					if(treatment ==3){		//종합이용권, after4, 우대사항 3.국가유공자 
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
					if(treatment==4){		//종합이용권, after4, 우대사항 4. 휴가장병  
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
					if(treatment==5){		//종합이용권, after4, 우대사항 5. 임산부  
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
					if(treatment ==6){		//종합이용권, after4, 우대사항 6.다둥이  
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
	
	
			if (ticket ==2){				//파크이용권, day1, 우대사항 없음 
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
					if(treatment ==2){		//파크이용권, day1, 우대사항 2.장애인 
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
					if(treatment ==3){		//파크이용권, day1, 우대사항 3.국가유공자  
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
				if (ticket_time==2){		//파크이용권, after4, 우대사항 없음
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
					if(treatment ==2){		//파크이용권, after4,  우대사항 2.장애인
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
					if(treatment ==3){		//파크이용권, after4, 우대사항 3.국가유공자  
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
		printf("만 나이: %d\n나이그룹: %d\n가격은 %d입니다.\n감사합니다. ", age, age_group, price);
		printf("계속 발권 하시겠습니까?\n1.티켓발권\n2.종료\n");
		scanf("%d",&isExit); 	
			
	}
	while (isExit <2);
		
	
	return 0;
}

	
	
	
	
 
