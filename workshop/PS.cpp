// Priority scheduling algorithm
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int arival_time;
    int burst_time;
    int turn_around_time;
    int waiting_time;
    int response_time;
    int priority;

    bool operator==(const process &p)
    {
        return pid == p.pid;
    }
};

bool cmp(process a, process b)
{
    if (a.arival_time == b.arival_time)
        return a.priority < b.priority;
    return a.arival_time < b.arival_time;
}

signed main()
{
    int no_of_process;
    // cout << "Enter the number of process: ";
    cin >> no_of_process;
    vector<process> p(no_of_process);
    for (int i = 0; i < no_of_process; i++)
    {
        // cout << "Enter the priority, arrival time and burst time of process " << i + 1 << ": ";
        cin >> p[i].priority >> p[i].arival_time >> p[i].burst_time;
        p[i].pid = i + 1;
        p[i].response_time = -1;
    }
    // TODO: sort the processes according to arrival time
    sort(p.begin(), p.end(), [](process a, process b)
         { return a.arival_time < b.arival_time; });
    vector<int> gantt;
    vector<process> ready_queue;
    int time = 0;
    // int i = 0;
    while (gantt.size() != no_of_process)
    {
        // if (ready_queue.empty())
        // {
        for (int i = 0; i < no_of_process; i++)
        {
            if (p[i].arival_time == time)
            {
                ready_queue.push_back(p[i]);
            }
        }
        sort(p.begin(), p.end(), [](process a, process b)
             { return a.priority < b.priority; });
        // }
        if (!ready_queue.empty())
        {
            process curr = ready_queue[0];
            ready_queue.erase(ready_queue.begin());
            if (curr.response_time == -1)
                curr.response_time = time - curr.arival_time;
            gantt.push_back(curr.pid);
            for (int timet = 0; timet < curr.burst_time; timet++)
            {
                time++;
                for (int i = 0; i < no_of_process; i++)
                {
                    if (p[i].arival_time == time)
                    {
                        ready_queue.push_back(p[i]);
                    }
                }
                sort(ready_queue.begin(), ready_queue.end(), [](process a, process b)
                     { return a.priority < b.priority; });
            }
            cout << "Process " << curr.pid << " completed at time " << time << endl;
            curr.turn_around_time = time - curr.arival_time;
            curr.waiting_time = curr.turn_around_time - curr.burst_time;
            for (int i = 0; i < no_of_process; i++)
            {
                if (p[i].pid == curr.pid)
                {
                    p[i] = curr;
                    break;
                }
            }
        }
    }

    cout << "Gantt chart: ";
    for (int i = 0; i < gantt.size(); i++)
        cout << gantt[i] << " ";
    cout << endl;
    cout << "Process\tArival time\tBurst time\tPriority\tTurn around time\tWaiting time\tResponse time" << endl;
    for (int i = 0; i < no_of_process; i++)
    {
        cout << p[i].pid << "\t" << p[i].arival_time << "\t\t" << p[i].burst_time << "\t\t" << p[i].priority << "\t\t" << p[i].turn_around_time << "\t\t\t" << p[i].waiting_time << "\t\t" << p[i].response_time << endl;
    }

    return 0;
}