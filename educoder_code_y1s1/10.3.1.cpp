// /*
// @10.3.1
// @pengjuyi
// @2023.12.23
// @version 1.0
// */

// #include "class.h"
// #include <iostream>

// int main(){
//     char tmp[1024],t;
//     int p,q;
//     std::cin.getline(tmp,1024);
//     String object(tmp);
//     char oprt = 0;
//     while(oprt != '@'){
//         std::cin >> oprt;
//         switch(oprt){
//             // case '0':
//             // std::cout << object.length() << std::endl;
//             // break;
//             case '1':
//             std::cin >> p >> q;
//             object.substr(p,q).printStr();
//             break;
//             case '2':
//             std::cin >> t;
//             std::cout << object.find_first_of(t) << std::endl; 
//             break;
//             case '3':
//             std::cin >> p >> t;
//             object.add_before(p+1,t);
//             break;
//             case '4':
//             std::cin >> p;
//             object.delete_at(p);
//             break;
//             case '5':
//             object.printStr();
//             break;
//             defaut:break;
//         }
//     }
// }