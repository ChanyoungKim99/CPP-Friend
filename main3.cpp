#include <iostream>

// ģ�� ��� �Լ�
// ������ ������ Ŭ������ �ڿ� �����ؾ� �Ѵ�

class Sword;			// ���� Warrior���� ���� ������ ���� ���� ����

class Warrior			// Warrior���� Sword�� ����ϱ� ���� ���漱���� �ʿ���
{
public:
	void AttackWith(Sword& sword);		
};						// ���� ���� Sword���� ������ ������ ���� ���� ����



class Sword									// ����
{
	friend void Warrior::AttackWith(Sword& sword);
	// Sword���� Warrior�� ����ϱ� ���� ���漱���� �ʿ���
private:
	int mAttack;

public:
	Sword(int attack) : mAttack{ attack }
	{
	}
};

void Warrior::AttackWith(Sword& sword)		// ����
{
	std::cout << "����� Į�� �ֵѷ� " << sword.mAttack << " ���ظ� ������." << std::endl;
}			
