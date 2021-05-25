#include <iostream> 
#include <string>
#include <cmath>
using namespace std;
class Student {
public:
  Student(string &fn, string &ln, char s):sex(s) {
  	firstname = fn;
  	lastname = ln;
  	gpa = 0.0f;
  	grade = 1;
  }
  Student(const char fn[], const char ln[], char s):firstname(fn), lastname(ln), sex(s) {
  	gpa = 0.0f;
  	grade = 1;
  }
  ~Student() {
  }
  //method
  void show_myself() {
  	std::cout << firstname << lastname << sex << grade << gpa << std::endl;
  }
  void study_time(int study_time) {
  	gpa = gpa + log(study_time);
  	gpa = gpa > 4.0f ? 4.0f : gpa;
  }
  int upgrade() {
  	int tmp = this->grade;
  	this->grade += 1;
  	this->grade = grade > 4 ? 4 : grade;
  	return tmp;
  }
private:
  float gpa;
  std::string firstname, lastname;
  char sex;
  int grade;
};

int main() {
  char buffer[5][100]={{"Mike", "Barnes", 'M'},{"Jim", "Nickerson", 'F'}}
  string fn("Mike"), ln("Barnes"); 
  Student st1(fn, ln, 'M'), st2("Jim", "Nickerson", 'F');
  std::vector<Student> student_list;
  student_list.push_pack(st1);
  st1.upgrade();
  st1.study_time(60);
  st2.study_time(1000);
  st1.show_myself();
  st2.show_myself();
  return 0;
}
