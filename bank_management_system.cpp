#include<iostream>
using namespace std;

class Bank
{
    char name[20],account_type[10];
    int init_bal;
public:
    void open_account();
    void deposit();
    void withdraw();
    void display();
};

void Bank::open_account()
{
    cout << "Provide account holder's name:" << endl;
    cin >> name;
    cout << "What type of account would it be (Savings or Current)?" << endl;
    cin >> account_type;
    cout << "Provide the opening balance:" << endl;
    cin >> init_bal;
}

void Bank::deposit()
{
    int amount;
    cout << "Provide the amount to deposit." << endl;
    cin >> amount;
    init_bal += amount;
}

void Bank::withdraw()
{
    int amount;
    cout << "Enter amount to withdraw: " << endl;
    cin >> amount;
    if(amount > init_bal)
    {
        cout << "Invalid amount!" << endl;
    }
    else
    {
        init_bal -= amount;
        cout << "Withdrawl successful!" << endl;
        cout << "Your present balance is: " << init_bal << endl;
    }
}


void Bank::display()
{
    cout << "Name of the account holder: " << name;
    cout << "Account type: " << account_type << endl;
    cout << "Current balance: " << init_bal << endl;

}


int main()
{
    Bank *b;
    int choice;
    int flag = 0;
    while(flag == 0)
    {
        cout << "\t Opening a new account " << endl;
        cout << "\t (1) Open account." << endl;
        cout << "\t (2) Deposit money." << endl;
        cout << "\t (3) Withdraw money." << endl;
        cout << "\t (4) Display account details." << endl;
        cout << "\t Press your choice.." << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            b -> open_account();
            break;
        case 2:
            b -> deposit();
            break;
        case 3:
            b -> withdraw();
            break;
        case 4:
            b -> display();
            break;
        default:
            printf("\t Exiting....\n");
            flag = 1;
            break;
        }
    };

}
