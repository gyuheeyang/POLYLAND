#include<stdio.h>
#include<time.h> //시간, 날짜에 대한 함수를 가지고 있음 

int main()
{
	//권종별 가격  
	const int STANDARD_DAY1_ADULT = 59000, STANDARD_DAY1_TEEN = 52000, STANDARD_DAY1_KID = 47000, STANDARD_DAY1_BABY = 15000, STANDARD_DAY1_SENIOR = 47000, 
			  STANDARD_AFTER4_ADULT= 48000, STANDARD_AFTER4_TEEN = 42000, STANDARD_AFTER4_KID  = 36000, STANDARD_AFTER4_BABY  = 15000, STANDARD_AFTER4_SENIOR  = 36000, 
			  PARK_DAY1_ADULT = 56000, PARK_DAY1_TEEN = 50000, PARK_DAY1_KID = 46000, PARK_DAY1_BABY = 15000, PARK_DAY1_SENIOR = 46000,
			  PARK_AFTER4_ADULT = 45000, PARK_AFTER4_TEEN = 40000, PARK_AFTER4_KID = 35000, PARK_AFTER4_BABY = 15000, PARK_AFTER4_SENIOR = 35000;  

	//권종  
	int ticket; //이용권 종류 
	int ticketTime; //1day after4
	int birthday; //주민번호 
	int ageGroup;
	int treatment; //우대사항 
	int ticketNumber; //티켓 수량  
	int price = 0; 
	int totalPrice = 0; 
	int finalPrice = 0;
	int again;
	int newOrder; 
	int counter = 0; //주문 내용 배열 탐색용 (position) 
	int today;
	int age;
	int todayDate;
	float discount;  //int에서  flaot으로 수정함  
	int treatmentGroup;
	
	//시간 불러오기 
	time_t timer;
	struct tm* t; //struct tm 구조체 안에는 int 가 들어가 있다 ex) int tm_min; int tm_hour; int tm_year; 등등  
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

	do{ //다음 손님 받기 위한 do while 반복  
		int ticketArr[20] = {0}, ticketTimeArr[20] = {0}, treatmentArr[20] = {0}, ticketNumberArr[20] = {0},
			priceArr[20] = {0}, totalPriceArr[20] = {0} , ageGroupArr[20] = {0} , treatmentGroupArr[20]= {0};
			// 초기화 위해서 do while 문 안에 넣음  
		do{ 
			printf("롯데월드 매표 시스템");
			do{
				printf("\n권종을 선택하세요.\n1.종합이용권\n2.파크이용권\n"); 
				scanf("%d", &ticket);
				if (ticket ==1 || ticket==2)
				continue;
				printf("다시 선택해주세요.\n");
			} while (!(ticket ==1 || ticket ==2));
			
			do{
				printf("1Day와 After4 중 하나를 선택하세요.\n1.1Day\n2.After4\n");
				scanf("%d", &ticketTime);
				if (ticketTime ==1 || ticketTime ==2)
				continue;
				printf("다시 선택해주세요.\n");
			}while (!(ticketTime ==1 || ticketTime ==2));
				
			printf("주민번호 앞 6자리를 입력하세요.\n");
			scanf("%d", &birthday);
				
			do{
				printf("우대사항을 선택하세요.\n1.없음(나이 우대는 자동처리)\n2.장애인\n3.국가유공자\n4.휴가장병\n5.임산부\n6.다둥이행복카드\n");
				scanf("%d", &treatment);
				if(treatment == 1 || treatment == 2 || treatment == 3 || treatment == 4 || treatment == 5 || treatment == 6 )
				continue;
				printf("다시 선택해주세요.\n");	
			}while(!(treatment == 1 || treatment == 2 || treatment == 3 || treatment == 4 || treatment == 5 || treatment == 6 ) );		
			
	
			do{	
				printf("몇개를 주문하시겠습니까?  (최대 10매)\n");
				scanf("%d",&ticketNumber) ;
				if(ticketNumber <= 10)
				continue; 
				printf("다시 선택해주세요.\n");
			}while (!(ticketNumber <= 10));
			

			//시간 입력 
			todayDate= (t->tm_year + 1900)*10000 + (t->tm_mon + 1)*100 + t->tm_mday;  
			// 위의 줄은 20220101 형태로 변형하기 위함  
			
			///만나이 계산 
			//todayDate: 20220323
			today = todayDate- 20000000 + 1000000; //ex)220323 + 1000000 
			//birthday = 951127 
		
			//만 나이  
			age = (today-birthday)/10000;
			if (age > 100){
				age = age - 100;
			} 
	
			//연령 그룹
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
			else {    //(65 < age) 삭제함  
				ageGroup =5; //senior
			}
	
				
				if (ticket == 1){				//종합이용권, 1day
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
					else if (ticketTime ==2){		//종합이용권, after4
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
				else{				//파크이용권, day1
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
					else if (ticketTime==2){		//파크이용권, after4
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
				
				//우대사항 적용
				
			
				switch (treatment){
					case (1):
						discount = 1; //할인이 되지 않으므로 1-0=1 
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
				
				//최종가격 
				totalPrice =  price*ticketNumber*discount;  
		
				if (totalPrice == 0){
					printf("\n무료 입장 입니다.\n");
				}
				else {
					printf ("\n%d매의  총금액은 %d원 입니다.\n",ticketNumber, totalPrice) ;
				}
		
				//선택사항 별, 행렬에 담기
				ticketArr[counter] = ticket;
				ticketTimeArr[counter] = ticketTime ;
				treatmentArr[counter] = treatment;
				ticketNumberArr[counter] = ticketNumber;
				priceArr[counter] = price;
				totalPriceArr[counter] = totalPrice;
				treatmentGroupArr[counter] = treatmentGroup;
				ageGroupArr[counter] = ageGroup;
				finalPrice += totalPrice;
				//counter에 1추가, 초기값은 0 
				counter++; 
		
				//이어서 예매할지 선택 
				printf("\n이어서 이용권을 구매하시겠습니까?\n1.예\n2.아니요\n");
				scanf("%d",&again); 
			}while(again == 1);
		
			
			/////파일로 출력하는 부분 수정, printf로 저장 
			FILE *filePointer = fopen("report.csv","a");	 
			fprintf(filePointer, "날짜, 권종, 권종시간, 연령, 수량, 가격, 우대사항\n");
			
			// 영수증 출력  
			printf("종합/파크\t1day/after\t연령\t매수\t가격\t우대사항\n");
			for (int i =0; i<counter; i++){				
				fprintf(filePointer,"%d,%d,%d,%d,%d,%d,%d\n",
								todayDate,ticketArr[i],ticketTimeArr[i],ageGroupArr[i],ticketNumberArr[i],totalPriceArr[i],treatmentGroupArr[i]);	
				
				switch (ticketArr[i]) {
				case 1:
					printf("\t종합이용권");
					break;
				case 2:
					printf("\t파크이용권");
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
						printf("\t어  른");
						break;
					case 2:
						printf("\t청소년");
						break;
					case 3:
						printf("\t어린이");
						break;
					case 4:
						printf("\t유  아");
						break;
					case 5:
						printf("\t노  인");
						break;
					default:
						break;
				}	
			
				printf("%d개 %d원",ticketNumberArr[i], totalPriceArr[i]) ; //매수   
					
				switch (treatmentGroupArr[i]) {
					case 1:
						printf("%s\n","우대사항 없음");
						break;
					case 2:
						printf("%s\n","장애인 우대");
						break;
					case 3:
						printf("%s\n","국가유공자 우대");
						break;
					case 4:
						printf("%s\n","휴가장병 우대");
						break;
					case 5:
						printf("%s\n","임산부 우대");
						break;
					case 6:
						printf("%s\n","다둥이 행복카드 우대");
						break;
					default:
						break;
				}		
		}
		printf("\n입장료 총액은 %d원 입니다.", finalPrice);

		printf("\n새로운 주문을 받겠습니까?\n1.예\n2.종료\n");
		scanf("%d", &newOrder);
		 
		fclose(filePointer);
		
		counter = 0; 
		finalPrice = 0;	
	}while (newOrder == 1);
	
	return 0; 
}

