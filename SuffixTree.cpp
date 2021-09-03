#include <iostream>
#include <String>
#include <algorithm>

struct compairfunc{
    std::string container;
    compairfunc(const std::string input){
        container=input;
    };
    bool operator()(int a,int b){
        if(std::lexicographical_compare(this->container.substr(a).begin(),this->container.substr(a).end(),this->container.substr(b).begin(),this->container.substr(b).end()))
            return true;
        else
            return false;
    };
};


class StringDS{
private:
    int counter=0;
    std::string container;
    int commonchar(std::string first, std::string second){
        int count=0;
        int minlen=first.length() < second.length() ? first.length() : second.length();
        for (int i = 0; i < minlen; i++)
        {
            if(first[i]==second[i])
                count++;
            else
                break;
        }
        return count;
        
    }
public:
    template<typename T>
    void printarr(T arr,int size){
        for (int i = 0; i < size; i++)
        {
            std::cout << this->container.substr(arr[i]) << "\n";
        }
    }

    // void print

    int* LCParrayfind(){
        int* suffixarray=new int[this->counter];
        int* LCParray=new int[this->counter];
        for (int i = 0; i < this->counter; i++)
        {
            suffixarray[i]=this->container.length()-i-1;
        }
        std::sort(suffixarray,suffixarray+this->counter,compairfunc(this->container));
        printarr<int*>(suffixarray,this->counter);
        LCParray[0]=0;
        for (int i = 1; i < this->counter; i++){
            LCParray[i]=this->commonchar(this->container.substr(suffixarray[i-1]),this->container.substr(suffixarray[i]));
        }
        return LCParray;
    };

    StringDS(){
            std::cout << "enter string" << ": ";
            std::cin >> this->container;
            this->counter=this->container.length();
        // for (int i = 0; i < this->counter; i++)
        // {
        //     std::cout << "enter string " << i+1 << ": ";
        //     std::cin >> this->container[i];
        // }
        
    };
};

int main() {
    StringDS DS;
    // DS.print();
    DS.LCParrayfind();
    return 0;
}

