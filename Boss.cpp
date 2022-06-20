#include"Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}

void Boss::ShowInfor()//输出职工信息
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->GetDeptname()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::GetDeptname()//输出职位
{
	return string("老板");
}