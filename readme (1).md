# C project - SUPER MARIO

Welcome to SUPER MARIO!!
This is a reference for setting up a C project. It contains almost all of the attributes and flexibilities provided by C language.This game is a 2D platformer where the player moves through an obstacle filled map created by a tilemap, must reach the end of the map to progress to the next level. The maps also have enemies which damage the player and decreases his lives if they make contact. The levels are all random as well as the enemies so, every level is different from the next. 

### Guidline to Installation
- Platform : Windows 
- Libraries : SFML
- Tool : Microsoft Visual Studio

    Here is the guidline how to run it:

- As it is a Visual Studio Project you have to Download visual studio first from this link: https://visualstudio.microsoft.com/downloads/

- Then you have to install it. Here is a procedure how to install it: https://docs.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=vs-2017

- Now, you have to open the solution file using visual studio. For this go to your download location and then .../Game/Game.sln

- Now go to Game properties and now go to 
configuration properties->  C/C++ -> General -> Additional Include Directories

- And now change the directory to ...../Game/SFML/include

- Now go to
configuration properties->  Linker -> General -> Additional Library Directories

- And now change the directory to ...../Game/SFML/lib

### Documentation
- The codes of the project have been designed primarily among 6 header files and a cpp file associated with it.
-The execution of the project starts with the "Source.cpp" file and from there the execution branches out among the other header files.
- "Menu.h" contains the the main menu of the game
- "Tilemaps.h" contains the map of the game
- "Collision.h" contains the functions for detecting collisions
- "Save.h" contains the program of saving the game
- "quit.h" contains a new window for closing the game

### Features
  - Menu:  The game’s starting screen features a menu containing “Continue”, “New Game”, “Highest Score” and “Quit”. All the games features can be used via the menu. 
            


- Simple 2D movement:  The game’s playable character can move left or right in any direction of the map. It can also jump up or down as long as the character is on the ground or on top of a block.
            


-   Randomized levels: Every time a new game is started or a new level is loaded, the level loaded is always completely random. The objects, coins , interactable objects are all set within the level randomly. This ensures gameplay will never be repetitive. 

-   Automatically spawning enemies:  There are two types of enemies in this game : mushrooms and bullets. The mushrooms are automatically spawned in front of the player as he progresses. The bullets randomly spawn at a location in front of the player and progress until they reach the end of the viewing screen.


-  Collision with map objects : In this game, both players and enemies are capable of interacting with the map objects. Different objects show different reactions to collision. The player or enemy’s movement is blocked if any block is in the way. Also, players can collect coins to increase their score.



-  Interaction with enemies: Players can interact with enemies if they mutually touch. The player’s life is decreased by 1 if an enemy touches them. After touching, for a brief period of time the player becomes transparent and no lives are lost if the enemy touches them during this period.



-   Player camera and on-screen text: The viewpoint or camera of the player always moves alongside it. There are text which follow the user on both sides of the screen. The show the score, lives, time elapsed and current level. As the player progresses, the text is automatically updated.

-   Saving scores : The score of the player is compared to the highest score stored in the file. If it is higher, a prompt is shown to enter the player’s name. The name and score are then stored in the file. This information can be seen in the “Highscore” menu option.

-  Saving progress : If the player quits the game after saving and clicks the “Continue” option in the menu, the player will start from the same phase he exited.



### Credits
Mohammad Wakilur Islam
Tanzimul Hoque

Batch 24
Department of Computer Science & Engineering
University of Dhaka
Bangladesh



