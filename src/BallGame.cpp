// #include <iostream>

// #define WIDTH               16
// #define HEIGHT              11
// #define TOTAL_SIZE          WIDTH * HEIGHT
// #define WALL_MARKER         '#'
// #define BALL_MARKER         '*'
// #define BACKGROUND_MARKER   ' ' // THIS IS A BLANK SPACE

// #ifdef __linux__
// struct consolcolors
// {
//     const char* RESET       = "\033[0m";
//     const char* BLACK       = "\033[30m";
//     const char* RED         = "\033[31m";
//     const char* GREEN       = "\033[32m";
//     const char* YELLOW      = "\033[33m";
//     const char* BLUE        = "\033[34m";
//     const char* MAGENTA     = "\033[35m";
//     const char* CYAN        = "\033[36m";
//     const char* WHITE       = "\033[37m";
//     const char* BOLDBLACK   = "\033[1m\033[30m";
//     const char* BOLDRED     = "\033[1m\033[31m";
//     const char* BOLDGREEN   = "\033[1m\033[32m";
//     const char* BOLDYELLOW  = "\033[1m\033[33m";
//     const char* BOLDBLUE    = "\033[1m\033[34m";
//     const char* BOLDMAGENTA = "\033[1m\033[35m";
//     const char* BOLDCYAN    = "\033[1m\033[36m";
//     const char* BOLDWHITE   = "\033[1m\033[37m";

//     consolcolors()
//     {

//     }
// };

// // #define RESET       "\033[0m"              /* Resets color to default */
// // #define BLACK       "\033[30m"             /* Black */
// // #define RED         "\033[31m"             /* Red */
// // #define GREEN       "\033[32m"             /* Green */
// // #define YELLOW      "\033[33m"             /* Yellow */
// // #define BLUE        "\033[34m"             /* Blue */
// // #define MAGENTA     "\033[35m"             /* Magenta */
// // #define CYAN        "\033[36m"             /* Cyan */
// // #define WHITE       "\033[37m"             /* White */
// // #define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
// // #define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
// // #define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
// // #define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
// // #define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
// // #define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
// // #define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
// // #define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
// #elif _WIN32
// // Check the color codes for Windows and compare them to Linux - 
// // PROBLEM DETECTED: Linux has a RESET function for colors that Windows does not use - Possible solution: Add #ifdef in main function 
// //PROBLEM DETECTED: Windows does not support BOLD text
// struct consolcolors
// {
// //COLORS LIST FOR WINDOWS
// //1: Blue
// //2: Green
// //3: Cyan
// //4: Red
// //5: Purple
// //6: Yellow (Dark)
// //7: Default white
// //8: Gray/Grey
// //9: Bright blue
// //10: Brigth green
// //11: Bright cyan
// //12: Bright red
// //13: Pink/Magenta
// //14: Yellow
// //15: Bright white

//     int RESET       = "\033[0m";
//     int BLACK       = "\033[30m";
//     int RED         = "\033[31m";
//     int GREEN       = "\033[32m";
//     int YELLOW      = "\033[33m";
//     int BLUE        = "\033[34m";
//     int MAGENTA     = "\033[35m";
//     int CYAN        = "\033[36m";
//     int WHITE       = "\033[37m";
//     int BOLDBLACK   = "\033[1m\033[30m";
//     int BOLDRED     = "\033[1m\033[31m";
//     int BOLDGREEN   = "\033[1m\033[32m";
//     int BOLDYELLOW  = "\033[1m\033[33m";
//     int BOLDBLUE    = "\033[1m\033[34m";
//     int BOLDMAGENTA = "\033[1m\033[35m";
//     int BOLDCYAN    = "\033[1m\033[36m";
//     int BOLDWHITE   = "\033[1m\033[37m";

//     consolcolors()
//     {
//         for(k = 1; k < 255; k++)
//         {
//             // pick the colorattribute k you want
//             SetConsoleTextAttribute(hConsole, k);
//         }
//     }
// }
// // Need to add code to check for colors for Windows
// #endif


// void Print(const char* message)
// {
//     std::cout << message << "\n" << std::endl;
// }

// class framebuffer
// {
//     char buffer [WIDTH * HEIGHT];

// public:
//     framebuffer()
//     {
//         for(int i = 0; i < TOTAL_SIZE; i++)
//         {
//             buffer[i] = BACKGROUND_MARKER;
//         } //ALL SPACES WITHIN HEIGHT * WIDTH THAT HASN'T BEEN ASSIGNED A VALUE SHALL HAVE VALUE '.'
        
//         for(int i = 0; i < WIDTH; i++)
//         {
//             buffer[i] = WALL_MARKER;
//         } // IN THE CASE OF HEIGHT = 12 and WIDTH = 12: MARK ALL SPACES BETWEEN ROW 0, COLUMN 0 and ROW 0 COLUMN 11 WIDTH '#'

//         for(int i = 1; i < (HEIGHT - 1); i++)
//         {
//             buffer[i * WIDTH] = WALL_MARKER;
//             buffer[i * WIDTH + (WIDTH - 1)] = WALL_MARKER;
//         } // MARK EVERY FIRST AND LAST SPACE IN EACH ROW (EXCEPT THE FIRST AND LAST (WHICH ARE DEFINE BY THE PREVIOUS AND THE NEXT COMING FOR-STATEMENT)) WITH '#'

//         for(int i = (TOTAL_SIZE - WIDTH); i < TOTAL_SIZE; i++)
//         {
//             buffer[i] = WALL_MARKER;
//         } // MARK ALL THE SPACES ON THE LAST ROW WITH '#'
//     }

//     void Draw()
//     {
//         for(int i = 0; i < HEIGHT; i++)
//         {
//             for(int a = 0 ; a < WIDTH; a++)
//             {
//                 std::cout << buffer[ (WIDTH * i) + a];
//             }
//             // std::cout << std::endl;
//             std::cout << "\n";
//         }

//         std::cout << std::endl;
//     }

//     // bool submit( int xPos, int yPos, char sign /*, int size, */ )
//     // {
//     //     // Function to your position too
//     //     // Width corresponds to x
//     //     if ( xPos > 0 && xPos < WIDTH )
//     //     {
//     //         if ( yPos > 0 && yPos < HEIGHT )
//     //         {
//     //             // Ideally calculate collisions!
//     //             buffer[ xPos * yPos ] = sign;
//     //         }
//     //     }



//     // }
// };

// class object
// {
// // public:
//     float positionX;
//     float positionY;
//     int size;
//     float speedX;
//     float speedY;

// public:
//     object()
//      : positionX(0.0f)
//     {
//         positionY = 0.0f;
//         size = 1;
//         speedX = 0.0f;
//         speedY = 0.0f;
//     }

//     object(const float& _X, const float& _Y, const int& _size, const float& _speed)
//     {
//         positionX = _X;
//         positionY = _Y;
//         size = _size;
//         speedX = _speed;
//         speedY = _speed;
//     }

//     void updatePosition(const float& deltatime)
//     {
//         positionX = positionX + (speedX * deltatime);
//         positionY = positionY + (speedY * deltatime);
//     }

//     void updateSpeed(const float& _speedX, const float& _speedY)
//     {
//         speedX = _speedX;
//         speedY = _speedY;
//     }

//     void update(const float& deltatime)
//     {
//         updatePosition(deltatime);

//         // We have to determine if the object has changed their speed, i.e. if it has collided with another object (in this simpler case: wall) or not
//         //updateSpeed();
//     }
    
//     void print()
//     {
//         std::cout << "positionX: " << positionX << "\n"
//                   << "positionY: " << positionX << "\n"
//                   << "size: "      << size      << "\n"
//                   << "speedX: "    << speedX    << "\n"
//                   << "speedY: "    << speedY    << "\n"                
//                   << std::endl;    
//     }
// };

// class ball : public object
// {
// // public:
//     float x;
//     float y;
//     float speed;
//     int direction;
//     int size;
// };

// template <typename T>
// void NORMALWARNING (T message, const consolcolors& color)
// {
//     std::cout << color.YELLOW << "[WARNING]: " << message << color.RESET << std::endl;
// }

// template <typename Y>
// void CRITICALWARNING (Y message, const consolcolors& color)
// {
//     std::cout << color.BOLDRED << "[CRITICAL WARNING]: " << message << color.RESET << std::endl;
// }

// // NORMALWARNING<int>(5);
// // NORMALWARNING(5);

// int main ()
// {
//     consolcolors color;
    
//     Print("Hello!");
//     std::cout << color.BOLDBLUE << "Hi!" << color.RESET << std::endl;
//     std::cout << color.BLUE << "Hi!" << color.RESET << std::endl;

//     framebuffer screen;
//     object testobject(0.0f, 0.0f, 1, 0.5f);
//     object testobject2(0.0f, 0.0f, 1, 0.5f);

//     for(int i = 0; i < 1; i++)
//     {
//         //Print("testobject: ");
//         //testobject.print();
//         //Print ("testobject2: ");
//         //testobject2.print();
//         //testobject.updatePosition(1.0f);
//         //testobject2.updatePosition(0.5f);

//         //testobject.update(deltaTid);
//         //testobject2.update(deltaTid);

//         screen.Draw();
//     }

   
//     // ball playerball;
    
//     for(int b = 1; b < 11; b+=2)
//     {
//         std::cout << color.RED << "b = :" << b << color.RESET << std::endl;
//     }

//     // int c = 1;
//     // while( c < 11)
//     // {
//     //     std::cout << "c = :" << c << std::endl;

//     //     c++;
//     // }

//     for(int d = 10; d > 0; d--)
//     {
//         std::cout << "d = :" << d << std::endl;
//     }

//     for(int e = 2; e < 6; e++)
//     {
        
//         std::cout << "e = :" << e << std::endl;

//         if(e >= 4)
//         {
//             CRITICALWARNING<const char*>("Something critical went wrong", color);
//         }
        
//         else if(e != 2)
//         {
//             NORMALWARNING<const char*>("Something went wrong", color);
//         }

//     }
// }    

#include <string>
#include <iostream>

#include "ConsoleColors.h"

using namespace std;


void wait() {
    cin.get();
}

void print_color_test() {
    print(" ", COLOR_BLACK, COLOR_MAGENTA   );
    print(" ", COLOR_BLACK, COLOR_BLUE      );
    print(" ", COLOR_BLACK, COLOR_LIGHT_BLUE);
    print(" ", COLOR_BLACK, COLOR_CYAN      );
    print(" ", COLOR_BLACK, COLOR_GREEN     );
    print(" ", COLOR_BLACK, COLOR_YELLOW    );
    print(" ", COLOR_BLACK, COLOR_ORANGE    );
    print(" ", COLOR_BLACK, COLOR_RED       );
    print();
    print(" ", COLOR_BLACK, COLOR_BLACK     );
    print(" ", COLOR_BLACK, COLOR_GRAY      );
    print(" ", COLOR_BLACK, COLOR_LIGHT_GRAY);
    print(" ", COLOR_BLACK, COLOR_WHITE     );
    print(" ", COLOR_BLACK, COLOR_PINK      );
    print(" ", COLOR_BLACK, COLOR_DARK_BLUE );
    print(" ", COLOR_BLACK, COLOR_DARK_GREEN);
    print(" ", COLOR_BLACK, COLOR_DARK_RED  );
    print();
    print("#", COLOR_MAGENTA   , COLOR_BLACK);
    print("#", COLOR_BLUE      , COLOR_BLACK);
    print("#", COLOR_LIGHT_BLUE, COLOR_BLACK);
    print("#", COLOR_CYAN      , COLOR_BLACK);
    print("#", COLOR_GREEN     , COLOR_BLACK);
    print("#", COLOR_YELLOW    , COLOR_BLACK);
    print("#", COLOR_ORANGE    , COLOR_BLACK);
    print("#", COLOR_RED       , COLOR_BLACK);
    print();
    print("#", COLOR_BLACK     , COLOR_BLACK);
    print("#", COLOR_GRAY      , COLOR_BLACK);
    print("#", COLOR_LIGHT_GRAY, COLOR_BLACK);
    print("#", COLOR_WHITE     , COLOR_BLACK);
    print("#", COLOR_PINK      , COLOR_BLACK);
    print("#", COLOR_DARK_BLUE , COLOR_BLACK);
    print("#", COLOR_DARK_GREEN, COLOR_BLACK);
    print("#", COLOR_DARK_RED  , COLOR_BLACK);
    print();
}

int main() {
    print("test");
    print_color_test();
    print("test\n");

    print("Hello", COLOR_GREEN, COLOR_BLACK);
    print("Bye", COLOR_RED, COLOR_BLACK);

    wait();
    return 0;
}