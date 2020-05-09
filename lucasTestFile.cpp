//https://www.cplusplus.com/doc/tutorial/files/

#include "FileManager.cpp"

int main(int argc, char **argv)

{
    FileManager *testManager = new FileManager();

    BST<Person> *myStuds = new BST<Person>();

    DoublyLinkedList<Person> *studStack = new DoublyLinkedList<Person>;

    DoublyLinkedList<Person> *facStack = new DoublyLinkedList<Person>;

    DoublyLinkedList<int> *emptyList = new DoublyLinkedList<int>();

    emptyList->insertFront(1);
    emptyList->insertFront(2);



//     _____      __     ____        __       
//    / ___/___  / /_   / __ \____ _/ /_____ _
//    \__ \/ _ \/ __/  / / / / __ `/ __/ __ `/
//   ___/ /  __/ /_   / /_/ / /_/ / /_/ /_/ / 
//  /____/\___/\__/  /_____/\__,_/\__/\__,_/  
//                                            

//     _____ __            __    
//    / ___// /___  ______/ /____
//    \__ \/ __/ / / / __  / ___/
//   ___/ / /_/ /_/ / /_/ (__  ) 
//  /____/\__/\__,_/\__,_/____/  
//                               
    Person *rosie = new Person();
    rosie->setId(35);
    rosie->setGPA(3.8);
    rosie->setMajor("Accounting");
    rosie->setStanding("Senior");
    rosie->setName("Rosie O Donald");
    rosie->setAdvisor(50);

    Person *frank = new Person();
    frank->setId(30);
    frank->setGPA(1.2);
    frank->setMajor("CompSci");
    frank->setStanding("Junior");
    frank->setName("Frank Azark");
    frank->setAdvisor(20);

    Person *bob = new Person();
    bob->setId(40);
    bob->setGPA(3.29);
    bob->setMajor("Finance");
    bob->setStanding("Senior");
    bob->setName("Bob Miller");
    bob->setAdvisor(70);


    studStack->insertFront(*bob);
    studStack->insertFront(*frank);
    studStack->insertFront(*rosie);


//      ______          
//     / ____/___ ______
//    / /_  / __ `/ ___/
//   / __/ / /_/ / /__  
//  /_/    \__,_/\___/  
//                      
    Person *lucas = new Person();
    lucas->setId(50);
    lucas->setName("Lucas Torti");
    lucas->setLevel("Lecturer");//Lecturer, assistant professor, associate professor
    lucas->setDepartment("Keck Center");
    lucas->setAdvisees(emptyList);//starting to delimeter and then create a new doubly linked list and add everything in between, pass in doubly linked list to set advisee

    Person *wyatt = new Person();
    wyatt->setId(20);
    wyatt->setName("wyatt miller");
    wyatt->setLevel("professor");//Lecturer, assistant professor, associate professor
    wyatt->setDepartment("Argyros");
    wyatt->setAdvisees(emptyList);

    Person *chris = new Person();
    chris->setId(70);
    chris->setName("chris change");
    chris->setLevel("assistant professor");//Lecturer, assistant professor, associate professor
    chris->setDepartment("dance school");
    chris->setAdvisees(emptyList);

    facStack->insertFront(*lucas);
    facStack->insertFront(*wyatt);
    facStack->insertFront(*chris);


//    ______          __ 
//   /_  __/__  _____/ /_
//    / / / _ \/ ___/ __/
//   / / /  __(__  ) /_  
//  /_/  \___/____/\__/  
//                                                 


    testManager->saveStudFile(*studStack);
    testManager->getStudData();
    // testManager->saveStudFile(*facStack);
    // testManager->getFacData();
    

}