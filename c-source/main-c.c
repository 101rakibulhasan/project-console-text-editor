#include <stdio.h>
#include <stdlib.h>

int close()
{
    system("CLS");
    printf("Thank You For Using CONSOLE TEXT EDITOR V1!!!\n\n");
    exit(0);
    return 0;
}

int main_func()
{
    system("CLS");

    int num;
    printf("Welcome To CONSOLE TEXT EDITOR V1\n");
    printf("Made By Rakibul Hasan\n\n");

    printf("1// Create A New File \n");
    printf("2// Modify Existing File \n");
    printf("3// Text Utility Tools \n");
    printf("4// Exit\n\n");
    printf("P.S //Any Other Number Or Character Will Abort The Application\\\\\n\n");

    printf("Enter Numbers To Continue: ");
    scanf("%d", &num);

    return num;
}

void create();

void modify();

void utility();

void total_words(char text[]);

void count_certain_word(char text[]);

void find_word(char text[]);

void replace_word(char text[]);

int main()
{
    system("CLS");
    switch(main_func())
    {
        case 1:
            create();
            break;
        case 2:
            modify();
            break;
        case 3:
            utility();
            break;
        case 4:
            close();
        default:
            printf("// Application Aborting... // \n\n");
    }

    return 0;
}

void create()
{
    system("CLS");
    char name[50],text[100];

    printf( "DISCLAIMER : OVERWRITE AND NEWLINE ISSUE\n");
    printf( "Don't type the same name as the files in the current folder. It may overwrite those files. Be aware !!!\n\n");
    printf( "Pressing the \"ENTER\" key will save the file\n\n");
    printf( "Enter the new file name with extension: ");
    scanf("%s",name);

    FILE *fptr;
    fptr = fopen(name,"w+");
    printf("TYPE >> ");
    while(getchar() != '\n');
    scanf("%[^\n]s",text);
    fputs(text, fptr);
    fclose(fptr);

    printf("\n\n%s has been saved !!!\n\n", name);

    char y_n_choice;
    printf("Return to MAINMENU ?\n");
    printf("Y/y = yes\n");
    printf("N/n or Any character = No and Exit Application\n");
    printf("Y / N ? >> ");
    while(getchar() != '\n');
    scanf("%c", &y_n_choice);

    if(y_n_choice == 'Y' || y_n_choice == 'y')
    {
        main();
    }else
    {
        close();
    }
}

void modify()
{
    system("CLS");
    char name[50],newtext[100],prevtext[100];
    printf( "Pressing the \"ENTER\" key will save the file\n\n");
    printf( "Enter the new file name with extension: ");
    scanf("%s",name);

//    ifstream read;
//    read.open(name);
//
//    if(!read)
//    {
//        while(1)
//        {
//            system("CLS");
//            if(read)
//            {
//                break;
//            }else
//            {
//                cout << "File doesn't exists !!!\n\n";
//            }
//            cout << "Enter the new file name with extension: ";
//            cin >> name;
//            read.open(name);
//        }
//    }
//
//    cout << "TYPE >> ";
//    getline(read,prevtext);
//    cout << prevtext;
//    cin.ignore();
//    getline(cin, newtext);
//
//    ofstream write;
//    write.open(name, ios::app);
//    write << newtext;
//    write.close();

    FILE *fptr;
    fptr = fopen(name,"r+");

    if(fptr == NULL)
    {
        while(1)
        {
            system("CLS");
            if(fptr != NULL)
            {
                break;
            }else
            {
                printf("File doesn't exists !!!\n\n");
            }
            printf("Enter the new file name with extension: ");
            scanf("%s",name);
            fptr = fopen(name,"a+");
        }
    }

    printf("TYPE >> ");
    while(getchar() != '\n');
    scanf("%[^\n]s",newtext);
    fputs(" " + newtext, fptr);
    fclose(fptr);

    printf( "\n\n%s has been modified !!!\n\n", name);

    char y_n_choice;
    printf("Return to MAINMENU ?\n");
    printf("Y/y = yes\n");
    printf("N/n or Any character = No and Exit Application\n");
    printf("Y / N ? >> ");
    scanf("%c",&y_n_choice);

    if(y_n_choice == 'Y' || y_n_choice == 'y')
    {
        main();
    }else
    {
        close();
    }

}

void utility()
{
    int choice;
    char name[50], prevtext[100];
    system("CLS");
    printf("Welcome To Text Utility !!!\n");

    printf("Enter the new file name with extension: ");
    scanf("%s",&name);

//    ifstream read;
//    read.open(name);
//
//    if(!read)
//    {
//        while(1)
//        {
//            system("CLS");
//            if(read)
//            {
//                break;
//            }else
//            {
//                cout << "File doesn't exists !!!\n\n";
//            }
//            cout << "Enter file name with extension: ";
//            cin >> name;
//            read.open(name);
//        }
//    }

    system("CLS");

    //getline(read,prevtext);
    printf("READ << %s <<  FILE ENDED\n", prevtext);

    printf("Enter choice to use the features below -\n\n");

    printf("1. Total words\n");
    printf("2. Count certain word\n");
    printf("3. Find word\n");
    printf("4. Replace word\n");
    printf("H. Return to MAINMENU\n");

    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            total_words(prevtext);
            break;
        case 2:
            count_certain_word(prevtext);
            break;
        case 3:
            find_word(prevtext);
            break;
        case 4:
            replace_word(prevtext);
        default:
//            cin.clear();
//            fflush(stdin);
            main();
    }

}

void total_words(char text[])
{
    system("CLS");
    printf("TOTAL WORDS -\n");

    int t_words = 0;
    int i = 0;
    int temp=0;

    while(i < strlen(text) )
    {
        if((text[i] >= 32 && text[i] <= 47) || (text[i] >= 58 && text[i] <= 64) || text[i] == '\n' || text[i] == '\t' )
        {
            temp = 0;
        }else if(temp == 0)
        {
            temp = 1;
            t_words++;
        }

        i++;
    }

    printf("%d\n\n",t_words);

    printf("// CLICK ANY BUTTON TO RETURN \\ \n");

    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        default:
//            cin.clear();
//            fflush(stdin);
            utility();
    }
}

void count_certain_word(char text[])
{
    system("CLS");
}

void find_word(char text[])
{
    system("CLS");
}

void replace_word(char text[])
{
    system("CLS");
}
