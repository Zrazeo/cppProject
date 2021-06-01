#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include "grid.h"

using namespace std;

#ifndef GAME_H_
#define GAME_H_

class Game
{
private:

    int score;

    Grid board;

    string *user_array;
    int *score_array;

    int boardsize;

public:

    Game();
    ~Game();

    void setScore(int);
    int getScore();

    //nowa plansza
    void initializeBoard(int);
    //dodaje kwadraty na planszy
    void addTile();

    //rysuje plansze
    void printBoard();

    bool gameOver();

    //przesuwa liczby i aktualizuje plansze
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void sumUp();
    void sumDown();
    void sumRight();
    void sumLeft();
};

#endif
