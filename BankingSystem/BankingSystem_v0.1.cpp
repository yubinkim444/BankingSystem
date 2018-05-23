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
	cout << "1. 계좌개설 (Make Account)" << endl;
	cout << "2. 입금(deposit)" << endl;
	cout << "3. 출금(withdraw)" << endl;
	cout << "4. 계좌정보 출력(show Account Info)" << endl;
	cout << "5. 종료(quit)" << endl;
}
void makeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	cout << "[계좌 개설(MAKE ACCOUNT)]" << endl;
	cout << "계좌 ID (account ID):";
	cin >> id;
	cout << "이름(name):" ;
	cin >> name;
	cout << "입금액(deposit money):";
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
	cout << "[입금(DEPOSIT)]" << endl;
	cout << "계좌 ID(account ID):";
	cin >> id;
	cout << "입금액(deposit money):";
	cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "입금완료(Deposit success)" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID(check your id)" << endl;

}
void withdrawMoney() {
	int money;
	int id;
	cout << "[출금(WITHDRAW)]" << endl;
	cout << "계좌 ID(account ID):";
	cin >> id;
	cout << "출금액(withdraw money):";
	cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			
			if (accArr[i].balance < money) {
				cout << "잔액 부족" << endl;
				return;
			}
			accArr[i].balance -= money;
			cout << "출금완료(Deposit success)" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID(check your id)" << endl;
}
void showAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "계좌 ID (id)" << accArr[i].accID << endl;
		cout << "이름 (name)" << accArr[i].cusName << endl;
		cout << "잔액 (balance)" << accArr[i].balance <<endl;
	}
}