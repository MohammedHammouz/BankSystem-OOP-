#pragma once

#include <iostream>
#include "clsScreen.h"
#include"clsMainScreen.h"
#include <iomanip>
#include"clsUser.h"
#include"Global.h"
using namespace std;
class clsLogin :protected clsScreen {
private:
    static  void _Login() {
        bool LoginFaild = false;
        string Username, Password;
        do {
            if (LoginFaild) {
                cout << "\nInvlaid Username/Password!\n\n";
            }
            cout << "Enter Username? ";
            cin >> Username;
            cout << "Enter Password? ";
            cin >> Password;
            clsUser User = clsUser::Find(Username, Password);
            LoginFaild = User.IsEmpty();
        } while (LoginFaild);
        clsMainScreen::ShowMainMenue();
    }
public:
    static void ShowLoginScreen() {
        _DrawScreenHeader("\t  Login Screen");
        _Login();
    }
};

