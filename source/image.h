#include <string>
using namespace std;

class Citizen;

class Image
{
    int w, h;
    int** im;
    void show_arr();

    public:
        Image(int width, int height);
        void fill(Citizen* citizens, int c_count, int radius, int max_width, int max_height);
        void save(string filename);

};