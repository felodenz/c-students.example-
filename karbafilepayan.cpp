#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
static int sum=0;
class student{
	
	public:
		bool flag=0;
		char fname[20];
		char lname[20];
		int un;
		int cn;	
		int point[2];	
		void add_students();
		void search_for_student();
		void show_students_list();
		void add_point(int count);	
		void show_avg(int count);
		
};
void student:: add_students(){
	cout<<"enter first name: ";
	cin>>fname;
	
	cout<<"enter last name: ";
	cin>>lname;
	
	cout<<"enter unic number: ";
	cin>>un;
	
	cout<<"enter class number: ";
	cin>>cn;
	
	fstream fp("c:/cpp/students.txt",ios::app);
	fp.write((char*)this,sizeof(student));
	fp.close();
	getch();
	
}

void student::search_for_student(){
	int fun;
	student stu;
	cout<<"enter unic number : ";
	cin>>fun;
	ifstream fp("c:/cpp/students.txt",ios::binary|ios::in);
	if(!fp)
		cout<<"error! ";
	fp.read((char*)&stu,sizeof(student));
	while(!fp.eof()){
		if(stu.un==fun){
			cout<<"[name: "<<stu.fname;
			cout<<" "<<stu.lname<<endl;
			cout<<"shomare tahsili: "<<stu.un<<endl;
			cout<<"class number:"<<stu.cn;
			break;
		}
		fp.read((char*)&stu,sizeof(student));	
	}
	fp.close();
	getch();	
}

void student::show_students_list(){
	student stu;
	ifstream fp("c:/cpp/students.txt",ios::binary|ios::in);
	fp.read((char*)&stu,sizeof(student));
	while(!fp.eof()){
			cout<<"[name: "<<stu.fname;
			cout<<" "<<stu.lname<<" , ";
			cout<<" shomare tahsili : "<<stu.un<<" , ";
			cout<<"class number: "<<stu.cn;
			fp.read((char*)&stu,sizeof(student));
			cout<<endl;	
	}
	fp.close();
	getch();
}
void student::add_point(int count){
	int fun;
	student stu;
	cout<<"enter unic number : ";
	cin>>fun;
	ifstream fp("c:/cpp/students.txt",ios::binary|ios::in);
	if(!fp)
		cout<<"error! ";
	fp.read((char*)&stu,sizeof(student));
	cout<<endl;
	while(!fp.eof()){
		if(stu.un==fun){
			stu.flag=1;
			for(int i=0;i<count;i++){
//				stu.point[i]=20;
				int p;
				cout<<"enter your point number "<<i+1<<" : ";
				cin>>p;
				stu.point[i]=p;
				sum+=p;
			}
		}
		fp.read((char*)&stu,sizeof(student));	
	}
	fp.close();
	getch();
}
void student::show_avg(int count){
	student stu;
	ifstream fp("c:/cpp/students.txt",ios::binary|ios::in);
	if(!fp)
		cout<<"error! ";
	fp.read((char*)&stu,sizeof(student));
//	cout<<endl;

	while(!fp.eof()){
		cout<<"[name: "<<stu.fname;
		cout<<" "<<stu.lname<<" , ";
		cout<<" shomare tahsili : "<<stu.un<<" , ";
		cout<<"class number: "<<stu.cn<<"]==>";
		if(flag=false){
			cout<<"NOMARAT VARED NASHODE!\n";
		}
		else{
			cout<<"NPMRE VARED SHODE AST! \n";
		}
		fp.read((char*)&stu,sizeof(student));	
	}
	cout<<"sum is: "<<sum;
	fp.close();
	getch();
}
int main(){
	#define count 2
	//int count=2;
	int select;
	student stu;
	l:
	system("cls");
	cout<<"this is our menu"<<endl;
	cout<<"1-add a new student"<<endl; //done
	cout<<"2-search for a student"<<endl;
	cout<<"3-show students list"<<endl;
	cout<<"4-add point for added student"<<endl;
	cout<<"5-number of students and class avg"<<endl;
	cout<<"select: ";
	cin>>select;
	if(select==1){
		stu.add_students();
		goto l;
	}
	else if(select==2){
		stu.search_for_student();
		goto l;
	}
	else if(select==3){
		stu.show_students_list();
		goto l;
	}
	else if(select==4){
		stu.add_point(count);
		goto l;
	}
	else if(select==5){
		stu.show_avg(count);
		goto l;
	}
	else{
		goto l;
	}
}
