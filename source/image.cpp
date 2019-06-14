#include "image.h"
#include "citizen.h"
#include "utilities.h"
#include <iostream>
#include <fstream>

using namespace std;

Image::Image(int width, int height)
{
    h = height;
    w = width;

    im = (int**)malloc(sizeof(int*) * height);
    for (int y = 0; y < height; y++)
    {
        im[y] = (int*)malloc(sizeof(int) * width);
    }
}

void Image::show_arr()
{
    for (int y = 0; y < h; y++)
    {
        cout << y << '\t';
        for (int x = 0; x < w; x++)
        {
            cout << im[y][x] << ' ';
        }
        
        cout << endl;
    }   
}

void Image::fill(Citizen* citizens, int c_count, int radius, int max_width, int max_height)
{
    for (int i = 0; i < c_count; i++)
    {
        int c_x = int(w/max_width  * citizens[i].get_x());
        int c_y = int(h/max_height * citizens[i].get_y());
        int temp_x, temp_y;

        for(int y = -radius; y <= radius; y++)
        {
            for(int x = -radius; x <= radius; x++)
            {
                double d = dist(x, y, 0, 0);
                temp_x = c_x + x;
                temp_y = c_y + y;
                if (temp_x >= 0 & temp_x < w & temp_y >= 0 & temp_y < h)
                {
                    if (d <= radius) { im[temp_y][temp_x] = citizens[i].get_club() + 1; }
                }
            }
        }
    }
}

void Image::save(string filename)
{
    ofstream file(filename);
    file << "P3\n" << w << '\t' << h << "\n255" << endl;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int r, g, b;
            r = 255;
            b = 255;
            g = 255;
            if (im[y][x] == 1) 
            { 
                r = 255;
                b = 0;
                g = 0;
            }
            if (im[y][x] == 2)
            { 
                r = 0;
                b = 255;
                g = 0;
            }

            file << r << '\t' << g << '\t' << b << endl;
        }
    }

    file.close();
}