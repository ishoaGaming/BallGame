#include <iostream>

#define WIDTH               16
#define HEIGHT              11
#define TOTAL_SIZE          WIDTH * HEIGHT
#define WALL_MARKER         '#'
#define BALL_MARKER         '*'
#define BACKGROUND_MARKER   ' ' // THIS IS A BLANK SPACE

#define RESET       "\033[0m"              /* Resets color to default */
#define BLACK       "\033[30m"             /* Black */
#define RED         "\033[31m"             /* Red */
#define GREEN       "\033[32m"             /* Green */
#define YELLOW      "\033[33m"             /* Yellow */
#define BLUE        "\033[34m"             /* Blue */
#define MAGENTA     "\033[35m"             /* Magenta */
#define CYAN        "\033[36m"             /* Cyan */
#define WHITE       "\033[37m"             /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


void Print(const char* message)
{
    std::cout << message << "\n" << std::endl;
}

class framebuffer
{
    char buffer [WIDTH * HEIGHT];

public:
    framebuffer()
    {
        for(int i = 0; i < TOTAL_SIZE; i++)
        {
            buffer[i] = BACKGROUND_MARKER;
        } //ALL SPACES WITHIN HEIGHT * WIDTH THAT HASN'T BEEN ASSIGNED A VALUE SHALL HAVE VALUE '.'
        
        for(int i = 0; i < WIDTH; i++)
        {
            buffer[i] = WALL_MARKER;
        } // IN THE CASE OF HEIGHT = 12 and WIDTH = 12: MARK ALL SPACES BETWEEN ROW 0, COLUMN 0 and ROW 0 COLUMN 11 WIDTH '#'

        for(int i = 1; i < (HEIGHT - 1); i++)
        {
            buffer[i * WIDTH] = WALL_MARKER;
            buffer[i * WIDTH + (WIDTH - 1)] = WALL_MARKER;
        } // MARK EVERY FIRST AND LAST SPACE IN EACH ROW (EXCEPT THE FIRST AND LAST (WHICH ARE DEFINE BY THE PREVIOUS AND THE NEXT COMING FOR-STATEMENT)) WITH '#'

        for(int i = (TOTAL_SIZE - WIDTH); i < TOTAL_SIZE; i++)
        {
            buffer[i] = WALL_MARKER;
        } // MARK ALL THE SPACES ON THE LAST ROW WITH '#'
    }

    void Draw()
    {
        for(int i = 0; i < HEIGHT; i++)
        {
            for(int a = 0 ; a < WIDTH; a++)
            {
                std::cout << buffer[ (WIDTH * i) + a];
            }
            // std::cout << std::endl;
            std::cout << "\n";
        }

        std::cout << std::endl;
    }

    // bool submit( int xPos, int yPos, char sign /*, int size, */ )
    // {
    //     // Function to your position too
    //     // Width corresponds to x
    //     if ( xPos > 0 && xPos < WIDTH )
    //     {
    //         if ( yPos > 0 && yPos < HEIGHT )
    //         {
    //             // Ideally calculate collisions!
    //             buffer[ xPos * yPos ] = sign;
    //         }
    //     }



    // }
};

class object
{
// public:
    float positionX;
    float positionY;
    int size;
    float speedX;
    float speedY;

public:
    object()
     : positionX(0.0f)
    {
        positionY = 0.0f;
        size = 1;
        speedX = 0.0f;
        speedY = 0.0f;
    }

    object(const float& _X, const float& _Y, const int& _size, const float& _speed)
    {
        positionX = _X;
        positionY = _Y;
        size = _size;
        speedX = _speed;
        speedY = _speed;
    }

    void updatePosition(const float& deltatime)
    {
        positionX = positionX + (speedX * deltatime);
        positionY = positionY + (speedY * deltatime);
    }

    void updateSpeed(const float& _speedX, const float& _speedY)
    {
        speedX = _speedX;
        speedY = _speedY;
    }

    void update(const float& deltatime)
    {
        updatePosition(deltatime);

        // We have to determine if the object has changed their speed, i.e. if it has collided with another object (in this simpler case: wall) or not
        //updateSpeed();
    }
    
    void print()
    {
        std::cout << "positionX: " << positionX << "\n"
                  << "positionY: " << positionX << "\n"
                  << "size: "      << size      << "\n"
                  << "speedX: "    << speedX    << "\n"
                  << "speedY: "    << speedY    << "\n"                
                  << std::endl;    
    }
};

class ball : public object
{
// public:
    float x;
    float y;
    float speed;
    int direction;
    int size;
};

template <typename T>
void NORMALWARNING (T message)
{
    std::cout << YELLOW << "[WARNING]: " << message << RESET << std::endl;
}

template <typename Y>
void CRITICALWARNING (Y message)
{
    std::cout << BOLDRED << "[CRITICAL WARNING]: " << message << RESET << std::endl;
}

// NORMALWARNING<int>(5);
// NORMALWARNING(5);

int main ()
{
    Print("Hello!");
    std::cout << BOLDBLUE << "Hi!" << RESET << std::endl;
    std::cout << BLUE << "Hi!" << RESET << std::endl;

    framebuffer screen;
    object testobject(0.0f, 0.0f, 1, 0.5f);
    object testobject2(0.0f, 0.0f, 1, 0.5f);

    for(int i = 0; i < 1; i++)
    {
        //Print("testobject: ");
        //testobject.print();
        //Print ("testobject2: ");
        //testobject2.print();
        //testobject.updatePosition(1.0f);
        //testobject2.updatePosition(0.5f);

        //testobject.update(deltaTid);
        //testobject2.update(deltaTid);

        screen.Draw();
    }

   
    // ball playerball;
    
    for(int b = 1; b < 11; b+=2)
    {
        std::cout << RED << "b = :" << b << RESET << std::endl;
    }

    // int c = 1;
    // while( c < 11)
    // {
    //     std::cout << "c = :" << c << std::endl;

    //     c++;
    // }

    for(int d = 10; d > 0; d--)
    {
        std::cout << "d = :" << d << std::endl;
    }

    for(int e = 2; e < 6; e++)
    {
        
        std::cout << "e = :" << e << std::endl;

        if(e >= 4)
        {
            CRITICALWARNING<const char*>("Something critical went wrong");
        }
        
        else if(e != 2)
        {
            NORMALWARNING<const char*>("Something went wrong");
        }

    }
}    