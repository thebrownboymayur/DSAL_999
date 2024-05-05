#include<iostream>
using namespace std;

class cinemax
{
public:
    int booked;
    cinemax *next, *prev;
    cinemax()
    {
        next = prev = NULL;
        booked = 0;
    }
}*head[10], *curr, *last;

void build_cinemax()
{
    int i, j;
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 7; j++)
        {
            curr = new cinemax();
            if (head[i] == NULL)
            {
                head[i] = curr;
                last = curr;
            }
            else
            {
                last->next = curr;
                last = curr;
                last->next = head[i];
            }
        }
    }
}

void display()
{
    int i, j;
    for (i = 1; i <= 10; i++)
    {
        curr = head[i];
        cout << "Row " << i << "---->";
        for (j = 1; j <= 7; j++)
        {
            cout << curr->booked << "->";
            curr = curr->next;
        }
        cout << endl;
    }
}

void booking()
{
    int row, col, count;
    count = 1;
    cout << "\n There are 10 rows and 7 cols are present";
    cout << "\n Enter row no...:";
    cin >> row;
    cout << "\n Enter col no...:";
    cin >> col;
    curr = head[row];
    while (curr->next != NULL && count <= 7)
    {
        if (count == col)
        {
            if (curr->booked != 1)
            {
                curr->booked = 1;
                cout << "\n Seat is booked \n" << curr->booked;
                display();
                break;
            }
            else
            {
                cout << "\n Seat is not available";
            }
        }
        else
        {
            curr = curr->next;
        }
        count++;
    }
}

void cancel()
{
    int row, col, count;
    count = 1;
    cout << "\n Enter row no...:";
    cin >> row;
    cout << "\n Enter col no...:";
    cin >> col;
    curr = head[row];
    while (curr->next != NULL && count <= 7)
    {
        if (count == col)
        {
            if (curr->booked == 1)
            {
                curr->booked = 0;
                cout << "Seat is cancel" << curr->booked << endl;
                cout << "Current Seat Status:" << endl;
                display();
            }
            else
            {
                cout << "\n Seat is not cancel as it is not booked";
            }
        }
        else
        {
            curr = curr->next;
        }
        count++;
    }
}

int main()
{
    int i, ch;
    char mt;
    build_cinemax();

    do
    {
        cout << "\n*****Welcome to Cinemax Booking System*****\n";
        cout << "\n1)Booking";
        cout << "\n2)Booking Cancel";
        cout << "\n3)Display";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            booking();
            break;
        case 2:
            cancel();
            break;
        case 3:
            display();
            break;
        }
    } while (ch < 4);

    return 0;
}
