#include "Workers.h"
#include <fstream>
#include <iostream>

using namespace std;

//Worker implementation

Worker::Worker() :mFirstName("Undefined"), mLastName("Undefined"), mSalary(0)
{
}

Worker::Worker(string firstName, string lastName, int salary): mFirstName(firstName), mLastName(lastName), mSalary(salary)
{	
}

//Manager implementation

Manager::Manager(string firstName, string lastName, int salary, int meetings, int vocations) : Worker(firstName, lastName, salary), mMeetings(meetings), mVocations(vocations), mType(Types::manager)
{}

void Manager::Print()
{
	cout << "Type: Manager" << endl;
	cout << "Name: " << mFirstName << " " << mLastName << endl;
	cout << "Salary: " << mSalary << endl;
	cout << "Meetings per week: " << mMeetings << endl;
	cout << "Vocations per year: " << mVocations << endl;
	cout << endl;
}

void Manager::Save()
{
	ofstream outFile;
	outFile.open("workers.txt", std::ios_base::app);
	outFile << "Type: Manager" << endl;
	outFile << "Name: " << mFirstName << " " << mLastName << endl;
	outFile << "Salary: " << mSalary << endl;
	outFile << "Meetings per weeks: " << mMeetings << endl;
	outFile << "Vocations per year : " << mVocations << endl;
	outFile << endl;
	outFile.close();
}
//Engineer implementation

Engineer::Engineer(string firstName, string lastName, int salary, bool cpp, float expirience) : Worker(firstName, lastName, salary), mCpp(cpp), mExpirience(expirience), mType(Types::engineer)
{}
	
void Engineer::Print()
{
	cout << "Type: Manager" << endl;
	cout << "Name: " << mFirstName << " " << mLastName << endl;
	cout << "Salary: " << mSalary << endl;
	if (mCpp)
		cout << "C++ knowledge: Yes" << endl;
	else
		cout << "C++ knowledge : No" << endl;
	cout << "Years of expirience: " << mExpirience << endl;
}

void Engineer::Save()
{
	ofstream outFile;
	outFile.open("workers.txt", std::ios_base::app);
	outFile << "Type: Engineer" << endl;
	outFile << "Name: " << mFirstName << " " << mLastName << endl;
	outFile << "Salary: " << mSalary << endl;
	if (mCpp)
		outFile << "C++ knowledge: Yes" << endl;
	else
		outFile << "C++ knowledge : No" << endl;
	outFile << "Expirience: " << mExpirience << endl;
	outFile << endl;
	outFile.close();
}

//Researcher implementation

Researcher::Researcher(string firstName, string lastName, int salary, string school, string topic) : Worker(firstName, lastName, salary), mSchool(school), mTopic(topic), mType(Types::researcher)
{}

void Researcher::Print()
{
	cout << "Type: Manager" << endl;
	cout << "Name: " << mFirstName << " " << mLastName << endl;
	cout << "Salary: " << mSalary << endl;
	cout << "School of PhD: " << mSchool << endl;
	cout << "PhD topic: " << mTopic << endl;
	cout << endl;
}

void Researcher::Save()
{
	ofstream outFile;
	outFile.open("workers.txt", std::ios_base::app);
	outFile << "Type: Researcher" << endl;
	outFile << "Name: " << mFirstName << " " << mLastName << endl;
	outFile << "Salary: " << mSalary << endl;
	outFile << "School: " << mSchool << endl;
	outFile << "PhD topic: " << mTopic << endl;
	outFile << endl;

	something new here
}
