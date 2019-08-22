#include <iostream>
using namespace std;
struct node
{
	int id;
	char name[50];
	char qua[30];
	char addrs[50];
	char city[30];
	char jobtitle[30];
	int salary;
	char date[30];
	node *prev, *next;
};
class employ
{
private:
	node *head;
	char ch;
public:
	employ()
	{
		head = NULL;
	}

	void menu()
	{
		system("color A1");
		cout << "\n\t\t\t welcome to the Employee Record Management system" << endl;
		cout << "\n\t\t\t\t 1- Add a record:" << endl;
		cout << "\n\t\t\t\t 2- Search a record:" << endl;
		cout << "\n\t\t\t\t 3- Update a record:" << endl;
		cout << "\n\t\t\t\t 4- delete a record:" << endl;
		cout << "\n\t\t\t\t 5- Display a record:" << endl;
		cout << "\n\t\t\t\t 0- Exit:" << endl;
		return;
	}
	void add_first()
	{
		system("color A4");
		node *newer = new node;
		cout << "\n\t\t Enter the employee id:";
		cin >> newer->id;
		fflush(stdin);
		cout << "\n\t\t Enter the full name of employee:";
		cin.getline(newer->name, 50);
		fflush(stdin);
		cout << "\n\t\t Enter the qualification of employee:";
		cin.getline(newer->qua, 30);
		fflush(stdin);
		cout << "\n\t\t Enter the address:";
		cin.getline(newer->addrs, 50);
		fflush(stdin);
		cout << "\n\t\t enter the city:";
		cin.getline(newer->city, 30);
		fflush(stdin);
		cout << "\n\t\t Enter the job title:";
		cin.getline(newer->jobtitle, 30);
		fflush(stdin);
		cout << "\n\t\t Enter the salary:";
		cin >> newer->salary;
		fflush(stdin);
		cout << "\n\t\t Enter the start date:";
		cin.getline(newer->date, 30);
		fflush(stdin);
		newer->next = head;
		newer->prev = NULL;
		if (head != NULL)
		{
			head->prev = newer;
		}
		head = newer;
		cout << "\n\t \t Record inserted successfully:" << endl;
	}
	void add_last()
	{
		if (head == NULL)
		{
			cout << "\n \t\t Link is empty:" << endl;
			cout << "\n \t \t Add a new record \n\t Press Y or N:";
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				add_first();
				return;
			}
			else
			{
				exit(1);
			}

		}
		else
		{
			node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			node *newer = new node;
			fflush(stdin);
			cout << "\n\t\t Enter the employee id:";
			cin >> newer->id;
			fflush(stdin);

			cout << "\n\t\t Enter the full name of employee:";
			cin.getline(newer->name, 50);
			fflush(stdin);

			cout << "\n\t\t enter the qualification of employee:";
			cin.getline(newer->qua, 50);
			fflush(stdin);
			cout << "\n\t\t Enter the address:";
			cin.getline(newer->addrs, 50);
			fflush(stdin);
			cout << "\n\t\t Enter the city:";
			cin.getline(newer->city, 50);
			fflush(stdin);
			cout << "\n\t\t Enter the job title:";
			cin.getline(newer->jobtitle, 50);
			fflush(stdin);
			cout << "\n\t\t Enter the salary:";
			cin >> newer->salary;
			fflush(stdin);
			cout << "\n\t\t Enter the start date:";
			cin.getline(newer->date, 30);
			fflush(stdin);
			newer->next = NULL;
			temp->next = newer;
			newer->prev = temp;
		}
	}
	void add_after()
	{
		if (head == NULL)
		{
			cout << "\n\t\t List is empty:" << endl;
			cout << "\n\t\t Add a new record \n\t Press y or n:";
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				add_first();
				return;
			}
			else
			{
				exit(1);
			}
		}
		else
		{
			int val;
			cout << "\n\t\t Enter the id after which you want to add a new record:";
			cin >> val;
			bool flag = false;
			node *temp = head;
			node*p;
			while (temp != NULL)
			{
				if (temp->id == val)
				{
					node*newer = new node;
					fflush(stdin);
					cout << "\n\t\t Enter the employee id:";
					cin >> newer->id;
					fflush(stdin);

					cout << "\n\t\t Enter the full name of employee:";
					cin.getline(newer->name, 50);
					fflush(stdin);

					cout << "\n\t\t enter the qualification of employee:";
					cin.getline(newer->qua, 50);
					fflush(stdin);
					cout << "\n\t\t Enter the address:";
					cin.getline(newer->addrs, 50);
					fflush(stdin);
					cout << "\n\t\t Enter the city:";
					cin.getline(newer->city, 50);
					fflush(stdin);
					cout << "\n\t\t Enter the job title:";
					cin.getline(newer->jobtitle, 50);
					fflush(stdin);
					cout << "\n\t\t Enter the salary:";
					cin >> newer->salary;
					fflush(stdin);
					cout << "\n\t\t Enter the start date:";
					cin.getline(newer->date, 30);
					fflush(stdin);
					if (temp->next != NULL)
					{
						newer->next = temp->next;
						newer->prev = temp;
						p = temp->next;
						p->prev = newer;
						temp->next = newer;
					}
					else
					{
						newer->next = temp->next;
						newer->prev = temp;
						temp->next = newer;
					}
					flag = true;
				}
				temp = temp->next;
			}
			if (flag == false)
			{
				cout << "\n\t\t id not found" << endl;
			}
		}
	}
	void add_before()
	{
		if (head == NULL)
		{
			cout << "\n\t\t List is empty:" << endl;
			cout << "\n\t\t Add a new record\n\t Press Y or N:";
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				add_first();
				return;
			}
			else
			{
				exit(1);
			}
		}
		else
		{
			int val;
			cout << "\n\t\t Enter the id beofre which you want to add a new record:" << endl;
			cin >> val;
			bool flag = false;
			node *temp = head;
			if (temp->id = val)
			{
				add_first();
				return;
			}
			else
			{
				while (temp != NULL)
				{
					if (temp->id == val)
					{
						node*newer = new node;
						fflush(stdin);
						cout << "\n\t\t Enter the employee id:";
						cin >> newer->id;
						fflush(stdin);

						cout << "\n\t\t Enter the full name of employee:";
						cin.getline(newer->name, 50);
						fflush(stdin);

						cout << "\n\t\t enter the qualification of employee:";
						cin.getline(newer->qua, 50);
						fflush(stdin);
						cout << "\n\t\t Enter the address:";
						cin.getline(newer->addrs, 50);
						fflush(stdin);
						cout << "\n\t\t Enter the city:";
						cin.getline(newer->city, 50);
						fflush(stdin);
						cout << "\n\t\t Enter the job title:";
						cin.getline(newer->jobtitle, 50);
						fflush(stdin);
						cout << "\n\t\t Enter the salary:";
						cin >> newer->salary;
						fflush(stdin);
						cout << "\n\t\t Enter the start date:";
						cin.getline(newer->date, 30);
						fflush(stdin);
						newer->next = temp;
						newer->prev = temp;
						node*p;
						p = temp->prev;
						p->next = newer;
						temp->prev = newer;
						flag = true;
					}
					temp = temp->next;
				}
				if (flag == false)
				{
					cout << "\n\t\t record is not found:" << endl;
				}
			}
		}
	}

	void del()

	{
		if (head == NULL)
		{
			cout << "\n\t\t List is empty:" << endl;
			cout << "\n\t\t add a new record\n\t Press Y to proceed or N to exit:";
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				add_first();
				return;
			}
			else
			{
				exit(1);
			}
		}
		else
		{
			int val;
			cout << "\n\t\t Enter the employee id which do you want to delete a record:";
			cin >> val;
			node*temp = head;
			bool flag = false;
			if (temp->id == val)
			{
				head = temp->next;
				head->prev = NULL;
				flag = true;
				delete temp;
				if (flag == true)
				{
					cout << "Record has been deleted successfully" << endl;
				}
			}
			else
			{
				while (temp != NULL)
				{
					if (temp->id == val)
					{
						node *p, *q;
						if (temp->next == NULL)
						{
							p = temp->prev;
							p->next = NULL;
							flag = true;
							delete temp;
						}


						else
						{
							p = temp->prev;
							q = temp->next;
							p->next = q;
							q->prev = p;
							flag = true;
							delete temp;
						}
					}
					temp = temp->next;
				}
				if (flag == false)
				{
					cout << "\n\t Value is not found:" << endl;
				}
			}
		}
	}
	void show()
	{
		if (head == NULL)
		{
			cout << "\n\t\t List is empty:" << endl;
			cout << "\n\t\t Add a new record \n\t Press Y to proceed or N to exit:";
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				add_first();
				return;
			}
			else
			{
				exit(1);
			}
		}
		else
		{
			node*temp = head;
			while (temp != NULL)
			{
				cout << "\n\t\t Information of employee:" << endl;
				cout << "\n\t\t ID:" << "\t\t\t" << temp->id << endl;
				cout << "\n\t\t name:" << "\t\t\t" << temp->name << endl;
				cout << "\n\t\t Qualification:" << "\t\t" << temp->qua << endl;
				cout << "\n\t\t Address:" << "\t\t" << temp->addrs << endl;
				cout << "\n\t\t city:" << "\t\t\t" << temp->city << endl;
				cout << "\n\t\t job title:""\t\t" << temp->jobtitle << endl;
				cout << "\n\t\t salary:" << "\t\t" << temp->salary << endl;
				cout << "\n\t\t starting date:" << "\t\t" << temp->date << endl;
				cout << "_______________________________________________________" << endl;
				temp = temp->next;
			}

		}
	}
	void search()
	{
		if (head == NULL)
		{
			cout << "\n\t\t List is empty:" << endl;
			cout << "\n\t\t Add a new record \n\t Press Y to proceed or N to exit:";
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				add_first();
				return;
			}
			else
			{
				exit(1);
			}
		}
		else
		{
			int val;
			cout << "\n\t\t Enter employee id which you want to search:";
			cin >> val;
			node *temp = head;
			bool flag = false;
			while (temp != NULL)
			{

				if (temp->id == val)
				{
					cout << "\n\t\t Information of employee:" << endl;
					cout << "\n\t\t ID:" << "\t\t\t" << temp->id << endl;
					cout << "\n\t\t name:" << "\t\t\t" << temp->name << endl;
					cout << "\n\t\t Qualification:" << "\t\t" << temp->qua << endl;
					cout << "\n\t\t Address:" << "\t\t" << temp->addrs << endl;
					cout << "\n\t\t city:" << "\t\t\t" << temp->city << endl;
					cout << "\n\t\t job title:""\t\t" << temp->jobtitle << endl;
					cout << "\n\t\t salary:" << "\t\t" << temp->salary << endl;
					cout << "\n\t\t starting date:" << "\t\t" << temp->date << endl;
					cout << "_______________________________________________________" << endl;
					return;

				}
				temp = temp->next;
			}
		}

	}
	void update()
	{
		if (head == NULL)
		{
			cout << "\n\t\t List is empty" << endl;
			cout << "\n\t\t Add a new record \n\t Press Y to proceed or N to exit:" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				add_first();
				return;
			}
			else
			{
				exit(1);
			}
		}
		else
		{
			int val;
			cout << "\n\t\t enter the emplyee id whose record you want to update:";
			cin >> val;
			node*temp = head;
			node *newer = new node;
			while (temp != NULL)
			{
				if (temp->id == val)
				{
					fflush(stdin);
					cout << "\n\t\t Enter the employee id:";
					cin >> newer->id;
					fflush(stdin);

					cout << "\n\t\t Enter the full name of employee:";
					cin.getline(newer->name, 50);
					fflush(stdin);

					cout << "\n\t\t enter the qualification of employee:";
					cin.getline(newer->qua, 50);
					fflush(stdin);
					cout << "\n\t\t Enter the address:";
					cin.getline(newer->addrs, 50);
					fflush(stdin);
					cout << "\n\t\t Enter the city:";
					cin.getline(newer->city, 50);
					fflush(stdin);
					cout << "\n\t\t Enter the job title:";
					cin.getline(newer->jobtitle, 50);
					fflush(stdin);
					cout << "\n\t\t Enter the salary:";
					cin >> newer->salary;
					fflush(stdin);
					cout << "\n\t\t Enter the start date:";
					cin.getline(newer->date, 30);
					fflush(stdin);
				}
				temp = temp->next;
			}
			cout << "Record has been updated successfully" << endl;
		}
	}
};

int main()
{
	int n;
	char ch;
	employ en;
Label2:
	en.menu();
	cout << "\n\t\t\t Enter your choice:";
	cin >> n;
	if (n == 1)
	{
	Label1:
		system("color A1");
		cout << "_______________________________________" << endl;
		cout << "\n\t\t Where you want to add record? " << endl;
		cout << "\t\t\t" << endl;
		cout << "\n\t\t 1- insert at very first place " << endl;
		cout << "\n\t\t 2- insert at very last place " << endl;
		cout << "\n\t\t 3- insert after recently added record(pointer pointing at this) " << endl;
		cout << "\n\t\t 4- insert before record " << endl;
		cout << "\n\t\t Enter Choice? " << endl;
		cin >> n;
		if (n == 1)
		{
			en.add_first();
			cout << "\n\t\t do you want to go to main menu?" << endl;
			cin >> ch;
			fflush(stdin);
			if (ch == 'Y' || ch == 'y')
			{
				goto Label2;
			}
			else
			{
				exit(1);
			}
		}
		else if (n == 2)
		{
			en.add_last();
			cout << "\n\t\t do you want to go to main menu:" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				goto Label2;
			}
			else
			{
				exit(1);
			}
		}
		else if (n == 3)
		{
			en.add_after();
			cout << "\n\t\t do you want to go to main menu:" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				goto Label2;
			}
			else
			{
				exit(1);
			}
		}
		else  if (n == 4)
		{
			en.add_before();
			cout << "\n\t\t Do you want to go to main menu?" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				goto Label2;
			}
			else
			{
				exit(1);
			}
		}
		else
		{
			cout << "\n\t\t Choose Correct Answer:" << endl;
			goto Label1;
		}
	}

	else if (n == 2)
	{
		en.search();
		cout << "\n\t\t Do you want to go to main menu:" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			goto Label2;
		}
		else
		{
			exit(1);
		}

	}
	else if (n == 3)
	{
		en.update();
		cout << "\n\t\t Do you want to go to main menu:" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			goto Label2;
		}
		else
		{
			exit(1);
		}
	}
	else if (n == 4)
	{
		en.del();
		cout << "\n\t\t Do you want to go to main menu" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			goto Label2;
		}
		else
		{
			exit(0);
		}
	}
	else if (n == 5)
	{
		en.show();
		cout << "\n\t\t Do you want to go to main menu" << endl;
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			goto Label2;
		}
		else
		{
			exit(1);
		}
	}
	else if (n == 6)
	{
		exit(1);
	}
	else
	{
		cout << "\n\t\t Choose correct answer" << endl;
		goto Label2;
	}
	system("pause");
}





























