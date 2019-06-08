#include "city.h"
#include "citizen.h"
#include "utilities.h"
#include <iostream>
#include <fstream>

using namespace std;

//double map_size = 25.0;

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
        int cur_hap = citizens[i].calc_happiness(*this, max_dist);
        avg_happiness += cur_hap;
        //cout << "current happiness:\t" << cur_hap << endl; 
    }

    for (int i = 0; i < get_size(); i++)
    {
        if (citizens[i].get_happiness() < 0)
        {
            citizens[i].removal();
        }
    }

    avg_happiness /= get_size();
}

void City::evolve(int n)
{
    for (int i = 0; i < n; i++) { evolve(); }
}

void City::save_to_file()
{
    ofstream* streams[2] = { new ofstream("green.txt"), new ofstream("red.txt") };

    for (int i = 0; i < citizens_count; i++)
    {
        Citizen* current = &citizens[i];
        int club = (*current).get_club();

        *streams[club] << (*current).get_x() << ' ' <<  (*current).get_y() << endl;    
    }
}

void City::save_and_draw()
{
    this->save_to_file();

    ofstream script("skrypt.gp");
    script << "plot \"green.txt\" with points pointtype 7,\"red.txt\" with points pointtype 7 \n"
           << "pause -1 \"Wciśnij ENTER\n\"" << endl;
    system("gnuplot skrypt.gp");

}