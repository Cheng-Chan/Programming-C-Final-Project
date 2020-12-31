//
//  Bank.hpp
//  Bank Mangement System
//
//  Created by Apple on 30/12/2563 BE.
//  Copyright © 2563 Step IT Academy. All rights reserved.
//

#ifndef Bank_hpp
#define Bank_hpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;


class Screen {
private:
    int choice;
public:
    Screen();
    int getChoice();
    void welcome();
};

class SignIn {
private:
    string username;
    string password;
public:
    SignIn() {
        
    }
    SignIn(string username, string password);
    void setUsername(string username);
    string getUsername() const;
    friend istream &operator >> (istream &in, SignIn &sign);
};

class Admin : public SignIn {
private:
    int option;
    int id;
    map<int, string> user;
    map<int, string> pass;
public:
    int getOption() const;
    int getID() const;
    void adminMenu();
    
    void addUser();
    void viewUser();
    void deleteUser();
    void updateUser();
    void findUser();
    void customerLogin();
    void customerChangePin();
};

class Customer : public Admin {
private:
    int option;
    map<int, double> balance;
public:
    int getOption() const;
    void customerMenu();
    double balENQ(int enq);
    double deposit(int enq);
    double withdraw(int enq);
};

istream &operator >> (istream &in, SignIn &sign);

#endif /* Bank_hpp */
