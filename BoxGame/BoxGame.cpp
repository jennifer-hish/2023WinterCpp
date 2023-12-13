////////////////////////////////////////////////////////////////////////////////
// description : 
// improvements: separate objects/functions with a clear purpose
// comments    : "\33c\e[3J" is for clearing the console,
//                but don't know how it works
//               getch() for input without enter
//               reference: kbhit() to check if any key is pressed
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <conio.h>   // getch()
#include "Point.hpp"
#include "Map.hpp"

void Print_Interface(Map const& m);

int main(void) {
  Map map = Map(7,7);
  std::cout << "\33c\e[3J" << map << std::endl;
  char key;
  bool runGame = true;
  while (runGame == true) {
    key = getch();
    // std::cin >> go;
    if (key == 'w' || key == 'W') {
      map.up();
      std::cout << "\33c\e[3J" << map << std::endl;
    }
    else if (key == 'a' || key == 'A') {
      map.left();
      std::cout << "\33c\e[3J" << map << std::endl;
    }
    else if (key == 's' || key == 'S') {
      map.down();
      std::cout << "\33c\e[3J" << map << std::endl;
    }
    else if (key == 'd' || key == 'D') {
      map.right();
      std::cout << "\33c\e[3J" << map << std::endl;
    }
    else {
      runGame = false;
      std::cout << "\33c\e[3J" << "GAME OVER!" << "\n\n\n\n\n\n\n\n\n\n";
    }
  }
  return 0;
}

void Print_Interface(Map const& m) {
  std::cout << "\33c\e[3J" << m << std::endl;
}