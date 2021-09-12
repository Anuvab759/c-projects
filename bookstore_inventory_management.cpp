#include<iostream>
#include<string>
#define MAX 20
using namespace std;

class Books
{
public:
    string bookname, author, publisher;
    int price;
    int quantity;

    void input_data();
    int search_item(string, string);
    void show_entries();
    //void modify_entry();
};

void Books::input_data()
{
    cout << "\t Please provide the Book title: " << endl;
    cin >> bookname;
    cout << "\t Please provide the author name: " << endl;
    cin >> author;
    cout << "\t Please provide the publisher name: " << endl;
    cin >> publisher;
    cout << "\t Please provide the price of the book: " << endl;
    cin >> price;
    cout << "\t Please provide the number of copies in stock: " << endl;
    cin >> quantity;
}

int Books::search_item(string _author, string title)
{
    if((author == _author) && (bookname == title))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Books::show_entries()
{
    cout << "\t Book title: " << bookname << endl;
    cout << "\t Author name: " << author << endl;
    cout << "\t Publisher: " << publisher << endl;
    cout << "\t Book price: " << price << endl;
    cout << "\t No. of copies: " << quantity << endl;
}


int main()
{
    Books *book[20];
    int choice;
    int i = 0;
    int j, ncopy;
    string title, author;
    int flag = 0;
    while(flag == 0)
    {
        cout <<"\t    MAIN MENU" << endl;
        cout <<"\t  (1)Entry of New Book" << endl;
        cout <<"\t  (2)Buy Book" << endl;
        cout <<"\t  (3)Search For Book" << endl;
        cout <<"\t  (Any other key)Exit" << endl;
        cout << endl;
        cout <<"\t     Enter your Choice: " << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            book[i] = new Books;
            book[i]->input_data();
            i++;
            break;

        case 2:
            if(book[0]->price == 0)
            {
                cout << "\t No books listed yet!" << endl;
                break;
            }
            else
            {
                cout << "\t Provide the book name " << endl;
                cin >> title;
                cout << "\t Provide the author name " << endl;
                cin >> author;
                cout << "\t Provide # of copies to buy" << endl;
                cin >> ncopy;
                for(j=0; j<i; j++)
                {
                    if(book[j] -> search_item(author,title))
                    {
                        cout << "\t Record found!" << endl;
                        if(book[j]->quantity < ncopy)
                        {
                            cout << "\t This much copy not in the stock!" << endl;
                            cout << endl;

                            break;
                        }
                        else
                        {
                            cout << "\t Purchase successful!" << endl;
                            cout << "\t Amount to pay: " << (book[j] -> price)*ncopy << endl;
                            cout << endl;
                            book[j]->quantity -= ncopy;
                            break;
                        }
                        cout << endl;
                        break;
                    }
                }

            }
            if(j==i) cout << "\tRecord not found!" << endl;
            break;

        case 3:
            if(book[0]->price == 0)
            {
                cout << "\t No books listed yet!" << endl;
                break;
            }
            else
            {
                cout << "\t Provide the book name " << endl;
                cin >> title;
                cout << "\t Provide the author name " << endl;
                cin >> author;
                for(j=0; j<i; j++)
                {
                    if(book[j] -> search_item(author,title))
                    {
                        cout << "\t Record found!" << endl;
                        book[j] -> show_entries();
                        cout << endl;
                        break;
                    }
                }

            }
            if(j==i) cout << "\tRecord not found!" << endl;
            break;


        default:
            printf("\t Exiting....\n");
            flag = 1;
            break;
        }
    }
}




