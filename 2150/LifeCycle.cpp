#include <iostream>
#include <string>
#include "LifeCycle.h"
using namespace std;

// ------------------------------------------------  default constructor
MyObject::MyObject(const char *n) : name(n)
{
    id = ++numObjs;
    cout << "MyObject Default constructor: " << *this << endl;
}

// ---------------------------------------------------  copy constructor
MyObject::MyObject(const MyObject& rhs) : name(rhs.name)
{
    id = ++numObjs;
    cout << "MyObject Copy constructor:    " << *this << endl;
}

// --------------------------------------------------------  destructor
MyObject::~MyObject()
{
    cout << "MyObject Destructor:          " << *this << endl;
}

// -----------------------------------------------------------  put to
ostream& operator<<(ostream& output, const MyObject& obj)
{
    // output in format:  ("object name",id)
    return output << "(\"" << obj.name << "\"," << obj.id << ")";
}

//---------------------------------------------------- static variables
int MyObject::numObjs = 0;  // static member for all objects in class
static MyObject staticObj("I'm static, outside of main");

//---------------------------------------------------------- prototypes
MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
int cmpMyObj(const MyObject o1, const MyObject o2);
void swapMyObj(MyObject& o1, MyObject& o2);
