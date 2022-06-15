//This is just a random script that I'm writing to learn C.
//Don't expect too much functionality out of it.

//Edit on May 31, 2022 2:50 PM. It works. For the most part
#include "../includes/helper-funcs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
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
        fprintf(checkw,"ShowCommands:1;");
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
                sett[j] = read[j];    
            }
            pos = i;
            if (strcmp("ShowCommands",sett))
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
        printf("\n\n\t5. Shutdown/Restart the PC");
        printf("\n\n\t6. Settings.");
        printf("\n\n\t7. Exit.");
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
            case 5: shutdown_restart();
                    break;
            case 6: settings();
                    break;
            case 7: system("clear");
                    return 0;
        }
    }
} 
