//Evans Kumi
//96162025

#include <iostream>
#include <vector>
using namespace std;

//class BankAccount
/**
 * @class BankAccount
 * @brief Represents a bank account with account number, account holder name, and balance.
 * 
 * The BankAccount class provides functionality to deposit, withdraw, display account information,
 * and perform arithmetic operations on bank accounts.
 */


class BankAccount {
protected:
    string accountNumber; /**< The account number of the bank account. */
    string accountHolderName; /**< The name of the account holder. */
    double balance; /**< The balance of the bank account. */

public:
    /**
     * @brief Default constructor.
     * Initializes the bank account with empty account number, account holder name, and zero balance.
     */
    BankAccount():accountNumber(""),accountHolderName(""),balance(0.0){};

    /**
     * @brief Parameterized constructor.
     * Initializes the bank account with the given account number, account holder name, and balance.
     * @param accNum The account number of the bank account.
     * @param accHN The name of the account holder.
     * @param bal The balance of the bank account.
     */
    BankAccount(string accNum,string accHN,double bal)
        :accountNumber(accNum),accountHolderName(accHN),balance(bal){};

    /**
     * @brief Deposits the specified amount into the bank account.
     * @param amount The amount to be deposited.
     */
    virtual void deposit(int amount){
        balance += amount;};

    /**
     * @brief Withdraws the specified amount from the bank account.
     * @param amount The amount to be withdrawn.
     */
    virtual void withdraw(int amount){
        balance -= amount;};

    virtual void addBalance(double amount){
        balance += amount;
    }

    /**
     * @brief Displays the account information.
     */
    virtual void display()const {
        cout<<"Account No.: "<<accountNumber<<endl;
        cout<<"Name: "<<accountHolderName<<endl;
        cout<<"Bal: "<<balance<<endl;
    }

    /**
     * @brief Destructor.
     * Displays a message indicating the destruction of the bank account object.
     */
    virtual ~BankAccount(){
        cout<<"Account of Mr./Mrs. "<<accountHolderName<<" with account no "<<accountNumber<<" is destroyed with a balance BDT "<<balance<<endl;
    };

    /**
     * @brief Overloaded addition operator.
     * Adds the balances of two bank accounts and returns a new bank account object.
     * If the new account holder name or account number is empty, prompts the user to enter the values.
     * @param b The bank account to be added.
     * @return The new bank account object with the sum of the balances.
     */

    BankAccount operator+(BankAccount &b){
        BankAccount temp;
        temp.balance = this->balance + b.balance;
        if (temp.accountHolderName.empty()){
            cout<<"Enter the name of the new account holder: ";
            string name;
            cin>>name;
            temp.accountHolderName=name;

        }
        if (temp.accountNumber.empty()){
            cout<<"Enter the new account number: ";
            string accNum;
            cin>>accNum;
            temp.accountNumber = accNum;
            cout<<endl;
        }
        return temp;
    }

    /**
     * @brief Gets the account number of the bank account.
     * @return The account number.
     */
    string getAccountNumber(){
        return accountNumber;
    }

    /**
     * @brief Gets the account holder name of the bank account.
     * @return The account holder name.
     */
    string getAccountHolderName(){
        return accountHolderName;
    }

    /**
     * @brief Gets the balance of the bank account.
     * @return The balance.
     */
    double getBalance(){
        return balance;
    }
};

/**
 * @class SavingsAccount
 * @brief Represents a savings account that inherits from BankAccount.
 * 
 * The SavingsAccount class represents a savings account with an additional interest rate.
 * It inherits from the BankAccount class and provides methods to add interest, deposit money, and display account information.
 */
class SavingsAccount:public BankAccount
{
protected:
    double interestRate; /**< The interest rate for the savings account. */

public:
    /**
     * @brief Default constructor for SavingsAccount.
     * 
     * Initializes the interest rate to 0.0.
     */
    SavingsAccount():BankAccount(),interestRate(0.0){};

    /**
     * @brief Parameterized constructor for SavingsAccount.
     * 
     * Initializes the savings account with the specified account number, account holder name, balance, and interest rate.
     * 
     * @param accNum The account number for the savings account.
     * @param accHN The account holder name for the savings account.
     * @param bal The balance for the savings account.
     * @param ir The interest rate for the savings account.
     */
    SavingsAccount(string accNum,string accHN,double bal,double ir)
        :BankAccount(accNum,accHN,bal),interestRate(ir){};

    /**
     * @brief Adds interest to the savings account balance.
     * 
     * The interest is calculated by multiplying the current balance by the interest rate.
     */
    void addInterest(){
        balance += balance*interestRate;
    }

    /**
     * @brief Deposits money into the savings account.
     * 
     * The specified amount is deposited into the savings account balance.
     * Additionally, the interest is calculated and added to the balance.
     * 
     * @param amount The amount to be deposited.
     */
    void deposit(int amount){
        BankAccount::deposit(amount);
        balance += amount*interestRate;
    }

    /**
     * @brief Displays the savings account information.
     * 
     * The account number, account holder name, balance, and interest rate are displayed.
     */
    void display()const{
        BankAccount::display();
        cout<<"Interest rate: "<<interestRate<<endl;
    }
};

/**
 * @class CheckingAccount
 * @brief Represents a checking account that is derived from the BankAccount class.
 * 
 * The CheckingAccount class provides additional functionality specific to checking accounts,
 * such as an overdraft limit. It inherits the properties and methods of the BankAccount class.
 */
class CheckingAccount:public BankAccount
{

protected:
    double overdraftLimit;

public:
    CheckingAccount():overdraftLimit(0.0){}

    /**
     * @brief Constructs a new CheckingAccount object.
     * 
     * @param accNum The account number of the checking account.
     * @param accHN The account holder's name of the checking account.
     * @param bal The balance of the checking account.
     * @param ov The overdraft limit of the checking account.
     */
    CheckingAccount(string accNum,string accHN,double bal,double ov)
        :BankAccount(accNum,accHN,bal),overdraftLimit(ov){};

    /**
     * @brief Changes the overdraft limit of the bank account.
     * 
     * This function allows you to change the overdraft limit of the bank account.
     * The overdraft limit determines the maximum negative balance that the account can have.
     * 
     * @param ov The new overdraft limit to be set.
     */
    void changeOverdraftLimit(double ov){
        overdraftLimit = ov;
    }

void addOverdraftLimit(double ov){
    overdraftLimit += ov;   
}

    /**
     * @brief Withdraws a specified amount from the bank account.
     * 
     * This function checks if the withdrawal amount is within the overdraft limit.
     * If it is, the amount is subtracted from the balance.
     * If it is not, an error message is displayed indicating the maximum amount that can be withdrawn.
     * 
     * @param amount The amount to be withdrawn from the bank account.
     */
    void withdraw(int amount){
        if(balance-amount>=overdraftLimit)
            balance -= amount;
        else
            cout<<"Withdrawal amount should not exceed "<<overdraftLimit<< " So you can withdraw: "<<balance-overdraftLimit<<endl;
    }

    /**
     * Displays the details of the bank account, including the overdraft limit.
     */
    void display()const{
        BankAccount::display();
        cout<<"Overdraft limit: "<<overdraftLimit<<endl;
    }
};

int main(){

    // Create a bank account
    vector<BankAccount> bankAccounts;
    bankAccounts.push_back(BankAccount("123456","Mr. Adam Zanku",1000));
    bankAccounts.push_back(BankAccount("123457","Mr. Balama Akwesi",2000));
    bankAccounts.push_back(BankAccount("123458","Mr. Cephas Kofi",3000));
    bankAccounts.push_back(BankAccount("123459","Mr. Evans Kumi",4000));

    cout<< "Merge two bank Accounts to create a new Account"<<endl;

    //merge two accounts
    BankAccount mergedAccount = bankAccounts[0] + bankAccounts[1];
    mergedAccount.display();
    cout <<endl;
    // loop through the vector and display the accounts
    for (const BankAccount& account : bankAccounts) {
        account.display();
        cout << endl;
    }
    cout<<endl;

    // Make deposit into account 1
    cout << "Depositing 500 into account 1" << endl;
    bankAccounts[0].display();
    cout<<endl;

    //deposit some money into the account
    bankAccounts[0].deposit(500);

    cout << "New balance of account 1" << endl;
    bankAccounts[0].display();
    cout<<endl;

    cout<< "Make withdrawal of 1000 from the first bank Account"<<endl;

    //withdraw some money from the account
    bankAccounts[1].withdraw(1000);
    cout<<endl;

    cout << "New balance of account 2" << endl;
    bankAccounts[1].display();
    cout<<endl;

    //create a savings account
    vector<SavingsAccount> savingsAccounts;
    savingsAccounts.push_back(SavingsAccount("123456","Mr. Adam Zanku",1000,0.05));
    savingsAccounts.push_back(SavingsAccount("123457","Mr. Balama Akwesi",2000,0.05));
    savingsAccounts.push_back(SavingsAccount("123458","Mr. Cephas Kofi",3000,0.05));
    savingsAccounts.push_back(SavingsAccount("123459","Mr. Evans Kumi",4000,0.05));

    // loop through the vector and display the accounts
    for (const SavingsAccount& account : savingsAccounts) {
        account.display();
        cout << endl;
    }
    cout<<endl;

    // add the interest to all the banks accounts
    for (auto& account : savingsAccounts) {
        account.addInterest();
    }
    cout<<endl;

    cout << "After adding interest to all the accounts" << endl;
    for (const auto& account : savingsAccounts) {
        account.display();
        cout << endl;
    }
    cout<<endl;
        //create a checking account
    vector<CheckingAccount> checkingAccounts;
    checkingAccounts.push_back(CheckingAccount("123456","Mr. Adam Zanku",1000,500));
    checkingAccounts.push_back(CheckingAccount("123457","Mr. Balama Akwesi",2000,500));
    checkingAccounts.push_back(CheckingAccount("123458","Mr. Cephas Kofi",3000,500));
    checkingAccounts.push_back(CheckingAccount("123459","Mr. Evans Kumi",4000,500));
    cout<<endl;
    // loop through the vector and display the accounts
    for (const CheckingAccount& account : checkingAccounts) {
        account.display();
        cout << endl;
    }
    cout<<endl;
    // change the overdraft limit of the account
    cout << "Changing the overdraft limit of account 1" << endl;
    checkingAccounts[0].display();
    cout<<endl;

    //change the overdraft limit of the account
    checkingAccounts[0].changeOverdraftLimit(1000);

    cout << "New overdraft limit of account 1" << endl;
    checkingAccounts[0].display();
    cout<<endl;

    return 0;
}