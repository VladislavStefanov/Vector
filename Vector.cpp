#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
class Vector {
private:
	size_t capacity;
	size_t size;
	T* elements;

	void extend()
	{
		this->capacity *= 2;
		T* extendedElements = new T[this->capacity];
		for (size_t i = 0; i < this->size; i++)
		{
			extendedElements[i] = this->elements[i];
		}
		delete[] this->elements;
		this->elements = extendedElements;
	}

public:
	Vector()
	{
		this->capacity = 1;
		this->size = 0;
		this->elements = new T[this->capacity];
	}
	void add(T element)
	{
		if (this->size == this->capacity)
		{
			this->extend();
		}
		this->elements[size] = element;
		this->size++;
	}
	void insert(size_t index, T element)
	{
		assert(index >= 0 && index < this->size);
		this->add(this->elements[this->size - 1]);
		for (size_t i = this->size - 1; i > index; i--)
		{
			this->elements[i] = this->elements[i - 1];
		}
		this->elements[index] = element;
	}
	void remove(size_t index)
	{
		assert(index >= 0 && index < this->size);
		for (size_t i = index + 1; i < this->size; i++)
		{
			this->elements[i - 1] = this->elements[i];
		}
		this->size--;
	}
	void removeLast()
	{
		if (this->size == 0) return;
		this->size--;
	}
	void clear()
	{
		this->capacity = 1;
		this->size = 0;
		delete[] this->elements;
		this->elements = new T[this->currentCapacity];
	}

	// the same as [] 
	T& at(size_t index)
	{
		assert(index >= 0 && index < this->size);
		return this->elements[index];
	}
	T& operator[] (size_t index)
	{
		assert(index >= 0 && index < this->size);
		return this->elements[index];
	}

	T& front()
	{
		return this->elements[0];
	}
	T& back()
	{
		return this->elements[size - 1];
	}
	bool isEmpty()
	{
		return this->size == 0;
	}
	size_t getSize()
	{
		return this->size;
	}
	size_t getCapacity()
	{
		return this->capacity;
	}

	~Vector()
	{
		this->capacity;
		this->size;
		delete[] this->elements;
	}

	Vector(Vector& vector)
	{
		this->capacity = vector.capacity;
		this->size = vector.size;
		this->elements = new T[this->capacity];
		for (size_t i = 0; i < this->size; i++)
		{
			this->elements[i] = vector.elements[i];
		}
	}

	Vector& operator=(Vector& vector)
	{
		if (this == &vector)
		{
			return *this;
		}
		this->capacity = vector.capacity;
		this->size = vector.size;
		delete[] this->elements;
		this->elements = new T[this->capacity];
		for (size_t i = 0; i < this->size; i++)
		{
			this->elements[i] = vector.elements[i];
		}
		return *this;
	}

	Vector(Vector&& vector)
	{
		this->capacity = vector.capacity;
		this->size = vector.size;
		this->elements = vector.elements;
		vector.elements = nullptr;
	}
	Vector& operator=(Vector&& vector)
	{
		this->capacity = vector.capacity;
		this->size = vector.size;
		this->elements = vector.elements;
		vector.elements = nullptr;
		return *this;
	}
};

// to test move constructor and assignment
Vector<int> getVector()
{
	Vector<int> a{};
	return a;
}


int main() {
	Vector<int> tst;
	for (int i = 0; i < 10; i++)
	{
		tst.add(i);
	}
	tst.insert(2, 20);
	tst.remove(0);
	tst.removeLast();
	tst[8] = 30;
	for (size_t i = 0; i < tst.getSize(); i++)
	{
		cout << tst[i] << " ";
	}
	cout << endl;
	cout << tst.front() << " " << tst.back() << endl;
	cout << tst.getCapacity() << endl;
	Vector<int> tst2(tst);
	Vector<int> tst3;
	tst3 = tst;
	// test move constructor and assignement with debugger
	Vector<int> tst4 (getVector());
	Vector<int> tst5;
	// for some reason I don't know why, move constructor is called when getVector() returns "a";
	tst5 = getVector();


	return 0;
}