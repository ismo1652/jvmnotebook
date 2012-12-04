#include <windows.h>

/* Use: i686-pc-mingw32-g++ -mwindows -static winmain.c */

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    MessageBox(0, "Hello", "Test", MB_OK);
    return 0;
}
