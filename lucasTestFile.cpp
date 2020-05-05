#include "BST.cpp"

int main(int argc, char **argv)

{
    cout << "Test" << endl;

    DoublyLinkedList<int> *w = new DoublyLinkedList<int>();

    w->insertFront(1);

    w->insertFront(2);

    w->insertFront(3);

    w->printList();

    w->clearList();

    cout <<"None shall remain" << endl;
    w->printList();
    
}