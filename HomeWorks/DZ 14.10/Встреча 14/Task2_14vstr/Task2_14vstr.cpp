#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip> 
#include <fstream>

// Структура для задания на печать
struct PrintJob {
    std::string user;
    int priority;
    std::string documentName;
    time_t requestTime;

    // Конструктор задания
    PrintJob(std::string user, int priority, std::string documentName)
        : user(user), priority(priority), documentName(documentName) {
        requestTime = std::time(nullptr);
    }
};

// Компаратор для очере
// ди с приоритетом
struct ComparePriority 
{
    bool operator()(const PrintJob& a, const PrintJob& b) {
        // Приоритетные задания будут идти в начале (наибольший приоритет - выше в очереди)
        return a.priority < b.priority;
    }
};

// Очередь печати
std::priority_queue<PrintJob, std::vector<PrintJob>, ComparePriority> printQueue;
// Очередь для статистики
std::vector<PrintJob> printLog;

// Функция для добавления задания в очередь печати
void addPrintJob(const std::string& user, int priority, const std::string& documentName) {
    PrintJob job(user, priority, documentName);
    printQueue.push(job);
    std::cout << "Задание от пользователя " << user << " добавлено в очередь.\n";
}

// Функция для форматирования времени
std::string formatTime(time_t time) {
    std::tm* tmPtr = std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Функция для выполнения задания печати
void processPrintJob()
{
    if (printQueue.empty()) 
    {
        std::cout << "Очередь пуста, нет заданий на печать.\n";
        return;
    }

    // Извлечение задания из очереди
    PrintJob job = printQueue.top();
    printQueue.pop();

    // Логирование выполненного задания
    printLog.push_back(job);

    // Вывод информации о выполнении
    std::cout << "Печатается документ: " << job.documentName
        << " от пользователя: " << job.user
        << " с приоритетом: " << job.priority
        << " время запроса: " << formatTime(job.requestTime) << "\n";
}

// Функция для вывода статистики
void printStatistics() {
    if (printLog.empty()) {
        std::cout << "Статистика пуста, нет выполненных заданий.\n";
        return;
    }

    std::cout << "\n--- Статистика печати ---\n";
    for (const auto& job : printLog) {
        std::cout << "Документ: " << job.documentName
            << ", Пользователь: " << job.user
            << ", Приоритет: " << job.priority
            << ", Время запроса: " << formatTime(job.requestTime) << "\n";
    }
    std::cout << "-------------------------\n";
}

// Главное меню программы
void menu() {
    int choice;
    while (true) {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Добавить задание на печать\n";
        std::cout << "2. Обработать задание\n";
        std::cout << "3. Показать статистику\n";
        std::cout << "4. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string user, documentName;
            int priority;
            std::cout << "Введите имя пользователя: ";
            std::cin >> user;
            std::cout << "Введите приоритет (чем выше число, тем выше приоритет): ";
            std::cin >> priority;
            std::cout << "Введите название документа: ";
            std::cin >> documentName;
            addPrintJob(user, priority, documentName);
            break;
        }
        case 2:
            processPrintJob();
            break;
        case 3:
            printStatistics();
            break;
        case 4:
            std::cout << "Выход из программы.\n";
            return;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}