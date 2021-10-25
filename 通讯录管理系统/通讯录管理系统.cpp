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

int IfExist(AddreBooks* a, string name);//��ѯ��ϵ���Ƿ���ڣ������������±괫����

int main()
{
	int switch1 = 0;
	AddreBooks abs;
	abs.c_size = 0;
	PrintMenu();

	while (true)
	{
		cout << "����ѡ����빦�ܣ�" << endl;
		cin >> switch1;
		switch (switch1)
		{
		case 1: PrintContact(&abs); break;//��ʾ��ϵ��
		case 2: TextC(&abs);  break;//�����ϵ��
		case 3: ModifyContact(&abs); break;//�޸���ϵ��
		case 4: DelContact(&abs); break;//ɾ����ϵ��
		case 5: FindContact(&abs); break;//��ѯ��ϵ��
		case 6: ClearContact(&abs); break;//���ͨѶ¼
		case 7:
			cout << "�˳�ͨѶ¼" << endl;
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
	cout << "*******1����ʾ��ϵ��******" << endl;
	cout << "*******2�������ϵ��******" << endl;
	cout << "*******3���޸���ϵ��******" << endl;
	cout << "*******4��ɾ����ϵ��******" << endl;
	cout << "*******5����ѯ��ϵ��******" << endl;
	cout << "*******6�����ͨѶ¼******" << endl;
	cout << "*******7���˳�ͨѶ¼******" << endl;
	cout << "**************************" << endl;
}

void AddContacts(AddreBooks *a)
{
	int gender;
	int sex_ture = 1;
	string men = "��";
	string wamen = "Ů";
	if (a->c_size == Max)
		cout << "ͨѶ¼������" << endl;
	else
	{
		cout << "�����ϵ��������" << endl;
		cin >> a->contacts[a->c_size].name;

		cout << "�Ա�Ϊ��" << endl;
		cout << "1������" << endl;
		cout << "2����Ů" << endl;	
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
			cout << "������ѡ���Ա�" << endl;
		}

		cout << "����Ϊ��" << endl;
		cin >> a->contacts[a->c_size].age;
		cout << "��ϵ�˵�ַ��" << endl;
		cin >> a->contacts[a->c_size].address;
		cout << "��ϵ��ʽ��" << endl;
		cin >> a->contacts[a->c_size].phone;
		a->c_size++;

	}
}

void PrintContact(AddreBooks *a)
{
	if (a->c_size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else 
	{
		for (int i = 0; i < a->c_size; i++)
		{
			cout << "��ϵ�������� " << a->contacts[i].name
				<< "\t�Ա�   " << a->contacts[i].gender
				<< "\t���䣺   " << a->contacts[i].age
				<< "\t��ϵ�˵�ַ��" << a->contacts[i].address
				<< "\t��ϵ��ʽ��  " << a->contacts[i].phone
				<< endl;
		}
	}
}

void FindContact(AddreBooks* a)
{
	string m_name;
	cout << "��������ϵ�������� ";
	cin >> m_name;
	int find = IfExist(a, m_name);
	if (find == -1)
		cout << "���޴��ˣ�" << endl;
	else
	{
		cout << "��ϵ��������" << a->contacts[find].name
			<< "\t�Ա�" << a->contacts[find].gender
			<< "\t���䣺" << a->contacts[find].age
			<< "\t��ϵ�˵�ַ��" << a->contacts[find].address
			<< "\t��ϵ��ʽ��  " << a->contacts[find].phone
			<< endl;
	}

}
//������ʵ�֣���ѭ�����ܴ�����
void ModifyContact(AddreBooks* a)
{
	string m_name;
	int m_key = 0;
	cout << "������Ҫ�޸ĵ���ϵ�˵�������";
	cin >> m_name;
	int find = IfExist(a, m_name);
	if (find == -1)
		cout << "���޴��ˣ�" << endl;
	else
	{
		cout << "�޸���һ�" << endl;
		cout << "1------���� " << endl;
		cout << "2------�Ա� " << endl;
		cout << "3------���� " << endl;
		cout << "4------��ַ " << endl;
		cout << "5------�绰 " << endl;
		cin >> m_key;
		switch (m_key)
		{
		case 1:
			cout << "�޸������� ";
			cin >> a->contacts[find].name;
			break;
		case 2:
			cout << "�޸��Ա� ";
			cin >> a->contacts[find].gender;
			break;
		case 3:
			cout << "�޸����䣺 ";
			cin >> a->contacts[find].age;
			break;
		case 4:
			cout << "�޸ĵ�ַ�� ";
			cin >> a->contacts[find].address;
			break;
		case 5:
			cout << "�޸ĵ绰�� ";
			cin >> a->contacts[find].phone;
			break;
		default:
			cout << "����ѡ������޷��޸ģ�" << endl;
			break;
		}
	}
}

void DelContact(AddreBooks* a)
{
	string m_name;
	cout << "������Ҫɾ������ϵ�������� ";
	cin >> m_name;
	int find = IfExist(a, m_name);
	if (find == -1)
		cout << "���޴��ˣ�" << endl;
	else
	{
		for (int j = find; j < a->c_size - find; j++)
		{
			a->contacts[j] = a->contacts[j + 1];
		}
		a->c_size--;
		cout << "ɾ���ɹ���" << endl;
	}
}

void ClearContact(AddreBooks* a)
{
	int Y_N = 0;
	cout << "�Ƿ����ͨѶ¼��" << endl;
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
	a->contacts[0].name = "����";
	a->contacts[0].gender = "��";
	a->contacts[0].age = 18;
	a->contacts[0].address = "jiangxi";
	a->contacts[0].phone = "132";

	a->contacts[1].name = "����";
	a->contacts[1].gender = "Ů";
	a->contacts[1].age = 20;
	a->contacts[1].address = "jiangxi";
	a->contacts[1].phone = "131";

	a->contacts[2].name = "����";
	a->contacts[2].gender = "��";
	a->contacts[2].age = 89;
	a->contacts[2].address = "jiangxi";
	a->contacts[2].phone = "139";

	a->contacts[3].name = "����";
	a->contacts[3].gender = "��";
	a->contacts[3].age = 1;
	a->contacts[3].address = "jiangxi";
	a->contacts[3].phone = "137";

	a->c_size = 4;

	cout << "��ӳɹ���" << endl;
}

int IfExist(AddreBooks* a,string name)
{
	int re_flag = -1;
	for (int i = 0; i < a->c_size; i++)
	{
		if (a->contacts[i].name == name)
			re_flag = i;//����ѯ�����˵������±괫��ȥ�����������ظ�ʱ���벻���ã�
	}
	return re_flag;
}
