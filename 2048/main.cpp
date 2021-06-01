#include <iostream>
#include <string>
#include "grid.h"
#include "game.h"

using namespace std;

void parseInput(char input);

//czyszczenie ekranu - imitacja odswiezania
void Clear()
{
    system("clear");
}

int main()
{
    Game game;
    string name;
    int size = 4;
    char input = '0';
    cout << "2048" << endl << endl;
    game.initializeBoard(size);
    game.printBoard();

    cout << "Wcisnij w, a, s, d (do poruszania)";
    cout << " lub q aby wyjsc" << endl;

    while (input != 'q')
    {
        //poruszanie
        cin >> input;
        if (input != 'q' && input != 'w' && input != 's' && input != 'a' && input != 'd')
        {
            cout << "Wcisnij w, a, s, d (do poruszania)";
            cout << " lub q aby wyjsc" << endl;
        }

        else
        {
            if (input == 'q')
            {
                break;
            }
            if (input == 'a')
            {
                game.moveLeft();
                game.sumLeft();
//                game.moveLeft();
            }
            if (input == 'w')
            {
                game.moveUp();
                game.sumUp();
//                game.moveUp();
            }
            if (input == 's')
            {
                game.moveDown();
                game.sumDown();
//                game.moveDown();
            }
            if (input == 'd')
            {
                game.moveRight();
                game.sumRight();
//                game.moveRight();
            }

            //odswiezanie po kazdym ruchu
            Clear();
            game.addTile();
            game.printBoard();

            if (game.gameOver() == true)
            {
                break;
            }

            cout << "Wynik: " << game.getScore() << endl
                 << "Nastepny ruch to? (w, s, a, d) ..." << endl;
        }
    }

    cout << "Koniec gry. Wynik: " << game.getScore() << endl;
    return 0;
}
