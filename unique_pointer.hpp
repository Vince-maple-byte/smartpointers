#pragma once

template <typename T>
class unique_pointer {
    T* data;

    public:
        unique_pointer(T data = null){
            data = new T(data);
        }

        ~unique_pointer() {
            delete data;
        }

        //Need to make the copy and move operator 

};