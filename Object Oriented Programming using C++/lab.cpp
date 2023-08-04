/*#include <iostream>

using namespace std;

class Pratham;

class Gaurav{
    public:
    void showMarks(Pratham&);
};

class Pratham{
    int marks = 0;
    public:
    friend void Gaurav::showMarks(Pratham& p);
};

void Gaurav::showMarks(Pratham& p){
    cout << p.marks <<endl;
}


int main()
{
    Gaurav g;
    Pratham p;
    g.showMarks(p);

    return 0;
}*/

/*#include<iostream>
       #include<conio.h>
       
       using namespace std;

       class A
       {
              public:
              int a;
       };

       class B : virtual public A
       {
              public:
              int b;
       };
       class C : virtual public A
       {
              public:
              int c;
       };

       class D : public B, public C
       {
              public:
              int d;
       };

       int main()
       {

		  D d1;

		  d1.a = 10; 
		  d1.b = 20;
		  d1.c = 30;
		  d1.d = 40;

		  cout<< "\n A : "<< d1.a;
		  cout<< "\n B : "<< d1.b;
		  cout<< "\n C : "<< d1.c;
		  cout<< "\n D : "<< d1.d;
    
        return 0;
	   }*/

/*#include <iostream>
#include <conio.h>

using namespace std;

class Gaurav
{
public:
       virtual void showMarks()
       {
              cout << "Gaurav's result was good." << endl;
       }
};

class Pratham : public Gaurav
{
public:
       void showMarks()
       {
              cout << "Pratham's was abysmal!" << endl;
       }
};

int main()
{
       Pratham p;
       p.showMarks();
       Gaurav g = Pratham();
       g.showMarks();

       getch();
       return 0;
}*/

/*#include <iostream>
#include <conio.h>

using namespace std;

class Test
{
       int answer;

public:
       Test(int x)
       {
              answer = x;
       }
       Test(Test &p)
       {
              p.answer = 100;
              answer = p.answer;
       }
       void display()
       {
              cout << "Answer is: " << answer << endl;
       }
};

int main()
{
       Test gaurav(1);
       Test pratham = gaurav;
       pratham.display();
       getch();
       return 0;
}*/

/*#include <iostream>
#include <conio.h>

using namespace std;

class Gaurav
{
public:
       virtual void display() = 0;
       /*void test()
       {
              cout << "Not overridden!" << endl;
       }
};

void Gaurav::display()
{
       cout << "Pure virtual definition" << endl;
}

class Pratham : public Gaurav
{
public:
       void display()
       {
              cout << "Overiding of pure virtual function" << endl;
       }
};

int main()
{
       Gaurav *g = new Pratham;
       g->display();
       //g->test();
       getch();
       return 0;
}*/

/*class shapeArea{
       public:
       int area(int radius){
              return 3.14*radius*radius;
       }
       int area(int len, int bre){
              return len*bre;
       }
       int area(float b, int h){
              return (0.5*b*h);
       }
};

int main(){
       shapeArea S;
       cout << S.area(10) << endl;
       cout << S.area(20, 10) << endl;
       cout << S.area(2.5, 5) << endl;

       getch();
       return 0;

}*/

class Student
{
public:
       int rollNum;
       string name;
};

class Exam : public Student
{
public:
       int subMarks[5];
};

class Result : public Exam
{
public:
       int totalMarks = 0;
       for (int i = 0; i <= 5; i++)
       {
              totalMarks += subMarks[i];
       }
};
