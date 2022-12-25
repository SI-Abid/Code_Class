#include <bits/stdc++.h>
namespace FCFS
{
    typedef struct
    {
        int pid;
        int at;
        int bt;
        int ct;
        int tat;
        int wt;
        int rt;
    } process;

    bool compare(process a, process b)
    {
        return a.at < b.at;
    }

    std::ostream &operator<<(std::ostream &os, const process &p)
    {
        os << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.rt << "\t" << p.tat << "\t" << p.wt << "\t" << p.ct << "\n";
        return os;
    }

    std::istream &operator>>(std::istream &is, process &p)
    {
        is >> p.at >> p.bt;
        return is;
    }
}

signed main()
{
    int no_of_process;
    std::cout << "Enter the number of process: ";
    std::cin >> no_of_process;
    std::vector<FCFS::process> p(no_of_process);
    for (int i = 0; i < no_of_process; i++)
    {
        std::cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
        std::cin >> p[i];
        p[i].pid = i + 1;
    }
    std::sort(p.begin(), p.end(), FCFS::compare);
    int time = 0;
    for (int i = 0; i < no_of_process; i++)
    {
        if (time < p[i].at)
            time = p[i].at;
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].rt = p[i].wt = p[i].tat - p[i].bt;
    }
    std::cout << "PID\tAT\tBT\tRT\tTAT\tWT\tCT\n";
    for (auto i : p)
        std::cout << i;
    return 0;
}