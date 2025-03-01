#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include"clsClientListScreen.h"
#include "clsAddNewClients.h"
#include"clsDeleteClientScreen.h"
#include"clsPermissions.h"
class clsUpdateClientsScreen:protected clsScreen
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
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:
    static void ShowUpdateClientScreen() {
       
       /* if (!IsPermission(clsUser::enMainMenuePermissions::pUpdateClients)) {
            return;
        }*/
        string AccountNumber = "";
        _DrawScreenHeader("Update client screen");
        cout << "Please Enter Client Account Number\n";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Client Account Number is not found,choose another one\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        _ReadClientInfo(Client1);
        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client1);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }

       
    }
};

