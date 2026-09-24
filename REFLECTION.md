1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
   Name exactly what each one frees, and name the two new calls back in the program responsible
   for putting them on the heap in the first place.

One delete call deletes the data stored in our object, the other deletes the data object itself. It's like deleting the stuff inside of a box and then the box too. 
    The data deleted is the new int = 10, while the object deleted is from the new Node<T>. 

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?

The original array contained the actual objects inside of it. When the array was destroyed so was the content inside. The ArrayList however is only storing pointers so we need to clean-up the data at the end of the points as well. 

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?

For us addFront() takes ownership of the pointer by storing it in the list. Although addFront() does not delete it immediately, the list later deletes the stored object in deleteFront() or in the destructor. search() only borrows its pointer to compare values at and never deletes it. 

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?

Both linkedList and arrayList rely on inheritance functions from List, but they use the virtual key word to override List with their own methods. 

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.

Virtual is a keyword I think is instrumental in our implementation. I was a bit skeptic about pointers at first but the more we use them the more I'm realizing the flexibility that they allow. Being albe to define individual methods for each type but still have the correct one at run time saves us from having to use if statements to something to check what datatype we have and then make the appropriate call. 