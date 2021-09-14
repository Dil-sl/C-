

#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>
using namespace std;




class student
{
	int rollno;
	char name[50];
	int p_marks, c_marks, m_marks, e_marks, cs_marks,c_num,rank_s;
	string cts_str = "Hello";
	int per;
	char grade;
	void calculate();
public:
	void getdata();
	void showdata() const;
	void show_tabular() const;
	int retrollno() const;
};


void student::calculate()
{

	per=(p_marks+c_marks+m_marks+e_marks+20);

 for (int i = 0; i <= per; i++) {
         if(41<=per and per<=320)
        {
            rank_s=321-i;
            cout<<rank_s;
        }

        else if(per<41)
        {
            rank_s=340-i;
            cout<<rank_s;
        }


}
}

void student::getdata()
{
	cout<<"\nEnter The roll number of student : ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter The class number(Bio=2,Maths=1) : ";
	cin>>c_num;
	if(c_num=1){
        cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>p_marks;
	cout<<"\nEnter The marks in chemistry out of 100 : ";
	cin>>c_marks;
	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>m_marks;
	cts_str = "Maths";
	calculate();
	}
	else if(c_num=2){
        cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>p_marks;
	cout<<"\nEnter The marks in chemistry out of 100 : ";
	cin>>c_marks;
	cout<<"\nEnter The marks in Biology out of 100 : ";
	cin>>e_marks;
	calculate();
	cts_str = "Biology";
	}


}

void student::showdata() const
{
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nMarks in Physics : "<<p_marks;
	cout<<"\nMarks in Chemistry : "<<c_marks;
	cout<<"\nMarks in Maths : "<<m_marks;
	cout<<"\nMarks in Biology : "<<e_marks;
	cout<<"\nTotal marks of student is  :"<<per-20;
	cout<<"\nRank of student is (From 320 students) :"<<rank_s;
	cout<<"\nClass of student is :"<<cts_str;
}

void student::show_tabular() const
{
	cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)<<e_marks<<setw(4)<<per<<setw(6)<<grade<<endl;
}

int  student::retrollno() const
{
	return rollno;
}



void write_student();
void display_all();
void display_sp(int);
void modify_student(int);
void delete_student(int);
void class_result();
void result();
void intro();
void entry_menu();





int main()
{
	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2);
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		switch(ch)
		{
			case '1': entry_menu();
				break;
			case '2': entry_menu();
				break;
			case '3':
				break;
			default :cout<<"\a";
		}
    }while(ch!='3');
	return 0;
}


void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}


void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}


void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}






void intro()
{
    cout<<"\n\n\t\t************************************************";
	cout<<"\n\n\n\t\t     Welcome To The Student Exam Rank System";
	cout<<"\n\n\t\t************************************************";
	cout<<"\n\n\t\t        Press any key to START programme>>> ";
	cout<<"\n\n\t\t        Made By:@Dilsha pramuditha ";
	cin.get();
}



void entry_menu()
{
	char ch;
	int num;
	system("cls");
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
				display_sp(num); break;

	case '4':	break;
	default:	cout<<"\a"; entry_menu();
	}
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
