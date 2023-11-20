#include <iostream>
#include <string>

using namespace std;

class Retailitem {
private:
	string description_; // описание товара
	unsigned int counter_; // кол-во единиц на складе
	float price_; // цена
public:
	Retailitem(string description, unsigned int counter, float price)
	{
		description_ = description;
		counter_ = counter;
		price_ = price;
	}
	friend class CashRegister;
};

class CashRegister 
{
private:
	Retailitem* array[3];
public:
	void buy_item(Retailitem * object, int i)
	{
		array[i] = object;
	}
	float get_total(Retailitem* obj_1, Retailitem* obj_2, Retailitem* obj_3)
	{
		float sum;
		sum = obj_1->price_ + obj_2->price_ + obj_3->price_;
		return sum;
	}
	void clear()
	{

	}

};

int main()
{
	float summa;

	Retailitem blazer("Blazer", 12, 59.95);
	Retailitem jeans("Jeans", 40, 34.95);
	Retailitem shirt("Shirt", 20, 24.95);

	CashRegister list;
	list.buy_item(&blazer, 0);
	list.buy_item(&jeans, 1);
	list.buy_item(&shirt, 2);

	summa = list.get_total(&blazer, &jeans, &shirt);
			
	return 0;
}
