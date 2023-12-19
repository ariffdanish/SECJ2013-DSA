#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Courier {
private:
    string name, parcelType, source, dest, stat;
    int trackNum;

public:
    Courier(string n = " ", string p = " ", string s = " ", string d = " ", string st = " ", int t = 0)
        : name(n), parcelType(p), source(s), dest(d), stat(st), trackNum(t) {}

    void setName(string n) { name = n; }
    void setType(string p) { parcelType = p; }
    void setSource(string s) { source = s; }
    void setDest(string d) { dest = d; }
    void setStat(string st) { stat = st; }
    void setTrackNum(int t) { trackNum = t; }

    string getName() const { return name; }
    string getType() const { return parcelType; }
    string getSource() const { return source; }
    string getDest() const { return dest; }
    string getStat() const { return stat; }
    int getTrackNum() const { return trackNum; }

    void display() const {
        cout << left << setw(25) << name
             << setw(15) << parcelType
             << setw(15) << source
             << setw(18) << dest
             << setw(16) << stat
             << setw(15) << trackNum << endl;
    }
};

// Merge function for mergesort
template <typename T>
void merge(vector<T>& data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> leftArray(n1);
    vector<T> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = data[left + i];
    }

    for (int j = 0; j < n2; j++) {
        rightArray[j] = data[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i].getTrackNum() <= rightArray[j].getTrackNum()) {
            data[k] = leftArray[i];
            i++;
        } else {
            data[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = rightArray[j];
        j++;
        k++;
    }
}

// Mergesort algorithm
template <typename T>
void mergeSort(vector<T>& data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);

        merge(data, left, mid, right);
    }
}

template <typename T>
int linearSearch(const vector<T>& data, const string& key) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].getName() == key) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

vector<Courier> readData(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        exit(0);
    }

    vector<Courier> couriers;
    string n, p, s, d, st;
    int t;
    while (file >> n >> p >> s >> d >> st >> t) {
        couriers.emplace_back(n, p, s, d, st, t);
    }

    file.close();
    return couriers;
}

void writeData(const string& filename, const vector<Courier>& couriers) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        exit(0);
    }

    for (const Courier& c : couriers) {
        file << c.getName() << " "
             << c.getType() << " "
             << c.getSource() << " "
             << c.getDest() << " "
             << c.getStat() << " "
             << c.getTrackNum() << endl;
    }

    file.close();
}

int main() {
    string filename;
    cout << "Enter the input file name: ";
    cin >> filename;

    vector<Courier> couriers = readData(filename);

    int choice;
    string searchKey;
    int index = -1; // Move the declaration outside the switch statement

    do {
        cout << "\nMenu:\n"
             << "[1] View all couriers\n"
             << "[2] Sort couriers by tracking number (using mergesort)\n"
             << "[3] Search courier by name\n"
             << "[4] Exit\n"
             << "Enter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:
 					cout << "\n| Name              | Parcel Type   | Source         | Destination    | Status          | Tracking Number |\n"
                         << "---------------------------------------------------------------------------------------------------------------------\n";
                for (const Courier& c : couriers) {
                    c.display();
                }
                break;

            case 2:
                mergeSort(couriers, 0, couriers.size() - 1);
                cout << "Couriers sorted by tracking number using mergesort.\n";
                cout << "\n| Name              | Parcel Type   | Source         | Destination    | Status          | Tracking Number |\n"
                     << "---------------------------------------------------------------------------------------------------------------------\n";
                for (const Courier& c : couriers) {
                    c.display();
                }                
                break;

            case 3:
                cout << "Enter the name to search: ";
                cin >> searchKey;
                index = linearSearch(couriers, searchKey);
                if (index != -1) {
                    cout << "Courier found at index " << index << ":\n";
                    cout << "\n| Name              | Parcel Type   | Source         | Destination    | Status          | Tracking Number |\n"
                         << "---------------------------------------------------------------------------------------------------------------------\n";
                    couriers[index].display();
                } else {
                    cout << "name not found.\n";
                }
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    // Save sorted data back to the file
    //writeData(filename, couriers);

    return 0;
}
