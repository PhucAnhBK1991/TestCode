#include <iostream>
#include <string>

using namespace std;

class SSinterface {
public:
	int SecurityNum() {};
	string SecurityMem() {};
	void setMem(string a) {};
	void setMem(int a) {};
	~SSinterface() {
		cout << "SSinterface Destructor" << endl;
	}
};

class SSDerived : SSinterface {
private:
	string Mem;
	int num;
public:
	SSDerived() {
		Mem = "";
		num = 0;
	}

	int SecurityNum() {
		return num;
	}

	string SecurityMem() {
		return Mem;
	}

	void setMem(string a) {
		Mem += a + "\n";
		num++;
	}

	void setMem(int a) {
		num += a;
	}
	void PrintMem();
	~SSDerived() {
		cout << "SSDerived Destructor" << endl;
	}
};

void SSDerived::PrintMem() {
	cout << "So luong thanh vien Security : " << num << endl;
	cout << "Cac thanh vien : " << Mem << endl;
}

int main() {
	SSDerived Secu;
	Secu.setMem("An");
	Secu.setMem("Dat");
	Secu.setMem("Phuc");
	Secu.setMem("Huyen");
	Secu.setMem(10);
	Secu.PrintMem();
	return 0;
}
