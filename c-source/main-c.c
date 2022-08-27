#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>


struct log
{
    char date[30];
    char name[30];
    char tool[10];
};

//// EXIT FUNCTION ////
int close()
{
    system("CLS");
    printf("Thank You For Using CONSOLE TEXT EDITOR V1!!!\n\n");
    exit(0);  // Exits The Application
    return 0;
}

//// HOMEPAGE FUNCTION ////
int main_func()
{
    system("CLS");  // Clears Console Screen

    int num;
    printf("// Welcome To CONSOLE TEXT EDITOR V1 (Supports Only 100 Characters)\n");
    printf("// Made By Rakibul Hasan\n\n");


printf("    ;dk0KKKKKKKKK0Oxc.   c0KKKKKKKKKKKKKKKKKKKo. ,x0KKKKKKKKKKKO;\n");
printf("  .xNMMNKOOOO00O0XWMW0; 'xOOOOOO0NMMMWXOOOOO0d.  lWMMN0OOOOOOOOc\n");
printf("  lWMMO;.       ..dNMMO.        .kMMMWl          lWMMx.\n");
printf(" .xMMWc           '0WMK,        .xMMMWc          oWMMd\n");
printf(" .xMMNc           .OWNk'        .xMMMWc          lWMMd\n");
printf(" .xMMNc           .:c'.         .xMMMWc          oWMMd\n");
printf(" .xMMNc                         .xMMMWc          oWMMk,''''''..'.\n");
printf(" .xMMNc                         .xMMMWc          lWMMWNNNNNNNNN0;\n");      // ASCII ART DISPLAY ;)
printf(" .xMMNc                         .xMMMWc          oWMMXkkkkkkkkx;\n");
printf(" .xMMNc                         .xMMMWc          lWMMd\n");
printf(" .xMMNc            'cxk,        .xMMMWc          oWMMd\n");
printf(" .xMMNc           .OMMX;        .xMMMNc          oWMMd\n");
printf(" .dMMWl           ,KMMK,        .xMMMNc          lWMMd\n");
printf("  :NMMXo;,,,,,,,,cOWMWx.        .xMWMNc          lWMMk;,,,,,,,,,,,,'.\n");
printf("   :0WMMMWWWWWWWWMMMXd.         .xMMMN:          lWMMMWWWWWWWWWWWWNd.\n");
printf("    .;coddddddddddl:.           .oOxo:.          ,ddddddddddddddddl.\n\n");


    printf("// Choose What You Want To Do-\n");


    printf("    1. Create A New File \n");
    printf("    2. Append Existing File \n");   //Displaying Homepage Options
    printf("    3. Text Utility Tools \n");
    printf("    4. Log\n");
    printf("    5. Exit\n\n");
    printf("// Any Other Number Or Character Will Abort The Application \\\\\n\n");

    printf("Enter Number To Continue: ");
    scanf("%d", &num);                      //For entering choice

    return num;                         //Returns the choice number
}

// USEFUL FUNCTIONS BEGINS //

void create();

void modify();

void utility();

void log();

void total_words(char text[]);

void count_certain_word(char text[]);

void find_word(char text[]);

void replace_word(char text[], char name[]);

// USEFUL FUNCTIONS ENDS //


//// MAIN FUNCTION ////
int main()
{
    system("CLS");
    switch(main_func())
    {
        case 1:
            create();   // calls CREATE FUNCTION
            break;
        case 2:
            modify();   // calls MODIFY FUNCTION
            break;
        case 3:
            utility();  // calls UTILITY FUNCTION
            break;
        case 4:
            log();    // calls LOG FUNCTION
        case 5:
            close();    // calls EXIT FUNCTION
        default:
            printf("// Application Aborting... // \n\n");
    }

    return 0;
}

//// CREATE FUNCTION ////
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
    fptr = fopen(name,"w+");  //Get name string to create file
    printf("TYPE >> ");
    while(getchar() != '\n'); //Ignores previous input "\n"
    scanf("%[^\n]s",text); //Ignores until "\n" is received and puts input in "text" variable
    fputs(text, fptr);  // puts input "text" in file
    fclose(fptr);   // saves the file in local directory

    //put the data in the LOG
    FILE *rec;
    rec = fopen("record.log", "a+");

    time_t t;
    time(&t);

    struct log temp;
    strcpy(temp.name, name);
    strcpy(temp.date, ctime(&t));
    strcpy(temp.tool, "CREATE");

    fwrite(&temp, sizeof(temp), 1, rec);
    fclose(rec);


    printf("\n\n%s has been saved !!!\n\n", name);

    // Gets user if the user wants to exit or go to mainmenu
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

//// MODIFY FUNCTION ////
void modify()
{
    system("CLS");
    char name[50],newtext[100],prevtext[100];
    printf( "Pressing the \"ENTER\" key will save the file\n\n");
    printf( "Enter the new file name with extension: ");
    scanf("%s",name);

    FILE *fptr;
    fptr = fopen(name,"r+");  //Get name string to read file

     // if name is INVALID then loop user input till the file is found
    while(fptr == NULL)
    {
        system("CLS");
        printf("File doesn't exists !!!\n\n");
        printf("Enter the new file name with extension: ");
        scanf("%s",&name);
        fptr = fopen(name,"r+");
    }

    printf("TYPE >> ");
    fgets(prevtext, 100, fptr);  //reads the file into "prevtext" variable
    printf("%s", prevtext);
    fclose(fptr);     // saves the file

    fptr = fopen(name,"a+"); // opens the file to append mode
    while(getchar() != '\n');
    scanf("%[^\n]s",newtext);
    fputs(newtext, fptr); // adds string to the end of file.
    fclose(fptr);  // saves the file

    //put the data in the LOG
    FILE *rec;
    rec = fopen("record.log", "a+");

    time_t t;
    time(&t);

    struct log temp;
    strcpy(temp.name, name);
    strcpy(temp.date, ctime(&t));
    strcpy(temp.tool, "MODIFY");

    fwrite(&temp, sizeof(temp), 1, rec);
    fclose(rec);

    printf( "\n\n%s has been modified !!!\n\n", name);

    // Gets user if the user wants to exit or go to mainmenu
    char y_n_choice;
    printf("Return to MAINMENU ?\n");
    printf("Y/y = yes\n");
    printf("N/n or Any character = No and Exit Application\n");
    printf("Y / N ? >> ");
    fflush(stdin);
    scanf("%c",&y_n_choice);

    if(y_n_choice == 'Y' || y_n_choice == 'y')
    {
        main();
    }else
    {
        close();
    }

}

//// UTILITY FUNCTION ////
void utility()
{
    int choice;
    char name[50], prevtext[100];
    system("CLS");
    system("Color 07"); // changes background color to "BLACK" and foreground color "WHITE"
    printf("// Welcome To Text Utility !!!\n");

    printf("Enter the new file name with extension: ");
    scanf("%s",&name); //takes the file name with extension

    FILE *fptr;
    fptr = fopen(name,"r+"); //open the file in read mode

    // if name is INVALID then loop user input till the file is found
    while(fptr == NULL)
    {
        system("CLS");
        printf("File doesn't exists !!!\n\n");
        printf("Enter the new file name with extension: ");
        scanf("%s",&name);
        fptr = fopen(name,"r+");
    }

    printf("TYPE >> ");
    fgets(prevtext, 100, fptr); //read the file in "prevtext" variable
    fclose(fptr);

    system("CLS");

    printf("File Name : %s\n\n", name);
    printf("READ << %s <<  FILE ENDED\n\n", prevtext);

    printf("Enter choice to use the features below -\n\n");

    printf("    1. Total words\n");
    printf("    2. Count certain word\n");
    printf("    3. Find word\n");              //Displaying Utility Options
    printf("    4. Replace word\n");
    printf("    H. Return to MAINMENU\n\n");

    printf("TYPE >> ");

    scanf(" %d",&choice);

    //choices that executes utility functions
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
            replace_word(prevtext, name);
        default:
            fflush(stdin); // flush the input stream
            main();
    }

}

//// LOG ////
void log()
{
    system("CLS");
    // For reading logfile
    FILE *rec;
    rec = fopen("record.log", "r");

    struct log temp;
    int flag = 0;
    while(fread(&temp, sizeof(temp), 1, rec)==1)
    {
        printf("\n%s    ", temp.date);
        printf("%s  ", temp.name);
        printf("%s  \n\n", temp.tool);
        flag = 1;
    }

    if(flag == 0)
    {
        printf("\n  No Record Found!\n\n");
    }

    fclose(rec);

    printf("// CLICK ANY BUTTON THEN PRESS \"ENTER\" TO RETURN \\\\ \n");

    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        default:
            fflush(stdin);    // flush the input stream
            main();
    }
}

//// TOTAL WORD COUNTING FUNCTION ////
void total_words(char text[])
{
    system("CLS");
    printf("TOTAL WORDS -\n");

    int t_words = 0;
    int i = 0;
    int temp=0;

    while(i < strlen(text) )
    {
        if((text[i] >= 32 && text[i] <= 47) || (text[i] >= 58 && text[i] <= 64) || text[i] == '\n' || text[i] == '\t' ) // a word will be only counted when it has before after any symbol or whitespace or tab
        {
            temp = 0;
        }else if(temp == 0)
        {
            temp = 1;
            t_words++;
        }

        i++;
    }

    printf("%d\n\n",t_words); // print total counted number

    printf("// CLICK ANY BUTTON THEN PRESS \"ENTER\" TO RETURN \\\\ \n");

    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        default:
            fflush(stdin);    // flush the input stream
            utility();
    }
}

//// COUNTING SPECIFIC WORD FUNCTION ////
void count_certain_word(char text[])
{
    system("CLS");
    char cert_word[100];
    printf("Enter The Word : ");
    scanf("%s", &cert_word); // the word we will count

    int i, j, found, count;
    int stringLen, searchLen;

    stringLen = strlen(text);
    searchLen = strlen(cert_word);

    count = 0;

    for(i=0; i <= stringLen-searchLen; i++)
    {
        found = 1;
        for(j=0; j<searchLen; j++)
        {
            if(text[i + j] != cert_word[j])
            {
                found = 0;  // if text[i + j] character doesn't match with cert_word[j] then that word is not matched
                break;
            }
        }

        if(found == 1)
        {
            count++;
        }
    }


    printf("Counted Word : %d\n",count);

    printf("// CLICK ANY BUTTON THEN PRESS \"ENTER\" TO RETURN \\\\ \n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        default:
            fflush(stdin);
            utility();
    }
}

//// UNDER CONSTRUCTION FUNCTION ////
void under_construction()
{
    system("Color 40");
    printf("// THIS PART IS STILL UNDER CONSTRUCTION \\\\\n\n");
    printf("Press any key to return HOME - ");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        default:
            fflush(stdin);
            utility();
    }

}

//// FIND SPECIFIC WORD FUNCTION ////
void find_word(char text[])
{
    system("CLS");
    char cert_word[100];
    printf("\\\\ The founded word will be all in CAPITALIZED\n\n");
    printf("Enter The Word : ");
    scanf("%s", &cert_word);


    int i, j, found, count;
    int stringLen, searchLen;

    stringLen = strlen(text);
    searchLen = strlen(cert_word);

    for(i=0; i <= stringLen-searchLen; i++)
    {
        found = 1;
        for(j=0; j<searchLen; j++)
        {
            if(text[i + j] != cert_word[j])
            {
                found = 0;
                break;
            }
        }

        if(found == 1)
        {
            for(j=0; j<searchLen; j++)
            {
                if(text[i + j] == cert_word[j])
                {
                    if(text[i + j] >= 'a' && text[i + j] <= 'z'){
                        text[i + j] = text[i + j] - 32; // if cert_word is found in text, make it capitalized
                    }
                }
            }
        }
    }

    printf("\n%s\n\n",text);

    printf("// CLICK ANY BUTTON THEN PRESS \"ENTER\" TO RETURN \\\\ \n");

    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        default:
            fflush(stdin);
            utility();
    }

}

//// REPLACE SPECIFIC WORD FUNCTION ////
void replace_word(char text[], char name[])
{
    system("CLS");
    printf("ORIGINAL : %s \n\n", text);
    char rep_word[50], spec_word[50];
    printf("Enter The Word You Want To Replace: ");
    scanf("%s",&spec_word);
    while(getchar() != '\n');
    printf("Enter The Word You Want %s To Be Replaced With : ", spec_word);
    scanf("%s",&rep_word);
    while(getchar() != '\n');

    int i, j, found, _count;
    char *after;
    int stringLen, searchLen, replaceLen;

    stringLen = strlen(text);
    searchLen = strlen(spec_word);
    replaceLen = strlen(rep_word);

    for(i=0; i <= stringLen-searchLen; i++)
    {
        found = 1;
        for(j=0; j<searchLen; j++)
        {
            if(text[i + j] != spec_word[j])
            {
                found = 0;
                break;
            }
        }

        if(found == 1)
        {
            if(spec_word == rep_word)
            {
                after = malloc((stringLen + 1) * sizeof(char));
            }
            else
            {
                int occurences = 0;

                int i = 0;
                while(i < stringLen)
                {
                    if(strstr(&text[i], spec_word) == &text[i])
                    {
                        occurences++;
                        i += searchLen;
                    }else
                    {
                        i++;
                    }
                }

                int sub_diff = replaceLen - searchLen;
                int after_length = stringLen;

                after_length += occurences * sub_diff;

                after = malloc((after_length + 1) * sizeof(char));
            }

            i = 0;
            int j = 0;

            while(i < strlen(text))
            {
                if(strstr(&text[i], spec_word) == &text[i])
                {
                    strcpy(&after[j], rep_word);
                    i += searchLen;
                    j += replaceLen;

                }else
                {
                    after[j] = text[i];
                    i++;
                    j++;
                }
            }

            after[j] = '\0';
        }
    }

    printf("\n\nREPLACED : %s\n\n",after);

    printf("// Save The Replaced Text ? ");
    printf("- ( WARNING: Will Overwrite The Original %s File )\n\n", name);
    printf("    Y/y     : Yes, Save and Overwrite\n");
    printf("    ANY KEY : No\n\n");

    char choice;
    printf("(Y/N) >> ");
    scanf("%c", &choice);

    if(choice == 'Y' || choice == 'y')
    {
        FILE *fptr;
        fptr = fopen(name,"w+");  //Get name string to create file
        fputs(after, fptr);  // puts input "text" in file
        fclose(fptr);

        printf("\n// %s has been saved !!!\n", name);

        //put the data in the LOG
        FILE *rec;
        rec = fopen("record.log", "a+");

        time_t t;
        time(&t);

        struct log temp;
        strcpy(temp.name, name);
        strcpy(temp.date, ctime(&t));
        strcpy(temp.tool, "REPLACE");

        fwrite(&temp, sizeof(temp), 1, rec);
        fclose(rec);
    }


    printf("\n// CLICK ANY BUTTON THEN PRESS \"ENTER\" TO RETURN \\\\ \n");

    while(getchar() != '\n');
    int any;
    printf(">> ");
    scanf("%d",&any);

    switch(any)
    {
        default:
            fflush(stdin);
            utility();
    }

}
