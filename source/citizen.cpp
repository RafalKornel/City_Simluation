#include "citizen.h"
#include "city.h"
#include "utilities.h"
#include <iostream>
#include <cmath>

//double max_dist = 1.0;

Citizen::Citizen(double a, double b, int c)
{
    x = a;
    y = b;
    club = c;
}

Citizen::Citizen()
{
    x = generate() * map_size;
    y = generate() * map_size;
    club = rand()%2;
    //cout << "Konstruktor  " << x << '\t' << y << '\t' << club << endl;
}

Citizen::Citizen(int club)
{
    x = generate() * map_size;
    y = generate() * map_size;
    this->club = club;
}

Citizen::Citizen(double p)
{
    x = generate() * map_size;
    y = generate() * map_size;
    double roll = generate();
    if (roll <= p) { club = 0; }
    else { club = 1; }
}

double Citizen::get_x() { return x; }

double Citizen::get_y() { return y; }

int Citizen::get_club() { return club; }

int Citizen::get_happiness() { return happiness; }

void Citizen::print()
{
    cout << "x: " << x << '\t'
         << "y: " << y << '\t'
         << "club: " << club << '\t'
         << "adress: " << this << endl;
}

int Citizen::calc_happiness(City city, double r)
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

    happiness = count_same - count_other;
    return count_same - count_other;
}

void Citizen::removal()
{
    double phi = generate() * M_PI;
    double temp_x = max_dist * cos(phi) + x;
    double temp_y = max_dist * sin(phi) + y;

    x = fmod(temp_x + map_size, map_size);
    y = fmod(temp_y + map_size, map_size);
    

    /*  // a option => very unefficient

    double temp_x, temp_y, phi;
    do{
        phi = generate() * M_PI;
        temp_x = max_dist * cos(phi) + x;
        temp_y = max_dist * sin(phi) + y;
        //cout << temp_x << '\t' << temp_y << endl;

        //temp_x = generate() * 2 * max_dist - max_dist + x;
        //temp_y = generate() * 2 * max_dist - max_dist + y;
    } while( temp_x > map_size || temp_x < 0 ||
             temp_y > map_size || temp_y < 0 );
    */
}