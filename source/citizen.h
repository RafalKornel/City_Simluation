using namespace std;

const double max_dist = 1.0; // using const in order to avoid multiple declaration

class City;

class Citizen
{
    double x, y;
    int happiness = 0;
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
        int get_happiness();

        int calc_happiness(City city, double radius);
        void removal();
        bool check_bounds();
};