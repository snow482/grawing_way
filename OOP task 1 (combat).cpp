#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>
#include <ctime>


int RandomThrow (int start, int rangeValue){
    int throwValue = 0;
    srand(time(0));
    throwValue = 1 + rand() % 20;
    return throwValue;
}

class Character {
public:
    Character(std::string& name, int hp, int AC, int attackThrow, int damageThrow, int weaponHp)
        : m_name(name), m_hp(hp), m_AC(AC), m_attackThrow(attackThrow), m_damageThrow(damageThrow), m_weaponHP(weaponHp)
        {}

    virtual void run()
    {
        std::cout << "run" << std::endl;
    }
    virtual int highAttack() = 0;
    virtual int middleAttack() = 0;
    virtual int lowAttack() = 0;
    virtual double damageBlock(int shield){

    };
    virtual int legendaryAttack() = 0;
    virtual void setHP(int attackThrow, int damageThrow){
        if (attackThrow > m_AC){
            m_hp -= damageThrow;
        }
        else{
            std::cout << "missing attack" << std::endl;
        }
        if (m_hp <= 0){
            std::cout << "DeathMoroz is dead"<< std::endl;
        }


    }

private:
    std::string m_name;
    int m_hp, m_AC, m_attackThrow, m_damageThrow, m_weaponHP;
};

class Ranger : public Character {
public:
    explicit Ranger(std::string name = "Ubiwator123", int hp = 44, int AC = 16,
                    int attackThrow = RandomThrow(1, 20),
                    int damageThrow = RandomThrow(1, 10), int weaponHp = 20, int bow = 2)
        : Character(name, hp, AC, attackThrow, damageThrow, weaponHp), m_bow(bow)
    {}

    void setHp(int attackThrow, int damageThrow){
        damageThrow += m_bow;
        Character::setHP(attackThrow, damageThrow);
    }

private:
    int m_bow;

};

class DeathMoroz : public Character {
public:
    explicit DeathMoroz(std::string name = "DeathMoroz", int hp = 34, int AC = 17,
               int attackThrow = RandomThrow(1, 20),
               int damageThrow = RandomThrow(1, 8), int weaponHp = 20, int shield = 2)
        : Character(name, hp, AC, attackThrow, damageThrow, weaponHp), m_shield(shield)
    {}

    void setHp(int attackThrow, int damageThrow){
        attackThrow -= m_shield;
    }

private:
    int m_shield;

};


int main() {

    int heroVariant;
    std::cin >> heroVariant;



    return 0;
}

