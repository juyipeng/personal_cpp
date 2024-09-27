#include<iostream>
using namespace std;

struct Node {
  int order, coeff;
  Node *nxt;
};

Node* add_poly(Node* a, Node* b) 
{
    Node *pc = nullptr, *tmp = nullptr, *c =nullptr;
    // if((a->order)==0&&(b->order)==0){
    //     pc = new Node;
    //     pc->coeff = 0;
    //     pc->order = 0;
    //     return pc;
    // }
    // else if((b->order)==0){
    //     while(a){
    //         pc = new Node;
    //         if(!c)c = pc;
    //         pc->coeff = a->coeff;
    //         pc->order = a->order;
    //         pc->nxt = nullptr;
    //         if(tmp){tmp->nxt = pc;}
    //         tmp = pc;
    //         a = a->nxt;
    //     }
    // }
    // else if((a->order)==0){
    //     while(b){
    //         pc = new Node;
    //         if(!c)c = pc;
    //         pc->coeff = b->coeff;
    //         pc->order = b->order;
    //         pc->nxt = nullptr;
    //         if(tmp){tmp->nxt = pc;}
    //         tmp = pc;
    //         b = b->nxt;
    //     }
    // }

    // else{
        // tmp = nullptr;
    while(a||b){
        pc = new Node;
        if(!c)c = pc;
        if(!b){
            pc->coeff = a->coeff;
            pc->order = a->order;
                pc->nxt = nullptr;
                a = a->nxt;
            }
            else if(!a){
                pc->coeff = b->coeff;
                pc->order = b->order;
                pc->nxt = nullptr;
                b = b->nxt;
            }
            else{
                if((a->order)>(b->order)){
                    pc->coeff = a->coeff;
                    pc->order = a->order;
                    pc->nxt = nullptr;
                    a = a->nxt;
                }
                else if((b->order)>(a->order)){
                    pc->coeff = b->coeff;
                    pc->order = b->order;
                    pc->nxt = nullptr;
                    b = b->nxt;   
                }
                else{
                    pc->coeff = (a->coeff)+(b->coeff);
                    pc->order = a->order;
                    pc->nxt = nullptr;
                    a = a->nxt;
                    b = b->nxt;
                    // if(pc->coeff == 0)
                }
            }
            if(tmp){tmp->nxt = pc;}
            tmp = pc;
        // }
        }
        tmp = nullptr;
        for(pc = c; pc->nxt != nullptr;){
            if(pc->coeff == 0){
                if(pc == c){
                    c = c->nxt;
                    delete pc;
                    pc = c;
                }
                else{
                    if(tmp){
                        tmp->nxt = pc->nxt;
                        delete pc;
                        pc = tmp->nxt;
                    }
                }
            }
            else{
                tmp = pc;
                pc = pc->nxt;
            }
        }
    if(!c){
        c = new Node;
        c->coeff = 0;
        c->order = 0;
        c->nxt = nullptr;
    }


    return c;
}

int main()
{
  Node *a = nullptr, *pa = nullptr, *b = nullptr, *pb = nullptr;
  int coef, orde;
  cin >> coef >> orde;
  while (orde >= 0) {
    Node* na = new Node;
    na->order = orde;
    na->coeff = coef;
    na->nxt = nullptr;
    if (pa) pa->nxt = na;
    pa = na;
    if (a == nullptr) a = pa;
    cin >> coef >> orde;
  }
  cin >> coef >> orde;
  while (orde >= 0) {
    Node* nb = new Node;
    nb->order = orde;
    nb->coeff = coef;
    nb->nxt = nullptr;
    if (pb)  pb->nxt = nb;
    pb = nb;
    if (b == nullptr) b = pb;
    cin >> coef >> orde;
  }
  
  Node* c = add_poly(a, b);
  Node *c1 = c;
  while (c) {
    cout << c->coeff << ' '<< c->order << endl;
    c = c->nxt;
  }
    Node*tmp = nullptr;
  //要不要补上a,b,c三个链表的删除？
  for(pa = a; pa!=nullptr; pa = tmp){
    tmp = pa->nxt;
    delete pa;
  }
  for(pa = b; pa!=nullptr; pa = tmp){
    tmp = pa->nxt;
    delete pa;
  }
  for(pa = c1; pa!=nullptr; pa = tmp){
    tmp = pa->nxt;
    delete pa;
  }

  return 0;
}