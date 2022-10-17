#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include<string.h>
#include<fstream>
#include<time.h>

using namespace std;

class log_class
{
    public:
        string date;
        string name;
        string tool;
};

// USEFUL FUNCTIONS BEGINS //

void create();

void modify();

void utility();

void log();

void total_words(string text);

void count_certain_word(string text);

void find_word(string text);

void replace_word(string text, string name);

void under_construction();
int close();

void cls();

// USEFUL FUNCTIONS ENDS //

//// HOMEPAGE FUNCTION ////
int main_func()
{
    cls(); // Clears Console Screen

    int num;
    cout << "// Welcome To CONSOLE TEXT EDITOR V1\n";
    cout << "// Made By Rakibul Hasan\n\n";

cout << "    ;dk0KKKKKKKKK0Oxc.   c0KKKKKKKKKKKKKKKKKKKo. ,x0KKKKKKKKKKKO;\n";
cout << "  .xNMMNKOOOO00O0XWMW0; 'xOOOOOO0NMMMWXOOOOO0d.  lWMMN0OOOOOOOOc\n";
cout << "  lWMMO;.       ..dNMMO.        .kMMMWl          lWMMx.\n";
cout << " .xMMWc           '0WMK,        .xMMMWc          oWMMd\n";
cout << " .xMMNc           .OWNk'        .xMMMWc          lWMMd\n";
cout << " .xMMNc           .:c'.         .xMMMWc          oWMMd\n";
cout << " .xMMNc                         .xMMMWc          oWMMk,''''''..'.\n";
cout << " .xMMNc                         .xMMMWc          lWMMWNNNNNNNNN0;\n";    // ASCII ART DISPLAY ;)
cout << " .xMMNc                         .xMMMWc          oWMMXkkkkkkkkx;\n";
cout << " .xMMNc                         .xMMMWc          lWMMd\n";
cout << " .xMMNc            'cxk,        .xMMMWc          oWMMd\n";
cout << " .xMMNc           .OMMX;        .xMMMNc          oWMMd\n";
cout << " .dMMWl           ,KMMK,        .xMMMNc          lWMMd\n";
cout << "  :NMMXo;,,,,,,,,cOWMWx.        .xMWMNc          lWMMk;,,,,,,,,,,,,'.\n";
cout << "   :0WMMMWWWWWWWWMMMXd.         .xMMMN:          lWMMMWWWWWWWWWWWWNd.\n";
cout << "    .;coddddddddddl:.           .oOxo:.          ,ddddddddddddddddl.\n\n";


    cout << "// Choose What You Want To Do-\n";

    cout << "    1. Create A New File \n";
    cout << "    2. Append Existing File \n";   //Displaying Homepage Options
    cout << "    3. Text Utility Tools \n";
    cout << "    4. Log\n";
    cout << "    5. Exit\n\n";
    cout << "// Any Other Number Or Character Will Abort The Application \\\\\n\n";

    cout << "Enter Number To Continue >>  ";
    cin >> num;                                  //For entering choice

    return num;                                 //Returns the choice number
}

//// MAIN FUNCTION ////
int main()
{
    cls();
    switch(main_func())
    {
        case 1:
            create(); // calls CREATE FUNCTION
            break;
        case 2:
            modify(); // calls MODIFY FUNCTION
            break;
        case 3:
            utility(); // calls UTILITY FUNCTION
            break;
        case 4:
            log();  // calls LOG FUNCTION
        case 5:
            close();  // calls EXIT FUNCTION
        default:
            cout << "// Application Aborting... // \n\n";
    }

    return 0;
}


//// CREATE FUNCTION ////
void create()
{
    cls();
    string name,text;

    cout << "DISCLAIMER : OVERWRITE AND NEWLINE ISSUE\n";
    cout << "Don't type the same name as the files in the current folder. It may overwrite those files. Be aware !!!\n\n";
    cout << "Pressing the \"ENTER\" key will save the file\n\n";
    cout << "Enter the new file name with extension: ";
    cin >> name;

    ofstream out(name); //Get name string to create file
    cout << "TYPE >> ";
    cin.ignore();  //Ignores last input
    getline(cin, text);   // puts input in "text" variable
    out << text;
    out.close();          // saves the file in local directory

    //put the data in the LOG
//    ofstream rec;
//    rec.open("record.log", ios::app);
//
//    time_t t;
//    time(&t);
//
//    cout << ctime(&t);
//    log_class temp;
//    temp.name = name;
//    temp.date = ctime(&t);
//    temp.tool = "CREATE";
//
//    rec.write((char*)&temp, sizeof(temp));
//    rec.close();

    cout << "\n\n" << name << " has been saved !!!\n\n";

    // Gets user if the user wants to exit or go to mainmenu
    char y_n_choice;
    cout << "Return to MAINMENU ?\n";
    cout << "Y/y = yes\n";
    cout << "N/n or Any character = No and Exit Application\n";
    cout << "Y / N ? >> ";
    cin >> y_n_choice;

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
    cls();
    string name, newtext, prevtext;
    cout << "Pressing the \"ENTER\" key will save the file\n\n";
    cout << "Enter the new file name with extension: ";
    cin >> name;

    ifstream read;
    read.open(name); //Get name string to read file

    // if name is INVALID then loop user input till the file is found
    while(!read)
    {
        cls();

        cout << "File doesn't exists !!!\n\n";
        cout << "Enter the new file name with extension: ";
        cin >> name;
        read.open(name);
    }

    cout << "TYPE >> ";
    getline(read,prevtext); //reads the file into "prevtext" variable
    cout << prevtext;
    cin.ignore();

    getline(cin, newtext); //takes new input in "newtext" variable

    ofstream write;
    write.open(name, ios::app); // opens the file to append mode
    write << newtext; // adds string to the end of file.
    write.close();  // saves the file
    cout << "\n\n" << name << " has been modified !!!\n\n";

    // Gets user if the user wants to exit or go to mainmenu
    char y_n_choice;
    cout << "Return to MAINMENU ?\n";
    cout << "Y/y = yes\n";
    cout << "N/n or Any character = No and Exit Application\n";
    cout << "Y / N ? >> ";
    cin >> y_n_choice;

    if(y_n_choice == 'Y' || y_n_choice == 'y')
    {
        main();
    }else
    {
        close();
    }

}

//// LOG ////
void log()
{
    cls();
    // For reading log file
    ifstream rec;
    rec.open("record.log", ios::in);

    log_class temp;
    int flag = 0;
    rec.read( (char*)&temp, sizeof(temp) );
        printf("\n%s    ", temp.date);
        printf("%s  ", temp.name);
        printf("%s  \n\n", temp.tool);
        flag = 1;

    if(flag == 0)
    {
        printf("\n  No Record Found!\n\n");
    }

    rec.close();

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

//// UTILITY FUNCTION ////
void utility()
{
    int choice;
    string name, prevtext;
    cls();
    system("Color 07"); // changes background color to "BLACK" and foreground color "WHITE"
    cout << "// Welcome To Text Utility !!!\n";

    cout << "Enter the new file name with extension: ";
    cin >> name; //takes the file name with extension

    ifstream read;
    read.open(name); //open the file in read mode

    // if name is INVALID then loop user input till the file is found
    if(!read)
    {
        while(1)
        {
            cls();
            if(read)
            {
                break;
            }else
            {
                cout << "File doesn't exists !!!\n\n";
            }
            cout << "Enter file name with extension: ";
            cin >> name;
            read.open(name);
        }
    }

    cls();

    getline(read,prevtext); //read the file in "prevtext" variable
    cout<< "File Name : " << name << endl << endl;
    cout<< "READ << ";
    cout << prevtext<< " >> FILE ENDED" <<"\n" <<endl;

    cout << "Enter choice to use the features below -\n\n";

    cout << "   1. Total words" <<endl;
    cout << "   2. Count certain word" <<endl;
    cout << "   3. Find word" <<endl;              //Displaying Utility Options
    cout << "   4. Replace word\n" <<endl;
    cout << "   H. Return to MAINMENU\n" <<endl;

    cout << "TYPE >> ";

    cin >> choice;

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
            cin.clear();
            fflush(stdin);
            main();
    }

}

//// TOTAL WORD COUNTING FUNCTION ////
void total_words(string text)
{
    cls();
    cout << "TOTAL WORDS -" << endl;

    int t_words = 0;
    int i = 0;
    int temp=0;

    while(i < text.size() )
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

    cout << t_words << endl << endl; // print total counted number

    cout << "// CLICK ANY BUTTON THEN PRESS \"ENTER\" TO RETURN \\\\ \n";

    int choice;
    cin >> choice;

    switch(choice)
    {
        default:
            cin.clear();
            fflush(stdin);  // flush the input stream
            utility();
    }
}

//// COUNTING SPECIFIC WORD FUNCTION ////
void count_certain_word(string text)
{
    cls();
    string cert_word;
    cout << "Enter The Word : ";
    cin >> cert_word; // the word we will count

    int t_words = 0;
    size_t i = 0;
    int temp=0;
    size_t  start = 0;


    while((i = text.find(cert_word, start)) != string::npos) //if cert_word is found in text
    {
        t_words++;
        start = i + cert_word.size();
    }


    cout << "Counted Word : " << t_words << endl << endl;

    cout << "// CLICK ANY BUTTON THEN PRESS \"ENTER\" TO RETURN \\\\ \n";

    int choice;
    cin >> choice;

    switch(choice)
    {
        default:
            cin.clear();
            fflush(stdin);
            utility();
    }

}

//// UNDER CONSTRUCTION FUNCTION ////
void under_construction()
{
    system("Color 40");
    cout << "// THIS PART IS STILL UNDER CONSTRUCTION \\\\\n\n";
    cout << "Press any key to return HOME - ";

    int choice;
    cin >> choice;

    switch(choice)
    {
        default:
            cin.clear();
            fflush(stdin);
            utility();
    }

}

//// FIND SPECIFIC WORD FUNCTION ////
void find_word(string text)
{
    cls();
    string cert_word;
    printf("\\\\ The founded word will be all in CAPITALIZED\n\n");
    cout << "Enter The Word : ";
    cin >> cert_word;

    int i, j, found, count;
    int stringLen, searchLen;

    stringLen = text.size();
    searchLen = cert_word.size();

    count = 0;

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

    cout << "// CLICK ANY BUTTON THEN PRESS \"ENTER\" TO RETURN \\\\ \n";

    int choice;
    cin >> choice;

    switch(choice)
    {
        default:
            cin.clear();
            fflush(stdin);
            utility();
    }
}

//// REPLACE SPECIFIC WORD FUNCTION ////
void replace_word(string text, string name)
{
    cls();
    cout << "ORIGINAL : " << text <<" \n\n";
    string rep_word, spec_word;
    cout << "Enter The Word You Want To Replace: ";
    cin >> spec_word;
    cin.ignore();
    cout << "Enter The Word You Want " << spec_word << " To Be Replaced With : ";
    cin >> rep_word;
    cin.ignore();

    int i, j, found, _count;
    int stringLen, searchLen;

    stringLen = text.size();
    searchLen = spec_word.size();

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
             text.replace(i,searchLen,rep_word); // if the word is found replace next searchLen with rep_word
        }
    }

    cout << "\n\nREPLACED : " << text << endl << endl;

    printf("// Save The Replaced Text ? ");
    cout << "- ( WARNING: Will Overwrite The Original " << name << " File )\n\n";
    printf("    Y/y     : Yes, Save and Overwrite\n");
    printf("    ANY KEY : No\n\n");

    char choice;
    printf("(Y/N) >> ");
    scanf("%c", &choice);

    if(choice == 'Y' || choice == 'y')
    {
        ofstream out(name); //Get name string to create file
        out << text;
        out.close();

        cout << "\n// " << name << " has been saved !!!\n";
    }


    printf("\n// CLICK ANY BUTTON THEN PRESS \"ENTER\" TO RETURN \\\\ \n");

    cin.ignore();
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

//// EXIT FUNCTION ////
int close()
{
    cls();
    cout << "Thank You For Using CONSOLE TEXT EDITOR V1!!!\n\n";
    exit(0); // Exits The Application
}

//// CLEARSCREEN FUNCTION ////
void cls()
{
    //defined using macros and conditions to find os using clear command based on os
    #ifdef _WIN32
        system("CLS");

    #elif __APPLE__
        system("clear");

    #elif __linux__
        system("clear");

    #elif TARGET_OS_EMBEDDED
        system("clear");

    #elif TARGET_IPHONE_SIMULATOR
        system("clear");

    #elif TARGET_OS_IPHONE
        system("clear");

    #elif TARGET_OS_MAC
        system("clear");

    #elif__ANDROID__
        system("clear");

    #elif __unix__
        system("clear");

    #elif _POSIX_VERSION
        printf("\e[3J\033c");

    #else
        printf("Sorry, unknown operating system. This program will not support clearscreen now \n\n\n\n\n");
    #endif
        ;
}
