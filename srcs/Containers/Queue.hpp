#ifndef QUEUE_HPP
# define QUEUE_HPP
#include "../Headers/Header.hpp"

namespace ft
{
	template <typename T, class Container = std::deque<T> >
	class queue
	{

	public:

		typedef T					value_type;
		typedef Container			container_type;
		typedef size_t				size_type;

	
		/**************************************************
		****************** Forme Coplien*******************
		**************************************************/

		explicit 			queue (const container_type& ctnr = container_type())
		{
			this->_container = ctnr;
		}

		~queue(void)
		{
		}

							queue(const queue& x){
			operator=(x);
		}

		queue				&operator=(const queue &src)
		{
			this->_container = src._container;
			return (*this);
		}
		
		/**************************************************
		******************* empty size ********************
		**************************************************/

		bool				empty(void) const
		{
			return (this->_container.empty());
		}


		size_type			size(void) const
		{
			return (this->_container.size());
		}

		/**************************************************
		******************** front back *******************
		**************************************************/

		value_type			&front(void)
		{
			return (this->_container.front());
		}


		const value_type	&front(void) const
		{
			return (this->_container.front());
		}


		value_type			&back(void)
		{
			return (this->_container.back());
		}


		const value_type	&back(void) const
		{
			return (this->_container.back());
		}

		/**************************************************
		******************** push pop *********************
		**************************************************/

		void				push(const value_type &val)
		{
			return (this->_container.push_back(val));
		}


		void				pop(void)
		{
			return (this->_container.pop_front());
		}


	private:
		container_type				_container;
	
		template <class U, class V>
		friend bool	operator==(const queue<U,V> &lhs, const queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator!=(const queue<U,V> &lhs, const queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator<(const queue<U,V> &lhs, const queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator<=(const queue<U,V> &lhs, const queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator>(const queue<U,V> &lhs, const queue<U,V> &rhs);
		template <class U, class V>
		friend bool	operator>=(const queue<U,V> &lhs, const queue<U,V> &rhs);
	};


template <class T, class Container>
	bool		operator==(const ft::queue<T,Container> &lhs, const ft::queue<T,Container> &rhs)
	{
		return (lhs._container == rhs._container);
	}

template <class T, class Container>
	bool		operator!=(const ft::queue<T,Container> &lhs, const ft::queue<T,Container> &rhs)
	{
		return (lhs._container != rhs._container);
	}

template <class T, class Container>
	bool		operator<(const ft::queue<T,Container> &lhs, const ft::queue<T,Container> &rhs)
	{
		return (lhs._container < rhs._container);
	}

template <class T, class Container>
	bool		operator<=(const ft::queue<T,Container> &lhs, const ft::queue<T,Container> &rhs)
	{
		return (lhs._container <= rhs._container);
	}

template <class T, class Container>
	bool		operator>(const ft::queue<T,Container> &lhs, const ft::queue<T,Container> &rhs)
	{
		return (lhs._container > rhs._container);
	}

template <class T, class Container>
	bool		operator>=(const ft::queue<T,Container> &lhs, const ft::queue<T,Container> &rhs)
	{
		return (lhs._container >= rhs._container);
	}

};

#endif