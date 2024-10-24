#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <ctime>

using namespace std;


struct PrintJob 
{
    string user;
    int priority;
    time_t requestTime;

    bool operator<(const PrintJob& other) const 
    {
        return priority < other.priority;
    }
};


struct PrintStat {
    string user;      
    time_t printTime; 
};


priority_queue<PrintJob> printQueue;


queue<PrintStat> printStats;


void addPrintJob(const string& user, int priority) 
{
    time_t currentTime = time(nullptr);
    printQueue.push({ user, priority, currentTime });
    cout << "Пользователь " << user << " добавил задание на печать с приоритетом " << priority << endl;
}


void processPrintJob() 
{
    if (printQueue.empty())
    {
        cout << "Нет заданий на печать в очереди." << endl;
        return;
    }

    PrintJob job = printQueue.top();
    printQueue.pop();

    time_t currentTime = time(nullptr);
    cout << "Печать задания пользователя " << job.user << " с приоритетом " << job.priority << endl;

    printStats.push({ job.user, currentTime });
}


void printStatistics() 
{
    if (printStats.empty())
    {
        cout << "Статистика печати пуста." << endl;
        return;
    }

    cout << "Статистика печати:" << endl;
    int count = 1;
    while (!printStats.empty()) 
    {
        PrintStat stat = printStats.front();
        printStats.pop();
        cout << count << ". Пользователь: " << stat.user
            << ", Время печати: " << ctime(&stat.printTime);
        count++;
    }
}

int main() {
    int choice;
    string user;
    int priority;
    setlocale(LC_ALL, "rus");
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить задание на печать\n";
        cout << "2. Обработать задание на печать\n";
        cout << "3. Показать статистику печати\n";
        cout << "4. Выйти\n";
        cout << "Введите номер действия: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите имя пользователя: ";
            cin >> user;
            cout << "Введите приоритет задания (целое число): ";
            cin >> priority;
            addPrintJob(user, priority);
            break;
        case 2:
            processPrintJob();
            break;
        case 3:
            printStatistics();
            break;
        case 4:
            cout << "Выход из программы." << endl;
            return 0;
        default:
            cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }
    return 0;
}