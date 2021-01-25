#include<iostream>
#include<string>

using namespace std;

class DynamicArray{
    public:
        int *arr;
        int size;
        int capacity;
        int *tail;
        DynamicArray(){
            this->size = 0;
            this->capacity = 1;
            this->arr = (int *)malloc(this->size*sizeof(int));
            this->tail = NULL;
        }
        DynamicArray(const unsigned int capacity){
            this->size = 0;
            this->capacity = capacity;
            this->arr = (int *)malloc(this->size*sizeof(int));
        }
        ~DynamicArray(){
            free(this->arr);
        }
        void insert(int element){
            *(this->arr + this->size) = element;
            this->size++;
            if(this->size == this->capacity){
                this->capacity = this->capacity*2;
                int *temp = (int *)malloc(this->capacity*sizeof(int));
                for(int i=0;i<this->size;i++){
                    *(temp+i) = *(this->arr + i);
                }
                free(this->arr);
                this->arr = temp;
            } 

        }
        int pop(){
            this->size--;
            return *(this->arr + this->size);
        }
        int remove(int index){
            int element = *(this->arr + index);
            if(index==this->size-1) this->pop();
            else{
                for(int i=index+1;i<this->size;i++){
                    *(this->arr + i - 1) = *(this->arr + i);
                }
                this->size--;
            }
            return element;
        }
        void print_elements(){
            for(int i=0;i<this->size;i++){
                cout << *(this->arr + i) << "\t";
            }
            cout << endl;
        }

};

int main(){
    DynamicArray array;
    //Testing the functionality of the dynamic array
    array.insert(10);
    array.print_elements();
    array.insert(5);
    array.insert(7);
    cout << "Popped element is :" << array.pop() << "\n";
    array.insert(20);
    array.insert(15);
    cout << "Removed at index 1 : " << array.remove(1) << "\n";
    array.print_elements();

    return 0;
}