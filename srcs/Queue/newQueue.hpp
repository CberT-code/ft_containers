
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
		typedef Container					container_type;
		typedef size_t				size_type;

	private:
		container_type				container;
	
	public:
	/* ********************************************************************** */
	/*   Member functions                                                     */
	/* ********************************************************************** */
		
		explicit queue (const container_type& ctnr = container_type())
		{
			this->container = ctnr;
			return ;
		}

		~queue(void)
		{
			return ;
		}

		queue(const queue &queue)
		{
			*this = queue;
			return ;
		}

		queue				&operator=(const queue &queue)
		{
			this->container = queue.container;
			return (*this);
		}
		
		value_type			&back(void)
		{
			return (this->container.back());
		}

		const value_type	&back(void) const
		{
			return (this->container.back());
		}

		bool				empty(void) const
		{
			return (this->container.empty());
		}

		value_type			&front(void)
		{
			return (this->container.front());
		}

		const value_type	&front(void) const
		{
			return (this->container.front());
		}

		void				pop(void)
		{
			return (this->container.pop_front());
		}

		void				push(const value_type &val)
		{
			return (this->container.push_back(val));
		}

		size_type			size(void) const
		{
			return (this->container.size());
		}

	private:
		/* Make friends to grant access of sub-container to compare */
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

	/* ************************************************************************** */
	/*   Non-member functions                                                     */
	/* ************************************************************************** */

	template <class T, class Container>
	bool		operator==(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.container == rhs.container);
	}

	template <class T, class Container>
	bool		operator!=(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.container != rhs.container);
	}

	template <class T, class Container>
	bool		operator<(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.container < rhs.container);
	}

	template <class T, class Container>
	bool		operator<=(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.container <= rhs.container);
	}

	template <class T, class Container>
	bool		operator>(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.container > rhs.container);
	}

	template <class T, class Container>
	bool		operator>=(const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.container >= rhs.container);
	}

};

#endif