#pragma once

class Entity {

	private:
		int hp;
		int maxHp;
		int attack;
		int defence;
		int intelligence;
		int lvl;

	public:
		Entity(int hp, int attack, int defence, int intelligence, int maxHp) {
			this->hp = hp;
			this->attack = attack;
			this->defence = defence;
			this->intelligence = intelligence;
			this->maxHp = maxHp;
		}
		
		int setLevel(int lvl) {
			this->lvl = lvl;
			return lvl;
		}

		int getLevel() {
			return lvl;
		}

		int setHp(int hp) {
			this->hp = hp;
			return hp;
		}

		int getHp() {
			return hp;
		}

		int setMaxhp(int maxHp) {
			this->maxHp = maxHp;
			return maxHp;
		}

		int getMaxhp() {
			return maxHp;
		}

		int setAttack(int attack) {
			this->attack = attack;
			return attack;
		}

		int getAttack() {
			return attack;
		}

		int setDefence(int defence) {
			this->defence = defence;
			return defence;
		}

		int getDefence() {
			return defence;
		}

		int setIntelligence(int intelligence) {
			this->intelligence = intelligence;
			return intelligence;
		}

		int getIntelligence() {
			return intelligence;
		}

		int meleeAttack(int attack, int defence) {
			int dmg = attack - defence;
			return dmg;
		}

		int spellAttack(int attack, int defence, int intelligence) {
			int dmg = (attack + intelligence) - defence;
			return dmg;
		}

		int chargedAttack(int attack, int defence) {
			int dmg = attack * 2 - defence;
			return dmg;
		}

		bool isAlive() {
			if (hp <= 0) {
				return false;
			}
			else {
				return true;
			}
		}

};