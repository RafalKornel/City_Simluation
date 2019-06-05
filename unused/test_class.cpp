#include<iostream>
#include<string>
#include "test_class.h"

using namespace std;

test_class::test_class(int num, string name)
{
    this->some_int = num;
    this->name = name;
}

void test_class::show_name()
{
    cout << this->name << endl;
}