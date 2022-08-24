#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include<string.h>
#include<fstream>

using namespace std;


int exit()
{
    system("CLS");
    printf("Thank You For Using CONSOLE TEXT EDITOR V1!!!\n\n");
    exit(0);
}

int main_func()
{
    system("CLS");

    int num;
    printf("// Welcome To CONSOLE TEXT EDITOR V1\n");
    printf("// Made By Rakibul Hasan\n\n");

printf("    ;dk0KKKKKKKKK0Oxc.   c0KKKKKKKKKKKKKKKKKKKo. ,x0KKKKKKKKKKKO;\n");
printf("  .xNMMNKOOOO00O0XWMW0; 'xOOOOOO0NMMMWXOOOOO0d.  lWMMN0OOOOOOOOc\n");
printf("  lWMMO;.       ..dNMMO.        .kMMMWl          lWMMx.\n");
printf(" .xMMWc           '0WMK,        .xMMMWc          oWMMd\n");
printf(" .xMMNc           .OWNk'        .xMMMWc          lWMMd\n");
printf(" .xMMNc           .:c'.         .xMMMWc          oWMMd\n");
printf(" .xMMNc                         .xMMMWc          oWMMk,''''''..'.\n");
printf(" .xMMNc                         .xMMMWc          lWMMWNNNNNNNNN0;\n");
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
    printf("    2. Modify Existing File \n");
    printf("    3. Text Utility Tools \n");
    printf("    4. Exit\n\n");
    printf("// Any Other Number Or Character Will Abort The Application \\\\\n\n");

    printf("Enter Numbers To Continue: ");
    cin >> num;

    return num;
}

void create();

void modify();

void utility();

void total_words(string text);

void count_certain_word(string text);

void find_word(string text);

void replace_word(string text);

void under_construction();

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
            exit();
        default:
            printf("// Application Aborting // \n\n");
    }

    return 0;
}

void create()
{
    system("CLS");
    string name,text;

    cout << "DISCLAIMER : OVERWRITE AND NEWLINE ISSUE\n";
    cout << "Don't type the same name as the files in the current folder. It may overwrite those files. Be aware !!!\n\n";
    cout << "Pressing the \"ENTER\" key will save the file\n\n";
    cout << "Enter the new file name with extension: ";
    cin >> name;

    ofstream out(name);
    cout << "TYPE >> ";
    cin.ignore();
    getline(cin, text);
    out << text;
    out.close();
    cout << "\n\n" << name << " has been saved !!!\n\n";

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
        exit();
    }
}

void modify()
{
    system("CLS");
    string name,newtext,prevtext;
    cout << "Pressing the \"ENTER\" key will save the file\n\n";
    cout << "Enter the new file name with extension: ";
    cin >> name;

    ifstream read;
    read.open(name);

    while(!read)
    {
        system("CLS");

        cout << "File doesn't exists !!!\n\n";
        cout << "Enter the new file name with extension: ";
        cin >> name;
        read.open(name);
    }

    cout << "TYPE >> ";
    getline(read,prevtext);
    cout << prevtext;
    cin.ignore();
    getline(cin, newtext);

    ofstream write;
    write.open(name, ios::app);
    write << newtext;
    write.close();
    cout << "\n\n" << name << " has been modified !!!\n\n";

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
        exit();
    }

}

void utility()
{
    int choice;
    string name, prevtext;
    system("CLS");
    system("Color 07");
    cout << "Welcome To Text Utility !!!\n";

    cout << "Enter the new file name with extension: ";
    cin >> name;

    ifstream read;
    read.open(name);

    if(!read)
    {
        while(1)
        {
            system("CLS");
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

    system("CLS");

    getline(read,prevtext);
    cout<< "File Name : " << name << endl << endl;
    cout<< "READ << ";
    cout << prevtext<< " >> FILE ENDED" <<"\n" <<endl;

    cout << "Enter choice to use the features below -\n\n";

    cout << "1. Total words" <<endl;
    cout << "2. Count certain word" <<endl;
    cout << "3. Find word" <<endl;
    cout << "4. Replace word\n" <<endl;
    cout << "H. Return to MAINMENU\n" <<endl;

    cout << "TYPE >> ";

    cin >> choice;

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
            cin.clear();
            fflush(stdin);
            main();
    }

}

void total_words(string text)
{
    system("CLS");
    cout << "TOTAL WORDS -" << endl;

    int t_words = 0;
    int i = 0;
    int temp=0;

    while(i < text.size() )
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

    cout << t_words << endl << endl;

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

void count_certain_word(string text)
{
    system("CLS");
    string cert_word;
    cout << "Enter The Word : ";
    cin >> cert_word;

    int t_words = 0;
    size_t i = 0;
    int temp=0;
    size_t  start = 0;


    while((i = text.find(cert_word, start)) != string::npos)
    {
        t_words++;
        start = i + cert_word.size();
    }


    cout << t_words << endl << endl;

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


void find_word(string text)
{
    system("CLS");
    under_construction();
}

void replace_word(string text)
{
    system("CLS");
    under_construction();
}
