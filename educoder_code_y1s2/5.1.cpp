#include <iostream>

using namespace std;

int scale, *nspace = nullptr;
void percolate(int present){
    while(present*2 <= scale){
        if(nspace[present]<min(nspace[present*2],nspace[present*2+1])){
            return;
        }
        else{
            int tmp = nspace[present];
            int tar = (nspace[present*2]>nspace[present*2+1]?present*2+1:present*2);
            if(present*2+1>scale){tar = present*2;}
            nspace[present] = nspace[tar];
            nspace[tar] = tmp;
            present = tar;
        }
    }
}

void build(int present){
    if(present*2<=scale){build(present*2);}
    if(present*2+1<=scale){build(present*2+1);}
    percolate(present);
}

int main(){
    
    cin >> scale;
    nspace = new int[scale+2];
    for(int i = 1; i < scale+1; i++){
        cin >> nspace[i];
    }
    build(1);
    int n, least = 40960, site = 1;
    cin >> n;
    bool tell = false;
    for(int i = 1; i <=scale; i++){
        if(n<=nspace[i]){
            tell = true;
            if(nspace[i]<least){
                site = i;
                least = nspace[i];
            }
        }
    }
    if(!tell){
        cout << "not exist" << endl;
    }
    for(int i = site; i < scale; i++){
        cout << nspace[i] << ' ';
    }
    cout << nspace[scale];

    

    delete nspace;
}