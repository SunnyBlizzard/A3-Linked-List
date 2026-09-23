//
// Created by alecm on 9/22/2026.
//

#pragma once
#include <memory>

template <typename T>
class List {
public:
    virtual ~List() = default;

    virtual void addFront(T* value) = 0; //here virtual tells us to skip to the ArrayList or LinkedList's own addFront method
    virtual void deleteFront() = 0;      //additionally, = 0 means there is not body (JUST inherit the other method)
    virtual bool search(T* value) const = 0;
    virtual void print() const = 0;
};

#include "ArrayList.h"
#include "LinkedList.h"

template <typename T>
std::unique_ptr<List<T>> makeList() {
    return std::make_unique<LinkedList<T>>();
    //return std::make_unique<ArrayList<T>>();

}