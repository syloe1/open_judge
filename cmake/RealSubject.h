#ifndef REALSUBJECT_H
#define REALSUBJECT_H
#include "Subject.h"
class RealSubject : public Subject{
public: 
	// 实现基类的纯虚函数 request，并使用 final 表示不能被进一步重写
	virtual void request() override final;  

	virtual ~RealSubject();	
};
#endif