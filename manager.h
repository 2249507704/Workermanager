#pragma once
//直接引用基类头文件
#include"Worker.h"

class manager :public Worker
{
public:
	//再来个构造函数 用于传数据
	manager(int id, string name, int did);

	virtual void ShowInfor(); //输出职工信息

	virtual string GetDeptname();//输出职位
};