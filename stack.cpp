#include<iostream>
#include<string>

using namespace std;

class Stack{
    public:
        int size;
        int capacity;
        int *arr;
        Stack(){
            this->capacity = 1;
            this->size = 0;
            this->arr = (int *)malloc(this->capacity*sizeof(int));
        }
        ~Stack(){
            free(this->arr);
        }
        int length(){
            return this->size;
        }
        void push(int element){
            *(arr+this->size) = element;
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
            if(this->size == 0) return -1;
            this->size--;
            return *(this->arr + this->size);
        }
        int top(){
            if(this->size == 0) return -1;
            return *(this->arr + this->size - 1);
        }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    cout << st.top() << endl;
    st.pop();
    st.push(3);
    while(st.length() != 0){
        cout << st.pop() << "\t";
    }
    cout << "\n";
    return 0;
}