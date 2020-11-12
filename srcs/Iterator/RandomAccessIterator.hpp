
#ifndef RANDOMACCESSITERATOR_H
#define RANDOMACCESSITERATOR_H

#include "./Iterator.hpp"

template <typename T>
class RandomAccessIterator
{
	public:

		typedef ptrdiff_t					difference_type;

		/**************************************************
		****************** Form Coplien *******************
		**************************************************/
		RandomAccessIterator(void){}	
		RandomAccessIterator(RandomAccessIterator const &src){
			operator=(src);
		}
		RandomAccessIterator &				operator=( RandomAccessIterator const &src){
			if (this != &src){
				this->_array = src._array;
			}
			return (*this);
		}
		virtual ~RandomAccessIterator(void){}
		RandomAccessIterator(T *src){
			this->_array = src;
		}

		/**************************************************
		*************** operator '==' '!=' ****************
		**************************************************/
		bool								operator==(const RandomAccessIterator &src) const{
			if (src._array == this->_array)
				return (true);
			return (false);
		}
		bool								operator!=(const RandomAccessIterator &src) const{
			return (!operator==(src));
		}

		/**************************************************
		************* operator '*a' 'a->m' ****************
		**************************************************/
		T									&operator*(void){
			return (*this->_array);
		}
		T									*operator->(void){
			return (*this->_array);
		}

		/**************************************************
		********* operator '++a' 'a++' '*a++' *************
		**************************************************/
		RandomAccessIterator				operator++(int){
			RandomAccessIterator I = *this;
			++this->_array;
			return (I);
		}
		RandomAccessIterator				operator++(void){
			++this->_array;
			return (*this);
		}
		T									*get_it(void) const{
			return (this->_array);
		}

		/**************************************************
		********* operator '--a' 'a--' '*a--' *************
		**************************************************/
		RandomAccessIterator				operator--(int){
			RandomAccessIterator I = *this;
			--this->_array;
			return (I);
		}
		RandomAccessIterator				&operator--(void){
			--this->_array;
			return (*this);
		}

		/**************************************************
		***** operator 'a + n' 'n + a' 'a - n' 'a - b' ****
		**************************************************/
		RandomAccessIterator				operator+(int n) {
			return (this->_array += n);
		}
		difference_type						operator+(RandomAccessIterator it) {
			return this->_array + it._array;
		}
		RandomAccessIterator				operator-(int n) {
			return (this->_array -= n);
		}
		difference_type						operator-(RandomAccessIterator it) {
			return (this->_array - it._array);
		}

		/**************************************************
		*** operator 'a < b' 'a > b' 'a <= b' 'a >= b' ****
		**************************************************/
		bool								operator<(const RandomAccessIterator& rhs) const {
			return (this->_array < rhs._array);
		}
		bool								operator>(const RandomAccessIterator& rhs) const {
			return (this->_array > rhs._array);
		}
		bool								operator<=(const RandomAccessIterator& rhs) const {
			return (this->_array <= rhs._array);
		}
		bool								operator>=(const RandomAccessIterator& rhs) const {
			return (this->_array >= rhs._array);
		}

		/**************************************************
		************ operator 'a += n' 'a -= n' ***********
		**************************************************/
		RandomAccessIterator				operator+=(difference_type n) {
			this->_array -= n;
			return (*this);
		}
		RandomAccessIterator				operator-=(difference_type n) {
			this->_array -= n;
			return (*this);
		}

		/**************************************************
		***************** operator 'a[n]' *****************
		**************************************************/
		RandomAccessIterator				operator[](int n) {
			return (this->_array[n]);
		}
		RandomAccessIterator							operator[](difference_type n) {
			return (*(this->_array + n));
		}
	private:
		T*			_array;
};

#endif
