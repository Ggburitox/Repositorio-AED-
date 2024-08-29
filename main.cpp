#include <iostream>
#include "ForwardList.h"


int main(){
    ForwardList<int> f_list;
    f_list.pushfront(3);
    f_list.pushfront(4);
    f_list.pushfront(5);
    f_list.reverse();
    f_list.print();
    f_list.erase(4);
    f_list.print();
}

