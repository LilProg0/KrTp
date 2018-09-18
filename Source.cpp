#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
using namespace std;

class Dog
{
	string _name;
	string _color;
	string _gender;
	string _dateOfBirth;
	string _size;
	string _keeperName;
	string _namePitomn;
	string _character;
	string _care;
	bool _abort;

	static bool checkExit(string s)
	{
		if (s == "/stop")
			return true;
		return false;
	}

	void putValByIndex(string val, int index)
	{
		void(Dog::*funcs[])(string) = {
			&Dog::SetName,
			&Dog::SetColor,
			&Dog::SetGender,
			&Dog::SetDAteOfBirth,
			&Dog::SetSize,
			&Dog::SetKeeperName,
			&Dog::SetNamePitomn,
			&Dog::SetCharacter,
			&Dog::SetCare
		};

		(this->*funcs[index])(val);
	}

	string msgs[9] = {
		"Введите кличку\n",
		"Введите цвет\n",
		"Введите пол\n",
		"Введите дату рождения\n",
		"Введите размер\n",
		"Введите имя владульца\n",
		"Введите имя питомника\n",
		"Введите характер\n",
		"Введите уход\n"
	};


public:
	Dog() {}
	Dog(bool fromConsole, int wtf)
	{
		if (fromConsole)
			ReadFromConsole();
	}

	virtual string GetClassName() { return "Dog"; }
	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

	string GetColor() { return _color; }
	void SetColor(string color) { _color = color; }

	string GetGender() { return _gender; }
	void SetGender(string gender) { _gender = gender; }

	string GetDateOfBirth() { return _dateOfBirth; }
	void SetDAteOfBirth(string dateOfBirth) { _dateOfBirth = dateOfBirth; }

	string GetSize() { return  _size; }
	void SetSize(string size) { _size = size; }

	string GetKeeperName() { return _keeperName; }
	void SetKeeperName(string keeperName) { _keeperName = keeperName; }

	string GetNamePitomn() { return _namePitomn; }
	void SetNamePitomn(string namePitomn) { _namePitomn = namePitomn; }

	string GetCharacter() { return _character; }
	void SetCharacter(string character) { _character = character; }

	string GetCare() { return _care; }
	void SetCare(string care) { _care = care; }

	bool aborted()
	{
		return _abort;
	}

	void ReadFromConsole()
	{
		string inp;
		cout << "Заполните все параметры анкеты собаки. Для отмены введите /stop\n";
		for (int i = 0; i < 9; i++)
		{
			cout << msgs[i];
			cin >> inp;
			if (checkExit(inp))
			{
				_abort = true;
				break;
			}
			putValByIndex(inp, i);
		}
		cout << "\n";
	}

	void ReadFromFile(ifstream* fin)
	{
		(*fin) >> _name
			>> _color
			>> _gender
			>> _dateOfBirth
			>> _size
			>> _keeperName
			>> _namePitomn
			>> _character
			>> _care;
	}

	string getValByIndex(int index)
	{
		string(Dog::*funcs[])() = {
			&Dog::GetName,&Dog::GetColor,&Dog::GetGender,&Dog::GetDateOfBirth,&Dog::GetSize,&Dog::GetKeeperName,&Dog::GetNamePitomn,&Dog::GetCharacter,&Dog::GetCare
		};
		return (this->*funcs[index])();
	}

	~Dog() {}
};

string pName[8]
{
	"Цвет",
	"Пол",
	"Дата рождения",
	"размер",
	"Имя владельца",
	"Название питомника",
	"Характер",
	"Уход"
};

void PrintDog(Dog* dog)
{
	cout << dog->GetClassName() << " " << dog->GetName() << endl;
	for (int i = 0; i < 8; i++)
		cout << pName[i] << ": " << dog->getValByIndex(i+1) << ";" << endl;
	cout << endl;
}

void SaveToFile(string FileName, Dog* dog)
{
	ofstream fout(FileName.c_str(), ios_base::app);

	fout << dog->GetClassName() << " " << dog->GetName() << endl
		<< dog->GetColor() << endl
		<< dog->GetGender() << endl
		<< dog->GetDateOfBirth() << endl
		<< dog->GetSize() << endl
		<< dog->GetKeeperName() << endl
		<< dog->GetNamePitomn() << endl
		<< dog->GetCharacter() << endl
		<< dog->GetCare() << endl;
}

class Labrador : public Dog
{
public:
	Labrador() {}
	Labrador(bool fromConsole) : Dog(fromConsole, 0) {	}

	string GetClassName() override
	{
		return "Лабрадор";
	}
};

class Haski : public Dog
{
public:
	Haski() {}
	Haski(bool fromConsole) : Dog(fromConsole, 0) {	}

	string GetClassName() override
	{
		return "Хаски";
	}
};

class shnaucer : public Dog
{
public:
	shnaucer() {}
	shnaucer(bool fromConsole) : Dog(fromConsole, 0) {	}

	string GetClassName() override
	{
		return "Шнауцер";
	}
};

class Chihuahua : public Dog
{
public:
	Chihuahua() {}
	Chihuahua(bool fromConsole) : Dog(fromConsole, 0) {	}

	string GetClassName() override
	{
		return "Чихуахуа";
	}
};

class Pudel : public Dog
{
public:
	Pudel() {}
	Pudel(bool fromConsole) : Dog(fromConsole, 0) {	}

	string GetClassName() override
	{
		return "Пудель";
	}
};

class Spaniel : public Dog
{
public:
	Spaniel() {}
	Spaniel(bool fromConsole) : Dog(fromConsole, 0) {	}

	string GetClassName() override
	{
		return "Спаниэль";
	}
};

class Creator
{
public:
	virtual Dog* FactoryMethod()
	{
		return new Dog();
	}
	~Creator() {}
};

class LabradorCreator : public Creator
{
public:
	Dog * FactoryMethod() override
	{
		return new Labrador(true);
	};
};

class HaskiCreator : public Creator
{
public:
	Dog * FactoryMethod() override
	{
		return new Haski(true);
	};
};

class shnaucerCreator : public Creator
{
public:
	Dog * FactoryMethod() override
	{
		return new shnaucer(true);
	};
};

class ChihuahuaCreator : public Creator
{
public:
	Dog * FactoryMethod() override
	{
		return new Chihuahua(true);
	};
};

class PudelCreator : public Creator
{
public:
	Dog * FactoryMethod() override
	{
		return new Pudel(true);
	};
};

class SpanielCreator : public Creator
{
public:
	Dog * FactoryMethod() override
	{
		return new Spaniel(true);
	};
};

string** split(string str, char splitSymbol = ' ')
{
	vector<string> mass = vector<string>();
	string tmp = "";
	for (char c : str)
	{
		if (c == splitSymbol)
		{
			if (tmp.length() > 0)
			{
				mass.push_back(tmp);
				tmp = "";
			}
		}
		else
			tmp.push_back(c);
	}

	if (tmp.length() > 0)
		mass.push_back(tmp);

	string** ret = (string**)malloc(sizeof(string*)*mass.size());
	for (int i = 0; i < mass.size(); i++)
		ret[i] = new string(mass.at(i));

	return ret;
};

static Dog** ReadFromFile(string file, int * size)
{
	*size = 0;
	Dog **ff = (Dog**)malloc(sizeof(Dog*));
	ifstream fin(file);
	while (1)
	{
		if (!fin.eof())
		{
			ff = (Dog**)realloc(ff, sizeof(Dog*)*((*size) + 1));
			Dog* b = new Dog();
			string type;
			fin >> type;
			if (type == "Лабрадор")
				b = new Labrador();

			if (type == "Хаски")
				b = new Haski();

			if (type == "Шнауцер")
				b = new shnaucer();

			if (type == "Чихуахуа")
				b = new Chihuahua();

			if (type == "Пудель")
				b = new Pudel();

			if (type == "Спаниэль")
				b = new Spaniel();

			if (type == "")
				break;

			b->ReadFromFile(&fin);
			ff[*size] = b;
			(*size)++;
		}
		else break;
	}
	return ff;
};

string mainfile = "system.txt";
vector<Dog*> dogs = vector<Dog*>();

int main() {
	setlocale(LC_ALL, "rus");
	system("color F0");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	static const size_t count = 6;
	Creator*creators[] = {
		new LabradorCreator(),new HaskiCreator(),new shnaucerCreator(),new ChihuahuaCreator(), new PudelCreator(), new SpanielCreator() };
	string command;
	while (true) {
		cout << "Введите команду. Для справки введите help\n";
		getline(cin, command);
		if (command == "") {
			getline(cin, command);
		}

		string** comArr = split(command);
		int commandEx = 0;

		if (*comArr[0] == "input") {
			if (*comArr[1] == "Labrador") {
				dogs.push_back(creators[0]->FactoryMethod());
				commandEx++;
			}
			if (*comArr[1] == "Haski")
			{
				dogs.push_back(creators[1]->FactoryMethod());
				commandEx++;
			}
			if (*comArr[1] == "shnaucer")
			{
				dogs.push_back(creators[2]->FactoryMethod());
				commandEx++;
			}
			if (*comArr[1] == "Chihuahua")
			{
				dogs.push_back(creators[3]->FactoryMethod());
				commandEx++;
			}
			if (*comArr[1] == "Pudel")
			{
				dogs.push_back(creators[4]->FactoryMethod());
				commandEx++;
			}
			if (*comArr[1] == "Spaniel")
			{
				dogs.push_back(creators[5]->FactoryMethod());
				commandEx++;
			}
		}

		if (*comArr[0] == "show") {
			if (dogs.size() == 0)
				cout << "Сначала добавьте значения" << endl;
			else
				for (Dog *b : dogs)
					PrintDog(b);
			commandEx++;
		}

		if (*comArr[0] == "help")
		{
			//input
			cout << "input <тип>\n"
				<< "Команда позволяет ввести анкету собаки с клавиатуры" << endl
				<< "тип может быть одним из следующих: Labrador, Haski, shnaucer, Chihuahua, Pudel, Spaniel" << endl << endl;

			//show
			cout << "show" << endl
				<< "Команда предназначена для вывода на экран всех созданных собак" << endl << endl;

			//file
			cout << "file <команда>" << endl
				<< "open: считывает данные из файла" << endl
				<< "save: считывает данные из файла" << endl << endl;

			//delete
			cout << "delete [id]" << endl
				<< "Удаляет запись с оответствующим индексом" << endl << endl;

			//clear 
			cout << "clear" << endl
				<< "Очищает массив данных программы, все несохраненные данные будут безвозвратно утеряны" << endl << endl;

			//exit
			cout << "exit" << endl
				<< "выход из программы" << endl << endl;

			commandEx++;
		}

		if (*comArr[0] == "file") {
			if (*comArr[1] == "open") {
				int count = 0;
				Dog** dogsFile = ReadFromFile(mainfile, &count);
				for (int i = 0; i < count; i++)
					dogs.push_back(dogsFile[i]);
				cout << "Успешно!" << endl;
				commandEx++;
			}
			if (*comArr[1] == "save") {
				FILE * f;
				fopen_s(&f, mainfile.c_str(), "w");
				for (Dog *b : dogs)
					SaveToFile(mainfile, b);
				cout << "Успешно!" << endl;
				commandEx++;
			}
		}

		if (*comArr[0] == "delete")
		{
			int p = stoi(*comArr[1]);
			dogs.erase(dogs.begin() + p);
			commandEx++;
		}

		if (*comArr[0] == "clear")
		{
			dogs = vector<Dog*>();
			commandEx++;
		}

		if (*comArr[0] == "exit")
			break;

		if (commandEx == 0)
			cout << "Команда не найдена" << endl;
	}
}