#pragma once
#include"Worker.h"

class Boss :public Worker
{
public:
	//����һ�����ڴ�������ĺ���
	Boss(int id,string name,int did);

	virtual void ShowInfor();//���ְ����Ϣ

	virtual string GetDeptname();//���ְλ

};