#ifndef SUBJECT_H
#define SUBJECT_H
class Subject
{
public:
	virtual void request() = 0;  // 纯虚函数，必须由派生类实现
	virtual ~Subject(){}; //虚析构函数
};
#endif