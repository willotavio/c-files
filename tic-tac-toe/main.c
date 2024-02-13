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
void clearGame(char*, int);
bool checkDraw(char[], int);

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

  int play = true;
  while(play)
  { 
    int option;
    int turn = 0;
    printf("Player 1 score: %d\nPlayer 2 score: %d\n", player1.score, player2.score);
    printf("1. Play\n2. Quit\n");

    scanf("%d", &option);
    bool gameEnd = false;

    switch(option)
    {
      case 1:
        while(!gameEnd)
        {
          showGame(positions, size);
          int victory = checkVictory(positions);
          if(victory == 1)
          {
            printf("Player 1 won\n");
            player1.score += 1;
            gameEnd = true;
            clearGame(positions, size);
            break;
          }
          else if(victory == 2)
          {
            printf("Player 2 won\n");
            player2.score += 1;
            gameEnd = true;
            clearGame(positions, size);
            break;
          }

          bool draw = checkDraw(positions, size);
          if(draw)
          {
            printf("Draw\n");
            gameEnd = true;
            clearGame(positions, size);
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
            else
            {
              printf("Spot already filled\n");
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
            else
            {
              printf("Spot already filled\n");
            }
          }
        }
        break;

      case 2:
        printf("Quitting");
        play = false;
        break;

      default:
        break;
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
    return 2;
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
    return false;
  }
  return true;
}

void clearGame(char *positions, int size)
{
  for(int i = 0; i < size; i++)
  {
    positions[i] = ' ';
  }
}

bool checkDraw(char positions[], int size)
{
  for(int i = 0; i < size; i++)
  {
    if(positions[i] == ' ')
    {
      return false;
    }
  }
  return true;
}