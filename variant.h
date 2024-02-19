#pragma once

#ifndef _BASE_VARIANT_H_
#define _BASE_VARIANT_H_

#include <iostream>
#include <memory>
#include <typeindex>
#include <vector>
#include <unordered_map>
#include <gtest/gtest.h>
#include <stack>
#include <stdio.h>
#include <string.h>

template <class T>
bool funcPrint(T a)
{
	std::cout << a << std::endl;
	return true;
}

class CVariant
{
public:
	CVariant() : data(nullptr), typeIndex(typeid(void))
	{
		std::cout << "default constructor was call" << std::endl;
	}

	template <typename T>
	CVariant(const T &value) : data(new Holder<T>(value)), typeIndex(typeid(void)) {}
	CVariant(const CVariant &other) : typeIndex(other.typeIndex)
	{
		if (other.data)
		{
			data = other.data->clone();
		}
	}

	CVariant(CVariant &&other) noexcept : typeIndex(std::move(other.typeIndex)), data(std::move(other.data))
	{
		other.typeIndex = typeid(void);
	}

	CVariant &operator=(const CVariant &other)
	{
		if (this != &other)
		{
			typeIndex = other.typeIndex;
			data.reset();
			if (other.data)
			{
				data = other.data->clone();
			}
		}
		return *this;
	}

	template <typename T>
	auto &&Value() const
	{
		if (typeIndex == std::type_index(typeid(void)))
		{
			return std::forward<T>(static_cast<Holder<T> *>(data.get())->value);
		}
		else
		{
			T r;
			return std::forward<T>(r);
		}
	}

private:
	struct BaseHolder
	{
		virtual ~BaseHolder() {}
		virtual std::unique_ptr<BaseHolder> clone() const = 0;
	};

	template <typename T>
	struct Holder : public BaseHolder
	{
		Holder(const T &val) : value(val) {}
		std::unique_ptr<BaseHolder> clone() const override
		{
			return std::make_unique<Holder<T>>(value);
		}
		T value;
	};

	std::type_index typeIndex;
	std::unique_ptr<BaseHolder> data;
};
#endif