#pragma once
//ֱ�����û���ͷ�ļ�
#include"Worker.h"

class manager :public Worker
{
public:
	//���������캯�� ���ڴ�����
	manager(int id, string name, int did);

	virtual void ShowInfor(); //���ְ����Ϣ

	virtual string GetDeptname();//���ְλ
};