//
//  main.cpp
//  Bank Mangement System
//
//  Created by Apple on 21/12/2563 BE.
//  Copyright © 2563 Step IT Academy. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include "Bank.hpp"
using namespace std;

int main() {
    Screen screen;
    Admin admin;
    Customer customer;
jump:
    screen.welcome();
    switch(screen.getChoice()) {
            case 1:
                cin >> admin;
                do {
                    admin.adminMenu();
                    if(admin.getOption() == 1) {
                    admin.addUser();
                        system("pause");
                        system("cls");
                    }
                    else if(admin.getOption() == 2) {
                        admin.viewUser();
                        system("pause");
                        system("cls");
                    }
                    else if(admin.getOption() == 3) {
                        admin.updateUser();
                        system("pause");
                        system("cls");
                    }
                    else if(admin.getOption() == 4) {
                        admin.deleteUser();
                        system("pause");
                        system("cls");
                    }
                    else if(admin.getOption() == 5) {
                        admin.findUser();
                        system("pause");
                        system("cls");
                    }
                }while(admin.getOption()!= 6);
                    system("pause");
                    system("cls");
                    //screen.welcome();
                    goto jump;
            case 2:
                customer.customerLogin();
                do {
                    customer.customerMenu();
                    if(customer.getOption() == 1) {
                        customer.balENQ(customer.getID());
                        system("pause");
                        system("cls");
                    }
                    else if(customer.getOption() == 2) {
                        customer.withdraw(customer.getID());
                        system("pause");
                        system("cls");
                    }
                    else if(customer.getOption() == 3) {
                        customer.deposit(customer.getID());
                        system("pause");
                        system("cls");
                    }
                    else if(customer.getOption() == 4) {
                        customer.customerChangePin();
                        system("pause");
                        system("cls");
                    }
                }while(customer.getOption() != 5);
                    system("pause");
                    system("cls");
                    goto jump;
            
        case 3:
            cout << "\t\t\t==========================" << endl;
            cout << "\t\t\t   THANKS FOR SUPPOTING   " << endl;
            cout << "\t\t\t==========================" << endl;
            break;
    }
    return 0;
}

