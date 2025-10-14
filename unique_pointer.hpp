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

        unique_pointer(unique_pointer& pointer) = delete;

        unique_pointer& operator=(unique_pointer& pointer) = delete;


        unique_pointer(unique_pointer&& pointer) {
            data = pointer.data;
            pointer.data = null;
        }

        unique_pointer& operator=(unique_pointer&& pointer) {
            if(this != &pointer) {
                delete data;
                data = pointer.data;
                pointer.data = null;
            }
            return *this;
        }

        unique_pointer* operator*() {
            return &this;
        }

        unique_pointer& operator->() {
            return *this;
        }

        boolean operator==(unique_pointer& pointer) {
            return this == pointer;
        }
        
        boolean operator!=(unique_pointer& pointer) {
            return this != pointer;
        }

        T* get() const{
            return this->data;
        }

        release(){}

        swap(){}



};