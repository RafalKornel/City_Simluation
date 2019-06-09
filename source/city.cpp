#include "city.h"
#include "citizen.h"
#include "utilities.h"
#include "image.h"
#include <iostream>
#include <fstream>
#include <vector>

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
        //(*c).print();
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

void City::print_city()
{
    cout << "Capacity: " << citizens_count << "\nAvg happiness: " << avg_happiness << endl;
    for (int i = 0; i < citizens_count; i++) { citizens[i].print(); }
}

void City::save_to_file()
{
    ofstream* streams[2] = { new ofstream("gp/green.txt"), new ofstream("gp/red.txt") };

    for (int i = 0; i < citizens_count; i++)
    {
        Citizen* current = &citizens[i];
        int club = (*current).get_club();

        *streams[club] << (*current).get_x() << ' ' <<  (*current).get_y() << endl;    
    }

    for (int i = 0; i <=1; i++) { (*streams[i]).close(); }
}

void City::save_and_draw()
{
    this->save_to_file();

    ofstream script("gp/skrypt.gp");
    script << "plot \"gp/green.txt\" with points pointtype 7,\"gp/red.txt\" with points pointtype 7 \n"
           << "pause -1 \"Wciśnij ENTER\n\"" << endl;
    system("gnuplot gp/skrypt.gp");
    script.close();

}

void City::init_from_file(string filename)
{
    ifstream file(filename);
    vector<Citizen> temp_citizens;
    double temp_x = -1;
    double temp_y = -1;
    string temp_club = "_";

    if (!file.is_open()) { cout << "Error opening file" << endl; }

    while(file >> temp_x >> temp_y >> temp_club)
    {
        cout << temp_x << '\t' << temp_y << '\t' << temp_club << endl;

        if (temp_x < 0 || temp_y < 0 || temp_x > map_size || temp_y > map_size)
        {
            cout << "Wrong input!" << endl;
            break;
        }

        if (temp_club != "Legia" & temp_club != "Polonia")
        {
            cout << "Assign citizen to club? [y/n]" << endl;
            string control;
            cin >> control;
            if (control != "y" & control != "Y") { break; }
            do
            {
                cout << "Which club? [Legia/Polonia]" << endl;
                cin >> control;

            } while (control != "Legia" & control != "Polonia");
            
            temp_club = control;           
        }

        int int_club;

        if (temp_club == "Legia") { int_club = 0; }
        else                      { int_club = 1; }

        temp_citizens.push_back(Citizen(temp_x, temp_y, int_club));
    }

    citizens_count = temp_citizens.size();
    citizens = (Citizen*)malloc(sizeof(Citizen) * citizens_count);
    copy(temp_citizens.begin(), temp_citizens.end(), citizens);

    file.close();

    print_city();
}

void City::save(string filename, int res, int r)
{
    Image im(res, res);
    im.fill(citizens, citizens_count, r, map_size, map_size);
    im.save(filename);

}