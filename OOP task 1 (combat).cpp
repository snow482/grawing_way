#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>
#include <ctime>

/*
 * Вначале бойцы находятся на расстоянии 100фт.
 * All characters has a running speed.
 * Needs to do an iniciative check for identify (random throw) from each character.
 * After
 *
 *
 *
 *
 */

// v1.0
/*template<typename T>
T DiceRole (T tMin, T tMax)
{
    return rand() % (tMax - tMin) +tMax;
}*/

// v2.0
template<int min, int max>
struct Dice {
    int Roll() const {
        return rand() % (max - min) + max;
    }
};

// d20 dice from 1 to 20, where 20 critical hit / 1 critical failure
// d4 - d12 for weapon damage rate
using d20 = Dice<1,20>;
using d4 = Dice<1,4>;
using d6 = Dice<1,6>;
using d8 = Dice<1,8>;
using d10 = Dice<1,10>;
using d12 = Dice<1,12>;



enum struct WeaponType {
    //------Santa------
    SantaBag,
    Icicle,   //сосулька
    Sleigh,   //сани
    //------Ranger------
    Sword,
    LongBow,
    Spell

};

/*int RandomThrow (int diceMin, int diceMax) {
    // d20 dice from 1 to 20, where 20 critical hit / 1 critical failure
    // d4 - d12 for weapon damage rate
    int throwValue = 0;
    srand(time(0));
    throwValue = diceMin + rand() % diceMax;
    return throwValue;
}*/




class Character {
public:
    Character(std::string& name, int hp, int armorClass, WeaponType weaponType, int weaponHp, int runRange)
    : m_name(name), m_hp(hp), m_armorClass(armorClass), m_weaponType(weaponType), m_weaponHP(weaponHp), m_runRange(runRange)
    {}

    virtual int Initiative() = 0;
    virtual void run()
    {
        std::cout << "run" << std::endl;
    }
    virtual int attackThrow() = 0;

    // может быть лучше map сделать, типа выбрать тип оружия, 1 - sword или "sword" - sword

    virtual int damageThrow(WeaponType) {
        int damage = 0;
        if (m_weaponType == WeaponType::Icicle) {
            damage = d6{}.Roll();
        }
        if (m_weaponType == WeaponType::SantaBag) {
            damage = d8{}.Roll();
        }
        if (m_weaponType == WeaponType::Sleigh) {
            damage = d10{}.Roll() + d10{}.Roll();
        }
        if (m_weaponType == WeaponType::Sword){
            damage = d8{}.Roll();
        }
        if (m_weaponType == WeaponType::LongBow){
            damage = d8{}.Roll();
        }
        if (m_weaponType == WeaponType::Spell){
            damage = d12{}.Roll() + d12{}.Roll();
        }
        return damage;
    }
    virtual int firstAttack() = 0;
    virtual int secondAttack() = 0;
    virtual int bonusAttack() = 0;
    virtual double damageBlock(int shield) {
        int value = 0;
        return value;
    };
    virtual int legendaryAttack() = 0;
    virtual void setHP(int d20, int damageThrow) {
        if (d20 > m_armorClass) {
            m_hp -= damageThrow;
        }
        else {
            std::cout << "missing attack" << std::endl;
        }
        if (m_hp <= 0){
            std::cout << "DeathMorozzz is dead"<< std::endl;
        }
    }

private:
    WeaponType m_weaponType;
    std::string m_name;
    int m_hp, m_armorClass, m_weaponHP, m_runRange;
};

class Ranger : public Character {
public:
    explicit Ranger(std::string name = "Ranger_x_Ubiwator123_x",
                    int hp = 44,
                    int armorClass = 13,
                    int weaponHp = 20,


                    int runRange = 35,
                    int bow = 2)
    : Character(name, hp, armorClass, weaponHp, runRange), m_longBow(bow)
    {}



    void setHP(int attackThrow, int damageThrow) override {
        damageThrow += m_longBow;
        Character::setHP(attackThrow, damageThrow);
    }

private:
    int m_longBow;

};

class DeathMorozzz : public Character {
public:
    explicit DeathMorozzz(std::string name = "The_DeathMorozzz",
                        int hp = 34,
                        int armorClass = 14,
                        int weaponHp = 20,
                        int runRange = 30,
                        int shield = 2)
    : Character(name, hp, armorClass, weaponHp, runRange), m_shield(shield)
    {}

    void setHP(int attackThrow, int damageThrow) override {
        attackThrow -= m_shield;
    }

private:
    int m_shield;

};


int main() {

    std::cout << "Good day, dear gamers! Please, "
                 "pick you hero for start: number 1 - The_DeathMorozzz, 2 - Ranger_x_Ubiwator123_x" << std::endl;
    /*int heroVariant;
    std::cin >> heroVariant;*/


    std::cout << RandomThrow() << std::endl;


    return 0;
}

