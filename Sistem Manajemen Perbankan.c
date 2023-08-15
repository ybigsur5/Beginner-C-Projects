#include <stdio.h>
#include <stdlib.h>

// layar utama akun perbankan
struct Account {
    int accNumber;
    char accHolder[50];
    float balance;
};

// Pembukaan rekening
void createAccount(struct Account accounts[], int *numAccounts) {
    printf("Enter account holder's name: ");
    scanf("%s", accounts[*numAccounts].accHolder);

    accounts[*numAccounts].accNumber = *numAccounts + 1;
    accounts[*numAccounts].balance = 0.0;

    (*numAccounts)++;
    printf("Account created successfully. Account number: %d\n", accounts[*numAccounts - 1].accNumber);
}

// Setoran tabungan
void deposit(struct Account accounts[], int numAccounts) {
    int accNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accNumber);

    if (accNumber >= 1 && accNumber <= numAccounts) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);

        accounts[accNumber - 1].balance += amount;
        printf("Amount deposited successfully. New balance: %.2f\n", accounts[accNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

// Penarikan dana dari rekening
void withdraw(struct Account accounts[], int numAccounts) {
    int accNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accNumber);

    if (accNumber >= 1 && accNumber <= numAccounts) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);

        if (accounts[accNumber - 1].balance >= amount) {
            accounts[accNumber - 1].balance -= amount;
            printf("Amount withdrawn successfully. New balance: %.2f\n", accounts[accNumber - 1].balance);
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}

// Pengecekan mutasi rekening Current Balance
void checkBalance(struct Account accounts[], int numAccounts) {
    int accNumber;

    printf("Enter account number: ");
    scanf("%d", &accNumber);

    if (accNumber >= 1 && accNumber <= numAccounts) {
        printf("Account holder: %s\n", accounts[accNumber - 1].accHolder);
        printf("Account balance: %.2f\n", accounts[accNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

int main() {
    struct Account accounts[100]; // Asumsi saja ada 100 rekening
    int numAccounts = 0;
    int choice;

    while (1) {
        printf("\n Bank Github Indonesia"\n);
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                checkBalance(accounts, numAccounts);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
