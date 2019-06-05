#include <iostream>
#include <cstdlib>
#include <ctime>
#include "city.h"
#include "citizen.h"

using namespace std;

int main()
{
    srand(time(0));


    City warsaw(250);
    warsaw.populate();
    warsaw.evolve();
    warsaw.show_avg_happiness();
    warsaw.evolve(2);
    //cout << warsaw.citizens[1].happiness(warsaw, 1.0) << endl;
    

    return 0;
}