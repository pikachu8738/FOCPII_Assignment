#include <iostream>

using namespace std;

class MovieTicket {
private:
    static const int MAX_USERS = 1000;
    static const int MAX_MOVIES = 1000;
    static const int MAX_TICKETS = 100;

    bool booked[MAX_USERS + 1][MAX_MOVIES + 1]; // user x movie
    int tickets[MAX_MOVIES + 1]; // tickets booked per movie

public:
    MovieTicket() {
        memset(booked, false, sizeof(booked));
        memset(tickets, 0, sizeof(tickets));
    }

    bool BOOK(int user, int movie) {
        if (booked[user][movie]) return false;

        if (tickets[movie] >= MAX_TICKETS) return false;

        booked[user][movie] = true;
        tickets[movie]++;
        return true;
    }

    bool CANCEL(int user, int movie) {
        if (!booked[user][movie]) return false;

        booked[user][movie] = false;
        tickets[movie]--;
        return true;
    }

    bool IS_BOOKED(int user, int movie) {
        return booked[user][movie];
    }

    int AVAILABLE_TICKETS(int movie) {
        return MAX_TICKETS - tickets[movie];
    }
};

int main() {
    int Q;
    cin >> Q;

    MovieTicket system;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.BOOK(X, Y) ? "true" : "false") << endl;

        } else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.CANCEL(X, Y) ? "true" : "false") << endl;

        } else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.IS_BOOKED(X, Y) ? "true" : "false") << endl;

        } else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << system.AVAILABLE_TICKETS(Y) << endl;
        }
    }

    return 0;
}