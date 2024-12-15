#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

enum Actions
{
    ADD_WALLET = 1,
    ADD_FUNDS = 2,
    ADD_EXPENSE = 3,
    GENERATE_REPORT = 4,
    GENERATE_TOP_EXPENSES = 5,
    SAVE_REPORTS = 6,
    EXIT = 0
};

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
    std::cout << "Кошелек добавлен." << std::endl;
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
            std::cout << "Баланс успешно пополнен." << std::endl;
            return;
        }
    }
    std::cout << "Кошелек не найден." << std::endl;
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
                std::cout << "Расход добавлен." << std::endl;
            }
            else {
                std::cout << "Недостаточно средств." << std::endl;
            }
            return;
        }
    }
    std::cout << "Кошелек не найден."<<std::endl;
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

    std::cout << std::endl<< "Отчет за " << date << ":" << std::endl;
    for (const auto& [category, total] : categoryTotals) {
        std::cout << "Категория: " << category << ", Сумма: " << total << std::endl;
    }
    std::cout << "Общие расходы: " << totalExpenses << std::endl;
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

    std::cout << "\nТОП-3 расходов за " << date << ":"<<std::endl;
    for (size_t i = 0; i < allTransactions.size() && i < 3; ++i) {
        std::cout << i + 1 << ". Категория: " << allTransactions[i].category
            << ", Сумма: " << allTransactions[i].amount << std::endl;
    }
}

void saveReports(const std::vector<Wallet>& wallets, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка при сохранении файла." << std::endl;
        return;
    }

    for (const auto& wallet : wallets) {
        file << "Кошелек: " << wallet.name << ", Баланс: " << wallet.balance << std::endl;
        for (const auto& transaction : wallet.transactions) {
            file << "Дата: " << transaction.date << ", Категория: " << transaction.category
                << ", Сумма: " << transaction.amount << std::endl;
        }
        file << std::endl;
    }
    file.close();
    std::cout << "Отчеты сохранены в " << filename << std::endl;
}

int main() {
    std::vector<Wallet> wallets;
    int choice;
    setlocale(LC_ALL, "rus");
    do {
        std::cout << std::endl<< "Управление финансами:" << std::endl;
        std::cout << "1. Добавить кошелек" << std::endl;
        std::cout << "2. Пополнить баланс" << std::endl;
        std::cout << "3. Добавить расход" << std::endl;
        std::cout << "4. Сформировать отчет" << std::endl;
        std::cout << "5. ТОП-3 расходов" << std::endl;
        std::cout << "6. Сохранить отчеты" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case ADD_WALLET:
            addWallet(wallets);
            break;
        case ADD_FUNDS:
            addFunds(wallets);
            break;
        case ADD_EXPENSE:
            addExpense(wallets);
            break;
        case GENERATE_REPORT:
        {
            std::string date;
            std::cout << "Введите дату (YYYY-MM-DD): ";
            std::cin >> date;
            generateReport(wallets, date);
            break;
        }
        case GENERATE_TOP_EXPENSES: 
        {
            std::string date;
            std::cout << "Введите дату (YYYY-MM-DD): ";
            std::cin >> date;
            generateTopExpenses(wallets, date);
            break;
        }
        case SAVE_REPORTS:
            saveReports(wallets, "finance_report.txt");
            break;
        case EXIT:
            std::cout << "Выход из программы."<<std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова."<<std::endl;
        }
    } while (choice != 0);

    return 0;
}