//This is just a random script that I'm writing to learn C.
//Don't expect too much functionality out of it.
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

char getch(void)  //Created this since Linux doesn't have getch() functionality.
{                 //Code : https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux?noredirect=1&lq=1
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}
void main()
{
    int c,k,s;
    while(1)
    {
        system("clear");
        fflush(0);
        printf("\n\n\n\t\tEnter a Choice :");
        printf("\n\n\t1. Perform a full system upgrade.");
        printf("\n\n\t2. Exit this script.");
        printf("\n\nEnter a Choice :");
        scanf("%d",&c);
        switch (c)
        {
            case 1: system("clear");
                    printf("\n\n\t\tPerforming Full System Upgrade.\n\n\t\tUpdating Repos.\n\n");
                    fflush(0);
                    system("sudo apt update");
                    fflush(0);
                    printf("\n\n\t\tStarting the actual Upgrade Process.\n\n");
                    fflush(0);
                    system("sudo apt upgrade");
                    printf("\n\n\t\tPress any key to continue.");
                    fflush(0);
                    getch();
                    break;
            case 2: system("clear");
                    return;
        }
    }
} 