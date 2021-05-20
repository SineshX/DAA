#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
// linked list with tail
// with some adv feature :)
// dont try its not normal LL ,

class linkedlist
{
private:
    node *head, *tail, *advtail;
    int size;
    //todo : add custom sized LL
    // createlist(int n)
    //currently it is flexible
public:
    linkedlist()
    {
        //one advance node will bw created // i know its not legal :)
        size = 0;
        head = new node;       //init with memory alloaction of head node
        tail = advtail = head; // all are pointing to head;
        tail->data = 0;
        tail->next = NULL;
    }
    void insert_end(int data) //insert at the end
    {
        tail = advtail;    // last time advtail ko memory allocate thi
        tail->data = data; //  data in advtail = tail  me :)
        //kyuki head ne init me new node create kr diya tha :)
        advtail = new node;   // we are making one advance node XD
        // traditionally if else se head ko check kiya jata tha 
        // now i made this kyuki mujhe mann nahi tha if use krne ka 
        advtail->next = NULL; // tail(jo ki adv hai) ke next me null 😉
        tail->next = advtail; // advtail(new adv node) ka address tail me
        size++;
    }
    void insert_beg(int data)
    {
        node *ptr = new node;
        ptr->data = data;
        ptr->next = head;
        head = ptr;
        size++;
    }
    void insert_at(int p, int data)
    {
        if (p == 1)
        {
            insert_beg(data);
        }
        // say (p)osition  = 5
        else if (p > size + 1) //  p  = 7 or ++
        {
            cout << "linked list overflow XD" << endl;
            cout << " LL size is :" << size << " , and you are trying to insert at : " << p << endl;
        }
        else if (p == size + 1) // p = 6
        {
            insert_end(data);
        }
        else // p = 3
        {
            node *ptr = head;
            for (int i = 0; i < p - 2; i++) //dimag lagaO on pen paper
            {
                ptr = ptr->next;
            }
            //ptr is just pre pointer of our actual node
            node *ptr1 = new node; // create node
            ptr1->data = data;     // put data

            ptr1->next = ptr->next;
            ptr->next = ptr1; // as simple as pen paper
            size++;           //almost forget it
        }
    }

    int getsize() { return size; }

    void display()
    {
        node *ptr = head;
        cout << "\nHere is yout  LL :  ";
        for (int i = 0; i < size; i++)
        {
            cout << ptr->data << " ,";
            ptr = ptr->next;
        }
        cout << endl;
    }
    //des~
    ~linkedlist()
    {
        //deletelist()
        node *temp;
        for (int i = 0; i <= size; i++)
        //coze we have one one adv node
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        // cout<<"Successfully deleted all nodes of LL"<<endl;
    }
};

// things u can try
// myLL.display()
// myLL.insert_end(data) // insert at end
// myLL.insert_beg(data) // beganing
// myLL.insert_at(position,data)
//
// todo :  delete : beg end mid
//
//

/*
int main()
{
    linkedlist myLL;
    
    myLL.insert_end(20);

    myLL.display();

    return 0;
}

*/