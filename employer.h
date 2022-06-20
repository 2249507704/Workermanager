#pragma once
#include"Worker.h"

class Employer :public Worker
{
public:
	//要有员工信息 首先要构造一个员工
	Employer(int id, string name, int did);

	virtual void ShowInfor(); //要传入一个员工信息 用于显示员工信息
	

	virtual string GetDeptname();//根据did来选择对应职位 后边要通过switch语句来实现对应数字对应职位

	~Employer();
	
};