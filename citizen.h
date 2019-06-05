using namespace std;

const double max_dist = 1.0;

class City;

class Citizen
{
    double x, y;
    int club;

    public:
        Citizen();
        Citizen(double p);
        Citizen(int club);
        Citizen(double x, double y, int club);
        ~Citizen() = default;

        void print();
        int get_club();
        double get_x();
        double get_y();

        int happiness(City city, double radius);
        void removal();
        bool check_bounds();
};