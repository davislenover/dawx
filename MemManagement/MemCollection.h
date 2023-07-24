#ifndef DAWX_MEMCOLLECTION_H
#define DAWX_MEMCOLLECTION_H

#include <set>

template<typename T>
class MemCollection {
private:
    std::set<T*> objPointerCollection;
public:
    MemCollection() {};
    void addObject(T* objToAdd) {
        // Using a set so no need to check if the item already exists
        this->objPointerCollection.insert(objToAdd);
    };
    void removeObject(T* objToRemove) {
        if (this->objPointerCollection.contains(objToRemove)) {
            delete objToRemove;
            // Calling erase on a vector of pointers will NOT call delete on the given object the pointer points to
            this->objPointerCollection.erase(&objToRemove);
        };
    };
    void killAllObjects() {
        for(T* objPtr : this->objPointerCollection) {
            delete objPtr;
        };
        this->objPointerCollection.clear();
    };
    int size() {
        return this->objPointerCollection.size();
    };
};


#endif
