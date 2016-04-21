#include "Interface.h"

using namespace std;

Interface::Interface() {
}

void Interface::displayMenu() {
	int nOptions = 0;
	int option = 0;

	cout << "Welcome to RideSharing! Please choose a option." << endl;
	nOptions++;
	cout << "1-Insert new user." << endl;
	nOptions++;
	cout << "2-See all users." << endl;
	nOptions++;
	cout << "3-Exit." << endl;

	do {
		cin >> option;

		try {
			if (option < 1 || option > nOptions) {
				option = 0;
				throw IlegalOptionException();
			}
		} catch (IlegalOptionException &e) {
			cout << "Not a possible option. Please choose other." << endl;
		}
	} while (option == 0);

	if (option == 1)
		newUser();
	else if (option == 2)
		displayUsers();
	else if (option == 3)
		return;

	cout << endl;
}

void Interface::displayUsers() {

	if (users.size() == 0) {
		cout << "No users registered. Enter to main menu." << endl;
		string input;
		cin >> input;
		displayMenu();
	} else {
		for (unsigned int i = 0; i < users.size(); i++) {
			cout << users[i].getName() << endl;
			cout << "Age: " << users[i].getAge() << endl;
			cout << "Adress: ";
			users[i].printUserAdress();
			cout << endl;
		}
	}

	cout << "Press enter to go for main menu.";
	string inp;
	cin >> inp;

	displayMenu();
}

void Interface::newUser() {

	string name;
	int age, ID, i = 0;
	Node N;

	cout << "Name: ";
	cin >> name;

	cout << "Age: ";
	cin >> age;

	while (true) {
		if (i == 0) {
			cout << "What is the ID of your Adress: ";
			cin >> ID;
			i++;
		} else {
			cout << "ID invalid, new ID again:";
			cin >> ID;
		}

		//if()encontrou o respetivo node, procura o adress e faz break
	}

	users.push_back(User(name, age));
	displayMenu();
}

vector<User> Interface::getUsers() {
	vector<User> U;

	for (int i = 0; i < users.size(); i++) {
		U.push_back(users[i]);
	}
	return U;
}
