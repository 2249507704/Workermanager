#pragma once
#include"Worker.h"

class Employer :public Worker
{
public:
	//Ҫ��Ա����Ϣ ����Ҫ����һ��Ա��
	Employer(int id, string name, int did);

	virtual void ShowInfor(); //Ҫ����һ��Ա����Ϣ ������ʾԱ����Ϣ
	

	virtual string GetDeptname();//����did��ѡ���Ӧְλ ���Ҫͨ��switch�����ʵ�ֶ�Ӧ���ֶ�Ӧְλ

	~Employer();
	
};