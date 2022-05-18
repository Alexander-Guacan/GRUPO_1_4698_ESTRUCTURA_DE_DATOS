#if !defined(COMPLEJO_TEMPLATE_H)
#define COMPLEJO_TEMPLATE_H
#include <iostream>
using namespace std;
template <class T>
class ComplejoTemplate;
template <typename T>
ostream& operator <<(ostream &o, const ComplejoTemplate<T> &A);

template <class T>
class ComplejoTemplate{
	public:
		ComplejoTemplate(T real=0, T img=0);
		void setReal(T real);
		void setImg(T img);
		T getReal();
		T getImg();
		ComplejoTemplate<T>& operator +(const ComplejoTemplate<T>  &A);
		ComplejoTemplate<T>& operator -(const ComplejoTemplate<T>  &A);
	private:
		T real;
		T img;
};

/**
 * @brief Construct a new ComplejoTemplate< T>:: ComplejoTemplate object
 * 
 * @tparam T 
 * @param real 
 * @param img 
 */

template <class T>
ComplejoTemplate<T>::ComplejoTemplate(T real, T img){
	this->real=real;
	this->img=img;
}
/**
 * @brief setReal
 * 
 * @tparam T 
 * @param real 
 */
template <class T>
void ComplejoTemplate<T>::setReal(T real){
	this->real=real;
}
/**
 * @brief setImg
 * 
 * @tparam T 
 * @param img 
 */
template <class T>
void ComplejoTemplate<T>::setImg(T img){
	this->img=img;
}
/**
 * @brief getReal
 * 
 * @tparam T 
 * @return T 
 */
template <class T>
T ComplejoTemplate<T>::getReal(){
	return this->real;
}
/**
 * @brief getImg
 * 
 * @tparam T 
 * @return T 
 */
template <class T>
T ComplejoTemplate<T>::getImg(){
	return this->img;
}
/**
 * @brief sobrecarga Operador +
 * 
 * @tparam T 
 * @param A 
 * @return ComplejoTemplate<T>& 
 */
template <class T>
ComplejoTemplate<T>& ComplejoTemplate<T>::operator +(const ComplejoTemplate<T>  &A){
	this->img+= A.img;
	this->real+= A.real;
	return *this;
}
/**
 * @brief sobrecarga operador -
 * 
 * @tparam T 
 * @param A 
 * @return ComplejoTemplate<T>& 
 */
template <class T>
ComplejoTemplate<T>& ComplejoTemplate<T>::operator -(const ComplejoTemplate<T>  &A){
	this->img-= A.img;
	this->real-= A.real;
	return *this;
}
template class ComplejoTemplate<int>;
template class ComplejoTemplate<float>;
template class ComplejoTemplate<double>;


#endif // MACRO