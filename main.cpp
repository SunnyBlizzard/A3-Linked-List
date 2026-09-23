#include <iostream>
#include "List.h"
#include "Data.h"
int main() {
    std::unique_ptr<List<int>> list = makeList<int>();
    list->addFront(new int(10));
    list->addFront(new int(20));
    list->addFront(new int(30));
    list->print();
    int key = 20;
    std::cout << "search(20): "
    << (list->search(&key) ? "found" : "not found") << std::endl;
    list->deleteFront();
    list->print();
    std::unique_ptr<List<Data>> roster = makeList<Data>();
    roster->addFront(new Data(1, "Alice"));
    roster->addFront(new Data(2, "Bilal"));
    roster->addFront(new Data(3, "Chen"));
    roster->print();
    Data query(2, "");
    std::cout << "search(id 2): "
    << (roster->search(&query) ? "found" : "not found")
    << std::endl;
    return 0;
}



//OLD STUFF
/*
#include <iostream>
class Box {
    public:
    Box(int value): data(new int(value)){}

    ~Box() {
        delete data;
        data = nullptr;
    }
    int value() {
        return *data;
    }

    private:
    int* data;
};

int main() {
//practice part 1
    /*
    int x = 5;
    int* p =  &x; //pointer p in stack memory // int* is an int pointer // &x is the memory address of x
    std::cout << x << std::endl; //print x's value
    std::cout << *p << std::endl; //print dereferenced pointer (the actual value at that address)
    std::cout << p << std::endl; //print the memory address
    std::cout << &p << std::endl; //print p's memory address (the location of x's memory address)
    *p = 10; //changes the actual value at p's stored address (x's value)
    std::cout << *p << std::endl;
    std::cout << p << std::endl; //same value/print as line below
    std::cout << &x << std::endl;
    */
//practice part 2
    /*
    int* p = new int(5); //new int pointer that points to our new int value's memory address *NOTE* this int variable has no name
    //these variables are on the heap and are long lasting
    std::cout << *p << std::endl; //dereferencing pointer to get its value instead
    std::cout << p << std::endl; //print the address stored by p
    delete p; //destructor in classes, frees up the memory (frees up the memory at the address stored in p, not p itself)
    p = nullptr; //need the pointer to go somewhere so we assign null
    */
/*practice part 3 (Box Class)
    Box *box1 = new Box(5);
    std::cout << box1->value() << std::endl; //equivilent of .value() but its a pointer so -> instead of .
    delete box1;
    std::cout << box1->value() << std::endl; //prints giberish because its a nullptr

    return 0;
}


*/