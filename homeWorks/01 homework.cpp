#include <iostream>
using namespace std;
#include <string>
#include <assert.h>
#define MAX 1000

struct Person//联系人结构体
{
	string m_Name;//姓名
	int m_Sex;//性别：1男 2女
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Addr;//住址
};

struct Addressbooks
{
	struct Person personArray[MAX];//通讯录中保存的联系人数组

	int m_Size;//初始化通讯录中人员个数
};
void addPerson( Addressbooks * abs)//添加联系人函数
{
	//判断通讯录是否已满，如果满了就无法添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别： " << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;

		while (true)
		{
			//输入1.2可以退出，有误重新输入。
			cin >> sex;
			assert(sex == 1 || sex == 2);
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}
		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");//任意键继续
		system("cls");//清屏    
	} 
}
//显所有联系人
void showPerson(Addressbooks  abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
		//如果不为0，显示记录的联系人信息。
	if (abs.m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs.m_Size; i++)
		{
			cout << "姓名：" << abs.personArray[i].m_Name << "\t";
			cout << "性别：" << (abs.personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs.personArray[i].m_Age << "\t";
			cout << "电话：" << abs.personArray[i].m_Phone << "\t";
			cout << "住址：" << abs.personArray[i].m_Addr << endl;
		}
	}
	system("pause");//任意键继续
	system("cls");//清屏   

}

//检测联系人是否存在，如果存在返回联系人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks * abs, string name) //参数1 通讯录  参数2  对比人名
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户输入的姓名了
		if (abs->personArray[i].m_Name == name)
		{
			return i;//如果找到了，返回这个人在数组中的下表
		}

	}
	return -1; //如果没有找到返回-1
}
//3、删除指定的联系人
void deletePerson(Addressbooks * abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int  ret = isExist(abs, name/*I*/);
	if (ret != -1)
	{
		//查到此人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新通讯录中人数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void showMenu()//封装函数显示菜单功能
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

int main()
{
	struct Addressbooks abs;//创建通讯录结构体变量

	abs.m_Size = 0;

	int select = 0;//创建用户选择输入的变量

	while (true)  //可以重复使用菜单，只有输入0时方可退出函数
	{
		showMenu();//菜单调用

		cin >> select;

		assert(select >= 0&&select <= 6);
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs/*I/O*/);//利用地址传递，可以修饰实参
			break;
		case 2://显示联系人
			showPerson(abs);//只显示不修改
			break;
		case 3://删除联系人
			deletePerson(&abs/*I/O*/);
			break;
		case 4://4、查找联系人
			break;
		case 5:// 5、修改联系人
			break;
		case 6:// 6、清空联系人 
			break;
		case 0://0、退出通讯录 
			cout << "欢迎下次使用" << endl;
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