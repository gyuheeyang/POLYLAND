#include<stdio.h>

int main()
{
	
	//권종별 가격  
	const int STANDARD_DAY1_ADULT = 59000; const int STANDARD_DAY1_TEEN = 52000; const int STANDARD_DAY1_KID = 47000; const int STANDARD_DAY1_BABY = 15000; const int STANDARD_DAY1_SENIOR = 47000; 	
	const int STANDARD_AFTER4_ADULT= 48000; const int STANDARD_AFTER4_TEEN = 42000; const int STANDARD_AFTER4_KID  = 36000; const int STANDARD_AFTER4_BABY  = 15000; const int STANDARD_AFTER4_SENIOR  = 36000; 
	const int PARK_DAY1_ADULT = 56000; const int PARK_DAY1_TEEN = 50000; const int PARK_DAY1_KID = 46000; const int PARK_DAY1_BABY = 15000; const int PARK_DAY1_SENIOR = 46000;
	const int PARK_AFTER4_ADULT = 45000; const int PARK_AFTER4_TEEN = 40000; const int PARK_AFTER4_KID = 35000; const int PARK_AFTER4_BABY = 15000;  const int PARK_AFTER4_SENIOR = 35000;  
	 
	/*우대사항 
	const float TREATMENT_DISABLED = 0.5;	//장애인 (종합,파크)
	const float TREATMENT_NATIONAL = 0.5;	//국가유공자 (종합,파크) 
	const float TREATMENT_MILITARY = 0.51;	//휴가장병 (종합) 
	const float TREATMENT_PREGNANT = 0.5;	//임산부 (종합) 
	const float TREATMENT_MULTICHILD = 0.7;	//다둥이 행복 카드 (종합)  
	 */
	//////////////메인 구현////////////////
	 
	//권종  
	int ticket; //이용권 종류 
	int ticket_time; //1day after4
	int birthday; //주민번호 
	int treatment; //우대사항 
	int ticket_number; //티켓 수량  
	int price = 0; 
	int totalPrice = 0; 
	int isExit;
	
	int index = 0; //주문 내용 배열 탐색용 (position) 
	int array[100][5] = {0}; //주문 내역 저장
	
	for(;;){
		do{
			printf("권종을 선택하세요.\n1.종합이용권\n2.파크이용권\n"); 
			scanf("%d", &ticket);
			if (ticket ==1 || ticket==2)
			continue;
			printf("다시 선택해주세요.\n");
		} while (!(ticket ==1 || ticket ==2));
		array[index][0] = ticket; //배열 0번째  
		
		do{
			printf("1Day와 After4 중 하나를 선택하세요.\n1.1Day\n2.After4\n");
			scanf("%d", &ticket_time);
			if (ticket_time ==1 || ticket_time ==2)
			continue;
			printf("다시 선택해주세요.\n");
		}while (!(ticket_time ==1 || ticket_time ==2));
		array[index][1] = ticket_time; //배열 1번째 
		
		printf("주민번호 앞 6자리를 입력하세요.\n");
		scanf("%d", &birthday);
	
		do{	
			printf("몇개를 주문하시겠습니까?  (최대 10매)\n");
			scanf("%d",&ticket_number) ;
			if(ticket_number <= 10)
			continue; 
			printf("다시 선택해주세요.\n");
		}while (!(ticket_number <= 10));
		array[index][2] = ticket_number; //배열 2번째 
		
		do{
			printf("우대사항을 선택하세요.\n1.없음(나이 우대는 자동처리)\n2.장애인\n3.국가유공자\n4.휴가장병\n5.임산부\n6.다둥이행복카드\n");
			scanf("%d", &treatment);
			if(treatment == 1 || treatment == 2 || treatment == 3 || treatment == 4 || treatment == 5 || treatment == 6 )
			continue;
			printf("다시 선택해주세요.\n");	
		}while(!(treatment == 1 || treatment == 2 || treatment == 3 || treatment == 4 || treatment == 5 || treatment == 6 ) );
		array[index][3] = treatment; //배열 3번째  
		
		
		int discount;  
		
		switch (treatment){
			case (1):
				discount = 1; //할인이 되지 않으므로 1-0=1 
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
		
	
		///만나이 계산 
		int today = 220316 ; //오늘 날짜  
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
		//연령 그룹 
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
		array[index][4] = age_group; //배열 네번째
		
		///////////////////////////////////////////////////////////////
		if (ticket == 1){				//종합이용권, 1day
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
			else if (ticket_time ==2){		//종합이용권, after4
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
		else{				//파크이용권, day1
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
			else if (ticket_time==2){		//파크이용권, after4
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
		
		
		//가격*할인*티켓수  
		totalPrice = price * discount * ticket_number;
		array[index][5] = totalPrice;
		
		printf("만 나이: %d\n나이그룹: %d\n가격은 %d입니다.\n감사합니다. ", age, age_group, totalPrice);
		printf("계속 발권 하시겠습니까?\n1.티켓발권\n2.종료\n");
		scanf("%d",&isExit); 	
		
		if (isExit ==2){
			printf("발권 내역\n");
			printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","이용권 종류","이용 시간","발권 수량","우대 구분","연령","입장료 총액");
			printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s","(종합/파크)","(1Day/After4)"," (매) ","(1-6)","(번째) ","(원)");
			break;
		}
		else {
		index++;
		}
	}
	//반복 입력 가능케 무한 루프 
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
	
	printf("입장료 총액은 %d입니다.",sum);
	
		
return 0;	
}










