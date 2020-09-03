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
        //create a function that makes a random 2 or 4 appear somewhere on the board
        //check how to use valgrind so no memory is leaking 
        int** board;
        int* size;
};

#endif
