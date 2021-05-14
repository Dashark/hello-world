#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Person
{
    public:
        Person(string lastname, string firstname)
            : _firstname(firstname)
            , _lastname(lastname)
        {
        }
        string firstname() const
        {
            return _firstname;
        }
        string lastname() const
        {
            return _lastname;
        }

    private:
        string _firstname = nullptr;
        string _lastname = nullptr;
};

class PersonSortCriterion
{
    public:
        bool operator()(const Person& p1, const Person& p2) const
        {
            return p1.lastname() < p2.lastname() || 
				   (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
        }
};

int main(void)
{
    set<Person, PersonSortCriterion> coll;
    Person p1("yu", "g");
    Person p2("an", "yu");
    Person p3("xiao", "ming");
    Person p4("xi", "biaoge");
    Person p5("u", "ong");
    coll.insert(p1);
    coll.insert(p2);
    coll.insert(p3);
    coll.insert(p4);
    coll.insert(p5);
    for (auto i : coll) {
        cout << i.lastname() << ", " << i.firstname() << endl;
    }

    return 0;
}

