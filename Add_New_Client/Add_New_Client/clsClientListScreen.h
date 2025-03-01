#pragma once
using namespace std;
#include <iostream>
#include "clsBankClient.h"
#include"clsScreen.h"
class clsClientListScreen:protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << "\t| " << setw(15) << left << Client.AccountNumber();
        cout << "\t| " << setw(20) << left << Client.FullName();
        cout << "\t| " << setw(12) << left << Client.Phone;
        cout << "\t| " << setw(20) << left << Client.Email;
        cout << "\t| " << setw(10) << left << Client.PinCode;
        cout << "\t| " << setw(12) << left << Client.AccountBalance;

    }
public:
	static void ShowClientsList() {
        
        /*if (!IsPermission(clsUser::enMainMenuePermissions::pListClients)) {
            return;
        }
        */
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t Clients list screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s)";
        _DrawScreenHeader(Title, SubTitle);
        
        cout << "\t___________________________________________________________________________________________________________________\n";
        cout << "\t| " << left << setw(15) << "Accout Number";
        cout << "\t| " << left << setw(20) << "Client Name";
        cout << "\t| " << left << setw(12) << "Phone";
        cout << "\t| " << left << setw(20) << "Email";
        cout << "\t| " << left << setw(10) << "Pin Code";
        cout << "\t| " << left << setw(12) << "Balance";
        cout << "\n\t_______________________________________________________";
        cout << "____________________________________________________________\n";
        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n\t_______________________________________________________";
        cout << "____________________________________________________________\n";
	}
};

