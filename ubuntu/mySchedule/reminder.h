#ifndef REMINDER_H
#define REMINDER_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

#define fileName "ScheduleData.txt"

using namespace std;

bool isRunning = true;
bool showtime = false;

// fReminder 
// the form of the schedule is "name@yymmddhhmm"
int fReminder(string username){
    ifstream file(username);
    if(!file.is_open()){
        cout << "Error: schedule not found." << endl;
        return 1;
    }
    string *schedules = new string[1000];
    int scale = 0;
    for(int i=0; i<1000&&file; i++){
        file >> schedules[i];
        scale++;
    }
    file.close();
    scale--;
    cout << "schedule file load successfully." << endl;
    int year, month, day, hour, minute, second;
    string time_now = "000000000000";

    while(isRunning){
        time_t now = time(nullptr);
        struct tm *localTime = localtime(&now);
        year = localTime->tm_year - 100;
        month = localTime->tm_mon + 1;
        day = localTime->tm_mday;
        hour = localTime->tm_hour;
        minute = localTime->tm_min;
        second = localTime->tm_sec;
        
        time_now[0] = year/10 + '0';time_now[1] = year%10 + '0';
        time_now[2] = month/10 + '0';time_now[3] = month%10 + '0';
        time_now[4] = day/10 + '0';time_now[5] = day%10 + '0';
        time_now[6] = hour/10 + '0';time_now[7] = hour%10 + '0';
        time_now[8] = minute/10 + '0';time_now[9] = minute%10 + '0';
        time_now[10] = second/10 + '0';time_now[11] = second%10 + '0';
        // cout << time_now << endl;

        if(showtime){
            cout << "Current time: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;

            showtime = false;
        }
        string timebuffer = "000000000000";
        for(int i=0; i<scale; i++){
            int t = 0;
            while(schedules[i][t]!='@'&&schedules[i][t]!='#'){
                t++;
            }
            for(int j=0; j<12; j++){
                timebuffer[j] = schedules[i][t+j+1];
            }
            // cout << timebuffer << endl;
            bool occur = (schedules[i][t]=='@')&&(timebuffer < time_now);
            if(occur){
                cout << "Reminder:\n" << "time for a new schedule:\n";
                for(int j=0; j<t; j++){
                    cout << schedules[i][j];
                }
                cout << endl;
                cout << timebuffer[0] << timebuffer[1] << "-" << timebuffer[2] << timebuffer[3] << "-" << timebuffer[4] << timebuffer[5] << " " << timebuffer[6] << timebuffer[7] << ":" << timebuffer[8] << timebuffer[9] << ":" << timebuffer[10] << timebuffer[11] << endl;
                schedules[i][t] = '#'; // mark as done
                ofstream file1(username, ios::trunc);
                file1.close();
                file1.open(username , ios::app);
                for(int j=0; j<scale; j++){
                    file1 << ' ' << schedules[j];
                }
                file1.close();
            }
        }
    }
    file.close();
    return 0;
}


#endif // REMINDER_H