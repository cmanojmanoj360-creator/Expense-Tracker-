#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Expense {
    string category;
    double amount;
};

int main() {
    vector<Expense> expenses;
    int choice;

    do {
        cout << "\n=== EXPENSE TRACKER ===\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Total Expenses\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            Expense e;

            cout << "Enter category: ";
            cin >> ws;
            getline(cin, e.category);

            cout << "Enter amount: ";
            if (!(cin >> e.amount) || e.amount <= 0) {
                cout << "Invalid amount!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            expenses.push_back(e);
            cout << "Expense added successfully!\n";

        } else if (choice == 2) {
            if (expenses.empty()) {
                cout << "No expenses recorded.\n";
            } else {
                cout << fixed << setprecision(2);
                for (size_t i = 0; i < expenses.size(); i++) {
                    cout << i + 1 << ". "
                         << expenses[i].category << " - Rs. "
                         << expenses[i].amount << '\n';
                }
            }

        } else if (choice == 3) {
            double total = 0;
            for (const Expense &e : expenses) {
                total += e.amount;
            }
            cout << fixed << setprecision(2);
            cout << "Total expenses: Rs. " << total << '\n';

        } else if (choice != 4) {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    cout << "Thank you for using Expense Tracker!\n";
    return 0;
}
