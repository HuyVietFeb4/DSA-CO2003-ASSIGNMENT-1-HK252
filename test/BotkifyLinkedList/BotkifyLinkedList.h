#ifndef BOTKIFY_LINKED_LIST_H
#define BOTKIFY_LINKED_LIST_H

#include "main.h"

template <class T>
class BotkifyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node* extra;

        Node() {
            this->next = nullptr;
            this->extra = nullptr;
        }
        Node(const T& data, Node* next = nullptr, Node* extra = nullptr) : data(data), next(next), extra(extra) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    BotkifyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    ~BotkifyLinkedList() {
        while(this->head != nullptr) {
            Node* tmpNodeObj = this->head;
            this->head = this->head->next;
            delete tmpNodeObj;
        }
    }

    void add(T e) {
        Node* newNode = new Node(e);
        if (this->count == 0) {
            this->head = this->tail = newNode;
        }
        else{
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->count++;
    }
    void add(int index, T e) {
        if (index > count || index < 0) {
            throw out_of_range("Index is invalid!");
        }
        Node* newNode = new Node(e);
        if (index == 0) {
            newNode->next = this->head;
            this->head = newNode;
            if(this->count == 0) {
                this->tail = newNode;
            }
        }
        else if(index == this->count) {
                this->tail->next = newNode;
                this->tail = newNode;
        }
        else {
            int currIndex = 0;
            Node* traverseLL = this->head;
            Node* prevTraverse = nullptr;
            while(currIndex < index) {
                prevTraverse = traverseLL;
                traverseLL = traverseLL->next;
                currIndex++;
            }
            prevTraverse->next = newNode;
            newNode->next = traverseLL;
        }
        this->count++;
    }
    T removeAt(int index) {
        if (index >= count || index < 0) {
            throw out_of_range("Index is invalid!");
        }
        T removedData;
        if (index == 0) {
            removedData = head->data;
            Node* tmpNodeObj = this->head;
            this->head = this->head->next;
            delete tmpNodeObj;
            if(this->count == 1) {
                this->tail = nullptr;
                this->head = nullptr;
            }
        }
        else {
            int currIndex = 0;
            Node* traverseLL = this->head;
            Node* prevTraverse = nullptr;
            while(currIndex < index) {
                prevTraverse = traverseLL;
                traverseLL = traverseLL->next;
                currIndex++;
            }
            removedData = traverseLL->data;
            prevTraverse->next = traverseLL->next;
            delete traverseLL;
            if(index == this->count-1) {
                this->tail = prevTraverse;
            }
            
        }
        this->count--;
        return removedData;
    }
    bool removeItem(T item) {
        Node* traverseLL = this->head;
        int removeIndex = 0;
        while(traverseLL != nullptr) {
            if(traverseLL->data == item) {
                break;
            }
            removeIndex++;
            traverseLL = traverseLL->next;
        }
        if (traverseLL == nullptr) {
            return false;
        }
        this->removeAt(removeIndex);
        return true;
    }

    bool empty() const {
        return this->count == 0? true:false;
    }
    int size() const {
        return this->count;
    }
    void clear() {
        while(this->head != nullptr) {
            Node* tmpNodeObj = this->head;
            this->head = this->head->next;
            delete tmpNodeObj;
        }
        this->head == nullptr;
        this->tail == nullptr;
        this->count = 0;
    }

    T& get(int index) const {
        if (index >= count || index < 0) {
            throw out_of_range("Index is invalid!");
        }

        int returnIndex = 0;
        Node* traverseLL = this->head;
        while(returnIndex < index) {
            traverseLL = traverseLL->next;
        }
        return traverseLL->data;
    }

    string toString() const {
        Node* traverseLL = this->head;
        ostringstream oss;
        while(traverseLL != nullptr) { 
            oss << traverseLL->data;
            if(traverseLL->next != nullptr) {
                oss << ",";
            }
            traverseLL = traverseLL->next;
        }
        return oss.str();
    }
};

#endif // BOTKIFY_LINKED_LIST_H
