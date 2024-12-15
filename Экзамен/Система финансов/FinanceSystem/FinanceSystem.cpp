#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

struct Transaction {
    std::string date;
    std::string category;
    double amount;
};

struct Wallet {
    std::string name;
    double balance;
    std::vector<Transaction> transactions;
};

void addWallet(std::vector<Wallet>& wallets) {
    Wallet wallet;
    std::cout << "Введите имя кошелька: ";
    std::cin >> wallet.name;
    std::cout << "Введите начальный баланс: ";
    std::cin >> wallet.balance;
    wallets.push_back(wallet);
    std::cout << "Кошелек добавлен.\n";
}

void addFunds(std::vector<Wallet>& wallets) {
    std::string walletName;
    double amount;
    std::cout << "Введите имя кошелька: ";
    std::cin >> walletName;
    std::cout << "Введите сумму для пополнения: ";
    std::cin >> amount;

    for (auto& wallet : wallets) {
        if (wallet.name == walletName) {
            wallet.balance += amount;
            std::cout << "Баланс успешно пополнен.\n";
            return;
        }
    }
    std::cout << "Кошелек не найден.\n";
}

void addExpense(std::vector<Wallet>& wallets) {
    std::string walletName, category, date;
    double amount;
    std::cout << "Введите имя кошелька: ";
    std::cin >> walletName;
    std::cout << "Введите дату (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "Введите категорию: ";
    std::cin >> category;
    std::cout << "Введите сумму: ";
    std::cin >> amount;

    for (auto& wallet : wallets) {
        if (wallet.name == walletName) {
            if (wallet.balance >= amount) {
                wallet.balance -= amount;
                wallet.transactions.push_back({ date, category, amount });
                std::cout << "Расход добавлен.\n";
            }
            else {
                std::cout << "Недостаточно средств.\n";
            }
            return;
        }
    }
    std::cout << "Кошелек не найден.\n";
}

void generateReport(const std::vector<Wallet>& wallets, const std::string& date) {
    std::map<std::string, double> categoryTotals;
    double totalExpenses = 0;

    for (const auto& wallet : wallets) {
        for (const auto& transaction : wallet.transactions) {
            if (transaction.date == date) {
                categoryTotals[transaction.category] += transaction.amount;
                totalExpenses += transaction.amount;
            }
        }
    }

    std::cout << "\nОтчет за " << date << ":\n";
    for (const auto& [category, total] : categoryTotals) {
        std::cout << "Категория: " << category << ", Сумма: " << total << "\n";
    }
    std::cout << "Общие расходы: " << totalExpenses << "\n";
}

void generateTopExpenses(const std::vector<Wallet>& wallets, const std::string& date) {
    std::vector<Transaction> allTransactions;

    for (const auto& wallet : wallets) {
        for (const auto& transaction : wallet.transactions) {
            if (transaction.date == date) {
                allTransactions.push_back(transaction);
            }
        }
    }

    std::sort(allTransactions.begin(), allTransactions.end(), [](const Transaction& a, const Transaction& b) {
        return a.amount > b.amount;
        });

    std::cout << "\nТОП-3 расходов за " << date << ":\n";
    for (size_t i = 0; i < allTransactions.size() && i < 3; ++i) {
        std::cout << i + 1 << ". Категория: " << allTransactions[i].category
            << ", Сумма: " << allTransactions[i].amount << "\n";
    }
}

void saveReports(const std::vector<Wallet>& wallets, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка при сохранении файла.\n";
        return;
    }

    for (const auto& wallet : wallets) {
        file << "Кошелек: " << wallet.name << ", Баланс: " << wallet.balance << "\n";
        for (const auto& transaction : wallet.transactions) {
            file << "Дата: " << transaction.date << ", Категория: " << transaction.category
                << ", Сумма: " << transaction.amount << "\n";
        }
        file << "\n";
    }
    file.close();
    std::cout << "Отчеты сохранены в " << filename << "\n";
}

int main() {
    std::vector<Wallet> wallets;
    int choice;
    setlocale(LC_ALL, "rus");
    do {
        std::cout << "\nУправление финансами:\n";
        std::cout << "1. Добавить кошелек\n";
        std::cout << "2. Пополнить баланс\n";
        std::cout << "3. Добавить расход\n";
        std::cout << "4. Сформировать отчет\n";
        std::cout << "5. ТОП-3 расходов\n";
        std::cout << "6. Сохранить отчеты\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addWallet(wallets);
            break;
        case 2:
            addFunds(wallets);
            break;
        case 3:
            addExpense(wallets);
            break;
        case 4: {
            std::string date;
            std::cout << "Введите дату (YYYY-MM-DD): ";
            std::cin >> date;
            generateReport(wallets, date);
            break;
        }
        case 5: {
            std::string date;
            std::cout << "Введите дату (YYYY-MM-DD): ";
            std::cin >> date;
            generateTopExpenses(wallets, date);
            break;
        }
        case 6:
            saveReports(wallets, "finance_report.txt");
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}