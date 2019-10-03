/* Bank Acct Management system: Create Acct, deposit, withdraw, fund transfer within same bank, balance inquiry,
display acct holder details, modify acct details, close acct permanently, loan request */
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include<string>

class banker;
class acct {
    private:
        int acctno;
    std::string holdername;
    std::string address;
    std::string accttype;
    float balance;
    float loan;
    float income;
    public:
        acct() {
            acctno = 0;
            holdername = "";
            address = "";
            accttype = "";
            balance = 0;
            loan = 0;
            income = 0;
        }
    static int no;
    void createacct();
    void deposit(float n);
    void withdraw(float m);
    void display_details();
    void modify_details();
    void close_acct();
    void loanrequest(int l);
    void transfer(int c, int amt);
    int getBalance();
    std::string getName();
};

int acct::no = 100835298;
std::string acct::getName() {
    return holdername;
}

int acct::getBalance() {
    return balance;
}

void acct::createacct() {
    std::cout << "Enter the name of the account holder:" << std::endl;
    std::cin >> holdername;
    std::cout << "Address of account holder:" << std::endl;
    std::cin >> address;
    std::cout << "Which type of account would you like? Savings or Current:" << std::endl;
    std::cin >> accttype;
    std::cout << "Please enter your starting balance(Rs.):" << std::endl;
    std::cin >> balance;
    std::cout << "For future loan purposes, what is your current annual salary?" << std::endl;
    std::cin >> income;
    acctno = no++;
    std::cout << "Your new account number: " << acctno << std::endl;
}

void acct::deposit(float n) {
    balance += n;
    std::cout << "You have successfully deposited." << std::endl << "Balance: " << balance << std::endl;
}

void acct::withdraw(float n) {
    balance -= n;
    if (balance < 0) {
        std::cout << "You don't have enough money to withdraw Rs. " << n << std::endl;
        balance += n;
    } else
        std::cout << "You have successfully withdrawn Rs. " << n << std::endl << "Remaining balance: " << balance << std::endl;
}

void acct::loanrequest(int l) {
    loan = l;
}

void acct::transfer(int c, int amt) {
    if (c == 1)
        balance += amt;
    else if (c == 2) {
        balance -= amt;
        std::cout << "Successfully transferred";
    }

}

void acct::display_details() {
    std::cout << "Name: " << holdername << std::endl <<
        "Account number: " << acctno << std::endl <<
        "Address: " << address << std::endl <<
        "Account type: " << accttype << std::endl <<
        "Balance: " << balance << std::endl <<
        "Amount of loan taken: " << loan << std::endl <<
        "Income: " << income << std::endl;
}

void acct::modify_details() {
    std::cout << "Enter the new name: ";
    std::cin >> holdername;
    std::cout << "Enter the new address: ";
    std::cin >> address;
    std::cout << "Enter the new income: ";
    std::cin >> income;
}

int main() {
    std::fstream file;
    int choice, f;
    float amount;
    long pos;
    std::string name;
    acct user;
    do {
        std::cout << std::endl << 
            "Welcome. What do you want to do?" << 
            std::endl <<
            "1. Create an account." << 
            std::endl <<
            "2. Deposit money." << 
            std::endl <<
            "3. Withdraw money." << 
            std::endl <<
            "4. Display your details." << 
            std::endl <<
            "5. Modify your details." << 
            std::endl <<
            "6. Request for loan." << 
            std::endl <<
            "7. Transfer money to other account" << 
            std::endl <<
            "8. Close your account." <<
            std::endl;
        std::cin >> choice;

        f = 0;

        if (choice == 0)
            exit(0);
        else if (choice == 1) {
            f = 0;
        } else if (choice >= 2 && choice <= 8) {
            std::cout << "Enter your name" << std::endl;
            std::cin >> name;
        } else {
            std::cout << "You seem to have entered a wrong number";
        }

        // Declares an object of the class acct.
        switch (choice) {
            case 1: // Creates an account for the user
                user.createacct();
                file.open("database.dat", std::ios::binary | std::ios::app);
                file.write((char * ) & user, sizeof(user));
                break;

            case 2: // Deposits money in the current users account
                std::cout << "Enter the amount you want to deposit" << std::endl;
                fflush(stdin);
                scanf("%f", & amount);
                file.open("database.dat", std::ios::binary | std::ios::out | std::ios::in);
                while (file.read((char * ) & user, sizeof(user))) {
                    if (user.getName().compare(name) == 0) {
                        user.deposit(amount);
                        pos = file.tellg();
                        file.seekp(pos - sizeof(user));
                        file.write((char * ) & user, sizeof(user));
                        f = 1;
                        break;
                    }
                }
                if (f == 0) {
                    std::cout << "Not Found";
                }
                break;
            
            case 3: // Withdraws money from the current users account
                std::cout << "Enter the amount you want to withdraw" << std::endl;
                float amout;
                std::cin >> amount;
                file.open("database.dat", std::ios::binary | std::ios::out | std::ios:: in );

                while (file.read((char * ) & user, sizeof(user))) {
                    if (user.getName().compare(name) == 0) {
                        user.withdraw(amount);
                        pos = file.tellg();
                        file.seekp(pos - sizeof(user));
                        file.write((char * ) & user, sizeof(user));
                        f = 1;
                        break;
                    }
                }
                if (f == 0) {
                    std::cout << "Not Found";
                }
                break;

            case 4: // Displays users details
                std::cout << "Here are your details." << std::endl;
                file.open("database.dat", std::ios::binary | std::ios::in);
                while (file.read((char * ) & user, sizeof(user))) {
                    if (user.getName().compare(name) == 0) {
                        user.display_details();
                        f = 1;
                        break;
                    }
                }
                if (f == 0) {
                    std::cout << "Not Found";
                }
                break;

            case 5: // Modify your account details
                file.open("database.dat", std::ios::binary | std::ios::out | std::ios::in);
                while (file.read((char * ) & user, sizeof(user))) {
                    if (user.getName().compare(name) == 0) {
                        user.modify_details();
                        pos = file.tellg();
                        file.seekp(pos - sizeof(user));
                        file.write((char * ) & user, sizeof(user));
                        f = 1;
                        break;
                    }
                }
                if (f == 0) {
                    std::cout << "Not Found";
                }
                break;

            case 6: // Apply for loan
                int l;

                std::cout << "Enter the loan required: ";
                std::cin >> l;
                file.open("database.dat", std::ios::binary | std::ios::out | std::ios::in);
                while (file.read((char * ) & user, sizeof(user))) {
                    if (user.getName().compare(name) == 0) {
                        user.loanrequest(l);
                        pos = file.tellg();
                        file.seekp(pos - sizeof(user));
                        file.write((char * ) & user, sizeof(user));
                        f = 1;
                        break;
                    }
                }
                if (f == 0) {
                    std::cout << "Not Found";
                }
                break;

            case 7:
                {
                    std::string rec;
                    int amt;
                    std::cout << "Enter recipient's name: ";
                    std::cin >> rec;
                    std::cout << "Enter amount: ";
                    std::cin >> amt;
                    int recipientBal,
                    senderBal;
                    file.open("database.dat", std::ios::binary | std::ios::out | std::ios::in);
                    while (file.read((char * ) & user, sizeof(user))) {
                        if (user.getName().compare(name) == 0) {
                            senderBal = user.getBalance();
                        }
                    }
                    file.close();
                    if (senderBal - amount > 0) {
                        file.open("database.dat", std::ios::binary | std::ios::out | std::ios::in);
                        while (file.read((char * ) & user, sizeof(user))) {
                            if (user.getName().compare(rec) == 0) {
                                user.transfer(1, amt);

                            } else if (user.getName().compare(name) == 0) {
                                user.transfer(2, amt);
                            }
                            pos = file.tellg();
                            file.seekp(pos - sizeof(user));
                            file.write((char * ) & user, sizeof(user));
                        }
                    } else {
                        std::cout << "Sender has insufficient balance" << std::endl;
                    }
                    break;
                }

            case 8: // Close account
                {
                    int deleted;
                    std::fstream file2;
                    file.open("database.dat", std::ios::binary | std::ios::out | std::ios::in);
                    file2.open("temporary.dat", std::ios::binary | std::ios::out);

                    while (file.read((char * ) & user, sizeof(user))) {
                        if (user.getName().compare(name)) {
                            file2.write((char * ) & user, sizeof(user));
                        } else {
                            deleted = 1;
                        }
                    }
                    file.close();
                    file2.close();
                    if (deleted == 0) {
                        std::cout << "Not Found";
                    } else {
                        std::cout << "Deleted";
                    }
                    deleted = remove("database.dat") == 0;
                    rename("temporary.dat", "database.dat");
                    break;
                }

        }
        file.close();
    } while (choice != 0);
}
