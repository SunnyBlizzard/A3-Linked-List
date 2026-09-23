//
// Created by alecm on 9/17/2026.
//

#pragma once
#include "Node.h"
#include "List.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr) {}
    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
    }
    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }
    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }
    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }
private:
    Node<T>* head_;


    // OLD STUFF
    /*
    Node<T> *head;
    Node<T> *tail;
    int size;

    LinkedList(T *value){
        Node<T> *temp = new Node<T>(value);
        head = temp;
        tail = nullptr;
        size = 1;
    };

    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void print() {
        Node<T> *temp = head;
        while (temp != nullptr) {
            temp->print();
            temp = temp->next;
        }
    }

    void append(T *value) {
        Node<T> *newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        } //OLD OLD STUFF
        Node<T> *temp = head;
        while (temp->next != nullptr) { //implementation assuming no tail pointer
            temp = temp->next;
        }
        temp->next = newNode;
        tail->next = newNode;
        tail = tail->next;
        size++;
    }

    */
};
