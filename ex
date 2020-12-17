q:为什么有时类的析构函数要定义为protected呢？
a:如果一个类被继承，同时定义了基类以外的成员对象，且基类析构函数不是virtual修饰的，
那么当基类指针或引用指向派生类对象并析构（例如自动对象在函数作用域结束时；或者通过delete）时，会调用基类的析构函数而导致派生类定义的成员没有被析构，产生内存泄露等问题。虽然把析构函数定义成virtual的可以解决这个问题，但是当其它成员函数都不是virtual函数时，会在基类和派生类引入vtable，实例引入vptr造成运行时的性能损失。

如果确定不需要直接而是只通过派生类对象使用基类，可以把析构函数定义为protected（这样会导致基类和派生类外使用自动对象和delete时的错误，因为访问权限禁止调用析构函数），就不会导致以上问题。

#include <iostream>
#include <utility>
#include <memory>
using namespace std;

class A{
public:
  A(){
    cout << "A" << endl;
  }
  virtual ~A(){
    cout << "~A" << endl;
  }
};

class B :public A{
public:
  B(){
    cout << "B" << endl;
  }
  virtual ~B()
  {
    cout << "~B" << endl;
  }
};

int main()
{
  {
    //std::shared_ptr<A> a = std::make_shared<A>(); 
     A* a = new B();
     delete a;
  }
  return 0;  
}

A
B
~B
~A

如果～A不是virtual
A
B
~A





