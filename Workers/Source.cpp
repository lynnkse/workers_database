#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Workers.h"

int main()
{
	std::cout << "===== WORKERS DATABASE MANAGER =====" << endl;
	std::cout << "====================================" << endl;
	std::cout << endl << endl << endl;
	std::vector<Worker*> workers;
	std::string firstName;
	std::string lastName;
	int salary;
	while (true)
	{
		std::cout << "1) Add an Employee, 2) Delete an Employee 3) Save Database, 4) Load Database 5) Exit" << endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1://add
		{
				   std::cout << "1) Add a Manager, 2) Add an Engineer, 3)Add a Researcher" << endl;
				   std::cin >> choice;
				   switch (choice)
				   {
				   case 1://manager
					   std::cout << "Enter first name: " << endl;
					   std::cin >> firstName;
					   std::cout << "Enter last name:" << endl;
					   std::cin >> lastName;
					   std::cout << "Enter salary:" << endl;
					   std::cin >> salary;
					   int meetings;
					   int vocations;
					   std::cout << "Number of meetings per week:" << endl;
					   std::cin >> meetings;
					   std::cout << "Number of vocations per year: " << endl;
					   std::cin >> vocations;
					   workers.push_back(new Manager(firstName, lastName, salary, meetings, vocations));
					   break;
				   case 2://engineer
					   std::cout << "Enter first name: " << endl;
					   std::cin >> firstName;
					   std::cout << "Enter last name:" << endl;
					   std::cin >> lastName;
					   std::cout << "Enter salary:" << endl;
					   std::cin >> salary;
					   int cpp;
					   bool bcpp;
					   float expirience;
					   std::cout << "Knowledge of C++: 1) Yes, 2) No" << endl;
					   std::cin >> cpp;
					   if (cpp == 1)
						   bcpp = true;
					   else
						   bcpp = false;
					   std::cout << "Years of expirience: " << endl;
					   std::cin >> expirience;
					   workers.push_back(new Engineer(firstName, lastName, salary, bcpp, expirience));
					   break;
				   case 3://researcher
					   std::cout << "Enter first name: " << endl;
					   std::cin >> firstName;
					   std::cout << "Enter last name:" << endl;
					   std::cin >> lastName;
					   std::cout << "Enter salary:" << endl;
					   std::cin >> salary;
					   std::string school;
					   std::string topic;
					   std::cout << "School of PhD: " << endl;
					   std::cin >> school;
					   std::cout << "Topic of PhD: " << endl;
					   std::cin >> topic;
					   workers.push_back(new Researcher(firstName, lastName, salary, school, topic));
					   break;
				   }
				   break;
		}
		case 2://delete
		{
				   for (int i = 0, n = workers.size(); i < n; i++) //prints them all out
				   {
					   cout << "No. " << i + 1 << ":" << endl;
					   workers[i]->Print();
				   }
				   cout << "Enter number of worker you wish to delete: " << endl;
				   int k;
				   cin >> k;
				   workers.erase(workers.begin() + k - 1);
				   break;
		case 3://save
			for (int i = 0, n = workers.size(); i < n; i++)
			{
				workers[i]->Save();
				//for debugging
				cout << "Sizeof(workers) = " << sizeof(*workers[i]) << endl;
			}
			break;
		}
		case 4://load 
		{
				   workers.clear();
				   ifstream inFile;
				   inFile.open("workers.txt", std::ios_base::binary | std::ios_base::in);
				   if (inFile)
				   {
					   int obj_size = 0;
					   int k = 0;
					   Worker* buffer = new Manager("a", "b", 1, 1, 1);
					   inFile.read((char*)&obj_size, sizeof(int));
					   while (obj_size)
					   {
						   inFile.read((char*)buffer, obj_size);
						   workers.push_back(buffer);
						   k++;
						   obj_size = 0;
						   inFile.read((char*)&obj_size, sizeof(int));
					   }
				   }
				   inFile.close();
				   break;
		}
		case 5://exit
		{
				   return 0;
				   break;
		}
		}
	}
}

	



	