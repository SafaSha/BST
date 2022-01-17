#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::ostream;

    /**
     * @class Vector
     * @brief  Vector to store different object
     *
     *
     *
     * @author Safa Shavandi
     * @version 01
     * @date 10/04/2020 Safa Shavandi, Started
     *
     *
     */
template <class T>
class Vector
{
public:

    /** \brief default constructor
     *
     *
     */
Vector()
    {
        arrPtr=new T[arrSize];

    }

    /** \brief decunstructor
     *
     * \return virtual
     *
     */
virtual ~Vector()
    {
        delete[] arrPtr;
    }

    /** \brief add element at the end of vector
     *
     * \param element T, object of T type
     * \return void
     *
     */
void add(T element);

    /** \brief It returns the capacity of elements in array.(size of array)
     *
     * \return int ,size of array
     *
     */
int getSize();

    /** \brief overloading [] operator
     *
     * \param index int, index of element
     * \return T&
     *
     */
T& operator[](int index);

    /** \brief const overloading [] operator
     *
     * \param index int, index of element
     * \return constT&
     *
     */
const T& operator[](int index) const;

    /** \brief copy constructor
     *
     * \param otherObject const Vector&
     *
     */
Vector(const Vector& otherObject);

    /** \brief overloding Assignment
     *
     * \param v const Vector&
     * \return Vector<T>&
     *
     */
Vector<T> & operator=(const Vector &v);


    /** \brief overloding Assignment
     *
     * \param t T*
     * \return Vector<T>*
     *
     */
Vector<T>* operator=( T *t);

    /** \brief create new array with 1.5 times bigger size
     *
     * \return void
     *
     */
void newArray( );

    /** \brief overloading operator +
     *
     * \param v1 const Vector<T>&
     * \return Vector<T>&
     *
     */
Vector<T>& operator+(const Vector<T> &v1) const;

 void clear();

protected:

private:
    T *arrPtr=nullptr;
    int arrSize=10;
    int numArrElement=0;
};


/////////////////////////////////////////////////////////////////////

template <class T>
void Vector<T>::clear()
{
    arrSize=10;
    numArrElement=0;
}


template <class T>
Vector<T>& Vector<T>::operator+(const Vector<T> &v1) const
 {
    Vector<T> newV;

  while(newV.arrSize <v1.arrSize)
    {
newArray();
  }

  for(int i = 0; i < v1.arrSize; i++)
    newV.arrPtr[i] = arrPtr[i] + v1.arrPtr[i];

return newV;
}

    //add new element to the vector
template <class T>
void Vector<T>::add(T element)
{
    while(numArrElement>=arrSize)
    {
        newArray();
    }

    arrPtr[numArrElement]=element;
    numArrElement++;
}


    //return cpacity of element in the array
template <class T>
int Vector<T>::getSize()
{
    return arrSize;
}

    //operator[] overloading
template <class T>
T& Vector<T>::operator[](int index)
{

    while(index>=arrSize)
    {
        newArray();
    }
    return arrPtr[index];
}

    //operator[] overloading
template <class T>
const T& Vector<T>::operator[](int index) const
{

    return arrPtr[index];
}


    //operator= overloading
template <class T>
Vector<T>* Vector<T>::operator=( T *t)
{
    arrPtr=t;
    return this;

}

    //new array with 1.5 times bigger size
template <class T>
void Vector<T>::newArray()
{
    T *newPtr=nullptr;
    int newArrSize=1.5*arrSize;
    newPtr=new T[newArrSize];
    for(int i=0; i<arrSize; i++)
    {
        newPtr[i]=arrPtr[i];
    }
    delete []arrPtr;
    arrPtr=newPtr;
    newPtr=nullptr;
    arrSize=newArrSize;
}


    // Assignment = operator overloading
template <class T>
Vector<T> & Vector<T>::operator=(const Vector &v)
{
    while(arrSize < v.arrSize)
    {
        newArray();
    }
    for(int i = 0; i < arrSize; i++)
    {
        arrPtr[i] = v.arrPtr[i];
    }
    return *this;
}


    //copy constructor
template <class T>
Vector<T>::Vector(const Vector& otherObject)
{

    arrSize=otherObject.arrSize;
    numArrElement=otherObject.numArrElement;
    arrPtr = new T[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        arrPtr[i] = otherObject.arrPtr[i];
    }
}


#endif // VECTOR_H
