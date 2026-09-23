//
// Created by alecm on 9/15/2026.
//

#pragma once

#include <iostream>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> {
public:
    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }
    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
    }
    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }
    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }
private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;

    //OLD STUFF
    /*
    ArrayList():size(0) {

    }
    void add(T item) { //O(n)
        if (size < CAPACITY) {
            for (int i = size; i > 0; i--) {
                data[i] = data[i - 1];
            }
            data[0] = item;
            size++;
        }
        else {
            cout << "Capacity Overflow" << endl;
        }
    }

    void deleteFront() { //O(n)
        if (size == 0) {
            cout<<"Array is empty"<<endl;
            return;
        }
        else {
            for (int i = 0; i < size-1; i++) {
                data[i] = data[i + 1];
            }
            size--;
        }
    }

    bool search(T item) { //O(n)
        if (size == 0) {
            cout<<"Array is empty"<<endl;
            return false;
        }
        else {
            for (int i = 0; i < size; i++) {
                if (data[i] == item) {
                    return true;
                }
            }
            return false;
        }
    }

    void printArray() { //O(n)
        for (int i = 0; i < size; i++) {
            cout << data[i] << ", ";
        }
        cout<<endl;
    }

    void addToBack(T item) { //O(1)
        data[size] = item;
        size++;
    }

    void deleteBack() { //O(1)
        size--;
    }



private:
    static const int CAPACITY = 20; //max capacity of the array
    T data[CAPACITY]; //physical array of data // using T with the template lets the array adapt to what ever data type it needs
    int size; //current count of values in array
*/
};
