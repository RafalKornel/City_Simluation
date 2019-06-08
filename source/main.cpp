#include <iostream>
#include <cstdlib>
#include <ctime>
#include "city.h"
#include "citizen.h"

using namespace std;

int main()
{
    srand(time(0));

    City warsaw(1000);
    warsaw.populate();
    for(int i = 0; i < 15; i++)
    {
        warsaw.evolve();
        warsaw.show_avg_happiness();
    }

    warsaw.save_and_draw();

    //for (int i = 0; i < warsaw.get_size(); i++) { warsaw.citizens[i].print(); }

    //warsaw.evolve(2);
    //warsaw.show_avg_happiness();
    //cout << warsaw.citizens[1].happiness(warsaw, 1.0) << endl;
    

    return 0;
}