#ifdef __linux__
    #include <termios.h>
    #include <unistd.h>
    
    char getSingleChar()
    {
        char c = 0;
        struct termios old = {0};
        struct termios newt = {0};
    
        // Get current terminal settings
        tcgetattr(STDIN_FILENO, &old);
        newt = old;
    
        // Disable canonical mode and echo
        newt.c_lflag &= ~(ICANON | ECHO);
    
        // Apply settings immediately
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
        // Read a single character
        read(STDIN_FILENO, &c, 1);
    
        // Restore original terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
    
        return c;
    }
#endif

#ifdef _WIN32
    #include <conio.h>

    char getSingleChar()
    {
        int c = _getch();
    
        return static_cast<char>(c);
    }
#endif
