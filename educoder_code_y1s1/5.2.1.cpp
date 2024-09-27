#include <iostream>

using namespace std;

int main()
{
    int nleft = 0, nright = 0, nresult = 0;
    char coperator;
    cin>> nleft;
    cin.get(coperator);
    cin>> nright;
    switch (coperator)
    {
    case '+':
        nresult = nleft + nright;
        break;
    case '-':
        nresult = nleft - nright;
        break;
    case '*':
        nresult = nleft * nright;
        break;
    case '/':
        nresult = nleft / nright;
        break;
    default:
        break;
    }
    cout<< nleft << coperator << nright << '=' << nresult;
}