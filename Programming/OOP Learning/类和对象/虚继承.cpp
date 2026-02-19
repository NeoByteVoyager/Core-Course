#include<bits/stdc++.h>
using namespace std;
class Animal {
public:
    int age;
    Animal(int a) : age(a) {}
};

class Mammal : public Animal {
public:
    Mammal(int a) : Animal(a) {}
};

class Bird : public Animal {
public:
    Bird(int a) : Animal(a) {}
};

class Bat : public Mammal, public Bird {
public:
    Bat() : Mammal(1), Bird(2) {}
    
};

int main(){
	Bat b; 
	cout<<b.Bird::age;
	return 0;
} 
