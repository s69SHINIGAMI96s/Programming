/*******************************
* Автор:    Богданов.К.А.      *
* Вариант:  2                  *
* Название: Работа с файлами   *
********************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Passenger {
    string surname;
    string name;
    string patronymic;
    int numItems;
    double weight;
};

    int main() {

        ifstream file("Passengers.txt");
        if (!file) {
            cerr << "File opening error." << endl;
        }

        Passenger object;
        double threshold;
        
        cout << "Enter the minimum baggage weight threshold: ";
        cin >> threshold;

        int totalItems = 0;
        double totalWeight = 0;
        Passenger heaviestPassenger;
        double maxWeight = 0;

        while (file >> object.surname >> object.name >> object.patronymic >> object.numItems >> object.weight) {
            totalWeight += object.weight;
            
            if (object.weight > threshold) {
                cout << object.surname << " " << object.name << " " << object.patronymic << endl;
                totalItems += object.numItems;
            }
            
            if (object.weight > maxWeight) {
                maxWeight = object.weight;
                heaviestPassenger = object;
            }
        }
        file.close();

        cout << "The total number of items carried by passengers with baggage is more than " 
        << threshold << " kg: " << totalItems << endl
        << "Total weight of all baggage: " << totalWeight << " kg" << endl
        << "The passenger with the heaviest luggage: " 
                << heaviestPassenger.surname << " " 
                << heaviestPassenger.name << " " 
                << heaviestPassenger.patronymic 
                << ", baggage weight: " << maxWeight << " kg" << endl;

        return 0;
    }
