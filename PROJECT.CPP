#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<iostream.h>

//****************
// CLASS NAME:Yamuna
// Details:it controls all functioning of the Yamuna
//****************

class Yamuna
 {
       int age;
       char name[20];
       char address[50];

       public:
       void aboutus(void);
       void sports(void);
       void facilities(void);
       void contactus(void);
       void membership(void);
  };


class member
  {
       char address[50];
       char name[20];
       int age;
       int id;

       public:
       void getdata(void);
       void putdata(void);
       int getid(void);
  };

    //**************
    // functions
    //**************


void member::getdata()
  {
     clrscr();

// data of the member

	cout<<"\n\n\t Enter your Name: ";
	gets(name);
	cout<<"\n\n\t Enter your Age: ";
	cin>>age;
	cout<<"\n\n\t Enter your Address: ";
	gets(address);
	cout<<"\n\n\t Enter ID number (any 3 digit): ";
	cin>>id;
   }


void member::putdata()
  {
	cout<<"\n\n\n\t\t"<<id<<"\t";
	puts(name);
	cout<<"\t";
	puts(address);
	cout<<"\t";
	cout<<age<<endl;
  }


int member::getid()
  {
	return(id);
  }

member m;

void write_file()
 {
	clrscr();

	ofstream afile("member.dat",ios::app);

	m.getdata();

// copying the record of the member into file

       afile.write((char*)&m,sizeof (m));
       afile.close();

       clrscr();
  }


void read_file()
  {
       clrscr();

       ifstream bfile("member.dat",ios::binary);
       while(bfile.read((char*)&m,sizeof(m)))
     {
	m.putdata();
     }

      getch();
      clrscr();
      bfile.close();
  }

void search()
  {
      clrscr();
      int n=0,p=-1;

      ifstream cfile("member.dat",ios::binary);
      cout<<"\n\n\n\n\n\t\t Enter ID of member to be searched: ";
      cin>>n;
      while(cfile.read((char*)&m,sizeof (m)))
      {
	  if(m.getid()==n)
	{
	  m.putdata();
	  p++;
	}
      }
	  if(p==-1)
	  cout<<"\n\n\n\t\t Record not found!!!!!!!!!";
	  getch();
	  clrscr();
	  cfile.close();
  }


void modify()
  {
     clrscr();
     int n,p=-1;
     int t=0;
     cout<<"\n\n\n\n\t Enter ID of the member to be modified: ";
     cin>>n;

     fstream dfile("member.dat",ios::binary|ios::in|ios::out);
       while(dfile.read((char*)&m,sizeof (m)))
     {
	t++;
	if(m.getid()==n)
      {
	m.getdata();
	dfile.seekp((t-1)*sizeof(m),ios::beg);
	dfile.write((char*)&m,sizeof(m));
	p++;
      }
    }
	if(p==-1)
	cout<<"\n\n\n\t\t Record not found!!!!!!!!";

	getch();
	clrscr();
	dfile.close();
  }


void delete1()
  {
	clrscr();

	int p=-1;
	int n;

	ifstream efile("member.dat",ios::binary);
	ofstream ffile("temp.dat",ios::out);
	cout<<"\n\n\n\t\t Enter ID of member to be deleted: ";
	cin>>n;

	while(efile.read((char*)&m,sizeof(m)))
      {
	  if(m.getid()!=n)
	{
	  ffile.write((char*)&m,sizeof(m));
	  p++;
	}
      }
	  efile.close();
	  ffile.close();

// deleting the record of member

	 remove("member.dat");
	 rename("temp.dat","member.dat");

	 if(p==-1)
	 cout<<"\n\n\n\t\t Record not found!!!!!!!";
	 else
	 cout<<"\n\n\n\t\t Record is deleted.";

	 getch();
	 clrscr();
  }


void Yamuna::aboutus()
  {
	 clrscr();

	 cout<<"\n\t\t*****************"
	 <<"\n\t\t      "
	 <<"\n\t\t YAMUNA SPORTS ACADEMY  "
	 <<"\n\t\t      "
	 <<"\n\t\t*****************"
	 <<"\n It is one of the most proclaimed academies of East Delhi."
	 <<"\n It has not only employed experienced coaches who have represented the"
	 <<" country  in one or the other sports but also have the previledge of producing"
	 <<" many of the famous sporting legends who are currently representing us"
	 <<" at National Level.       "
	 <<"\n\t\t                 "
	 <<"\n * Virender Sehwag"
	 <<"\n * Gautam Gambhir"
	 <<"\n * Sunil Chhetri"
	 <<"\n * Sania Mirza"
	 <<"\n\n These are the few names of the sportsperson produced by the Academy."
	 <<"\n\t\t               ";

	 getch();
	 clrscr();

	 cout<<"\n It has best instructors."
	 <<"\n Best Infrastructure for amateur players."
	 <<"\n\t\t************************************"
	 <<"\n\t\t                "
	 <<"\n The Academy was founded by "
	 <<" Sh. Yashvardhan (Chairman of Vardhan Textiles)"
	 <<" in  the year 1993."
	 <<"\n\t\t                "
	 <<"\n The academy gives coaching for the following sports:"
	 <<"\n Cricket, Football, Basketball, Lawn Tennis, Swimming, Athletics."
	 <<"\n\t                  "
	 <<"\n The academy has following facilities for the members: "
	 <<"\n\n* Parking for cars and two wheelers."
	 <<"\n* Good sports shop."
	 <<"\n* World class Restrooms and showers."
	 <<"\n* Canteen serving nutritious food."
	 <<"\n\n It also provides Membership (Monthly,Yearly or Lifetime)."
	 <<"\n\t\t                 "
	 <<"\n Hope you will have a MARVELOUS time in the academy!!"
	 <<"\n\t\t                  "
	 <<"\n\t\t*************************************";

	 getch();
  }


void Yamuna::sports()
 {
	sportmenu:

	clrscr();

	int a,b,e,f;
	char c,d;

	cout<<"\n\t\t******************************";
	cout<<"\n\t\t            ";
	cout<<"\n\n\t\t YAMUNA SPORTS ACADEMY\n";
	cout<<"\n\t\t            ";
	cout<<"\n\t\t******************************";
	cout<<"\n\t\t****** SPORTS *******";
	cout<<"\n\t\t******************************";
	cout<<"\n\t\t            ";
	cout<<"\n\t\t   1)CRICKET ";
	cout<<"\n\t\t   2)FOOTBALL ";
	cout<<"\n\t\t   3)BASKET BALL ";
	cout<<"\n\t\t   4)LAWN TENNIS ";
	cout<<"\n\t\t   5)SWIMMING ";
	cout<<"\n\t\t   6)ATHLETICS ";
	cout<<"\n\t\t   7)EXIT ";
	cout<<"\n\t\t   ENTER YOUR CHOICE: ";

	cin>>a;

	if(a==1)
     {
	{
	  cricket:

	  clrscr();

	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t YAMUNA SPORTS ACADEMY\n";
	  cout<<"\n\t\t            ";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t****** SPORTS-CRICKET *******";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t Enter your age(between 05-20 Years): ";

	  cin>>age;

	  if(age>=5 && age<=12)
	  cout<<"\n\t Your fees is Rs 800/- per month.";
	  else if(age>12 && age<=20)
	  cout<<"\n\t Your fees is rs 1000/- per month.";
	  else
	{
	  cout<<"\n\t Your age is not applicable.";
	  cout<<"\n\t Press 1 to re-enter the age";
	  cout<<"\n\t Or press any other key to go to Sports Menu.";
	  cin>>b;

	  if(b==1)
	  goto cricket;
	  else
	  goto sportmenu;
	}
     }
	  cout<<"\n\t Would you like to join the academy?? Press Y for yes and N for no: ";
	  cin>>c;
	  if(c=='Y'||c=='y')
	  goto ycricket;
	  else
	  goto sportmenu;

	{
	  ycricket:
	  clrscr();

	// Data of member

	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t****** CRICKET *******";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";

	  cout<<"\n\t\t Enter NAME: ";
	  gets(name);

	  cout<<"\n\t\t Enter Address: ";
	  gets(address);

	  cout<<"\n\t\t Enter shift timings (m-morning;e-evening):";
	  cin>>d;

	  if(age>=5&&age<=12&&d=='m')
	 {
	  cout<<"\n\n\t Timings are: 9:00am to 10:30am";
	  cout<<"\n\n\t Days: Monday, Wednesday, Friday";
	 }
	  else if(age>=5&&age<=12&&d=='e')
	 {
	  cout<<"\n\n\t Timings are: 4:30pm to 6:00pm";
	  cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
	 }
	  else if(age>12&&age<=20&&d=='m')
	 {
	  cout<<"\n\n\t Timings are: 6:30am to 8:00am";
	  cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
	 }
	  else if(age>12&&age<=20&&d=='e')
	 {
	  cout<<"\n\n\t Timings are: 6:30pm to 8:00pm";
	  cout<<"\n\n\t Days: Monday, Wednesday, Friday";
	 }
	  else
	 {
	  cout<<"\n\n\t You have entered wrong choice.";
	  cout<<"\n\n\t Press 1 to go to cricket menu.";
	  cin>>e;
	  if(e==1)
	  goto cricket;
	  else
	  goto sportmenu;
	 }
     }

	 // Data of Head of cricket

	  clrscr();

	  cout<<"\n\t\t\t\t Faculty: ";
	  cout<<"\n\n\t\t\t HEAD- Mr. Lalit Sahu";
	  cout<<"\n\t\t\t COACH- Mr. Gopal Gupta";
	  cout<<"\n\n\n\t\t\t Equipments required";
	  cout<<"\n\t\t\t 1. Cricket kit";
	  cout<<"\n\t\t\t 2. Jersey";
	  cout<<"\n\n\n\t\t\t Thanks for joining the Academy!";

	  getch();

	  goto sportmenu;
   }
	  if(a==2)
	 {
	 {
	  football:

	  clrscr();
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t YAMUNA SPORTS ACADEMY\n";
	  cout<<"\n\t\t            ";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t****** SPORTS-FOOTBALL *******";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t Enter your age(between 05-20 Years): ";

	  cin>>age;

	 if(age>=5 && age<=12)
	 cout<<"\n\t Your fees is Rs 800/- per month.";
	 else if(age>12 && age<=20)
	 cout<<"\n\t Your fees is rs 1000/- per month.";
	 else
      {
	 cout<<"\n\t Your age is not applicable.";
	 cout<<"\n\t Press 1 to re-enter the age";
	 cout<<"\n\t Or press any other key to go to Sports Menu";
	 cin>>b;
	 if(b==1)
	 goto football;
	 else
	 goto sportmenu;
      }
   }
	 cout<<"\n\t Would you like to join the academy?? Press Y for yes and N for no: ";
	 cin>>c;
	 if(c=='Y'||c=='y')
	 goto yfootball;
	 else
	 goto sportmenu;

   {
	 yfootball:

	 clrscr();

	// Data of member

	cout<<"\n\t\t******************************";
	cout<<"\n\t\t            ";
	cout<<"\n\t\t******************************";
	cout<<"\n\t\t****** FOOTBALL *******";
	cout<<"\n\t\t******************************";
	cout<<"\n\t\t            ";

	cout<<"\n\t\t Enter NAME: ";
	gets(name);

	cout<<"\n\t\t Enter Address: ";
	gets(address);
	cout<<"\n\t\t Enter shift timings(m-morning;e-evening): ";
	cin>>d;

	if(age>=5&&age<=12&&d=='m')
      {
	cout<<"\n\n\t Timings are: 9:00am to 10:30am";
	cout<<"\n\n\t Days: Monday, Wednesday, Friday.";
      }
	else if(age>=5&&age<=12&&d=='e')
      {
	cout<<"\n\n\t Timings are: 4:30pm to 6:00pm";
	cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
      }
	else if(age>12&&age<=20&&d=='m')
      {
	cout<<"\n\n\t Timings are: 6:30am to 8:00am";
	cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
      }
	else if(age>12&&age<=20&&d=='e')
      {
	cout<<"\n\n\t Timings are: 6:30pm to 8:00pm";
	cout<<"\n\n\t Days: Monday, Wednesday, Friday";
      }
	else
      {
	cout<<"\n\n\t You have entered wrong choice.";
	cout<<"\n\n\t Press 1 to go to football menu.";
	cin>>e;
	if(e==1)
	goto football;
	else
	goto sportmenu;
      }
      }

      // Data of Head of football

	 clrscr();

	 cout<<"\n\t\t\t\t Faculty:";
	 cout<<"\n\n\t\t\t HEAD- Mr. Kunal Dhoundial";
	 cout<<"\n\t\t\t COACH- Mr. Abhishek Rawat";
	 cout<<"\n\n\n\t\t\t equipments required";
	 cout<<"\n\t\t\t 1. Studs";
	 cout<<"\n\t\t\t 2. Jersey";
	 cout<<"\n\n\n\t\t\t Thanks for joining the Academy!";

	 getch();

	 goto sportmenu;
   }
	 if(a==3)
       {
	{
	 basketball:

	 clrscr();

	 cout<<"\n\t\t******************************";
	 cout<<"\n\t\t            ";
	 cout<<"\n\n\t\t YAMUNA SPORTS ACADEMY\n";
	 cout<<"\n\t\t            ";
	 cout<<"\n\t\t******************************";
	 cout<<"\n\t\t****** SPORTS-BASKETBALL *******";
	 cout<<"\n\t\t******************************";
	 cout<<"\n\t\t            ";
	 cout<<"\n\n\t\t Enter your age(between 05-20 Years): ";

	 cin>>age;

	 if(age>=5 && age<=12)
	 cout<<"\n\t Your fees is Rs 800/- per month.";
	 else if(age>12 && age<=20)
	 cout<<"\n\t Your fees is rs 1000/- per month.";
	 else
       {
	 cout<<"\n\t Your age is not applicable.";
	 cout<<"\n\t Press 1 to re-enter the age";
	 cout<<"\n\t Or press any other key to go to Sports Menu";
	 cin>>b;
	 if(b==1)
	 goto basketball;
	 else
	 goto sportmenu;
       }
      }
	 cout<<"\n\t Would you like to join the academy?? Press Y for yes and N for no: ";
	 cin>>c;
	 if(c=='Y'||c=='y')
	 goto ybasketball;
	 else
	 goto sportmenu;

       {
	 ybasketball:

	 clrscr();

	// Data of member

	 cout<<"\n\t\t******************************";
	 cout<<"\n\t\t            ";
	 cout<<"\n\t\t******************************";
	 cout<<"\n\t\t****** BASKETBALL *******";
	 cout<<"\n\t\t******************************";
	 cout<<"\n\t\t            ";

	 cout<<"\n\t\t Enter NAME: ";
	 gets(name);

	 cout<<"\n\t\t Enter Address: ";
	 gets(address);
	 cout<<"\n\t\t Enter shift timings(m-morning;e-evening): ";
	 cin>>d;

	 if(age>=5&&age<=12&&d=='m')
	{
	 cout<<"\n\n\t Timings are: 9:00am to 10:30am";
	 cout<<"\n\n\t Days: Monday, Wednesday, Friday";
	}
	 else if(age>=5&&age<=12&&d=='e')
	{
	 cout<<"\n\n\t Timings are: 4:30pm to 6:00pm";
	 cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
	}
	 else if(age>12&&age<=20&&d=='m')
	{
	 cout<<"\n\n\t Timings are: 6:30am to 8:00am";
	 cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
	}
	 else if(age>12&&age<=20&&d=='e')
	{
	 cout<<"\n\n\t Timings are: 6:30pm to 8:00pm";
	 cout<<"\n\n\t Days: Monday, Wednesday, Friday";
	}
	 else
	{
	 cout<<"\n\n\t You have entered wrong choice.";
	 cout<<"\n\n\t Press 1 to go to basketball menu";
	 cin>>e;
	 if(e==1)
	 goto basketball;
	 else
	 goto sportmenu;
	}
	}

	 // Data of Head of Basketball

	 clrscr();

	 cout<<"\n\t\t\t\t Faculty          :";
	 cout<<"\n\n\t\t\t HEAD- Mr. Deepanshu Batra";
	 cout<<"\n\t\t\t COACH- Mr. Piyush Gupta";
	 cout<<"\n\n\n\t\t\t equipments required";
	 cout<<"\n\t\t\t 1. Basketball";
	 cout<<"\n\t\t\t 2. Jersey";
	 cout<<"\n\n\n\t\t\t Thanks for joining the Academy!";

	 getch();

	 goto sportmenu;
   }
	 if(a==4)
	{
	{ lawn:

	  clrscr();

	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t YAMUNA SPORTS ACADEMY\n";
	  cout<<"\n\t\t            ";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t****** SPORTS-LAWN TENNIS *******";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t Enter your age(between 05-20 Years): ";

	  cin>>age;

	  if(age>=5 && age<=12)
	  cout<<"\n\t Your fees is Rs 800/- per month.";
	  else if(age>12 && age<=20)
	  cout<<"\n\t Your fees is rs 1000/- per month.";
	  else
	{
	  cout<<"\n\t Your age is not applicable.";
	  cout<<"\n\t Press 1 to re-enter the age";
	  cout<<"\n\t Or press any other key to go to Sports Menu";
	  cin>>b;
	  if(b==1)
	  goto lawn;
	  else
	  goto sportmenu;
	}
     }
	  cout<<"\n\t Would you like to join the academy?? Press Y for yes and N for no: ";
	  cin>>c;
	  if(c=='Y'||c=='y')
	  goto ylawn;
	  else
	  goto sportmenu;

	{
	  ylawn:

	  clrscr();

	// Data of member

	 cout<<"\n\t\t******************************";
	 cout<<"\n\t\t            ";
	 cout<<"\n\t\t******************************";
	 cout<<"\n\t\t****** LAWN TENNIS *******";
	 cout<<"\n\t\t******************************";
	 cout<<"\n\t\t            ";

	 cout<<"\n\t\t Enter NAME: ";
	 gets(name);

	 cout<<"\n\t\t Enter Address: ";
	 gets(address);
	 cout<<"\n\t\t Enter shift timings(m-morning;e-evening):";
	 cin>>d;

	if(age>=5&&age<=12&&d=='m')
     {
	cout<<"\n\n\t Timings are: 9:00am to 10:30am";
	cout<<"\n\n\t Days: Monday, Wednesday, Friday";
     }
	else if(age>=5&&age<=12&&d=='e')
     {
	cout<<"\n\n\t Timings are: 4:30pm to6:00pm";
	cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
     }
	else if(age>12&&age<=20&&d=='m')
     {
	cout<<"\n\n\t Timings are: 6:30am to 8:00am";
	cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
     }
	else if(age>12&&age<=20&&d=='e')
     {
	cout<<"\n\n\t Timings are: 6:30pm to 8:00pm";
	cout<<"\n\n\t Days: Monday, Wednesday, Friday";
     }
	else
     {
	cout<<"\n\n\t You have entered wrong choice.";
	cout<<"\n\n\t Press 1 to go to Lawn Tennis menu.";
	cin>>e;
	if(e==1)
	goto lawn;
	else
	goto sportmenu;
     }
  }

     // Data of Head of Lawn tennis

	 clrscr();

	 cout<<"\n\t\t\t\t Faculty:";
	 cout<<"\n\n\t\t\t HEAD- Mr.Rakshit Singhal";
	 cout<<"\n\t\t\t COACH- Mrs. Shivani Singhal";
	 cout<<"\n\n\n\t\t\t equipments required";
	 cout<<"\n\t\t\t 1. Tennis kit";
	 cout<<"\n\t\t\t 2. Jersey";
	 cout<<"\n\n\n\t\t\t Thanks for joining the Academy!";

	 getch();

	 goto sportmenu;
  }
	 if(a==5)
	{
	{
	  swim:
	  clrscr();

	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t YAMUNA SPORTS ACADEMY\n";
	  cout<<"\n\t\t            ";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t****** SPORTS-SWIMMING *******";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t Enter your age(between 05-20 Years): ";

	  cin>>age;

	  if(age>=5 && age<=12)
	  cout<<"\n\t Your fees is Rs 800/- per month";
	  else if(age>12 && age<=20)
	  cout<<"\n\t Your fees is rs 1000/- per month";
	  else
	{
	  cout<<"\n\t Your age is not applicable.";
	  cout<<"\n\t Press 1 to re-enter the age";
	  cout<<"\n\t Or press any other key to go to Sports Menu";
	  cin>>b;
	  if(b==1)
	  goto swim;
	  else
	  goto sportmenu;
	}
	}
	  cout<<"\n\t Would you like to join the academy?? Press Y for yes and N for no:";
	  cin>>c;
	  if(c=='Y'||c=='y')
	  goto yswim;
	  else
	  goto sportmenu;

       {
	  yswim:

	  clrscr();

	// Data of member

	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t****** SWIMMING *******";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";

	  cout<<"\n\t\t Enter NAME: ";
	  gets(name);

	  cout<<"\n\t Enter Address: ";
	  gets(address);
	  cout<<"\n\t Enter shift timings(m-morning;e-evening): ";
	  cin>>d;

	  if(age>=5&&age<=12&&d=='m')
	{
	  cout<<"\n\n\t Timings are: 9:00am to 10:30am";
	  cout<<"\n\n\t Days: Monday, Wednesday, Friday";
	}
	  else if(age>=5&&age<=12&&d=='e')
	{
	  cout<<"\n\n\t Timings are: 4:30pm to 6:00pm";
	  cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
	}
	  else if(age>12&&age<=20&&d=='m')
	{
	  cout<<"\n\n\t Timings are: 6:30am to 8:00am";
	  cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
	}
	  else if(age>12&&age<=20&&d=='e')
	{
	  cout<<"\n\n\t Timings are: 6:30pm to 8:00pm";
	  cout<<"\n\n\t Days: Monday, Wednesday, Friday";
	}
	  else
	{
	  cout<<"\n\n\t You have entered wrong choice.";
	  cout<<"\n\n\t Press 1 to go to swimming menu";
	  cin>>e;
	  if(e==1)
	  goto swim;
	  else
	  goto sportmenu;
	}
	}

	// Data of Head of swimming

	  clrscr();

	  cout<<"\n\t\t\t\t Faculty          :";
	  cout<<"\n\n\t\t\t HEAD- Mr. Nischal Kumar";
	  cout<<"\n\t\t\t COACH- Mrs. Neha Bareja";
	  cout<<"\n\n\n\t\t\t equipments required";
	  cout<<"\n\t\t\t 1. Swimming Costume";
	  cout<<"\n\t\t\t 2. Gears";
	  cout<<"\n\n\n\t\t\t Thanks for joining the Academy!";

	  getch();

	  goto sportmenu;
       }
	  if(a==6)
       {
       {  athletics:

	  clrscr();

	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t YAMUNA SPORTS ACADEMY\n";
	  cout<<"\n\t\t            ";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t****** SPORTS-ATHLETICS *******";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\n\t\t Enter your age(between 05-20 Years): ";

	  cin>>age;

	  if(age>=5 && age<=12)
	  cout<<"\n\t Your fees is Rs 800/- per month.";
	  else if(age>12 && age<=20)
	  cout<<"\n\t Your fees is rs 1000/- per month.";
	  else
      {
	  cout<<"\n\t Your age is not applicable.";
	  cout<<"\n\t Press 1 to re-enter the age";
	  cout<<"\n\t Or press any other key to go to Sports Menu";
	  cin>>b;
	  if(b==1)
	  goto athletics;
	  else
	  goto sportmenu;
      }
      }
	  cout<<"\n\t Would you like to join the academy?? Press Y for yes and N for no:";
	  cin>>c;
	  if(c=='Y'||c=='y')
	  goto yathletics;
	  else
	  goto sportmenu;

      {
	  yathletics:

	  clrscr();

	// Data of member

	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t****** ATHLETICS *******";
	  cout<<"\n\t\t******************************";
	  cout<<"\n\t\t            ";

	  cout<<"\n\t\t Enter NAME: ";
	  gets(name);

	  cout<<"\n\t\t Enter Address: ";
	  gets(address);
	  cout<<"\n\t\t Enter shift timings(m-morning;e-evening): ";
	  cin>>d;

	  if(age>=5&&age<=12&&d=='m')
	{
	  cout<<"\n\n\t Timings are: 9:00am to 10:30am";
	  cout<<"\n\n\t Days: Monday, Wednesday, Friday";
	}
	  else if(age>=5&&age<=12&&d=='e')
	{
	  cout<<"\n\n\t Timings are: 4:30pm to 6:00pm";
	  cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
	}
	  else if(age>12&&age<=20&&d=='m')
	{
	  cout<<"\n\n\t Timings are: 6:30am to 8:00am";
	  cout<<"\n\n\t Days: Tuesday, Thursday, Saturday";
       }
	  else if(age>12&&age<=20&&d=='e')
       {
	  cout<<"\n\n\t Timings are: 6:30pm to 8:00pm";
	  cout<<"\n\n\t Days: Monday, Wednesday, Friday";
       }
	  else
       {
	 cout<<"\n\n\t You have entered wrong choice.";
	 cout<<"\n\n\t Press 1 to go to athletics menu";
	 cin>>e;
	 if(e==1)
	 goto athletics;
	 else
	 goto sportmenu;
       }
       }

	 // Data of Head of athletics

	 clrscr();

	 cout<<"\n\t\t\t\t Faculty:";
	 cout<<"\n\n\t\t\t HEAD- Mr.Deepak Gupta";
	 cout<<"\n\t\t\t COACH- Mrs. Pooja Gupta";
	 cout<<"\n\n\n\t\t\t equipments required";
	 cout<<"\n\t\t\t 1. Shorts";
	 cout<<"\n\t\t\t 2. sports shoes";
	 cout<<"\n\n\n\t\t\t Thanks for joining the Academy!";

	 getch();

	 goto sportmenu;
      }
      }

void Yamuna::facilities()
  {
	 clrscr();
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t ****** SPORTS **************";
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t**** FACILITIES *******";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t**** Canteen *******";
	 cout<<"\n\t\t**** Sportshop ******";
	 cout<<"\n\t\t**** Security *******";
	 cout<<"\n\t\t**** Parking ********";
	 cout<<"\n\t\t**** Restrooms ******";
	 cout<<"\n\t\t**** Showers ********";
	 cout<<"\n\t\t****************************";
	 getch();
  }


void Yamuna::contactus()
   {
	 clrscr();
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t **** Contact us *****";
	 cout<<"\n\t\t***** Head office ****";
	 cout<<"\n\t\t****************************";
	 cout<<"\n";
	 cout<<"\n\t\tYamuna sports academy             ";
	 cout<<"\n\t\t502,Dayanand Vihar";
	 cout<<"\n\t\tPlot no 708             ";
	 cout<<"\n\t\tBlock A";
	 cout<<"\n\t\tDelhi 110092";
	 cout<<"\n\t\tPh:011-22230569/70/71";
	 cout<<"\n";
	 cout<<"\n\t\t************************************";
	 cout<<"\n\t\t       Details of Head of Sports ";
	 cout<<"\n\t\t ************************************";
	 cout<<"\n\t\t 1)CRICKET: Mr.Lalit Sahu 	   ";
	 cout<<"\n\t\t 2)FOOTBALL: Mr. Kunal Dhoundial";
	 cout<<"\n\t\t 3)BASKETBALL: Mr.Deepanshu Batra";
	 cout<<"\n\t\t 4)LAWN TENNIS: Mr.Rakshit Singhal";
	 cout<<"\n\t\t 5)SWIMMING: Mr.Nischal Kumar";
	 cout<<"\n\t\t 6)ATHLETICS: Mr.Deepak Kumar";
	 getch();
   }


void Yamuna::membership()
   {
	 void write_file();
	 void read_file();
	 void search();
	 void modify();
	 void delete1();

	 int a,c,d;
	 char b;
	 ymembership:

	 clrscr();
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t ****** MEMBERSHIP ********";
	 cout<<"\n\n";
	 cout<<"\n\t\t 1.Monthly Membership";
	 cout<<"\n\t\t 2.Yearly Membership";
	 cout<<"\n\t\t 3.Lifetime Membership";
	 cout<<"\n\t\t 4.For Administration use only";
	 cout<<"\n\t\t 5.Exit";
	 cout<<"\n\n\n\t\t Enter your choice:  ";
	 cin>>a;

	 if(a==1)
       {
	 clrscr();
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t ****** MEMBERSHIP ********";
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t*** MONTHLY-MEMBERSHIP ******";
	 cout<<"\n\t\t***************************";
	 cout<<"\n\n\n\n FEES : Rs. 2500/- p.m";
	 cout<<"\n\n Benefit: Swimming/Athletics is inclusive(free of cost)-Daily one hour";
	 cout<<"\n\n Would you like to join the academy?(Press Y for yes or N for no):";
	 cin>>b;

	 if(b=='y')
       {
	 clrscr();
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	 cout<<"\n\t\t             ";
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t ****** MEMBERSHIP ********";
	 cout<<"\n\t\t***************************";
	 cout<<"\n\t\t*** MONTHLY-MEMBERSHIP ******";
	 cout<<"\n\t\t***************************";

	 write_file();
	 cout<<"\n\t\t THANKS FOR JOINING OUR ACADEMY....";
	 cout<<"\n\t\t Press 0 to continue.";
	 cin>>d;

	 if(d==0)
	 goto ymembership;
	 else
	 goto ymembership;
       }
	 else
	 goto ymembership;
       }
	 if(a==2)
       {
	  clrscr();
	  cout<<"\n\t\t***************************";
	  cout<<"\n\t\t             ";
	  cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	  cout<<"\n\t\t             ";
	  cout<<"\n\t\t***************************";
	  cout<<"\n\t\t ****** MEMBERSHIP ********";
	  cout<<"\n\t\t***************************";
	  cout<<"\n\t\t*** YEARLY-MEMBERSHIP ******";
	  cout<<"\n\t\t***************************";
	  cout<<"\n\n\n\n FEES : Rs. 11000/- per annum";
	  cout<<"\n\n Benefit: Swimming/Athletics is inclusive(free of cost)-weekly 10 hours";
	  cout<<"\n\n Would you like to join the academy?(Press Y for yes or N for no):";
	  cin>>b;

	  if(b=='y')
       {
	  clrscr();
	  cout<<"\n\t\t***************************";
	  cout<<"\n\t\t             ";
	  cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	  cout<<"\n\t\t             ";
	  cout<<"\n\t\t***************************";
	  cout<<"\n\t\t ****** MEMBERSHIP ********";
	  cout<<"\n\t\t***************************";
	  cout<<"\n\t\t*** YEARLY-MEMBERSHIP ******";
	  cout<<"\n\t\t***************************";

	  write_file();
	  cout<<"\n\t\t THANKS FOR JOINING OUR ACADEMY....";
	  cout<<"\n\t\t Press 0 to continue.";
	  cin>>d;
	  if(d==0)
	  goto ymembership;
	  else
	  goto ymembership;
       }
	  else
	  goto ymembership;
       }
	  if(a==3)
       {
	   clrscr();
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t             ";
	   cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	   cout<<"\n\t\t             ";
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t ****** MEMBERSHIP ********";
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t*** LIFETIME-MEMBERSHIP ******";
	   cout<<"\n\t\t***************************";
	   cout<<"\n\n\n\n FEES : Rs. 60000 once";
	   cout<<"\n\n Benefit: Swimming/Athletics is inclusive(free of cost)-Daily one hour(self+spouse)";
	   cout<<"\n\n Would you like to join the academy?(Press Y for yes or N for no):";
	   cin>>b;

	   if(b=='y')
       {
	   clrscr();
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t             ";
	   cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	   cout<<"\n\t\t             ";
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t ****** MEMBERSHIP ********";
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t*** LIFETIME-MEMBERSHIP ******";
	   cout<<"\n\t\t***************************";

	   write_file();
	   cout<<"\n\t\t THANKS FOR JOINING OUR ACADEMY....";
	   cout<<"\n\t\t Press 0 to continue.";
	   cin>>d;
	   if(d==0)
	   goto ymembership;
	   else
	   goto ymembership;
       }
	   else
	   goto ymembership;
       }
	   if(a==4)
       {
	   clrscr();
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t             ";
	   cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	   cout<<"\n\t\t             ";
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t ****** MEMBERSHIP ********";
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t*** FOR THE ADMINISTRATION ONLY ***";
	   cout<<"\n\t\t***********************************";

	   do
       {
	   cout<<"\n\t\t1.  Add member ";
	   cout<<"\n\t\t2.  Read member ";
	   cout<<"\n\t\t3.  Search member ";
	   cout<<"\n\t\t4.  Modify member ";
	   cout<<"\n\t\t5.  Delete member ";
	   cout<<"\n\t\t6.  Exit    ";
	   cout<<"\n\n\n\n\n\n\t\t  Enter your slection: ";
	   cin>>c;

	   if(c==1)
	   write_file();
	   if(c==2)
	   read_file();
	   if(c==3)
	   search();
	   if(c==4)
	   modify();
	   if(c==5)
	   delete1();
       }   while(c!=6);
       }
   }


void main()
   {

// Starting Page

	   mainmenu:
	   clrscr();
	   int h;
	   char j;
	   Yamuna y;
//Main options

	   clrscr();
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\t             ";
	   cout<<"\n\t\t YAMUNA SPORTS ACADEMY     ";
	   cout<<"\n\t\t             ";
	   cout<<"\n\t\t***************************";
	   cout<<"\n\t\tYamuna sports academy";
	   cout<<"\n\t\t502,Dayanand Vihar";
	   cout<<"\n\t\tPlot no 708             ";
	   cout<<"\n\t\tBlock A";
	   cout<<"\n\t\tDelhi 110092";
	   cout<<"\n\t\tPh:011-22230569/70/71";
	   cout<<"\n\n\t\t WELCOME TO YAMUNA SPORTS ACADEMY !!";
	   cout<<"\n\t\t1) ABOUT US  ";
	   cout<<"\n\t\t2) SPORTS ";
	   cout<<"\n\t\t3) FACILITIES ";
	   cout<<"\n\t\t4) MEMBERSHIP ";
	   cout<<"\n\t\t5) CONTACT US ";
	   cout<<"\n\t\t6) EXIT";
	   cout<<"\n\t\t ENTER YOUR CHOICE: ";
	   cin>>h;

// for going to the specified option

	   if(h==1)
	   y.aboutus();
	   if(h==2)
	   y.sports();
	   if(h==3)
	   y.facilities();
	   if(h==4)
	   y.membership();
	   if(h==5)
	   y.contactus();
	   if(h>=6)
       {
	   exit(0);
       }
	   goto mainmenu;
       }









