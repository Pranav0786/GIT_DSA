// insertion from rear and front both sides
// deletion from front only

#include<bits/stdc++.h>
using namespace std;

class Q
{
    const int size = 5 ;

    int front ;
    int rear ;
    int arr[5] ;

    public:
    Q()
    {
        front = -1 ;
        rear = -1 ;
    }

    inline bool isempty()
    {
        if( front == -1 && rear == -1 )
            return 1 ;
        return 0 ;
    }
    inline bool isfull()
    {
        if( (rear+1) % size == front )
            return 1 ;
        return 0 ;
    }

    void enqueue_from_rear( int data )
    {
        if( isfull() )
        {
            cout << "Q is full can't inserted\n" ;
            return ;
        }

        if( front == -1 )
        {
            front++ ;
            rear++ ;
            arr[rear] = data ;
            return ;
        }

        rear = (rear+1) % size ;
        arr[rear] = data ;
    }
    void enqueue_from_front( int data )
    {
        if( isfull() )
        {
            cout << "Q is full can't inserted\n" ;
            return ;
        }

        if( front == -1 )
        {
            front++ ;
            rear++ ;
            arr[front] = data ;
            return ;
        }

        if( front != 0 )
        {
            front-- ;
            arr[front] = data ;
            return ;
        }

        front = size-1 ;
        arr[front] = data ;
    }

    void dequeue()
    {
        if( isempty() )
        {
            cout << "Q is empty\n" ;
            return ;
        }

        if( front == 0 && rear == 0 ) 
        {
            front = -1 ;
            rear = -1 ;
            return ;
        }

        front = ( front+1 ) % size ;
    }

    void display()
    {
        if( isempty() )
        {
            cout << "Q is empty\n" ;
            return ;
        }

        if( front <= rear )
        {
            for( int i=front ; i<=rear ; i++ )
                cout << arr[i] << " " ;
            cout << endl ;

            return ;
        }

        for( int i=front ; i< size ; i++ )
            cout << arr[i] << " " ;

        for( int i=0 ; i<= rear ; i++ )
            cout << arr[i] << " " ;
        cout << endl ;

    }

    void peek()
    {
        if( isempty() )
        {
            cout << "Q is empty\n" ;
            return ;
        }

        cout << "Peek element is: " << arr[front] << endl ;
    }

};

int main()
{
    Q q ;
    q.enqueue_from_front(100) ;
    q.enqueue_from_front(200) ;
    q.enqueue_from_rear(300) ;
    q.enqueue_from_front(400) ;
    q.enqueue_from_rear(500) ;
    q.display() ;
    q.dequeue() ;
    q.enqueue_from_rear(30000) ;
    q.display() ;
    q.peek() ;

    q.dequeue() ;
    q.display() ;
    return 0;
}