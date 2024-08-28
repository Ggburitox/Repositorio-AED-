#ifndef REPOSITORIOAED_FORWARDLIST_H
#define REPOSITORIOAED_FORWARDLIST_H

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



};






#endif //REPOSITORIOAED_FORWARDLIST_H
