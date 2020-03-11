#include <iostream>
#include <cstring>

struct Node {
    int data;
    Node* next;
};

Node* push_front(Node* head, int data) {
    Node* tmp = new Node{data,nullptr};
    tmp->next = head;
    return tmp;
}

void push_back(Node* head, int data) {
    Node* tmp = new Node{ data,nullptr };
    while(head -> next !=nullptr){
        head = head -> next;


    }
    head->next=tmp;
}

void clear(Node* head) {
    while (head) {
        auto del = head;
        head = head->next;
        delete del;
    }
}

void print_list(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout <<"nullptr"<< std::endl;
}

int main()
{   
    Node* list{nullptr};
    list = push_front(list, 10);
    list = push_front(list, 40);
    print_list(list);
    push_back(list, 90);
    print_list(list);
    clear(list);
    list = nullptr;
    print_list(list);
    return 0;
}

