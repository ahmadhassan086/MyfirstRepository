#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include<conio.h>
#include<fstream>
//#include "Dictionary.h"
#include <iostream>
using namespace std;

struct book{
    char name[30];
    char author[30];
    char id[30];
    struct book *next;
};

struct student{
	char stu_id[30];
    char name[30];
    char email[20];
    char book_id[20];
    struct student *next;
};

struct book *start_lib=NULL;
struct book *tail=NULL;
struct student *start=NULL;
struct book insert_book(char *B_author,char *B_name,char *B_id);
//struct student *student_insert(char *S_id,char *S_name,char *S_email,char *S_ID);
void S_write_data();
//struct S_read_data();
struct student *book_issue(struct student *);
struct student *book_return(struct student *);
struct book *diplay_lib(struct book *);
struct book delete_book(char a);
struct book *add_book(char [],char [],char*b);
void display(struct student *);
void write_data(char B_author,char *B_name, char *B_id); 
void read_data();
void write_stud();  
void greetings();
void main_menu();

int main(){
   // start_lib=insert_book();
    greetings();
    main_menu();
    return 0;
}

void greetings(){
    cout<<"\n\n";
    cout<<"\t\t\t     **************\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *     ----------------------------     *\n";
    cout<<"\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n";
    cout<<"\t\t\t     *     ----------------------------     *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     **************\n";
    cout<<"\n\n";
    cout<<"\t\t\t     **************\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *       ------------------------       *\n";
    cout<<"\t\t\t     *           STUDENT LIBRARY            *\n";
    cout<<"\t\t\t     *       ------------------------       *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *     Name: Madiha Amjad\n";
    cout<<"\t\t\t     *     Email: Madiha Amjad1234@gmail.com      *\n";
    cout<<"\t\t\t     *      \n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     **************\n";
    cout<<"\n\n\t\t\t             Press any key to continue: ";
    getch();
}

void main_menu(){
    int choice;
      char author[128], book[256],id[256];

    do{
        cout<<"\n\n";
        cout<<"\n\t\t\t*****************\n";
        cout<<"\n\t\t\t\t      MAIN MENU: ";
         cout<<"\n\t\t\t\t    1.ADD BOOK ";
        cout<<"\n\t\t\t\t     2.ISSUE OF BOOKS ";
        cout<<"\n\t\t\t\t     3.RETURN OF BOOKS ";
        cout<<"\n\t\t\t\t     4.DISPLAY STUDENT DETAILS ";
        cout<<"\n\t\t\t\t     5.SUPERIOR DICTIONARY";
        cout<<"\n\t\t\t\t     6.BACK TO MAIN\n ";
        cout<<"\n\t\t\t*****************\n";
        cout<<"\n\t\t\t\t      Enter your choice: ";
        cin>>choice;
        switch(choice){
        	case 1:{
        		cin.ignore();
        		  cout<<"ENTER BOOK ID :";
                  fgets(id,256,stdin);
        		 cout<<"ENTER AUTHOR NAME:";
                fgets(author,128,stdin);
                cout<<endl;
                cin.ignore();
                cout<<"ENTER BOOK NAME:"; 
                fgets(book,256,stdin);
                cout<<endl;
                cin.ignore();

                   insert_book(author,book,id);
                  write_data(author,book,id);
				break;
			}
            case 2:{
read_data();
                 start=book_issue(start);
               
//                  read_data();
                 
                break;
            }
            case 3:{
                start=book_return(start);
                break;
            }
            case 4:{
                display(start);
                break;
            }
            case 5:{
                //Superior_dictionary();
                break;
            }
                case 6:{
                exit(1);
            }
            default:{
                cout<<"\n\t\t\t\t      ...Invalid Option!...\n";
                cout<<"\n\t\t\t\t      Press any key to try again: ";
                getch();
            }
        }
    }while(choice!=4);
}

struct book *insert_book(char *B_id,char *B_author,char *B_name){
	  
  struct book *ptr= new book();
  strcpy(ptr->id,B_id);
strcpy(ptr->author,B_author);
strcpy(ptr->name,B_name);
ptr->next=NULL;
   
}
void write_data(char B_author,char *B_name,char B_id){
	ofstream my_bookfile;
	my_bookfile.open("BOOK.txt",ios::app);
	my_bookfile<<"BOOK ID:"<<B_id;
	my_bookfile<<endl;
	my_bookfile<<"AUTHOR:"<<B_author;
	my_bookfile<<endl;
	my_bookfile<<"BOOK NAME:"<<B_name;
	my_bookfile<<"------------------------";
	my_bookfile<<endl;
	my_bookfile.close();
}
void read_data(){
	int i_d,id;
	string name,author;
	ifstream infile;
	infile.open("BOOK.txt",ios::in);
	cout<<"ENTER BOOK ID WHICH U WANT TO ISSUE:";
	cin>>i_d;
	if(!infile.is_open()){
		cout<<"FILE IS NOT OPENED...."<<endl;
	}
	else{
		while(!infile.eof()){
			infile>>id;
			if(id==i_d){
			cout<<"BOOK HAS FOUND..."<<endl;
			cout<<"\n";
			infile>>author;
			infile>>name;
			cout<<"BOOK NAEM"<<":"<<name<<endl;
			cout<<"BOOK ID :"<<id<<endl;
			cout<<"AUTHOR NAME :"<<author<<endl;	
			
			}
		
		}
		
	}+0
}

struct student *book_issue(struct student *start){

          
		    S_write_data();
            
            cout<<"\n\t Issue of Book ID %d done successfully!\n";th
            cout<<"\n\n\t*****************\n";
           
}

//struct student *student_insert(char *S_id,char *S_name,char *S_email,char *B_ID){
//struct student *temp=new student();
//temp->id=S_id;
//temp->name=S_name;
//temp->email=S_email;
//temp->book_id=B_ID;
//temp->next=NULL;
//}
void S_write_data(){
	
	       char bk_id [100], name[100], email[256],student_id[100];
	        struct student *temp=new student();
            cout<<"\n\t Enter Student Details:\n ";
            cout<<"\n\t Enter Student id: ";
            cin>>student_id;
            cout<<"\n\t Enter Student Name: ";
            cin>>name;
            cout<<"\n\t Enter Student Email: ";
            cin>>email;
            cout<<"\n\t Enter Book id: ";
            cin>>bk_id;
            
            strcpy(temp->stu_id, student_id);
            strcpy(temp->name, name);
            strcpy(temp->email, email);
            strcpy(temp->book_id, bk_id);
             temp->next=NULL;
	

//	File Handling starts from here
	ofstream my_studfile;			
	my_studfile.open("STUDENT.txt",ios::app);
	my_studfile<<"STUDENT ID:"<<student_id<<endl;
	my_studfile<<"STUDENT NAME:"<<name<<endl;
	my_studfile<<"STUDENT EMAIL:"<<email<<endl;
	my_studfile<<"BOOK ID:"<<bk_id<<endl;
	my_studfile<<"------------------------";
	my_studfile<<endl;
//	my_studfile<<
}

struct student *book_return(struct student *start){
    struct student *ptr,*preptr;
    char bookname[30],authorname[30],idname[30];
    int flag=0,c=0,d=1;
    char identity[30];
    char id[30];
    cout<<"\n\n\t****** Books Submission: *******\n";
    cout<<"\n\n\t Enter your Book ID: ";
    cin>>identity;
    ptr=start;
    while(ptr!=NULL){
        if(ptr->book_id==identity){
            flag=1;
            break;
        }
        ptr=ptr->next;
    }		
    if(flag==1){
        ptr=start;
        while(ptr!=NULL){
            c++;
            ptr=ptr->next;
        }
        ptr=start;
        while(ptr->stu_id!=identity){
                   d++;
            ptr=ptr->next;
        }
        ptr=start;
        if( d==1 ){
            cout<<"\n\t_________________\n";
            cout<<"\n\t Student Name:"<<start->name;
            cout<<"\n\t Student Email:"<<start->email;
            cout<<"\n\t Name of Book Issued:"<<start->book_id;
            cout<<"\n\t_________________\n";
            cout<<"\n\n\t Return of Book ID  done successfully!\n"<<identity;
            cout<<"\n\n\t*****************\n";
            strcpy(bookname,start_lib->name);
	        strcpy(authorname,start_lib->author);
	        strcpy(idname,start_lib->id);
//            id=start->id;
            start=start->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }else{
            ptr=start;
            while(ptr->stu_id!=identity){
                preptr=ptr;
                ptr=ptr->next;
            }
            cout<<"\n\t_________________\n";
            cout<<"\n\t Student Name: %s"<<ptr->name;
            cout<<"\n\t Student Email: %s"<<ptr->email;
            cout<<"\n\t ID of Book Issued:"<<ptr->book_id;
            cout<<"\n\t STUDENT ID:"<<ptr->stu_id;
            cout<<"\n\t_________________\n";
            strcpy(bookname,start_lib->name);
            strcpy(authorname,start_lib->author);
            strcpy(idname,start_lib->id);
//            id=ptr->id;
            preptr->next=ptr->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }
        cout<<"\n\t Thank you! \n\t Do visit again! ";
        cout<<"\n\n\t Press any key to go to the main menu: ";
        getch();
        system("cls");
    }else{
        cout<<"\n\tSorry the book doesn't exist! Please recheck the entered ID";
        cout<<"\n\t\t\t\t      Press any key to try again: ";
        getch();
        system("cls");
    }
    return start;
}

void display(struct student *start){
    struct student *ptr;
    ptr=start;
    while(ptr!=NULL){
        cout<<"\n\t***** Details of Students: ******\n";
        cout<<"\n\t_________________\n";
        cout<<"\n\t\t Student Name:"<<ptr->name;
        cout<<"\n\t\t Student Email:"<<ptr->email;
        cout<<"\n\t\t ID of Book Issued:"<<ptr->book_id;
        cout<<"\n\t\t STUDENT ID:"<<ptr->stu_id;
        cout<<"\n\t_________________\n";
        cout<<"\n\n\t*****************\n";
        ptr=ptr->next;
    }
    cout<<"\n\n\t Press any key to go to the main menu: ";
    getch();
    system("cls");
}

struct book *delete_book(char *id){
    struct book *ptr,*preptr;
    int c=0;
    ptr=start_lib;
    while(ptr!=NULL){
        c++;
        ptr=ptr->next;
    }
    if(c==1){
        ptr=start_lib;
        start_lib=NULL;
        free(ptr);
    }else if(start_lib->id==id){
        ptr=start_lib;
        start_lib=start_lib->next;
        free(ptr);
    }else{
        ptr=start_lib;
        while(ptr->id!=id){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return start_lib;
}

struct book *add_book(char bookname[30],char authorname[30],char id[30]){
    struct book *ptr,*new_book;
    new_book=(struct book *)malloc(sizeof(struct book));
    strcpy(new_book->name,bookname);
    strcpy(new_book->author,authorname);
    strcpy(new_book->id,id);
    new_book->next=NULL;
    if(start_lib==NULL){
        start_lib=new_book;
    }else{
        ptr=start_lib;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new_book;
    }
    return start_lib;
}
