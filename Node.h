//
// Created by alecm on 9/17/2026.
//
# pragma once
#include <iostream>
#include <ostream>

// OLD Node.h
/*
template <typename T>

class Node {

public:
    T *value;
    Node<T> *next;

    Node(T *value) {
        this->value=value;
        next = nullptr;
    }

    void print() {
        value->print();
    }

    void setNext(Node<T> *next) {
        this->next = next;
    }

    void setValue(T *value) {
        this->value = value;
    }
}; */

//New Node.h
template <typename T>
class Node {
public:
    T* data;
    Node<T>* next;

    explicit Node(T* value): data(value), next(nullptr) {} //explicit helps protect T* and keep it a pointer
};
