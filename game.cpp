#include <iostream>
#include <string>
#include <random>
#include <cstdio>
#include <cstdlib>

#include "game.h"
#include "int-string.h"


using namespace std;


void Game::print_number(string num) {
    printf("%-6s", num.c_str());
}

Game::Game(){ //constructor
  cout << "How long would you like the length to be?" << endl;
  cin >> *size;  
  board = new int*[*size]; //replace it with a 3   

  for (int i = 0; i < *size; i++) {
    board[i] = new int[*size];
  }

for(int i = 0; i < *size; i++){
  for(int j = 0; j < *size; j++){
    board[i][j] = 0;
  }
}
  
  
}

void Game::printBoard(){
  for(int i = 0; i < *size; i++){ //make sure i is less than a pointer later
    for(int j = 0; j < *size; j++){
    if(board[i][j] == 0){
      print_number("-");
    }
    else{
      string asdf = int2string(board[i][j]);
      print_number(asdf); 
    }
  }
  cout << endl;
  }
}


void Game::move_left(int i){
  bool** lilbaby;
  lilbaby = new bool*[*size];

  for (int i = 0; i < *size; i++){
    lilbaby[i] = new bool[*size];
  }
  
  for(int i = 0; i < *size; i++){
    for(int j = 0; j < *size; j++){
      lilbaby[i][j] = false;
    }
  }
  
  int j = 0; 
  while(j < *size){
    if(j == 0){
      j++;
      continue;
    }
    else if(board[i][j] == 0){
      j++;
      continue; 
    }
    else if(board[i][j] % 2 == 0 and board[i][j - 1] == 0){ //if the number to left is a zero
      bool temp;
      temp = lilbaby[i][j-1];
      lilbaby[i][j - 1] = lilbaby[i][j];
      lilbaby[i][j] = temp;
      
      board[i][j - 1] = board[i][j];
      board[i][j] = 0;
      j = 0;
      continue;
    }
    else if(board[i][j] == board[i][j - 1] and lilbaby[i][j] == false and lilbaby[i][j - 1] == false){ //if the two numbers are equal 
      board[i][j-1] += board[i][j];
      board[i][j] = 0;
      lilbaby[i][j-1] = true;
      lilbaby[i][j] = false;
      
      j = 0;
      continue; 
    }
    j++;
  }
  
  // First, we need to recycle the memory for all of the inner arrays.
  for (int i = 0; i < *size; i++) {
    delete [] lilbaby[i];
  }

  // Now, we can recycle the memory for the outer array.
  delete [] lilbaby;
}


void Game::move_right(int i){
  bool** lilbaby;
  lilbaby = new bool*[*size];

  for (int i = 0; i < *size; i++){
    lilbaby[i] = new bool[*size];
  }
  
  for(int i = 0; i < *size; i++){
    for(int j = 0; j < *size; j++){
      lilbaby[i][j] = false;
    }
  }
  
  
  int j = (*size) - 1; //3
  while(j > -1){
    if(j == (*size) - 1){ //3
      j--;
      continue;
    }
    else if(board[i][j] == 0){
      j--;
      continue; 
    }
    else if(board[i][j] % 2 == 0 and board[i][j + 1] == 0){ //if the number to right is a zero
      
      bool temp;
      temp = lilbaby[i][j + 1];
      lilbaby[i][j + 1] = lilbaby[i][j];
      lilbaby[i][j] = temp;
      
      
      board[i][j + 1] = board[i][j];
      board[i][j] = 0;
      j = (*size) - 1;
      continue;
    }
    else if(board[i][j] == board[i][j + 1] and lilbaby[i][j] == false and lilbaby[i][j + 1] == false){ //if the two numbers are equal 
      board[i][j + 1] += board[i][j];
      board[i][j] = 0;
      lilbaby[i][j + 1] = true;
      lilbaby[i][j] = false;
      
      
      j = (*size) - 1;
      continue; 
    }
    j--;
  }
  
  // First, we need to recycle the memory for all of the inner arrays.
  for (int i = 0; i < *size; i++) {
    delete [] lilbaby[i];
  }

  // Now, we can recycle the memory for the outer array.
  delete [] lilbaby;
  
}


void Game::move_up(int j){ //keep j constant 
  bool** lilbaby;
  lilbaby = new bool*[*size];

  for (int i = 0; i < *size; i++){
    lilbaby[i] = new bool[*size];
  }
  
  for(int i = 0; i < *size; i++){
    for(int j = 0; j < *size; j++){
      lilbaby[i][j] = false;
    }
  }
  
  int i = 0;
  while(i < *size){
    if(i == 0){
      i++;
      continue;
    }
    else if(board[i][j] == 0){
      i++;
      continue;
    }
    else if(board[i][j] % 2 == 0 and board[i - 1][j] == 0){
      bool temp;
      temp = lilbaby[i - 1][j];
      lilbaby[i - 1][j] = lilbaby[i][j];
      lilbaby[i][j] = temp;
      
      
      board[i - 1][j] = board[i][j];
      board[i][j] = 0;
      i = 0;
      continue;
    }
    else if(board[i][j] == board[i - 1][j] and lilbaby[i][j] == false and lilbaby[i - 1][j] == false){ //if the two numbers are equal 
      board[i - 1][j] += board[i][j];
      board[i][j] = 0;
    
      lilbaby[i - 1][j] = true;
      lilbaby[i][j] = false;
      i = 0;
      continue; 
    }
    i++;
  }
  
  // First, we need to recycle the memory for all of the inner arrays.
  for (int i = 0; i < *size; i++) {
    delete [] lilbaby[i];
  }

  // Now, we can recycle the memory for the outer array.
  delete [] lilbaby;
}


void Game::move_down(int j){ //going to be similar to moving right since u have to start from bottom 
  
  bool** lilbaby;
  lilbaby = new bool*[*size];

  for (int i = 0; i < *size; i++){
    lilbaby[i] = new bool[*size];
  }

  for(int i = 0; i < *size; i++){
    for(int j = 0; j < *size; j++){
      lilbaby[i][j] = false;
    }
  }


  int i = (*size) - 1; //3
  while(i > -1){
    if(i == *size - 1){
      i--;
      continue;
    }
    else if(board[i][j] == 0){
      i--;
      continue;
    }
    else if(board[i][j] % 2 == 0 and board[i + 1][j] == 0){
      bool temp;
      temp = lilbaby[i + 1][j];
      lilbaby[i + 1][j] = lilbaby[i][j];
      lilbaby[i][j] = temp;
      
      
      board[i + 1][j] = board[i][j];
      board[i][j] = 0;
      i = (*size) - 1;
      continue;
    }
    else if(board[i][j] == board[i + 1][j] and lilbaby[i][j] == false and lilbaby[i + 1][j] == false){ //if the two numbers are equal 
      board[i + 1][j] += board[i][j];
      board[i][j] = 0;
    
      lilbaby[i + 1][j] = true;
      lilbaby[i][j] = false;
      i = (*size) - 1;
      continue; 
    }
    i--;
  }
  
  // First, we need to recycle the memory for all of the inner arrays.
  for (int i = 0; i < *size; i++) {
    delete [] lilbaby[i];
  }

  // Now, we can recycle the memory for the outer array.
  delete [] lilbaby;
}


bool Game:: gameover(){
  while(true){
    
    for(int i = 0; i < *size; i++){
      for(int j = 0; j < *size; j++){
        if(board[i][j] == 0){
          return false;
        }
    }
  }
    for(int i = 0; i < *size; i++){
      for(int j = 0; j < *size; j++){
        if(j == 0){
          continue;
        }
        if(board[i][j] == board[i][j - 1]){
          return false;
        }  
      }
    }
  
  for(int i = 0; i < *size; i++){
    for(int j = 0; j < *size; j++){
      if(j == 0){
        continue;
      }
      if(board[j][i] == board[j - 1][i]){
        return false;
        }
      }
    }
    return true;
  }
}

void Game::add_two(){ //randomly add a two anywhere to the board after every turn
    while(true){
      random_device rd; //obtain a random number from hardware
      mt19937 gen(rd()); //seed the generator
      int counter = (*size) * (*size) - 1; 
      uniform_int_distribution<> distr(0, counter); //define the range of board
      int random_spot = distr(gen);
      
      int row = random_spot / *size;
      int col = random_spot % *size;
      
      
      if(board[row][col] == 0){
          board[row][col] = 2;
          return;
      }
      else{
        continue;
      }
  }
}

void Game::play(){
  string turn;
  add_two();
  while(!gameover()){ //replace with gameover function when completed 
    add_two();
    if(gameover()){
      printBoard();
      cout << "Game Over" << endl;
      exit(1);
    }
    printBoard();
    cin >> turn;
  if(turn == "a"){ //left
    for(int i = 0; i < *size; i++){
      move_left(i);
    }
  }
  else if(turn == "d"){ //right
    for(int i = 0; i < *size; i++){
      move_right(i);//didnt compile yet only tried for first row it worked up until then
    }
  }
  else if(turn == "w"){
    for(int j = 0; j < *size; j++){
      move_up(j);
    }
  }
  else if(turn == "s"){
    for(int j = 0; j < *size; j++){
      move_down(j);
    }
  }
  else if(turn == "q"){
    exit(1);
    }
  else if(turn == "g"){
    cout << gameover() << endl;
    }
  else if(turn == "p" ){
    break; 
    }
  else if(turn == "z"){
    add_two();
    }    
  }
}

Game::~Game(){

  // First, we need to recycle the memory for all of the inner arrays.
  for (int i = 0; i < *size; i++) {
    delete [] board[i];
  }

  // Now, we can recycle the memory for the outer array.
  delete [] board;
}



