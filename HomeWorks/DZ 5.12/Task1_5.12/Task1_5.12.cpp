#include <iostream>
#include <stdexcept>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value) {
        try {
            Node* newNode = new Node(value); 
            if (!head) { head = tail = newNode;}
            else 
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Error: There is not enough memory to add the item."<<std::endl;
            throw;
        }
    }

    void remove() {
        if (!head) 
        {
            throw std::underflow_error("Error: Attempt to delete from an empty list.");
        }
        Node* temp = tail;
        if (head == tail) {head = tail = nullptr; }
        else 
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void print() const {
        if (!head)
        {
            std::cout << "The list is empty." << std::endl;
            return;
        }
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList list;

    try
    {
        list.add(rand()%100);
        list.add(rand() % 100);
        list.add(rand() % 100);
        list.print();

        list.remove();
        list.print();

        list.remove();
        list.remove();

        list.remove();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        while (true) {list.add(1);}
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}