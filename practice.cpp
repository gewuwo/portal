#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    string food = "pizza";
    string &meal = food;
    string *ptr = &food;
    cout << food << endl;
    cout << meal << endl;
    cout << &food<< endl;
    cout << &meal << endl;
    return 0;
}
