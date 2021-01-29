#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

class Character {
public:
    virtual int highAttack() = 0;
    virtual int middleAttack() = 0;
    virtual int lowAttack() = 0;
    virtual double damageBlock() = 0;
    virtual int specialAttack() = 0;
private:
    int m_characterHP;
    int m_weaponHP;
};

class Ch {
    int m =0;
};

class DeathMoroz : Character {

};


int main() {



    return 0;
}

