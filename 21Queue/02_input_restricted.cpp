// insertion by rear end only
// deletion from front & rear both

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

    void enqueue( int data )
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

    void dequeue_from_front()
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

    void dequeue_from_rear()
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

        if( rear == 0 && front > 0 )
        {
            rear = size-1 ;
            return ;
        }

        rear-- ;
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
    q.enqueue(100) ;
    q.enqueue(200) ;
    q.enqueue(300) ;
    q.enqueue(400) ;
    q.enqueue(500) ;
    q.dequeue_from_front() ;
    q.enqueue(30000) ;
    q.display() ;
    q.peek() ;

    q.dequeue_from_rear() ;
    q.display() ;
    return 0;
}