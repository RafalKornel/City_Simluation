#include "utilities.h"
#include "city.h"
#include "citizen.h"
#include <iostream>
using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
    return pow( pow(x1-x2, 2) + pow(y1-y2, 2), 0.5 );
}

double generate()
{
    return (double(rand())/RAND_MAX);
}

void script()
{  
    double size = 25;
    double dist = 1;
    double ratio = 0.5;
    int citizens_count = 1000;
    int years = 5;
    int res = 600;
    bool load_from_file = false;
    bool defaults = false;
    bool visualize = false;
    string filename;
    string temp_inp;

    do{
        cout << "\nDo you want to load city from file? (y/n)" << endl;
        cin >> temp_inp;
        if (temp_inp == "y" || temp_inp == "Y" ) { load_from_file = true; }
    } while (temp_inp != "y" & temp_inp != "Y" & temp_inp != "n" & temp_inp != "N");

    if (!load_from_file)
    {
        do{
            cout << "\nDo you want to load default values?" << endl
                << "Citizens count:" << citizens_count << endl
                << "Years: " << years << endl
                << "Map size: " << size << endl
                << "Radius: " << dist << endl
                << "Legia fans to Polonia fans ratio: " << ratio << endl
                << "Resolution: " << res << endl
                << "No loading from file" << endl
                << "(y/n): " << endl;
            cin >> temp_inp;
            if (temp_inp == "y" || temp_inp == "Y" ) { defaults = true; }
        } while (temp_inp != "y" & temp_inp != "Y" & temp_inp != "n" & temp_inp != "N");

        if (!defaults) 
        {
            do{
                cout << "\nPlease insert number of the citizens (1000 by default): " << endl;
                cin >> citizens_count;
            } while (citizens_count <= 0);

            do{
                cout << "\nPlease insert number of years to simulate (5 by default): " << endl;
                cin >> years;
            } while (years <= 0);

            do{
                cout << "\nPlease insert map size (25.0 by default): " << endl;
                cin >> size;
            } while (size <= 0);

            do{
                cout << "\nPlease insert radius size (1.0 by default): " << endl;
                cin >> dist;
            } while (dist <= 0);

            do{
                cout << "\nPlease insert ratio of Legia fans to Polonia fans (0.5 by default): " << endl;
                cin >> ratio;
            } while (ratio <= 0 || ratio > 1);

            do{
                cout << "\nPlease insert image resolution in pixels (600px by default): " << endl;
                cin >> res;
            } while (res <= 0);
        }
    }

    else
    {
       do{
            cout << "\nPlease insert number of years to simulate (5 by default): " << endl;
            cin >> years;
        } while (years <= 0);
    }
       
    #ifdef map_size
    #undef map_size
    #endif

    #ifdef max_dist
    #undef max_dist
    #endif

    #define map_size #size
    #define max_dist #dist 

    City warsaw(citizens_count);

    if (load_from_file)
    {
        cout << "\nPlease insert filename: " << endl;
        cin >> temp_inp;
        bool control = warsaw.init_from_file(temp_inp);
        if (!control) { return; }
    }
    else
    {
        warsaw.populate(ratio);
    }
    
    string out_filename = "out.ppm";

    for(int i = 0; i < years; i++)
    {
        if (i % 5 == 0)
        {
            string temp = to_string(i) + out_filename;
            //cout << temp << endl;
            warsaw.save(temp, res, 4);
        }
        warsaw.evolve();
        cout << "Current year: " << i + 1 << ' ' << '\t';
        warsaw.show_avg_happiness();
    }  

    do{
        cout << "\nDo you want to visualize simulation in gnuplot? (y/n):" << endl;
        cin >> temp_inp;
        if (temp_inp == "y" || temp_inp == "Y" ) { visualize = true; }
    } while (temp_inp != "y" & temp_inp != "Y" & temp_inp != "n" & temp_inp != "N");

    if (visualize)
    {
        warsaw.save_and_draw();
    }
}