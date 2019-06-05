#include "city.h"
#include "citizen.h"
#include <iostream>

using namespace std;

int City::get_size() { return citizens_count; }

City::City(int count)
{
    citizens_count = count;
    citizens = (Citizen*)malloc(sizeof(Citizen) * count);
    cout << sizeof(Citizen) * count << ' ' <<  sizeof(Citizen) << endl;
}

City::City(int count, double p)
{
    citizens_count = count;
    citizens = (Citizen*)malloc(sizeof(Citizen) * count);
    populate(p);
}


void City::populate()
{
    for (int i = 0; i < citizens_count; i++) 
    { 
        Citizen* c = new Citizen();
        (*c).print();
        citizens[i] = (*c); 
    }
}

void City::populate(double p)
{
    
    for (int i = 0; i < citizens_count; i++) { citizens[i] = (*new Citizen(p)); }
}

void City::show_avg_happiness()
{
    cout << "Average happiness is: " << avg_happiness << endl;
}

void City::evolve()
{
    for (int i = 0; i < get_size(); i++)
    {
        avg_happiness += citizens[i].happiness(*this, max_dist);
    }

    avg_happiness /= get_size();
}

void City::evolve(int n)
{
    for (int i = 0; i < n; i++) { evolve(); }
}