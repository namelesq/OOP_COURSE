#include <iostream>
#include <queue>
#include <random>
#include <chrono>


double generateExponential(double lambda)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<> dis(lambda);
    return dis(gen);
}

struct Passenger
{
    double arrivalTime;
};
struct Bus 
{
    double arrivalTime; 
    int availableSeats; 
};

int main() {

    double averagePassengerArrivalTime = 5.0; 
    double averageBusArrivalTime = 15.0;      
    int maxPeopleOnStop = 10;                 
    int simulationTime = 480;                 
    bool isTerminal = false;                  

    std::queue<Passenger> stopQueue;              
    double currentTime = 0.0;                 
    double totalWaitingTime = 0.0;            
    int totalPassengers = 0;                  
    int peopleLeftDueToFullBus = 0;           

    
    double passengerArrivalRate = 1.0 / averagePassengerArrivalTime;
    double busArrivalRate = 1.0 / averageBusArrivalTime;

   
    double nextPassengerArrival = generateExponential(passengerArrivalRate);
    double nextBusArrival = generateExponential(busArrivalRate);

    while (currentTime < simulationTime)
    {
        
        if (nextPassengerArrival < nextBusArrival)
        {
            currentTime = nextPassengerArrival;
            if (stopQueue.size() < maxPeopleOnStop) 
            {
                stopQueue.push({ currentTime });
            }
            
            nextPassengerArrival = currentTime + generateExponential(passengerArrivalRate);
        }
        else 
        { 
            currentTime = nextBusArrival;
            int availableSeats = isTerminal ? 15 : rand() % 16; 
            int passengersToBoard = std::min(static_cast<int>(stopQueue.size()), availableSeats);

            
            for (int i = 0; i < passengersToBoard; ++i)
            {
                Passenger passenger = stopQueue.front();
                stopQueue.pop();
                totalWaitingTime += currentTime - passenger.arrivalTime;
                totalPassengers++;
            }

            peopleLeftDueToFullBus += std::max(0, static_cast<int>(stopQueue.size()) - availableSeats);

            nextBusArrival = currentTime + generateExponential(busArrivalRate);
        }
    }

    double averageWaitingTime = totalPassengers > 0 ? totalWaitingTime / totalPassengers : 0.0;
    std::cout << "Average passenger waiting time: " << averageWaitingTime << " minutes." << std::endl;
    std::cout << "Number of passengers served: " << totalPassengers << std::endl;
    std::cout << "The number of passengers remaining due to overcrowding: " << peopleLeftDueToFullBus << std::endl;

    return 0;
}