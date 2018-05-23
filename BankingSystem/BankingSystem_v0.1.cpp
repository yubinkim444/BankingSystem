#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void showMenu();
void makeAccount();
void depositMoney();
void withdrawMoney();
void showAllAccInfo();

enum {MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int accID;
	int balance;
	char cusName[NAME_LEN];
}Account;

Account accArr[100];
int accNum = 0;
int main(void) {
	int choice;
	while (1)
	{
		showMenu();
		cout << "select: ";
		cin >> choice;
		cout << endl;
		switch (choice) 
		{
		case MAKE:
			makeAccount();
			break;
		case DEPOSIT:
			depositMoney();
			break;
		case WITHDRAW:
			withdrawMoney();
			break;
		case INQUIRE:
			showAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegeal Section.." << endl;

		}		
	}
	return 0;
}
void showMenu() {
	cout << "---------Menu-----------"<<endl;
	cout << "1. ���°��� (Make Account)" << endl;
	cout << "2. �Ա�(deposit)" << endl;
	cout << "3. ���(withdraw)" << endl;
	cout << "4. �������� ���(show Account Info)" << endl;
	cout << "5. ����(quit)" << endl;
}
void makeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	cout << "[���� ����(MAKE ACCOUNT)]" << endl;
	cout << "���� ID (account ID):";
	cin >> id;
	cout << "�̸�(name):" ;
	cin >> name;
	cout << "�Աݾ�(deposit money):";
	cin >> balance;
	cout << endl;
	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName, name);
	accNum++;

}
void depositMoney() {
	int money;
	int id;
	cout << "[�Ա�(DEPOSIT)]" << endl;
	cout << "���� ID(account ID):";
	cin >> id;
	cout << "�Աݾ�(deposit money):";
	cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "�ԱݿϷ�(Deposit success)" << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID(check your id)" << endl;

}
void withdrawMoney() {
	int money;
	int id;
	cout << "[���(WITHDRAW)]" << endl;
	cout << "���� ID(account ID):";
	cin >> id;
	cout << "��ݾ�(withdraw money):";
	cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			
			if (accArr[i].balance < money) {
				cout << "�ܾ� ����" << endl;
				return;
			}
			accArr[i].balance -= money;
			cout << "��ݿϷ�(Deposit success)" << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID(check your id)" << endl;
}
void showAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "���� ID (id)" << accArr[i].accID << endl;
		cout << "�̸� (name)" << accArr[i].cusName << endl;
		cout << "�ܾ� (balance)" << accArr[i].balance <<endl;
	}
}