#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Note
{
	std::string firm;
	std::string owner;
	std::string phonenumber;
	std::string address;
	std::string activity;

public:

	Note(std::string _firm, std::string _owner, std::string _phonenumber, std::string _address, std::string _activity)
		: firm{ _firm }, owner{ _owner }, phonenumber{ _phonenumber }, address{ _address }, activity{ _activity } {}

	std::string Firm() { return firm; }
	std::string Owner() { return owner; }
	std::string Phonenumber() { return phonenumber; }
	std::string Address() { return address; }
	std::string Activity() { return activity; }

	void printNote()
	{
		std::cout << firm << " " << owner << " " << phonenumber << " " << address << " " << activity << "\n";
	}
};

class Catalog
{
	std::vector<Note>catalog;
public:
	Catalog()
	{
		std::ifstream file("file.txt");
		std::string str;
		char* firm = new char[20];
		char* owner = new char[20];
		char* phone = new char[20];
		char* addr = new char[20];
		char* act = new char[20];

		while (!file.eof())
		{
			getline(file, str);
			if (str == "") continue;
			sscanf_s(str.data(), "%s %s %s %s %s", firm, 10, owner, 10, phone, 10, addr, 10, act, 10);
			catalog.push_back(Note(firm, owner, phone, addr, act));
		}
		file.close();
		delete[]firm;
		delete[]owner;
		delete[]phone;
		delete[]addr;
		delete[]act;
	}
	void addNote(Note temp) 
	{
		std::fstream file("file.txt", std::ios_base::app);
		file << temp.Firm() << " " << temp.Owner() << " " << temp.Phonenumber() << " " << temp.Address() << " " << temp.Activity() << "\n";
		file.close();
		catalog.push_back(temp); 
	}

	void findFirm(std::string temp)
	{
		for (auto item : catalog)
			if (item.Firm() == temp)
				item.printNote();
		std::cout << std::endl;
	}

	void findOwner(std::string temp)
	{
		for (auto item : catalog)
			if (item.Owner() == temp)
				item.printNote();
		std::cout << std::endl;
	}
	void findPhone(std::string temp)
	{
		for (auto item : catalog)
			if (item.Phonenumber() == temp)
				item.printNote();
		std::cout << std::endl;
	}

	void findAddress(std::string temp)
	{
		for (auto item : catalog)
			if (item.Address() == temp)
				item.printNote();
		std::cout << std::endl;
	}

	void findActivity(std::string temp)
	{
		for (auto item : catalog)
			if (item.Activity() == temp)
				item.printNote();
		std::cout << std::endl;
	}

	void print()
	{
		for (auto item : catalog)
			item.printNote();
		std::cout << std::endl;
	}
};

int main()
{
	Catalog catalog;
	catalog.findActivity("activity1");
	catalog.print();

	return 0;
}