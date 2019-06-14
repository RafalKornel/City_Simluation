#include <string>
using namespace std;

//double map_size = 25; // using const in order to avoid multiple declaration

#define map_size 25

class Citizen;

class City
{
    int citizens_count;
    double avg_happiness;
    void print_city();
    

    public:
        void save_to_file();
        Citizen* citizens;
        City(int citizens_count);
        City(int citizens_count, double percent);
        City() = default;
        ~City() = default;

        void populate();
        void populate(double percent);
        void evolve();
        void evolve(int steps);
        
        int get_size();
        void save(string filename, int res, int radius);
        void show_avg_happiness();
        void save_and_draw();
        bool init_from_file(string filename);
};