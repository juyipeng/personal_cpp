//@author juyip
//version 1.0 #basic functionality


#include <iostream>
#include <string>
#include "mingw.thread.h"//for windows, <thread> for linux
#include "reminder.h"
#include "user_management.h"
#include "task_management.h"

using namespace std;

int processOpt(string);
int run(int);

int main(int argc, char* argv[]) {

    if(argc == 4){
        user = argv[1];
        bool islogin = silent_login(user, argv[2]);
        if(islogin){
            run(processOpt(argv[3]));
        }
        else{
            cout << "Invalid username or password" << endl;
        }
        return 0;
    }

    if(argc != 1 && !(argc == 2 && argv[1][0]=='-' && argv[1][1]=='h')){
        cout << "Invalid arguments" << endl;
        return 1;
    }
    
    if (argc == 2 && (argc == 2 && argv[1][0]=='-' && argv[1][1]=='h')) {
        cout << "Usage: mySchedule [-h]" << endl;
        cout << "Description: A simple schedule managing program which allows you to add tasks and reminds you of your upcoming tasks." << endl;
        cout << "Options:" << endl;
        cout << "-h: display help" << endl;
        cout << "Commands:" << endl;
        cout << "exit: exit the program" << endl;
        cout << "addtask: add a new task" << endl;
        cout << "showtask: show all tasks" << endl;
        cout << "deltask: delete a task" << endl;
        cout << "\nyou can use args in terms of:" << endl;
        cout << "mySchedule username password command";
        cout << "command can be one of the following:" << endl;
        cout << "addtask, showtask, deltask" << endl;
        return 0;
    }
    


    int logininfo = user_login();
    while(logininfo == 2){
        cout << endl;
        logininfo = user_login();
    }
    switch(logininfo){
        case 0:
            return 0;
        case 1:
            int signupinfo = signup();
            while(signupinfo == 2){
                cout << endl;
                signupinfo = signup();
            }
            if(signupinfo == 0){
                return 0;
            }
            break;
    }

    //suuccessful login or signup

    thread *reminder = new thread(fReminder, user);

    string command;
    
    while(true){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> command;
        int opt = processOpt(command);
        run(opt);
        if (!isRunning)
        {
            break;
        }
        isRunning = false;
        reminder->join();
        delete reminder;
        isRunning = true;
        reminder = new thread(fReminder, user);
    }

        reminder->join();
        delete reminder;
        return 0;
    
}

int processOpt(string command){
    if(command == "exit"){
        return 0;
    }
    else if(command == "addtask"){
        return 1;
    }
    else if(command == "showtime"){
        showtime = true;
        return -1;
    }
    else if(command == "showtask"){
        return 2;
    }
    else if(command == "deltask"){
        return 3;
    }
    else{
        return -1;
    }
}

int run(int opt){
        int taskinfo;
        switch(opt){
            case 0://exit
                isRunning = false;
                break;
            
            case 1://addtask
                taskinfo = addTask();
                if (taskinfo == 0) {
                    cout << "Task added successfully" << endl;
                }
                else {

                    cout << "Failed to add task, please try again" << endl;
                }
                break;
            
            case 2://showtask
                showTask();
                break;

            case 3://deltask
                cout << "Here is the list of tasks:" << endl;
                taskinfo = showTask();
                if(taskinfo == -1){
                    break;
                }
                deleteTask();
                
                break;

            default://invalid command
                cout << "Invalid command" << endl;
                break;
        }
    return 0;
}