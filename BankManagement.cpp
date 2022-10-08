#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<fstream.h>
#include<string.h>
#include<ctype.h>
#include<dos.h> 


class graphics
 {
	char pass[20];
       public:
	graphics()			      //constructor
	{
	strcpy(pass,"bank");
	};
	void gr1();
	void login ();
	void reset(char []);
	void blink(int,int);

 };


class bank
 {
     int  account_no,age;
     float balance,initial_deposit;
     char name[40],address[40];
 public:

     void transactions();
     void open_new_account();
     void list_of_accounts();
     void see_account();
     void edit_account();
 }b;





class file
 {
     int counter;
   public:
     void write_to_file(int pos=0);
     void read_from_file(int ct=0);
     int count_records();
 };

class menu
 {
 int choice;
  public:
  void show_menu();
  int toggle(int,int);
 } ;

void main()
{
  clrscr();
  graphics g;
  menu m;
  int gdriver = DETECT, gmode;
  initgraph(&gdriver,&gmode,"");
  setfillstyle(XHATCH_FILL,9);
  floodfill(getmaxx()/2,getmaxy()/2,9);
  delay(800);
  g.login();
  m.show_menu();
  closegraph();
  getch();
}

/*****************************FUNCTIONS OF CLASS GRAPHICS***************************/
void graphics::gr1()
{
 cleardevice();
 setcolor(15);
 setbkcolor(0);
 rectangle(250,50,350,150);
 line(300,50,300,150);
 line(250,100,350,100);
 setfillstyle(LINE_FILL,9);
 floodfill(275,70,15);
 floodfill(330,120,15);
 setfillstyle(BKSLASH_FILL,9);
 rectangle(5,5,633,180);
 setfillstyle(WIDE_DOT_FILL,15);
 floodfill(100,100,15);
 settextstyle(0,0,2);
 setbkcolor(0);
 setcolor(4);
 outtextxy(230,250,"T n M BANK");
 settextstyle(0,0,3/2);
 setcolor(15);
 outtextxy(205,337,"LOADING . . .");
 setcolor(4);
 setcolor(15);
 rectangle(200,288,401,319) ;
 setfillstyle(SOLID_FILL,4);
for(int i=2;i<=100;i++)
  {
   setcolor(4);
   rectangle(202,290,200+(2*i),317);
   floodfill(201+(2*(i-1)),300,4);
   setcolor(15);
   gotoxy(38,22);
   cout<<i<<" %";
   delay(70);
  }
outtextxy(180,370,"LOADING COMPLETE");
outtextxy(180,400,"PRESS ANY KEY TO CONTINUE..");
getch();
clrscr();
setbkcolor(0);
}

void graphics::login()
{
 cleardevice();
 setbkcolor(BLACK);
  setcolor(15);
  char password[25]="";
  rectangle(200,150,430,200);
  outtextxy(210,170,"Enter password: ");
  char ch;
  int k=0,i=340;
  do
  {
  ch=getch();
  if(ch==13)
  break;
  password[k]=ch;
  outtextxy(i,170,"*");
  ++k;  i+=10;
  }
while(ch!=13);


 if(strcmp(password,pass)==0)
   {
	outtextxy(210,230,"Password Accepted..");
	settextstyle(0,0,2);
	delay(800);
	clrscr();
	setcolor(10);
	gr1();
   }
   else
   {
     setcolor(15);
     outtextxy(210,270,"Invalid password.....");
     outtextxy(210,320,"Press Enter To TRY AGAIN");
     outtextxy(210,350,"Any other key to EXIT");
     char ch=getch();
      if(ch=='\r')
	{
	 reset(password);
	}
      else
	{
	clrscr();
	exit(0);
	}
   }
}

void graphics::reset(char pass[15])
{
strcpy(pass,"");
login();
}

void graphics::blink(int x_pos,int y_pos)
{
 while(!kbhit())
 {
  setcolor(15);
  outtextxy(x_pos,y_pos,"_");
  delay(400);
  setcolor(0);
  outtextxy(x_pos,y_pos,"_");
  delay(400);
 }
}

/***************************FUNCTIONS OF CLASS BANK  *********************************/
/* Screen to open new account */

void bank::open_new_account()
{
setcolor(15);
cleardevice();
graphics g;
file f;
menu m;
rectangle(20,10,600,80);
outtextxy(270,42,"OPEN NEW ACCOUNT");
moveto(getmaxx()/2,100);
lineto(getmaxx()/2,370);
outtextxy(25,130,"NAME : ");
outtextxy(25,160,"ADDRESS : ");
outtextxy(25,190,"AGE : ");
outtextxy(25,220,"INITIAL DEPOSIT : ");
line(20,370,600,370);
int ct=f.count_records();
outtextxy(200,390,"ACCOUNT NUMBER : ") ;
gotoxy(45,25);
cout<<ct;
setcolor(15);
g.blink(350,130);
gotoxy(45,9);
gets(name);

g.blink(350,160);
gotoxy(45,11);
gets(address);

g.blink(350,190);
gotoxy(45,13);
cin>>age;

g.blink(350,220);
gotoxy(45,15);
cin>>initial_deposit;

account_no = ct;
balance=initial_deposit;
setcolor(15);

f.write_to_file(ct-1);
outtextxy(5,405,"CREATING ACCOUNT...PLEASE WAIT...");
delay(1000);
outtextxy(5,420,"YOUR ACCOUNT HAS BEEN CREATED SUCCESSFULLY");
getch();
m.show_menu();
}
*/ List of all accounts 
void bank::list_of_accounts()
{
setcolor(15);
cleardevice();
file f;
menu m;
int x,y=10;
line(2,50,640,50);
rectangle(2,2,getmaxx()-4,getmaxy()-2);
outtextxy(245,22,"LIST OF ALL ACCOUNTS");
int d1, m1, y1 ;
struct date d;
getdate(&d);           		//Inbuilt function to display current
d1 = d.da_day ;			//date of the system
m1 = d.da_mon ;
y1 = d.da_year ;
outtextxy(30,67,"DATE : ");
gotoxy(13,5);
cout<<d1<<" / "<<m1<<" / "<<y1;
line(2,82,640,82);
line(2,115,640,115);
outtextxy(19,95," ACCOUNT NO.");
line(140,85,140,465);
outtextxy(180,95," NAME ");
line(280,85,280,465);
outtextxy(300,95," BALANCE ");
line(380,85,380,465);
outtextxy(440,95,"ADDRESS");
int a=0,c=f.count_records();
while(a<c-1)
{
f.read_from_file(a);
++a;
x=7;
gotoxy(x,y);
cout<<account_no;
gotoxy(x+=13,y);
puts(name);
gotoxy(x+=20,y);
cout<<balance;
gotoxy(x+=10,y);
puts(address);
y+=3;
}
getch();
m.show_menu();
}
/* List all transactions, given an account */
void bank::transactions()
{
menu m;
graphics g;
file f;
setcolor(15);
setbkcolor(0);
cleardevice();
int acc_no;
outtextxy(50,50,"ENTER YOUR ACCOUNT NUMBER : ");
outtextxy(520,40," 0 => QUIT");
g.blink(270,50);
gotoxy(35,4);
cin>>acc_no;
if(acc_no==0)
exit(0);
int ct=f.count_records();
int a=0;
while(a<=ct)
{
f.read_from_file(a);
++a;         			      //a is the number of records read
if(acc_no==account_no)
{
cleardevice();
setcolor(15);
rectangle(0,10,630,80);
outtextxy(280,45,"TRANSACTIONS");
rectangle(3,120,630,400);
outtextxy(20,100," DATE : ");
gotoxy(11,7);
int d1, m1, y1 ;
struct date d;
getdate(&d);           		//Inbuilt function to display current
d1 = d.da_day ;			//date of the system
m1 = d.da_mon ;
y1 = d.da_year ;
cout<<d1<<" / "<<m1<<" / "<<y1;
outtextxy(20,145,"ACCOUNT NUMBER : ");
gotoxy(20,10);
cout<<acc_no;
rectangle(120,180,500,270);
outtextxy(130,200," NAME : ");
gotoxy(25,13);
puts(name);
outtextxy(130,240," ADDRESS : ");
gotoxy(27,16);
puts(address);
outtextxy(20,290," LAST BALANCE: ");
gotoxy(20,19);
cout<<balance;
outtextxy(20,320," DEPOSIT(d)/ WITHDRAW(w) : ");
g.blink(260,320);
gotoxy(31,21);
char choice;
float amount;
cin>>choice;
choice=tolower(choice);
setcolor(15);
outtextxy(110,350," ENTER AMOUNT : ");
g.blink(260,360);
gotoxy(30,23);
cin>>amount;
switch(choice)
{
case 'd':  balance+=amount;
	   setcolor(getmaxcolor());
	   outtextxy(100,390," NEW BALANCE : ");
	   gotoxy(30,25);
	   cout<<balance;
	   break;

case 'w':  balance-=amount;
	   setcolor(getmaxcolor());
	   if(amount>balance)
	    {
	      outtextxy(20,400," INVALID ...");
	      getch();
	      m.show_menu();
	    }
	   outtextxy(100,390," NEW BALANCE : ");
	   gotoxy(23,25);
	   cout<<balance;
	   break;
}
ofstream fout("records.txt",ios::ate);
int location=(a-1)*sizeof(b);
fout.seekp(location);
fout.write((char*)&b,sizeof(b));
break;
}
}
getch();
m.show_menu();
}

/* See details of bank and amount, given an account number */

void bank::see_account()
{
menu m;
graphics g;
file f;
setcolor(15);
setbkcolor(0);
cleardevice();
int acc_no;
outtextxy(50,50,"ENTER YOUR ACCOUNT NUMBER : ");
outtextxy(520,40," 0 => QUIT");
g.blink(270,50);
gotoxy(35,4);
cin>>acc_no;
if(acc_no==0)
exit(0);
int ct=f.count_records(),a=0;
while(a<=ct)
{
f.read_from_file(a);
++a;         			      //a is the number of records read
if(acc_no==account_no)
{
cleardevice();
setcolor(15);
rectangle(0,10,630,80);
outtextxy(280,45,"SEE ACCOUNT");
rectangle(3,120,630,400);
outtextxy(20,100," DATE : ");
gotoxy(11,7);
int d1, m1, y1 ;
struct date d;
getdate(&d);           		//Inbuilt function to display current
d1 = d.da_day ;			//date of the system
m1 = d.da_mon ;
y1 = d.da_year ;
cout<<d1<<" / "<<m1<<" / "<<y1;
outtextxy(20,145,"ACCOUNT NUMBER : ");
gotoxy(20,10);
cout<<acc_no;
rectangle(120,180,500,270);
outtextxy(130,200," NAME : ");
gotoxy(25,13);
puts(name);
outtextxy(130,230," ADDRESS : ");
gotoxy(27,15);
puts(address);
outtextxy(20,290," LAST BALANCE: ");
gotoxy(20,19);
cout<<balance;
break;
}
}
getch();
m.show_menu();
}

/* Edit address of an account, given account number */
void bank::edit_account()
{
menu m;
graphics g;
file f;
setcolor(15);
setbkcolor(0);
cleardevice();
int acc_no;
outtextxy(50,50,"ENTER YOUR ACCOUNT NUMBER : ");
outtextxy(520,40," 0 => QUIT");
g.blink(270,50);
gotoxy(35,4);
cin>>acc_no;
if(acc_no==0)
exit(0);
int ct=f.count_records(),a=0,pos;
while(a<=ct)
{
pos=a;
f.read_from_file(a);
++a;         			      //a is the number of records read
if(acc_no==account_no)
{
cleardevice();
setcolor(15);
rectangle(0,10,630,80);
outtextxy(280,45,"EDIT ACCOUNT");
rectangle(3,120,630,400);
outtextxy(20,100," DATE : ");
gotoxy(11,7);
int d1, m1, y1 ;
struct date d;
getdate(&d);           		//Inbuilt function to display current
d1 = d.da_day ;			//date of the system
m1 = d.da_mon ;
y1 = d.da_year ;
cout<<d1<<" / "<<m1<<" / "<<y1;
outtextxy(130,200,"ACCOUNT NUMBER : ");
gotoxy(34,13);
cout<<acc_no;
rectangle(120,180,500,270);
outtextxy(130,245,"NAME : ");
gotoxy(27,16);
puts(name);
outtextxy(20,290," ENTER NEW NAME : ");
outtextxy(20,325," ENTER NEW ADDRESS : ");
g.blink(185,290);
gotoxy(22,19);
gets(name);
g.blink(180,330);
gotoxy(24,21);
gets(address);
f.write_to_file(pos);
outtextxy(20,410,"Your changes have been saved");
break;
}
}
getch();
m.show_menu();
}

/*************************** FUNCTIONS OF CLASS FILE ***********************************/

void file::write_to_file(int pos)
{
ofstream fout;
fout.open("records.txt",ios::out|ios::ate);
int location=pos*(sizeof(b));
fout.seekp(location);
fout.write((char*)&b,sizeof(b));
fout.close();
}


void file::read_from_file(int ct)
{
ifstream fin;
fin.open("records.txt",ios::in);
fin.seekg((ct*sizeof(b)),ios::beg);
fin.read((char*)&b,sizeof(b));
}

int file::count_records()
{
 ifstream fin;
 counter=0;
 fin.open("records.txt",ios::in);

 fin.seekg(0);
 while(!fin.eof())
 {
  fin.read((char*)&b,sizeof(b));
  ++counter;
 }
 fin.close();
return counter;
}

/*************************** FUNCTIONS OF CLASS MENU ***************************/


void menu::show_menu()
{
 file f;
 menu m;
 choice=1;
 char ch;
 int x_pos=0,y_pos=30;
 int x=getmaxx(),y=70;
 cleardevice();
 setcolor(15);
 settextstyle(0,0,1);
 outtextxy(260,45,"B A N K I N G");
 while(x_pos!=640)
  {
   moveto(x_pos,y_pos);
   putpixel(x_pos+=10,y_pos,15);
   moveto(x,y);
   putpixel(x-=10,y,15);
   delay(40);
  }
 rectangle(230,100,430,140);
 rectangle(230,160,430,200);
 rectangle(230,220,430,260);
 rectangle(230,280,430,320);
 rectangle(230,340,430,380);
 rectangle(230,400,430,440);
 outtextxy(250,115," CREATE NEW ACCOUNT ");
 outtextxy(248,175," LIST OF ALL ACCOUNTS ");
 outtextxy(270,235," TRANSACTIONS");
 outtextxy(240,295," SEE PARTICULAR ACCOUNT");
 outtextxy(270,355," EDIT ACCOUNT");
 outtextxy(300,415," EXIT ");
int temp=0;


while(1)
{
setfillstyle(SOLID_FILL,9);
floodfill(250,120,15);
 do
 {
 ch=getch();
 if(ch==0)
  {
   ch=getch();
   temp=choice;
   switch(ch)
   {
    case 80: ++choice; break;            //down
    case 72: --choice; break;              //up
   }
   choice=m.toggle(choice,temp);
  }
 }while(ch!=13);
 setcolor(0);
 switch(choice)
  {
   case 1: b.open_new_account();
		break;
   case 2: b.list_of_accounts();
		break;
   case 3: b.transactions();
		break;
   case 4: b.see_account();
		break;
   case 5:b.edit_account();
		break;
   case 6: exit(0);
		break;
 }

}
};

int menu::toggle(int ch,int temp)
{
setfillstyle(SOLID_FILL,0);
switch(temp)
{
  case 1:   floodfill(330,130,15);
	     if(ch==0)
	     ch=6;
	     break;
  
  
  case 2:   floodfill(240,190,15);
	      break;
  case 3:   floodfill(330,250,15);
	      break;
  case 4:   floodfill(330,310,15);
	      break;
  case 5:   floodfill(330,370,15);
	      break;
  case 6:   floodfill(330,430,15);
	     if(ch==7)
	       ch=1;
	     break;
};
setfillstyle(SOLID_FILL,9);
switch(ch)
 {
  case 1:    floodfill(330,130,15);
	      break;
  case 2:    floodfill(240,190,15);
	      break;
  case 3:    floodfill(330,250,15);
	      break;
  case 4:    floodfill(330,310,15);
	      break;
  case 5:    floodfill(330,370,15);
	      break;
  case 6:    floodfill(330,430,15);
	      break;
 };
return ch;
}

//END OF PROGRAM...
