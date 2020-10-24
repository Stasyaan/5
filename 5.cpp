#include <iostream>
#include <string>
#include <regex>

class  house {
public:
	house() {};
	virtual ~house() {};
	house(int _w, int _d, int _h) {
		w = _w;
		d = _d;
		h = _h;
	}
	virtual void print()=0 {
		std::cout << "Width: " << w << " m\n";
		std::cout << "Depth: " << d << " m\n";
		std::cout << "Height: " << h << " m\n";
	}
	virtual void doSomething() {
	}
protected:
	int w;
	int d;
	int h;
};

class blockOfFlats :virtual public  house {
public:
	blockOfFlats() {};
	~blockOfFlats() {};
	blockOfFlats(int _residents, int _w, int _d, int _h) :house(_w, _d, _h) {
		residents = _residents;
	}
	void print() {
		std::cout << "Count of residents: " << residents << "\n";
	}
	void doSomething() {
		std::cout << "Add 100 mexicans" << "\n";
		residents += 100;
	}
protected:
	int residents;
};

class flat :public blockOfFlats {
public:
	flat() {};
	~flat() {};
	flat(int _sqare, int _residents, int _w, int _d, int _h) :blockOfFlats(_residents, _w, _d, _h) {
		sqare = _sqare;
	}
	void print(){
		std::cout << "Sqare: " << sqare << " m^2\n";
	}
	void doSomething() {
		std::cout << "Add 100 sqare meters" << "\n";
		sqare += 100;
	}
protected:
	int sqare;
};

class semiDetached :virtual public house {
public:
	semiDetached() {}
	~semiDetached() {}
	semiDetached(std::string _adress, int _w, int _d, int _h) :house(_w, _d, _h) {
		adress = _adress;
	}
	void print() {
		std::cout << "Address: \"" << adress << "\"\n";
	}
	void doSomething() {
		std::cout << "New address" << "\n";
		adress += " Stas was here";
	}
protected:
	std::string adress;
};


int main() {

	house** Q = new house *[3];
	int S, R, W, w, d, h;
	std::string A, N;
		Q[0] = new blockOfFlats(200, 1, 1, 2);
		Q[1] = new flat(2, 200, 1, 1, 2);
		Q[2] = new semiDetached("Alexander platz 12/1", 1, 1, 2);
		for (int i = 0; i < 3; i++)
			Q[i]->print();

		for (int i = 0; i < 3; i++)
			Q[i]->doSomething();

		for (int i = 0; i < 3; i++)
			Q[i]->print();

		for (int i = 0; i < 3; i++)
			delete Q[i];


}
