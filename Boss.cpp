#include"Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}

void Boss::ShowInfor()//���ְ����Ϣ
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->GetDeptname()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::GetDeptname()//���ְλ
{
	return string("�ϰ�");
}