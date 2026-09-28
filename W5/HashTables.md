# Homework 5 1/1: Hash Tables
### Part 1.
|  Key  |  Digit Sum  |  Table Index  |
| ----- | ----------- | ------------- |
| 555223|     22      |       2       |
| 555980|     32      |       2       |
| 555000|     15      |       5       |
| 555890|     32      |       2       |
#### Analysis: Three keys produced the exact same table index using the hash function. This is known as hash collision. Considering that the only remainders of module $10$ can be $0$ through $9$ and the hash table is assumed to contain $10$ slots, any result of this hash function can only be a valid index. Increasing the table size will not reduce the chance of hash collisions. The probability of hash collisions is dependent on the type of hash function implemented. If it produces a small number of hash values, say $0$ through $9$, those values will only take up a small portion of memory and result in a higher likelihood of collisions. Even if the table size were to increase, it may potentially decrease that likelihood but it will not guarantee that hash collisions will never occur. 
### Part 2.
```C++
int hashFunction(int key, int tableSize)
{
	int sum = 0;
	int index;

	while (key != 0)
	{
		int last = key % tableSize;

		sum += last;

		key /= tableSize;
	}

	index = sum % tableSize;

	return index;
}
```
### Parts 3 & 4.
```C++
#include<iostream>
#include<string>
#include<vector>

int hashFunction(int key, int tableSize)
{
	int sum = 0;
	int index;

	while (key != 0)
	{
		int last = key % tableSize;

		sum += last;

		key /= tableSize;
	}

	index = sum % tableSize;

	return index;
}

struct Record
{
	int key = 0;
	std::string value = "";
};

int main()
{
	std::vector<Record> records(11);
	Record clientInfo;
	std::string name;
	int choice;
	int recordNumber;
	int index;

	std::cout << "Type a number to make your choice or -1 to exit. " << "\n";
	std::cout << "1. Placement \n2. Search \n3. Deletion \nChoice: ";
	std::cin >> choice;

	while (choice != -1)
	{
		switch (choice)
		{
			case 1:

				std::cout << "Enter the record number: ";
				std::cin >> recordNumber;
				if (recordNumber > 0)
				{
					clientInfo.key = recordNumber;
				}

				std::cout << "Enter the client's name: ";
				std::cin.ignore();
				getline(std::cin, name);
				clientInfo.value = name;

				index = hashFunction(recordNumber, records.size());

				if (records.at(index).value.length() == 0)
				{
					records.at(index) = clientInfo;
				}
				else
				{
					for (int i = 0; i < records.size(); i++)
					{
						int probeIndex = (index + i) % records.size();

						if (records.at(probeIndex).key == clientInfo.key && records.at(probeIndex).value.length() > 0)
						{
							records.at(probeIndex).value = clientInfo.value;
							break;
						}
						else if (records.at(probeIndex).value == "")
						{
							records.at(probeIndex) = clientInfo;
							break;
						}
					}
				}

				std::cout << "\n--- TABLE ---\n";

				for (int i = 0; i < records.size(); i++)
				{
					std::cout << i << ": "
						<< records.at(i).key << " | "
						<< records.at(i).value << "\n";
				}

				std::cout << "-------------\n";

				break;

			case 2:
			{
				bool found = false;

				std::cout << "Enter the record number: ";
				std::cin >> recordNumber;

				index = hashFunction(recordNumber, records.size());

				for (int i = 0; i < records.size(); i++)
				{
					int probeIndex = (index + i) % records.size();
					
					if (records.at(probeIndex).key == recordNumber)
					{
						std::cout << "Client name: " << records.at(probeIndex).value << "\n";
						found = true;
						break;
					}
				}

				if (!found)
				{
					std::cout << "Record was not found.\n";
				}

				break;
			}
			case 3:

				std::cout << "Enter record number of slot for deletion: ";
				std::cin >> recordNumber;

				index = hashFunction(recordNumber, records.size());

				for (int i = index; i < records.size(); i++)
				{
					if (records.at(i).key == recordNumber)
					{
						records.at(i).key = 0;
						records.at(i).value = "mark";
					}
				}
				break;
		}
		std::cout << "Choice: ";
		std::cin >> choice;
	}
	return 0;
}
```
