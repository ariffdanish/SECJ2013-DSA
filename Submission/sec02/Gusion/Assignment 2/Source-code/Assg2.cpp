// Assignment 2 - SECJ2013 - 23241 (Assg2.cpp)
// Group Members:
// 1. Muhammad Iman Firdaus Bin Baharuddin A22EC0216
// 2. Muhammad Ariff Danish Bin Hashnan A22EC0204
// 3. Che Marhumi Bin Che AB Rahim A22EC0147
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;
// Task (Chemi) --------> Function LinkedList & int main (Part LinkedList)



// Task (Ariff) --------> Function Searching & int main (Part Searching)
    vector<Node *> findNode(const string &searchKey, int searchType)
    {
        Node *current = head;
        vector<Node *> matchNode;

        while (current != nullptr)
        {
            bool isMatch = false;
            
            //convert the key to uppercase or lowercase when user accidently enter wrong char
            string lowerSearchKey = searchKey;
            transform(lowerSearchKey.begin(), lowerSearchKey.end(), lowerSearchKey.begin(), ::tolower);

            string lowerName = current->data->getName();
            transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

            if (searchType == 1 && lowerName.find(lowerSearchKey) != string::npos )
            {
                isMatch = true;
            }

            if (searchType == 2 && current->data->getDestination() == searchKey)
            {
                isMatch = true;
            }

            if (searchType == 3 && current->data->getAirlines() == searchKey)
            {
                isMatch = true;
            }

            if (searchType == 4)
            {
                // Extract day, month, and year from the stored date using getdate()
                int storedDate = current->data->getdate();
                int storedYear = storedDate / 10000;
                int storedMonth = (storedDate / 100) % 100;
                int storedDay = storedDate % 100;
                // Extract day, month, and year from the search key
                int searchDay, searchMonth, searchYear;
                char dot1, dot2;
                stringstream dateStream(searchKey);
                dateStream >> searchDay >> dot1 >> searchMonth >> dot2 >> searchYear;

                // Check if the extracted values match
                if (!dateStream.fail() &&
                    dot1 == '.' && dot2 == '.' &&
                    storedDay == searchDay && storedMonth == searchMonth && storedYear == searchYear)
                {
                    isMatch = true;
                }
            }

            if (isMatch)
            {
                matchNode.push_back(current);
            }
            current = current->next;
        }

        return matchNode;
    }

// // Task (Iman) --------> Function Sorting & int main (Part Sorting)




int main()
{



                                                //Task (Ariff) 
///-----------------------------------------------CODE TO START THE SEARCHING IN THE LIST----------------------------------------------------------------///
        case 3: // search
        {
            int searchKey;

            do
            {
                cout << "\n\t\t\t\t   +================== SEARCH MENU ===================+" << endl;
                cout << "\t\t\t\t   +1. \t\tSearch Customer by Name"
                     << "\t\t      +" << endl;
                cout << "\t\t\t\t   +2. \t\tSearch Customer by Destination"
                     << "\t      +" << endl;
                cout << "\t\t\t\t   +3. \t\tSearch Customer by Airline"
                     << "\t      +" << endl;
                cout << "\t\t\t\t   +4. \t\tSearch Customer by Date"
                     << "\t\t      +" << endl;
                cout << "\t\t\t\t   +5. \t\tExit"
                     << "\t\t\t\t      +" << endl;
                cout << "\t\t\t\t   +==================================================+" << endl;
                cout << "\n\n\t\t\t\t\t\tEnter your choice: ";
                cin >> searchKey;

                switch (searchKey)
                {
                case 1:
                {
                    // Search Customer by Name
                    string searchName;
                    cout << "\t\t\t\t\t\tEnter the name to search: ";
                    cin.ignore(); // Clear the newline character from the previous input
                    getline(cin, searchName);

                    vector<Node *> matchNode = custList.findNode(searchName, 1);

                    if (!matchNode.empty())
                    {
                        cout << "\n\n\t\t\t\t\t\tCustomer found:" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                        cout << left << setw(5) << setw(15) << "\t\t\tName"
                             << "Date of Booking"
                             << " \t \tDestination"
                             << "\t    Airlines" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;

                        for (Node *current : matchNode)
                        {
                            cout << "\t\t\t";
                            current->data->printSearch(current->data->getdate());
                        }

                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\t\tCustomer not found." << endl;
                    }
                    break;
                }

                case 2:
                {
                    // Search Customer by destination
                    string searchDest;
                    cout << "\n\t\t\t\t\t\tEnter the destination to search" << endl;
                    cout << "\t\t\t\t\t\t(Attention! Case Sensitive): ";
                    cin.ignore(); // Clear the newline character from the previous input
                    getline(cin, searchDest);

                    vector<Node *> matchNode = custList.findNode(searchDest, 2);

                    if (!matchNode.empty())
                    {
                        cout << "\n\t\t\t\t\t\tCustomer found:" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                        cout << left << setw(5) << setw(15) << "\t\t\tName"
                             << "Date of Booking"
                             << " \t \tDestination"
                             << "\t    Airlines" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;

                        for (Node *current : matchNode)
                        {
                            cout << "\t\t\t";
                            current->data->printSearch(current->data->getdate());
                        }

                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\t\tCustomer not found." << endl;
                    }
                    break;
                }

                case 3:
                {
                    // Search Customer by Airline
                    string searchAir;
                    cout << "\n\t\t\t\t\t\tEnter the Airline to search" << endl;
                    cout << "\t\t\t\t\t\t(Attention! Case Sensitive): ";
                    cin.ignore(); // Clear the newline character from the previous input
                    getline(cin, searchAir);

                    vector<Node *> matchNode = custList.findNode(searchAir, 3);

                    if (!matchNode.empty())
                    {
                        cout << "\n\t\t\t\t\t\tCustomer found:" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                        cout << left << setw(5) << setw(15) << "\t\t\tName"
                             << "Date of Booking"
                             << " \t \tDestination"
                             << "\t    Airlines" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;

                        for (Node *current : matchNode)
                        {
                            cout << "\t\t\t";
                            current->data->printSearch(current->data->getdate());
                        }

                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\t\tCustomer not found." << endl;
                    }
                    break;
                }

                case 4:
                {
                    // Search Customer by Date
                    string searchDate;
                    cout << "\t\t\t\t\t\tEnter the date to search" << endl;
                    cout << "\t\t\t\t\t(in the format dd.mm.yyyy): ";
                    cin >> searchDate;

                    int day, month, year;
                    char dot1, dot2;
                    stringstream dateStream(searchDate);

                    if (!(dateStream >> day >> dot1 >> month >> dot2 >> year) || dot1 != '.' || dot2 != '.' || !dateStream.eof())
                    {
                        cout << "\n\t\t\t\t\t\tInvalid date format." << endl;
                        cout << "\t\t\t\t\t\tPlease enter the date in DD.MM.YYYY format." << endl;
                        break;
                    }
                    vector<Node *> matchNode = custList.findNode(searchDate, 4);

                    if (!matchNode.empty())
                    {
                        cout << "\n\t\t\t\t\t\tCustomer found:" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                        cout << left << setw(5) << setw(15) << "\t\t\tName"
                             << "Date of Booking"
                             << " \t \tDestination"
                             << "\t    Airlines" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;

                        for (Node *current : matchNode)
                        {
                            cout << "\t\t\t";
                            current->data->printSearch(current->data->getdate());
                        }

                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\t\tCustomer not found." << endl;
                    }
                    break;
                }

                case 5:
                    // Exit
                    cout << "\n\n\t\t\t\t\t[Exiting the  search program. Goodbye]!" << endl;
                    break;

                default:
                    cout << "\n\t\t\t\t\t\tInvalid choice. Please enter a valid option." << endl;
                }
            } while (searchKey != 5);
        }
        break;
        ///--------------------------------------------------------END OF CODE TO SEARCH----------------------------------------------------------------------------------///

    return 0;
}
