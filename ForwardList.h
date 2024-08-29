#ifndef REPOSITORIOAED_FORWARDLIST_H
#define REPOSITORIOAED_FORWARDLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class ForwardList {
private:
    Node<T>* head;
public:
    ForwardList(): head(nullptr) {};
    void pushfront(T data){
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void push_back(T data){
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    T front(){
        return head->data;
    }

    T back() {
        Node<T> *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }
    void pop_front(){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back(){
        Node<T>* temp = head;
        Node<T>* post = head->next;
        while(post->next != nullptr){
            temp = temp->next;
            post = post->next;
        }
        temp->next = nullptr;

    }


    void print(){
        Node<T>* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    T operator[](int pos){
        Node<T>* temp = head;
        for (int i = 0; i < pos; i++){
            temp = temp->next;
        }
        cout << temp->data << endl;
        return temp->data;
    }

    bool empty(){
        if (head == nullptr){
            cout << "Empty" << endl;
            return true;
        } else {
            cout << "Not empty" << endl;
            return false;
        }
    }

    int size(){
        Node<T>* temp = head;
        int i = 1;
        while (temp->next != nullptr){
            temp = temp->next;
            i++;
        }
        cout << "El size de la lista es: " << i << endl;
        return i;
    }

    void clear(){
        while (head != nullptr){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void reverse(){
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while (current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void insertion_sort(){
        Node<T>* temp = head;
        Node<T>* temp2 = head->next;
        Node<T>* temp3 = head->next->next;
        while (temp3 != nullptr){
            if (temp->data > temp2->data){
                temp->next = temp3;
                temp2->next = temp;
                head = temp2;
            }
            temp = temp->next;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
    }

    void erase(int dato) {
        Node<T>* curr = head;
        Node<T>* prev = nullptr;
        while(curr != nullptr){
            if(curr->data == dato){
                if (prev == nullptr){
                    head = curr->next;
                }
                else{
                    prev->next = curr->next;
                }
                Node<T>* NodoTD = curr;
                curr = curr->next;
                delete NodoTD;
            }
            else{
                prev = curr;
                curr = curr->next;
            }

        }
    }

};




//leetcode
//Gtest


};

#endif //REPOSITORIOAED_FORWARDLIST_H
