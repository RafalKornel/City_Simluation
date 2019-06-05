#include "citizen.h"
#include "city.h"
#include "utilities.h"
#include <iostream>

Citizen::Citizen(double a, double b, int c)
{
    x = a;
    y = b;
    club = c;
}

Citizen::Citizen()
{
    x = (double(rand())/RAND_MAX) * map_size;
    y = (double(rand())/RAND_MAX) * map_size;
    club = rand()%2;
    //cout << "Konstruktor  " << x << '\t' << y << '\t' << club << endl;
}

Citizen::Citizen(int club)
{
    x = (double(rand())/RAND_MAX) * map_size;
    y = (double(rand())/RAND_MAX) * map_size;
    this->club = club;
}

Citizen::Citizen(double p)
{
    x = (double(rand())/RAND_MAX) * map_size;
    y = (double(rand())/RAND_MAX) * map_size;
    double roll = (double)(rand() % 100)/100;
    if (roll <= p) { club = 0; }
    else { club = 1; }
}

double Citizen::get_x() { return x; }

double Citizen::get_y() { return y; }

int Citizen::get_club() { return club; }

void Citizen::print()
{
    cout << "x: " << x << '\t'
         << "y: " << y << '\t'
         << "club: " << club << '\t'
         << "adress: " << this << endl;
}

int Citizen::happiness(City city, double r)
{
    int size = city.get_size();
    int count_same = 0;
    int count_other = 0;

    for (int i = 0; i < size; i++)
    {
        Citizen* current = &city.citizens[i];
        if (current != this)
        {
            double d = dist(x, y, (*current).get_x(), (*current).get_y());
            if (d < r)
            { 
                if ((*current).get_club() == club) { count_same++;  }
                else                               { count_other++; }
            }
        }
    }

    return count_same - count_other;
}
