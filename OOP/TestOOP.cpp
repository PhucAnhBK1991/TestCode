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
	virtual ~Person() {
		cout << "Personal Destructor" << endl;
	}
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

	int getID() {
		return StudentID;
	}

	virtual void DoingSth() override{
		cout << "Study" << endl;
	}

	~Student() {
		cout << "Student Destructor" << endl;
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

	int getID() {
		return EngID;
	}

	virtual void DoingSth() override{
		cout << "Working" << endl;
	}

	~Engineer() {
		cout << "Engineer Destructor" << endl;
	}
};

int main() {
	Person *Phuc = new Student("Hoang Phuc Anh", 31, "982EU823928", 23);
	Student *Hue = new Student("Hoang Kim Hue", 30, "38JOI23239", 12);
	Engineer *Yen = new Engineer("Hoang Hai Yen", 25, "9482OIJ2323",32);
	cout << "Person : " << Phuc->getName() << endl;
	cout << "Tuoi : " << Phuc->getAge() << endl;
	cout << "Number : " << Phuc->getNumber() << endl;
	
	cout << "Hoc sinh : " << Hue->getName()  << " len do" << endl;
	cout << "Tuoi : " << Hue->getAge() << " nghe lenh xuong tu tren bo" << endl;
	cout << "Number : " << Hue->getNumber() << " xam nhap duong day ma tuy. O can biet thu ben ho" << endl;
	cout << "ID : " << Hue->getID() << endl;
	Hue->DoingSth();

	cout << "Ki su : " << Yen->getName() << endl;
	cout << "Tuoi : " << Yen->getAge() << endl;
	cout << "Number : " << Yen->getNumber() << endl;
	cout << "ID : " << Yen->getID() << endl;
	Yen->DoingSth();

	cout << "Delete Phuc" << endl;
	delete Phuc;
	cout << "Delete Hue" << endl;
	delete Hue;
	cout << "Delete Yen" << endl;
	delete Yen;

	return 0;
}

void Person::DoingSth()
{
}

