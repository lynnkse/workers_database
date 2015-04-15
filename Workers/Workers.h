#ifndef WORKERS_H
#define WORKERS_H

#include<string>

using namespace std;

enum class Types {manager, engineer, researcher};

class Worker
{
public:
	//constructors
	Worker();
	Worker(string firstName, string lastName, int salary);

	virtual void Print() = 0;
	
	void Save();
	
	protected:
	string mFirstName;
	string mLastName;
	int mSalary;
};

class Manager: public Worker
{
public:
	Manager(string firstName, string lastName, int salary, int meetings, int vocations);

	void Print();
protected:
	int mMeetings;
	int mVocations;
	Types mType;
};

class Engineer: public Worker
{
public:
	Engineer(string firstName, string lastName, int salary, bool cpp, float expirience);
	void Print();
protected:
	bool mCpp;
	float mExpirience;
	Types mType;
};

class Researcher : public Worker
{
public:
	Researcher(string firstName, string lastName, int salary, string school, string topic);
	void Print();
protected:
	string mSchool;
	string mTopic;
	Types mType;
};

#endif

