
#include <ncurses.h>
#include <stdio.h>

int main(){
  
  initscr(); // Init the screen

  // Add points (Coordinates are in (Y,X))
  mvaddch(10,10,46); // Add a white point on (10,10)
  mvaddch(10,20,46); // "                  " (20,10)
  mvaddch(10,30,46); // "                  " (30,10)
  mvaddch(10,40,46); // "                  " (40,10)
  // If we want to add black points: mvaddch(Y,X,10);
  
  refresh(); // Refresh the screen so it shows the added points

  getch(); // Wait for the user to click the keyboard (otherwise the program shuts down)
  
  endwin(); // End the screen

  return 0;
}
