#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED

#include <windows.h>


namespace CC{
    class ConsoleColor{
        HANDLE console_color;


        public:
            // default constructor
            ConsoleColor(){
                console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(console_color, 14);
            }

            //color functions
            void Message(){
                SetConsoleTextAttribute(console_color, 9);
            }

            void ErrorM(){
                SetConsoleTextAttribute(console_color, 12);
            }

            void InputM(){
                SetConsoleTextAttribute(console_color, 11);
            }

            void DisplayData(){
                SetConsoleTextAttribute(console_color, 10);
            }

    };
}
#endif // COLORS_H_INCLUDED
