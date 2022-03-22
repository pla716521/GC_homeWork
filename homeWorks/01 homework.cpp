#include <iostream>
using namespace std;
#include <string>
#include <assert.h>
#define MAX 1000

struct Person//��ϵ�˽ṹ��
{
	string m_Name;//����
	int m_Sex;//�Ա�1�� 2Ů
	int m_Age;//����
	string m_Phone;//�绰
	string m_Addr;//סַ
};

struct Addressbooks
{
	struct Person personArray[MAX];//ͨѶ¼�б������ϵ������

	int m_Size;//��ʼ��ͨѶ¼����Ա����
};
void addPerson( Addressbooks * abs)//�����ϵ�˺���
{
	//�ж�ͨѶ¼�Ƿ�������������˾��޷����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int sex = 0;

		while (true)
		{
			//����1.2�����˳��������������롣
			cin >> sex;
			assert(sex == 1 || sex == 2);
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룺" << endl;
		}
		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//���������
		system("cls");//����    
	} 
}
//��������ϵ��
void showPerson(Addressbooks  abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
		//�����Ϊ0����ʾ��¼����ϵ����Ϣ��
	if (abs.m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs.m_Size; i++)
		{
			cout << "������" << abs.personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs.personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs.personArray[i].m_Age << "\t";
			cout << "�绰��" << abs.personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs.personArray[i].m_Addr << endl;
		}
	}
	system("pause");//���������
	system("cls");//����   

}

//�����ϵ���Ƿ���ڣ�������ڷ�����ϵ�����������еľ���λ�ã������ڷ���-1
int isExist(Addressbooks * abs, string name) //����1 ͨѶ¼  ����2  �Ա�����
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].m_Name == name)
		{
			return i;//����ҵ��ˣ�����������������е��±�
		}

	}
	return -1; //���û���ҵ�����-1
}
//3��ɾ��ָ������ϵ��
void deletePerson(Addressbooks * abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	int  ret = isExist(abs, name/*I*/);
	if (ret != -1)
	{
		//�鵽���ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼������
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void showMenu()//��װ������ʾ�˵�����
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

int main()
{
	struct Addressbooks abs;//����ͨѶ¼�ṹ�����

	abs.m_Size = 0;

	int select = 0;//�����û�ѡ������ı���

	while (true)  //�����ظ�ʹ�ò˵���ֻ������0ʱ�����˳�����
	{
		showMenu();//�˵�����

		cin >> select;

		assert(select >= 0&&select <= 6);
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs/*I/O*/);//���õ�ַ���ݣ���������ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(abs);//ֻ��ʾ���޸�
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs/*I/O*/);
			break;
		case 4://4��������ϵ��
			break;
		case 5:// 5���޸���ϵ��
			break;
		case 6:// 6�������ϵ�� 
			break;
		case 0://0���˳�ͨѶ¼ 
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}	
	system("pause");
	return 0;

}