////////////////////////////////////////////////////////////////////////////////
// description : 
// improvements: separate objects/functions with a clear purpose
// comments    : "\33c\e[3J" is for clearing the console,
//                but don't know how it works
//               getch() for input without enter
//               reference: kbhit() to check if any key is pressed
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <conio.h>   // getch()
#include "Point.hpp"
#include "Map.hpp"

void Set_Interface(int interface[], int w, int h);
void Print_Interface(int interface[], int w, int h);
void Text_Generation(int interface[], int x, int y, int const& section, std::string const& str);

const int i_l=20, i_r=70, i_t=1, i_m=20, i_b=3;

int main(void) {
  int interface[i_t+i_m+i_b+4][i_l+i_r+3] = {0};
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
  int menu_line = 8, menu_left = 4;
  Text_Generation(interface, menu_left, menu_line, 'A', "MENU");
  Text_Generation(interface, menu_left, menu_line+2, 'A', "1.Tutorial");
  Text_Generation(interface, menu_left, menu_line+3, 'A', "2.Play");
  Text_Generation(interface, menu_left, menu_line+4, 'A', "3.Rank");
  Text_Generation(interface, 0, 0, 'D', "Very Long Description Very Long Description Very Long Description Very Long Description Very Long Description Very Long Description Very Long Description Very Long Description");
}
void Print_Interface(int interface[], int w, int h) {
  std::cout << "\33c\e[3J";
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      std::cout << char(interface[i*w+j]);
    }
    std::cout << std::endl;
  }
}
void Text_Generation(int interface[], int x, int y, int const& section, std::string const& str) {
  int max_length = i_r - 2;
  switch (section) {
    case 'A':
      x += 1;
      y += 1;
      max_length = i_l - 2;
      break;
    case 'B':
      x += i_l + 2;
      y += 1;
      break;
    case 'C':
      x += i_l + 2;
      y += i_t + 2;
      break;
    case 'D':
      x += i_l + 2;
      y += i_t + i_m + 3;
      break;
    default:
      std::cerr << "invalid section for Text_Generation()" << std::endl;
      break;
  }
  int line = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (i > 0 && i%max_length == 0)
      line++;
    interface[x+(y+line)*(i_l+i_r+3)+i-(max_length*line)+1] = str[i];
  }
}