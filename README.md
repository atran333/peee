# Boss Baby: Working Title
 
 Authors: 
 -  [Joshua Candelaria](https://github.com/jecndlria)
 -  [Vinz Madrigal](https://github.com/mvinzangelo) 
 -  [Ashwin Jagadish](https://github.com/ashwinjagadish1) 
 -  [Andy Tran](https://github.com/atran333)
 
## Project Description
We developed a game engine from scratch using C++ and the SFML graphics library. With this game engine, other users can utilize it by creating their own top down roguelike roleplaying game. This project is interesting to us because instead of using existing technologies and game engines, we created our own, which allows us to have a greater control over the backend of our game. We used Visual Studio for text editing, Git/GitHub for version control, and the SFML graphics library for sprite rendering. The input of our game will be user keystrokes, and the output will be the interactions of ingame objects with each other. 

## Class Diagram
![](CS100%20Final%20Project%20UML%20Class%20Diagram.png?raw=true)
In our UML Class Diagram, we implemented 3 specific design patterns. We included one composite pattern (GuiElement) and two strategy pattern (GuiStyle adn GameComponent).
For the GameComponent part of our UML Class Diagram, Game Class acts as the context in this composite pattern. It declares our interface and default behaviors for the rest of our program. The Composite would be the GameObject Class. The GameObject Class stores children of the GameComponent class through a vector of GameComponents. It also holds various GameComponent (children) related operations including set and get accessor methods. By utilizing our GameComponent class, we were also able to test Movement and Audio which express behaviors and act on those operations provided by the GameComponent class. 

The scene is a composition of the GUI and GameObject classes that essentially creates different scenes and gives us the ability to organize our various classes into their individual groups so that they can be shown together based on the state of our game

For the GUI portion of the UML diagram, we utilized the strategy pattern by abstracting the draw pattern for the different GUI components. Depending on the strategy, the GUI components will either be shown like a menu or an in-game user interface. We use the same draw function for two different algorithms. The canvas is also a composition of different GUIElements of different varieties.

 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design patterns did you use? For each design pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design patterns you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your TA you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 ![](unknown.png?raw=true)
 ## Dependencies
`sudo apt-get install libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libglew1.5-dev libjpeg8-dev libsndfile1-dev libopenal-dev libudev-dev libxcursor-dev`
 ## Installation/Usage
 1. Make sure you have the dependencies
 2. Clone repository
 5. Run `cmake .` at {root}
 6. Run `make`
 7. Run `./main` at {root}
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
