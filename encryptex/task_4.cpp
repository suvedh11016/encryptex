#include<bits/stdc++.h>

using namespace std;

struct listOfTasks
{
    string taskName;
    bool isCompleted = false;
};

vector<listOfTasks> tasks;

void addTask(string task)
{
    listOfTasks newTask;
    newTask.taskName = task;
    tasks.push_back(newTask);
}

void viewTasks()
{
    if (!tasks.empty())
    {
        cout << "     " << "**************" << endl;
        cout << "     " << "* TO-DO-LIST *" << endl;
        cout << "     " << "**************" << endl;
        for (size_t i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].isCompleted)
            {
                cout << i + 1 << "." << tasks[i].taskName << " [completed] " << endl;
            }
            else
            {
                cout << i + 1 << "." << tasks[i].taskName << " [not completed] " << endl;
            }
        }
    }
    else
    {
        cout << "There are no tasks to display" << endl;
    }
}

void updateTask(string task)
{
    int found = 0;
    int counter = 0;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].isCompleted == true)
        {
            counter++;
        }
    }

    if (size_t(counter) == tasks.size())
    {
        cout << "All tasks are already completed so there is no chance to update" << endl;
    }

    if (!tasks.empty() && size_t(counter) != tasks.size())
    {
        for (size_t i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].taskName == task)
            {
                found = 1;
            }
        }

        if (found == 1)
        {
            for (size_t i = 0; i < tasks.size(); i++)
            {
                if (tasks[i].taskName == task)
                {
                    if (tasks[i].isCompleted == false)
                    {
                        tasks[i].isCompleted = true;
                        cout << "Successfully updated the status of " << task << endl;
                    }
                    else
                    {
                        cout << "The task is already completed" << endl;
                    }
                }
            }
        }
        else
        {
            cout << "No such task is found" << endl;
        }
    }

    else
    {
        cout << "There are no tasks to update" << endl;
    }
}

void deleteTask(string task)
{
    int found = 0;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].taskName == task)
        {
            found = 1;
        }
    }
    if (found == 1)
    {
        for (size_t i = 0; i < tasks.size(); i++)
        {
            tasks.erase(tasks.begin() + i);
            cout << "Successfully deleted task: " << task << endl;
            break;
        }
    }
    else
    {
        cout << "No such task is found" << endl;
    }
}

int main()
{
    int key;
    string task;
    while (true)
    {
        cout << "******INSTRUCTIONS***************************" << endl;
        cout << "* Press 1 to Add task to the list           *" << endl;
        cout << "* Press 2 to view your task status          *" << endl;
        cout << "* Press 3 to update your task status        *" << endl;
        cout << "* Press 4 to remove the task from your list *" << endl;
        cout << "* Press 5 to exit                           *" << endl;
        cout << "*********************************************" << endl;
        cout << "Enter your choice: ";
        cin >> key;
        if (key == 1)
        {
            cout << "Enter the task name you want to do: ";
            cin.ignore();
            getline(cin, task);
            addTask(task);
        }
        else if (key == 2)
        {
            viewTasks();
        }
        else if (key == 3)
        {
            cout << "Enter the name of the task whose status you want to update: ";
            cin.ignore();
            getline(cin, task);
            updateTask(task);
        }
        else if (key == 4)
        {
            cout << "Enter the task name you want to delete: ";
            cin.ignore();
            getline(cin, task);
            deleteTask(task);
        }
        else if (key == 5)
        {
            break;
        }
    }

    return 0;
}