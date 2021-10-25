#include <iostream>
#include <string>
using namespace std;

#define Max 20

struct Contact
{
	string name;

	string gender;

	int age;

	string address;

	string  phone;
};

struct AddreBooks
{
	Contact contacts[Max];

	int c_size;
};

void PrintMenu();
void AddContacts(AddreBooks *a);
void PrintContact(AddreBooks *a);
void ClearContact(AddreBooks* a);
void ModifyContact(AddreBooks* a);
void FindContact(AddreBooks* a);
void DelContact(AddreBooks* a);
void TextC(AddreBooks* a);

int IfExist(AddreBooks* a, string name);//查询联系人是否存在，存在则将数组下标传回来

int main()
{
	int switch1 = 0;
	AddreBooks abs;
	abs.c_size = 0;
	PrintMenu();

	while (true)
	{
		cout << "输入选项进入功能：" << endl;
		cin >> switch1;
		switch (switch1)
		{
		case 1: PrintContact(&abs); break;//显示联系人
		case 2: TextC(&abs);  break;//添加联系人
		case 3: ModifyContact(&abs); break;//修改联系人
		case 4: DelContact(&abs); break;//删除联系人
		case 5: FindContact(&abs); break;//查询联系人
		case 6: ClearContact(&abs); break;//清空通讯录
		case 7:
			cout << "退出通讯录" << endl;
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

void PrintMenu()
{
	cout << "**************************" << endl;
	cout << "*******1、显示联系人******" << endl;
	cout << "*******2、添加联系人******" << endl;
	cout << "*******3、修改联系人******" << endl;
	cout << "*******4、删除联系人******" << endl;
	cout << "*******5、查询联系人******" << endl;
	cout << "*******6、清空通讯录******" << endl;
	cout << "*******7、退出通讯录******" << endl;
	cout << "**************************" << endl;
}

void AddContacts(AddreBooks *a)
{
	int gender;
	int sex_ture = 1;
	string men = "男";
	string wamen = "女";
	if (a->c_size == Max)
		cout << "通讯录已满！" << endl;
	else
	{
		cout << "添加联系人姓名：" << endl;
		cin >> a->contacts[a->c_size].name;

		cout << "性别为：" << endl;
		cout << "1——男" << endl;
		cout << "2——女" << endl;	
		while(sex_ture)
		{
			cin >> gender;
			if(gender == 1)
			{
				a->contacts[a->c_size].gender = men;
				break;
			}
			else if (gender == 2)
			{
				a->contacts[a->c_size].gender = wamen;
				break;
			}
			cout << "请重新选择性别！" << endl;
		}

		cout << "年龄为：" << endl;
		cin >> a->contacts[a->c_size].age;
		cout << "联系人地址：" << endl;
		cin >> a->contacts[a->c_size].address;
		cout << "联系方式：" << endl;
		cin >> a->contacts[a->c_size].phone;
		a->c_size++;

	}
}

void PrintContact(AddreBooks *a)
{
	if (a->c_size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else 
	{
		for (int i = 0; i < a->c_size; i++)
		{
			cout << "联系人姓名： " << a->contacts[i].name
				<< "\t性别：   " << a->contacts[i].gender
				<< "\t年龄：   " << a->contacts[i].age
				<< "\t联系人地址：" << a->contacts[i].address
				<< "\t联系方式：  " << a->contacts[i].phone
				<< endl;
		}
	}
}

void FindContact(AddreBooks* a)
{
	string m_name;
	cout << "请输入联系人姓名： ";
	cin >> m_name;
	int find = IfExist(a, m_name);
	if (find == -1)
		cout << "查无此人！" << endl;
	else
	{
		cout << "联系人姓名：" << a->contacts[find].name
			<< "\t性别：" << a->contacts[find].gender
			<< "\t年龄：" << a->contacts[find].age
			<< "\t联系人地址：" << a->contacts[find].address
			<< "\t联系方式：  " << a->contacts[find].phone
			<< endl;
	}

}
//功能已实现，但循环功能待考虑
void ModifyContact(AddreBooks* a)
{
	string m_name;
	int m_key = 0;
	cout << "请输入要修改的联系人的姓名：";
	cin >> m_name;
	int find = IfExist(a, m_name);
	if (find == -1)
		cout << "查无此人！" << endl;
	else
	{
		cout << "修改哪一项：" << endl;
		cout << "1------姓名 " << endl;
		cout << "2------性别 " << endl;
		cout << "3------年龄 " << endl;
		cout << "4------地址 " << endl;
		cout << "5------电话 " << endl;
		cin >> m_key;
		switch (m_key)
		{
		case 1:
			cout << "修改姓名： ";
			cin >> a->contacts[find].name;
			break;
		case 2:
			cout << "修改性别： ";
			cin >> a->contacts[find].gender;
			break;
		case 3:
			cout << "修改年龄： ";
			cin >> a->contacts[find].age;
			break;
		case 4:
			cout << "修改地址： ";
			cin >> a->contacts[find].address;
			break;
		case 5:
			cout << "修改电话： ";
			cin >> a->contacts[find].phone;
			break;
		default:
			cout << "输入选项错误，无法修改！" << endl;
			break;
		}
	}
}

void DelContact(AddreBooks* a)
{
	string m_name;
	cout << "请输入要删除的联系人姓名： ";
	cin >> m_name;
	int find = IfExist(a, m_name);
	if (find == -1)
		cout << "查无此人！" << endl;
	else
	{
		for (int j = find; j < a->c_size - find; j++)
		{
			a->contacts[j] = a->contacts[j + 1];
		}
		a->c_size--;
		cout << "删除成功！" << endl;
	}
}

void ClearContact(AddreBooks* a)
{
	int Y_N = 0;
	cout << "是否清空通讯录？" << endl;
	cout << "1---Yes" << endl;
	cout << "2---No" << endl;
	cin >> Y_N; 
	if (Y_N == 1)
	{
		//free(a->contacts);
		a->c_size = 0;
	}
}

void TextC(AddreBooks* a)
{
	a->contacts[0].name = "张三";
	a->contacts[0].gender = "男";
	a->contacts[0].age = 18;
	a->contacts[0].address = "jiangxi";
	a->contacts[0].phone = "132";

	a->contacts[1].name = "李四";
	a->contacts[1].gender = "女";
	a->contacts[1].age = 20;
	a->contacts[1].address = "jiangxi";
	a->contacts[1].phone = "131";

	a->contacts[2].name = "王五";
	a->contacts[2].gender = "男";
	a->contacts[2].age = 89;
	a->contacts[2].address = "jiangxi";
	a->contacts[2].phone = "139";

	a->contacts[3].name = "温流";
	a->contacts[3].gender = "男";
	a->contacts[3].age = 1;
	a->contacts[3].address = "jiangxi";
	a->contacts[3].phone = "137";

	a->c_size = 4;

	cout << "添加成功！" << endl;
}

int IfExist(AddreBooks* a,string name)
{
	int re_flag = -1;
	for (int i = 0; i < a->c_size; i++)
	{
		if (a->contacts[i].name == name)
			re_flag = i;//将查询到的人的数组下标传回去，当有人名重复时代码不适用；
	}
	return re_flag;
}
