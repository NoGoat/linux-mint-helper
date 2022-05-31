//This is just a random script that I'm writing to learn C.
//Don't expect too much functionality out of it.

//Edit on May 31, 2022 1:36 PM. The code is same as the v0.2 release for now.
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

int set[10];
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
void update()
{
    system("clear");
    printf("\n\n\t\tPerforming Full System Upgrade.\n\n\t\tUpdating Repos.\n\n");
    if (set[0] == 1)
    {
        printf("\033[1;31m\n\n\tCommand : \033[1;32msudo apt update \033[0m \n\n"); 
    }
    fflush(stdin);
    system("sudo apt update");
    fflush(stdin);
    printf("\n\n\t\tStarting the actual Upgrade Process.\n\n");
    fflush(stdin);
    if (set[0] == 1)
    {
        fflush(0);
        printf("\033[1;31m\n\n\tCommand : \033[1;32msudo apt upgrade \033[0m \n\n");
    }
    system("sudo apt upgrade");
    printf("\n\n\t\tPress any key to continue.");
    fflush(stdin);
    getch();
}
void settings()
{
    FILE *checkr,*checkw;
    char path[] = "preferences.txt";
    int c;
    int ch;
    char read[1000], sett[1000];
    int k,i,pos=0,j;
    while(1)
    {
        system("clear");
        printf("\n\n\t\t \033[1;31mSettings \033[0m");
        printf("\n\n\t1. Show Commands");
        if(set[0] == 0)
        {
            printf("\t[ ]");
        }
        else if(set[0] == 1)
        {
            printf("\t[*]");
        }
        printf("\n\n\t2. Exit");
        printf("\n\nEnter a Choice to Change :");
        scanf("%d",&c);
        fflush(stdin);
        switch (c)
        {
            case 1: system("clear");
                    printf("\n\n\t\t \033[1;31mSettings \033[0m");
                    printf("\n\n\t1. Show Commands");
                    if(set[0] == 0)
                    {
                        printf("\t[ ]");
                    }
                    else if(set[0] == 1)
                    {
                        printf("\t[*]");
                    }
                    printf("\n\n\t2. Exit");
                    printf("\n\nDo you want to change this setting [1\\0] :");
                    fflush(stdin);
                    scanf("%d",&ch);
                    
                    if(ch == 1)
                    {
                        if(set[0]==1)
                        {
                            set[0]=0;
                        }
                        else if(set[0]==0)
                        {
                            set[0]=1;
                        }
                    }
                    break;
            case 2: checkr = fopen(path,"r");
                    fflush(stdin);
                    fgets(read, 1000, checkr);
                    fflush(stdin);
                    for(i = 0 ; i < strlen(read) ; i++)
                    {
                        if(read[i] == ';')
                        {
                            for (j=pos ; j < i-1 ; j++)
                            {
                                sett[j] == read[j];    
                            }
                            pos = i;
                            if (strcmp("ShowCommands",sett));
                            {
                                if(set[0] == 0)
                                {
                                    read[i-1] = '0';
                                }
                                else if(set[0] == 1)
                                {
                                    read[i-1] = '1';
                                }
                            }
                        }
                    }
                    fclose(checkr);
                    checkw = fopen(path,"w");
                    fwrite(read,1,15,checkw);
                    fclose(checkw);
                    return;
        }
    }
    return;
}
void main()
{
    int c,k,i,pos=0,j;
    char path[] = "preferences.txt";
    char read[1000], sett[1000], character;
    FILE *checkw,*checkr;
    if(fopen(path,"r") == NULL)
    {
        //system("mkdir ~/.config/helper");
        fflush(stdin);
        checkw = fopen(path,"w");
        fflush(stdin);
        fprintf(checkw,"ShowCommands:0;");
        fflush(stdin);
        fclose(checkw);
        fflush(stdin);
    }
    checkr = fopen(path,"r");
    fflush(stdin);
    fgets(read, 1000, checkr);
    fflush(stdin);
    for(i = 0 ; i < strlen(read) ; i++)
    {
        if(read[i] == ';')
        {
            for (j=pos ; j < i-1 ; j++)
            {
                sett[j] == read[j];    
            }
            pos = i;
            if (strcmp("ShowCommands",sett));
            {
                if(read[i-1] == '0')
                {
                    set[0] = 0;
                }
                else if(read[i-1] == '1')
                {
                    set[0] = 1;
                }
            }
        }
    }
    while(1)
    {
        system("clear");
        fflush(stdin);
        printf("\n\n\n\t\t \033[1;31mMint Helper : \033[0m");
        printf("\n\n\t1. Perform a full system upgrade.");
        printf("\n\n\t2. Change the settings file.");
        printf("\n\n\t3. Exit this script.");
        printf("\n\nEnter a Choice :");
        scanf("%d",&c);
        switch (c)
        {
            case 1: update();
                    break;
            case 2: settings();
                    break;
            case 3: system("clear");
                    return;
        }
    }
} 
