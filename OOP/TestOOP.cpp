#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
	string name;
	int age;
	string number;

public:
	Person() {
		name = "";
		age = 0;
		number = "";
	}
	Person(string name, int age, string number) {
		name = name;
		age = age;
		number = number;
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}

	string getNumber() {
		return number;
	}

	virtual void DoingSth();
};

class Student :public Person {
private:
	int StudentID;
public:
	Student() {
		name = "";
		age = 0;
		number = "";
		StudentID = 0;
	}

	Student(string name, int age, string number, int StudentID) {
		this->name = name;
		this->age = age;
		this->number = number;
		this->StudentID = StudentID;
	}

	virtual void DoingSth() override{
		cout << "Study" << endl;
	}
};

class Engineer : public Person {
private:
	int EngID;
public:
	Engineer() {
		name = "";
		age = 0;
		number = "";
		EngID = 0;
	}
	Engineer(string name, int age, string number, int EngID) {
		this->name = name;
		this->age = age;
		this->number = number;
		this->EngID = EngID;
	}

	virtual void DoingSth() override{
		cout << "Working" << endl;
	}
};

int main() {
	Person Phuc = Person("Hoang Phuc Anh", 31, "982EU823928" );
	Student Hue ("Hoang Kim Hue", 30, "38JOI23239", 12);
	Engineer Yen("Hoang Hai Yen", 25, "9482OIJ2323",32);

	cout << "Hoc sinh : " << Hue.getName()  << " len do" << endl;
	cout << "Tuoi : " << Hue.getAge() << " nghe lenh xuong tu tren bo" << endl;
	cout << "Number : " << Hue.getNumber() << " xam nhap duong day ma tuy. O can biet thu ben ho" << endl;
	Hue.DoingSth();

	cout << "Ki su : " << Yen.getName() << endl;
	cout << "Tuoi : " << Yen.getAge() << endl;
	cout << "Number : " << Yen.getNumber() << endl;
	Yen.DoingSth();

	return 0;
}

void Person::DoingSth()
{
}

