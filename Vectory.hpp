#ifndef INCLUDED_VECTOR_H
#define INCLUDED_VECTOR_H
#include <cstdlib>
#include <cstring>
#include <stddef.h>
template<class T>
class Vectory{
private:
    T* _base = nullptr;
	size_t _len = 0;
	size_t _capacity = 0;
public:
    // explicit Vector(size_t size);
	// explicit Vector(size_t size,const T & value);
    Vectory()=default;
    Vectory(const Vectory & ele)
    {
        _len = ele.getLen();
        _capacity = ele.getCapacity();
        _base = new T[_capacity];
        for ( int i = 0 ; i < _len ; i ++ )
        {
           _base[i]=ele.getThePos(i);
        }
    }
    Vectory(int size , int value = 0)
    {
        _base = new T [size+1];
        for(int i=0 ; i < size ; i++ )
        {
            pushBack(value);
        }
    }
    ~Vectory(){;}
    void pushBack(T value)
    {
        if(_len == _capacity)
        {
            inCrease();
        }
        *(_base  + _len++) = value;
    }
    void popBack(void)
    {
        _len--;
        if(_len <= _capacity / 2)
        {
            deCrease();
        }
    }
    const size_t getLen() const {return this->_len;}
    const size_t getCapacity() const {return this->_capacity;}
    const T & operator[](int pos)const
    {
        return *(_base+pos);
    }
    bool isEmpty(){return _len==0;}
    void clear()
    {
        delete[] _base;
        _len=0;
        _capacity=0;
    }
    const T getThePos(int pos) const 
    {
        return _base[pos];
    }
private:
    void inCrease()
    {
        if(_capacity==0)
        {
            _capacity=1;
            _base=new T[_capacity*1];
        }
        else{
            T * newbase = new T[_capacity*2];
            for(int i=0;i<_len;i++)
                newbase[i]=_base[i];
            delete[] _base;
            _base = newbase;
            _capacity *=2;
        }
    }
    void deCrease()
    {
        if(_len==0)
        {
            _base=nullptr;
            _capacity=0;
        }
        else{
            T * newbase = new T[_len];
            for(int i=0;i<_len;i++)
                newbase[i]=_base[i];
            delete[] _base;
            _base = newbase;
            _capacity = _len;
        }
    }
};
#endif

// isDigit();
// isAlpha();
// Student();

