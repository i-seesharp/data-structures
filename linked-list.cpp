#include<iostream>
#include<string>

using namespace std;

class Node{
    public:
        int value;
        Node *next;
};

class LinkedList{
    public:
        Node *head;
        Node *tail;
        int size;
        LinkedList(){
            this->head = NULL;
            this->size = 0;
        }
        ~LinkedList(){
            if(this->size==0) free(this->head);
            else{
                Node *curr = this->head;
                Node *temp = this->head;
                while(curr != NULL){
                    temp = curr->next;
                    free(curr);
                    curr = temp;
                }
            }
        }
        void append(int element){
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->value = element;
            new_node->next = NULL;
            this->size++;

            if(this->size == 0) this->head = new_node;
            else{
                Node *curr = this->head;
                while(curr->next != NULL){
                    curr = curr->next;
                }
                curr->next = new_node;
            }
        }
        void insert(int index, int element){
            if(index==this->size){
                this->append(element);
                return;
            }
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->value = element;
            new_node->next = NULL;
            if(index>this->size-1){
                cout << "Error: This index does not exist.\n";
                return;
            }

            Node *curr = this->head;
            if(index==0){
                new_node->next = this->head;
                this->head = new_node;
                this->size++;
            }else{
                for(int i=0;i<index-1;i++){
                    curr = curr->next;
                }
                new_node->next = curr->next;
                curr->next = new_node;
                this->size++;
            }
        }
        int find(int element){
            Node *curr = this->head;
            int position = 0;
            while(curr != NULL){
                if(curr->value == element) return position;
                curr = curr->next;
                position++;
            }
            return -1;
        }
        void remove(int index){
            if(index > this->size-1) return;
            int i=0;
            Node *curr = this->head;
            while((curr != NULL) && (i<index-1)){
                curr = curr->next;
                i++;
            }
            Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        void print_elements(){
            Node *curr = this->head;
            while(curr != NULL){
                cout << curr->value << "\t";
                curr = curr->next;
            }
            cout << endl;
        }

};

int main(){
    
    //Testing the functionality of the linked list
    LinkedList list;
    list.append(5);
    list.insert(1,10);
    list.append(2);
    list.insert(1, 3);
    list.print_elements();
    list.remove(2);
    list.print_elements();
    return 0;
}