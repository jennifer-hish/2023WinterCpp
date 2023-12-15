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
void Update_Menu(int interface[], int n, bool selected);
void Text_Generation(int interface[], int x, int y, int const& section, std::string const& str);

const int i_l=20, i_r=70, i_t=1, i_m=20, i_b=3;
const int menu_line = 10, menu_count = 4;

int main(void) {
  int interface[i_t+i_m+i_b+4][i_l+i_r+3] = {0};
  Set_Interface(*interface, sizeof(interface[0])/sizeof(int), sizeof(interface)/sizeof(interface[0]));
  // 메뉴 선택 조건
  int current_menu = 1;
  bool is_menu_selected = false;
  // 게임 진행중 확인
  bool is_game_running = false;
  // Map map = Map(7,7);
  // std::cout << "\33c\e[3J" << map << std::endl;
  char key;
  Update_Menu(*interface, current_menu, is_menu_selected);
  while (current_menu != menu_count || is_menu_selected == false) {
    Print_Interface(*interface, sizeof(interface[0])/sizeof(int), sizeof(interface)/sizeof(interface[0]));
    // key input
    if (key = getch()) {
      // std::cout << "key=" << key << std::endl;
      
      // menu control
      if (is_menu_selected == false) {
        if (key == 32 || key == 13) {
          is_menu_selected = true;
          Update_Menu(*interface, current_menu, is_menu_selected);
        } else if (key == 'w' || key == 'W') {
          if (current_menu > 1)
            current_menu--;
          Update_Menu(*interface, current_menu, is_menu_selected);
        } else if (key == 's' || key == 'S') {
          if (current_menu < menu_count)
            current_menu++;
          Update_Menu(*interface, current_menu, is_menu_selected);
        }
      } // else의 경우: 동작하지 않음, 그러나 임시로 동작시켰으므로 추후 코드 삭제
      else {
        if (key == 32 || key == 13)
          is_menu_selected = false;
      }
    }
  }
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
  int menu_left = 4;
  Text_Generation(interface, menu_left, menu_line-2, 'A', "MENU");
  Text_Generation(interface, menu_left, menu_line, 'A', "1.Tutorial");
  Text_Generation(interface, menu_left, menu_line+1, 'A', "2.Play");
  Text_Generation(interface, menu_left, menu_line+2, 'A', "3.Rank");
  Text_Generation(interface, menu_left, menu_line+3, 'A', "4.Quit");
  Text_Generation(interface, 0, 0, 'D', "JHISH 2023 Winter C++ Project");
}
void Print_Interface(int interface[], int w, int h) {
  std::cout << "\33c\e[3J";
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      std::cout << char(interface[i*w+j]);
    }
    std::cout << '\n';
  }
}
void Update_Menu(int interface[], int n, bool selected) {
  for (int i=0; i<menu_count; ++i) {
    if (i == n-1) {
      interface[(menu_line+i+1)*(i_l+i_r+3)+3] = selected ? 219 : '[';
      interface[(menu_line+i+1)*(i_l+i_r+3)+i_l-2] = selected ? 219 : ']';
    } else {
      interface[(menu_line+i+1)*(i_l+i_r+3)+3] = 32;
      interface[(menu_line+i+1)*(i_l+i_r+3)+i_l-2] = 32;
    }
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
      std::cerr << "invalid section for Text_Generation()\n";
      break;
  }
  int line = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (i > 0 && i%max_length == 0)
      line++;
    interface[x+(y+line)*(i_l+i_r+3)+i-(max_length*line)+1] = str[i];
  }
}