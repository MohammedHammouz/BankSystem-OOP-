#pragma once
using namespace std;
#include <iomanip>
#include "clsUser.h"
#include "clsPermissions.h"
#include"Global.h"
class clsScreen

{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }
    /*static bool IsPermission(clsUser::enMainMenuePermissions Permissons) {
        
        if (!CurrentUser.CheckAccessPermission(Permissons)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\nThis page is denied access\n";
            cout << "\t\t\t\t\t______________________________________";
            return false;
        }
        else {
            return true;
        }
        
    }*/
    
};