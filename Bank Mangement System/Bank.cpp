//
//  Bank.cpp
//  Bank Mangement System
//
//  Created by Apple on 30/12/2563 BE.
//  Copyright © 2563 Step IT Academy. All rights reserved.
//

#include "Bank.hpp"

Screen::Screen() {
    cout << "\t\t\t=========================" << endl;
    cout << "\t\t\t       LABOUR  BANK      " << endl;
    cout << "\t\t\t        MANAGEMENT       " << endl;
    cout << "\t\t\t          SYSTEM         " << endl;
    cout << "\t\t\t=========================" << endl;
    cout << "\n\t\tPress any key to continue ..." << endl;
    system("pause");
    system("cls");
}
int Screen::getChoice() {
    return choice;
}
    //main page
void Screen::welcome() {
    cout << "\t\t\t=========================" << endl;
    cout << "\t\t\t         WELCOME         " << endl;
    cout << "\t\t\t=========================" << endl;
    cout << "\n\t\t1. Admin Login" << endl;
    cout << "\t\t2. Customer Login" << endl;
    cout << "\t\t3. Exit" << endl;
    cout << "\n\t\t==> Enter your choice: ";
    cin >> choice;
}

SignIn::SignIn(string username, string password) {
    this->username = username;
    this->password = password;
}
void SignIn::setUsername(string username) {
    this->username = username;
}
string SignIn::getUsername() const{
    return username;
}

int Admin::getOption() const {
    return option;
}
int Admin::getID() const {
    return id;
}
void Admin::adminMenu() {
    cout << "\t\t\t=========================" << endl;
    cout << "\t\t\t        MAIN MENU        " << endl;
    cout << "\t\t\t=========================" << endl;
    cout << "\n\t\t1. Add User" << endl;
    cout << "\t\t2. View User" << endl;
    cout << "\t\t3. Update User" << endl;
    cout << "\t\t4. Delete User" << endl;
    cout << "\t\t5. Find User" << endl;
    cout << "\t\t6. Exit" << endl;
    cout << "\n\t\t==> Enter your choice: ";
    cin >> option;
}
void Admin::addUser() {
    cout << "\t\t\t==========================" << endl;
    cout << "\t\t\t    USER CREATION FORM    " << endl;
    cout << "\t\t\t==========================" << endl;
    int id;
    cout << "\n\t\tEnter ID number: ";
    cin >> id;
    cout << "\t\tEnter username: ";
    cin >> user[id];
    cout << "\t\tEnter password: ";
    cin >> pass[id];
    fstream st;
    st.open("Admin.txt", ios::out | ios::binary | ios::app);
    try {
        if(!st) {
            cout << "\n\t\t\tFile creation failed ...";
            throw id;
        }else {
            st << "Adding a user/customer" << endl;
            st << "ID Number: " << id << endl;
            st << "Username: " << user[id] << endl;
            st << "Password: " << pass[id] << endl;
            st.close();
        }
    }
    catch(int id) {
        cout << "\n\t\tFile couldn't created with this ID number: " << id << " of user.";
    }
}
void Admin::viewUser() {
    cout << "\t\t\t==========================" << endl;
    cout << "\t\t\t       VIEW ALL USER      " << endl;
    cout << "\t\t\t==========================" << endl;
    cout << "No.\t\t\t" <<"Username\t\t\t" << "Password" << endl;
    for(int i = 1; i <= user.size() ;i++) {
        cout << i << ". \t\t\t"<< user[i] <<"\t\t\t\t" << pass[i] << endl;
    }
}
void Admin::deleteUser() {
    cout << "\t\t\t==========================" << endl;
    cout << "\t\t\t        DELETE USER       " << endl;
    cout << "\t\t\t==========================" << endl;
    int id;
    cout <<"\n\t\tEnter ID of user to delete: ";
    cin >> id;
    user.erase(id);
    pass.erase(id);fstream st;
    st.open("Admin.txt", ios::out | ios::binary | ios::app);
    try {
        if(!st) {
            cout << "\n\t\t\tFile creation failed ...";
            throw id;
        }else {
            st << "Delete user/customer information" << endl;
            st << "ID Number: " << id << endl;
            st << "Username: " << user[id] << endl;
            st << "Password: " << pass[id] << endl;
            st.close();
        }
    }
    catch(int id) {
        cout << "\n\t\tFile couldn't created with this ID number: " << id << " of user.";
    }
}
void Admin::updateUser() {
    cout << "\t\t\t==========================" << endl;
    cout << "\t\t\t        UPDATE USER       " << endl;
    cout << "\t\t\t==========================" << endl;
    cout << "No.\t\t\t" <<"Username\t\t\t" << "Password" << endl;
    for(int i = 1; i <= user.size() ;i++) {
        cout << i << ". \t\t\t"<< user[i] <<"\t\t\t\t" << pass[i] << endl;
    }
    int id;
    cout << "\n\t\tEnter ID of user to update: ";
    cin >> id;
    cout << "\t\tEnter current username: ";
    cin >> user[id];
    cout << "\t\tEnter current password: ";
    cin >> pass[id];
    cout << "\t\tRe-enter current password: ";
    cin >> pass[id];
    cout << "\t\tEnter new username: ";
    cin >> user[id];
    cout << "\t\tEnter new password: ";
    cin >> pass[id];
    cout << "\t\tRe-enter new password: ";
    cin >> pass[id];
    fstream st;
    st.open("Admin.txt", ios::out | ios::binary | ios::app);
    try {
        if(!st) {
            cout << "\n\t\t\tFile creation failed ...";
            throw id;
        }else {
            st << "Update user/customer information" << endl;
            st << "ID Number: " << id << endl;
            st << "Username: " << user[id] << endl;
            st << "Password: " << pass[id] << endl;
            st.close();
        }
    }
    catch(int id) {
        cout << "\n\t\tFile couldn't created with this ID number: " << id << " of user.";
    }
}
void Admin::findUser() {
    cout << "\t\t\t==========================" << endl;
    cout << "\t\t\t        SERACH USER       " << endl;
    cout << "\t\t\t==========================" << endl;
    int id;
    cout << "\n\t\tEnter ID of user to find: ";
    cin >> id;
    cout << "\n\t\tID: " << id;
    cout << "\n\t\tUsername: "<< user[id] << endl;
    cout << "\t\tPassword: "<< pass[id] << endl;
}
void Admin::customerLogin() {
    cout << "\t\t\t==========================" << endl;
    cout << "\t\t\t           LOGIN          " << endl;
    cout << "\t\t\t==========================" << endl;
    cout << "\n\t\tEnter ID number: ";
    cin >> id;
    cout << "\t\tEnter username: ";
    cin >> user[id];
    cout << "\t\tEnter password: ";
    cin >> pass[id];
    fstream st;
    st.open("Customer.txt", ios::out | ios::binary | ios::app);
    try {
        if(!st) {
            cout << "\n\t\t\tFile creation failed ...";
            throw id;
        }else {
            st << "User/customer information logined" << endl;
            st << "ID Number: " << id << endl;
            st << "Username: " << user[id] << endl;
            st << "Password: " << pass[id] << endl;
            st.close();
        }
    }
    catch(int id) {
        cout << "\n\t\tFile couldn't created with this ID number: " << id << " of user.";
    }
}
void Admin::customerChangePin() {
    cout << "\t\t\t==========================" << endl;
    cout << "\t\t\t        CHANGE PIN        " << endl;
    cout << "\t\t\t==========================" << endl;
    int id;
    cout << "\n\t\tEnter ID number: ";
    cin >> id;
    cout << "\t\tRe-enter current password: ";
    cin >> pass[id];
    cout << "\t\tEnter new username: ";
    cin >> user[id];
    cout << "\t\tEnter new password: ";
    cin >> pass[id];
    cout << "\t\tRe-enter new password: ";
    cin >> pass[id];
    fstream st;
    st.open("Customer.txt", ios::out | ios::binary | ios::app);
    try {
        if(!st) {
            cout << "\n\t\t\tFile creation failed ...";
            throw id;
        }else {
            st << "Update user/customer information" << endl;
            st << "ID Number: " << id << endl;
            st << "Username: " << user[id] << endl;
            st << "Password: " << pass[id] << endl;
            st.close();
        }
    }
    catch(int id) {
        cout << "\n\t\tFile couldn't created with this ID number: " << id << " of user.";
    }
}

int Customer::getOption() const {
    return option;
}
void Customer::customerMenu() {
    cout << "\t\t\t=========================" << endl;
    cout << "\t\t\t        MAIN MENU        " << endl;
    cout << "\t\t\t=========================" << endl;
    cout << "\n\t\t1. BALANCE ENQUIRY" << endl;
    cout << "\t\t2. CASH WITHDRAWAL" << endl;
    cout << "\t\t3. DEPOSIT" << endl;
    cout << "\t\t4. CHANGE PIN" << endl;
    cout << "\t\t5. Exit" << endl;
    cout << "\n\t\t==> Enter your choice: ";
    cin >> option;
}
double Customer::balENQ(int enq) {
    cout << "\t\t\t=========================" << endl;
    cout << "\t\t\t     BALANCE ENQUIRY     " << endl;
    cout << "\t\t\t=========================" << endl;
    cout << "\n\t\tYour account has: " << balance[enq] << " USD" << endl;
    fstream wt;
    wt.open("Customer.txt", ios::out | ios::binary | ios::app);
    try {
        if(!wt) {
            cout << "\n\t\t\tFile creation failed ...";
            throw enq;
        }else {
            wt << "Balance Enquiry" << endl;
            wt << "Balance: " << balance[enq] << endl;
            wt.close();
        }
    }
    catch(int enq) {
        cout << "\n\t\tFile couldn't created with this enquiry: " << enq << endl;
    }
    return enq;
}
double Customer::deposit(int enq) {
    cout << "\t\t\t=========================" << endl;
    cout << "\t\t\t        DEPOSIT          " << endl;
    cout << "\t\t\t=========================" << endl;
    double amount;
    cout << "\n\t\tEnter amount you want to deposit: ";
    cin >> amount;
    balance[enq] = balance[enq] + amount;
    fstream wt;
    wt.open("Customer.txt", ios::out | ios::binary | ios::app);
    try {
        if(!wt) {
            cout << "\n\t\t\tFile creation failed ...";
            throw enq;
        }else {
            wt << "Cash Deposit" << endl;
            wt << "Balance: " << balance[enq] << endl;
            wt.close();
        }
    }
    catch(int enq) {
        cout << "\n\t\tFile couldn't created with this enquiry: " << enq << endl;
    }
    return balance[enq];
}
double Customer::withdraw(int enq) {
    cout << "\t\t\t=========================" << endl;
    cout << "\t\t\t     CASH WITHDRAWAL     " << endl;
    cout << "\t\t\t=========================" << endl;
    double amount;
    cout << "\n\t\tEnter amount you want to withdraw: ";
    cin >> amount;
    balance[enq] = balance[enq] - amount;
    fstream wt;
    wt.open("Customer.txt", ios::out | ios::binary | ios::app);
    try {
        if(!wt) {
            cout << "\n\t\t\tFile creation failed ...";
            throw enq;
        }else {
            wt << "Cash Withdrawal" << endl;
            wt << "Balance: " << balance[enq] << endl;
            wt.close();
        }
    }
    catch(int enq) {
        cout << "\n\t\tFile couldn't created with this enquiry: " << enq << endl;
    }
    return balance[enq];
}

istream &operator >> (istream &in, SignIn &sign) {
    do{
        cout << "\n\t\tEnter username: ";
        in >> sign.username;
        cout << "\t\tEnter password: ";
        in >> sign.password;
        cout << "\t\tRe-enter password: ";
        in >> sign.password;
        if(sign.username != "admin" && sign.password != "sa123") {
            cout << "\n\t\tIncorrect password or username" << endl;
        }
        system("pause");
        system("cls");
    }while(sign.username != "admin" && sign.password != "sa123");
    fstream st;
    st.open("Admin.txt", ios::out | ios::binary | ios::beg);
    try {
        if(!st) {
            cout << "\n\t\t\tFile creation failed ...";
            throw sign.username;
        }else {
            st << "Admin information" << endl;
            st << "Admin username: " << sign.username << endl;
            st << "Admin password: " << sign.password << endl;
            st.close();
        }
    }
    catch(string username) {
        cout << "\n\t\tFile couldn't created with this username: " << username << endl;
    }
    
    return in;
}

