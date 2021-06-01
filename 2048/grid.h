#include <iostream>

using namespace std;

#ifndef GRID_H_
#define GRID_H_

class Grid
{
private:
    int size;
    int **grid;

public:

    Grid();
    ~Grid();


    int getSize();
    void writeElement(int element, int row, int col);
    void print();
    void initialize();
    void allocate(int);
    int read(int, int);
    int makeTile();
    void placeTile(int tile);
    bool placeRow(int tile);
    bool placeCol(int tile);
};

#endif
