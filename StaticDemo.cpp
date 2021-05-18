#include <string>
#include <iostream>
using namespace std;
class Person
{
public:
    string firstname() const
    {
        return _firstname;
    }
    string lastname() const
    {
        return this->_lastname;
    }
    static int howmany() {
    	return counter;
	}
	static Person *create() {
		return new Person("aa", "bb");
	}
private:
    Person(string lastname, string firstname)
        : _firstname(firstname), _lastname(lastname)
    {
    	counter ++;
    }
    const string _firstname = nullptr;
    const string _lastname = nullptr;
    static int counter;
};
int Person::counter = 0;
int main(void)
{
    Person *p1 = Person::create();
    Person p2("ou", "you");
    //how many person?
    std::cout << Person::howmany() << std::endl;
    cout << p1.howmany() << std::endl;
    cout << p2.howmany() << std::endl;
    Person p4("xi", "biaoge");
    
    return 0;
}

