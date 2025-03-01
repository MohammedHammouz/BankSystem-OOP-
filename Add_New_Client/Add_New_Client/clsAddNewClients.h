#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsAddNewClients:protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }
    static void _PrintClient(clsBankClient Client)
        {
        
            cout << "| " << setw(15) << left << Client.AccountNumber();
            cout << "| " << setw(20) << left << Client.FullName();
            cout << "| " << setw(12) << left << Client.Phone;
            cout << "| " << setw(20) << left << Client.Email;
            cout << "| " << setw(10) << left << Client.PinCode;
            cout << "| " << setw(12) << left << Client.AccountBalance;
        
        }
public:
	static void AddNewClientsScreen() {

       /* if (!IsPermission(clsUser::enMainMenuePermissions::pAddNewClient)) {
            return;
        }*/
        string AccountNumber = "";
        _DrawScreenHeader("\tAdd new client screen");
        cout << "Please Enter new client Account Number: " << endl;
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);
        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }

	}

};

