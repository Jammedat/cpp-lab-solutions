#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person() : name(""), age(0) {}

    void enterData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore(); // To ignore the newline character left in the buffer
    }

    void printAddress() const {
        cout << "Address of this object: " << this << endl;
    }

    virtual void printDetails() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Student
class Student : public Person {
public:
    void enterData() {
        Person::enterData();
    }

    void printDetails() const override {
        cout << "Student - ";
        Person::printDetails();
    }
};

// Derived class: Employee
class Employee : public Person {
public:
    void enterData() {
        Person::enterData();
    }

    void printDetails() const override {
        cout << "Employee - ";
        Person::printDetails();
    }
};

int main() {
    // Create objects of base and derived classes
    Person p1, p2;
    Student s1, s2;
    Employee e1, e2;

    // Enter data for each object
    cout << "Enter data for Person 1:" << endl;
    p1.enterData();
    cout << "Enter data for Person 2:" << endl;
    p2.enterData();

    cout << "Enter data for Student 1:" << endl;
    s1.enterData();
    cout << "Enter data for Student 2:" << endl;
    s2.enterData();

    cout << "Enter data for Employee 1:" << endl;
    e1.enterData();
    cout << "Enter data for Employee 2:" << endl;
    e2.enterData();

    // Print addresses of each object
    cout << endl << "Printing addresses:" << endl;
    p1.printAddress();
    p2.printAddress();
    s1.printAddress();
    s2.printAddress();
    e1.printAddress();
    e2.printAddress();

    // Print details of each object
    cout << endl << "Printing details:" << endl;
    p1.printDetails();
    p2.printDetails();
    s1.printDetails();
    s2.printDetails();
    e1.printDetails();
    e2.printDetails();

    // Calculate size of each object (including base and derived parts)
    cout << endl << "Size of each object (in bytes):" << endl;
    cout << "Person: " << sizeof(Person) << endl;
    cout << "Student: " << sizeof(Student) << endl;
    cout << "Employee: " << sizeof(Employee) << endl;

    return 0;
}
