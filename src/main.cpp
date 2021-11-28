#include <iostream>
#include <Game.h>





using namespace std;

#define DEBUG 1

#if DEBUG
  #define LOG(x) (cout << x << endl)
#else
  #define LOG(x) 
#endif


int main() 
{
    Game game;
    game.run();
    return 0;
}
