#include"employer.h"
//cpp��ֱ��д��������

Employer::Employer(int id, string name, int did) //Ҫ����һ��Ա����Ϣ �������
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}

void Employer::ShowInfor() //���ְ����Ϣ
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->GetDeptname()
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employer::GetDeptname()
{
	return string("Ա��");
}