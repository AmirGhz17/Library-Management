#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <unistd.h>

using namespace std;

//====================================================================================================

struct borrowed_book
{
    string book_id;
    string user_id;
    string status;
    int day;
} borrowed_books[100];

int b_bookno = 0;
int nowday;

struct book
{
    string book_id;
    string book_title;
    string author_name;
    int fine;
} books[100];

int bookno = 0;

struct admin
{
    string admin_id;
    string admin_name;
    string admin_pass;

} admins[100];

int adminno = 0;
int adminloginno;

struct user
{
    string user_id;
    string user_pass;
    string user_name;
    string phone_no;
} users[100];

int userno = 0;
int userloginno;

//====================================================================================================

void welcome();

void RenderAdmin();

void RenderUser();

void RenderBook();

void RenderBorrowedBook();

void firstmenu();

void Admin_Login();

void User_Login();

void User_Signup();

void Edit_User_Profile();

void User_Menu();

void Edit_User_Name();

void Edit_User_Pass();

void Edit_User_PhoneNumber();

void Add_Reserve_List(string borrow_book);

void User_Borrowed_Books();

void Delay_Money();

void Add_Admin();

void Add_Book();

void Delete_Book();

void Edit_Book();

void Edit_Title();

void Edit_Author();

void Edit_Fine();

void Search_Book();

void Show_Books(book[]);

void Borrow_Book();

string Id_Generator();

void Admin_Menu();

void Extending_Deadline();

void return_book();

//=======================================================================================================================================

int main()
{
    RenderAdmin();
    RenderUser();
    RenderBook();
    RenderBorrowedBook();

    cout << "Please Enter Now Day (1 <= nowday <= 30): ";
    cin >> nowday;

    welcome();
    firstmenu();

    return 0;
}

//=======================================================================================================================================

void welcome()
{
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
    cout << "\t\t\t\t====================================================" << endl
         << endl
         << "\t\t\t\t ";
    cout << "P R E S S    E N T E R    T O    C O N T I N U E";
    getch();
}

//=======================================================================================================================================

void firstmenu()
{
    bool flag = true;
    system("cls");
    int key;

    while (flag)
    {
        cout << "\t\t\t\t=========================================================" << endl;
        cout << "\t\t\t\t*                                                       *" << endl;
        cout << "\t\t\t\t*                  Admin Login  [1]                     *" << endl;
        cout << "\t\t\t\t*                  User  Login  [2]                     *" << endl;
        cout << "\t\t\t\t*                  User  Signup [3]                     *" << endl;
        cout << "\t\t\t\t*                  Exit         [0]                     *" << endl;
        cout << "\t\t\t\t*                                                       *" << endl;
        cout << "\t\t\t\t=========================================================" << endl
             << endl;

        cout << "\t\t\t\t\tC H O O S E    Y O U R    O P T I O N : ";
        cin >> key;
        system("cls");
        switch (key)
        {
        case 1:
            Admin_Login();
            break;
        case 2:
            User_Login();
            break;
        case 3:
            User_Signup();
            break;
        case 0:
            system("cls");
            cout << "\t\t\t\t  ====================================================\n";
            cout << "\t\t\t\t  #                HAVE A GOOD TIME                  #\n";
            cout << "\t\t\t\t  ====================================================";
            sleep(3);
            exit(-1);
            break;
        default:
            system("cls");
            cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n"
                 << endl;
        }
    }
}

//=======================================================================================================================================

void Add_Admin()
{
    system("cls");

    long long admin_id2;
    string admin_id3;
    string admin_name;
    string admin_pass;

    srand(time(0));
    admin_id2 = 1000000000 + rand();

    admin_id3=to_string(admin_id2);

    for(int i=0 ; i<adminno ; i++)
    {
        while (admin_id3 == admins[i].admin_id)
        {
            Add_Admin();
        }
    }

    cout << "E N T E R    T H E    N E W    A D M I N    N A M E: ";
    getline(cin, admin_name);
    getline(cin, admin_name);
    cout << endl;

    cout << "\nP A S S W O R D\n(just numbers & letters without space)\n(uppercase and lowercase letters are important)\nE N T E R: ";
    cin >> admin_pass;

    ofstream admin_file2("admin.txt", ios ::app | ios ::in);
    admin_file2 << admin_id2 << "*" << admin_name << "*" << admin_pass << "*" << endl;
    cout << "\nY O U R    A D M I N    I D: " << admin_id2 << endl;
    system("pause");
    admin_file2.close();
    RenderAdmin();
}

//=======================================================================================================================================

void Admin_Login()
{
    string admin_enter_id;
    string admin_enter_pass;
    int key;

    cout << "E N T E R    Y O U R    I D :  ";
    cin >> admin_enter_id;
    cout << "E N T E R    Y O U R    P A S S W O R D :  ";
    cin >> admin_enter_pass;
    bool flag = false;
    for (int i = 0; i <= adminno; i++)
    {
        if (admin_enter_id == admins[i].admin_id && admin_enter_pass == admins[i].admin_pass)
        {
            cout << "L O G I N    S U C C E S F U L L Y    !\n\n";
            flag = true;
            Admin_Menu();
        }
    }
    if (!flag)
    {
        cout << "I D    O R    P A S S W O R D    W R O N G    !!!\n";
        cout << "DO    Y O U    W A N T    T R Y    A G A I N    ?";
        cout << "YES[1] NO[2]: ";
        cin >> key;
        cout << endl
             << endl;
        switch (key)
        {
        case 1:
            Admin_Login();
            break;
        case 2:
            break;
        }
    }
}

//=======================================================================================================================================

void Admin_Menu()
{
    int key_admin;

    system("cls");

    cout << "\t\t\t\t=========================================================" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t*                 Add     Book  [1]                     *" << endl;
    cout << "\t\t\t\t*                 Delete  Book  [2]                     *" << endl;
    cout << "\t\t\t\t*                 Edit    Book  [3]                     *" << endl;
    cout << "\t\t\t\t*                 Add     Admin [4]                     *" << endl;
    cout << "\t\t\t\t*                 Show    Books [5]                     *" << endl;
    cout << "\t\t\t\t*                 Back          [0]                     *" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t=========================================================" << endl
         << endl;
    cout << "\t\t\t\t\tC H O O S E    Y O U R    O P T I O N : ";

    cin >> key_admin;
    system("cls");
    switch (key_admin)
    {
    case 1:
        Add_Book();
        break;
    case 2:
        Delete_Book();
        break;
    case 3:
        Edit_Book();
        break;
    case 4:
        Add_Admin();
        break;
    case 5:
        Show_Books(books);
        break;
    case 0:
        break;
    default:
        system("cls");
        cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n"
             << endl;
    }
    if (key_admin != 0)
        Admin_Menu();
}

//=======================================================================================================================================

void User_Login()
{
    string user_enter_id;
    string user_enter_pass;
    int key;

    cout << "E N T E R    Y O U R    I D :  ";
    cin >> user_enter_id;
    cout << "E N T E R    Y O U R    P A S S W O R D :  ";
    cin >> user_enter_pass;
    bool flag = false;
    for (int i = 0; i <= userno; i++)
    {
        if (user_enter_id == users[i].user_id && user_enter_pass == users[i].user_pass)
        {
            cout << "L O G I N    S U C C E S F U L L Y    !\n\n";
            flag = true;
            userloginno = i;
            User_Menu();
        }
    }
    if (!flag)
    {
        cout << "I D    O R    P A S S W O R D    W R O N G    !!!\n";
        cout << "DO    Y O U    W A N T    T R Y    A G A I N    ?";
        cout << "YES[1] NO[2]: ";
        cin >> key;
        cout << endl
             << endl;
        switch (key)
        {
        case 1:
            User_Login();
            break;
        case 2:
            break;
        }
    }
}

//=======================================================================================================================================

void User_Menu()
{
    int key_user;

    system("cls");

    cout << "\t\t\t\t=========================================================" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t*               Search     Book     [1]                 *" << endl;
    cout << "\t\t\t\t*               Borrow     Book     [2]                 *" << endl;
    cout << "\t\t\t\t*               Extending  Deadline [3]                 *" << endl;
    cout << "\t\t\t\t*               Edit       Profile  [4]                 *" << endl;
    cout << "\t\t\t\t*               Borrowed   Books    [5]                 *" << endl;
    cout << "\t\t\t\t*               Pay        Fine     [6]                 *" << endl;
    cout << "\t\t\t\t*               return     Book     [7]                 *" << endl;
    cout << "\t\t\t\t*               Back                [0]                 *" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t=========================================================" << endl
         << endl;
    cout << "\t\t\t\t\tC H O O S E    Y O U R    O P T I O N : ";

    cin >> key_user;
    system("cls");
    switch (key_user)
    {
    case 1:
        Search_Book();
        break;
    case 2:
        Borrow_Book();
        break;
    case 3:
        Extending_Deadline();
        break;
    case 4:
        Edit_User_Profile();
        break;
    case 5:
        User_Borrowed_Books();
        break;
    case 6:
        Delay_Money();
        break;
    case 7:
        return_book();
        break;
    case 0:
        break;
    default:
        cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n"
             << endl;
    }
    if (key_user != 0)
        User_Menu();
}

//=======================================================================================================================================

void User_Signup()
{
    system("cls");

    long long user_id2;
    string user_id3;
    string user_name;
    string user_pass;
    string phone_no;
    string id_allbook_userhave;

    srand(time(0));
    user_id2 = 2000000000 + rand();

    user_id3=to_string(user_id2);

    for(int i=0 ; i<userno ; i++)
    {
        while (user_id3 == users[i].user_id)
        {
            User_Signup();
        }
    }

    cout << "E N T E R    Y O U R    N A M E   : ";
    getline(cin, user_name);
    getline(cin, user_name);
    cout << endl;

    cout << "\nP A S S W O R D\n(just numbers & letters without space)\n(uppercase and lowercase letters are important)\nE N T E R   : ";
    cin >> user_pass;

    cout << "\nP L E A S E    E N T E R    Y O U R    P H O N E    N U M B E R   (11 DIGITS) : ";
    cin >> phone_no;

    ofstream user_file2("user.txt", ios ::app | ios ::in);
    user_file2 << user_id2 << "*" << user_name << "*" << user_pass << "*" << phone_no << "*" << endl;
    cout << "\nY O U R    U S E R    I D: " << user_id2 << endl;
    system("pause");
    system("cls");
    RenderUser();
}

//=======================================================================================================================================

void Show_Books(book books[])
{
    book t;
    for (int i = 0; i < bookno; i++)
    {
        for (int j = 0; j < bookno - i - 1; j++)
        {
            if (books[j].book_id[0] > books[j + 1].book_id[0])
            {
                t = books[j];
                books[j] = books[j + 1];
                books[j + 1] = t;
            }
        }
    }
    for (int k = 0; k < bookno; k++)
    {
        cout << books[k].book_id << endl;
        cout << books[k].book_title << endl;
        cout << books[k].author_name << endl;
        cout << books[k].fine << endl;
        cout << "==========\n";
    }
    system("pause");
    Admin_Menu();
}

//=======================================================================================================================================

void Delay_Money()
{
    string borrow_book;

    cout << "W H A T    B O O K    D O    Y O U    W A N T    B O R R O W W (BOOK ID)?  : ";
    getline(cin, borrow_book);
    getline(cin, borrow_book);
    int book_status = -2;
    for (int k = 0; k < b_bookno; k++)
    {
        if (borrow_book == borrowed_books[k].book_id)
        {
            if (borrowed_books[k].user_id == users[userloginno].user_id)
            {
                int space = 0;
                if (nowday >= borrowed_books[k].day)
                {
                    space = nowday - borrowed_books[k].day;
                }
                else
                {
                    space = (nowday + 30) - borrowed_books[k].day;
                }
                if (space <= 7)
                {
                    cout << "Your Time Is Not Ended...\n\n";
                    system("pause");
                    return;
                }
                else
                {
                    for (int i = 0; i < bookno; i++)
                    {
                        if (books[i].book_id == borrowed_books[k].book_id)
                        {
                            cout << "Your Delay For This Book : " << books[i].fine * (space - 7) << endl;
                            system("pause");

                            return;
                        }
                    }
                }
            }
            else if (borrowed_books[k].status == "Borrow")
            {
                break;
            }
        }
    }
    cout << "T H E    B O O K    W I T H    I D    N O T    F O U N D\n";
    system("pause");
    User_Menu();

}

//=======================================================================================================================================

void User_Borrowed_Books()
{
    for (int i = 0; i < b_bookno; i++)
    {
        if (borrowed_books[i].user_id == users[userloginno].user_id)
        {
            for (int k = 0; k < bookno; k++)
            {
                if (borrowed_books[i].book_id == books[k].book_id)
                {
                    cout << "book id : " << books[k].book_id << endl;
                    cout << "book title : " << books[k].book_title << endl;
                    cout << "book author name : " << books[k].author_name << endl;
                    cout << "book fine : " << books[k].fine << endl;
                    break;
                }
            }
            cout << "borrowed day : " << borrowed_books[i].day << endl;
            cout << "borrowed status : " << borrowed_books[i].status << endl;
            cout << "==========\n";
        }
    }
    system("pause");
    User_Menu();
}

//=======================================================================================================================================

void Edit_User_Profile()
{
    cout << "\t\t\t\t=========================================================" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t*         E D I T    Y O U R    P R O F I L E           *" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t=========================================================" << endl;

    sleep(3);

    cout << "\t\t\t\t=========================================================" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t*               Edit   Name         [1]                 *" << endl;
    cout << "\t\t\t\t*               Edit   Password     [2]                 *" << endl;
    cout << "\t\t\t\t*               Edit   Phone Number [3]                 *" << endl;
    cout << "\t\t\t\t*               Back                [0]                 *" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t=========================================================" << endl
         << endl;
    cout << "\t\t\t\t\tC H O O S E    Y O U R    O P T I O N : ";

    int key_user;
    cin >> key_user;
    system("cls");
    switch (key_user)
    {
    case 1:
        Edit_User_Name();
        break;
    case 2:
        Edit_User_Pass();
        break;
    case 3:
        Edit_User_PhoneNumber();
        break;
    case 0:
        break;
    default:
        cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n"
             << endl;
    }
    if (key_user != 0)
        Edit_User_Profile();
}

//=======================================================================================================================================

void Edit_User_Name()
{
    cout << "E N T E R    Y O U R    N E W    N A M E   : ";
    getline(cin, users[userloginno].user_name);
    getline(cin, users[userloginno].user_name);

    fstream user("user.txt", ios ::out);
    for (int i = 0; i < userno; i++)
    {
        user << users[i].user_id << "*" << users[i].user_name << "*" << users[i].user_pass << "*" << users[i].phone_no << "*" << endl;
    }

    cout << "Y O U R    N A M E    C H A N G E D    S U C C E S S F U L L Y" << endl;
}

//=======================================================================================================================================

void Edit_User_Pass()
{
    cout << "E N T E R    Y O U R    N E W    P A S S W O R D   : ";
    getline(cin, users[userloginno].user_pass);
    getline(cin, users[userloginno].user_pass);

    fstream user("user.txt", ios ::out);
    for (int i = 0; i < userno; i++)
    {
        user << users[i].user_id << "*" << users[i].user_name << "*" << users[i].user_pass << "*" << users[i].phone_no << "*" << endl;
    }

    cout << "Y O U R    P A S S W O R D    C H A N G E D    S U C C E S S F U L L Y" << endl;
}

//=======================================================================================================================================

void Edit_User_PhoneNumber()
{
    cout << "E N T E R    Y O U R    N E W    P H O N E    N U M B E R   : ";
    getline(cin, users[userloginno].phone_no);
    getline(cin, users[userloginno].phone_no);

    fstream user("user.txt", ios ::out);
    for (int i = 0; i < userno; i++)
    {
        user << users[i].user_id << "*" << users[i].user_name << "*" << users[i].user_pass << "*" << users[i].phone_no << "*" << endl;
    }

    cout << "Y O U R    P H O N E    N U M B E R    C H A N G E D    S U C C E S S F U L L Y" << endl;
}

//=======================================================================================================================================

void Extending_Deadline()
{
    string borrow_book;

    cout << "W H A T    B O O K    D O    Y O U    W A N T    B O R R O W W (BOOK ID)?  : ";
    getline(cin, borrow_book);
    getline(cin, borrow_book);
    int book_status = -2;
    for (int k = 0; k < b_bookno; k++)
    {
        if (borrow_book == borrowed_books[k].book_id)
        {
            if (borrowed_books[k].user_id == users[userloginno].user_id)
            {
                book_status = k;
            }
            else if (borrowed_books[k].status == "Reserve")
            {
                book_status = -1;
                break;
            }
        }
    }
    if (book_status == -1)
    {
        cout << "T H I S    B O O K    I S    A L R E A D Y    R E S E R V E D .";
        system("pause");
        User_Menu();
    }
    else if (book_status == -2)
    {
        cout << "T H E    B O O K    W I T H    I D    N O T    F O U N D\n";
        system("pause");
        User_Menu();
    }
    else
    {
        remove("b_book.txt");
        fstream b_book("b_book.txt", ios ::app | ios ::in);
        for (int i = 0; i < b_bookno; i++)
        {
            if (i == book_status)
            {
                borrowed_books[i].day = nowday;
                b_book << borrowed_books[i].book_id << "*" << borrowed_books[i].user_id << "*" << borrowed_books[i].day << "*" << borrowed_books[i].status << "*" << endl;
            }
            else
            {
                b_book << borrowed_books[i].book_id << "*" << borrowed_books[i].user_id << "*" << borrowed_books[i].day << "*" << borrowed_books[i].status << "*" << endl;
            }
        }
        b_book.close();
        cout << "T H E    B O R R O W    T I M E    S U C C E S S F U L L Y    U P D A T E    F O R    7    D A Y S\n";
        system("pause");
        User_Menu();
    }
}

//=======================================================================================================================================

void Borrow_Book()
{
    string borrow_book;

    cout << "W H A T    B O O K    D O    Y O U    W A N T    B O R R O W W (BOOK ID)?  : ";
    getline(cin, borrow_book);
    getline(cin, borrow_book);
    int book_status = 0;
    for (int k = 0; k < b_bookno; k++)
    {
        if (borrow_book == borrowed_books[k].book_id)
        {
            if (borrowed_books[k].status == "Borrow")
            {
                book_status = 1;
            }
            else if (borrowed_books[k].status == "Reserve")
            {
                book_status = 2;
                break;
            }
        }
    }
    if (book_status == 1)
    {
        cout << "T H I S    B O O K    I S    A L R E A D Y    B O R R O W E D .";
        cout << "D O    Y O U    W A N T    R E S E R V E    I T   ?   YES[1] NO[2]";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_Reserve_List(borrow_book);
            break;
        case 2:
            break;
        default:
            cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n"
                 << endl;
            Borrow_Book();
            break;
        }
    }
    else if (book_status == 2)
    {
        cout << "T H I S    B O O K    I S    A L R E A D Y    R E S E R V E D .";
    }
    else
    {
        for (int i = 0; i < bookno; i++)
        {
            if (borrow_book == books[i].book_id)
            {
                fstream b_book("b_book.txt", ios ::app | ios ::in);
                borrowed_books[b_bookno].book_id = borrow_book;
                borrowed_books[b_bookno].user_id = users[userloginno].user_id;
                borrowed_books[b_bookno].day = nowday;
                borrowed_books[b_bookno].status = "Borrow";
                b_book << borrowed_books[b_bookno].book_id << "*" << borrowed_books[b_bookno].user_id << "*" << borrowed_books[b_bookno].day << "*" << borrowed_books[b_bookno].status << "*" << endl;
                cout << "T H E    B O O K    S U C C E S S F U L L Y    B O R R O W E D    F O R    7    D A Y S\n";
                system("pause");
                b_bookno++;
                return;
            }
        }
        cout << "T H E    B O O K    W I T H    I D    N O T    F O U N D\n";
    }
}

//=======================================================================================================================================

void Add_Reserve_List(string borrow_book)
{
    fstream b_book("b_book.txt", ios ::app | ios ::in);
    borrowed_books[b_bookno].book_id = borrow_book;
    borrowed_books[b_bookno].user_id = users[userloginno].user_id;
    borrowed_books[b_bookno].day = nowday;
    borrowed_books[b_bookno].status = "Reserve";
    b_book << borrowed_books[b_bookno].book_id << "*" << borrowed_books[b_bookno].user_id << "*" << borrowed_books[b_bookno].day << "*" << borrowed_books[b_bookno].status << "*" << endl;
    cout << "T H E    B O O K    S U C C E S S F U L L Y    R E S E R V E D\n";
    b_bookno++;
    b_book.close();
}

//=======================================================================================================================================

void return_book()
{
    string borrow_book;

    cout << "W H A T    B O O K    D O    Y O U    W A N T    B O R R O W W (BOOK ID)?  : ";
    getline(cin, borrow_book);
    getline(cin, borrow_book);
    int book_status = -2;
    for (int k = 0; k < b_bookno; k++)
    {
        if (borrow_book == borrowed_books[k].book_id)
        {
            if (borrowed_books[k].user_id == users[userloginno].user_id)
            {
                book_status = k;
                break;
            }
        }
    }
    if (book_status == -2)
    {
        cout << "T H E    B O O K    W I T H    I D    N O T    F O U N D\n";
    }
    else
    {
        remove("b_book.txt");
        fstream b_book("b_book.txt", ios ::app | ios ::in);
        for (int i = 0; i < b_bookno; i++)
        {
            if (i != book_status)
            {
                if (borrowed_books[i].book_id == borrow_book)
                {
                    borrowed_books[i].status = "Borrow";
                    borrowed_books[i].day = nowday;
                }
                b_book << borrowed_books[i].book_id << "*" << borrowed_books[i].user_id << "*" << borrowed_books[i].day << "*" << borrowed_books[i].status << "*" << endl;
            }
        }
        cout << "T H E    B O R R O W E    T I M E    S U C C E S S F U L L Y    U P D A T E\n";
        b_book.close();
        RenderBorrowedBook();
    }
}

//=======================================================================================================================================

void Search_Book()
{
    system("cls");

    string enteri_bookname;
    cout << "E N T E R    B O O K    T I T L E   : ";
    getline(cin, enteri_bookname);
    getline(cin, enteri_bookname);

    for (int i = 0; i < bookno; i++)
    {
        if (books[i].book_title == enteri_bookname)
        {
            cout << "\n\n\n";
            cout << "===============================================================================\n";
            cout << "B O O K    I D   : " << books[i].book_id << endl
                 << endl;
            cout << "B O O K    T I T L E   : " << books[i].book_title << endl
                 << endl;
            cout << "A U T H O R    N A M E   : " << books[i].author_name << endl
                 << endl;
            cout << "F I N E    P E R    D A Y   : " << books[i].fine << endl
                 << endl;
            cout << "T H I S    B O O K    I S    N O T    B O R R O W E D    Y E T\n";
            cout << "===============================================================================\n\n";
            system("pause");
            return;
        }
    }
    cout << "Y O U R    E N T E R Y    B O O K    N A M E    I S    W R O N G!!\n";
    cout << "D O    Y O U    W A N T    T R Y    A G A I N    ? ? YES[1] NO[2]";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        Search_Book();
        break;
    case 2:
        break;
    default:
        cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n"
             << endl;
        break;
    }
}

//=======================================================================================================================================

void Add_Book()
{
    system("cls");

    string book_id2;
    string book_title;
    string author_name;
    int fine;

    cout << "E N T E R    B O O K    T I T L E   : ";

    getline(cin, book_title);
    getline(cin, book_title);

    cout << "E N T E R    A U T H O R    N A M E   : ";

    getline(cin, author_name);

    cout << "E N T E R    F I N E    P E R    D A I L Y    D E L A Y   : ";
    cin >> fine;

    book_id2 = Id_Generator();

    cout << "B O O K    I D   : " << book_id2 << endl;

    ofstream book_file2("book.txt", ios ::app | ios ::in);
    book_file2 << book_id2 << "*" << book_title << "*" << author_name << "*" << fine << "*" << endl;
    books[bookno].book_id = book_id2;
    books[bookno].book_title = book_title;
    books[bookno].author_name = author_name;
    books[bookno].fine = fine;
    bookno++;
}

//=======================================================================================================================================

string Id_Generator()
{

    string id = "";

    char temp;
    char chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        temp = chars[rand() % 62];

        id += temp;
    }
    for (int j = 0; j < bookno; j++)
    {
        while (id == books[j].book_id)
        {
            string Id_Generator();
        }
    }
    return id;
}

//=======================================================================================================================================

void Delete_Book()
{
    string book_id2;
    bool flag = false;
    cout << "E N T E R    B O O K    I D    F O R    D E L E T E    B O O K   : ";
    getline(cin, book_id2);
    getline(cin, book_id2);

    for (int i = 0; i < bookno; i++)
    {
        if (book_id2 == borrowed_books[i].book_id)
        {
            flag = true;
            cout << "T H E    B O O K    I S    A L R E A D Y    B O R R O W E D";
            sleep(3);
            Admin_Menu();
        }
        else if (book_id2 == books[i].book_id)
        {
            fstream book("book.txt", ios ::out);
            flag = true;

            for (int j = 0; j < bookno; j++)
            {
                if (i != j)
                {
                    book << books[j].book_id << "*" << books[j].book_title << "*" << books[j].author_name << "*" << books[j].fine << "*" << endl;
                }
            }
            cout << "T H E    B O O K    D E L E T E D    S U C C E S S F U L L Y";
            sleep(3);
            RenderBook();
        }
    }
    if (flag == false)
    {
        cout << "W R O N G    I D !!!\n";
        cout << "D O    Y O U    W A N T    T R Y    A G A I N    ? ? YES[1] NO[2]";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            Delete_Book();
            break;
        case 2:
            break;
        default:
            cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n"
                 << endl;
        }
    }
}

//=======================================================================================================================================

void Edit_Book()
{

    cout << "\t\t\t\t=========================================================" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t*                 E D I T    B O O K                    *" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t=========================================================" << endl;

    sleep(3);

    cout << "\t\t\t\t=========================================================" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t*               Edit     Title      [1]                 *" << endl;
    cout << "\t\t\t\t*               Edit     Author     [2]                 *" << endl;
    cout << "\t\t\t\t*               Edit     Fine       [3]                 *" << endl;
    cout << "\t\t\t\t*               Back                [0]                 *" << endl;
    cout << "\t\t\t\t*                                                       *" << endl;
    cout << "\t\t\t\t=========================================================" << endl
         << endl;
    cout << "\t\t\t\t\tC H O O S E    Y O U R    O P T I O N : ";

    int key_admin;
    cin >> key_admin;
    system("cls");
    switch (key_admin)
    {
    case 1:
        Edit_Title();
        break;
    case 2:
        Edit_Author();
        break;
    case 3:
        Edit_Fine();
        break;
    case 0:
        break;
    default:
        cout << "\t\t\t\t\t   W R O N G     N U M B E R   !!!\n"
             << endl;
    }
    if (key_admin != 0)
        Edit_Book();
}

//=======================================================================================================================================

void Edit_Title()
{
    string book_id;
    string new_title;
    cout << "E N T E R    B O O K I D   : ";
    getline(cin, book_id);
    getline(cin, book_id);

    cout << "E N T E R    N E W    T I T L E   : ";
    getline(cin, new_title);
    bool flag = false;
    for (int i = 0; i < bookno; i++)
    {
        fstream book("book.txt", ios ::out);
        if (books[i].book_title == book_id)
        {
            books[i].book_title = new_title;
            book << books[i].book_id << "*" << new_title << "*" << books[i].author_name << "*" << books[i].fine << "*" << endl;
            cout << "B O O K    T I T L E    C H A N G E D    S U C C E S S F U L L Y" << endl;
            flag = true;
        }
        else
        {
            book << books[i].book_id << "*" << books[i].book_title << "*" << books[i].author_name << "*" << books[i].fine << "*" << endl;
        }
    }
    if (!flag)
        cout << endl
             << "B O O K    N O T    F O U N D!!!";
}

//=======================================================================================================================================

void Edit_Author()
{
    string book_id;
    string author_name;
    cout << "E N T E R    B O O K I D   : ";
    getline(cin, book_id);
    getline(cin, book_id);

    cout << "E N T E R    A U T H O R    N A M E   : ";
    getline(cin, author_name);
    getline(cin, author_name);
    bool flag = false;
    for (int i = 0; i < bookno; i++)
    {
        fstream book("book.txt", ios ::out);
        if (books[i].book_id == book_id)
        {
            books[i].author_name = author_name;
            book << books[i].book_id << "*" << books[i].book_title << "*" << author_name << "*" << books[i].fine << "*" << endl;
            flag = true;
            cout << "A U T H O R    N A M E    C H A N G E D    S U C C E S S F U L L Y" << endl;
        }
        else
        {
            book << books[i].book_id << "*" << books[i].book_title << "*" << books[i].author_name << "*" << books[i].fine << "*" << endl;
        }
    }
    if (!flag)
        cout << endl
             << "B O O K    N O T    F O U N D!!!";
}

//=======================================================================================================================================

void Edit_Fine()
{
    string book_id;
    int fine;
    cout << "E N T E R    B O O K I D   : ";
    getline(cin, book_id);
    getline(cin, book_id);

    cout << "E N T E R    F I N E   : ";
    cin >> fine;
    bool flag = true;
    for (int i = 0; i < bookno; i++)
    {
        fstream book("book.txt", ios ::out);
        if (books[i].book_id == book_id)
        {
            books[i].fine = fine;
            book << books[i].book_id << "*" << books[i].book_title << "*" << books[i].author_name << "*" << books[i].fine << "*" << endl;
            flag = true;
            cout << "F I N E    C H A N G E D    S U C C E S S F U L L Y" << endl;
        }
        else
        {
            book << books[i].book_id << "*" << books[i].book_title << "*" << books[i].author_name << "*" << books[i].fine << "*" << endl;
        }
    }
    if (!flag)
        cout << endl
             << "B O O K    N O T    F O U N D!!!";
}

//=======================================================================================================================================

void RenderAdmin()
{
    string line;
    fstream adminfile;
    adminno = 0;
    adminfile.open("admin.txt", ios ::app | ios::in);

    if (adminfile.is_open())
    {
        while (getline(adminfile, line))
        {
            int a = 0;
            string s[3];
            string t = "";

            for (int i = 0; i <= line.length(); i++)
            {
                if (line[i] == '*')
                {
                    s[a] = t;
                    t = "";
                    a++;
                }
                else
                {
                    t += line[i];
                }
            }
            // convert character to string and
            string s0 = s[0].c_str();
            string s1 = s[1].c_str();
            string s2 = s[2].c_str();

            // put in struct
            admins[adminno].admin_id = s0;
            admins[adminno].admin_name = s1;
            admins[adminno].admin_pass = s2;

            adminno++;
        }
        adminfile.close();
    }
}

//=======================================================================================================================================

void RenderUser()
{
    string line;
    fstream userfile;
    userno = 0;
    userfile.open("user.txt", ios ::app | ios ::in);

    if (userfile.is_open())
    {

        while (getline(userfile, line))
        {
            int a = 0;
            string s[4];
            string t = "";

            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == '*')
                {
                    s[a] = t;
                    t = "";
                    a++;
                }
                else
                {
                    t += line[i];
                }
            }
            // convert character to string and
            string s0 = s[0].c_str();
            string s1 = s[1].c_str();
            string s2 = s[2].c_str();
            string s3 = s[3].c_str();

            // put in struct
            users[userno].user_id = s0;
            users[userno].user_name = s1;
            users[userno].user_pass = s2;
            users[userno].phone_no = s3;

            userno++;
        }
        userfile.close();
    }
}

//=======================================================================================================================================

void RenderBook()
{
    string line;
    fstream bookfile;
    bookno = 0;
    bookfile.open("book.txt", ios ::app | ios ::in);

    if (bookfile.is_open())
    {
        while (getline(bookfile, line))
        {
            int a = 0;
            string s[6];
            string t;
            for (int i = 0; i <= line.length(); i++)
            {
                if (line[i] == '*')
                {
                    s[a] = t;
                    t = "";
                    a++;
                }
                else
                {
                    t += line[i];
                }
            }
            // convert character to string and
            string s0 = s[0].c_str();
            string s1 = s[1].c_str();
            string s2 = s[2].c_str();
            string s3 = s[3].c_str();

            // put in struct
            books[bookno].book_id = s0;
            books[bookno].book_title = s1;
            books[bookno].author_name = s2;
            books[bookno].fine = atoi(s[3].c_str());

            bookno++;
        }

        bookfile.close();
    }
}

//=======================================================================================================================================

void RenderBorrowedBook()
{
    string line;
    fstream bookfile;
    b_bookno = 0;
    bookfile.open("b_book.txt", ios ::app | ios ::in);
    if (bookfile.is_open())
    {
        while (getline(bookfile, line))
        {
            int a = 0;
            string s[4];
            string t;
            for (int i = 0; i <= line.length(); i++)
            {
                if (line[i] == '*')
                {
                    s[a] = t;
                    t = "";
                    a++;
                }
                else
                {
                    t += line[i];
                }
            }

            // convert character to string and
            string s0 = s[0].c_str();
            string s1 = s[1].c_str();
            string s3 = s[3].c_str();

            // put in struct
            borrowed_books[b_bookno].book_id = s0;
            borrowed_books[b_bookno].user_id = s1;
            borrowed_books[b_bookno].day = atoi(s[2].c_str());
            borrowed_books[b_bookno].status = s3;

            b_bookno++;
        }

        bookfile.close();
    }
}

//=======================================================================================================================================
