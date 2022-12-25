// Round Robin
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int arival_time;
    int burst_time;
    int turn_around_time;
    int waiting_time;
    int remaining_time;
    int response_time;
    bool done;
    bool in_queue;
    
    bool operator==(const process &p)
    {
        return pid == p.pid;
    }
    bool operator!=(const process &p)
    {
        return pid != p.pid;
    }
};

bool cmp(process a, process b)
{
    return a.arival_time < b.arival_time;
}

signed main()
{
    int no_of_process;
    cout << "Enter the number of process: ";
    cin >> no_of_process;
    int quantum;
    cout << "Enter the quantum: ";
    cin >> quantum;
    vector<process> p(no_of_process);
    for (int i = 0; i < no_of_process; i++)
    {
        cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
        cin >> p[i].arival_time >> p[i].burst_time;
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
        p[i].response_time = -1;
        p[i].done = false;
    }
    sort(p.begin(), p.end(), cmp);
    int time = 0;
    vector<int> gantt;
    queue<process> q;
    q.push(p[0]);
    p[0].in_queue = true;
    int i = 1;
    while (!q.empty())
    {
        process curr = q.front();
        q.pop();
        curr.in_queue = false;
        if (curr.response_time == -1)
            curr.response_time = time - curr.arival_time;
        if (curr.remaining_time <= quantum)
        {
            time += curr.remaining_time;
            curr.remaining_time = 0;
            curr.done = true;
            curr.turn_around_time = time - curr.arival_time;
            curr.waiting_time = curr.turn_around_time - curr.burst_time;
            gantt.push_back(curr.pid);
            for (; i < no_of_process; i++)
            {
                if (p[i].arival_time <= time)
                {
                    q.push(p[i]);
                    p[i].in_queue = true;
                }
                else
                    break;
            }
        }
        else
        {
            time += quantum;
            curr.remaining_time -= quantum;
            gantt.push_back(curr.pid);
            for (; i < no_of_process; i++)
            {
                if (p[i].arival_time <= time)
                {
                    q.push(p[i]);
                    p[i].in_queue = true;
                }
                else
                    break;
            }
            q.push(curr);
            curr.in_queue = true;
        }
        if (curr.done)
        {
            for (auto &i : p)
            {
                if (i == curr)
                {
                    i = curr;
                    break;
                }
            }
        }
    }
    cout << "Gantt Chart: ";
    for (auto i : gantt)
        cout << i << " ";
    cout << "\n";
    cout << "PID\tAT\tBT\tRT\tTAT\tWT\n";
    for (auto i : p)
        cout << i.pid << "\t" << i.arival_time << "\t" << i.burst_time << "\t" << i.response_time << "\t" << i.turn_around_time << "\t" << i.waiting_time << "\n";
    return 0;
}