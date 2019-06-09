#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "city.h"
#include "citizen.h"
#include "image.h"

using namespace std;

int main()
{
    srand(time(0));
    enum clubs {Legia, Polonia};

    // Test1
    //City berlin;
    //berlin.init_from_file("test.txt");

    City warsaw(10000);
    warsaw.populate();
    string filename = "out.ppm";

    for(int i = 0; i < 10; i++)
    {
        warsaw.evolve();
        warsaw.show_avg_happiness();
        string temp = to_string(i) + filename;
        cout << temp << endl;
        warsaw.save(temp, 800, 4);
    }
    
    warsaw.save_and_draw();

    //for (int i = 0; i < warsaw.get_size(); i++) { warsaw.citizens[i].print(); }

    //warsaw.evolve(2);
    //warsaw.show_avg_happiness();
    //cout << warsaw.citizens[1].happiness(warsaw, 1.0) << endl;
    

    return 0;
}
