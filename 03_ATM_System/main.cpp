#include <iostream>
using namespace std;

enum EnATMOptions { CheckBalance = 1, DepositOp = 2, WithdrawOp = 3, ExitOp = 4 };

bool Login()
{
    const int CorrectPIN = 1234;
    int EnteredPIN;
    int Attempts = 0;

    cout << "Please Enter PIN Code: ";
    cin >> EnteredPIN;

    while (EnteredPIN != CorrectPIN && Attempts < 2)
    {
        Attempts++;
        system("cls");
        cout << "Wrong PIN! (" << (3 - Attempts) << " attempts left)\n";
        cout << "Please Enter PIN Code: ";
        cin >> EnteredPIN;
    }

    return (EnteredPIN == CorrectPIN);
}

void PerformDeposit(int& Balance)
{
    int Amount;
    do
    {
        cout << "\nEnter Deposit Amount (Positive Only): ";
        cin >> Amount;
    } while (Amount <= 0);

    Balance += Amount;
    cout << "\nSuccessful Deposit.\nNew Balance is: " << Balance << endl;
}

void PerformWithdraw(int& Balance)
{
    int Amount;
    cout << "\nEnter Withdraw Amount: ";
    cin >> Amount;

    while (Amount > Balance || Amount <= 0)
    {
        if (Amount <= 0)
            cout << "Invalid Amount. Enter positive number: ";
        else
            cout << "Insufficient Balance! Your Balance is " << Balance << ". Try again: ";

        cin >> Amount;
    }

    Balance -= Amount;
    cout << "\nSuccessful Withdraw.\nNew Balance is: " << Balance << endl;
}

void ShowATMMenu(int& Balance)
{
    int Choice;
    EnATMOptions Option;

    do
    {
        system("cls");
        cout << "=============================\n";
        cout << "       ATM Main Menu         \n";
        cout << "=============================\n";
        cout << "[1] Check Balance\n";
        cout << "[2] Deposit\n";
        cout << "[3] Withdraw\n";
        cout << "[4] Exit\n";
        cout << "=============================\n";
        cout << "Choose an operation: ";
        cin >> Choice;

        Option = (EnATMOptions)Choice;

        switch (Option)
        {
        case EnATMOptions::CheckBalance:
            cout << "\nYour Current Balance is: " << Balance << endl;
            break;
        case EnATMOptions::DepositOp:
            PerformDeposit(Balance);
            break;
        case EnATMOptions::WithdrawOp:
            PerformWithdraw(Balance);
            break;
        case EnATMOptions::ExitOp:
            cout << "\nThank you for using our ATM. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }

        if (Option != EnATMOptions::ExitOp)
            system("pause");

    } while (Option != EnATMOptions::ExitOp);
}

int main()
{
    int UserBalance = 7500;

    if (Login())
    {
        ShowATMMenu(UserBalance);
    }
    else
    {
        system("cls");
        cout << "Access Denied. Card Locked due to too many failed attempts.\n";
    }

    return 0;
}