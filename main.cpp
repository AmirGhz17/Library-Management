#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include  <bits/stdc++.h>

using namespace std;

void welcome();
void Exit();
void firstmenu();
void Admin_Login();
void User_Login();
void User_Signup();
void Add_Admin();
void Add_Book();
void Delete_Book();
void Edit_Book();
void Admin_Menu();

int i=0;
int j=0;
int k=0;

struct {
    string book_id;
    string book_title;
    string author_fullname;
    string price_punishment;
    string name_returndate_borrower;
    string list_waitingfor_borrowedbook;
} books[100];

int bookno=0;

struct {
    string admin_id;
    string admin_fullname;
    string admin_pass;
} admins[100];

int adminno=0;

struct {
    string user_id;
    string user_pass;
    string user_fullname;
    string phone_no;
    string id_allbook_userhave;
} users[100];

int userno=0;

int main(){
    welcome();
    firstmenu();

    return 0;
}

void welcome(){
    cout << "\t\t\t\t====================================================" << endl;
    cout << "\t\t\t\t*                                                  *" << endl;
    cout << "\t\t\t\t*                                                  *" << endl;
    cout << "\t\t\t\t*                  W E L C O M E                   *" << endl;
    cout << "\t\t\t\t*                                                  *" << endl;
    cout << "\t\t\t\t*                  T O       U R                   *" << endl;
    cout << "\t\t\t\t*                                                  *" << endl;
    cout << "\t\t\t\t*                  L I B R A R Y                   *" << endl;
    cout << "\t\t\t\t*                                                  *" << endl;
    cout << "\t\t\t\t*                                                  *" << endl;
    cout << "\t\t\t\t====================================================" << endl << endl << "\t\t\t\t\t";
    system("pause");
}

bool flag=true;

void firstmenu(){
    system ("cls");
    int key;

    while(flag){
        cout << "\t\t\t\t=========================================================" << endl;
        cout << "\t\t\t\t*                                                       *" << endl;
        cout << "\t\t\t\t*                  Admin Login  [1]                     *" << endl;
        cout << "\t\t\t\t*                  User  Login  [2]                     *" << endl;
        cout << "\t\t\t\t*                  User  Signup [3]                     *" << endl;
        cout << "\t\t\t\t*                  Exit         [0]                     *" << endl;
        cout << "\t\t\t\t*                                                       *" << endl;
        cout << "\t\t\t\t=========================================================" << endl << endl;

        cout << "\t\t\t\t\tC H O O S E    Y O U R    O P T I O N : ";
        cin >> key;

        switch(key)
        {
            case 1 : Admin_Menu();
                break;
            case 2 : User_Login();
                break;
            case 3 : User_Signup();
                break;
            case 0 : Exit();
                break;
            default :
                system ("cls");
                cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n" << endl;
        }
    }
}

void Exit()
{
    system ("cls");
    cout << "\t\t\t\t  ====================================================\n";
    cout << "\t\t\t\t  #                HAVE A GOOD TIME                  #\n";
    cout << "\t\t\t\t  ====================================================";
    flag=false;
}

void Add_Admin()
{
    system ("cls");
    ifstream admin_file("admin.txt");

    long admin_id,admin_id2;
    string admin_name;
    string admin_pass;
    admin_id2 = 1000000000+rand()%888888889+445462356;
    while(admin_file >> admin_id){
        while(admin_id2==admin_id)
            admin_id2 = 1000000000+rand()%888888889+445462356;
    }
    admin_file.close();
    cout << "E N T E R    T H E    N E W    A D M I N    N A M E: ";
    getline(cin,admin_name);
    getline(cin,admin_name);
    cout << endl;

    cout << "\nP A S S W O R D\n(just numbers & letters without space)\n(uppercase and lowercase letters are important)\nE N T E R: ";
    cin >> admin_pass;

    ofstream admin_file2("admin.txt");
    admin_file2 << admin_name << " " << admin_id2 << " " << admin_pass << endl;
    cout << "\nY O U R    A D M I N    I D: " << admin_id2 <<endl;
}

void Admin_Login()
{
    string username="amir", password="radman";
    string user , pass;
    cout << "E N T E R    Y O U R    I D: ";
    cin >> user;
    cout << "E N T E R    Y O U R    P A S S W O R D: ";
    cin >> pass;
    if(user == username && pass == password){
        Admin_Menu();
    }
    else {
        cout<<"your user or password is wrong";
        Admin_Login();
    }

}

void Admin_Menu()
{
    system ("cls");
   
    int key_admin;

    cout << "\t\t\t\t=========================================================" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t*                 Add     Book  [1]                     *" << endl;
    cout << "\t\t\t\t*                 Delete  Book  [2]                     *" << endl;
    cout << "\t\t\t\t*                 Edit    Book  [3]                     *" << endl;
    cout << "\t\t\t\t*                 Add     Admin [4]                     *" << endl;
    cout << "\t\t\t\t*                 Back          [0]                     *" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t=========================================================" << endl << endl;
    cout << "\t\t\t\t\tC H O O S E    Y O U R    O P T I O N : ";

    cin >> key_admin;

    switch(key_admin){
        case 1 : Add_Book();
            break;
        case 2 : Delete_Book();
            break;
        case 3 : Edit_Book();
            break;
        case 4: Add_Admin();
            break;
        case 0 : firstmenu();
            break;
        default :
            system ("cls");
            cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n" << endl;
    }
}

void User_Login()
{
    cout << "hi";
}

void User_Signup()
{
    string name;
    string password;


}

void Add_Book()
{
   
}

void Delete_Book()
{
    cout << "hi";
}

void Edit_Book()
{
    cout << "hi";
}

