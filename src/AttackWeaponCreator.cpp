#include <AttackWeaponCreator.h>

AttackWeaponCreator::AttackWeaponCreator()
{
    /// \todo: Implement  AttackWeaponCreator::AttackWeaponCreator
}

AttackWeapon* AttackWeaponCreator::produce()
{
  	return produceAttackWeapon();
}
int AttackWeaponCreator::getPrice(){
    return price;
}

void AttackWeaponCreator::setPrice(int price){
    this->price = price;
}