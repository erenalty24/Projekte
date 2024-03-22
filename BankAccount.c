#include <stdio.h>
#include <string.h>  

struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
};

struct BankAccount createAccount(int accountNumber, char name[50], float initialBalance) {
    struct BankAccount account;
    account.accountNumber = accountNumber;
    strcpy(account.name, name);
    account.balance = initialBalance;
    return account;
}

void deposit(struct BankAccount *account, float amount) {
    account->balance += amount;
    printf("Deposited $%.2f into account %d. New Balance: $%.2f\n", amount, account->accountNumber, account->balance);
}

void withdraw(struct BankAccount *account, float amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawn $%.2f from account %d. New Balance: $%.2f\n", amount, account->accountNumber, account->balance);
    } else {
        printf("Insufficient balance in account %d. Current balance: $%.2f\n", account->accountNumber, account->balance);
    }
}

float checkBalance(struct BankAccount account) {
    return account.balance;
}

int main() {
    struct BankAccount account1 = createAccount(1001, "John Doe", 1000.00);
    struct BankAccount account2 = createAccount(1002, "Jane Smith", 1500.00);

    deposit(&account1, 500.00);
    withdraw(&account2, 700.00);

    printf("Account %d balance: $%.2f\n", account1.accountNumber, checkBalance(account1));
    printf("Account %d balance: $%.2f\n", account2.accountNumber, checkBalance(account2));

    return 0;  
}
