//This is just a random script that I'm writing to learn C.
//Don't expect too much functionality out of it.

//Edit on May 31, 2022 2:50 PM. It works. For the most part
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
    printf("\n\n\t\t \033[1;34mPerforming Full System Upgrade.\033[0m\n\n\t\t \033[1;36mUpdating Repos.\033[0m\n\n");
    if (set[0] == 1)
    {
        printf("\033[1;31m\n\n\tCommand : \033[1;32msudo apt update \033[0m \n\n"); 
    }
    fflush(stdin);
    system("sudo apt update");
    fflush(stdin);
    printf("\n\n\t\t \033[1;36mStarting the actual Upgrade Process.\033[0m\n\n");
    fflush(stdin);
    if (set[0] == 1)
    {
        fflush(0);
        printf("\033[1;31m\n\n\tCommand : \033[1;32msudo apt upgrade \033[0m \n\n");
    }
    system("sudo apt upgrade");
    printf("\n\n\t\t\033[1;32m Press any key to continue. \033[0m");
    fflush(stdin);
    getch();
}
void install()
{
    char name[1000];
    char com[] = "sudo apt install ";
    system("clear");
    printf("\n\n\t\t \033[1;34mInstall Software. \033[0m \t");
    printf("\n\n \033[1;32mEnter an Application Name : \033[0m");
    scanf("%s",name);
    strcat(com,name);
    if (set[0] == 1)
    {
        printf("\033[1;31m\n\n\tCommand : \033[1;32m%s \033[0m \n\n",com); 
    }
    system(com);
    printf("\n\n\t\t\033[1;32m Press any key to continue. \033[0m");
    getch();
}
void uninstall()
{
    char name[1000];
    char com[] = "sudo apt remove ";
    system("clear");
    printf("\n\n\t\t \033[1;34mRemove Software. \033[0m \t");
    printf("\n\n\033[1;32mEnter an Application Name : \033[0m");
    scanf("%s",name);
    fflush(stdin);
    strcat(com,name);
    if (set[0] == 1)
    {
        printf("\033[1;31m\n\n\tCommand : \033[1;32m%s \033[0m \n\n",com); 
    }
    system(com);
    printf("\n\n\t\t\033[1;32m Press any key to continue. \033[0m");
    getch();
}
void autoremove()
{
    system("clear");
    printf("\n\n\t\t \033[1;34mRemoving Unused Packages.\033[0m");
    if (set[0] == 1)
    {
        printf("\033[1;31m\n\n\tCommand : \033[1;32msudo apt autoremove \033[0m \n\n"); 
    }
    fflush(stdin);
    system("sudo apt autoremove");
    fflush(stdin);
    printf("\n\n\t\t\033[1;32m Press any key to continue. \033[0m");
    fflush(stdin);
    getch();
}
void settings()
{
    FILE *checkr,*checkw;
    char path[] = "preferences.txt";
    int c;
    char read[1000], sett[1000], ch;
    int k,i,pos=0,j;
    while(1)
    {
        system("clear");
        printf("\n\n\t\t \033[1;34mSettings \033[0m");
        printf("\n\n\t1. Show Commands");
        if(set[0] == 0)
        {
            printf("\t\t[ ]");
        }
        else if(set[0] == 1)
        {
            printf("\t\t[*]");
        }
        printf("\n\n\t2. Go Back");
        printf("\n\n \033[1;32mEnter a Choice to Change : \033[0m");
        scanf("%d",&c);
        fflush(stdin);
        switch (c)
        {
            case 1: system("clear");
                    printf("\n\n\t\t \033[1;34mSettings \033[0m");
                    printf("\n\n\t1. Show Commands");
                    if(set[0] == 0)
                    {
                        printf("\t\t[ ]");
                    }
                    else if(set[0] == 1)
                    {
                        printf("\t\t[*]");
                    }
                    printf("\n\n\t2. Go Back");
                    printf("\n\n \033[1;32mDo you want to change this Setting [y\\n] : \033[0m");
                    fflush(stdin);
                    scanf("%s",&ch);
                    if(ch == 'y' || ch == 'Y')
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
        checkw = fopen("preferences.txt","w");
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
        printf("\n\n\n\t\t \033[1;34mMint Helper : \033[0m");
        printf("\n\n\t1. Perform a full system upgrade.");
        printf("\n\n\t2. Install Software.");
        printf("\n\n\t3. Remove Software.");
        printf("\n\n\t4. Remove Unused Packages.");
        printf("\n\n\t5. Settings.");
        printf("\n\n\t6. Exit.");
        printf("\n\n \033[1;32mEnter a Choice : \033[0m");
        scanf("%d",&c);
        switch (c)
        {
            case 1: update();
                    break;
            case 2: install();
                    break;
            case 3: uninstall();
                    break;
            case 4: autoremove();
                    break;
            case 5: settings();
                    break;
            case 6: system("clear");
                    return;
        }
    }
} 
