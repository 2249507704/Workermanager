#pragma once
#include<iostream>
#include<string>
using namespace std;
//抽象职工类
class Worker
{
public:

	virtual void ShowInfor() = 0; //输出职工信息

	virtual string GetDeptname() = 0;//输出职位

	int m_id;
	string m_name;
	int m_did;
};
