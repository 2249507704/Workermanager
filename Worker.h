#pragma once
#include<iostream>
#include<string>
using namespace std;
//����ְ����
class Worker
{
public:

	virtual void ShowInfor() = 0; //���ְ����Ϣ

	virtual string GetDeptname() = 0;//���ְλ

	int m_id;
	string m_name;
	int m_did;
};
