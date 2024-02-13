#include <stdio.h>
#include <stdbool.h>

struct Player
{
  char symbol;
  int score;
};

void showGame(char[], int);
int checkVictory(char[]);
bool checkPositions(char[], int);

int main()
{
  char positions [9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  int size = sizeof(positions)/sizeof(positions[0]);
  
  int position;

  struct Player player1;
  player1.symbol = 'x';
  player1.score = 0;

  struct Player player2;
  player2.symbol = 'o';
  player2.score = 0;

  bool close = false;
  int turn = 0;

  while(true)
  { 
    showGame(positions, size);
    bool victory = checkVictory(positions);
    if(victory == 1)
    {
      player1.score += 1;
      break;
    }
    else if(victory == 2)
    {
      player2.score += 1;
      break;
    }

    if(turn == 0)
    {
      printf("Player 1 turn: \n");
      printf("Enter a position: \n");
      scanf("%d", &position);
      if(checkPositions(positions, position))
      {
        positions[position-1] = player1.symbol;
        turn = 1;
      }
    }
    else
    {
      printf("Player 2 turn: \n");
      printf("Enter a position: \n");
      scanf("%d", &position);
      if(checkPositions(positions, position))
      {
        positions[position-1] = player2.symbol;
        turn = 0;
      }
    }

  }

  return 0;
}

void showGame(char positions[], int size)
{
  printf(
    " %c | %c | %c \n"
    "-----------\n"
    " %c | %c | %c \n"
    "-----------\n"
    " %c | %c | %c \n",
    positions[0],positions[1],positions[2],
    positions[3],positions[4],positions[5],
    positions[6],positions[7],positions[8]
  );
}

int checkVictory(char positions[]){
  if(
    positions[0] == 'x' && positions[1] == 'x' && positions[2] == 'x'
    ||
    positions[3] == 'x' && positions[4] == 'x' && positions[5] == 'x'
    ||
    positions[6] == 'x' && positions[7] == 'x' && positions[8] == 'x'
    ||
    positions[0] == 'x' && positions[3] == 'x' && positions[6] == 'x'
    ||    
    positions[1] == 'x' && positions[4] == 'x' && positions[7] == 'x'
    ||
    positions[2] == 'x' && positions[5] == 'x' && positions[8] == 'x'
    ||
    positions[0] == 'x' && positions[4] == 'x' && positions[8] == 'x'
    ||
    positions[2] == 'x' && positions[4] == 'x' && positions[6] == 'x'
  )
  {
    printf("Player 1 won\n");
    return 1;
  }
  else if(
    positions[0] == 'o' && positions[1] == 'o' && positions[2] == 'o'
    ||
    positions[3] == 'o' && positions[4] == 'o' && positions[5] == 'o'
    ||
    positions[6] == 'o' && positions[7] == 'o' && positions[8] == 'o'
    ||
    positions[0] == 'o' && positions[3] == 'o' && positions[6] == 'o'
    ||    
    positions[1] == 'o' && positions[4] == 'o' && positions[7] == 'o'
    ||
    positions[2] == 'o' && positions[5] == 'o' && positions[8] == 'o'
    ||
    positions[0] == 'o' && positions[4] == 'o' && positions[8] == 'o'
    ||
    positions[2] == 'o' && positions[4] == 'o' && positions[6] == 'o'
  )
  {
    printf("Player 2 won\n");
    return 1;
  }
  else
  {
    return 0;
  }
}

bool checkPositions(char positions[], int position)
{
  if(positions[position-1] == 'x' || positions[position-1] == 'o')
  {
    printf("Spot already filled\n");
    return false;
  }
  return true;
}