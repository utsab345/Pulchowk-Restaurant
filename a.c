#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void add();  //FUNCTIONS
void list();
void edit();  //GLOBALLY DECLARED FUNCTIONS N VARIABLE
void delete1();
void search();
void out(void);
int main1();

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);

	SetConsoleTextAttribute(hStdOut,wColor);
}
}
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
char current_username[10] = "";
char current_password[10] = "";

void login();
void signup() {
	int i=0;
    FILE *f;
    char uname[20], pword[20],c=' ';
    char existing_uname[20], existing_pword[20];
    int found = 0;

    system("cls");
    printf("\n  **************************  SIGNUP FORM  **************************  ");
    printf(" \n                       CREATE USERNAME:");
    scanf("%s", uname);
    printf(" \n                       CREATE PASSWORD:");
     while(i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if(c == 13) break;
            else printf("*");
            i++;
        }
        pword[i] = '\0';

    f = fopen("users.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s", existing_uname, existing_pword) == 2) {
            if (strcmp(uname, existing_uname) == 0) {
                found = 1;
                break;
            }
        }
        fclose(f);
    } else {
        printf("\n\n       Error in accessing user data. Please try again later.\n");
        return;
    }

    if (found) {
        printf("\n\n       Username already exists! Please again Sign up or login\n");
		
	gotoxy(6,15);
/*making horizontal line from x=6 & y=6*/
/* here \xb2 is the hex characters*/
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(6,16);
printf("\xb2\xb2");   /*making vertical line from x=6 & y=7*/
gotoxy(6,17);
printf("\t   1.SIGNUP");
gotoxy(6,17);
printf("\xb2\xb2");
gotoxy(6,18);
printf("\xb2\xb2");
gotoxy(6,19);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(27,16);/* making another vertical line */
printf("\xb2\xb2");
gotoxy(27,17);
printf("\xb2\xb2");
gotoxy(27,18);
printf("\xb2\xb2");
/*for another right rectangular box at x=32 & y=6*/
gotoxy(45,15);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(45,16);
printf("\xb2\xb2");
gotoxy(45,17);
printf("\t   2. LOGIN");
gotoxy(45,17);
printf("\xb2\xb2");
gotoxy(45,18);
printf("\xb2\xb2");
gotoxy(45,19);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(66,16);
printf("\xb2\xb2");
gotoxy(66,17);
printf("\xb2\xb2");
gotoxy(66,18);
printf("\xb2\xb2");
/*for third middle box*/
gotoxy(29,20);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(29,21);
printf("\xb2\xb2");
gotoxy(29,22);
printf("\t 3. EXIT");
gotoxy(29,22);
printf("\xb2\xb2");
gotoxy(29,23);
printf("\xb2\xb2");
gotoxy(29,24);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(43,21);
printf("\xb2\xb2");
gotoxy(43,22);
printf("\xb2\xb2");
gotoxy(43,23);
printf("\xb2\xb2");
gotoxy(20,26);
printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");


	gotoxy(20,32);
printf("Enter your choice");
gotoxy(6,36);

gotoxy(38,28);
switch(getch())
{
	case '1':
		signup();
        
		break;
		case '2':
			login();
            main1();
			break;
            
			case '3':
				out();
				break;
                
				default:
					system("cls");
			gotoxy(6,15);
				printf("\aInvalid Input!!!\n\n");
				printf("\tPlease Enter 1,2,3 or 4 . Starting the main module in 5 seconds>>>>");
Sleep(5000);
system("cls");
// goto l;
	main1();			
}
		// signup();
		// login();
		// main1();
    } else {
        f = fopen("users.txt", "a");
        if (f != NULL) {
            fprintf(f, "%s %s\n", uname, pword);
            fclose(f);
            printf("\n\n       SIGNUP SUCCESSFUL! You can now login with your new credentials.\n");
        login();
		main1();
		} else {
            printf("\n\n       Error in creating user. Please try again later.\n");
        }
    }
}
void login() {
    int a = 0;
    char uname[10], pword[10], c;
    FILE *f;

    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf("\n                       ENTER USERNAME: ");
    scanf("%s", uname);

    printf(" \n                      ENTER PASSWORD: ");
    int i = 0;
    while ((c = getch()) != '\r' && i < 10) { // Read password until Enter is pressed or maximum length is reached
        pword[i++] = c;
        printf("*");
    }
    pword[i] = '\0'; // Null-terminate the password string

    f = fopen("users.txt", "r");
    if (f != NULL) {
        char user[10], pass[10];
        while (fscanf(f, "%s %s", user, pass) == 2) {
            if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0) {
                printf("\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
                a = 1;
                break;
            }
        }
        fclose(f);
    }

    if (!a) {
        printf("\n        SORRY !!!!  LOGIN IS UNSUCCESSFUL");
        printf("\n        Please Signup with new credentials\n");
        getch();
        signup(); // After unsuccessful login, offer signup option
    }
}


struct CustomerDetails   //STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];	
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;

int main(){     // MAIN FUNCTION	
	int i=0;
	
	time_t t;
	time(&t);
	char customername;
	char choice;

	system("cls");   // FOR CLEARING SCREEN
	setcolor(15);
	printf("                      -------------------------------------------------------------------------\n");
	printf("                     |                                                                         |\n");      
	printf("                     |                                                                         |\n");
	printf("                     |  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
	printf("                     |  O        O    O O      O        O      O    O O    O O        O        |\n");
	printf("                     |  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
	printf("                     |  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
	printf("                     |  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
	printf("                     |                                                                         |\n");                       
	printf("                      -------------------------------------------------------------------------\n");
 	printf("                     \t\t*************************************************\n");
	printf("                     \t\t*                                               *\n");
	printf("                     \t\t*       ------------------------------------    *\n");
	printf("                     \t\t*        WELCOME TO PULCHOWKALAYA RESTAURANT    *\n");
	printf("                     \t\t*       ------------------------------------    *\n");
	printf("                     \t\t*                                               *\n");
	printf("                     \t\t*                                               *\n");
	printf("                     \t\t*                                               *\n");
	printf("                     \t\t*************************************************\n\n\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue:");
	
	getch();	
    system("cls");
	gotoxy(6,6);
/*making horizontal line from x=6 & y=6*/
/* here \xb2 is the hex characters*/
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(6,7);
printf("\xb2\xb2");   /*making vertical line from x=6 & y=7*/
gotoxy(6,8);
printf("\t   1.SIGNUP");
gotoxy(6,8);
printf("\xb2\xb2");
gotoxy(6,9);
printf("\xb2\xb2");
gotoxy(6,10);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(27,7);/* making another vertical line */
printf("\xb2\xb2");
gotoxy(27,8);
printf("\xb2\xb2");
gotoxy(27,9);
printf("\xb2\xb2");
/*for another right rectangular box at x=32 & y=6*/
gotoxy(45,6);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(45,7);
printf("\xb2\xb2");
gotoxy(45,8);
printf("\t   2. LOGIN");
gotoxy(45,8);
printf("\xb2\xb2");
gotoxy(45,9);
printf("\xb2\xb2");
gotoxy(45,10);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(66,7);
printf("\xb2\xb2");
gotoxy(66,8);
printf("\xb2\xb2");
gotoxy(66,9);
printf("\xb2\xb2");
/*for third middle box*/
gotoxy(29,11);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(29,12);
printf("\xb2\xb2");
gotoxy(29,13);
printf("\t 3. EXIT");
gotoxy(29,13);
printf("\xb2\xb2");
gotoxy(29,14);
printf("\xb2\xb2");
gotoxy(29,15);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(43,12);
printf("\xb2\xb2");
gotoxy(43,13);
printf("\xb2\xb2");
gotoxy(43,14);
printf("\xb2\xb2");
gotoxy(20,17);
printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");


	gotoxy(20,23);
printf("Enter your choice");
gotoxy(6,27);

gotoxy(38,19);
switch(getch())
{
	case '1':
		signup();
        
		break;
		case '2':
			login();
            main1();
			break;
            
			case '3':
				out();
				break;
                
				default:
					system("cls");
			gotoxy(6,6);
				printf("\aInvalid Input!!!\n\n");
				printf("\tPlease Enter 1,2,3 or 4 . Starting the main module in 5 seconds>>>>");
Sleep(5000);
system("cls");
// goto l;
	main1();			
}
}
int main1(){
	int i=0;
	
	time_t t;
	time(&t);
	char customername;
	char choice;
    system("cls");
	while (1)      // INFINITE LOOP
	{
		system("cls");
		setcolor(10);
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		setcolor(10);
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book a room");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
		
		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{	
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				out();
				break;
				
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}

void add()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&s.period);
		
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;
			
	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ROOM    ");
	printf("NAME\t ");
	printf("\tADDRESS ");
	printf("\tPHONENUMBER ");
	
	
	printf("\t\t  PERIOD ");

	
	for(i=0;i<110;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		
		printf("\n%s \t%s \t\t%s \t\t%s     \t     %s  ",s.roomnumber, s.name , s.address , s.phonenumber ,s.period);
	}
	printf("\n");
	for(i=0;i<110;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       
		printf("\n\n Records of Customer in this  Room number is not found!!");
		
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
		
		
			printf("\nPeriod:\t%s",s.period);
			
			flag=0;
			break;
		}
	}
	if(flag==1){	
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}
void edit() {
    FILE *f;
    struct CustomerDetails s;
    char roomnumber[20];
    int found = 0;

    system("cls");
    printf("Enter Room number of the customer to edit: ");
    scanf("%s", roomnumber);

    f = fopen("add.txt", "r+");
    if (f == NULL) {
        printf("Error in opening file.\n");
        exit(1);
    }

    while (fread(&s, sizeof(s), 1, f) == 1) {
        if (strcmp(s.roomnumber, roomnumber) == 0) {
            found = 1;
            printf("\nEnter New Room Number     : ");
            scanf("%s", s.roomnumber);
            printf("Enter Name    : ");
            scanf("%s", s.name);
            printf("Enter Address        : ");
            scanf("%s", s.address);
            printf("Enter Phone number : ");
            scanf("%s", s.phonenumber);
            printf("Enter Period : ");
            scanf("%s", s.period);

            fseek(f, -sizeof(s), SEEK_CUR); // Move back to the beginning of the record
            fwrite(&s, sizeof(s), 1, f);
            printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!\n");
            break;
        }
    }

    if (!found) {
        printf("\n\nTHE RECORD DOESN'T EXIST!!!!\n");
    }

    fclose(f);
}

void out(void) {
    int i;
    char thanks[1000] = "Thanks for using Pulchowkalaya Restaurant!!!";
    char d[100] = "Developed By:";
    char v[1000] = "|Utsab Dahal| |Sameer Chaulagain| |Abiral Panta| |Amit Acharya|";

    system("cls");
    gotoxy(23, 5);

    for (i = 0; i < 45; i++) {
        Sleep(50);
        printf("%c", thanks[i]);
    }
    gotoxy(23, 6);
    for (i = 0; i < 31; i++) {
        Sleep(50);
        printf("%c", d[i]);
    }
    gotoxy(30, 7);
    for (i = 0; i < strlen(v); i++) {
      
            Sleep(40);
            printf("%c", v[i]);
        
    }

    gotoxy(30, 13);
    printf("Exiting in 5 seconds......>>>>>>>>");
    Sleep(5000);
    printf("\a"); /*making a alert sound*/
    exit(0);
}

