#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<mysql/mysql.h>
#include<string.h>

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

int qty,cont,qstate;
char choice;


char f[1024],another='y';

static char *host="localhost";
static char *dbname="project";
static char *user="root";
static char *pass="mom&dad12";

unsigned int port=3306;

static char *unix_socket=NULL;
unsigned int flag = 0;

using namespace std;

void login();
//void book();
void conne();

class teach
{
       
       
       public:
       char tid[3],sid[3],bnm[50],bid[30],tpn[30],tage[10];
       char tnm[50],snm[50];
       char x[2];
       int ch;
      
                       void tdisplay()
                     {
                         system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                                   cout<<"1.Enter Record:\n";
                                   cout<<"2.Edit Record:\n";
                                   cout<<"3.Delete Record:\n";
                                   cout<<"4.Show Record:\n";
                                   cout<<"5.Issue Book:\n";
                                   cout<<"6.Return Book:\n";
                                   cout<<"\nEnter Your Choice:";
                                   cin>>ch;
                                   cout<<"\n\n\n";
                                   switch (ch)
                                   {
                                    
                                   case 1:
                                   
                                               tgetdata();
                                       break;
                                   case 2:
                                               update();
                                       break;
                                    case 3:
                                               del();
                                       break; 
                                    case 4:
                                               showdata();
                                       break;
                                    case 5:
                                              issue();
                                        break;
                                    case 6:
                                               retur();
                                        break;

                                   default:cout<<"\nWrong Choice Entered:\n\n";
                                       break;
                                   }

                     }
                     
                  
                    void tgetdata()
                    {
                        system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                         //system("clear");
                         cout<<"\t\t\t\t\t\t\t##########Teacher's Portal##########\n\n";
                        cout<<"\nEnter Your Name:\n";
                        cin>>tnm;
                        cout<<"\nEnter Your ID:\n";
                        cin>>tid;
                        cout<<"\nEnter Teacher's Age:\n";
                        cin>>tage;
                        cout<<"\nEnter Teacher Phone Number:\n";
                        cin>>tpn;
                        sprintf(f,"INSERT INTO teacher (teacher_name,teacher_id,teacher_pn,teacher_age) VALUES('%s','%s','%s','%s')",tnm,tid,tpn,tage);

                        if(mysql_query(conn,f)==0)
                        {
                            cout<<"\nValue Inserted:\n";
                        }
                        else
                        {
                            cout<<"\nValue Not Inserted:\n";
                        }                    
                    }

                    void update()
                    {
                        system("clear");
                        cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                        cout<<"\t\t\t\t\t\t\t##########Teacher's Portal##########\n\n";
                        cout<<"\t\t\t\t\t\t\t-----Welcome in the UPDATE SECTION-----\n\n";
                        cout<<"\nSelect the Suitable Option:\n\n";
                        cout<<"1.Want to Update USER Name:\n";
                        cout<<"2.Want To Update USER ID:\n";
                        cin>>ch;
                        switch(ch)
                        {
                            case 1:
                                         cout<<"Enter User Name and Their User ID:";
                                         cin>>tnm>>tid;
                                         sprintf(f,"UPDATE teacher SET teacher_name='%s' WHERE teacher_id='%s'",tnm,tid);
                                         if(mysql_query(conn,f)==0)
                                         {
                                             cout<<"Updated:\n\n";
                                         }
                                         else
                                         {
                                             cout<<"Updated:";
                                         }
                                         break;
                            case 2:
                                         cout<<"Enter User ID and Their User Name:";
                                         cin>>tid>>tnm;
                                         sprintf(f,"UPDATE teacher SET teacher_id='%s' WHERE teacher_name='%s'",tid,tnm);
                                         if(mysql_query(conn,f)==0)
                                         {
                                             cout<<"Updated:\n\n";
                                         }
                                         else
                                         {
                                             cout<<"Not Updated:";
                                         }
                                         break;
                            default:cout<<"Wrong Choice Entered:";
                        }                        
                    }
                    void del()
                    {
                        system("clear");
                        cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                        cout<<"\t\t\t\t\t\t\t##########Teacher's Portal##########\n\n";
                        cout<<"\t\t\t\t\t\t\t------Welcome In The DELETE SECTION------";
                        cout<<"\nEnter the Teacher ID for Deletion:\n";
                        cin>>tid;

                        sprintf(f,"DELETE FROM teacher WHERE teacher_id='%s'",tid);
                        if(mysql_query(conn,f)==0)
                        {
                            cout<<"\nRecord Successfully Deleted:\n\n";
                        } 
                        else
                        {
                            cout<<"\nRecord Not Deleted:\n\n";
                        }
                        
                    }
                    void showdata()
                    {
                        system("clear");
                        cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                        cout<<"\t\t\t\t\t\t\t##########Teacher's Portal##########\n\n";
                        cout<<"\t\t\t\t\t\t\t-------Welcome To The Display Section:-------";
                        cout<<"\nEnter Teacher's ID For Display Record:";
                        cin>>tid;
                        sprintf(f,"SELECT *FROM teacher WHERE teacher_id='%s'",tid);
                        if(mysql_query(conn,f)==0);
                        {
                        res = mysql_store_result(conn);

                        while(row = mysql_fetch_row(res))
                         {
                                   printf("Teacher Name:%s\t\nTeacher Id%s\t\nTeacher Phone Number:%s\t\nTeacher Age:%s\t\n",row[0],row[1],row[2],row[3]);
                         }
                        }                                                               
                    }
                   void issue()
                    {
                        system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                         cout<<"\t\t\t\t\t\t\t##########Teacher's Portal##########\n\n";
                         cout<<"\nEnter the Book ID to Issue:";
                         cin>>bid;
                         /*sprintf(f,"SELECT *FROM book WHERE book_id='%s'",bid);
                         if(mysql_query(conn,f)==0)
                         {*/
                                  cout<<"\nBook is Available:\n";
                                  cout<<"\nPress Y to Issue:\n";
                                  fflush(stdin);
                                  cin>>choice;
                                  
                                  switch(choice)
                                  {
                                          case 'y': 
                                                 
                                                        cout<<"\nBook Issued:\n";       
                                                   /*sprintf(f,"UPDATE book SET book_qty='%s' WHERE book_id='%s'",qty,bid);
                                                   if(mysql_query(conn,f)==0)
                                                   {
                                                       cout<<"Successfully book issued:\n\n";
                                                   }*/
                                                   
                                          break;
                                          default:cout<<"Wrong Choice:\n";         
                            }                            
                        

                         
                       /* if(mysql_query(conn,f)==0);
                        {
                        res = mysql_store_result(conn);

                        while(row = mysql_fetch_row(res))
                         {
                                   printf("book Name:%s\n",row[0]);
                         }
                        }  */                      
                        
                    }

                    void retur()
                    {
                        system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                         cout<<"\t\t\t\t\t\t\t##########Teacher's Portal##########\n\n";
                         cout<<"\nEnter the Book ID to Return:";
                         cin>>bid;
                          cout<<"\nBook Returned:\n";    
                         /*sprintf(f,"SELECT *FROM book WHERE book_id='%s'",bid);
                         if(mysql_query(conn,f)==0)
                         {
                                  cout<<"\nBook is Available:\n";
                                  cout<<"\nPress Y to Issue:\n";
                                  fflush(stdin);
                                  cin>>choice;
                                  
                                  switch(choice)
                                  {
                                          case 'y': */
                                                 
                                                          
                                                   /*sprintf(f,"UPDATE book SET book_qty='%s' WHERE book_id='%s'",qty,bid);
                                                   if(mysql_query(conn,f)==0)
                                                   {
                                                       cout<<"Successfully book issued:\n\n";
                                                   }*/
                                          //default:cout<<"Wrong Choice:\n";                                  
                        }

                         
                       /* if(mysql_query(conn,f)==0);
                        {
                        res = mysql_store_result(conn);

                        while(row = mysql_fetch_row(res))
                         {
                                   printf("book Name:%s\n",row[0]);
                         }
                        }  */                      

};

class stud
{
       
       public:
       char tid[3],sid[3];
       char tnm[50],snm[50],sage[30],spn[20],bnm[50],bid[30];
                    int ch;
                    void sdisplay()
                     {
                         system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                         cout<<"\t\t\t\t\t\t\t##########Student's Portal##########\n\n";
                                   cout<<"1.Enter Record:\n";
                                   cout<<"2.Edit Record:\n";
                                   cout<<"3.Delete Record:\n";
                                   cout<<"4.Show Record:\n";
                                   cout<<"5.Issue Book:\n";
                                   cout<<"6.Return Book:\n";
                                   cout<<"\nEnter Your Choice:\n";
                                   cin>>ch;
                                   switch (ch)
                                   {
                                   case 1:
                                               sgetdata();
                                       break;
                                   case 2:
                                               update();
                                       break;
                                    case 3:
                                               del();
                                       break; 
                                    case 4:
                                               showdata();
                                       break;
                                    case 5:
                                               issue();
                                        break;
                                    case 6:
                                               retur();
                                        break;
                                   default:cout<<"\nWrong Choice Entered:\n\n";
                                       break;
                                   }

                     }                    
                    void sgetdata()
                    {
                        system("clear");
                        cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                        cout<<"\t\t\t\t\t\t\t##########Student's Portal##########\n\n";
                        cout<<"\nEnter Your Name:\n";
                        cin>>snm;
                        cout<<"Enter Your ID:\n";
                        cin>>sid;
                        cout<<"Enter Student's Age:\n";
                        cin>>sage;
                        cout<<"Enter Student Phone Number:\n";
                        cin>>spn;
                        sprintf(f,"INSERT INTO student (student_name,student_id,student_pn,student_age) VALUES('%s','%s','%s','%s')",snm,sid,spn,sage);

                        if(mysql_query(conn,f)==0)
                        {
                            cout<<"\nValue Inserted:\n";
                        }
                        else
                        {
                            cout<<"\nValue Not Inserted:\n";
                        }                    
                    }                
                    void update()
                    {
                        system("clear");
                        cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                        cout<<"\t\t\t\t\t\t\t##########Student's Portal##########\n\n";
                        cout<<"\t\t\t\t\t\t\t-----Welcome in the UPDATE SECTION-----\n\n";
                        cout<<"\nSelect Update Option:\n";
                        cout<<"1.Update Name:\n";
                        cout<<"2.Update ID:\n";
                        cin>>ch;
                        switch(ch)
                        {
                            case 1:
                                         cout<<"Enter User Name and Their User ID:";
                                         cin>>snm>>sid;
                                         sprintf(f,"UPDATE student SET student_name='%s' WHERE student_id='%s'",snm,sid);
                                         if(mysql_query(conn,f)==0)
                                         {
                                             cout<<"Updated:\n\n";
                                         }
                                         else
                                         {
                                             cout<<"Not Updated:";
                                         }
                                         break;
                            case 2:
                                         cout<<"Enter User ID and Their User Name:";
                                         cin>>sid>>snm;
                                         sprintf(f,"UPDATE student SET student_id='%s' WHERE student_name='%s'",sid,snm);
                                         if(mysql_query(conn,f)==0)
                                         {
                                             cout<<"Updated:\n";
                                         }
                                         else
                                         {
                                             cout<<"Not Updated:";
                                         }
                                         break;
                                         
                            default:cout<<"\nSelect The Correct Option:\n\n";
                                         
                        }                        
                    }
                    void del()
                    {
                        system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                          cout<<"\t\t\t\t\t\t\t##########Student's Portal##########\n\n";
                        cout<<"\t\t\t\t\t\t\t------Welcome In The DELETE SECTION------";
                        cout<<"\nEnter the User ID to Be Deleted:";
                        cin>>sid;

                        sprintf(f,"DELETE FROM student WHERE student_id='%s'",sid);
                        if(mysql_query(conn,f)==0)
                        {
                            cout<<"\nRecord Successfully Deleted:\n\n";
                        }
                        else
                        {
                            cout<<"\nRecord Not Deleted:\n\n";
                        }
                        
                    }
                    void showdata()
                    {
                        system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                          cout<<"\t\t\t\t\t\t\t##########Student's Portal##########\n\n";
                        cout<<"\t\t\t\t\t-\t\t---------Welcome To The Display Section:----------\n";
                        cout<<"\nEnter the ID To Be Displayed:\n\n";
                        cin>>sid;
                        sprintf(f,"SELECT *FROM student WHERE student_id='%s'",sid);
                        mysql_query(conn,f);
                        res = mysql_store_result(conn);

                        while(row = mysql_fetch_row(res))
                         {
                                   printf("Student's Name:%s\t\nStudent's ID:%s\t\nStudent Phone Number:%s\t\nStudnet's Age:%s\t\n",row[0],row[1],row[2],row[3]);
                         } 
                    }
                    void issue()
                    {
                        system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                         cout<<"\t\t\t\t\t\t\t##########Student's Portal##########\n\n";
                         cout<<"\nEnter the Book ID to Issue:";
                         cin>>bid;
                         sprintf(f,"SELECT *FROM book WHERE book_id='%s'",bid);
                         if(mysql_query(conn,f)==0)
                         {
                                  cout<<"\nBook is Available:\n";
                                  cout<<"\nPress Y to Issue:\n";
                                  fflush(stdin);
                                  cin>>choice;
                                  
                                  switch(choice)
                                  {
                                          case 'y': 
                                                 
                                                        cout<<"\nBook Issued:\n";       
                                                   /*sprintf(f,"UPDATE book SET book_qty='%s' WHERE book_id='%s'",qty,bid);
                                                   if(mysql_query(conn,f)==0)
                                                   {
                                                       cout<<"Successfully book issued:\n\n";
                                                   }*/
                                                   
                                          break;
                                          default:cout<<"Wrong Choice:\n";         
                            }                            
                        }

                         
                       /* if(mysql_query(conn,f)==0);
                        {
                        res = mysql_store_result(conn);

                        while(row = mysql_fetch_row(res))
                         {
                                   printf("book Name:%s\n",row[0]);
                         }
                        }  */                      
                        
                    }

/*void issue()
                    {
                        system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                         cout<<"\t\t\t\t\t\t##########Teacher's Portal##########\n\n";
                        cout<<"\nEnter the Book ID to Issue:";
                        cin>>bid;
                        sprintf(f,"SELECT *FROM book WHERE book_id='%s'",bid);
                        if(mysql_query(conn,f)==0)
                        {
                            cout<<"Book is Available:\n";
                            cout<<"\nPress Y to Issue:\n";
                            fflush(stdin);
                            cin>>choice;
                            switch(choice)
                            {
                                case 'y':
                                         sprintf(f,"UPDATE book SET book_qty='%s' WHERE book_id='%s'",qty--,bid);
                                         if(mysql_query(conn,f)==0)
                                         {
                                             cout<<"Successfully book issued:\n\n";
                                         }
                                         
                                break;
                                default:cout<<"Wrong Choice:\n";         
                            }                            
                        }
                        else
                        {
                            cout<<"\nError Book Not Found:";
                        }
                        
                    }*/

void retur()
                    {
                        system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                         cout<<"\t\t\t\t\t\t\t##########Student's Portal##########\n\n";
                         cout<<"\nEnter the Book ID to Return:";
                         cin>>bid;
                          cout<<"\nBook Returned:\n";   
                         /*sprintf(f,"SELECT *FROM book WHERE book_id='%s'",bid);
                         if(mysql_query(conn,f)==0)
                         {
                                  cout<<"\nBook is Available:\n";
                                  cout<<"\nPress Y to Issue:\n";
                                  fflush(stdin);
                                  cin>>choice;
                                  
                                  switch(choice)
                                  {
                                          case 'y': */
                                                 
                                                           
                                                   /*sprintf(f,"UPDATE book SET book_qty='%s' WHERE book_id='%s'",qty,bid);
                                                   if(mysql_query(conn,f)==0)
                                                   {
                                                       cout<<"Successfully book issued:\n\n";
                                                   }*/
                                          //default:cout<<"Wrong Choice:\n";                                     
                        }

                         
                       /* if(mysql_query(conn,f)==0);
                        {
                        res = mysql_store_result(conn);

                        while(row = mysql_fetch_row(res))
                         {
                                   printf("book Name:%s\n",row[0]);
                         }
                        }  */                      

};
class book
{
    
    public:
    char bnm[30],bid[30],bisbn[20],bpb[20],bed[20],bqty[40];
    int ch;
               void bdisplay()
               {
                    system("clear");
                    cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n"; 
                    cout<<"\t\t\t\t\t\t\t##########Book's Portal##########\n\n";             
                    cout<<"1.Show Book's Record:\n";
                    cout<<"2.Edit Book's Record:\n";
                    cout<<"3.Delete Book's Record:\n";
                    cout<<"4.Enter Book:\n";
                    cout<<"Choose Any of The Option:\n\n";
                    cin>>ch;
                    switch(ch)
               {
                   case 1:
                               showbook();
                            break;
                   case 2: 
                               updatebook();
                            break;
                   case 3:
                               delbook();
                            break;
                    case 4:
                              bgetdata();
                            break;
                   default:cout<<"Entered Wrong Choice:";
               }
               }

               void bgetdata()
                    {
                        system("clear");
                        cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                        cout<<"\t\t\t\t\t\t\t##########Book's Portal##########\n\n"; 
                        cout<<"\nEnter Book Name:\n";
                        cin>>bnm;
                        cout<<"\nEnter Book ID:\n";
                        cin>>bid;
                        cout<<"\nEnter Book ISBN Number:\n";
                        cin>>bisbn;
                        cout<<"\nEnter Book Publisher:\n";
                        cin>>bpb;
                        cout<<"\nEnter Book Edition:\n";
                        cin>>bed;
                        //cout<<"\nEnter Book Quantity:\n";
                        //cin>>bqty;
                        sprintf(f,"INSERT INTO book (book_name,book_publication,book_ed,book_isbn,book_id) VALUES('%s','%s','%s','%s','%s')",bnm,bpb,bed,bisbn,bid);

                        if(mysql_query(conn,f)==0)
                        {
                            cout<<"\nValue Inserted:\n";
                        }
                        else
                        {
                            cout<<"\nValue Not Inserted:\n";
                        }                     
                    }
                    
                    void updatebook()
                    {
                        system("clear");
                         cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                         cout<<"\t\t\t\t\t\t\t##########Book's Portal##########\n\n"; 
                        cout<<"\t\t\t\t\t\t\t-----Welcome in the UPDATE SECTION-----";
                        cout<<"\nSelect Update Option:\n\n";
                        cout<<"1.Update Name:\n";
                        cout<<"2.Update ID:\n";
                        cin>>ch;
                        switch(ch)
                        {
                            case 1:
                                         cout<<"Enter The Name To be Updated With it's Id:";
                                         cin>>bnm>>bid;
                                         sprintf(f,"UPDATE book SET book_name='%s' WHERE book_id='%s'",bnm,bid);
                                         if(mysql_query(conn,f)==0)
                                         {
                                             cout<<"Successfully Updated:\n\n";
                                         }
                                         else
                                         {
                                             cout<<"Value Not Updated:";
                                         }
                                         break;
                            case 2:
                                         cout<<"Enter Book ID and Their Book Name:";
                                         cin>>bid>>bnm;
                                         sprintf(f,"UPDATE book SET book_id=%s WHERE book_name=%s",bid,bnm);
                                         if(mysql_query(conn,f)==0)
                                         {
                                             cout<<"Updated:\n\n";
                                         }
                                         else
                                         {
                                             cout<<"Not Updated:";
                                         }
                            default:cout<<"Wrong Choice Entered:";
                                         
                        }

                        
                    }
                    void delbook()
                    {
                        system("clear");
                        cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                        cout<<"\t\t\t\t\t\t\t##########Book's Portal##########\n\n"; 
                        cout<<"\nEnter the Book ID to Be Deleted:";
                        cin>>bid;

                        sprintf(f,"DELETE FROM book WHERE book_id='%s'",bid);
                        if(mysql_query(conn,f)==0)
                        {
                            cout<<"\nRecord Successfully Deleted:\n\n";
                        }
                        else
                        {
                            cout<<"\nRecord Not Deleted:\n\n";
                        }
                        
                    }
                    void showbook()
                    {
                        system("clear");
                        cout<<"\t\t\t\t\t----------------------LIBRARY MANAGEMENT SYSTEM--------------------\n\n";
                        cout<<"\t\t\t\t\t\t\t##########Book's Portal##########\n\n"; 
                        cout<<"Welcome To The Display Section:";
                        cout<<"\nEnter the Name To Be Displayed:";
                        cin>>bnm;
                        cout<<"\n\n";
                        sprintf(f,"SELECT *FROM book WHERE book_name='%s'",bnm);
                        mysql_query(conn,f);
                        res = mysql_store_result(conn);

                        while(row = mysql_fetch_row(res))
                         {
                                   printf("Book Name:\t%s\n\nBook Publisher:\t%s\n\nBook Edition:\t%s\n\nBook ISBN Number:\t%s\n\nBook ID:\t%s\n\n",row[0],row[1],row[2],row[3],row[4]);
                         }
 
                    }           
      
};


class show: public teach,public stud,public book
{
      public: 
      int ch;
                    teach obj2;
                    stud obj3;
                    book obj4;
                         int showdata()
                         {
                             system("clear");
                         cout<<"\t\t\t\t\t----------Welcome To The LIBRARY MANAGEMENT SYSTEM----------\n\n\n";
                         
                         cout<<"\t\t\t\t\t\t\t1.Teacher's Portal:\n";
                         cout<<"\t\t\t\t\t\t\t2.Student's Portal:\n";
                         cout<<"\t\t\t\t\t\t\t3.Book's Portal:\n";
                         cout<<"\n\t\t\t\t\t\t\tEnter Your Choice:";
                         cin>>ch;
                         cout<<"\n\n\n";
                         switch(ch)
                         {
                             case 1:
                                           obj2.tdisplay();
                                           break;
                             case 2:                       
                                           obj3.sdisplay();
                                           break;
                             case 3:
                                           obj4.bdisplay();
                                          break;
                             default:cout<<"\nYour Choice is Wrong:\n";
                         }
                         cout<<"\nGo To Mainmenu() Press 1 or 0 to EXIT:";
                         cin>>cont;
                         if(cont==1)
                         return cont;
                         else
                         {
                             system("clear");
                             exit(1);
                         }
                         
                         }
                         
                    
                   
};
void conne()
{
             
             conn = mysql_init(NULL);

             if(!(mysql_real_connect(conn,host,user,pass,dbname,port,unix_socket,flag)))
             {
                 fprintf(stderr,"\nError: %s [%d]\n",mysql_error(conn),mysql_errno(conn));
                 exit(1);
             }
             cout<<"Connected Successfully\n\n\n";
             
}

int main()
{
    conne();
    system("clear");
    int c=1;
    show obj1;
    while(c==1)
    {
        system("clear");
           c=obj1.showdata();
    }
}
