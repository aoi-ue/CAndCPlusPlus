#include <iostream> 

using namespace std; 

class Hero 
{
    public: 
        Hero(int health, char* name): health(health), defaultHealth(health), name(name) {}; 
        virtual void interact(); 
        virtual void melee(Hero& hero); 
        virtual void takeDamage(int damage); 
        virtual void getHeal(int heal); 
        virtual bool setAlive(); 
        virtual bool unableToHeal(); 

        void printHealth(); 
        int getHealth(); 
        int getDefaultHealth(); 
        void setHealth(int health); 
    
    protected: 
        char* name; 
        int health = 0; 
        int defaultHealth; 
        bool isAlive = true; 

    private: 
        int chargeUlti = 0; 
        bool getHealed = true; 
};

void Hero::interact()
{
    cout << name << ": Hello" << endl; 
}

void Hero::melee(Hero& hero) 
{
    if (isAlive) {
        hero.takeDamage(30); 
    }
}

void Hero::takeDamage(int damage) 
{
    setHealth(health - damage); 
}

void Hero::getHeal(int heal) 
{
    if (getHealed) setHealth(health + heal); 
}

bool Hero::unableToHeal() 
{
    getHealed = !getHealed; 
    return getHealed; 
}

int Hero::getDefaultHealth() {
    return defaultHealth; 
}

bool Hero::setAlive() {
    isAlive = true; 
    return isAlive;
}

void Hero::setHealth(int newHealth) 
{ 
    if (newHealth <= 0) {
        health = 0;
        isAlive = false; 
    } 
    else if (newHealth > defaultHealth) {
        health = defaultHealth; 
    }
    else {
        health = newHealth;
    }
}

void Hero::printHealth() 
{
    cout << health << endl; 
}

int Hero::getHealth() 
{
    return health; 
}

class Ana: public Hero 
{
    public:

    Ana(): Hero(200, (char*)"Ana"){};
    void bionicGrenade(Hero& hero); 
    //     void sleepDart(Hero& hero); 
    //     void nanoBoost(Hero& hero); 
    void shootDamage(Hero& enemy); 
    void shootHeal(Hero& ally); 
}; 

void Ana::shootDamage(Hero& enemy) 
{
    if (isAlive) {
        enemy.takeDamage(75); 
        cout << "Ana is still alive" << isAlive << endl; 
    } 
}

void Ana::shootHeal(Hero& ally) 
{
    ally.getHeal(75); 
}

void Ana::bionicGrenade(Hero& enemy) 
{
    enemy.takeDamage(40); 
    enemy.unableToHeal(); 
}

class Reinhardt: public Hero 
{
    public:
    void takeDamage(int damage); 
    void printShield(); 

    Reinhardt(): Hero(600, (char*)"Reinhardt"){};
      
    void melee(Hero& enemy) 
    {
        if (isAlive) {
            enemy.takeDamage(120); 
        }
    }
    //     void earthShatter(Hero& hero); 
    //     void fireStrike(Hero& hero); 
    //     void charge(Hero& hero); 
    void barrierField() 
    {
        shieldUp = !shieldUp;  
    } 

    private: 
        int shield = 2000; 
        bool shieldUp = false; 
}; 

void Reinhardt::takeDamage(int damage) 
{
    if (shieldUp) {
        shield -= damage; 
    } else {
        setHealth(health - damage); 
    }
}

void Reinhardt::printShield() 
{
    cout << shield << endl; 
} 

class Mercy: public Hero 
{
    public: 
    Mercy(): Hero(200, (char*)"Mercy"){};
    void resuscitate(Hero& ally); 
}; 

void Mercy::resuscitate(Hero& ally) 
{
    ally.setAlive(); 
    ally.setHealth(ally.getDefaultHealth()); 
}

int main () {
    Ana ana; 
    Reinhardt rein; 
    Mercy mercy; 

    // ana.melee(rein); 
    // ana.bionicGrenade(rein); 
    //ana.shootDamage(rein); 
    rein.melee(ana); 
    rein.melee(ana); 
    rein.melee(ana); 
    mercy.resuscitate(ana);  
    ana.shootDamage(rein); 

    // //rein.barrierField();
    ana.printHealth(); 
    rein.printHealth();
    // rein.printShield();
}