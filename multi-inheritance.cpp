#include<iostream>
using namespace std;

template<class T>
class Person {
   // Data members of person 
public:
    Person(int x)  { cout << "Person::Person(int ) called" << endl;   }
    void learn() {
        static_cast<T const&>(*this).learn();
    }
    void teach() {
        static_cast<T const&>(*this).teach();
    }
};

template<class T>
class Faculty : public Person<Faculty> {
   // data members of Faculty
public:
    Faculty(int x):Person(x)   {
       cout<<"Faculty::Faculty(int ) called"<< endl;
    }
    void learn() {
        cout << "Faculty learn sth." << endl;
    }
    void teach() {
        cout << "Faculty teach sth." << endl;
    }
};

template<class T>
class Student : public Person<Student> {
   // data members of Student
public:
    Student(int x):Person(x) {
        cout<<"Student::Student(int ) called"<< endl;
    }
    void learn() {
        cout << "Student learn sth." << endl;
    }
    void teach() {
        cout << "Student can't teach." << endl;
    }
};
/*
template<class T1, class T2>
class TA : public T1 {
    TA(int x):T1(x) {
        cout << "TA::TA(int ) called" << endl;
    }
    void learn() {
        T1::learn();
    }
    void teach() {
        static_cast<T2 const&>(*this).teach();
    }
    // TA constraints
};
*/

class TA : public Person<TA> {
public:
    TA(int x):st(x), fa(x)   {
        cout << "TA::TA(int ) called" << endl;
    }
    void learn() {
        st.learn();
    }
    void teach() {
        fa.teach();
    }
private:
    Student st;
    Faculty fa;
};
class TA : public Student, public Faculty {
public:
    TA(int x):Student(x), Faculty(x)   {
        cout << "TA::TA(int ) called" << endl;
    }
    void learn() {
        Student::learn();
    }
    void teach() {
        Faculty::teach();
    }
};
  
int main()  {
    TA ta1(30);
    //TA<Student, Faculty> ta1(30);
    ta1.learn(); // Student's learn
    ta1.teach(); // Faculty's teach
}