#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>


template <typename T>
class Array {
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array() : _data(NULL), _size(0) {};
		Array(unsigned int n) : _data(new T[n]), _size(n) {};
		Array(const Array& other) : _data(NULL), _size(0) {*this = other;};
		~Array() { delete[] _data; };

		Array& operator=(const Array& b) {
			if (this != &b)
			{
				delete[] _data;
				_size = b._size;
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_data[i] = b._data[i];
			}
			return *this;
		}

		T& operator[](unsigned int index){
			if (index >= _size)
				throw GradeTooLowException();
			return _data[index];
		}

		const T& operator[](unsigned int index) const {
			if (index >= _size)
				throw GradeTooLowException();
			return _data[index];
		}

		unsigned int size() const { return _size; };

		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw()
				{
					return "Array index out of bounds";
				}
		};
};





#endif