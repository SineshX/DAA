#include <iostream>
#include "list.h"
//goal : to learn to use external file and its classes

// myLL.display()
// myLL.insert_end(data) // insert at end
// myLL.insert_beg(data) // beganing
// myLL.insert_at(position,data)
//
// todo :  delete : beg end mid
//
//
using namespace std;

int main()
{
    linkedlist myLL;

    myLL.insert_end(20);
    myLL.insert_end(20);

    myLL.display();

    return 0;
}
