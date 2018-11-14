#include <iostream>
using namespace std;

template<class T>
class Vector {
private:
	int capacity;
	int currentCapacity;
	int size;

	T* beginning = nullptr;
	T* end = nullptr;
	Vector<T>* next = nullptr;
	void extend(int length)
	{
		if (this->next != nullptr)
		{
			next->extend(length);
		}
		else
		{
			this->next = new Vector<T>(length);
		}

		this->capacity *= 2;
	}

	Vector(int capacity)
	{
		this->capacity = capacity;
		this->currentCapacity = capacity;
		this->size = 0;
		this->beginning = new T[this->currentCapacity];
		this->end = this->beginning;
	}
	T* addUtil(T element)
	{
		if (this->size >= this->currentCapacity)
		{
			this->end = this->next->addUtil(element);
		}
		else
		{
			*(this->end) = element;
			this->end++;
		}
		this->size++;
		return this->end;
	}

public:
	Vector()
	{
		this->capacity = 1;
		this->currentCapacity = 1;
		this->size = 0;
		this->beginning = new T[this->currentCapacity];
		this->end = this->beginning;
	}
	void add(T element)
	{
		if (this->size == this->capacity)
		{
			this->extend(this->capacity);
		}
		if (this->size >= this->currentCapacity)
		{
			this->end = this->next->addUtil(element);
		}
		else
		{
			*(this->end) = element;
			this->end++;
		}
		this->size++;
	}
	void insert(int index, T element)
	{
		if (index < 0) throw out_of_range::out_of_range("Index cannot be less than 0");
		if (index > this->size) throw out_of_range::out_of_range("Index cannot be greater than vector size");
		this->add(this->operator[](this->size - 1));
		for (int i = this->size - 1; i > index; i--)
		{
			this->operator[](i) = this->operator[](i - 1);
		}
		this->operator[](index) = element;
	}
	void remove(int index)
	{
		if (index < 0 || index > this->size - 1) throw out_of_range::out_of_range("Index out of bounds!");
		for (int i = index + 1; i < this->size; i++)
		{
			this->operator[](i - 1) = this->operator[](i);
		}
		this->size;
	}
	void removeLast()
	{
		this->size--;
	}
	void clear()
	{
		this->capacity = 1;
		this->currentCapacity = 1;
		this->size = 0;
		delete[] this->beginning;
		this->beginning = new T[this->currentCapacity];
		this->end = this->beginning;
		if (this->next != nullptr)
		{
			delete this->next;
			this->next = nullptr;
		}
	}

	// the same as [] with exceptions
	T& at(int index)
	{
		if (index < 0 || index > this->size - 1) throw out_of_range::out_of_range("Index out of bounds!");
		if (index + 1 > this->currentCapacity)
		{
			return this->next->at(index - this->currentCapacity);
		}
		return this->beginning[index];
	}
	T& operator[] (int index)
	{
		if (index + 1 > this->currentCapacity)
		{
			return this->next->operator[](index - this->currentCapacity);
		}
		return this->beginning[index];
	}

	T& front()
	{
		return *(this->beginning);
	}
	T& back()
	{
		return *((this->end - 1));
	}
	bool isEmpty()
	{
		return this->size == 0;
	}
	int getSize()
	{
		return this->size;
	}
	int getCapacity()
	{
		return this->capacity;
	}

	~Vector() 
	{
		this->capacity;
		this->currentCapacity;
		this->size;
		delete[] this->beginning;
		if (this->next != nullptr)
		{
			delete this->next;
		}
	}
};

int main() {
	Vector<int> tst;
	//for (int i = 0; i < 20; i++)
	//{
	//	tst.add(i);
	//}
	for (int i = 0; i < 2; i++)
	{
		tst.add(i);
	}
	//tst.front() = 5;
	//tst.back() = 25;
	//cout << tst.front()<< endl;
	//tst[5] = 6;
	//tst.remove(8);
	//tst.insert(20, 20);
	for (int i = 0; i < tst.getSize(); i++)
	{
		cout << tst.at(i) << " ";
	}
	//cout << endl;
	//cout << tst.getSize() << endl;
	//cout << tst.getCapacity() << endl;
	//cout << tst[5] << endl;
	//try 
	//{
	//	cout << tst.at(19) << endl;
	//}
	//catch (out_of_range e)
	//{
	//	cout << e.what() << endl;
	//}
	//cout << tst.getSize() << endl;
	
	
	
	

	return 0;
}