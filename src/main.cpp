#include <iostream>
#include "../header/Game.hpp"
#include "../header/Canvas.hpp"

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
    
    GUIStyle* style = new GUIStyle();
    style->subheadingSize = 30;
    Canvas canvas(style);
    GUIElement* button1 = new GUIButton(sf::Vector2f(game.getWindow()->getView().getCenter().x, game.getWindow()->getView().getCenter().y), sf::Vector2f(100, 50), "Start");
    canvas.addElement(button1);

    while(game.running())
    {
      game.updateDeltaTime();
      game.update();
      game.getWindow()->draw(canvas);
      game.render();
    }
    return 0;
}
