/*
    Design and implement class called BankAccount. This will be a generic account defined by its account number,
    the name of the owner and the funds available.

    Complete the following steps:

    1) Create class called BankAccount
    2) Use typical info about bank accounts to design attributes, such as the account number,
    the owner name, and the available funds.
    3) Specify access so that member data are protected from other parts of the program.
    4) Create accessor and mutator functions for member data.
*/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;
using std::string;
using std::cout;

class BankAccount
{
  private:
      // TODO: declare member variables
    string name;
    int account_no;
    double balance;

  public:
    // Constructor declaration
    BankAccount(string str, int acc, double bal);
    
      // TODO: declare setters
    void Cust_Name(string str);
    void Cust_Acc(int acc);
    void Cust_Bal(double bal);
    
      // TODO: declare getters
    string Cust_Name() const;
    int Cust_Acc() const;
    double Cust_Bal() const;
};

// Constructor
BankAccount::BankAccount(string str, int acc, double bal) {
  Cust_Name(str);
  Cust_Acc(acc);
  Cust_Bal(bal);
}

// TODO: implement setters
void BankAccount::Cust_Name(string str) {name = str;}
void BankAccount::Cust_Acc(int acc) {account_no = acc;}
void BankAccount::Cust_Bal(double bal) {balance = bal;}

// // TODO: implement getters
string BankAccount::Cust_Name() const {return name;}
int BankAccount::Cust_Acc() const {return account_no;}
double BankAccount::Cust_Bal() const {return balance;}

int main(){
    // TODO: instantiate and output a bank account
    BankAccount bank("bank", 100, 2250.09);
    assert(bank.Cust_Name() == "bank");
    assert(bank.Cust_Acc() == 100);
    assert(bank.Cust_Bal() == 2250.09);
}