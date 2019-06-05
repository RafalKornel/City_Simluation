using namespace std;

const double map_size = 25;

class Citizen;

class City
{
    int citizens_count;
    int avg_happiness;
    void populate(double percent);

    public:
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