#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"


using namespace std;
class clsListUsers:protected clsScreen
{
    static void _PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;


    }
public:
	static void ShowListUsers() {
		
        vector<clsUser>vUsers = clsUser::getListUsers();
        string Title = "\t Users list screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s)";
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
        if (vUsers.size() == 0) {
            cout << "No Users available";
        }
        else {
            for (clsUser User : vUsers) {
                _PrintUserRecordLine(User);
                cout << endl;

            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;

        }

	}
};

