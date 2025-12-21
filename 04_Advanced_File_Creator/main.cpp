# include <iostream>
# include <string>
# include <fstream>
using namespace std;

struct stFile_Config
{
	string file_name, content, extension;
	int file_number = 0;
};

stFile_Config Get_User_Input()
{
	stFile_Config config;

	cout << "--- File Creator Tool ---" << endl;

	do
	{
		cout << "Enter How Many File:\n";
		cin >> config.file_number;
	} while (config.file_number <= 0);

	cout << "Entre File Name:\n";
	cin.ignore(1, '\n');
	getline(cin, config.file_name);
	cout << "Enter File Content:\n";
	getline(cin, config.content);
	cout << "Enter File Extension (e.g, .txt, .html)\n";
	getline(cin, config.extension);


	return config;
}

void File_Creator(stFile_Config config)
{
	for (int i = 1; i <= config.file_number; i++)
	{
		string Number_str = to_string(i);

		if (i < 10)
		{
			Number_str = "00" + Number_str;
		}
		else if (i < 100)
		{
			Number_str = "0" + Number_str;
		}

		string finally_name = config.file_name + "_" + Number_str + config.extension;

		ifstream check_file(finally_name);

		if (check_file)
		{
			cout << "Skipped (Already Exists):" << finally_name << endl;
			check_file.close();
		}
		else
		{
			ofstream file(finally_name);
			if (file.is_open())
			{
				cout << "Created: " << finally_name << endl;
				file << config.content << " " << Number_str << endl;
				file.close();
			}
			else
			{
				cout << "Error Creating File!" << endl;
			}
		}
	}
}

int main()
{
	stFile_Config config = Get_User_Input();
	File_Creator(config);

	cout << "Done! Created " << config.file_number << " Files." << endl;
	system("pause");
	return 0;
}