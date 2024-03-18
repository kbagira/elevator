#include <bits/stdc++.h>
using namespace std;

void move(int currentFloor, int destination, int passengers) {
    int time = abs(destination - currentFloor) * 10; 
    if (time > 0) {
        cout << "Elevator is moving from floor " << currentFloor << " to floor " << destination << " with " << passengers << " passengers (Time: " << time << " seconds)" << endl;
    }
}
void process(stack<int>& requests, int floor, int maxPassengers, int& passengersInLift) {
    int numPassengers = rand() % (maxPassengers) + 1; 
    if (numPassengers > passengersInLift) { 
        passengersInLift = numPassengers; 
    }
    for (int i = 0; i < numPassengers; ++i) {
        requests.push(floor);
    }
}

void requests(stack<int>& requests, int currentFloor, int maxPassengers, int& totalPassengers, int& minPassengersInLift, int& maxPassengersInLift) {
    while (!requests.empty()) {
        int destination = requests.top();
        if (destination != currentFloor) { 
            int passengers = rand() % maxPassengers + 1; 
            move(currentFloor, destination, passengers);
            totalPassengers += passengers; 
            if (passengers > maxPassengersInLift) { 
                maxPassengersInLift = passengers; 
            }
            if (passengers < minPassengersInLift || minPassengersInLift == 0) { 
                minPassengersInLift = passengers; 
            }
        }
        currentFloor = destination; 
        requests.pop();
    }
}

void simulate(int numFloors, int maxPassengers, int duration) {
    stack<int> elevatorRequests;
    map<int, int> floorCalls;
    int currentFloor = 1;
    int totalSeconds = 0;
    int totalPassengers = 0; 
    int minPassengersInLift = 0; 
    int maxPassengersInLift = 0; 

    srand(time(0));

    cout << "Simulating passenger calls..." << endl;
    while (totalSeconds < duration) {
    int floor = rand() % numFloors + 1;
    if (floor != currentFloor) {
        process(elevatorRequests, floor, maxPassengers, minPassengersInLift);
        ++floorCalls[floor];
        totalSeconds += abs(floor - currentFloor) * 10; 
        currentFloor = floor;
    }

}
     
    cout << "Elevator starts processing requests..." << endl;
    requests(elevatorRequests, currentFloor, maxPassengers, totalPassengers, minPassengersInLift, maxPassengersInLift);
    cout << "Simulation completed." << endl;
    cout << "Analysis:" << endl;
    cout << "Total time needed for all calls: " << totalSeconds << " seconds" << endl;
    cout << "Frequency of calls from each floor:" << endl;
    map<int, int>::iterator it;
    for (it = floorCalls.begin(); it != floorCalls.end(); ++it) {
        if (it->first != currentFloor) { 
            cout << "Floor " << it->first << ": " << it->second << " calls" << endl;
        }
    }

    cout << "Total number of passengers: " << totalPassengers << endl;
    cout << "Maximum number of passengers in the lift: " << maxPassengersInLift << endl;
    cout << "Minimum number of passengers in the lift: " << minPassengersInLift << endl;

    cout << "Thank you for using Elevator Simulation!" << endl;
}

int main() {
    cout << "Welcome to Elevator Simulation!" << endl;
    int numFloors, maxPassengers, durationInMinutes;
    cout << "Number of floors: ";
    cin >> numFloors;
    cout << "Maximum passengers per trip: ";
    cin >> maxPassengers;
    cout << "Simulation duration (in minutes): ";
    cin >> durationInMinutes;
    int durationInSeconds = durationInMinutes * 60; 
    simulate(numFloors, maxPassengers, durationInSeconds);

    return 0;
}



