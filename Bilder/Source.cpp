#include<iostream>
#include<string>
#include<ctime>
#include<map>
#include<vector>
using namespace std;
class Notebook 
{
public:
	Notebook()
	{

	}
	Notebook(string name):name (name)
	{

	}
	~Notebook()
	{

	}
	void AddPart(string n, string n2)
	{
		note[n] = n2;
	}
	void print()
	{
		cout << "Name" << name << endl;
		for (auto& el : note)
		{
			cout << "not" << el.first << " " << el.second << endl;
		}
	}
	string GetName()
	{
		return name;
	}
private:
	string name;
	map <string, string> note;
};
class  NotebookBilder 
{
protected:
	Notebook* device;
public:
	NotebookBilder()
	{
		device = new Notebook();
	}
	
	~NotebookBilder()
	{

	}
	virtual void SetMemory() = 0;
	
	virtual void SetHDD() = 0;
	
	virtual void SetMatrix() = 0;

	virtual void SetProcessor() = 0;
	
	Notebook*GetNotebook()
	{
		return device;
	}
};
class  Homebook : public NotebookBilder
{
public:
	
	Homebook()
	{
		device = new Notebook("Home");
	}
	~Homebook()
	{

	}
	void SetMemory()
	{
		device->AddPart("Memory: ", "8GB");
	}
	void SetHDD()
	{
		device->AddPart("HDD: ", "250GB");
	}
	void SetMatrix()
	{
		device->AddPart("Materix: ", "HD");
	}
	void SetProcessor()
	{
		device->AddPart("Processor: ", "Ryzen 5");
	}
};
class  GameNote : public NotebookBilder
{
public:
	GameNote()
	{
		device = new Notebook("Game");
	}
	~GameNote()
	{

	}
	void SetMemory()
	{
		device->AddPart("Memory: ", "16GB");
	}
	void SetHDD()
	{
		device->AddPart("HDD: ", "1000GB");
	}
	void SetMatrix()
	{
		device->AddPart("Materix: ", "Full HD");
	}
	void SetProcessor()
	{
		device->AddPart("Processor: ", "Ryzen 7");
	}
};
class CustomNote : public NotebookBilder
{
public:
	CustomNote()
	{
		device = new Notebook("Custom");
	}
	~CustomNote()
	{

	}
	void SetMemory(double value)
	{
		device->AddPart("Memory: ", "12GB");
	}
	void SetHDD()
	{
		device->AddPart("HDD: ", "650GB");
	}
	void SetMatrix()
	{
		device->AddPart("Materix: ", "QHD");
	}
	void SetProcessor()
	{
		device->AddPart("Processor: ", "Ryzen 3");
	}
};
class ShopBook
{
public:
	void GreateNotebook(NotebookBilder * note2)
	{
		note2->SetHDD();
		note2->SetMemory();
		note2->SetMatrix();
		note2->SetProcessor();
	}
	~ShopBook()
	{

	}
};
int main() {
	ShopBook* shop = new ShopBook();
	NotebookBilder* builder = new GameNote();
	shop->GreateNotebook(builder);
	builder->GetNotebook()->print();
	delete builder;
	builder = new Homebook();
	delete builder;
	/*builder = new CustomNote();
	delete builder;*/
	system("pause");
}