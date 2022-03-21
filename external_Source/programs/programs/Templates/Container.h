/*********************************************************************
 * Container.h
 * Generic containers.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/
#ifndef CONTAINER_H_
#define CONTAINER_H_

template<typename T> class Container {
  T* value;
public:
  Container(T x) { value = new T; *value = x; }
};

template<> class Container<int> {
  int value;
public:
  Container(int x) { value = x; }
};

#endif /* CONTAINER_H_ */
