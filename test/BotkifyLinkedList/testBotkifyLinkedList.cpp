#include "main.h"
#include "BotkifyLinkedList.h"
#include <cstdlib>
int main() {
    // Student can use this main function to do some basic testing
    BotkifyLinkedList<int> intList;
    for(int i = 0; i < 20; i++) {
        intList.add(i);
    }
    cout << intList.toString();
    
    return 0;
}