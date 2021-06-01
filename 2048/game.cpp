#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "grid.h"
#include "game.h"

using namespace std;

//konstruktor
Game::Game()
{
    score = 0;
    boardsize = 0;
}

//destruktor
Game::~Game()
{
}

void Game::initializeBoard(int size)
{
    board.allocate(size);
    board.initialize();
    boardsize = size;
}


void Game::addTile()
{
    board.placeTile(board.makeTile());
}


void Game::printBoard()
{
    board.print();
}


int Game::getScore()
{
    return score;
}


void Game::moveLeft()
{
    //wykonuje iteracjê raz dla ka¿dego kwadratu, aby zapewniæ przesuniêcie wszystkich wartoœci
    int count = 0;
    while (count < boardsize)
    {

        for (int i = 0; i < boardsize; i++)
        {
            for (int j = 0; j < (boardsize - 1); j++)
            {
                //jeœli kwadrat jest pusty, przesuñ kwadrat po prawej stronie
                if (board.read(i, j) == 0)
                {
                    int num = board.read(i, (j + 1));
                    board.writeElement(num, i, j);
                    board.writeElement(0, i, (j + 1));
                }
            }
        }
        count++;
    }
}


void Game::moveUp()
{
    int count = 0;
    while (count < boardsize)
    {
        for (int j = 0; j < boardsize; j++)
        {
            for (int i = 0; i < (boardsize - 1); i++)
            {
                if (board.read(i, j) == 0)
                {
                    int num = board.read((i + 1), j);
                    board.writeElement(num, i, j);
                    board.writeElement(0, (i + 1), j);
                }
            }
        }
        count++;
    }
}


void Game::moveDown()
{
    int count = 0;
    while (count < boardsize)
    {
        for (int j = 0; j < boardsize; j++)
        {
            for (int i = (boardsize - 1); i > 0; i--)
            {
                if (board.read(i, j) == 0)
                {
                    int num = board.read((i - 1), j);
                    board.writeElement(num, i, j);
                    board.writeElement(0, (i - 1), j);
                }
            }
        }
        count++;
    }
}


void Game::moveRight()
{
    int count = 0;
    while (count < boardsize)
    {
        for (int i = 0; i < boardsize; i++)
        {
            for (int j = (boardsize - 1); j > 0; j--)
            {
                if (board.read(i, j) == 0)
                {
                    int num = board.read(i, (j - 1));
                    board.writeElement(num, i, j);
                    board.writeElement(0, i, (j - 1));
                }
            }
        }
        count++;
    }
}


void Game::sumUp()
{
    for (int j = 0; j < boardsize; j++)
    {
        for (int i = 0; i < (boardsize - 1); i++)
        {
            if (board.read(i, j) == board.read((i + 1), j))
            {
                int num = (board.read((i + 1), j) + (board.read(i, j)));
                score = (score + num);
                board.writeElement(num, i, j);
                board.writeElement(0, (i + 1), j);
            }
        }
    }
}


void Game::sumDown()
{
    for (int j = 0; j < boardsize; j++)
    {
        for (int i = (boardsize - 1); i > 0; i--)
        {
            if (board.read(i, j) == board.read((i - 1), j))
            {
                int num = board.read((i - 1), j) + (board.read(i, j));
                score = (score + num);
                board.writeElement(num, i, j);
                board.writeElement(0, (i - 1), j);
            }
        }
    }
}


void Game::sumRight()
{
    for (int i = 0; i < boardsize; i++)
    {
        for (int j = (boardsize - 1); j > 0; j--)
        {
            if (board.read(i, j) == board.read(i, (j - 1)))
            {
                int num = (board.read(i, (j - 1)) + (board.read(i, j)));
                score = (score + num);
                board.writeElement(num, i, j);
                board.writeElement(0, i, (j - 1));
            }
        }
    }
}


void Game::sumLeft()
{
    for (int i = 0; i < boardsize; i++)
    {
        for (int j = 0; j < (boardsize - 1); j++)
        {
            if (board.read(i, j) == board.read(i, (j + 1)))
            {
                int num = (board.read(i, (j + 1)) + (board.read(i, j)));
                score = (score + num);
                board.writeElement(num, i, j);
                board.writeElement(0, i, (j + 1));
            }
        }
    }
}


bool Game::gameOver()
{
    //gra konczy sie gdy wszystkie pola sa zajete
    for (int i = 0; i < boardsize; i++)
    {
        for (int j = 0; j < (boardsize); j++)
        {
            if (board.read(i, j) == 0)
            {
                return false;
            }
        }
    }
    return true;
}
