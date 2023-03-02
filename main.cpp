#include <iostream>

class Sword
{
	friend class Warrior;
	friend void DamageBuff(Sword& sword);

private:
	int mAttack;

public:
	Sword(int attack) : mAttack{ attack }
	{
	}
};

class Warrior
{
public:
	void AttackWith(Sword& sword)
	{
		std::cout << "전사는 칼을 휘둘러 " << sword.mAttack << " 피해를 입혔다." << std::endl;
		// 여기서 mAttack에 접근할 수 있는 3가지
			// 1. private -> public
			// 2. Getter 함수 활용
			// 3. friend 사용
	}
};			

void DamageBuff(Sword& sword)
{
	sword.mAttack *= 2;
	// 친구 함수를 통해 접근이 가능해짐

	std::cout << "칼을 강화해 공격력이 " << sword.mAttack << "가 되었다." << std::endl;
}

int main()
{
	Sword shortSword(10);
	Warrior w;

	w.AttackWith(shortSword);

	DamageBuff(shortSword);
}