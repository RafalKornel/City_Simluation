#include <string>
using namespace std;

class Citizen;

const double map_size = 12.5; // using const in order to avoid multiple declaration

class City
{
    int citizens_count;
    double avg_happiness;
    void populate(double percent);
    

    public:
        void save_to_file();
        Citizen* citizens;
        City(int citizens_count);
        City(int citizens_count, double percent);
        ~City() = default;

        void populate();
        void evolve();
        void evolve(int steps);
        
        int get_size();
        void show_avg_happiness();
        void save_and_draw();
};