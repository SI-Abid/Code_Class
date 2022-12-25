#include <bits/stdc++.h>
using namespace std;

namespace SJF
{
    struct process
    {
        int pid;
        int at;
        int bt;
        int tat;
        int wt;
        int rt;
    };

    bool compare(process a, process b)
    {
        return a.bt < b.bt;
    }

    ostream &operator<<(ostream &os, const process &p)
    {
        os << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.rt << "\t" << p.tat << "\t" << p.wt << "\n";
        return os;
    }

    istream &operator>>(istream &is, process &p)
    {
        is >> p.at >> p.bt;
        return is;
    }
} // namespace SJF
using namespace SJF;

signed main()
{
    int no_of_process;
    cout << "Enter the number of process: ";
    cin >> no_of_process;
    vector<process> p(no_of_process);
    for (int i = 0; i < no_of_process; i++)
    {
        cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
        cin >> p[i];
        p[i].pid = i + 1;
    }
    sort(p.begin(), p.end(), compare);
    int time = 0;
    for (int i = 0; i < no_of_process; i++)
    {
        if (time < p[i].at)
            time = p[i].at;
        p[i].rt = time;
        time += p[i].bt;
        p[i].tat = time - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
    cout << "Average waiting time: " << accumulate(p.begin(), p.end(), 0, [](int a, process b)
                                                   { return a + b.wt; }) /
                                            (double)no_of_process
         << "\n";
    cout << "Average turnaround time: " << accumulate(p.begin(), p.end(), 0, [](int a, process b)
                                                      { return a + b.tat; }) /
                                               (double)no_of_process
         << "\n";
    cout << "Average response time: " << accumulate(p.begin(), p.end(), 0, [](int a, process b)
                                                    { return a + b.rt; }) /
                                             (double)no_of_process
         << "\n";
    cout << "Gantt chart:\n";
    for (int i = 0; i <= 5 * no_of_process; i++)
        cout << "-";
    cout << "\n";
    for (process proc : p)
    {
        cout << "| ";
        // color the process id
        switch (proc.pid)
        {
        case 1:
            cout << "\033[1;31m";
            break;
        case 2:
            cout << "\033[1;32m";
            break;
        case 3:
            cout << "\033[1;33m";
            break;
        case 4:
            cout << "\033[1;34m";
            break;
        case 5:
            cout << "\033[1;35m";
            break;
        case 6:
            cout << "\033[1;36m";
            break;
        case 7:
            cout << "\033[1;37m";
            break;
        case 8:
            cout << "\033[1;38m";
            break;
        case 9:
            cout << "\033[1;39m";
            break;
            cout << "\033[1;40m";
            break;
        default:
            cout << "\033[1;41m";
            break;
        }
        cout << "P" << proc.pid << " \033[0m";
    }
    cout << "|\n";
    for (int i = 0; i <= 5 * no_of_process; i++)
        cout << "-";
    cout << "\n";
    cout << "Process\tAT\tBT\tRT\tTAT\tWT\n";
    for (process proc : p)
        cout << proc;
    cout << "\n";
    return 0;
}