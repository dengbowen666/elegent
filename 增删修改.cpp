#pragma once // 只编译一次
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 结构体，存各个数据
struct Contact {
	string phoneNumber;
	string name;
	string tag;
	string address;
	string birthdate;
};


// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
// ↓↓↓↓↓     基础函数     ↓↓↓↓↓
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


// 1. 读取数据文件
// 读取文件数据(若有) or 创建(若无)     在"./data.csv"
// 返回值：所有Contact的vecter数组
vector<Contact> readContactsFromCSV() {
	vector<Contact> contacts;
	ifstream file("data.csv");

	if (file.is_open()) {
		string line;
		getline(file, line); // 跳过标题行，反正都是固定的
		// 在contacts中分别储存各个contact
		while (getline(file, line)) {
			Contact contact;
			istringstream iss(line);
			string field;

			getline(iss, field, ',');
			contact.phoneNumber = field;

			getline(iss, field, ',');
			contact.name = field;

			getline(iss, field, ',');
			contact.tag = field;

			getline(iss, field, ',');
			contact.address = field;

			getline(iss, field, ',');
			contact.birthdate = field;

			contacts.push_back(contact);
		}

		file.close();

		cout << "成功读取 通讯录数据" << endl;
		//cout << "\n按任意键启动 通讯录管理系统" << endl;
		//cin.ignore(); // 忽略用户输入的字符
	}
	else {
		cout << "无法打开 通讯录数据文件" << endl;
		ofstream file("data.csv");

		file.close();
		cout << "已创建 通讯录数据文件" << endl;
		//cout << "\n按任意键以启动 通讯录管理系统" << endl;
		//cin.ignore();
	}
	system("cls");
	return contacts;
}
// 2. 保存数据文件
// 参数1：contact的vector数组
void saveContactsToCSV(const vector<Contact>& contacts) {
	ofstream file("data.csv");
	if (file.is_open()) {
		file << "Phone Number,Name,Tag,Address,Birthdate\n";

		for (const auto& contact : contacts) {
			file << contact.phoneNumber << ","
				<< contact.name << ","
				<< contact.tag << ","
				<< contact.address << ","
				<< contact.birthdate << "\n";
		}

		file.close();

		std::cout << "通讯录保存成功" << std::endl;
	}
	else {
		std::cout << "无法打开文件" << std::endl;
	}
}
// 3. 排序


// 3. 清空
// 3.1 清空输入流中的剩余字符（主要用于防止有人手贱，喜欢骚整，打一串字符）
// 3.2 清空界面
void clearIstream() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// 参数1：忽略限制为最大值(即，忽略所有字符)	参数2：忽略的终止字符为'\n'
	system("cls");
}



// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
// ↓↓↓↓↓     界面函数     ↓↓↓↓↓
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
// 
// 1. 主菜单界面
void showMenu() {
	clearIstream();
	cout << "*******************************" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    欢迎使用通讯录   *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*******************************" << endl;
	cout << "*****    1、显示联系人    *****" << endl;
	cout << "*****    2、查找联系人    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    3、添加联系人    *****" << endl;
	cout << "*****    4、删除联系人    *****" << endl;
	cout << "*****    5、修改联系人    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    6、立即排序      *****" << endl;
	cout << "*****    7、清空联系人    *****" << endl;
	cout << "*****                     *****" << endl;
	cout << "*****    0、退出通讯录    *****" << endl;
	cout << "*******************************" << endl;
}

// 2. 显示联系人
void showMenu_1() {
	clearIstream();
	cout << "检测到 输入 1" << endl;
}
// 3. 查找联系人
void showMenu_2() {
	clearIstream();
	cout << "检测到 输入 2" << endl;
}
// 4. 添加联系人 
void showMenu_3() {
	clearIstream();
	cout << "检测到 输入 3" << endl;
}
// 5. 删除联系人
void showMenu_4() {
	clearIstream();
	cout << "检测到 输入 4" << endl;
}
// 6. 修改联系人
void showMenu_5() {
	clearIstream();
	cout << "检测到 输入 5" << endl;
}
// 7. 立即排序		不需要界面，吧
void showMenu_6() {
	clearIstream();
	cout << "检测到 输入 6" << endl;
}
// 8. 清空联系人(需要确认 或者 有个密码)
void showMenu_7() {
	clearIstream();
	cout << "检测到 输入 7" << endl;
}
// 9. 退出通讯录		在main.cpp中实现
void showMenu_0() {
	clearIstream();
	cout << "检测到 输入 0" << endl;
	cout << "欢迎下次使用" << endl;
	system("pause");
	return;
}


void modify(vector<Contact>& a){
	cout << "请输入你要修改的联系人号码: " << endl;
	string number;
	cin >> number;
	auto it = a.begin();
	while (it!= a.end()) {
		if (number == it->phoneNumber) {
			cout << "请确定你要修改的内容：1-name\n2-address\n3-phoneNumber\n4-tag\n5-birthdate " << endl;
			int n;
			cin >> n;
			switch (n) {
			case 1:
				cout << "请输入你要修改的内容：" << endl;
				cin >> it->name;
				break;
			case 2:
				cout << "请输入你要修改的内容：" << endl;
				cin >> it->address;
				break;
			case 3:
				cout << "请输入你要修改的内容：" << endl;
				cin >> it->phoneNumber;
				break;
			case 4:
				cout << "请输入你要修改的内容：" << endl;
				cin >> it->tag;
				break;
			case 5:
				cout << "请输入你要修改的内容：" << endl;
				cin >> it->birthdate;
				break;

			}


		}it++;
	
	}
	cout << "修改成功" << endl;
	system("pause");
	system("cls");



}

void add(vector<Contact>& a) {
	Contact person;
	cout << "请输入姓名： " << endl;
	cin >> person.name;
	cout << "请输入地址：" << endl;
	cin >> person.address;
	cout << "请输入号码： " << endl;
	cin >> person.phoneNumber;
	cout << "请输入标签： " << endl;
	cin >> person.tag;
	cout << "请输入生日：" << endl;
	cin >> person.birthdate;
	a.push_back(person);
	cout << "添加成功" << endl;
	system("pause");
	system("cls");






}

void dele(vector<Contact>& a) {
	cout << "请输入你要删除的联系人电话： " << endl;
	string number;
	cin >> number;
	auto it = a.begin();
	while (it != a.end()) {
		if (number == it->phoneNumber) {
		a.erase(it + 1);
			cout << "删除成功" << endl;
			break;

		}
		it++;
	}system("pause");
	system("cls");
}
int main() {
	// 读取数据
	vector<Contact> Contacts = readContactsFromCSV();
	clearIstream();
	// 启动 
	for (;;) {

		showMenu();
		char select;
		cin >> select;
		if (select == '1') {
			showMenu_1();
		}
		else if (select == '2') {
			showMenu_2();
		}
		else if (select == '3') {
			showMenu_3();
			add(Contacts);

		}
		else if (select == '4') {
			showMenu_4();
			dele(Contacts);
		}
		else if (select == '5') {
			showMenu_5();
		    modify(Contacts);
		}
		else if (select == '6') {
			showMenu_6();
		}
		else if (select == '7') {
			showMenu_7();
		}
		else if (select == '0') {
			showMenu_0();
		}
		else {
			clearIstream();
			cout << "检测到非法操作符\n请按任意建继续..." << endl;
			clearIstream();
		}
	}


	return 0;
}