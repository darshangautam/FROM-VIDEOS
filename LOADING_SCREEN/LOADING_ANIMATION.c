#include <windows.h>
#include <stdio.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void loading_screen() // done 
{
    system("cls");
    // console_screen_buffer_info csbi;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width, height, x, y;
    int r, q;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    x = width / 2 - 10;
    y = height / 2;

    gotoxy(x, y);
    printf("------Loading------\n");
    gotoxy(x, y + 2);
    for (r = 1; r < 20; r++)
    {
        for (q = 0; q < 1; q++)
        {
            Sleep(30);
            printf("%c", 219);
        }
    }
}
int main()
{
    loading_screen();
    return (0);
}
