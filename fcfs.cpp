#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    queue<string> customerQueue;
    int choice;
    string name;
    string lastMessage = "";

    while (true) {
        clearScreen();
        cout << "Electronic Queuing System (FIFO - First Come First Serve)" << endl;
        
        if (!lastMessage.empty()) {
            cout << "\n" << lastMessage << endl;
        }
        
        cout << "\nMenu:" << endl;
        cout << "1. Add customer to queue" << endl;
        cout << "2. Serve next customer" << endl;
        cout << "3. Display current queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                customerQueue.push(name);
                lastMessage = name + " has been added to the queue.";
                break;
            case 2:
                if (!customerQueue.empty()) {
                    lastMessage = "Serving: " + customerQueue.front();
                    customerQueue.pop();
                } else {
                    lastMessage = "Queue is empty. No customers to serve.";
                }
                break;
            case 3:
                if (!customerQueue.empty()) {
                    string queueList = "Current queue: ";
                    queue<string> temp = customerQueue;
                    while (!temp.empty()) {
                        queueList += temp.front() + " ";
                        temp.pop();
                    }
                    lastMessage = queueList;
                } else {
                    lastMessage = "Queue is empty.";
                }
                break;
            case 4:
                clearScreen();
                cout << "Exiting the system." << endl;
                return 0;
            default:
                lastMessage = "Invalid choice. Please try again.";
        }
    }

    return 0;
}