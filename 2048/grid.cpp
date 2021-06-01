#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "grid.h"

using namespace std;

//konstruktor
Grid::Grid()
{
    size = 0;
    grid = NULL;
}

//destruktor
Grid::~Grid()
{
    for (int i = 0; i < size; ++i)
    {
        delete[] grid[i];
    }
    delete[] grid;
}

//tworzenie siatki
void Grid::allocate(int input)
{
    size = input;
    grid = new int *[size];
    for (int i = 0; i < size; i++)
    {
        grid[i] = new int[size];
    }
}

//generator liczb - 90% ze to bedzie 2
int Grid::makeTile()
{
    srand(time(NULL));
    int prob = rand() % 10;

    if (prob < 8)
    {
        return 2;
    }
    else
    {
        return 4;
    }
}

//umieszcza liczbe w pustym miejscu
void Grid::placeTile(int tile)
{
    int coin;
    bool placed = false;
    while (!placed)
    {
        coin = rand() % 2;
        if (coin == 1)
        {
            placed = placeRow(tile);
        }
        else
        {
            placed = placeCol(tile);
        }
    }
}

//losowe umieszaczanie nowych liczb w wierszu
bool Grid::placeRow(int tile)
{
    int row = rand() % (size - 1);
    int coin = rand() % 2;
    if (coin == 1)
    {
        if (grid[row][0] == 0)
        {
            grid[row][0] = tile;
            return true;
        }
    }
    else
    {
        if (grid[row][(size - 1)] == 0)
        {
            grid[row][(size - 1)] = tile;
            return true;
        }
    }
    return false;
}

//losowe umieszaczanie nowych liczb w kolumnie
bool Grid::placeCol(int tile)
{
    int col = rand() % (size - 1);
    int coin = rand() % 2;
    if (coin == 1)
    {
        if (grid[0][col] == 0)
        {
            grid[0][col] = tile;
            return true;
        }
    }
    else
    {
        if (grid[(size - 1)][col] == 0)
        {
            grid[(size - 1)][col] = tile;
            return true;
        }
    }
    return false;
}

//tworzenie pustej planszy
void Grid::initialize()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }
    grid[size - 1][0] = 2;
    grid[0][0] = 2;
}

//rysowanie siatki planszy
void Grid::print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // X zamiast pustego pola
            if (grid[i][j] == 0)
            {
                cout << 'X';
            }
            else
            {
                cout << grid[i][j];
            }

            //formatowanie pustych miejsc, zeby bylo rowno
            if (grid[i][j] < 10)
            {
                cout << "     ";
            }
            else if (grid[i][j] < 100 && grid[i][j] > 9)
            {
                cout << "    ";
            }
            else if (grid[i][j] < 1000 && grid[i][j] > 99)
            {
                cout << "   ";
            }
            else if (grid[i][j] < 10000 && grid[i][j] > 999)
            {
                cout << "  ";
            }
            else
            {
                cout << " ";
            }
        }
        // nowy wers planszy
        cout << "\n"
                "\n";
    }
}


int Grid::read(int row, int col)
{
    return grid[row][col];
}


void Grid::writeElement(int num, int row, int col)
{
    grid[row][col] = num;
}


int Grid::getSize()
{
    return size;
}
