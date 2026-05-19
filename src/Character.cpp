#include "Character.h"
#include "Ability.h"
#include "Mana.h"

Character::Character(const string& name, int startingHP, int startingMana)
	: Name{ name }, HitPoints{ startingHP }, ManaPoints{ startingMana }
{
}

void Character::characterTakeDamage(int damage)
	// character taking damage
{
	cout << Name << " lost " << damage << " hp!" << endl;
	HitPoints.takeDamage(damage);
}

void Character::characterHealsHP(int heal)
	// character gets healed by heal amount
{
	cout << Name << " got healed by " << heal << " hp!" << endl;
	HitPoints.healHP(heal);
}

void Character::useAbility(size_t index, Character &target)
	// character using ability
{
	if (index >= CharacterAbilities.size()) {
		cout << "Invalid ability!" << endl;
		return;
	}

	Ability* ability = CharacterAbilities[index].get();

	if(ManaPoints.isEnoughMana(ability)) {
		int cost = ManaPoints.getCurrentMana() - ability->getManaCost();

		ManaPoints.setCurrentMana(cost);
		
		CharacterAbilities[index]->useAbility(*this, target);
	}
	else {
		cout << "You do not have enough mana!" << endl;
	}
}

void Character::addAbility(std::unique_ptr<Ability> ability)
{
    CharacterAbilities.push_back(std::move(ability));
}

void Character::addEffect(const Effect& effect)
{
	this->ActiveEffects.push_back(effect);
}

void Character::updateEffect()
{
	// there can be more than one buff or debuff, so iterating through the list to add/subtract damage and reduce the countdown by one
	for (auto it = ActiveEffects.begin(); it != ActiveEffects.end(); ) {
		it->effectRounds--; // reduce the effect by one turn

		if (it->effectRounds <=0 ) { // once it done, remove the effect
			it = ActiveEffects.erase(it);
		}
		else { // iterate
			++it;
		}
	}
}

string Character::getName() const
{
	return Name;
}

void Character::printHitPoints() const
{
	this->HitPoints.displayHP();
}

int Character::getCurrentHP() const
{
	return this->HitPoints.getCurrentHP();
}

int Character::getBuffDamangeBonus() const
{
	int bonusDamage = 0;

	for (const auto& e : ActiveEffects) {
		bonusDamage += e.damageBonus;
	}

    return bonusDamage;
}

bool Character::isAlive() const
{
	return HitPoints.isAlive();
}
