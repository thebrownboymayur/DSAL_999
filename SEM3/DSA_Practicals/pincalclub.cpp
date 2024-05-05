/* ASSIGNMENT...:Department of Computer Engineering has student's
club named 'Pinnacle Club'. Students of Second, third and final
year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is
reserved for president of club and last node is reserved for
secretary of club. Write C++ program to maintain club memberâ€˜s
information using singly linked list. Store student PRN and Name.
Write functions to
a) Add and delete the members as well as president or even
secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two
lists. */


#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    char prn[10];
    char name[20];
    node *next;
}*precident,*secratory,*new1,*curr;

void creat_list()
{
    int count,i;
    cout<<"\n Enter total no of members in pinacal list...:";
    cin>>count;
    
    for(i=0;i<(count-1);i++)
    {
        if(precident==NULL && secratory==NULL)
        {
            precident=new node;
            cout<<"\n Enter PRN no of precident....:";
            cin>>precident->prn;
            cout<<"\n Enter name of precident...:";
            cin>>precident->name;
            precident->next=NULL;
            curr=precident;
            secratory=new node;
            cout<<"\n Enter PRN no of secratory....:";
            cin>>secratory->prn;
            cout<<"\n Enter name of secratory...:";
            cin>>secratory->name;
            secratory->next=NULL;
        }
        else
        {
            new1=new node;
            cout<<"\n Enter PRN no of membor....:";
            cin>>new1->prn;
            cout<<"\n Enter name of membor...:";
            cin>>new1->name;
            curr->next=new1;
            new1->next=secratory;
            curr=new1;
        }
    }
}

void del_pr()
{
    curr=precident;
    precident=curr->next;
    delete curr;
}

void del_sec(node *curr)
{
    node *temp;
    while((curr->next)->next!=NULL)
    {
        curr=curr->next;
    }
    temp=curr->next;
    curr->next=NULL;
    delete temp;
}

void display()
{
    node *curr;
    curr=precident;
    while(curr!=NULL)
    {
        cout<<curr->prn<<"-"<<curr->name<<"->";
        curr=curr->next;
    }
}

void countnodes()
{
    int total;
    total = 0;
    node *curr;
    curr=precident;
    while(curr!=NULL)
    {
        total++;
        curr=curr->next;
    }
    cout<<"\nTotal no. of members in CLUB:"<<total;
}

void reverse(node *curr)
{
    if(curr->next==NULL)
    {
        cout<<curr->prn<<"-"<<curr->name<<"->";
    }
    else
    {
        reverse(curr->next);
        cout<<curr->prn<<"-"<<curr->name<<"->";
    }
}

void add_mem()
{
    new1=new node;
    cout<<"\n Enter PRN no of membor....:";
    cin>>new1->prn;
    cout<<"\n Enter name of membor...:";
    cin>>new1->name;
    new1->next = secratory;
    curr->next = new1;
    curr=new1;
}

int main()
{
    int ch;
    do
    {
        cout<<"\nMENU";
        cout<<"\n1)creat";
        cout<<"\n2)display";
        cout<<"\n3)add mem";
        cout<<"\n4)reverse";
        cout<<"\n5)delete secretory";
        cout<<"\n6)delete precident";
        cout<<"\n7)countnodes";
        cout<<"\n8)exit";
        cout<<"\n Enter your choice....:";
        cin>>ch;
        switch(ch)
        {
            case 1: creat_list();
                break;
            case 2: display();
                break;
            case 3:add_mem();
                break;
            case 4:reverse(precident);
                break;
            case 5: del_sec(precident);
                break;
            case 6: del_pr();
                break;
            case 7: countnodes();
                break;
            case 8: exit(0);
                break;
            default:cout<<"\n Invalid choice";
        }
    } while(ch!=8);
    return 0;
}
