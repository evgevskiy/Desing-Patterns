#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Unit abstract
{
public:
	virtual void play() = 0;
	virtual ~Unit(){}
}; 
class Archer : public Unit
{
public:
	virtual void play()
	{
		cout << "Archer go play!" << endl;
	}
};
class Mage : public Unit
{
public:
	virtual void play()
	{
		cout << "Mag go play!" << endl;
    } 
};
class Swardsman : public Unit
{
public:
	virtual void play()
	{
		cout << "Swardsman go play!" << endl;
	}
};

class FactoryMethod abstract
{
public:
	virtual Unit* CreatPlayer() = 0;
};

class FactoryMethodArcher : public FactoryMethod
{
public:
	Unit* CreatPlayer()
	{
		return new Archer();
	 }
};

class FactoryMethodMage : public FactoryMethod
{
public:
	Unit* CreatPlayer()
	{
		return new Mage();
	}
};


class FactoryMethodSwardsman : public FactoryMethod
{
public:
	Unit* CreatPlayer()
	{
		return new Swardsman();
	}
};

//class CreatPlayer : public Unit
//{};
//
//class CreatPlayer : public Unit 
//{};

void main() {
	FactoryMethodArcher f1;
	FactoryMethodMage f2;
	FactoryMethodSwardsman f3;

	FactoryMethod* fact[] = { &f1, &f2, &f3 };
	vector<Unit*>players;
	int menu;
	while (true)
	{
		cout << "Archer (1)" << endl;
		cout << "Mage (2)" << endl;
		cout << "Swardsman (3)" << endl;
		cout << "Exit (4)" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			players.push_back(fact[menu-1]->CreatPlayer());
			for (auto el : players)
			{
				el->play();
			}
			break;
		}
		case 2:
		{
			players.push_back(fact[menu -1]->CreatPlayer());
			for (auto el : players)
			{
				el->play();
			}
			break;
		}
		case 3:
		{
			players.push_back(fact[menu -1]->CreatPlayer());
			for (auto el : players)
			{
				el->play();
			}
			break;
		}
		case 4: 
		{
			system("cls");
			return;
			break;
		}

		default:
			break;
	}
}
	system("pause");
}