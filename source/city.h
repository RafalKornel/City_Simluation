#include <string>
using namespace std;

const double map_size = 12.5; // using const in order to avoid multiple declaration

class Citizen;

class City
{
    int citizens_count;
    double avg_happiness;
    void populate(double percent);
    void print_city();
    

    public:
        void save_to_file();
        Citizen* citizens;
        City(int citizens_count);
        City(int citizens_count, double percent);
        City() = default;
        ~City() = default;

        void populate();
        void evolve();
        void evolve(int steps);
        
        int get_size();
        void save(string filename, int res, int radius);
        void show_avg_happiness();
        void save_and_draw();
        void init_from_file(string filename);
};