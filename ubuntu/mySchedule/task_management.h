#ifndef TASK_MANAGEMENT_H
#define TASK_MANAGEMENT_H

#include <iostream>
#include <string>
#include "user_management.h"

using namespace std;

int addTask(){
    cout << "Enter task name: ";
    string taskName;
    cin >> taskName;
    cout << "Enter task time: (in the format of yymmddhhmmss)";
    string taskTime;
    cin >> taskTime;
    bool validTime = true;
    for(int i=0; i<12; i++){
        if(!(taskTime[i]>='0' && taskTime[i]<='9')){
            validTime = false;
            break;
        }
    }

    if(!validTime){
        cout << "Invalid time format. Please enter a valid time in the format of yymmddhhmmss." << endl;
        return -1;
    }
    ofstream file(user, ios::app);
    file << ' ' << taskName << "@" << taskTime;

    file.close();
    return 0;
}

int showTask(){
    cout << endl;
    ifstream file(user);
    if(!file.is_open()){
        cout << "No task found." << endl;
        return -1;
    }
    string task;
    int scale = 0;
    cout << "Your tasks:" << endl;
    cout << "number\tname\t\t\ttime" << endl;
    while(file >> task){
        scale++;
        int index = task.find("@");
        if(index == -1){index = task.find("#");}
        string taskName = task.substr(0, index);
        string taskTime = task.substr(index+1);
        cout << scale << '\t' << taskName << "\t\t\t";
        cout << taskTime[0] << taskTime[1] << '-' << taskTime[2] << taskTime[3] << '-' << taskTime[4] << taskTime[5] << ' ';
        cout << taskTime[6] << taskTime[7] << ':' << taskTime[8] << taskTime[9] << ':' << taskTime[10] << taskTime[11] << endl;
    }
    file.close();
    if(scale == 0){
        cout << "No task found." << endl;
    }
    cout << endl;
    return 0;
}

int deleteTask(){
    cout << "Enter the task number you want to delete:\n(enter 0 to cancel)\n(enter -1 to delete all tasks)" << endl;
    int taskNum;
    cin >> taskNum;
    if(taskNum == 0){
        return 0;
    }
    if(taskNum == -1){
        ofstream file(user, ios::trunc);
        file.close();
        return 0;
    }
    ifstream file(user);
    if(!file.is_open()){
        return 1;
    }
    string *schedules = new string[1000];
    int scale = 0;
    for(int i=0; i<1000&&file; i++){
        file >> schedules[i];
        scale++;
    }
    scale--;
    file.close();
    if(taskNum > scale){
        cout << "Invalid task number." << endl;
        return 1;
    }
    ofstream file2(user, ios::trunc);
    file2.close();
    file2.open(user, ios::app);
    for(int i=0; i<scale; i++){
        if(i!= taskNum-1){
            file2 << ' ' << schedules[i] << endl;
        }
    }
    file2.close();
    delete[] schedules;
    return 0;
}


#endif // TASK_MANAGEMENT_H