#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Node
{
public:
    int count = 0;
    string name;
    int balance;
    char account_type;
    Node *next;
};

Node *head;

void open_account()
{
    Node *curr, *iter;
    char choice;
    curr = new Node();
    cout << "\t Enter the entries..." << endl;
    cout << "\t Provide the name of the account holder" << endl;
    cin >> curr -> name;
    cout << "\t Provide the account balance" << endl;
    cin >> curr -> balance ;
    cout << "\t Which type of account?" << endl;
    cin >> curr -> account_type;
    curr -> next = NULL;
    head = curr;
    iter = head;

    cout << "\t Include further accounts (y/N)?" << endl;
    cin >> choice;
    if(choice  == 'y')
    {
        while(choice != 'n')
        {
            curr = new Node();
            cout << "\t Enter the entries..." << endl;
            cout << "\t Provide the name of the account holder" << endl;
            cin >> curr -> name;
            cout << "\t Provide the account balance" << endl;
            cin >> curr -> balance ;
            cout << "\t Which type of account?" << endl;
            cin >> curr -> account_type;
            curr -> next = NULL;
            iter -> next = curr;
            iter = curr;
            cout << "\t Add one more entry (y/N)?" << endl;
            cin >> choice;
        }

    }
}

void Display_account_details()
{
    Node *iter;
    if(!head)
    {
        cout << "No account yet! Try later..." << endl;
    }
    else
    {
        string name;
        cout << "\t Please provide the account holder name." << endl;
        cin >> name;
        iter = head;
        while(iter)
        {
            if(iter -> name == name)
            {
                cout << "\t ==================== " << endl;
                cout << "\tName of the holder: " << iter -> name << endl;
                cout << "\tType of the account: " << iter -> account_type << endl;
                cout << "\tAccount balance: " << iter -> balance << endl;
                cout << "\t ==================== " << endl;
                cout << endl;
                return;
            }
            iter = iter -> next;
        }
        cout << "\t This entry does not exist in our database!" << endl;
    }
}

void add_new_account()
{
    Node *iter, *temp;
    if(!head)
    {
        cout << "No account yet! Try later..." << endl;
    }
    else
    {
        iter = head;
        while(iter -> next != NULL)
        {
            iter = iter -> next;
        }
        temp = new Node();
        cout << "\t Provide account holder name " << endl;
        cin >> temp -> name;
        cout << "\t Provide the account balance " << endl;
        cin >> temp -> balance;
        cout << "\t Provide the account type " << endl;
        cin >> temp -> account_type;
        temp -> next = NULL;
        iter -> next = temp;
    }

}


void Deposit()
{
    Node *iter;
    if(!head)
    {
        cout << "No account yet! Try later..." << endl;
    }
    else
    {
        string name;
        cout << "\t Please provide the account holder name." << endl;
        cin >> name;
        iter = head;
        while(iter)
        {
            if(iter -> name == name)
            {
                int amount;
                (iter -> count)++;
                cout << "\t Please provide the amount to deposit." << endl;
                cin >> amount;
                iter -> balance += amount;
                cout << endl;
                cout << "\t ==================== " << endl;
                cout << "\t Deposit successful!" << endl;
                cout << "\t Present account balance: " << iter -> balance << endl;
                cout << "\t ==================== " << endl;
                cout << endl;
                return;
            }
            iter = iter -> next;
        }
        cout << endl;
        cout << "\t ==================== " << endl;
        cout << "\t This entry does not exist in our database!" << endl;
        cout << "\t ==================== " << endl;
        cout << endl;
    }
}


void Withdraw()
{
    Node *iter;
    if(!head)
    {
        cout << "No account yet! Try later..." << endl;
    }
    else
    {
        string name;
        cout << "\t Please provide the account holder name." << endl;
        cin >> name;
        iter = head;
        while(iter)
        {
            if(iter -> name == name)
            {
                int amount;
                cout << "\t Please provide the amount to withdraw." << endl;
                cin >> amount;
                if(amount > (iter -> balance))
                {
                    cout << "\t Withdrawal failed! Insufficient balance." << endl;
                    cout << endl;
                }
                else if((iter -> count) > 2 && amount < 0.9*(iter -> balance))
                {
                    iter -> balance -= amount;
                    cout << endl;
                    cout << "\t ==================== " << endl;
                    cout << "\t Withdrawal successful!" << endl;
                    cout << "\t Present account balance: " << iter -> balance << endl;
                    cout << "\t ==================== " << endl;
                    cout << endl;
                    return;
                }
                else
                {
                    cout << "\t ==================== " << endl;
                    cout << "\t Insurance not paid! " << endl;
                    cout << "\t Deposit Unsuccessful. " << endl;
                    cout << "\t ==================== " << endl;

                }
            }
            iter = iter -> next;
        }
        cout << "\t This entry does not exist in our database!" << endl;
    }
}



int main()
{
    int choice;
    int flag = 0;
    while(flag == 0)
    {
        cout << "\t ---- Enter your option ----- " << endl;
        cout << "\t (1) Open account." << endl;
        cout << "\t (2) Deposit money." << endl;
        cout << "\t (3) Withdraw money." << endl;
        cout << "\t (4) Display account details." << endl;
        cout << "\t (5) Add new account." << endl;
        cout << "\t Press your choice.." << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            open_account();
            break;
        case 2:
            Deposit();
            break;
        case 3:
            Withdraw();
            break;
        case 4:
            Display_account_details();
            break;
        case 5:
            add_new_account();
            break;
        default:
            printf("\t Exiting....\n");
            flag = 1;
            break;
        }
    };

}
