/*********************************************************************
 * Variable.h
 * Generic value containers.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/
#ifndef VARIABLE_H_
#define VARIABLE_H_

template<typename T> class Variable
{
  T value;
public:
  Variable(T x): value(x) { }
  void set(T x) { value = x; }
  template<typename U> void set(U x) { x = static_cast<T>(x); }
};

#endif /* VARIABLE_H_ */
