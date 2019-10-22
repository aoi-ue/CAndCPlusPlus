#include <iostream> 

using namespace std; 

class Human 
{
    public: 
        int age; 
        const char* name; 
        int getWeight(); 

    Human() {};  

    ~Human() 
    {
        cout << "bitch dead"; 
    }

    Human(int _age, const char* _name) 
    {
        age = _age; 
        name = _name; 
    }
    
    private: 
        float weight; 
}; 

int Human:: getWeight() 
{
    return weight; 
}

int main() 
{
    Human trash; 
    cout << trash.name; 
}


