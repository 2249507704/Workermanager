#include"employer.h"
//cpp里直接写函数主体

Employer::Employer(int id, string name, int did) //要传入一个员工信息 用于输出
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}

void Employer::ShowInfor() //输出职工信息
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->GetDeptname()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

string Employer::GetDeptname()
{
	return string("员工");
}