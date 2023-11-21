#include <string>
#include <iostream>

#define COLOR_BLACK      0
#define COLOR_DARK_BLUE  1
#define COLOR_DARK_GREEN 2
#define COLOR_LIGHT_BLUE 3
#define COLOR_DARK_RED   4
#define COLOR_MAGENTA    5
#define COLOR_ORANGE     6
#define COLOR_LIGHT_GRAY 7
#define COLOR_GRAY       8
#define COLOR_BLUE       9
#define COLOR_GREEN     10
#define COLOR_CYAN      11
#define COLOR_RED       12
#define COLOR_PINK      13
#define COLOR_YELLOW    14
#define COLOR_WHITE     15

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#endif // _WIN32

void print(const std::string s="") {
    std::cout << s << std::endl;
}
void print(const std::string s, const int textcolor, const int backgroundcolor) {
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    WORD default_colors = 0;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) default_colors = csbi.wAttributes;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backgroundcolor<<4|textcolor);
#elif defined(__linux__)
    std::string t, b;
    switch(textcolor) {
        case COLOR_BLACK      : t="30"; break; // color_black      0
        case COLOR_DARK_BLUE  : t="34"; break; // color_dark_blue  1
        case COLOR_DARK_GREEN : t="32"; break; // color_dark_green 2
        case COLOR_LIGHT_BLUE : t="36"; break; // color_light_blue 3
        case COLOR_DARK_RED   : t="31"; break; // color_dark_red   4
        case COLOR_MAGENTA    : t="35"; break; // color_magenta    5
        case COLOR_ORANGE     : t="33"; break; // color_orange     6
        case COLOR_LIGHT_GRAY : t="37"; break; // color_light_gray 7
        case COLOR_GRAY       : t="90"; break; // color_gray       8
        case COLOR_BLUE       : t="94"; break; // color_blue       9
        case COLOR_GREEN      : t="92"; break; // color_green     10
        case COLOR_CYAN       : t="96"; break; // color_cyan      11
        case COLOR_RED        : t="91"; break; // color_red       12
        case COLOR_PINK       : t="95"; break; // color_pink      13
        case COLOR_YELLOW     : t="93"; break; // color_yellow    14
        case COLOR_WHITE      : t="97"; break; // color_white     15
        default               : t="97";
    }
    switch(backgroundcolor) {
        case COLOR_BLACK      : b= "40"; break; // color_black      0
        case COLOR_DARK_BLUE  : b= "44"; break; // color_dark_blue  1
        case COLOR_DARK_GREEN : b= "42"; break; // color_dark_green 2
        case COLOR_LIGHT_BLUE : b= "46"; break; // color_light_blue 3
        case COLOR_DARK_RED   : b= "41"; break; // color_dark_red   4
        case COLOR_MAGENTA    : b= "45"; break; // color_magenta    5
        case COLOR_ORANGE     : b= "43"; break; // color_orange     6
        case COLOR_LIGHT_GRAY : b= "47"; break; // color_light_gray 7
        case COLOR_GRAY       : b="100"; break; // color_gray       8
        case COLOR_BLUE       : b="104"; break; // color_blue       9
        case COLOR_GREEN      : b="102"; break; // color_green     10
        case COLOR_CYAN       : b="106"; break; // color_cyan      11
        case COLOR_RED        : b="101"; break; // color_red       12
        case COLOR_PINK       : b="105"; break; // color_pink      13
        case COLOR_YELLOW     : b="103"; break; // color_yellow    14
        case COLOR_WHITE      : b="107"; break; // color_white     15
        default               : b= "40";
    }
    std::cout << "\033["+t+";"+b+"m";
#endif // Windows/Linux
    std::cout << s;
#if defined(_WIN32)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), default_colors);
#elif defined(__linux__)
    std::cout << "\033[0m"; // reset color
#endif // Windows/Linux
}