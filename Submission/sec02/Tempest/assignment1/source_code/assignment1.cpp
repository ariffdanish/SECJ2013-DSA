#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class task
{
private:
    string task;
    string day;
    string month;
    string year;
    string status;
    string date;

public:
    void display();
    void settask(string t) { task = t; }
    void setday(string d) { day = d; }
    void setmonth(string m) { month = m; }
    void setyear(string y) { year = y; }
    void setstatus(string s) { status = s; }
    string gettask() const { return task; }
    string getday() const { return day; }
    string getmonth() const { return month; }
    string getyear() const { return year; }
    string getstatus() const { return status; }
};

void task::display()
{

    cout << left << setw(40) << task;
    cout << left << setw(2) << "|";
    cout << left << setw(20) << day + "-" + month + "-" + year;
    cout << left << setw(2) << "|";
    cout << left << setw(10) << status << endl;
}

vector<int> SequenceSearchByTask(const string &key, const task T[], int size)//searching sequence by task
{
}

vector<int> SequenceSearchByDate(const string &key, const task T[], int size)//searching sequence by date
{
   
}

vector<int> SequenceSearchByStatus(const string &key, const task T[], int size)//searching sequence by status
{

}

int partitionByTaskasc(task T[], int first, int last)//partion task ascending
{
    string pivot= T[last].gettask();
    int i=(first - 1);

    for(int j= first; j<=last-1 ; j++)
    {
        if (T[j].gettask()<pivot)
        {
            i++;
            swap(T[i], T[j]);
        }
    }

    swap(T[i +1], T[last]);
    return (i+1);

}

void quicksortByTaskasc(task T[], int first, int last)//quicksort task ascending
{
    if (first<last)
    {
        int pi= partitionByTaskasc(T, first, last);
        quicksortByTaskasc(T,first, pi - 1);
        quicksortByTaskasc(T,pi + 1, last);
    }

}

int partitionByDateasc(task T[], int first, int last)//partion date ascending
{
    string pivot=T[last].getyear() + T[last].getmonth() + T[last].getday();
    int i=(first-1);

    for (int j=first; j<=last-1; j++)
    {
        string currentDate=T[j].getyear() + T[j].getmonth() + T[j].getday();
        if (currentDate<pivot)
        {
            i++;
            swap(T[i],T[j]);
        }
    }
    swap(T[i+1], T[last]);
    return (i+1);

}

void quicksortByDateasc(task T[], int first, int last)//quicksort date ascending
{
    if (first<last)
    {
        int pi=partitionByDateasc(T,first,last);
        quicksortByDateasc(T,first,pi-1);
        quicksortByDateasc(T,pi+1,last);
    }

}

int partitionByStatusasc(task T[], int first, int last)//partion status ascending
{
    string pivot = T[last].getstatus();
    int i = (first - 1);

    for (int j=first; j<=last-1;j++)
    {
        if(T[j].getstatus()<pivot)
        {
            i++;
            swap(T[i],T[j]);
        }
    }

    swap(T[i+1],T[last]);
    return (i+1);

}

void quicksortByStatusasc(task T[], int first, int last)//quicksort status ascending
{
    if(first<last)
    {
        int pi = partitionByStatusasc(T, first, last);
        quicksortByStatusasc(T, first, pi - 1);
        quicksortByStatusasc(T,pi + 1, last);
    }

}

int partitionByTaskdec(task T[], int first, int last)//partion task descending
{
    string pivot = T[last].gettask();
    int i = (first - 1);
    
    for (int j=first; j<=last -1; j++)
    {
        if(T[j].gettask()>pivot)
        {
            i++;
            swap(T[i], T[j]);
        }
    }
    swap(T[i+1],T[last]);
    return (i+1);

}

void quicksortByTaskdec(task T[], int first, int last)//quicksort task descending
{
    if (first<last)
    {
        int pi= partitionByTaskdec(T,first,last);
        quicksortByTaskdec(T,first,pi-1);
        quicksortByTaskdec(T,pi + 1, last);

    }

}

int partitionByDatedec(task T[], int first, int last)//partion date descending
{
    string pivot=T[last].getyear() + T[last].getmonth() + T[last].getday();
    int i=(first - 1);

    for (int j= first; j<=last - 1; j++)
    {
        string currentDate= T[j].getyear() + T[j].getmonth() + T[j].getday();
        if (currentDate < pivot)
        {
            i++;

            swap(T[i], T[j]);
        }
    }

    swap(T[i + 1], T[last]);
    return (i+1);


}

void quicksortByDatedec(task T[], int first, int last)//quicksort date descending
{
    if(first<last)
    {
        int pi = partitionByDateasc(T,first,last);
        quicksortByDatedec(T,first,pi - 1);
        quicksortByDatedec(T,pi + 1, last);
    }

}

int partitionByStatusdec(task T[], int first, int last)//partion status descending
{
    string pivot= T[last].getstatus();
    int i=(first - 1);

    for(int j=first;j<=last - 1; j++)
    {
        if(T[j].getstatus()>pivot)
        {
            i++;
            swap(T[i], T[j]);
        }
    }
    swap(T[i+1], T[last]);
    return(i+1);


}

void quicksortByStatusdec(task T[], int first, int last)//quicksort status descending
{
    if(first<last)
    {
        int pi=partitionByStatusdec(T, first, last);
        quicksortByStatusdec(T,first,pi - 1);
        quicksortByStatusdec(T,pi + 1,last);

    }

}

int main()
{
    int opt, ch;

    fstream input("task.txt", ios ::in);
    string tasks, status, date;
    string day, month, year;
    task t[5];

    for (int a = 0; a < 5; a++)
    {
        getline(input >> ws, tasks, '/');
        getline(input, day, '-');
        getline(input, month, '-');
        getline(input, year, '(');
        getline(input, status, ')');
        t[a].settask(tasks);
        t[a].setday(day);
        t[a].setmonth(month);
        t[a].setyear(year);
        t[a].setstatus(status);
    }

    input.close();

    cout << left << setw(40) << "TASK";
    cout << left << setw(2) << "|";
    cout << left << setw(20) << "DAY";
    cout << left << setw(2) << "|";
    cout << left << setw(10) << "STATUS" << endl
         << endl;
    for (int i = 0; i < 5; ++i)
    {
        t[i].display();
    }
    cout << endl
         << endl;

    do
    {
        cout << "<<< OPERATION PROCESS >>>" << endl;
        cout << "[1] SORTING PROCESS \n"
             << "[2] SEARCHING PROCESS \n"
             << "[3] EXIT \n"
             << endl;

        cout << "Enter your choice: ";
        cin >> opt;
        cout << endl
             << endl;

        switch (opt)
        {
        case 1:
        {
            cout << "<<< SORTING PROCESS >>>" << endl;
            cout << "[1] BY ASCENDING ALPHABET \n"
                 << "[2] BY ASCENDING DATE \n"
                 << "[3] BY ASCENDING STATUS \n"
                 << "[4] BY DESCENDING ALPHABET \n"
                 << "[5] BY DESCENDING DATE \n"
                 << "[6] BY DESCENDING STATUS \n"
                 << "[7] EXIT \n"
                 << endl;

            cout << "Enter your choice: ";
            cin >> ch;
            cout << endl
                 << endl;

            switch (ch)
            {
            case 1:
                // Sort by ascending task
                quicksortByTaskasc(t,0,4);
                
                break;
            case 2:
                // Sort by ascending date
                quicksortByDateasc(t,0,4);
                break;
            case 3:
                // Sort by ascending status
                quicksortByStatusasc(t,0,4);
                break;
            case 4:
                // Sort by descending task
                quicksortByTaskdec(t,0,4);
                break;
            case 5:
                // Sort by descending date
                quicksortByDatedec(t,0,4);
                break;
            case 6:
                // Sort by descending status
                quicksortByStatusdec(t,0,4);
                break;
            case 7:
                // Exit sorting process
                break;
            default:
                cout << "Invalid choice for sorting." << endl;
                break;
            }

            // Display sorted tasks
            cout << left << setw(40) << "TASK";
            cout << left << setw(2) << "|";
            cout << left << setw(20) << "DAY";
            cout << left << setw(2) << "|";
            cout << left << setw(10) << "STATUS" << endl
                 << endl;
            for (int i = 0; i < 5; ++i)
            {
                t[i].display();
            }
            cout << endl
                 << endl;

            break;
        }
        case 2:
        {
            cout << "<<< SEARCHING PROCESS >>>" << endl;
            cout << "[1] BY TASK \n"
                 << "[2] BY DATE \n"
                 << "[3] BY STATUS \n"
                 << "[4] EXIT \n"
                 << endl;

            cout << "Enter your choice: ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case 1:
            {
                // Search by task
                string searchTask;
                cout << "Enter the task to search: ";
                cin.ignore(); // Ignore the newline character in the buffer
                getline(cin, searchTask);
                

                if ()
                {
                    cout << "Tasks found with key '" << searchTask << "':" << endl
                         << endl;
                    cout << left << setw(40) << "TASK";
                    cout << left << setw(2) << "|";
                    cout << left << setw(20) << "DAY";
                    cout << left << setw(2) << "|";
                    cout << left << setw(10) << "STATUS" << endl;
                    for ()
                    {
                        t[index].display();
                    }
                    cout << endl
                         << endl;
                }
                else
                {
                    cout << "Task not found." << endl;
                }
                break;
            }
            case 2:
            {
                // Search by date
                string searchdate;
                cout << "Enter the date to search (DD-MM-YYYY): ";
                cin >> searchdate;


                if ()
                {
                    cout << "Tasks found with key '" << searchdate << "':" << endl
                         << endl;

                    cout << left << setw(40) << "TASK";
                    cout << left << setw(2) << "|";
                    cout << left << setw(20) << "DAY";
                    cout << left << setw(2) << "|";
                    cout << left << setw(10) << "STATUS" << endl;
                    for (int index : dateIndices)
                    {
                        t[index].display();
                    }
                    cout << endl
                         << endl;
                }
                else
                {
                    cout << "Task not found." << endl;
                }
                break;
            }
            case 3:
            {
                // Search by status
                string searchstatus;
                cout << "Please enter either TODO, DOING OR DONE" << endl;
                cout << "Enter the status to search: ";
                cin >> searchstatus;
                

                if ()
                {
                    cout << "Tasks found with key '" << searchstatus << "':" << endl
                         << endl;

                    cout << left << setw(40) << "TASK";
                    cout << left << setw(2) << "|";
                    cout << left << setw(20) << "DAY";
                    cout << left << setw(2) << "|";
                    cout << left << setw(10) << "STATUS" << endl;
                    for (int index : statusIndices)
                    {
                        t[index].display();
                    }

                    cout << endl
                         << endl;
                }
                else
                {
                    cout << "Task not found." << endl;
                }
                break;
            }
            case 4:
                // Exit searching process
                break;
            default:
                cout << "Invalid choice for searching." << endl;
                break;
            }

            break;
        }
        case 3:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

    } while (opt != 3);

    return 0;
}
