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
		std::cout << "����� Į�� �ֵѷ� " << sword.mAttack << " ���ظ� ������." << std::endl;
		// ���⼭ mAttack�� ������ �� �ִ� 3����
			// 1. private -> public
			// 2. Getter �Լ� Ȱ��
			// 3. friend ���
	}
};			

void DamageBuff(Sword& sword)
{
	sword.mAttack *= 2;
	// ģ�� �Լ��� ���� ������ ��������

	std::cout << "Į�� ��ȭ�� ���ݷ��� " << sword.mAttack << "�� �Ǿ���." << std::endl;
}

int main()
{
	Sword shortSword(10);
	Warrior w;

	w.AttackWith(shortSword);

	DamageBuff(shortSword);
}