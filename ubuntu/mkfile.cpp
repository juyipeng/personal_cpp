#include "kit.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

    if(argc!=1&&argv[1][1]=='h'){
        cout << "helptext";
        return 0;
    }

    student* s = nullptr;
    vector<student*> students;
    getinfo(students, argv[1]);
    int size = students.size();
    char* com = new char[24];
    while(cin >> com){
        if(com[0]=='q'||com[0]=='Q'){
            break;
        }
        else if((com[0]=='s'||com[0]=='S')&&(com[5]=='l'||com[5]=='L')){
            for(int i = 0; i < students.size(); i++){
                for(int j = i+1; j < students.size(); j++){
                    if((students[j]->number)<(students[i]->number)){
                        s = students[j];
                        students[j] = students[i];
                        students[i] = s;
                    }
                }
                cout << students[i]->name << ' ' << students[i]->number << ' ' << students[i]->score << endl;
            }
        }
        else if((com[0]=='s'||com[0]=='S')&&(com[5]=='v'||com[5]=='V')){
            int sum;
            for(int i = 0; i < students.size(); i++){
                sum += students[i]->score;
            }
            cout << sum/students.size() << endl;
        }
        else if((com[4]=='m'||com[4]=='M')){
            int max = 0;
            for(int i = 0; i < students.size(); i++){
                if((students[i]->score)>max){
                    max = students[i]->score;
                }
            }
            for(int i = 0; i < students.size(); i++){
                if((students[i]->score)==max){
                    cout << students[i]->name << ' ' << students[i]->number << ' ' << students[i]->score << endl;
                }
            }
        }
        else{
        	cout << "invalid input" << endl;
        }
    }

    while(students.size()!=0){
        delete students[students.size()-1];
        students.pop_back();
    }
    delete com;
}
