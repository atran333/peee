#include <iostream>
#include "../header/Game.hpp"




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
    while(game.running())
    {
      game.updateDeltaTime();
      game.update();
      game.render();
    }
    return 0;
}
