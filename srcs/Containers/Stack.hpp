
#ifndef STACK_HPP
# define STACK_HPP
#include "../Headers/Header.hpp"

namespace ft
{
	template <typename T, class Container = std::deque<T> >
	class stack
	{

	public:

		typedef T					value_type;
		typedef Container			container_type;
		typedef size_t				size_type;
	
		/**************************************************
		****************** Form Coplien *******************
		**************************************************/

		explicit 			stack (const container_type& ctnr = container_type()){
			this->_container = ctnr;
		}
		~stack(void){}
		stack(const stack& x){
			operator=(x);
		}
		stack				&operator=(const stack &src){
			this->_container = src._container;
			return (*this);
		}
		
		/**************************************************
		******************* empty size ********************
		**************************************************/

		bool				empty(void) const{
			return (this->_container.empty());
		}
		size_type			size(void) const{
			return (this->_container.size());
		}

		/**************************************************
		******************** front back *******************
		**************************************************/

		value_type			&top(void){
			return (this->_container.back());
		}
		const value_type	&top(void) const{
			return (this->_container.back());
		}

		/**************************************************
		******************** push pop *********************
		**************************************************/

		void				push(const value_type &val){
			return (this->_container.push_back(val));
		}
		void				pop(void){
			return (this->_container.pop_back());
		}

	private:
		container_type				_container;
	
		template <class U, class V>
		friend bool	operator==(const stack<U,V> &lhs, const stack<U,V> &rhs);
		template <class U, class V>
		friend bool	operator!=(const stack<U,V> &lhs, const stack<U,V> &rhs);
		template <class U, class V>
		friend bool	operator<(const stack<U,V> &lhs, const stack<U,V> &rhs);
		template <class U, class V>
		friend bool	operator<=(const stack<U,V> &lhs, const stack<U,V> &rhs);
		template <class U, class V>
		friend bool	operator>(const stack<U,V> &lhs, const stack<U,V> &rhs);
		template <class U, class V>
		friend bool	operator>=(const stack<U,V> &lhs, const stack<U,V> &rhs);
	};

template <class T, class Container>
	bool		operator==(const ft::stack<T,Container> &lhs, const ft::stack<T,Container> &rhs){
		return (lhs._container == rhs._container);
	}
template <class T, class Container>
	bool		operator!=(const ft::stack<T,Container> &lhs, const ft::stack<T,Container> &rhs){
		return (lhs._container != rhs._container);
	}
template <class T, class Container>
	bool		operator<(const ft::stack<T,Container> &lhs, const ft::stack<T,Container> &rhs){
		return (lhs._container < rhs._container);
	}
template <class T, class Container>
	bool		operator<=(const ft::stack<T,Container> &lhs, const ft::stack<T,Container> &rhs){
		return (lhs._container <= rhs._container);
	}
template <class T, class Container>
	bool		operator>(const ft::stack<T,Container> &lhs, const ft::stack<T,Container> &rhs){
		return (lhs._container > rhs._container);
	}
template <class T, class Container>
	bool		operator>=(const ft::stack<T,Container> &lhs, const ft::stack<T,Container> &rhs){
		return (lhs._container >= rhs._container);
	}

};

#endif