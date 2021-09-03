#include <iostream>
#include <vector>

class PriorityQueue
{
private:
    std::vector<int> stack;
    //swap function
    int swap(int *a, int *b){
        // std::cout << *a << " " << *b << "\n";
        int temp=*a;
        *a=*b;
        *b=temp;
        return 0;
    };
    

    //max heap creation greatest element on top to change into min change the comparisions
    void heapify(int i){
        //children
        int left=i*2;
        int right=(i*2)+1;

        //if left branch exist
        //if its greater than size then return right is gauranted to not exist
        if( left>this->stack.size() )
            return;

        //if left child greater than parent then proceed to swap
        if(this->stack[left-1]>this->stack[i-1]){
            this->swap(&this->stack[left-1],&this->stack[i-1]);
            this->heapify(left);
        }

        //check if right brach exist
        //if it is greater that size of array the right branch doesnt exist and return
        if( right>this->stack.size() )
            return;
        
        //if right children is greater than parent then swap
        if(this->stack[right-1]>this->stack[i-1]){
            this->swap(&this->stack[right-1],&this->stack[i-1]);
            this->heapify(right);
        }
        return;
    };

    void maxheap(int i){
        //parent of 1 index
        int parent=i/2;
        
        //weve reached the top
        if(i<=1)
            return;

        //children i is greater than parent then swap and go next
        if(this->stack[i-1] > this->stack[parent-1]){
            this->swap(&this->stack[i-1], &this->stack[parent-1]);
            //now greater element is in parent
            this->maxheap(parent);
        }
        return;
    };

public:
    void print(){
        for (int i = 0; i < this->stack.size(); i++)
        {
            std::cout << this->stack[i] << " ";
        }
        std::cout << "\n";
    };

    PriorityQueue(std::vector<int>& mat){
        for (int i = 0; i < mat.size(); i++)
            this->stack.push_back(mat[i]);
        for (int i = this->stack.size(); i >= 1; i--)
            this->heapify(i);
    };

    void insert(int t){
        this->stack.push_back(t);
        this->maxheap(this->stack.size());
    };

    int pop(){
        //if empty then return max negetive
        if(this->stack.size()==0)
            return INT_MIN;
        
        //interchange the top of tree to end so max is found at the end
        this->swap(&this->stack[0],&this->stack[this->stack.size()-1]);
        int maxima=this->stack[this->stack.size()-1];
        this->stack.pop_back();

        //check if the tree is non empty then heapify top
        if(this->stack.size()!=0)
            this->heapify(1);
        
        //return the maximum for max heap
        return maxima;
    };

    ~PriorityQueue(){
        
    };
};

int main(){
    std::vector<int> mat={10,20,15,12,40,25,18};
    PriorityQueue p(mat);
    p.print();
    // p.insert(100);
    std::cout << p.pop() << " popped\n";
    std::cout << p.pop() << " popped\n";
    p.print();
}