#pragma once

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:

		MutantStack();
		MutantStack(MutantStack const&);
		MutantStack&	operator=(MutantStack const&);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator		begin();
		const_iterator	begin() const;
		iterator		end();
		const_iterator	end() const;
};

#include "MutantStack.tpp"
