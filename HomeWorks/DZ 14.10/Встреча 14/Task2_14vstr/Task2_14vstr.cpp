#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>


struct PrintJob 
{
    std::string user;
    int priority;
    time_t requestTime;

    PrintJob(const std::string& user, int priority)
        : user(user), priority(priority)
    {
        requestTime = std::time(nullptr);
    }

    bool operator<(const PrintJob& other) const
    {
        return priority < other.priority;
    }
};


struct PrintStatistics 
{
    std::string user;
    time_t printTime;

    PrintStatistics(const std::string& user, time_t printTime)
        : user(user), printTime(printTime) {}
};


class Printer 
{
private:
    std::priority_queue<PrintJob> printQueue; 
    std::vector<PrintStatistics> statistics;  

public:

    void addPrintJob(const std::string& user, int priority)
    {
        printQueue.emplace(user, priority);
        std::cout << "Added print job for user: " << user << " with priority: " << priority << std::endl;
    }

    void processPrintJob()
    {
        if (printQueue.empty())
        {
            std::cout << "No print jobs in the queue." << std::endl;
            return;
        }

        PrintJob job = printQueue.top();
        printQueue.pop();


        time_t currentTime = std::time(nullptr);
        statistics.emplace_back(job.user, currentTime);

        std::tm localTime;
        localtime_s(&localTime, &currentTime); 

        std::cout << "Printing job for user: " << job.user
            << " with priority: " << job.priority
            << " at " << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << std::endl;
    }

    void showStatistics() const 
    {
        if (statistics.empty()) 
        {
            std::cout << "No completed print jobs." << std::endl;
            return;
        }

        std::cout << "Printing Statistics:" << std::endl;
        for (const auto& stat : statistics) 
        {
            std::tm localTime;
            localtime_s(&localTime, &stat.printTime); 

            std::cout << "User: " << stat.user
                << ", Time: " << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << std::endl;
        }
    }
};

int main() {
    Printer printer;
    int choice;

    while (true) 
    {
        std::cout << "\n1. Add print job\n2. Process print job\n3. Show statistics\n4. Exit\nChoose an option: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string user;
            int priority;
            std::cout << "Enter user name: ";
            std::cin >> user;
            std::cout << "Enter priority (higher number = higher priority): ";
            std::cin >> priority;
            printer.addPrintJob(user, priority);
        }
        else if (choice == 2) 
        {
            printer.processPrintJob();
        }
        else if (choice == 3) 
        {
            printer.showStatistics();
        }
        else if (choice == 4) 
        {
            break;
        }
        else 
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}