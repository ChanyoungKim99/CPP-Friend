#include <iostream>

// 친구 멤버 함수
// 정보를 공개할 클래스를 뒤에 선언해야 한다

class Sword;			// 뒤의 Warrior에게 정보 제공을 위한 전방 선언

class Warrior			// Warrior에서 Sword를 사용하기 위해 전방선언이 필요함
{
public:
	void AttackWith(Sword& sword);		
};						// 역시 뒤의 Sword에게 정보를 제공을 위한 전방 선언



class Sword									// 정의
{
	friend void Warrior::AttackWith(Sword& sword);
	// Sword에서 Warrior를 사용하기 위해 전방선언이 필요함
private:
	int mAttack;

public:
	Sword(int attack) : mAttack{ attack }
	{
	}
};

void Warrior::AttackWith(Sword& sword)		// 정의
{
	std::cout << "전사는 칼을 휘둘러 " << sword.mAttack << " 피해를 입혔다." << std::endl;
}			
