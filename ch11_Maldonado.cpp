
#include <iostream>
#include <string>
using namespace std;

class Address
{
    public:
        void setAddress(string street, string city, string state);
        void printAddress() const;
        Address(string street = "", string city = "", string state = "");

    private:
        string street;
        string city;
        string state;
};

void Address::setAddress(string s, string c, string st)
{
    street = s;
    city   = c;
    state  = st;
}

void Address::printAddress() const
{
    cout << street << "," << city << "," << state;
}

Address::Address(string s, string c, string st)
{
    street = s;
    city   = c;
    state  =st;
}


class Animal
{
    public:
        void setInfo(string n, int a, string t);
        string getName() const;
        int    getAge()  const;
        string getType() const;
        void   print()   const;

        Animal(string n = "", int a = 0, string t = "");
    
    protected:
        string name;
        int    age;
        string animalType;    
};


class Dog : public Animal
{
    public:
       void setBreed(string b);
       string getBreed() const;
       void print() const;

       Dog(string name = "", int age = 0, string breed = "");
    
    private:
        string breed;
};


class Cat : public Animal
{
    public:
        void setIndoor(bool i);
        bool getIndoor() const;
        void print() const;

        Cat(string name = "", int age = 0, bool indoor = true);

    private:
        bool isIndoor;
};


class Shelter
{
    public:
        void printInfo() const;
        Shelter(string name, string street, string city, string state, int cap);

    private:
        string shelterName;
        Address location;
        int    capacity;
};

void Shelter::printInfo() const
{
    cout << "Shelter: " << shelterName << endl;
    cout << "Address: ";
    location.printAddress();
    cout << endl;
    cout << "Capacity: " << capacity << " animals" << endl;
}





int main()
{
    cout << "=== Animal Shelter System ===" << endl << endl;

    cout << "--- Shelter Info ---" << endl;
    Shelter rescuePets("Rescue Pets Shelter", "1022 Pine St", "Houston", "TX", 50);
    rescuePets.printInfo();
    cout <<  endl;

    cout << "--- Base Class Animals ---" << endl;
    Animal a1("Bravo", 3, "Dog");
    a1.print();
    cout << endl;

    Animal a2;
    a2.setInfo("Mystery", 5, "Cat");
    a2.print();
    cout << endl;

    cout << "--- Dogs ---" << endl;
    Dog d1("Jack", 4, "Pug");
    d1.print();
    cout << endl;

    Dog d2;
    d2.setInfo("Jerry", 2, "Dog");
    d2.setBreed("Bulldog");
    d2.print();
    cout << endl;

    cout << "--- Cats ---" << endl;
    Cat c1("Rose", 3, true);
    c1.print();
    cout << endl;

    Cat c2("Fluffy", 1, true);
    c2.print();
    cout << endl;

    cout << "--- All Animals in Shelter ---" << endl;
    Animal* roster[4];
    roster[0] = &a1;
    roster[1] = &d1;
    roster[2] = &c1;
    roster[3] = &c2;

    for (int i = 0; i < 4; i++)
    {
        cout << "Animal " << i + 1 << ": " << roster[i]->getName() << "(" << roster[i]->getType() << ")" << " - Age: " << roster[i]->getAge() << endl;
    }

    cout << endl << "Program complete." << endl;
    return 0;
}