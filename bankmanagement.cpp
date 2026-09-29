#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string name;
    int balance;
    static int totalAccounts;
    bool accountCreated;

public:
    BankAccount() {
        accountNumber = 0;
        balance = 0;
        accountCreated = false;
    }

    virtual ~BankAccount() {
    }

    void createAccount() {
        if (accountCreated) {
            cout << "Account is already created!" << endl;
            return;
        }

        cout << "Enter your account number: ";
        cin >> accountNumber;

        cout << "Enter your name: ";
        cin >> name;

        accountCreated = true;
        totalAccounts++;

        cout << "YOUR ACCOUNT IS SUCCESSFULLY CREATED!" << endl;
    }

    void deposit() {
        int dep;

        cout << "Enter the amount you have to deposit: ";
        cin >> dep;

        try {
            if (dep <= 0)
                throw 0;

            balance += dep;
            cout << "Deposit Successful!" << endl;
        }
        catch (int x) {
            cout << "Deposit amount must be greater than zero." << endl;
        }
    }

    void deposit(int amount) {
        if (amount > 0)
            balance += amount;
    }

    void deposit(int amount, int bonus) {
        if (amount > 0 && bonus >= 0)
            balance += amount + bonus;
    }

    virtual void withdraw() = 0;

    static void ShowTotalAccounts() {
        cout << "Number of Accounts Created till now: "
             << totalAccounts << endl;
    }

    bool operator==(BankAccount &obj) {
        return balance == obj.balance;
    }

    bool operator>(BankAccount &obj) {
        return balance > obj.balance;
    }

    bool operator<(BankAccount &obj) {
        return balance < obj.balance;
    }

    virtual void calculateReward() = 0;

    friend void showBalance(BankAccount &obj);
};

class RewardSystem {
protected:
    int rewardPoints;

public:
    RewardSystem() {
        rewardPoints = 0;
    }

    void addRewardPoints(int balance) {
        if (balance > 0)
            rewardPoints = balance / 100;
        else
            rewardPoints = 0;
    }

    void showPoints() {
        cout << "Reward Points = " << rewardPoints << endl;
    }
};

class SavingsAccount : public BankAccount, public RewardSystem {
public:
    void withdraw() override {
        int withd;

        cout << "Enter the amount you have to withdraw: ";
        cin >> withd;

        if (withd <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        }
        else if (balance >= withd) {
            balance -= withd;
            cout << "Withdrawal Successful!" << endl;
        }
        else {
            cout << "Insufficient Balance" << endl;
        }
    }

    void calculateReward() override {
        addRewardPoints(balance);
        showPoints();
    }
};

class CurrentAccount : public BankAccount, public RewardSystem {
protected:
    int overdraftlimit;

public:
    CurrentAccount() {
        overdraftlimit = 5000;
    }

    void withdraw() override {
        int withd;

        cout << "Enter the amount you have to withdraw: ";
        cin >> withd;

        if (withd <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        }
        else if (balance - withd >= -overdraftlimit) {
            balance -= withd;
            cout << "Withdrawal Successful (Overdraft allowed)" << endl;
        }
        else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void calculateReward() override {
        addRewardPoints(balance);
        showPoints();
    }
};

int BankAccount::totalAccounts = 0;

void showBalance(BankAccount &obj) {
    cout << "Balance -> " << obj.balance << endl;
}

int main() {
    BankAccount *b[2];

    b[0] = new SavingsAccount;
    b[1] = new CurrentAccount;

    while (true) {
        cout << "\n==== BANK MANAGEMENT SYSTEM ====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Show Balance" << endl;
        cout << "5. Show Reward Points" << endl;
        cout << "6. Compare Accounts" << endl;
        cout << "7. Show Total Accounts" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
        case 2:
        case 3:
        case 4:
        case 5: {
            int i;

            cout << "Enter account index (Savings = 0, Current = 1): ";
            cin >> i;

            if (i < 0 || i > 1) {
                cout << "Invalid index!" << endl;
                break;
            }

            if (choice == 1)
                b[i]->createAccount();
            else if (choice == 2)
                b[i]->deposit();
            else if (choice == 3)
                b[i]->withdraw();
            else if (choice == 4)
                showBalance(*b[i]);
            else if (choice == 5)
                b[i]->calculateReward();

            break;
        }

        case 6:
            if (*b[0] > *b[1]) {
                cout << "Savings Account has more balance." << endl;
            }
            else if (*b[0] < *b[1]) {
                cout << "Current Account has more balance." << endl;
            }
            else {
                cout << "Both accounts have same balance." << endl;
            }
            break;

        case 7:
            BankAccount::ShowTotalAccounts();
            break;

        case 8:
            cout << "Exiting program..." << endl;

            for (int i = 0; i < 2; i++) {
                delete b[i];
            }

            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}