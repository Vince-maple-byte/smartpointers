#include "unique_pointer.hpp"
#include <iostream>

int main() {
    unique_pointer<int> pInt = unique_pointer(40);
    unique_pointer<int[]> pInt2 = unique_pointer<int[]>(new int[3]);
    for(int i = 0; i < 3; i++){
        *(pInt2.get() + i) = i+1;
    }
    
    
    std::cout << "pInt value " << *pInt.get() << "\n";
    for(int i = 0; i < 3; i++){
        std::cout << "pInt2 at index " << i << " equals to " << *(pInt2.get() + i)<< "\n";
    }
    
    //unique_pointer<int> pCopy = pInt; Gives out an error good;

    
    

    return 0;
}