#include <iostream>
#include <string>

using namespace std;

struct student{
    private:
    std::string sName = "",sSequence = "";
    int nScore[3] = {0};
    public:
    string checkname();
    string checksequence();
    void println();
    int checkscore();
    void input(string);
    student *m_last = NULL, *m_next = NULL;
};

int student::checkscore(){
    int m = nScore[0]+nScore[1]+nScore[2];
    return m;
}

string student::checkname(){
    return sName;
}

void student::input(string tmp){
    sSequence = tmp;
    for(int i = 0; i < 3; i++){
        cin>> nScore[i];
    }
    cin.get();
    getline(cin,sName);
    return;
}

string student::checksequence(){
    string m = sSequence;
    return m;
}

// void student::input(){
//     cin>> sSequence;
//     for(int i = 0; i < 3; i++){
//         cin>> nScore[i];
//     }
//     cin.get();
//     getline(cin,sName);
// }

void student::println(){
    cout<< sSequence << ' '<<sName ;
    for(int i = 0; i < 3; i++){
        cout<< ' '<< nScore[i] ;
    }
    cout<<' '<< endl;
}

// string sequences[1000];

// int which(string tofind, int fnindex){
//     for(int i = 0; i <= fnindex; i++){
//         if(sequences[i]==tofind){
//             return i;
//         }
//     }
//     return -1;
// }

int main(){
    int oprtr,past2,present2;
    bool cntrl = true,test1 = true,test2;
    student *last = NULL, *p=NULL, *q = NULL;
    // int presentindex = 0;
    string tmp = "";
    string past1 = "", present1 = "";
    while(cntrl){
        cin>> oprtr;
        switch (oprtr){
            case 1:
            cin>>tmp;
            for(q = last;(q != NULL) && (q->checksequence() != tmp) ; q = q->m_last){}
            if(!q){
                p = new student;
                p->input(tmp);
                if(last){last->m_next = p;}
                p->m_last = last;
                last = p;
                p = q = NULL;
                break;
            }
            else{
                q->input(tmp);
                q = NULL;
                break;
            }

            case 2:
            cin>> tmp;
            p = NULL;
            for(q = last; q != NULL; q = q->m_last){
                if(q->checksequence()==tmp){
                    p = q;
                    break;
                }
            }
            if(p){
                p->input(tmp);
                p = NULL;
            }
            else{
                getline(cin,tmp);
            }
            break;

            case 3:
            cin>>tmp;
            p = NULL;
            for(q = last; q != NULL; q = q->m_last){
                if(q->checksequence()==tmp){
                    p = q;
                    q = NULL;
                    break;
                }
            }

            if(p){
                if(p->m_last){p->m_last->m_next = p->m_next;}
                if(p->m_next){p->m_next->m_last = p->m_last;}
                delete p;
                p = NULL;
            }
            break;

            case 4:
            cin>> tmp;
            for(q = last;  (q != NULL) &&(q->checksequence() != tmp); q = q->m_last){}
            if(q){q->println();}
            p = q = NULL;
            break;

            case 5:
            cin.get();
            getline(cin,tmp);
            test1 = true;
            past1 = "";

            while(test1){
                present1 = "999999999999";
                test1 = false;
                for(q = last; (q != NULL); q = q->m_last){
                    if((q->checkname() == tmp)&&(q->checksequence()>past1)){
                        if(q->checksequence()<present1){
                            present1 = q->checksequence();
                            p = q;
                        }
                        test1 = true;
                    }
                }
                if(test1){
                    p->println();
                    past1 = p->checksequence();
                    p = NULL;
                }
            }
            q = NULL;
            break;

            case 6:
            test1 = true;
            past1 = "";
            while(test1){
                test1 = false;
                present1 = "999999999999";
                for(q = last; q != NULL; q = q->m_last){
                    if((q->checksequence()<present1)&&(q->checksequence()>past1)){
                        test1 = true;
                        p = q;
                        present1 = p->checksequence();
                    }
                }
                if(test1){
                    p->println();
                    past1 = p->checksequence();
                    p = NULL;
                }
            }
            q = NULL;
            break;
            
            case 7:
            test2 = true;
            past2 = 999;
            while(test2){
                test2 = false;
                present2 = 0;
                for(q = last; q!=NULL; q=q->m_last){
                    if((q->checkscore()<past2)&&(q->checkscore()>present2)){
                        present2 = q->checkscore();
                        test2 = true;
                    }
                }
                if(test2){
                    past2 = present2;
                    test1 = true;
                    past1 = "";
                    while(test1){
                        test1 = false;
                        present1 = "999999999999";
                        for(q = last; q!=NULL; q = q->m_last){
                            if((q->checksequence()>past1)&&(q->checksequence()<present1)&&(q->checkscore()==present2)){
                                test1 = true;
                                p = q;
                                present1 = p->checksequence();
                            }
                        }
                        if(test1){
                            p->println();
                            past1 = p->checksequence();
                            p = NULL;
                        }
                    }
                }
            }
            break;

            case 0:
            cntrl = false;
            break;

            default:
            cout<<"error";
            cntrl = false;
            break;
        }
    }
    for(q = last; q!=NULL;){
        if(q->m_last){
            p = q->m_last;
            delete q;
            q = p;
            p = NULL;
        }
        else{
            delete q;
            q = NULL;
        }
    }
}