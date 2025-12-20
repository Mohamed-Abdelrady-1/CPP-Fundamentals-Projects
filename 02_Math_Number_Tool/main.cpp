#include <iostream>
using namespace std;

enum EnMainMenuOptions { Prime = 1, Factorial = 2, SumDigits = 3, Reset = 4, Exit = 5 };

void ReadNumber(int& Number)
{
    cout << "Please Enter a Positive Number: ";
    cin >> Number;
    while (Number < 0)
    {
        cout << "Positive numbers only! Enter again: ";
        cin >> Number;
    }
}

bool CheckPrime(int Number)
{
    if (Number <= 1) return false;
    for (int i = 2; i <= Number / 2; i++)
    {
        if (Number % i == 0) return false;
    }
    return true;
}

int CalculateFactorial(int Number)
{
    int Result = 1;
    for (int i = 1; i <= Number; i++)
    {
        Result *= i;
    }
    return Result;
}

int CalculateSumDigits(int Number)
{
    int Sum = 0;
    while (Number > 0)
    {
        Sum += (Number % 10);
        Number /= 10;
    }
    return Sum;
}

void ShowMainMenu(int& Number)
{
    int Choice;
    EnMainMenuOptions Option;

    do
    {
        system("cls");
        cout << "*********************\n";
        cout << "    Number Tool      \n";
        cout << "*********************\n";
        cout << "Current Number: " << Number << endl;
        cout << "*********************\n";
        cout << "[1] Check Prime\n";
        cout << "[2] Calculate Factorial\n";
        cout << "[3] Sum Digits\n";
        cout << "[4] Reset Number\n";
        cout << "[5] Exit\n";
        cout << "*********************\n";
        cout << "Your Choice: ";
        cin >> Choice;

        Option = (EnMainMenuOptions)Choice;

        switch (Option)
        {
        case EnMainMenuOptions::Prime:
            if (CheckPrime(Number))
                cout << "\nResult: The number " << Number << " IS Prime.\n";
            else
                cout << "\nResult: The number " << Number << " is NOT Prime.\n";
            break;

        case EnMainMenuOptions::Factorial:
            cout << "\nResult: Factorial of " << Number << " is " << CalculateFactorial(Number) << endl;
            break;

        case EnMainMenuOptions::SumDigits:
            cout << "\nResult: Sum of digits is " << CalculateSumDigits(Number) << endl;
            break;

        case EnMainMenuOptions::Reset:
            ReadNumber(Number);
            break;

        case EnMainMenuOptions::Exit:
            cout << "\nGoodbye!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please try again.\n";
        }

        if (Option != EnMainMenuOptions::Exit && Option != EnMainMenuOptions::Reset)
        {
            system("pause");
        }

    } while (Option != EnMainMenuOptions::Exit);
}

int main()
{
    int Number;
    ReadNumber(Number);
    ShowMainMenu(Number);
    return 0;
}