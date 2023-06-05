#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;

int book_number=0;
int book_ID=0;

struct book
{
    string title,author,genre;
    int book_id;
    double popularity[2]={0,0};
    bool borrow=false;

}Book[1000];

string username="ali";
char password[]="doalef";
int manager_id=209;

int member_number=0;
int member_ID=0;

struct member
{
   string password,username,firstname,lastname;
   char phone_number[11];
   int borrow_count_limit=5,borrowed_books_counter=0,total_latency,member_id,borrowed_books_list[20];

}Member[1000];

int activ_member_id;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

char Security_[6];
string Security__;
bool Security_phrase;

void main_menu();
void member_menu();
void manager_menu();
void view_borrow_books();
void manage_books_menu();
void view_manage_book();
void add_new_book();
void member_singup();
void Member_login();
void Manager_login();
void manage_member_menu();
void sort_by_author();
void cheshmak();
bool Security__phrase();
void Security___phrase();
void Popularity(double a,double b);

int main()
{
    cout<<"Enter enter for start:))))))";
    char x;
    x=getch();
    system("cls");
    char welcom[]="***WELCOME TO THE LIBRARY***";
    for(int i=0;i<28;i++)
    {
        cout<<welcom[i];
                 system("color 04");
                 Sleep(5);
                 system("color 01");
                  Sleep(5);
                 system("color 02");
 Sleep(20);
    }
    system("color 02");
    SetConsoleTextAttribute(h,0x01);
   // cout<<"***WELCOM TO THE LIBRARY***";
    cout<<"\n---------------";
    cout<<"\n1. Main menu";
    SetConsoleTextAttribute(h,0x04);
    cout<<"\n2. Exit\n";
    SetConsoleTextAttribute(h,0x01);
    int a;
    cin>>a;
    if(a==1)
    {
       main_menu();
    }

        SetConsoleTextAttribute(h,0x02);
    cout<<"Thank you for your visit";
        SetConsoleTextAttribute(h,0x01);
    getch();
    Sleep(1000);

}
void member_singup()
{
    system ("cls");
    cout<<"***MEMBER SIGNUP***";
    cout<<"\n---------------";
    cout<<"\nFirst name : ";
    string temp;
    getline(cin,temp);
    getline(cin,Member[member_number].firstname);
    cout<<"\nLast name : ";
    getline(cin,Member[member_number].lastname);
    cout<<"\nUsername : ";
    getline(cin,Member[member_number].username);
    cout<<"\nPassword : ";
    getline(cin,Member[member_number].password);
    cout<<"\nPhone number : ";
    for(int i=0;i<11;i++)
    {
        Member[member_number].phone_number[i]=getche();
    }
        SetConsoleTextAttribute(h,0x02);
    cout<<"\n\nYour registration was successful";
        SetConsoleTextAttribute(h,0x01);
    Member[member_number].member_id=member_ID+101;
    member_ID++;
    cout<<"\n\nYour member_id is : "<<Member[member_number].member_id;
    Member[member_number].borrow_count_limit=5;
    for(int i=0;i<20;i++)
    {
        if(i<5)
         Member[member_number].borrowed_books_list[i]=-1;
        else
            Member[member_number].borrowed_books_list[i]=-2;
    }
    member_number++;
    cout<<"\n---------------";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n1. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int q;
    cin>>q;
    Member_login();
}

void edit_book()
{
    bool chek=false;
    do
    {
    system("cls");
    cout<<"***EDIT BOOK***";
    cout<<"\n---------------\n";
    cout<<"Enter book_id: ";
    int a;
    cin>>a;
     bool check_book=false;
    for(int i=0;i<book_number;i++)
    {
        if(Book[i].book_id==a)
        {
            check_book=true;
            a=i;
            break;
        }
    }
    if(check_book==false)
    {
        cheshmak();
        SetConsoleTextAttribute(h,0x04);
        cout<<"\n!!There are no book with this ID , please check and try again!!";
            SetConsoleTextAttribute(h,0x01);
        cout<<"\n---------------";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
              int s=0;
       while(s!=1)
        {
         cin>>s;
        }
        view_manage_book();
    }
    else
    {
    cout<<"\nCurrent title : "<<Book[a].title;
    cout<<"\nNew title : ";
    string temp;
    getline(cin,temp);
    getline(cin,Book[a].title);
    cout<<"\n\nCurrent author : "<<Book[a].author;
    cout<<"\nNew author : ";
    getline(cin,Book[a].author);
    cout<<"\n\nCurrent genre : "<<Book[a].genre;
    cout<<"\nNew genre : ";
    getline(cin,Book[a].genre);
    cout<<"---------------";
        SetConsoleTextAttribute(h,0x02);
    cout<<"\nChanges saved successfully.";
        SetConsoleTextAttribute(h,0x01);
    chek=true;
    }
    }while(chek==false);
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n1. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int y=11;
    while(y!=1)
    {
        cin>>y;
        if(y!=1)
         cout<<"\a";
    }
    view_manage_book();
}

void delete_book()
{
    system("cls");
    cout<<"***DELEDE BOOK***";
    cout<<"\n---------------";
    cout<<"\nEnter the book ID :";
    int a;
    cin>>a;
    bool check_book=false;
    for(int i=0;i<book_number;i++)
    {
        if(Book[i].book_id==a)
        {
            check_book=true;
            a=i;
            break;
        }
    }
    if(check_book==false)
    {
        cheshmak();
        SetConsoleTextAttribute(h,0x04);
        cout<<"\n!!There are no book with this ID , please check and try again!!";
            SetConsoleTextAttribute(h,0x01);
        cout<<"\n---------------";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
              int s=0;
       while(s!=1)
        {
         cin>>s;
        }
        view_manage_book();
    }
    else
    {
        cout<<"\nTitle:  \t"<<Book[a].title;
        cout<<"\n\nAuthor: \t"<<Book[a].author;
        cout<<"\n\nGenre:  \t"<<Book[a].genre;
        if(Book[a].borrow==true)
        {
            cout<<"\n---------------";
            cheshmak();
            SetConsoleTextAttribute(h,0x04);
            cout<<"\n!!One of the members borrowed this book!!";
            cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
            int s=0;
            while(s!=1)
            {
             cin>>s;
            }
             view_manage_book();
        }
    else
     {
            cout<<"\n\nYou want this book? (enter 'yes' or 'no') : ";
        string want;
        cin>>want;
        if(want=="yes")
        {
         for(int i=a;i<book_number;i++)
         {
           Book[i]=Book[i+1];
         }
       }
    else
     {
         cheshmak();
         cout<<"\n---------------";
        cout<<"\n1. Continuation";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n2. Back\n";
            SetConsoleTextAttribute(h,0x01);
        int b;
        cin>>b;
        if(b==2)
          view_manage_book();
     }
    }
   }
  cout<<"---------------";
      SetConsoleTextAttribute(h,0x02);
  cout<<"\nBook successfully deleted";
      SetConsoleTextAttribute(h,0x04);
book_number--;
  cout<<"\n1.Back\n";
      SetConsoleTextAttribute(h,0x01);
  int s=0;
  while(s!=1)
  {
      cin>>s;
  }
  view_manage_book();
}
void view_manage_book()
{
    system ("cls");
    cout<<"***BOOK MANAGEMENT***";
    cout<<"\n---------------";
    for(int i=0;i<book_number;i++)
    {
        cout<<endl<<i+1<<".\n   Title: \t"<<Book[i].title;
        cout<<"\n   Author: \t"<<Book[i].author;
        cout<<"\n   Genre: \t"<<Book[i].genre;
        cout<<"\n   Book_id:\t"<<Book[i].book_id;
        cout<<"\n   Popularity:\t";
        Popularity(Book[i].popularity[0],Book[i].popularity[1]);
        if(Book[i].borrow==false)
              {
                      SetConsoleTextAttribute(h,0x02);
                  cout<<"\n   Available to borrow";
                      SetConsoleTextAttribute(h,0x01);
              }

        else
            {
                    SetConsoleTextAttribute(h,0x04);
         cout<<"\n   Is barrowed";
            SetConsoleTextAttribute(h,0x01);
            }
        cout<<"\n---------------";
    }
    cout<<"\n1. Edit";
    cout<<"\n2. Delete";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n3. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int a;
    cin>>a;
    switch (a)
    {
    case 1:
        {
         edit_book();
         break;
        }
    case 2:
        {
            delete_book();
            break;
        }
    case 3:
        {
         manage_books_menu();
         break;
        }
    }
}

void add_new_book()
{
    system ("cls");
    cout<<"***ADD NEW BOOK***";
    cout<<"\n---------------";
    cout<<endl<<"\nEnter book's title : ";
    string temp;
    getline(cin,temp);
    getline(cin,Book[book_number].title);
    cout<<"\nEnter book's author : ";
    getline(cin,Book[book_number].author);
    cout<<"\nEnter book's genre : ";
    getline(cin,Book[book_number].genre);
    cout<<"---------------";
        SetConsoleTextAttribute(h,0x02);
    cout<<"\nBook saved successfully.";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n1. Back\n";
        SetConsoleTextAttribute(h,0x01);
    Book[book_number].book_id=book_ID+1001;
    book_number++;
    book_ID++;
    int a;
    do
    {
     cin>>a;
     if(a==1)
     break;
     else
     cout<<"\a\b";
    }while(a!=1);
    manage_books_menu();
}

void manage_books_menu()
{
    system ("cls");
    cout<<"***MANAGE BOOKS***";
    cout<<"\n---------------";
    int a;
    cout<<endl<<"1. Add new book";
    cout<<endl<<"2. View and manage books";
        SetConsoleTextAttribute(h,0x04);
    cout<<endl<<"3. Back\n";
        SetConsoleTextAttribute(h,0x01);
    cin>>a;
    switch (a)
    {
    case 1:
        {
         add_new_book();
         break;
        }
    case 2:
        {
         view_manage_book();
         break;
        }
    case 3:
        {
        manager_menu();
         break;
        }
    }
}

void manager_edit_member()
{
    system("cls");
    cout<<"***EDIT MEMBER***";
    cout<<"\n---------------";
    cout<<"\nEnter member_id : ";
    int a,i=0;
    cin>>a;
     bool check_member=false;
    for(int i=0;i<member_number;i++)
    {
        if(Member[i].member_id==a)
        {
            check_member=true;
            a=i;
            break;
        }
    }
    if(check_member==false)
    {
        cheshmak();
        SetConsoleTextAttribute(h,0x04);
        cout<<"\n!!There are no member with this ID , please check and try again!!";
            SetConsoleTextAttribute(h,0x01);
        cout<<"\n---------------";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
              int s=0;
       while(s!=1)
        {
         cin>>s;
        }
        manage_member_menu();
    }
 else
  {
        cout<<"\nFirst name : "<<Member[a].firstname;
        cout<<"\nLast name : "<<Member[a].lastname;
        cout<<"\nUsername : "<<Member[a].username;
        cout<<"\n\nCurrent borrow limit : "<<Member[a].borrow_count_limit;
        cout<<"\n\nEnter new borrow limit : ";
        int b;
        cin>>b;
        Member[i].borrow_count_limit=b;
    for(int k=0;k<20;k++)
    {
        if(i< Member[i].borrow_count_limit)
        Member[i].borrowed_books_list[k]=-1;
        else
            Member[i].borrowed_books_list[k]=-2;
    }
  }
    cout<<"---------------";
        SetConsoleTextAttribute(h,0x02);
    cout<<"\nChenge saved successfully";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n1. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int c=0;
    while(c!=1)
    {
        cin>>c;
    }
    manage_member_menu();
}

void manager_delete_member()
{
    system("cls");
    cout<<"***DELETE MEMBER***";
    cout<<"\n---------------";
    cout<<"\nEnter the member ID : ";
    int a;
    cin>>a;
    bool check_member=false;
    for(int i=0;i<member_number;i++)
    {
        if(Member[i].member_id==a)
        {
            check_member=true;
            a=i;
            break;
        }
    }
    if(check_member==false)
    {
        cheshmak();
        SetConsoleTextAttribute(h,0x04);
        cout<<"\n!!There are no member with this ID , please check and try again!!";
            SetConsoleTextAttribute(h,0x01);
        cout<<"\n---------------";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
              int s=0;
       while(s!=1)
        {
         cin>>s;
        }
        manage_member_menu();
    }
    else
    {
        cout<<"\nFirst name :\t"<<Member[a].firstname;
        cout<<"\n\nLast name : \t"<<Member[a].lastname;
        cout<<"\n\nUser name : \t"<<Member[a].username;
        cout<<"\n\nmember_id : \t"<<Member[a].member_id;
        cout<<"\n\nYou want this member? (enter 'yes' or 'no') : ";
        string want;
        cin>>want;
    if(want=="yes")
     {
         for(int i=0;i<Member[a].borrowed_books_counter;i++)
         {
             Book[Member[a].borrowed_books_list[i]].borrow=false;
         }
      for(int i=a;i<member_number;i++)
      {
          Member[i]=Member[i+1];
      }
      member_number--;
     }
     else
     {
         cheshmak();
        cout<<"\n1. Back\n";
          int s=0;
         while(s!=1)
           {
            cin>>s;
           }
          manage_member_menu();
     }
  cout<<"\n---------------";
      SetConsoleTextAttribute(h,0x02);
  cout<<"\nMember successfully deleted";
      SetConsoleTextAttribute(h,0x04);
  cout<<"\n1.Back\n";
      SetConsoleTextAttribute(h,0x01);
  int s=0;
  while(s!=1)
  {
      cin>>s;
  }
  manage_member_menu();
    }

}

void manage_member_menu()
{
    system("cls");
    cout<<"***VIEW AND MANAGER MEMBER***";
    cout<<"\n---------------";
    for(int i=0;i<member_number;i++)
    {
        cout<<endl<<i+1<<".";
        cout<<"\nFirst name :\t"<<Member[i].firstname;
        cout<<"\n\nLast name : \t"<<Member[i].lastname;
        cout<<"\n\nUser name : \t"<<Member[i].username;
        cout<<"\n\nPassword :  \t";
        cout<<Member[i].password;
        cout<<"\n\nPhone number :  ";
        for(int j=0;j<11;j++)
        {
            cout<<Member[i].phone_number[j];
        }
        cout<<"\n\nmember_id : \t"<<Member[i].member_id;
        cout<<"\n\nBorrow limit :  "<<Member[i].borrow_count_limit;
        cout<<"\n\nBorrow count :  "<<Member[i].borrowed_books_counter;
        cout<<"\n---------------";
    }
    cout<<"\n1. Chenge member's limits";
    cout<<"\n2. Delete";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n3. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int a;
    cin>>a;
    switch (a)
    {
    case 1:
        {
          manager_edit_member();
          break;
        }
    case 2:
        {
          manager_delete_member();
          break;
        }
    case 3:
        {
         manager_menu();
          break;
        }
    }
}

void manager_menu()
{
    system ("cls");
    cout<<"***MANAGER MENU***";
    cout<<"\n---------------";
    int a;
    cout<<endl<<"1. Manage books";
    cout<<endl<<"2. Manage members";
        SetConsoleTextAttribute(h,0x04);
    cout<<endl<<"3. Back\n";
        SetConsoleTextAttribute(h,0x01);
    cin>>a;
    switch (a)
    {
    case 1:
        {
         manage_books_menu();
         break;
        }
    case 2:
        {
         manage_member_menu();
        break;
        }
    case 3:
       {
        main_menu();
        break;
       }
    }
}

void borrow_book()
{
    system("cls");
    cout<<"***BORROOW BOOK***";
    cout<<"\n---------------";
    cout<<"\nEnter the ID of the book you want : ";
    int a;
    cin>>a;
 bool check_book=false;
    for(int i=0;i<book_number;i++)
    {
        if(Book[i].book_id==a)
        {
            check_book=true;
            a=i;
            break;
        }
    }
    if(check_book==false)
    {
        cheshmak();
        SetConsoleTextAttribute(h,0x04);
        cout<<"\n!!There are no book with this ID , please check and try again!!";
            SetConsoleTextAttribute(h,0x01);
        cout<<"\n---------------";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
              int s=0;
       while(s!=1)
        {
         cin>>s;
        }
        view_borrow_books();
    }
    else
    {
            if(Book[a].borrow==true)
    {
        cheshmak();
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n!!This book is not available!!";
            SetConsoleTextAttribute(h,0x01);
        cout<<"\n---------------";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
        int u=0;
        while(u!=1)
        {
          cin>>u;
        }
            view_borrow_books();
    }
    else
    {
        cout<<"\nTitle:     \t"<<Book[a].title;
        cout<<"\n\nAuthor:    \t"<<Book[a].author;
        cout<<"\n\nGenre:     \t"<<Book[a].genre;
        cout<<"\n\nPopularity:\t";
        Popularity(Book[a].popularity[0],Book[a].popularity[1]);
        cout<<"\n\nYou want this book? (enter 'yes' or 'no') : ";
        string want;
        cin>>want;
        if(want=="yes")
        {
            Member[activ_member_id].borrowed_books_list[Member[activ_member_id].borrowed_books_counter]=a;
            Member[activ_member_id].borrowed_books_counter++;
            Book[a].borrow=true;
            cout<<"---------------";
                SetConsoleTextAttribute(h,0x02);
            cout<<"\nBook borrowed seccessfully!";
                SetConsoleTextAttribute(h,0x01);
        }
        else
        {
            cheshmak();
        cout<<"---------------";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
        int u=0;
        while(u!=1)
         {
           cin>>u;
         }
            view_borrow_books();
        }
    }
    }
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n1. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int u=0;
    while(u!=1)
    {
        cin>>u;
    }
    view_borrow_books();
}

void Search()
{
    system("cls");
    cout<<"***Search***";
    cout<<"\n---------------";
    cout<<"\nEnter the word or phrase you want to search for : ";
    string search_,temp;
    getline(cin,temp);
    getline(cin,search_);
    int m=4294,k=1;
    for(int i=0;i<book_number;i++)
    {
       if(Book[i].title.find( search_ )<m||Book[i].author.find( search_ )<m||Book[i].genre.find( search_ )<m)
          {
            cout<<endl<<k<<".\n  Title:     \t"<<Book[i].title;
            cout<<"\n  Author:    \t"<<Book[i].author;
            cout<<"\n  Genre:     \t"<<Book[i].genre;
            cout<<"\n  Book ID:   \t"<<Book[i].book_id;
            cout<<"\n  Popularity:\t";
            Popularity(Book[i].popularity[0],Book[i].popularity[1]);
            if(Book[i].borrow==false)
              {
                      SetConsoleTextAttribute(h,0x02);
                  cout<<"\n  Available to borrow";
                      SetConsoleTextAttribute(h,0x01);
              }

        else
            {
                    SetConsoleTextAttribute(h,0x04);
         cout<<"\nIs barrowed";
            SetConsoleTextAttribute(h,0x01);
            }
      cout<<"\n---------------";
            k++;
          }
    }
    if(k==1)
    {
        cheshmak();
        cout<<"\n---------------";
            SetConsoleTextAttribute(h,0x04);
         cout<<"!!There are no books available for this search!!";
         SetConsoleTextAttribute(h,0x01);
         cout<<"\n---------------";
         SetConsoleTextAttribute(h,0x04);
            cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
              int s=0;
       while(s!=1)
        {
         cin>>s;
        }
        view_borrow_books();
    }
    cout<<"\n1. Barrow";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n2. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int a;
    while(a!=-100)
        {
          cin>>a;
          if(a==1||a==2)
            break;
        }
    switch (a)
    {
     case 1:
         {
            borrow_book();
            break;
         }
     case 2:
         {
            view_borrow_books();
            break;
         }
    }
}

void sort_by_title()
{
    system ("cls");
    cout<<"***BOOKS***";
    cout<<"\n---------------";
    string title[book_number];
    for(int i=0;i<book_number;i++)
    {
        title[i]=Book[i].title;
    }
    int n=sizeof(title)/sizeof(title[0]);
    sort(title,title+n);
    int t;
    for(int i=0;i<book_number;i++)
    {
        for(int j=0;j<book_number;j++)
        {
            if(title[i]==Book[j].title)
            {
                t=j;
                break;
            }
        }
        cout<<endl<<i+1<<".\n   Title: \t"<<Book[t].title;
      cout<<"\n   Author: \t"<<Book[t].author;
      cout<<"\n   Genre: \t"<<Book[t].genre;
      cout<<"\n   Book_id:\t"<<Book[t].book_id;
      cout<<"\n  Popularity:\t";
      Popularity(Book[i].popularity[0],Book[i].popularity[1]);
              if(Book[t].borrow==false)
              {
                      SetConsoleTextAttribute(h,0x02);
                  cout<<"\n  Available to borrow";
                      SetConsoleTextAttribute(h,0x01);
              }

        else
            {
                    SetConsoleTextAttribute(h,0x04);
         cout<<"\nIs barrowed";
            SetConsoleTextAttribute(h,0x01);
            }
      cout<<"\n---------------";
    }
    cout<<"\n\n *Sort by:\t11. Default\t12. Author";
    cout<<"\n2. Search";
    cout<<"\n3. Barrow";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n4. Back to member menu\n";
        SetConsoleTextAttribute(h,0x01);
    int a;
    cin>>a;
    switch (a)
    {
    case 11:
        {
           view_borrow_books();
           break;
        }
    case 12:
        {
            sort_by_author();
            break;
        }
    case 2:
        {
            Search();
            break;
        }
    case 3:
        {
            borrow_book();
            break;
        }
    case 4:
        {
            member_menu();
            break;
        }
    }
}

void sort_by_author()
{
    system ("cls");
    cout<<"***BOOKS***";
    cout<<"\n---------------";
    string author[book_number];
    for(int i=0;i<book_number;i++)
    {
        author[i]=Book[i].author;
    }
    int n=sizeof(author)/sizeof(author[0]);
    sort(author,author+n);
    int t;
    for(int i=0;i<book_number;i++)
    {
        for(int j=0;j<book_number;j++)
        {
            if(author[i]==Book[j].author)
            {
                t=j;
                break;
            }
        }
        cout<<endl<<i+1<<".\n   Title: \t"<<Book[t].title;
      cout<<"\n   Author: \t"<<Book[t].author;
      cout<<"\n   Genre: \t"<<Book[t].genre;
      cout<<"\n   Book_id:\t"<<Book[t].book_id;
      cout<<"\n  Popularity:\t";
      Popularity(Book[i].popularity[0],Book[i].popularity[1]);
              if(Book[t].borrow==false)
              {
                      SetConsoleTextAttribute(h,0x02);
                  cout<<"\n  Available to borrow";
                      SetConsoleTextAttribute(h,0x01);
              }
        else
            {
                    SetConsoleTextAttribute(h,0x04);
         cout<<"\nIs barrowed";
            SetConsoleTextAttribute(h,0x01);
            }
      cout<<"\n---------------";
    }
    cout<<"\n\n *Sort by:\t11. Default\t12. Title";
    cout<<"\n2. Search";
    cout<<"\n3. Barrow";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n4. Back to member menu\n";
        SetConsoleTextAttribute(h,0x01);
    int a;
    cin>>a;
    switch (a)
    {
    case 11:
        {
           view_borrow_books();
           break;
        }
    case 12:
        {
            sort_by_title();
            break;
        }
    case 2:
        {
            Search();
            break;
        }
    case 3:
        {
            borrow_book();
            break;
        }
    case 4:
        {
            member_menu();
            break;
        }
    }
}

void view_borrow_books()
{
    system ("cls");
    cout<<"***BOOKS***";
    cout<<"\n---------------";
     for(int i=0;i<book_number;i++)
    {
        cout<<endl<<i+1<<".\n  Title:  \t"<<Book[i].title;
        cout<<"\n  Author: \t"<<Book[i].author;
        cout<<"\n  Genre:  \t"<<Book[i].genre;
        cout<<"\n  Book ID:\t"<<Book[i].book_id;
        cout<<"\n  Popularity:\t";
        Popularity(Book[i].popularity[0],Book[i].popularity[1]);
        if(Book[i].borrow==false)
          {
                  SetConsoleTextAttribute(h,0x02);
            cout<<"\n  Available to borrow";
                SetConsoleTextAttribute(h,0x01);
          }
        else
            {
                    SetConsoleTextAttribute(h,0x04);
         cout<<"\n  Is barrowed";
            SetConsoleTextAttribute(h,0x01);
            }
        cout<<"\n---------------";
    }
    cout<<"\n\n  *Sort by:\t11. Title\t12. Author";
    cout<<"\n2. Search";
    cout<<"\n3. Barrow";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n4. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int a;
    cin>>a;
    switch (a)
    {
    case 11:
        {
           sort_by_title();
           break;
        }
    case 12:
        {
            sort_by_author();
            break;
        }
    case 2:
        {
            Search();
            break;
        }
    case 3:
        {
            borrow_book();
            break;
        }
    case 4:
        {
            member_menu();
            break;
        }
    }
}

void return_book()
{
    int number_book_return;
    system("cls");
    cout<<"***RETURN BOOK***";
    cout<<"\n---------------";
    cout<<"\nEnter book id : ";
    int a;
    cin>>a;
     bool check_book=false;
    for(int i=0;i<book_number;i++)
    {
        if(Book[i].book_id==a)
        {
            check_book=true;
            a=i;
            break;
        }
    }
    if(check_book==false)
    {
        cheshmak();
        SetConsoleTextAttribute(h,0x04);
        cout<<"\n!!There are no book with this ID , please check and try again!!";
            SetConsoleTextAttribute(h,0x01);
        cout<<"\n---------------";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
              int s=0;
       while(s!=1)
        {
         cin>>s;
        }
        member_menu();
    }
  else
   {
               bool chek=false;
    for(int i=0;i<Member[activ_member_id].borrowed_books_counter;i++)
    {
        if(Member[activ_member_id].borrowed_books_list[i]==a)
        {
            chek=true;
            number_book_return=i;
            break;
        }
    }
    if(chek==true)
    {
        cout<<"\nTitle:  \t"<<Book[a].title;
        cout<<"\n\nAuthor: \t"<<Book[a].author;
        cout<<"\n\nGenre:  \t"<<Book[a].genre;
        cout<<"\n\nDo you want return this book ? ('yes' or 'no') : ";
        string awnser;
        cin>>awnser;
        if(awnser=="yes")
        {
            cout<<"\nWe will be grateful if you rate this book(from 0 to 100) : ";
            double w;
            cin>>w;
            Book[a].popularity[0]+=w;
            Book[a].popularity[1]++;
          for(int i=number_book_return;i<=Member[activ_member_id].borrowed_books_counter;i++)
          {
            Member[activ_member_id].borrowed_books_list[i]=Member[activ_member_id].borrowed_books_list[i+1];
          }
        }
        else
        {
          SetConsoleTextAttribute(h,0x04);
          cout<<"\n1. Back\n";
          SetConsoleTextAttribute(h,0x01);
          int z=0;
          while(z!=1)
          {
            cin>>z;
          }
           member_menu();
        }
     }
   }
  cout<<"---------------";
      SetConsoleTextAttribute(h,0x02);
  cout<<"\nReturn book successfully.";
      SetConsoleTextAttribute(h,0x01);
  Member[activ_member_id].borrowed_books_counter--;
  Book[a].borrow=false;
      SetConsoleTextAttribute(h,0x04);
  cout<<"\n1. Back\n";
      SetConsoleTextAttribute(h,0x01);
  int z=0;
  while(z!=1)
  {
      cin>>z;
  }
  member_menu();
}

void view_borrowed_books()
{
    system("cls");
    cout<<"***BORROWED BOOKS***";
    cout<<"\n---------------";
    for(int i=0;i<Member[activ_member_id].borrowed_books_counter;i++)
    {
        cout<<endl<<i+1<<".\n   Title: \t"<<Book[Member[activ_member_id].borrowed_books_list[i]].title;
        cout<<"\n   Author: \t"<<Book[Member[activ_member_id].borrowed_books_list[i]].author;
        cout<<"\n   Genre: \t"<<Book[Member[activ_member_id].borrowed_books_list[i]].genre;
        cout<<"\n   Book_id:\t"<<Book[Member[activ_member_id].borrowed_books_list[i]].book_id;
        cout<<"\n---------------";
    }
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n1. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int a=0;
    while(a!=1)
    {
        cin>>a;
    }
    member_menu();
}
void temp_()
{
   cout<<"\n---------------";
   SetConsoleTextAttribute(h,0x02);
   cout<<"\nChenge saved successfully";
   SetConsoleTextAttribute(h,0x04);
   cout<<"\n1. Back\n";
   SetConsoleTextAttribute(h,0x01);
   int s=0;
   while(s!=1)
    {
     cin>>s;
    }
    member_menu();
}
void edit_profile()
{
    system("cls");
    cout<<"***EDIT PROFILE***";
    cout<<"\n---------------";
    cout<<"\n1. First name :\t"<<Member[activ_member_id].firstname;
    cout<<"\n\n2. Last name : \t"<<Member[activ_member_id].lastname;
    cout<<"\n\n3. User name : \t"<<Member[activ_member_id].username;
    cout<<"\n\n4. Password :  \t"<<Member[activ_member_id].password;
    cout<<"\n\n5. Phone number :  ";
    for(int j=0;j<11;j++)
    {
        cout<<Member[activ_member_id].phone_number[j];
    }
    SetConsoleTextAttribute(h,0x04);
    cout<<"\n\n6. Back";
    SetConsoleTextAttribute(h,0x01);
    cout<<"\n---------------";
    cout<<"\nWhich item do you want to change? ";
    int a;
    cin>>a;
  switch(a)
   {
    case 1:
    {
        cout<<"\n\nNew first name : ";
        string temp;
        getline(cin,temp);
        getline(cin,Member[activ_member_id].firstname);
        temp_();
        break;
    }
    case 2:
    {
        cout<<"\n\nNew last name : ";
        string temp;
        getline(cin,temp);
        getline(cin,Member[activ_member_id].lastname);
        temp_();
        break;
    }
    case 3:
    {
        cout<<"\n\nNew username : ";
        string temp;
        getline(cin,temp);
        getline(cin,Member[activ_member_id].username);
        temp_();
        break;
    }
    case 4:
    {
        cout<<"\n\nNew password : ";
        string temp;
        getline(cin,temp);
        getline(cin,Member[activ_member_id].password);
        temp_();
        break;
    }
    case 5:
    {
        cout<<"\n\nNew phone number : ";
        for(int j=0;j<11;j++)
        {
          Member[activ_member_id].phone_number[j]=getche();
        }
        temp_();
        break;
    }
    case 6:
    {
      member_menu();
      break;
    }
   }
}

void member_menu()
{
    system ("cls");
    cout<<"***MEMBER MENU***";
    cout<<"\n---------------";
    cout<<endl<<"1. View all books and search and borrow";
    cout<<endl<<"2. View borrowed books";
    cout<<endl<<"3. Return the book";
    cout<<endl<<"4. Edit profile";
        SetConsoleTextAttribute(h,0x04);
    cout<<endl<<"5. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int a;
    cin>>a;
    switch (a)
    {
    case 1:
        {
            view_borrow_books();
            break;
        }
    case 2:
        {
            view_borrowed_books();
            break;
        }
    case 3:
        {
           return_book();
           break;
        }
    case 4:
        {
           edit_profile();
           break;
        }
    case 5:
        {
           main_menu();
           break;
        }
    }
}

void Manager_login()
{
 int chek=0,i=0;
 do{
    system("cls");
   cout<<"***MANAGER SECTION***";
   cout<<"\n---------------\n";
   if(i>0)
    {
        cheshmak();
            SetConsoleTextAttribute(h,0x04);
     cout<<"!! The infromation is not correct , please chek and tyr again !!\n";
        SetConsoleTextAttribute(h,0x01);
        cout<<"---------------\n";
    }
      i++;
       cout<<"Eeter your manager_id : ";
       int a;
       cin>>a;
       cout<<"\nEnter your username : ";
       string man_user;
       cin>>man_user;
       cout<<"\nEnter your password : ";
       char man_pass[6];
       for(int j=0;j<6;j++)
       {
           man_pass[j]=getch();
               SetConsoleTextAttribute(h,0x04);
           cout<<"*";
       }
        Security___phrase();
       if(a==209&&man_user=="ali"&&man_pass[0]=='d'&&man_pass[1]=='o'&&man_pass[2]=='a'&&man_pass[3]=='l'&&man_pass[4]=='e'&&man_pass[5]=='f'&&Security__phrase()==true)
        {
          chek=1;
        }
 }while(chek==0);
   manager_menu();
}

void member__login()
{
     system("cls");
     cout<<"***MEMBER SECTION***";
       cout<<"\n---------------\n";
       cout<<"Eeter your member_id : ";
       int a;
       cin>>a;
       cout<<"\nEnter your username : ";
       string temp;
       getline(cin,temp);
       string mem_user;
       getline(cin,mem_user);
       cout<<"\nEnter your password : ";
       string mem_pass;
       getline(cin,mem_pass);
       Security___phrase();
       bool check_member=false;
    for(int i=0;i<member_number;i++)
    {
        if(Member[i].member_id==a)
        {
            check_member=true;
            a=i;
            break;
        }
    }
    if(check_member==false)
    {
        cheshmak();
        SetConsoleTextAttribute(h,0x04);
        cout<<"\n!!There are no member with this ID , please check and try again!!";
            SetConsoleTextAttribute(h,0x01);
        cout<<"\n---------------";
            SetConsoleTextAttribute(h,0x04);
        cout<<"\n1. Back\n";
            SetConsoleTextAttribute(h,0x01);
              int s=0;
       while(s!=1)
        {
         cin>>s;
        }
        main_menu();
    }
      else if(mem_user==Member[a].username&&Member[a].password==mem_pass&&Security__phrase()==true)
      {
          activ_member_id=a;
          member_menu();
      }
}

void Member_login()
{
    system ("cls");
    cout<<"***MEMBER SECTION***";
    cout<<"\n---------------\n";
    cout<<"1. Login";
    cout<<"\n2. Singup";
        SetConsoleTextAttribute(h,0x04);
    cout<<"\n3. Back\n";
        SetConsoleTextAttribute(h,0x01);
    int a;
    cin>>a;
    switch (a)
    {
    case 1:
        {
            member__login();
            break;
        }
    case 2:
        {
            member_singup();
            break;
        }
    case 3:
        {
          main_menu();
          break;
        }
    }
}

void main_menu()
{
    system ("cls");
    cout<<"***MAIN MENU***";
    cout<<"\n---------------";
    int a;
    cout<<"\nChose your user type";
    cout<<endl<<"1. Manager";
    cout<<endl<<"2. Member";
        SetConsoleTextAttribute(h,0x04);
    cout<<endl<<"3. Exit\n";
        SetConsoleTextAttribute(h,0x01);
    cin>>a;
    switch (a)
    {
    case 1:
        {
         Manager_login();
         break;
        }
    case 2:
       {
        Member_login();
        break;
       }
    case 3:
        return;
    }
}

void cheshmak()
{
    for(int i=0;i<5;i++)
    {
        if(i==2)cout<<"\a";
       system("color 41");
       for(int j=0;j<6;j++)
        system("color 01");
       system("color 14");
    }
    system("color 04");
    cout<<"\n\n\n\n\n\n\n\n\n                                                     ERROR! ";
        Sleep(3000);
        system("cls");
    system("color 01");
}

void Security___phrase()
{
    Security_phrase=false;
    srand(time(0));
    for (int i = 0; i < 5;i++)
    {
      Security_[i] = (rand() % 2 == 0) ? (rand() % 26 + 97) : (rand() % 10 + 48);
    }
    Security_[5] = 0;
    SetConsoleTextAttribute(h,0x01);
    cout<<"\n\nEnter the security phrase : ";
    SetConsoleTextAttribute(h,0x04);
    printf(Security_);
    SetConsoleTextAttribute(h,0x01);
    cout<<"   ";
    SetConsoleTextAttribute(h,0x04);
    cin>>Security__;
    SetConsoleTextAttribute(h,0x01);
}

bool Security__phrase()
{
    Security_phrase=false;
    if(Security_==Security__)
    Security_phrase=true;
    return Security_phrase;
}

void Popularity(double a,double b)
{
    if(b==0)
    {
        SetConsoleTextAttribute(h,0x04);
        cout<<"__";
        SetConsoleTextAttribute(h,0x01);
    }
    else
    {
        double c=a/b;
        if(c>=50)
        {
           SetConsoleTextAttribute(h,0x02);
           cout<<fixed<<setprecision(2)<<c<<" %";
           SetConsoleTextAttribute(h,0x01);
        }
        else
        {
           SetConsoleTextAttribute(h,0x04);
           cout<<fixed<<setprecision(2)<<c<<" %";
           SetConsoleTextAttribute(h,0x01);
        }
    }
}
