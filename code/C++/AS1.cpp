#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACTS = 100;

bool isValidEmail(const string &email) {
    bool hasAt = false, hasDot = false;

    for (size_t i = 0; i < email.length(); i++) 
	{
        if (email[i] == '@') hasAt = true;
        if (hasAt && email[i] == '.') hasDot = true; // '.' 必须在 '@' 后面
    }

    return hasAt && hasDot;
}

bool isValidName(const string &name) {
    for (size_t i = 0; i < name.length(); i++) 
	{
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z'))) 
		{
            return false;
        }
    }
    return true;
}

bool isValidPhoneNumber(const string &phone) {
    if (phone.length() != 10)
    {
    	return false;
	}
    for (size_t i = 0; i < phone.length(); i++) 
	{
        if (phone[i] < '0' || phone[i] > '9') return false;
    }
    return true;
}

void addContact(string names[], string phones[], string emails[], int &count) {
    if (count >= MAX_CONTACTS) 
	{
        cout << "Contact list is full!\n";
        return;
    }

    string name, phone, email;

    // 输入并验证名字
    do {
        cout << "Enter name: ";
        cin >> name;
        if (!isValidName(name)) 
		{
            cout << "Invalid input. Names should only contain alphabetic characters.\n";
        } 
		else 
		{
            break;
        }
    } while (true);

    // 输入并验证电话号码
    do {
        cout << "Enter phone number: ";
        cin >> phone;
        if (!isValidPhoneNumber(phone)) 
		{
            cout << "Invalid input. The phone number should contain exactly 10 digits.\n";
        } else 
		{
            break;
        }
    } while (true);

    // 输入并验证邮箱
    do {
        cout << "Enter email: ";
        cin >> email;
        if (!isValidEmail(email)) 
		{
            cout << "Invalid input. The email address should contain @ and .\n";
        } 
		else 
		{
            break;
        }
    } while (true);

    names[count] = name;
    phones[count] = phone;
    emails[count] = email;
    count++;

    cout << "Contact added successfully!\n";
}

void deleteContact(string names[], string phones[], string emails[], int &count) {
    if (count == 0) 
	{
        cout << "No contacts to delete.\n";
        return;
    }

    string nameToDelete;
    cout << "Enter the name of the contact to delete: ";
    cin >> nameToDelete;

    for (int i = 0; i < count; i++) 
	{
        if (names[i] == nameToDelete) 
		{
            for (int j = i; j < count - 1; j++) 
			{
                names[j] = names[j + 1];
                phones[j] = phones[j + 1];
                emails[j] = emails[j + 1];
            }
            count--;
            cout << "Contact deleted successfully!\n";
            return;
        }
    }

    cout << "Contact not found.\n";
}

void searchContact(const string names[], const string phones[], const string emails[], int count) {
    if (count == 0) 
	{
        cout << "No contacts to search.\n";
        return;
    }

    string nameToSearch;
    cout << "Enter the name of the contact to search: ";
    cin >> nameToSearch;

    for (int i = 0; i < count; i++) 
	{
        if (names[i] == nameToSearch) 
		{
            cout << "Contact found:\n";
            cout << "Name: " << names[i] << "\n";
            cout << "Phone: " << phones[i] << "\n";
            cout << "Email: " << emails[i] << "\n";
            return;
        }
    }

    cout << "Contact not found.\n";
}

void displayAllContacts(const string names[], const string phones[], const string emails[], int count) {
    if (count == 0) 
	{
        cout << "No contacts to display.\n";
        return;
    }

    cout << "All Contacts:\n";
    for (int i = 0; i < count; i++) 
	{
        cout << "Name: " << names[i] << "\n";
        cout << "Phone: " << phones[i] << "\n";
        cout << "Email: " << emails[i] << "\n";
        cout << "---------------------------\n";
    }
}

int main() {
    string names[MAX_CONTACTS];
    string phones[MAX_CONTACTS];
    string emails[MAX_CONTACTS];
    int count = 0;
    int choice;

    do {
        cout << "Contact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Delete Contact\n";
        cout << "3. Search Contact\n";
        cout << "4. Display All Contacts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) 
		{
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) 
		{
            case 1:
                addContact(names, phones, emails, count);
                break;
            case 2:
                deleteContact(names, phones, emails, count);
                break;
            case 3:
                searchContact(names, phones, emails, count);
                break;
            case 4:
                displayAllContacts(names, phones, emails, count);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

