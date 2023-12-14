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

void Set_Interface(int interface[], int w, int h);
void Print_Interface(int interface[], int w, int h);

const int i_l=20, i_r=70, i_t=1, i_m=20, i_b=3;

int main(void) {
  int interface[i_t+i_m+i_b+4][i_l+i_r+3] = {0};
  std::cout << sizeof(interface) << ' ';
  Set_Interface(*interface, sizeof(interface[0])/sizeof(int), sizeof(interface)/sizeof(interface[0]));
  // Map map = Map(7,7);
  // std::cout << "\33c\e[3J" << map << std::endl;
  // char key;
  // bool runGame = true;
  // while (runGame == true) {
  //   key = getch();
  //   // std::cin >> go;
  //   if (key == 'w' || key == 'W') {
  //     map.up();
  //     std::cout << "\33c\e[3J" << map << std::endl;
  //   }
  //   else if (key == 'a' || key == 'A') {
  //     map.left();
  //     std::cout << "\33c\e[3J" << map << std::endl;
  //   }
  //   else if (key == 's' || key == 'S') {
  //     map.down();
  //     std::cout << "\33c\e[3J" << map << std::endl;
  //   }
  //   else if (key == 'd' || key == 'D') {
  //     map.right();
  //     std::cout << "\33c\e[3J" << map << std::endl;
  //   }
  //   else {
  //     runGame = false;
  //     std::cout << "\33c\e[3J" << "GAME OVER!" << std::endl;
  //   }
  // }
  Print_Interface(*interface, sizeof(interface[0])/sizeof(int), sizeof(interface)/sizeof(interface[0]));
  return 0;
}

void Set_Interface(int interface[], int w, int h) {
  std::cout << "set: " << w << ' ' << h << std::endl;
  for (int j=1; j<w-1; j++) {
    if (j == i_l+1) {
      interface[j] = 203;
      interface[w*(h-1)+j] = 202;
    } else {
      interface[j] = 205;
      interface[w*(h-1)+j] = 205;
    }
  }
  for (int i=1; i<h-1; i++) {
    for (int j=1; j<w-1; j++) {
      if (j == i_l+1)
        interface[i*w+j] = 186;
      else
        interface[i*w+j] = 32;
    }
    interface[i*w] = 186;
    interface[i*w+w-1] = 186;
  }
  interface[0] = 201;
  interface[w-1] = 187;
  interface[w*h-1] = 188;
  interface[w*(h-1)] = 200;
  for (int j=i_l+2; j<w-1; j++) {
    interface[(i_t+1)*w+j] = 205;
    interface[(i_t+i_m+2)*w+j] = 205;
  }
  interface[(i_t+1)*w+i_l+1] = 204;
  interface[(i_t+i_m+2)*w+i_l+1] = 204;
  interface[(i_t+2)*w-1] = 185;
  interface[(i_t+i_m+3)*w-1] = 185;

  // menu text
  int menu_line = 8, menu_left = 5;
  interface[w*menu_line+menu_left] = 'M';
  interface[w*menu_line+menu_left+1] = 'E';
  interface[w*menu_line+menu_left+2] = 'N';
  interface[w*menu_line+menu_left+3] = 'U';

  interface[w*(menu_line+2)+menu_left] = 219;
  interface[w*(menu_line+2)+menu_left+1] = '.';
  interface[w*(menu_line+2)+menu_left+2] = 'T';
  interface[w*(menu_line+2)+menu_left+3] = 'u';
  interface[w*(menu_line+2)+menu_left+4] = 't';
  interface[w*(menu_line+2)+menu_left+5] = 'o';
  interface[w*(menu_line+2)+menu_left+6] = 'r';
  interface[w*(menu_line+2)+menu_left+7] = 'i';
  interface[w*(menu_line+2)+menu_left+8] = 'a';
  interface[w*(menu_line+2)+menu_left+9] = 'l';

  interface[w*(menu_line+3)+menu_left] = '2';
  interface[w*(menu_line+3)+menu_left+1] = '.';
  interface[w*(menu_line+3)+menu_left+2] = 'P';
  interface[w*(menu_line+3)+menu_left+3] = 'l';
  interface[w*(menu_line+3)+menu_left+4] = 'a';
  interface[w*(menu_line+3)+menu_left+5] = 'y';

  interface[w*(menu_line+4)+menu_left] = '3';
  interface[w*(menu_line+4)+menu_left+1] = '.';
  interface[w*(menu_line+4)+menu_left+2] = 'R';
  interface[w*(menu_line+4)+menu_left+3] = 'a';
  interface[w*(menu_line+4)+menu_left+4] = 'n';
  interface[w*(menu_line+4)+menu_left+5] = 'k';
}
void Print_Interface(int interface[], int w, int h) {
  std::cout << "print: " << w << ' ' << h << std::endl;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      std::cout << char(interface[i*w+j]);
    }
    std::cout << std::endl;
  }
}