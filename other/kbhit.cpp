#include <sys/ioctl.h>
#include <termios.h>

bool kbhit()
{
    /* отключения буферизации строк в потоках,
     * чтобы получать все данные сразу после их поступления,
     * например, нажатия клавиш
     * */

    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}
