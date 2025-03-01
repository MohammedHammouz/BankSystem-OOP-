#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsString.h"
using namespace std;
class clsDepositScreen :protected clsScreen
{
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }
    static void _PrintClient(clsBankClient Client)
    {
        cout << "_____________________Client Card___________________________\n";
        cout << "|AccountNumber: " << setw(15) << left << Client.AccountNumber();
        cout << "\n|FullName: " << setw(20) << left << Client.FullName();
        cout << "\n|Phone: " << setw(12) << left << Client.Phone;
        cout << "\n|Email: " << setw(20) << left << Client.Email;
        cout << "\n|PinCode: " << setw(10) << left << Client.PinCode;
        cout << "\n|AccountBalance: " << setw(12) << left << Client.AccountBalance;
        cout << "_______________________________________________________________\n";

    }
public:
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\tDeposit Screen");
        cout << "Please Enter new client Account Number: " << endl;
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        cout << "Enter\n";
        double Deposit = Client.Deposit();
        Client.AccountBalance = Deposit;
        Client.Save();
        
    }
};

