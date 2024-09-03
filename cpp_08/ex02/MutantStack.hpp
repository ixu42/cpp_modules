/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:55:21 by ixu               #+#    #+#             */
/*   Updated: 2024/09/03 12:10:47 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		// inherit all constructors from std::stack
		using std::stack<T, Container>::stack;
		
		// type aliases for iterator types
		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;
		using reverse_iterator = typename Container::reverse_iterator;
		using const_reverse_iterator = typename Container::const_reverse_iterator;

		iterator begin() {
			return this->c.begin();
		}

		const_iterator begin() const {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		const_iterator end() const {
			return this->c.end();
		}

		reverse_iterator rbegin() {
			return this->c.rbegin();
		}

		const_reverse_iterator rbegin() const {
			return this->c.rbegin();
		}

		reverse_iterator rend() {
			return this->c.rend();
		}

		const_reverse_iterator rend() const {
			return this->c.rend();
		}
};
