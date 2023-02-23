#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Grocery {
private: // private
    map < string, int > items; // map used to store key value pair

public: // public
    void readFile(string file) { // read file method
        ifstream fileInput; // ifstream allows us to read information from a file
        fileInput.open(file); // open file

        if (fileInput.is_open()) { // if file opened successfully
            string item;
            while (fileInput >> item) { // read information into fileInput
                items[item]++; // adds information line by line
            }
            fileInput.close(); // close file
        }
        else {
            cout << "Can't open" << endl; // open file failed
        }
    }

    void writeFile(string file) { // write file method
        ofstream outputFile; // of stream allows us to write information to a file
        outputFile.open(file); // open file

        if (outputFile.is_open()) { // if file opened successfully
            for (auto const& item : items) { // constant keyword, keeps me from modifying it
                outputFile << item.first << " " << item.second << endl; // output to file
            }
            outputFile.close(); // close file
        }
        else {
            cout << "Can't open" << endl; // unable to open file
        }
    }

    int findItem(string item) {
        if (items.count(item) > 0) { // count how many times an item is in the list
            return items[item];
        }
        else {
            return 0;
        }
    }

    void printFrequency() {
        for (auto const& item : items) {
            cout << item.first << " " << item.second << endl; // outputs the food and how many times it occurs in the list
        }
    }

    void printHistogram() {
        for (auto const& item : items) {
            cout << item.first << " "; // outputs food
            for (int i = 0; i < item.second; i++) { // outputs amount of times the food is listed, using asterisks 
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    Grocery list;
    list.readFile("CS210_Project_Three_Input_File.txt"); // calls method to read file
    list.writeFile("frequency.dat"); // calls method to write to file

    int option;
    string item;
    do { //do while loop
        cout << "1. Find item frequency" << endl; // menu
        cout << "2. Print the frequency of all items" << endl;
        cout << "3. Print a histogram of all items" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option) { // allows the variable to be compared to the values of each case
        case 1: // Find item frequency
            cout << "Enter item: ";
            cin >> item;
            cout << "Frequency: " << list.findItem(item) << endl;
            break;
        case 2: // Print the frequency of all items
            list.printFrequency();
            break;
        case 3: // Print a histogram of all items
            list.printHistogram();
            break;
        case 4: // Exit
            break;
        default: // Wrong input
            cout << "Try again" << endl;
            break;
        }
    } while (option != 4); // loop until 4 is pressed

    return 0;
}
