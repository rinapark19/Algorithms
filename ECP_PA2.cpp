#include <iostream>
#include <string>
using namespace std;

class Account
{
	public:
		Account(int idv);
		void setId(int id);
		int getId();
		void setName(string name);
		string getName();
		void setMoney(int money);
		int getMoney();
	
	private:
		int id;
		string name;
		int money;
};

Account::Account(int idv)
{
	id = idv;
}
void Account::setId(int id)
{
	this->id = id;
}

int Account::getId()
{
	return this->id;
}

void Account::setName(string name)
{
	this->name = name;
}

string Account::getName()
{
	return this->name;
}

void Account::setMoney(int money)
{
	this->money = money;
}

int Account::getMoney()
{
	return this->money;
}

Account a1(0);
Account a2(1);
Account a3(2);
Account a4(3);
Account a5(4);

class Bank
{
	public:
		void createAccount(int id, string name);
		void sendMoney(int id1, int id2, int money);
		void depositMoney(int id, int money);
		void withdrawMoney(int id, int money);
		void printInfo(int n);
	
	private:
};

void Bank::createAccount(int id, string name)
{
	if(id == 0)
	{
		a1.setId(id);
		a1.setName(name);
		a1.setMoney(0);
	}
	else if(id == 1)
	{
		a2.setId(id);
		a2.setName(name);
		a2.setMoney(0);
	}
	else if(id == 2)
	{
		a3.setId(id);
		a3.setName(name);
		a3.setMoney(0);
	}
	else if(id == 3)
	{
		a4.setId(id);
		a4.setName(name);
		a4.setMoney(0);
	}
	else if(id == 4)
	{
		a5.setId(id);
		a5.setName(name);
		a5.setMoney(0);
	}
}

void Bank::sendMoney(int id1, int id2, int money)
{
	if(id1 == 0)
	{
		if(id2 == 1)
		{
			cout << "Try to send " << money << " from USER" << a1.getId() << " to USER" << a2.getId() << " ... " << endl;
			cout << "\n";
			
			if(a1.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a1.getMoney() - money;
				int n = a2.getMoney() + money;
				a1.setMoney(m);
				a2.setMoney(n);
			}
		}
		else if(id2 == 2)
		{
			cout << "Try to send " << money << " from USER" << a1.getId() << " to USER" << a3.getId() << " ... " << endl;
			cout << "\n";
			
			if(a1.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a1.getMoney() - money;
				int n = a3.getMoney() + money;
				a1.setMoney(m);
				a3.setMoney(n);
			}
		}
		else if(id2 == 3)
		{
			cout << "Try to send " << money << " from USER" << a1.getId() << " to USER" << a4.getId() << " ... " << endl;
			cout << "\n";
			
			if(a1.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a1.getMoney() - money;
				int n = a4.getMoney() + money;
				a1.setMoney(m);
				a4.setMoney(n);
			}
		}
		else if(id2 == 4)
		{
			cout << "Try to send " << money << " from USER" << a1.getId() << " to USER" << a5.getId() << " ... " << endl;
			cout << "\n";
			
			if(a1.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a1.getMoney() - money;
				int n = a5.getMoney() + money;
				a1.setMoney(m);
				a5.setMoney(n);
			}
		}
		else
		{
			cout << "Error : No exist user ..." << endl;
			cout << "\n";
		}
	}
	else if(id1 == 1)
	{
		if(id2 == 0)
		{
			cout << "Try to send " << money << " from USER" << a2.getId() << " to USER" << a1.getId() << " ... " << endl;
			cout << "\n";
			
			if(a2.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a2.getMoney() - money;
				int n = a1.getMoney() + money;
				a2.setMoney(m);
				a1.setMoney(n);
			}
		}
		else if(id2 == 2)
		{
			cout << "Try to send " << money << " from USER" << a2.getId() << " to USER" << a3.getId() << " ... " << endl;
			cout << "\n";
			
			if(a2.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a2.getMoney() - money;
				int n = a3.getMoney() + money;
				a2.setMoney(m);
				a3.setMoney(n);
			}
		}
		else if(id2 == 3)
		{
			cout << "Try to send " << money << " from USER" << a2.getId() << " to USER" << a4.getId() << " ... " << endl;
			cout << "\n";
			
			if(a2.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a2.getMoney() - money;
				int n = a4.getMoney() + money;
				a2.setMoney(m);
				a4.setMoney(n);
			}
		}
		else if(id2 == 4)
		{
			cout << "Try to send " << money << " from USER" << a2.getId() << " to USER" << a5.getId() << " ... " << endl;
			cout << "\n";
			
			if(a2.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a2.getMoney() - money;
				int n = a5.getMoney() + money;
				a2.setMoney(m);
				a5.setMoney(n);
			}
		}
		else
		{
			cout << "Error : No exist user ..." << endl;
			cout << "\n";
		}
	}
	else if(id1 == 2)
	{
		if(id2 == 0)
		{
			cout << "Try to send " << money << " from USER" << a3.getId() << " to USER" << a1.getId() << " ... " << endl;
			cout << "\n";
			
			if(a3.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a3.getMoney() - money;
				int n = a1.getMoney() + money;
				a3.setMoney(m);
				a1.setMoney(n);
			}
		}
		else if(id2 == 1)
		{
			cout << "Try to send " << money << " from USER" << a3.getId() << " to USER" << a2.getId() << " ... " << endl;
			cout << "\n";
			
			if(a3.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a3.getMoney() - money;
				int n = a2.getMoney() + money;
				a3.setMoney(m);
				a2.setMoney(n);
			}
		}
		else if(id2 == 3)
		{
			cout << "Try to send " << money << " from USER" << a3.getId() << " to USER" << a4.getId() << " ... " << endl;
			cout << "\n";
			
			if(a3.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a3.getMoney() - money;
				int n = a4.getMoney() + money;
				a3.setMoney(m);
				a4.setMoney(n);
			}
		}
		else if(id2 == 4)
		{
			cout << "Try to send " << money << " from USER" << a3.getId() << " to USER" << a5.getId() << " ... " << endl;
			cout << "\n";
			
			if(a3.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a3.getMoney() - money;
				int n = a5.getMoney() + money;
				a3.setMoney(m);
				a5.setMoney(n);
			}
		}
		else
		{
			cout << "Error : No exist user ..." << endl;
			cout << "\n";
		}
	}
	else if(id1 == 3)
	{
		if(id2 == 0)
		{
			cout << "Try to send " << money << " from USER" << a4.getId() << " to USER" << a1.getId() << " ... " << endl;
			cout << "\n";
			
			if(a4.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a4.getMoney() - money;
				int n = a1.getMoney() + money;
				a4.setMoney(m);
				a1.setMoney(n);
			}
		}
		else if(id2 == 1)
		{
			cout << "Try to send " << money << " from USER" << a4.getId() << " to USER" << a2.getId() << " ... " << endl;
			cout << "\n";
			
			if(a4.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a4.getMoney() - money;
				int n = a2.getMoney() + money;
				a4.setMoney(m);
				a2.setMoney(n);
			}
		}
		else if(id2 == 2)
		{
			cout << "Try to send " << money << " from USER" << a4.getId() << " to USER" << a3.getId() << " ... " << endl;
			cout << "\n";
			
			if(a4.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a4.getMoney() - money;
				int n = a3.getMoney() + money;
				a4.setMoney(m);
				a3.setMoney(n);
			}
		}
		else if(id2 == 4)
		{
			cout << "Try to send " << money << " from USER" << a4.getId() << " to USER" << a5.getId() << " ... " << endl;
			cout << "\n";
			
			if(a4.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a4.getMoney() - money;
				int n = a5.getMoney() + money;
				a4.setMoney(m);
				a5.setMoney(n);
			}
		}
		else
		{
			cout << "Error : No exist user ..." << endl;
			cout << "\n";
		}
	}
	else if(id1 == 4)
	{
		if(id2 == 0)
		{
			cout << "Try to send " << money << " from USER" << a5.getId() << " to USER" << a1.getId() << " ... " << endl;
			cout << "\n";
			
			if(a5.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a5.getMoney() - money;
				int n = a1.getMoney() + money;
				a5.setMoney(m);
				a1.setMoney(n);
			}
		}
		else if(id2 == 1)
		{
			cout << "Try to send " << money << " from USER" << a5.getId() << " to USER" << a2.getId() << " ... " << endl;
			cout << "\n";
			
			if(a5.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a5.getMoney() - money;
				int n = a2.getMoney() + money;
				a5.setMoney(m);
				a2.setMoney(n);
			}
		}
		else if(id2 == 2)
		{
			cout << "Try to send " << money << " from USER" << a5.getId() << " to USER" << a3.getId() << " ... " << endl;
			cout << "\n";
			
			if(a5.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a5.getMoney() - money;
				int n = a3.getMoney() + money;
				a5.setMoney(m);
				a3.setMoney(n);
			}
		}
		else if(id2 == 3)
		{
			cout << "Try to send " << money << " from USER" << a5.getId() << " to USER" << a4.getId() << " ... " << endl;
			cout << "\n";
			
			if(a5.getMoney() < money)
			{
				cout << "Error : Not enough money..." << endl;
				cout << "\n";
			}
			else
			{
				int m = a5.getMoney() - money;
				int n = a4.getMoney() + money;
				a5.setMoney(m);
				a4.setMoney(n);
			}
		}
		else
		{
			cout << "Error : No exist user ..." << endl;
			cout << "\n";
		}
	}
	else
	{
		cout << "Error : No exist user ..." << endl;
		cout << "\n";
	}
}

void Bank::depositMoney(int id, int money)
{
	if(id ==0)
	{
		int m = a1.getMoney() + money;
		a1.setMoney(m);
	}
	else if(id == 1)
	{
		int m = a2.getMoney() + money;
		a2.setMoney(m);
	}
	else if(id == 2)
	{
		int m = a3.getMoney() + money;
		a3.setMoney(m);
	}
	else if(id == 3)
	{
		int m = a4.getMoney() + money;
		a4.setMoney(m);
	}
	else if(id == 4)
	{
		int m = a5.getMoney() + money;
		a5.setMoney(m);
	}
	else
	{
		cout << "Error : No exist user ..." << endl;
		cout << "\n";
	}
}

void Bank::withdrawMoney(int id, int money)
{
	if(id == 0)
	{
		cout << "Try to withdraw " << money << " from USER" << a1.getId() << " ... " << endl;
		cout << "\n";
		
		if(a1.getMoney() < money)
		{
			cout << "Error : Not enough money..." << endl;
			cout << "\n";
		}
		else
		{
			int m = a1.getMoney() - money;
			a1.setMoney(m);
		}
	}
	else if(id == 1)
	{
		cout << "Try to withdraw " << money << " from USER" << a2.getId() << " ... " << endl;
		cout << "\n";
		
		if(a2.getMoney() < money)
		{
			cout << "Error : Not enough money..." << endl;
			cout << "\n";
		}
		else
		{
			int m = a2.getMoney() - money;
			a2.setMoney(m);
		}
	}
	else if(id == 2)
	{
		cout << "Try to withdraw " << money << " from USER" << a3.getId() << " ... " << endl;
		cout << "\n";
		
		if(a3.getMoney() < money)
		{
			cout << "Error : Not enough money..." << endl;
			cout << "\n";
		}
		else
		{
			int m = a3.getMoney() - money;
			a3.setMoney(m);
		}
	}
	else if(id == 3)
	{
		cout << "Try to withdraw " << money << " from USER" << a4.getId() << " ... " << endl;
		cout << "\n";
		
		if(a4.getMoney() < money)
		{
			cout << "Error : Not enough money..." << endl;
			cout << "\n";
		}
		else
		{
			int m = a4.getMoney() - money;
			a4.setMoney(m);
		}
	}
	else if(id == 4)
	{
		cout << "Try to withdraw " << money << " from USER" << a5.getId() << " ... " << endl;
		cout << "\n";
		
		if(a5.getMoney() < money)
		{
			cout << "Error : Not enough money..." << endl;
			cout << "\n";
		}
		else
		{
			int m = a5.getMoney() - money;
			a5.setMoney(m);
		}
	}
	else
	{
		cout << "Error : No exist user ..." << endl;
		cout << "\n";
	}
}

void Bank::printInfo(int n)
{
	if(n == 1)
	{
		cout << " ######## Bank User Info ######## " << endl;
		cout << "User : " << a1.getId() << "\tName : " << a1.getName() << "\tMoney : " << a1.getMoney() << endl;
		cout << "\n";
	}
	else if(n==2)
	{
		cout << " ######## Bank User Info ######## " << endl;
		cout << "User : " << a1.getId() << "\tName : " << a1.getName() << "\tMoney : " << a1.getMoney() << endl;
		cout << "User : " << a2.getId() << "\tName : " << a2.getName() << "\tMoney : " << a2.getMoney() << endl;
		cout << "\n";
	}
	else if(n==3)
	{
		cout << " ######## Bank User Info ######## " << endl;
		cout << "User : " << a1.getId() << "\tName : " << a1.getName() << "\tMoney : " << a1.getMoney() << endl;
		cout << "User : " << a2.getId() << "\tName : " << a2.getName() << "\tMoney : " << a2.getMoney() << endl;
		cout << "User : " << a3.getId() << "\tName : " << a3.getName() << "\tMoney : " << a3.getMoney() << endl;
		cout << "\n";
	}
	else if(n==4)
	{
		cout << " ######## Bank User Info ######## " << endl;
		cout << "User : " << a1.getId() << "\tName : " << a1.getName() << "\tMoney : " << a1.getMoney() << endl;
		cout << "User : " << a2.getId() << "\tName : " << a2.getName() << "\tMoney : " << a2.getMoney() << endl;
		cout << "User : " << a3.getId() << "\tName : " << a3.getName() << "\tMoney : " << a3.getMoney() << endl;
		cout << "User : " << a4.getId() << "\tName : " << a4.getName() << "\tMoney : " << a4.getMoney() << endl;
		cout << "\n";
	}
	else if(n==5)
	{
		cout << " ######## Bank User Info ######## " << endl;
		cout << "User : " << a1.getId() << "\tName : " << a1.getName() << "\tMoney : " << a1.getMoney() << endl;
		cout << "User : " << a2.getId() << "\tName : " << a2.getName() << "\tMoney : " << a2.getMoney() << endl;
		cout << "User : " << a3.getId() << "\tName : " << a3.getName() << "\tMoney : " << a3.getMoney() << endl;
		cout << "User : " << a4.getId() << "\tName : " << a4.getName() << "\tMoney : " << a4.getMoney() << endl;
		cout << "User : " << a5.getId() << "\tName : " << a5.getName() << "\tMoney : " << a5.getMoney() << endl;
		cout << "\n";
	}
}

int main()
{
	int count = 0;
	Bank b;
	
	while(true)
	{
		int choice = 0;
		cout << "0. Create Account | 1. Deposit | 2. Withdraw | 3. Send | 4. Exit" << endl;
		cout << "Enter Command : ";
		cin >> choice;
		cout << "\n";
		
		switch(choice)
		{
			case 0:
				{
					if(count >= 5)
					{	
						cout << "Error : Max user..." << endl;
						cout << "\n";
						b.printInfo(count);
						break;
					}
					else
					{
						string name;
						cout << "Enter user name : ";
						cin >> name;
						cout << "\n";
						b.createAccount(count, name);
						count++;
						b.printInfo(count);
						break;
					}
					
				}
			
			case 1:
				{
					int id;
					int money;
					cout << "Enter User idx : ";
					cin >> id;
					cout << "Enter money : ";
					cin >> money;
					cout << "\n";
					if( id >= count)
					{
						cout << "Error : No exist user ..." << endl;
						cout << "\n";
					}
					else
					{
						b.depositMoney(id, money);
					}
					b.printInfo(count);
					break;
				}			
			
			case 2:
				{
					int id;
					int money;
					cout << "Enter User idx : ";
					cin >> id;
					cout << "Enter money : ";
					cin >> money;
					cout << "\n";
					if(id >= count)
					{
						cout << "Error : No exist user ..." << endl;
						cout << "\n";
					}
					else
					{
						b.withdrawMoney(id, money);
					}
					b.printInfo(count);
					break;
				}			
			
			case 3:
				{
					int id1;
					int id2;
					int money;
					cout << "Enter User idx (From): ";
					cin >> id1;
					cout << "Enter User idx (To): ";
					cin >> id2;
					cout << "Enter money : ";
					cin >> money;
					cout << "\n";
					if(id1 >= count || id2 >= count)
					{
						cout << "Error : No exist user ..." << endl;
						cout << "\n";
					}
					else
					{
						b.sendMoney(id1, id2, money);
					}
					b.printInfo(count);
					break;
				}			
			
			case 4:
				{
					b.printInfo(count);
					return 0;
				}
				
			default:
				{
					cout << "Command Error!" << endl;
					cout << "\n";
					b.printInfo(count);
					break;
				}							
		}
	}
}
