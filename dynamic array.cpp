#include<iostream>
using namespace std;
class Array
{
    private:
    int *array;
    int size;
    int capacity;
    
    public:
     Array()
    {
        array = new int[1];
        size=0;
        capacity=1;
        
    }
    void insert(int value)
    {
        if(size==capacity)
        {
            resize();
        }
        size++;
        array[size-1]=value;
    }
    void insertat(int index,int value)
    {
        resize();
        for( int i=size;i>=index;i--)
        {
           array[i]=array[i-1]; 
        }
        array[index]=value;
        size++;
    }
    int get(int index)
    {
        if(index>=size)
        {
            cout<<"index not present"<<" ";
        }
        return array[index];
    }
    void resize( )
    {
        int *temp = new int[2*size];
        for( int i=0;i<size;i++)
        {
            temp[i]=array[i];
        }
        capacity=2*capacity;
        delete []array;
        array=temp;
    }
    void printarray()
    {
        for(int i=0;i<size;i++)
        {
            cout<<array[i]<<" ";
            
        }
        cout<<endl;
    }
    int getsize()
    {
        return size;
    }
    int getcapacity()
    {
        return capacity;
    }
    ~Array()
    {
        delete []array;
        size=0;
        capacity=0;
    }
    
    
};
int main()
{ 
    int index;
    Array a;
    a.insert(20);
    a.insert(30);
    a.insert(40);
    a.insert(50);
    a.insertat(2,10);
    a.printarray();
    cout<<"size is"<<a.getsize()<<"and capacity is"<<a.getcapacity()<<endl;
    cout<<"enter the index you want to search"<<endl;
    cin>>index;
    cout<<"element is"<<a.get(index)<<endl;
    
    return 0;
}