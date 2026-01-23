#include "main.h"
#include "BotkifyLinkedList.h"
#include <cstdlib>
int main() {
    // Student can use this main function to do some basic testing
    BotkifyLinkedList<int> intList;
    for(int i = 0; i < 20; i++) {
        intList.add(i);
    }
    cout << intList.toString() << endl;
    cout << "Is list empty ? " << intList.empty() << endl; 
    cout << "Size of list: " << intList.size() << endl;
    intList.clear();
    cout << intList.toString() << endl;
    cout << "Is list empty ? " << intList.empty() << endl; 
    cout << "Size of list: " << intList.size() << endl;
    for(int i = 0; i < 10; i++) {
        intList.add(i);
    }
    for(int i = 0; i < 10; i++) {
        intList.add(i, i + 20);
    }
    cout << "After add with index: " << intList.toString() << endl;

    int startRemove = 5;
    int endRemove = 10;
    for(int i = startRemove; i < endRemove; i++) {
        intList.removeAt(i);
    }
    cout << "After remove index " << startRemove << " to " << endRemove << ": " << intList.toString() << endl;
    intList.clear();
    for(int i = 0; i < 20; i++) {
        intList.add(i);
    }
    cout << intList.toString() << endl;
    for(int i = startRemove; i <= endRemove; i++) {
        intList.removeItem(i);
    }
    cout << "After remove item " << startRemove << " to " << endRemove << ": " << intList.toString() << endl;
    cout << intList.removeItem(-99) << endl;
    int getItemIndex = 5;
    int item = intList.get(getItemIndex);
    cout << "Item at index " << getItemIndex << ": " << item << endl;
    return 0;
}