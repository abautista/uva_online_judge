#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    Person(string nn, int dd, int mm, int yy);
    bool operator<(Person& p);
    string name() const { return n; }
private:
    int d, m, y;
    string n;
};

Person::Person(string nn, int dd, int mm, int yy)
{
    n = nn;
    d = dd;
    m = mm;
    y = yy;
}

bool Person::operator<(Person& p)
{
    if (y == p.y && m == p.m) {
        return d < p.d;
    } else if (y == p.y) {
        return m < p.m;
    } else {
        return y < p.y;
    }
}


int main(int argc, char *argv[])
{
    int people_number;
    string name;
    int day, month, year;
    vector<Person> people;

    cin >> people_number;
    for (int i = 0; i < people_number; i++) {
        cin >> name >> day >> month >> year;
        people.push_back(Person(name, day, month, year));
    }

    cout << max_element(people.begin(), people.end())->name() << endl;
    cout << min_element(people.begin(), people.end())->name() << endl;

}
