## OOP 1 - Project 1 - Super Pac-Man

### README

====================================================================================================
**Developed by: Ido Azulay & Maor Attar**
====================================================================================================

### About the Program

This program is a **Super Pac-Man** game. Super Pac-Man is an action maze chase video game where the player controls the Pac-Man character through an enclosed maze. 

The objective of the game is to eat all of the dots placed in the maze while avoiding the colored ghosts before the clock reaches 0. 

In this game, we created 3 levels, each with a 90-second time limit. During gameplay, the player can collect keys to open doors. Picking up a key grants 7 points. The player can also collect gifts that add 5 points each. The available gifts are:

- **Freeze Time Gift**: Freezes the ghosts for 3 seconds.
- **Super Pac-Man Gift**: Turns Pac-Man into Super Pac-Man for 5 seconds.
- **Time Gift**: Adds 30 seconds to the clock.
- **Life Gift**: Adds 1 life.

While in Super Mode, Pac-Man can eat ghosts and run through doors.

====================================================================================================

### Data Structure

We use vectors of `unique_ptr` to manage static objects (e.g., keys, doors, walls) and moving objects (e.g., ghosts). This allows us to iterate through the vectors to manage movement and functionality.

====================================================================================================

### Algorithm

**Ghosts Movement:**

- **Red Ghost**: Determines direction based on the difference between Pac-Man’s and the red ghost’s positions (using absolute values). If the distances are equal, the ghost moves based on its relative position to Pac-Man.

- **Random Ghost (Blue Ghost)**: Moves randomly based on the time modulo 5, with an enum representing 4 possible directions.

- **Orange Ghost**: Moves randomly based on the time modulo 10, with an enum representing 9 possible directions.

**Scale Factor:**

We calculate the map pixels compared to the sprite size to allow the player to choose the board size. 

