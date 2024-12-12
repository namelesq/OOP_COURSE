#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>

class Expense {
public:
    std::string category;
    double amount;

    Expense(const std::string& cat, double amt) : category(cat), amount(amt) {}
};

class Wallet {
private:
    std::string name;
    double balance;

public:
    Wallet(const std::string& walletName, double initialBalance = 0.0)
        : name(walletName), balance(initialBalance) {}

    void addFunds(double amount) {
        balance += amount;
    }

    bool spendFunds(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }

    std::string getName() const {
        return name;
    }
};

class FinanceManager {
private:
    std::vector<Wallet> wallets;
    std::vector<Expense> expenses;

public:
    void addWallet(const std::string& name, double initialBalance = 0.0) {
        wallets.emplace_back(name, initialBalance);
    }

    bool addFundsToWallet(const std::string& name, double amount) {
        for (auto& wallet : wallets) {
            if (wallet.getName() == name) {
                wallet.addFunds(amount);
                return true;
            }
        }
        return false;
    }

    bool addExpense(const std::string& walletName, const std::string& category, double amount) {
        for (auto& wallet : wallets) {
            if (wallet.getName() == walletName && wallet.spendFunds(amount)) {
                expenses.emplace_back(category, amount);
                return true;
            }
        }
        return false;
    }

    void generateReport(const std::string& period) {
        std::map<std::string, double> categoryTotals;

        for (const auto& expense : expenses) {
            categoryTotals[expense.category] += expense.amount;
        }

        std::cout << "Report for period: " << period << std::endl;
        for (const auto& category : categoryTotals) {
            std::cout << "Category: " << category.first << ", Total: " << category.second << std::endl;
        }
    }

    void generateTopExpenses(const std::string& period, size_t topCount = 3) {
        std::vector<Expense> sortedExpenses = expenses;

        std::sort(sortedExpenses.begin(), sortedExpenses.end(), [](const Expense& a, const Expense& b) {
            return a.amount > b.amount;
            });

        std::cout << "Top " << topCount << " expenses for period: " << period << std::endl;
        for (size_t i = 0; i < std::min(topCount, sortedExpenses.size()); ++i) {
            std::cout << i + 1 << ". Category: " << sortedExpenses[i].category
                << ", Amount: " << sortedExpenses[i].amount << std::endl;
        }
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Wallets:\n";
            for (const auto& wallet : wallets) {
                file << "Name: " << wallet.getName() << ", Balance: " << wallet.getBalance() << "\n";
            }

            file << "\nExpenses:\n";
            for (const auto& expense : expenses) {
                file << "Category: " << expense.category << ", Amount: " << expense.amount << "\n";
            }

            file.close();
        }
    }
};

int main() {
    FinanceManager manager;

    manager.addWallet("Debit Card", 1000.0);
    manager.addWallet("Credit Card", 500.0);

    manager.addFundsToWallet("Debit Card", 200.0);

    manager.addExpense("Debit Card", "Food", 50.0);
    manager.addExpense("Debit Card", "Entertainment", 100.0);
    manager.addExpense("Credit Card", "Travel", 300.0);

    manager.generateReport("Week");

    manager.generateTopExpenses("Week");

    manager.saveToFile("report.txt");

    return 0;
}