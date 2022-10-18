#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 256
using namespace std;
void password_validator(char *username, char *password);
void regist();
void login()
{
    bool keepgoing = false;
    ofstream passupdate;
    ifstream passlist;
    ofstream userinfo;
    printf("Welcome to Relaxxx, the mindfulness journal\n");
    do
    {
        if (keepgoing == true)
        {
            cin.ignore(10000);
            cin.clear();
        }
        printf("1. Login for existing users\n");
        printf("2. Create an account for new users\n");
        int x;
        cin >> x;
        if (x != 1 && x != 2)
        {

            cout << "Invalid choice" << endl;
            keepgoing = true;
            continue;
        }
        if (x == 1)
        {
            char *username;
            char *password;
            printf("Username: ");
            cin >> username;
            cout << "\nPassword: ";
            cin >> password;
            password_validator(username, password);
        }
        else
        {
            regist();
        }
    } while (keepgoing == true);
};

void regist()
{
    ofstream f;
    ofstream i;
    f.open("userpass.csv", ios::app);
    i.open("info.txt", ios::app);
    string firstname;
    string lastname;
    int age;
    string gender;
    string username;
    string password;
    cout << "We will take your basic information and save it in a file to our records so that we can see our demographics" << endl;
    cout << "If this makes you uncomfortable, press CTRL + C to abort the program" << endl;

    cout << "Firstname: ";
    cin >> firstname;
    i << firstname << " ";
    cout << endl;
    cout << "Lastname: ";
    cin >> lastname;
    i << lastname << " ";
    cout << endl;
    cout << "Age: ";
    cin >> age;
    i << age << " ";
    cout << endl;
    cout << "Gender: ";
    cin >> gender;
    i << gender << " ";
    cout << endl;
    cout << "Username: ";
    cin >> username;
    i << username << " ";
    f << username << ",";
    cout << endl;
    cout << "Password: ";
    cin >> password;
    i << password << "\n";
    f << password << '\n';
    cout << "Registration complete, welcome " << username << endl;
    f.close();
    i.close();
    // doprogram
};

void password_validator(char *username, char *password)
{
    FILE *f;
    f = fopen("userpass.csv", "r");
    char *buf = new char[MAX_STR_LENGTH];
    char *tmp;
    char *tmppass;
    char *name;
    char *pass;
    while (fgets(buf, 255, f) != NULL)
    {

        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
            buf[strlen(buf) - 1] = '\0';
        tmp = strtok(buf, ",");
        name = tmp;
        tmp = strtok(NULL, ",");
        pass = tmp;

        if (strcmp(username, name) == 0 && strcmp(password, pass) == 0)
        {
            printf("Welcome %s...\n", username);
            cout << "Now for your daily question.... \nA new mindfullness experiment of this application to allow you to assess your life" << endl;
            // do things
            fclose(f);
        }
    }
    if (feof(f) != 0)
    {
        printf("Username/Password combo not found.");
        fclose(f);
        login();
    }
};

int getchoice()
{
    int userchoice;
    cout << "Pick a number 1-9 so that we can formulate a specfic question to help your reflection of the day" << endl;
    cin >> userchoice;
    return userchoice;
};
string shortquestion(int userchoice)
{
    string answer;
    switch (userchoice)
    {
    case 1:
        cout << "What is something that made you laugh today?" << endl;
        break;
    case 2:
        cout << "What challenged you today?" << endl;
        break;
    case 3:
        cout << "What was suprisingly easy for you to accomplish today?" << endl;
        break;
    case 4:
        cout << "What is something new you learned today?" << endl;
        break;
    case 5:
        cout << "Describe a memory that crossed your mind today" << endl;
        break;
    case 6:
        cout << "Who am I?" << endl;
        break;
    case 7:
        cout << "What are you most scared of?" << endl;
        break;
    case 8:
        cout << "Name something you are looking forward to this week" << endl;
        break;
    case 9:
        cout << "If you could take back one of your recent actions; what would it be and why?" << endl;
        break;
    }
    cout << "Type your answer to this reflection prompt followed by the enter key. Do not go over one line." << endl;
    cout << endl;
    cin >> answer;
    cout << endl;
    return answer;
}

int getRating()
{
    int rating;
    cout << "If you could rate your experience today using this application on a scale of 1-10\n 1 being the worst; 10 being the best service. What would you rate your experience?" << endl;
    cout << "This helps us out a in improving the quality of our new features. If you would like to skip, press ctrl + c" << endl;
    cout << endl;
    cin >> rating;
    return rating;
};

int main(int argc, char *argv[])
{
    string filename = argv[1];
    ofstream f;
    f.open(filename, ios::app);
    if (f.is_open() == false)
    {
        printf("file error");
        return 0;
    }
    f.close();
    login();
    int userchoice = getchoice();
    string answer = shortquestion(userchoice);
    int rating = getRating();
    return 1;
}
