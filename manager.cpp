#include"manager.h"
//manager的函数主体在这
manager::manager(int id, string name, int did) //是manager下的成员函数
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}

void  manager::ShowInfor()//输出职工信息
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->GetDeptname()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string manager::GetDeptname()//输出职位
{
	return string("经理");
}