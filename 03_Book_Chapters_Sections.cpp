/*
Name - Jay Yogesh Chavan 
Class - S.E.(A)
Roll No.- 18

A book consists of chapters, chapters consist of sections and sections consist of 
subsections. Construct a tree and print the nodes. Find the time and space requirements of your 
method. 


*/
#include<iostream> 
#include <iostream> 
#include <string.h> 
#include<cstring>
using namespace std; 
struct node // Node Declaration 
{ 
    string label; 
    //char label[10]; 
    int ch_count; 
    struct node *child[10]; 
} * root; 
class GT // Class Declaration 
{ 
public: 
    void create_tree(); 
    void display(node *r1); 
    GT() 
    { 
        root = NULL; 
    } 
}; 
void GT::create_tree() 
{ 
    int tbooks, tchapters, i, j, k; 
    root = new node; 
    cout << "Enter name of book : "; 
    cin.get(); 
    getline(cin, root->label); 
    cout << "Enter number of chapters in book : "; 
    cin >> tchapters; 
    root->ch_count = tchapters; 
    for (i = 0; i < tchapters; i++) 
    { 
        root->child[i] = new node; 
        cout << "Enter the name of Chapter " << i + 1 << " : "; 
        cin.get(); 
        getline(cin, root->child[i]->label); 
        cout << "Enter number of sections in Chapter : " << root->child[i]->label << " : "; 
        cin >> root->child[i]->ch_count; 
        for (j = 0; j < root->child[i]->ch_count; j++) 
        { 
            root->child[i]->child[j] = new node; 
            cout << "Enter Name of Section " << j + 1 << " : "; 
            cin.get(); 
            getline(cin, root->child[i]->child[j]->label); 
            //cout<<"Enter no. of subsections in "<<r1->child[i]->child[j]->label; 
            //cin>>r1->child[i]->ch_count; 
        } 
    } 
} 
void GT::display(node *r1) 
{ 
    int i, j, k, tchapters; 
    if (r1 != NULL) 
    { 
        cout << "\n-----Book Hierarchy---"; 
        cout << "\n Book title : " << r1->label; 
        tchapters = r1->ch_count; 
        for (i = 0; i < tchapters; i++) 
        { 
            cout << "\nChapter " << i + 1; 
            cout << " : " << r1->child[i]->label; 
            cout << "\nSections : "; 
            for (j = 0; j < r1->child[i]->ch_count; j++) 
            { 
                cout << "\n"<< r1->child[i]->child[j]->label; 
            } 
        } 
    } 
    cout << endl; 
} 
int main() 
{ 
    int choice; 
    GT gt; 
    while (1) 
    { 
        cout << "-----------------" << endl; 
        cout << "Book Tree Creation" << endl; 
        cout << "-----------------" << endl; 
        cout << "1.Create" << endl; 
        cout << "2.Display" << endl; 
        cout << "3.Quit" << endl; 
        cout << "Enter your choice : "; 
        cin >> choice; 
        switch (choice) 
        { 
        case 1: 
            gt.create_tree(); 
        case 2: 
            gt.display(root); 
            break; 
        case 3: 
             
          exit(1); 
        default: 
            cout << "Wrong choice!!!" << endl; 
        } 
    } 
    return 0; 
}

/*
Output- 
-----------------
Book Tree Creation
-----------------
1.Create
2.Display
3.Quit
Enter your choice : 1
Enter name of book : Maths
Enter number of chapters in book : 5
Enter the name of Chapter 1 : 1
Enter number of sections in Chapter : 1 : 0
Enter the name of Chapter 2 : 1
Enter number of sections in Chapter : 1 : 0
Enter the name of Chapter 3 : 1
Enter number of sections in Chapter : 1 : 0
Enter the name of Chapter 4 : 1
Enter number of sections in Chapter : 1 : 0
Enter the name of Chapter 5 : 1
Enter number of sections in Chapter : 1 : 0

-----Book Hierarchy---
 Book title : Maths
Chapter 1 : 1
Sections : 
Chapter 2 : 1
Sections : 
Chapter 3 : 1
Sections : 
Chapter 4 : 1
Sections : 
Chapter 5 : 1
Sections : 
-----------------
Book Tree Creation
-----------------
1.Create
2.Display
3.Quit
Enter your choice : 3


=== Code Exited With Errors ===*/