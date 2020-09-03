#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;


class Game {
    public:
        Game(); //constructor
        ~Game(); //destructor
        void play(); 
    private:
        void printBoard();
        void print_number(string num);
        
        
        void move_left(int i);
        void move_right(int i);
        
        
        void move_up(int j);
        void move_down(int j);
        
        bool gameover();
        void add_two();
        
        int** board; //by making board a double pointer we can dereference twice
                     //and use it as a normal 2d array 
        int* size;
};

#endif
