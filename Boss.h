#pragma once
#include"Worker.h"

class Boss :public Worker
{
public:
	//构造一个用于传入参数的函数
	Boss(int id,string name,int did);

	virtual void ShowInfor();//输出职工信息

	virtual string GetDeptname();//输出职位

};