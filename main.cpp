#include <iostream>
#include <string.h>
using namespace std;

int bookno;

int userno;

int adminno;

struct {
    string name;
    string price;
    string publisher;
    string subject;
    string versin_no;
    string edit_no;
    string release_date;
    string date_last_edit;
    string authors;
    string borrowable;
    string id_last_user;
    string price_punishment;
    string date_last_borrow;
    string return_date;
} books[100];
   bookno=0;

struct {
    string admin_id;
    string admin_pass;
} admins[100];
   adminno=0

struct {
    string user_id;
    string user_pass;
    string first_last_name;
    string birthday_date;
    string adress;
    string phone_no;
    string another_info;
    string date_membership;
    string date_all_membership;
    string type_membership;
    string limit_debt_no;
    string limit_debt_date;
    string bookdebt_intime;
    string all_date;
    string allbook_user_have;
} user[100];
    userno=0;

