// Build a basic to-do list app with functions to add, delete, and update tasks
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Task structure to hold task details

struct Task
{
 int id;
 string description;
 bool completed;

 Task(int id, const string &desc) : id(id), description(desc), completed(false) {}
};
// Function to add a task
void addTask(vector<Task> &tasks, const string &description)
{
 int id = tasks.size() + 1; // Simple ID generation
 tasks.emplace_back(id, description);
 cout << "Task added: " << description << endl;
}

int main()
{
 vector<Task> tasks;
 string command, description;

 while (true)
 {
  cout << "Enter command (add, delete, update, list, exit): ";
  cin >> command;

  if (command == "add")
  {
   cout << "Enter task description: ";
   cin.ignore(); // Clear the newline character from the input buffer
   getline(cin, description);
   addTask(tasks, description);
  }
  else if (command == "delete")
  {
   int id;
   cout << "Enter task ID to delete: ";
   cin >> id;
   if (id > 0 && id <= tasks.size())
   {
    tasks.erase(tasks.begin() + id - 1);
    cout << "Task deleted." << endl;
   }
   else
   {
    cout << "Invalid task ID." << endl;
   }
  }
  else if (command == "update")
  {
   int id;
   cout << "Enter task ID to update: ";
   cin >> id;
   if (id > 0 && id <= tasks.size())
   {
    cout << "Enter new description: ";
    cin.ignore();
    getline(cin, description);
    tasks[id - 1].description = description;
    cout << "Task updated." << endl;
   }
   else
   {
    cout << "Invalid task ID." << endl;
   }
  }
  else if (command == "list")
  {
   for (const auto &task : tasks)
   {
    cout << "ID: " << task.id
         << ", Description: " << task.description
         << ", Completed: " << (task.completed ? "Yes" : "No")
         << endl;
   }
  }
  else if (command == "exit")
  {
   break;
  }
  else
  {
   cout << "Unknown command." << endl;
  }
 }

 return 0;
}