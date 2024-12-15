
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <iomanip>

struct Wallet {
    std::string name;
    double balance;
};

struct Expense {
    std::string category;
    double amount;
    std::string date; 
};

std::string getCurrentDate() {
    return "2024-12-15"; 
}

void saveToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        std::cout << "The data is saved to a file: " << filename << std::endl;
    }
    else {
        std::cout << "Error saving the file!" << std::endl;
    }
}

class FinanceManager {
private:
    std::vector<Wallet> wallets;
    std::vector<Expense> expenses;

public:
    void addWallet() {
        Wallet wallet;
        std::cout << "Enter the name of the wallet/card: ";
        std::cin >> wallet.name;
        std::cout << "Enter the initial balance: ";
        std::cin >> wallet.balance;
        wallets.push_back(wallet);
        std::cout << "Wallet/card added!" << std::endl;
    }

    void topUpWallet() {
        std::string name;
        double amount;
        std::cout << "Enter the name of the wallet/card: ";
        std::cin >> name;
        std::cout << "Enter the deposit amount: ";
        std::cin >> amount;

        for (auto& wallet : wallets) {
            if (wallet.name == name) {
                wallet.balance += amount;
                std::cout << "The balance has been replenished!" << std::endl;
                return;
            }
        }
        std::cout << "Wallet/card not found!" << std::endl;
    }

    void addExpense() {
        Expense expense;
        std::cout << "Enter the expense category: ";
        std::cin >> expense.category;
        std::cout << "Enter the amount of the expense: ";
        std::cin >> expense.amount;
        expense.date = getCurrentDate();
        expenses.push_back(expense);

        std::cout << "Consumption has been added!" << std::endl;
    }

    void showReport(const std::string& period) {
        std::map<std::string, double> categoryTotals;
        double total = 0;

        for (const auto& expense : expenses) {
            if (period == "day" && expense.date == getCurrentDate()) {
                categoryTotals[expense.category] += expense.amount;
                total += expense.amount;
            }
        }

        std::cout << "Report for " << period << ":" << std::endl;
        for (const auto& [category, amount] : categoryTotals) {
            std::cout << category << ": " << amount << std::endl;
        }
        std::cout << "Total amount: " << total << std::endl;
    }

    void showTopExpenses(const std::string& period, int topN) {
        std::vector<Expense> filteredExpenses;

        for (const auto& expense : expenses) {
            if (period == "day" && expense.date == getCurrentDate()) {
                filteredExpenses.push_back(expense);
            }
        }

        sort(filteredExpenses.begin(), filteredExpenses.end(), [](const Expense& a, const Expense& b) {
            return a.amount > b.amount;
            });

        std::cout << "top-" << topN << " costs for " << period << ":" << std::endl;
        for (int i = 0; i < std::min(topN, (int)filteredExpenses.size()); ++i) {
            std::cout << filteredExpenses[i].category << ": " << filteredExpenses[i].amount << std::endl;
        }
    }
};

int main() {
    FinanceManager manager;
    int choice;

    do {
        std::cout << "\nMenu:\n"
            << "1. Add a wallet/card\n"
            << "2. Top up your wallet/card\n"
            << "3. Add Expense\n"
            << "4. Show the report (day)\n"
            << "5. TOP 3 costs (day)\n"
            << "0. Exit\n"
            << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addWallet();
            break;
        case 2:
            manager.topUpWallet();
            break;
        case 3:
            manager.addExpense();
            break;
        case 4:
            manager.showReport("day");
            break;
        case 5:
            manager.showTopExpenses("day", 3);
            break;
        case 0:
            std::cout << "Exit the program." << std::endl;
            break;
        default:
            std::cout << "Wrong choice. Try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}