/*Bank Acct Management system: Create Acct, deposit, withdraw, fund transfer within same bank, balance inquiry,
display acct holder details, modify acct details, close acct permanently, loan request*/
#include<iostream>

#include<fstream>

#include<string>

#include <string.h>

#include <stdlib.h>

using namespace std;
class banker;
class acct {
    private:
        int acctno;
    string holdername;
    string address;
    string accttype;
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
    string getName();
};
int acct::no = 100835298;
string acct::getName() {
    return holdername;
}
int acct::getBalance() {
    return balance;
}
void acct::createacct() {
    cout << "Enter the name of the account holder:\n";
    cin >> holdername;
    cout << "Address of account holder:\n";
    cin >> address;
    cout << "Which type of account would you like? Savings or Current:\n";
    cin >> accttype;
    cout << "Please enter your starting balance(Rs.):\n";
    cin >> balance;
    cout << "For future loan purposes, what is your current annual salary?\n";
    cin >> income;
    acctno = no++;
    cout << "Your new account number: " << acctno << endl;
}
void acct::deposit(float n) {
    balance += n;
    cout << "You have successfully deposited.\n" << "Balance: " << balance << endl;
}
void acct::withdraw(float n) {
    balance -= n;
    if (balance < 0) {
        cout << "You don't have enough money to withdraw Rs. " << n << endl;
        balance += n;
    } else
        cout << "You have successfully withdrawn Rs. " << n << "\n" << "Remaining balance: " << balance << endl;
}
void acct::loanrequest(int l) {
    loan = l;
}
void acct::transfer(int c, int amt) {
    if (c == 1)
        balance += amt;
    else if (c == 2) {
        balance -= amt;
        cout << "Successfully transferred";
    }

}
void acct::display_details() {
    cout << "Name: " << holdername << endl <<
        "Account number: " << acctno << endl <<
        "Address: " << address << endl <<
        "Account type: " << accttype << endl <<
        "Balance: " << balance << endl <<
        "Amount of loan taken: " << loan << endl <<
        "Income: " << income << endl;
}
void acct::modify_details() {
    cout << "Enter the new name: ";
    cin >> holdername;
    cout << "Enter the new address: ";
    cin >> address;
    cout << "Enter the new income: ";
    cin >> income;
}
int main() {
    fstream file;
    int choice, f;
    float amount;
    long pos;
    string name;
    acct user;
    do {
        cout << "\nWelcome. What do you want to do?" <<
            "\n1. Create an account." <<
            "\n2. Deposit money." <<
            "\n3. Withdraw money." <<
            "\n4. Display your details." <<
            "\n5. Modify your details." <<
            "\n6. Request for loan." <<
            "\n7. Transfer money to other account" <<
            "\n8. Close your account." <<
            endl;
        cin >> choice;

        f = 0;

        if (choice == 0)
            exit(0);
        else if (choice == 1) {
            f = 0;
        } else if (choice >= 2 && choice <= 8) {
            cout << "Enter your name\n";
            cin >> name;
        } else {
            cout << "You seem to have entered a wrong number";
        }

        //declares an object of the class acct.
        switch (choice) {
            case 1: //creates an account for the user
                user.createacct();
                file.open("database.dat", ios::binary | ios::app);
                file.write((char * ) & user, sizeof(user));
                break;

            case 2: //deposits money in the current users account
                cout << "Enter the amount you want to deposit" << endl;
                fflush(stdin);
                scanf("%f", & amount);
                file.open("database.dat", ios::binary | ios::out | ios:: in );
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
                    cout << "Not Found";
                }
                break;

            case 3: //withdraws money from the current users account
                cout << "Enter the amount you want to withdraw" << endl;
                float amout;
                cin >> amount;
                file.open("database.dat", ios::binary | ios::out | ios:: in );

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
                    cout << "Not Found";
                }
                break;

            case 4: //displays users details
                cout << "Here are your details.\n";
                file.open("database.dat", ios::binary | ios:: in );
                while (file.read((char * ) & user, sizeof(user))) {
                    if (user.getName().compare(name) == 0) {
                        user.display_details();
                        f = 1;
                        break;
                    }
                }
                if (f == 0) {
                    cout << "Not Found";
                }
                break;

            case 5: //modify your account details
                file.open("database.dat", ios::binary | ios::out | ios:: in );
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
                    cout << "Not Found";
                }
                break;

            case 6: //apply for loan
                int l;

                cout << "Enter the loan required: ";
                cin >> l;
                file.open("database.dat", ios::binary | ios::out | ios:: in );
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
                    cout << "Not Found";
                }
                break;

            case 7:
                {
                    string rec;
                    int amt;
                    cout << "Enter recipient's name: ";
                    cin >> rec;
                    cout << "Enter amount: ";
                    cin >> amt;
                    int recipientBal,
                    senderBal;
                    file.open("database.dat", ios::binary | ios::out | ios:: in );
                    while (file.read((char * ) & user, sizeof(user))) {
                        if (user.getName().compare(name) == 0) {
                            senderBal = user.getBalance();
                        }
                    }
                    file.close();
                    if (senderBal - amount > 0) {
                        file.open("database.dat", ios::binary | ios::out | ios:: in );
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
                        cout << "Sender has insufficient balance" << endl;
                    }
                    break;
                }

            case 8: //close account
                {
                    int deleted;
                    fstream file2;
                    file.open("database.dat", ios::binary | ios::out | ios:: in );
                    file2.open("temporary.dat", ios::binary | ios::out);

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
                        cout << "Not Found";
                    } else {
                        cout << "Deleted";
                    }
                    deleted = remove("database.dat") == 0;
                    rename("temporary.dat", "database.dat");


                    break;
                }

        }
        file.close();
    } while (choice != 0);
}
