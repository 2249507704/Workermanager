#include"manager.h"
//manager�ĺ�����������
manager::manager(int id, string name, int did) //��manager�µĳ�Ա����
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}

void  manager::ShowInfor()//���ְ����Ϣ
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->GetDeptname()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string manager::GetDeptname()//���ְλ
{
	return string("����");
}