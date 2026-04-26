#include <iostream>
using namespace std;

class Bank {
private:
    static const int MAX_USERS = 100000;

    bool exists[MAX_USERS + 1];   // does user exist?
    long long balance[MAX_USERS + 1]; // user balance

public:
    Bank() {
        memset(exists, false, sizeof(exists));
        memset(balance, 0, sizeof(balance));
    }

    bool CREATE(int user, long long amount) {
        if (!exists[user]) {
            exists[user] = true;
            balance[user] = amount;
            return true; // new account created
        } else {
            balance[user] += amount;
            return false; // already existed
        }
    }

    bool DEBIT(int user, long long amount) {
        if (!exists[user] || balance[user] < amount) {
            return false;
        }
        balance[user] -= amount;
        return true;
    }

    bool CREDIT(int user, long long amount) {
        if (!exists[user]) {
            return false;
        }
        balance[user] += amount;
        return true;
    }

    long long BALANCE(int user) {
        if (!exists[user]) {
            return -1;
        }
        return balance[user];
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank system;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (system.CREATE(X, Y) ? "true" : "false") << endl;

        } else if (query == "DEBIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (system.DEBIT(X, Y) ? "true" : "false") << endl;

        } else if (query == "CREDIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (system.CREDIT(X, Y) ? "true" : "false") << endl;

        } else if (query == "BALANCE") {
            int X;
            cin >> X;
            cout << system.BALANCE(X) << endl;
        }
    }

    return 0;
}