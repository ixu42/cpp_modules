/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:28:15 by ixu               #+#    #+#             */
/*   Updated: 2024/08/29 22:19:20 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : _data(nullptr), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (_size == 0)
		_data = nullptr;
	else
	{
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = T();
	}
}

template<typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size)
{
	if (_size == 0)
		_data = nullptr;
	else
	{
		T* tempData = new T[_size];
		try
		{
			for (unsigned int i = 0; i < _size; ++i)
				tempData[i] = other._data[i];
			_data = tempData;
		}
		catch (...)
		{
			delete[] tempData;
			_data = nullptr;
			throw ;
		}
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
		return *this;
	_size = other._size;
	if (_size == 0)
	{
		delete[] _data;
		_data = nullptr;
	}
	else
	{
		T* tempData = new T[_size];
		try
		{
			for (unsigned int i = 0; i < _size; ++i)
				tempData[i] = other._data[i];
			delete[] _data;
			_data = tempData;
		}
		catch (...)
		{
			delete[] tempData;
			throw ;
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _data;
}

// allow element modification for non-const Array objects
template<typename T>
T& Array<T>::operator[](int i)
{
	if (i < 0 || static_cast<unsigned int>(i) >= _size)
		throw std::out_of_range("Array::operator[] error: index out of bounds");
	return _data[i];
}

// provide read-only access to elements of const Array objects
template<typename T>
const T& Array<T>::operator[](int i) const
{
	if (i < 0 || static_cast<unsigned int>(i) >= _size)
		throw std::out_of_range("Array::operator[] error: index out of bounds");
	return _data[i];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
