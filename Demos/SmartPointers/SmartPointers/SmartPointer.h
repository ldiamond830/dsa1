#pragma once

template <class t>
class SmartPointer 
{
public:
	SmartPointer(t* _ptr = nullptr)
	{
		ptr = _ptr;
	}
	~SmartPointer() 
	{
		delete ptr;
		ptr = nullptr;
	}

	t& operator *() 
	{
		return *ptr;
	}
	t* operator ->() 
	{
		return ptr;
	}
private:
	t* ptr;
};

