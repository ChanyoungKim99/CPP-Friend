#include <iostream>

// 친구 함수

class Sword
{
	friend class Warrior;
	friend void DamageBuff(Sword& sword)
	{
		sword.mAttack *= 2;

		std::cout << "칼을 강화해 공격력이 " << sword.mAttack << "가 되었다." << std::endl;
	};
	// 이렇게 선언과 정의를 합친다면,
	// 마치 멤버함수 같이 표기가 되어버린다.
	// 그러나 이건 전역함수다!!!

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

int main()
{
	Sword shortSword(10);
	Warrior w;

	w.AttackWith(shortSword);

	DamageBuff(shortSword);				// 전역함수 라는 증거
	Sword::DamageBuff(shortSword);		// 멤버함수가 아니라는 증거
}