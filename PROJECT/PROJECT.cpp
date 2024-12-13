#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include <conio.h>
using namespace std;
int total_num;
string NAME = "anon";


void menu()
{
	cout << 1 << " = " << "set_name" << endl;
	cout << 2 << " = " << "set_color" << endl;
	cout << 3 << " = " << "system(all files)" << endl;
	cout << 4 << " = " << "system(special file(.txt,.cpp))" << endl;
	cout << 5 << " = " << "Creating a directory" << endl;
	cout << 6 << " = " << "clear" << endl;
	cout << 7 << " = " << "Create a new file" << endl;
	cout << 8 << " = " << "Overwrite_file" << endl;
	cout << 9 << " = " << "update_file" << endl;
	cout << 10 << " = " << "watch_file" << endl;
	cout << 11 << " = " << "chanse_file" << endl;


}

void on_load()
{

	fstream Read_File("name.txt", ios::in);
	if (Read_File.is_open())
	{
		Read_File >> NAME;
	}
	Read_File.close();

	
	fstream file_read("color.txt", ios::in);
	if (file_read.is_open())
	{
		file_read >> total_num;
	}
	
	
}

void colorize(int number)
{
	
	string command = "color " + to_string(number);
	system(command.c_str());

}

void set_name()
{
	cin >> NAME;
	fstream Writer_file("name.txt", ios::out);
	if (Writer_file.is_open())
	{
		Writer_file << NAME;
	}
	Writer_file.close();

}

void set_color()
{
	cin >> total_num;
	fstream Write_in_file("color.txt", ios::out);
	if (Write_in_file.is_open())
	{
		Write_in_file << total_num;
	}
	Write_in_file.close();
	
}

void system_dir()
{
	string command = "dir /b *.cpp *.txt | findstr /v /c:\" bytes\" > fileNames.txt";
	system(command.c_str());
	cout << command << endl;
}

void system_spec()
{
	cout << "<<Выберите формат который вы хотели бы увидеть, либо ввести самому>>" << endl;
	cout << "<< 1 - .txt >>" << endl;
	cout << "<< 2 - .cpp >>" << endl;
	cout << "<< 3 - Ввести формат самому >>" << endl;


	int number;
	cin >> number;
	string form;
	string command1 = "dir /b *.txt";
	string command2 = "dir /b *.cpp";
	
	
	if (number == 1)
	{
		system(command1.c_str());
		cout << endl;

	}

	else if (number == 2)
	{
		system(command2.c_str());
		cout << endl;
	}

	else if (number == 3)
	{
		cin >> form;
		string command3 = "dir /b *" + form;
		system(command3.c_str());
		cout << endl;
	}

	
}


void cmd()
{
	cout << "<<Введите название директории>>" << endl;
	string name;
	cin >> name;
	string command = "mkdir " + name;
	system(command.c_str());
}


void system_cls()
{
	string command = "cls";
	system(command.c_str());
}

void Name_of_file()
{
	cout << "<<Введите имя файла>>" << endl;
	string Name;
	cin >> Name;
	fstream Write_file(Name + ".txt",ios::app);
	Write_file.close();
	cout << "Файл создан " << endl;
	cout << endl;
}

void overwrite_file()
{
	cout << "<<Введите имя файла>>" << endl;
	string name;
	cin >> name;

	string line;
	fstream Read_file(name + ".txt", ios::in);
	if (Read_file.is_open())
	{
		while (getline(Read_file, line))
		{
			cout << line << endl;
			
		}
		cout << "<<Вы уверены перезаписать файл?>>" << endl;
		cout << "<<1 - ДА>>" << endl;
		cout << "<<2 - НЕТ>>" << endl;
		int number;
		vector <string> vec;
		cin >> number;
		if (number == 1)
		{
			string client_word;
			cout << "<<Введите свой текст>>" << endl;
			while (true)
			{
				getline(cin, client_word);
				vec.push_back(client_word);
				if (client_word == "stop")
				{
					break;
				}
			}
			
			vec.pop_back();
			fstream Write_file(name + ".txt", ios::out);
			if (Write_file.is_open())
			{
				for (size_t i = 0; i < vec.size(); i++)
				{
					Write_file << vec[i] << endl;
				}
				
			}
		}
		else if (number == 2)
		{
			cout << "<<Изменений нет>>" << endl;
		}
	}
	else
	{
		cout << "Файл не найден" << endl;
	}
	Read_file.close();

	
}

void update_file()
{
	string line;
	string words;
	vector<string>vec;
	string name_of_file;
	cout << "<<Введите название файла>>" << endl;
	cin >> name_of_file;
	
	
	
	fstream write_file(name_of_file + ".txt", ios::app);
	if (write_file.is_open())
	{
		int ch;
		cout << "<<Укажите кол-во строчек>>" << endl;
		cin >> ch;
		cout << "Введите текст" << endl;
		getchar();
		for (size_t i = 0; i < ch; i++)
		{
			getline(cin, words);
			vec.push_back(words);
		}
		
		for (size_t i = 0; i < vec.size(); i++)
		{
			write_file << vec[i] << endl;
		}
		
	}
	else
	{
		cout << "NON";
	}
	write_file.close();
}

void watch_file()
{
	string name;
	string line;
	cout << "<<Введите имя файла>>" << endl;
	cin >> name;
	fstream read_file(name + ".txt", ios::in);
	if (read_file.is_open())
	{
		while (getline(read_file, line))
		{
			cout << line << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Файл не найден";
	}
	read_file.close();
}

void chanse_file()
{
	string name;
	vector <string>vec;
	string line;
	int k = 0;

	while (true)
	{
		cout << "<<Введите имя файла>>" << endl;
		cin >> name;
		fstream read_file(name + ".txt", ios::in);
		if (read_file.is_open())
		{
			
			cout << "=======================" << endl;
			while (getline(read_file, line))
			{
			
				cout << k << " = " << line << endl;
				k++;
				vec.push_back(line);
			}
			cout << "=======================" << endl;
			break;
		}
		else
		{
			cout << "файла не существует" << endl;
			cout << "to out cin >> ESC or any type to continue" << endl;
			if ((int)_getch() == 27)
			{
				return;
			}

		}

		read_file.close();
	}
	
	
	
	
	int numbers = 0;

	while (numbers != -1)
	{
	
		cout << "Выберите строку которую хотите изменить" << endl;
		int num;
		string chanse;
		cin >> num;
		if (num > -1 && num < vec.size())
		{
			cout << "Введите изменения" << endl;
			getchar();	
			getline(cin, chanse);
		
			vec[num] = chanse;
			cout << endl;
		
		}
		else
		{
			cout << "выход за пределы строк" << endl;
		}
		cout << "======================" << endl;
		for (size_t i = 0; i < vec.size(); i++)
		{
			cout << i << " = " << vec[i] << endl;
		}
		cout << "======================" << endl;

		
		
		cout << "to out cin == -1, else 1" << endl;
		cin >> numbers;

	
		
	}
	fstream write_file(name + ".txt", ios::out);
	if (write_file.is_open())
	{
		for (string elem : vec)
		{
			write_file << elem << endl;
		}
	}
	else
	{
		cout << "NON";
	}
	write_file.close();

	cout << "Файл успешно перзаписан" << endl;

}

int main()
{
	
	on_load();
	setlocale(LC_ALL, "RUS");
	cout << "Hello " << NAME << endl;
	string command;
	while (true)
	{
		colorize(total_num);
		menu();
		int ch;
		cout << "ch - > ";
		cin >> ch;
		cout << endl;
		switch (ch) {
		case 0:
			cout << "end\n";
			return 0;
			break;
		case 1:
			set_name();
			break;
		case 2:
			set_color();
			break;
		case 3:
			system_dir();
			break;
		case 4:
			system_spec();
			break;
		case 5:
			cmd();
			break;
		case 6:
			system_cls();
			break;
		case 7:
			Name_of_file();
			break;
		case 8:
			overwrite_file();
			break;
		case 9:
			update_file();
			break;
		case 10:
			watch_file();
			break;
		case 11:
			chanse_file();
			break;
		default:
			cout << "err \n";
			break;
		}
	}
	return 0;





	




}
