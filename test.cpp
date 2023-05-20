#include <iostream>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <istream>
#include <stdlib.h>
using namespace std;

struct student
{
    char name[80];
    int roll;
    float cpp, java, writing, alg, sum, average;
};

void mainmenu();
void intro();
void addStud();
void searchStud(int);
void modifyStud(int);
void gmrksht(int);
void deleteStud(int);
void viewallStud();
//void changepwd();

void intro()
{
    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(300);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(300);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(300);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(300);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(300);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"\t\t\t\t  THIS IS STUDENT RECORD MANEGEMENT SYSTEM"<<endl;
    Sleep(500);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"press any key to continue...";
    cin.ignore();
};

class auth
{
    string uname[5] = {
        "Sainath",
        "Karan",
        "kp",
        "ashish",
        "random"};
    string pass[5] = {
        "password",
        "password",
        "password",
        "password",
        "password"};

public:
    bool login(string username, string password)
    {
        for (int i = 0; i < 5; i++)
        {

            if (uname[i] == username && pass[i] == password)
            {

                return true;
            }
        }
        return false;
    }
    void changePass(string username)
    {
        for (int i = 0; i < 5; i++)
        {

            if (uname[i] == username)
            {
                string npass;
                cout << "Enter new password : ";
                cin >> npass;
                uname[i] == npass;
                cout << "You have successfully changed password";
            }
        }
    }
};
class StudentRecord
{
public:
    void mainmenu()
    {
        char cc;
        cout << "\t\t\t\t=================MAIN MENU================\n\n"
             << endl;
        Sleep(300);
        cout << "\t\t\t\t1. CREATE STUDENT RECORD\n\n"
             << endl;
        Sleep(300);
        cout << "\t\t\t\t2. SEARCH A STUDENT RECORD \n\n"
             << endl;
        Sleep(300);
        cout << "\t\t\t\t3. MODIFY RECORD \n\n"
             << endl;
        Sleep(300);
        cout << "\t\t\t\t4. GENERATE MARKSHEET\n\n"
             << endl;
        Sleep(300);
        cout << "\t\t\t\t5. DELETE RECORD\n\n"
             << endl;
        Sleep(300);
        cout << "\t\t\t\t6. VIEW ALL STUDENT'S RECORD \n\n"
             << endl;
        Sleep(300);
        cout << "\t\t\t\t==============================" << endl;
        Sleep(300);
        cout << "\t\t\t\tENTER YOUR CHOICE...:) <1-6> :";
        Sleep(300);
        cin >> cc;
        cout << endl;
        switch (cc)
        {
        case '1':
        {
            addStud();
            break;
        }
        case '2':
        {
            int n;
            cout << "ENTER STUDENT'S ROLL NUMBER :";
            cin >> n;
            searchStud(n);
            break;
        }
        case '3':
        {
            int n;
            cout << "ENTER STUDENT'S ROLL NUMBER :";
            cin >> n;
            modifyStud(n);
            break;
        }

        case '4':
        {
            int n;
            cout << "ENTER STUDENT'S ROLL NUMBER :";
            cin >> n;
            cout << endl;
            gmrksht(n);
            break;
        }
        case '5':
        {
            int n;
            cout << "ENTER STUDENT'S ROLL NUMBER :";
            cin >> n;
            cout << endl;
            deleteStud(n);
            break;
        }
        case '6':
        {
            int n;
            cout << "ENTER STUDENT'S ROLL NUMBER :";
            cin >> n;
            cout << endl;
            viewallStud();
        };
        }
    }

    void addStud()
    {
        system("cls");
        student s;
        ofstream outfile;
        outfile.open("RECORD.txt", ios::app | ios::binary);
        if (outfile.fail())
        {
            cout << "THE FILE COULD NOT BE OPEN...press enter key";
            cin.ignore();
            cin.get();
        }
        cout << "\n\n";
        cout << "\t\t\t\t==============ENTER STUDENT RECORD===============\n\n";
        cout << "ENTER YOUR FULL NAME :";
        cin.ignore();
        cin.getline(s.name, 80);
        cout << "ENTER STUDENT'S ROLL NUMBER :";
        cin >> s.roll;
        cout << "ENTER STUDENT'S C++ MARK :";
        cin >> s.cpp;
        cout << "ENTER STUDENT'S JAVA MARK :";
        cin >> s.java;
        cout << "ENTER STUDENT'S WRITING SKILL MARK :";
        cin >> s.writing;
        cout << "ENTER STUDENT'SALGEBRA MARK :";
        cin >> s.alg;
        s.sum = s.cpp + s.java + s.writing + s.alg;
        s.average = (s.sum / 4);

        s.sum = s.cpp + s.java + s.writing + s.alg;
        s.average = (s.sum / 4);
        outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
        outfile.close();
        cout << endl;

        cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
        cout << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
    }

    void searchStud(int n)
    {
        system("cls");
        student s;
        ifstream infile;
        infile.open("RECORD.txt", ios::app | ios::binary);
        if (infile.fail())
        {
            cout << "THE FILE COULD NOT BE OPENED...";

            cin.ignore();
            cin.get();
        }
        bool equality = false;
        cout << "\t\t\t\t==========VIEW A SINGLE STUDENT RECORD==========\n\n";
        while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            if (s.roll == n)
            {
                cout << "\t\t\t\tSTUDENT NAME :" << s.name << endl;
                cout << "\t\t\t\tSTUDENT ROLL NUMBER :" << s.roll << endl;
                cout << "\t\t\t\tC++ MARK :" << s.cpp << endl;
                cout << "\t\t\t\tJAVA MARK :" << s.java << endl;
                cout << "\t\t\t\tWRITING SKILL MARK :" << s.writing << endl;
                cout << "\t\t\t\tALGEBRA MARK :" << s.alg << endl;
                cout << "\t\t\t\tSUM :" << s.sum << endl;
                cout << "\t\t\t\tAVERAGE :" << s.average << endl;
                cout << "\t\t\t\t================================================" << endl;
                equality = true;
            }
        }
        infile.close();
        if (equality == false)
            cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
        cout << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
    }

    void gmrksht(int n)
    {
        system("cls");
        student s;
        ifstream infile;
        infile.open("RECORD.txt", ios::app | ios::binary);
        if (infile.fail())
        {
            cout << "THE FILE COULD NOT BE OPENED..." << endl;
            cin.ignore();
            cin.get();
        }
        bool eq = false;
        cout << "\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
        while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            if (s.roll == n)
            {
                cout << "\t\t\t\tSTUDENT NAME :" << s.name << endl
                     << endl;
                cout << "\t\t\t\tC++ MARK :" << s.cpp << endl
                     << endl;
                cout << "\t\t\t\tJAVA MARK :" << s.java << endl
                     << endl;
                cout << "\t\t\t\tWRITING SKILL MARK :" << s.writing << endl
                     << endl;
                cout << "\t\t\t\tALGEBRA MARK :" << s.alg << endl
                     << endl;
                cout << "\t\t\t\tSUM :" << s.sum << endl
                     << endl;
                cout << "\t\t\t\tAVERAGE :" << s.average << endl
                     << endl;
                cout << "\t\t\t\t==================================================" << endl;
                eq = true;
            }
        }
        infile.close();
        if (eq == false)
            cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
        cout << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
    }

    void modifyStud(int n)
    {
        system("cls");
        student s;
        fstream infile;
        infile.open("RECORD.txt", ios::binary | ios::in | ios::out);
        if (infile.fail())
        {
            cout << "THE FILE COULD NOT BE OPENED..." << endl;
            cin.ignore();
            cin.get();
        }
        bool checker = false;
        cout << "\t\t\t\t==========MODIFY STUDENT RECORD ==========\n\n";
        while (!infile.eof() && checker == false)
        {
            infile.read(reinterpret_cast<char *>(&s), sizeof(student));
            {
                if (s.roll == n)
                {
                    cout << "\t\t\t\tSTUDENT NAME :" << s.name << endl
                         << endl;
                    cout << "\t\t\t\tC++ MARKS :" << s.cpp << endl
                         << endl;
                    cout << "\t\t\t\tJAVA MARKS :" << s.java << endl
                         << endl;
                    cout << "\t\t\t\tWRITING SKILL MARKS :" << s.writing << endl
                         << endl;
                    cout << "\t\t\t\tALGEBRA MARKS :" << s.alg << endl
                         << endl;
                    cout << "=============================================" << endl;
                    cout << "\t\tENTER THE NEW DATA" << endl;
                    cout << "=============================================" << endl;
                    cout << "ENTER YOUR FULL NAME :";
                    cin.ignore();
                    cin.getline(s.name, 80);
                    cout << "ENTER STUDENT'S ROLL NUMBER :";
                    cin >> s.roll;
                    cout << "ENTER STUDENT'S C++ MARKs :";
                    cin >> s.cpp;
                    cout << "ENTER STUDENT'S YOUR JAVA MARKS :";
                    cin >> s.java;
                    cout << "ENTER STUDENT'S WRITING SKILL MARKS :";
                    cin >> s.writing;
                    cout << "ENTER STUDENT'S ALGEBRA MARKS :";
                    cin >> s.alg;
                    s.sum = s.cpp + s.java + s.writing + s.alg;
                    s.average = (s.sum / 4);
                    int pos = (-1) * static_cast<int>(sizeof(student));
                    infile.seekp(pos, ios::cur);
                    infile.write(reinterpret_cast<char *>(&s), sizeof(student));
                    cout << endl;
                    cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY updated" << endl;
                    checker = true;
                }
            }
        }
        infile.close();
        if (checker == false)
            cout << "\t\t\t\tRECORD NOT FOUND" << endl;
        cout << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
    }

    void deleteStud(int n)
    {
        system("cls");
        student s;
        ifstream infile;
        infile.open("RECORD.txt", ios::binary);
        if (!infile)
        {
            cout << "THE FILE COULD NOT BE OPENED..." << endl;
            cin.ignore();
            cin.get();
        }
        ofstream outfile;
        outfile.open("Record2.txt", ios::binary);
        infile.seekg(0, ios::beg);
        cout << "\t\t\t\t===========DELETE A RECORD CARD==========\n\n";
        while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            if (s.roll != n)
            {
                outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
            }
        }
        infile.close();
        outfile.close();
        remove("RECORD.txt");
        rename("Record2.txt", "RECORD.txt");
        cout << endl;
        cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED" << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
    }

    void viewallStud()
    {
        system("cls");
        student s;
        ifstream infile;
        bool check = false;
        infile.open("RECORD.txt", ios::app | ios::binary);
        if (infile.fail())
        {
            cout << "THE FILE COULD NOT BE OPENED.....press enter key...";
            cin.ignore();
            cin.get();
        }
        cout << "\n\n";
        cout << "\t\t\t\tALL STUDENTS RECORD" << endl;
        cout << "==================================================================================" << endl;
        while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            cout << "\t\t\t\tSTUDENT NAME :" << s.name << endl
                 << endl;
            cout << "\t\t\t\tSTUDENT ROLL NUMBER :" << s.roll << endl
                 << endl;
            cout << "\t\t\t\tC++ MARKS :" << s.cpp << endl
                 << endl;
            cout << "\t\t\t\tJAVA MARKS :" << s.java << endl
                 << endl;
            cout << "\t\t\t\tWRITING SKILL MARKS :" << s.writing << endl
                 << endl;
            cout << "\t\t\t\tALGEBRA MARKS :" << s.alg << endl
                 << endl;
            cout << "\t\t\t\tSUM :" << s.sum << endl
                 << endl;
            cout << "\t\t\t\tAVERAGE :" << s.average << endl
                 << endl;
            cout << "==================================================================================" << endl;
            check = true;
        }
        infile.close();

        if (check == false)
            cout << "\t\t\t\tNO RECORD FOUND..." << endl
                 << endl;
        cout << "press any key to continue....";
        cin.ignore();
        cin.get();
    }
};
int main()
{
    // string uname;
    // string pass;
    // cout << "Enter username: ";
    // cin >> uname;
    // cout << "Enter password : ";
    // cin >> pass;
    auth obj;
    // StudentRecord obj2;

    // if (obj.login(uname, pass))
    // {
    //     intro();
    //     obj2.mainmenu();
    // }
    string username;
    cout << "Enter your username : ";
    cin >> username;
    obj.changePass(username);
  

    // StudentRecord obj;
    // char c;
    // system("cls");
    //obj.intro();

    // do
    // {
    //     system("cls");
    //     system("color e");
    //     cout << "\n\n";
    //     cout << "\t====================STUDENT RECORD MANEGEMENT SYSTEM====================" << endl;
    //     cout << endl;
    //     cout << "\t\t\t\t1. MAIN MENU\n\n";
    //     cout << "\t\t\t\t2. EXIT\n\n";
    //     cout << "ENTER YOUR CHOICE :";
    //     cin >> c;
    //     system("cls");
    //     switch (c)
    //     {
    //     case '1':
    //     {
    //         mainmenu();
    //         break;
    //     }
    //     case '2':
    //     {
    //         cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE" << endl;
    //     }

    //     }
    // } while (c != '2');
    //return 0;
}