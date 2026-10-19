#include<limits>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

struct Package
{
	string trackingNumber;
	string recipient;
	string destination;
	double weight = 0;
	string status;
};

bool checkForDuplicate(string number, unordered_map<string, Package> packages)
{
	if (packages.size() == 0)
	{
		return false;
	}

	if (number.find(' ') != string::npos)
	{
		number.erase(remove_if(number.begin(), number.end(), isspace), number.end());
	}
	if (packages.contains(number))
	{
		return true;
	}
	
	return false;
}

bool checkForInvalidNumber(string number)
{
	int i = 0;

	while (number[i])
	{
		if (ispunct(number[i]))
		{
			return true;
		}
		if (isspace(number[i]) || isblank(number[i]))
		{
			return true;
		}
		i++;
	}
	return false;
}

bool checkForInvalidRecipient(string name)
{
	int i = 0;
	int alphaCount = 0;

	while (name[i])
	{
		if (ispunct(name[i]) || isdigit(name[i]))
		{
			return true;
		}
		if (isalpha(name[i]))
		{
			alphaCount++;
		}
		i++;
	}

	if (alphaCount == 0)
	{
		return true;
	}

	return false;
}

bool checkForInvalidDestination(string destination)
{
	int i = 0;
	int alphaCount = 0;

	while (destination[i])
	{
		if (isalpha(destination[i]))
		{
			alphaCount++;
		}
		i++;
	}

	if (alphaCount == 0)
	{
		return true;
	}

	return false;
}

vector<Package> sortByTrackingNumber(vector<Package> originalRecords)
{
	vector<Package> copyRecords = originalRecords;

	if (originalRecords.size() == 0)
	{
		cout << "No packages to sort by tracking number.\n";
	}
	else
	{
		for (int i = 1; i < copyRecords.size(); i++)
		{
			Package key = copyRecords.at(i);
			int j = i - 1;

			while (j >= 0 && key.trackingNumber < copyRecords.at(j).trackingNumber)
			{
				copyRecords.at(j + 1) = copyRecords.at(j);
				--j;
			}
			copyRecords.at(j + 1) = key;
		}
	}

	return copyRecords;
}

vector<Package> sortByRecipient(vector<Package> originalRecords)
{
	vector<Package> copyRecords = originalRecords;

	if (originalRecords.size() == 0)
	{
		cout << "No packages to sort by recipient.\n";
	}
	else
	{
		for (int i = 1; i < copyRecords.size(); i++)
		{
			Package key = copyRecords.at(i);
			int j = i - 1;

			while (j >= 0 && key.recipient < copyRecords.at(j).recipient)
			{
				copyRecords.at(j + 1) = copyRecords.at(j);
				--j;
			}
			copyRecords.at(j + 1) = key;
		}
	}

	return copyRecords;
}

vector<Package> sortByWeight(vector<Package> originalRecords)
{
	vector<Package> copyRecords = originalRecords;

	if (originalRecords.size() == 0)
	{
		cout << "No packages to sort by weight.\n";
	}
	else
	{
		for (int i = 1; i < copyRecords.size(); i++)
		{
			Package key = copyRecords.at(i);
			int j = i - 1;

			while (j >= 0 && key.weight < copyRecords.at(j).weight)
			{
				copyRecords.at(j + 1) = copyRecords.at(j);
				--j;
			}
			copyRecords.at(j + 1) = key;
		}
	}

	return copyRecords;
}

vector<Package> sortByDestination(vector<Package> originalRecords)
{
	vector<Package> copyRecords = originalRecords;

	if (originalRecords.size() == 0)
	{
		cout << "No packages to sort by destination.\n";
	}
	else
	{
		for (int i = 1; i < copyRecords.size(); i++)
		{
			Package key = copyRecords.at(i);
			int j = i - 1;

			while (j >= 0 && key.destination < copyRecords.at(j).destination)
			{
				copyRecords.at(j + 1) = copyRecords.at(j);
				--j;
			}
			copyRecords.at(j + 1) = key;
		}
	}

	return copyRecords;
}

int processedPackagesCount(vector<Package> records)
{
	int count = 0;

	for (int i = 0; i < records.size(); i++)
	{
		if (records.at(i).status == "Processed")
		{
			count++;
		}
	}

	return count;
}

int inTransitPackagesCount(vector<Package> records)
{
	int count = 0;

	for (int i = 0; i < records.size(); i++)
	{
		if (records.at(i).status == "In Transit")
		{
			count++;
		}
	}

	return count;
}

int deliveredPackagesCount(vector<Package> records)
{
	int count = 0;

	for (int i = 0; i < records.size(); i++)
	{
		if (records.at(i).status == "Delivered")
		{
			count++;
		}
	}

	return count;
}

double totalPackageWeight(vector<Package> records)
{
	double totalWeight = 0;

	if (records.size() == 0)
	{
		cout << "No packages to weigh to determine total weight.\n";
	}
	else
	{
		for (int i = 0; i < records.size(); i++)
		{
			totalWeight += records.at(i).weight;
		}
	}

	return totalWeight;
}

double averagePackageWeight(vector<Package> records)
{
	double averageWeight = 0;
	
	if (records.size() == 0)
	{
		cout << "No packages to weigh to determine average weight.\n";
	}
	else
	{
		averageWeight = totalPackageWeight(records) / records.size();
	}

	return averageWeight;
}

double heaviestPackage(vector<Package> records)
{
	double heaviest = 0;

	if (records.size() == 0)
	{
		cout << "No packages to weigh to find heaviest package.\n";
	}
	else
	{
		heaviest = records.at(0).weight;
		
		for (int i = 0; i < records.size(); i++)
		{
			if (heaviest < records.at(i).weight)
			{
				heaviest = records.at(i).weight;
			}
		}
	}

	return heaviest;
}

void printPackageDetails(Package package)
{
	cout << "Tracking Number: " << package.trackingNumber << "\n";
	cout << "Recipient: " << package.recipient << "\n";
	cout << "Destination: " << package.destination << "\n";
	cout << "Weight: " << package.weight << "\n";
	cout << "Status: " << package.status << "\n";
	cout << "-------------------------------------\n";
}

void printWaitingPackages(queue<Package> packageQueue)
{
	cout << "Waiting Packages\n";
	cout << "------------------\n";

	int queueSize = packageQueue.size();

	if (packageQueue.size() != 0)
	{
		for (int i = 0; i < queueSize; i++)
		{
			cout << "Package " << i + 1 << ":\n";
			cout << "Tracking number: " << packageQueue.front().trackingNumber << "\n";
			cout << "Recipient: " << packageQueue.front().recipient << "\n";
			cout << "Destination: " << packageQueue.front().destination << "\n";
			cout << "Weight: " << packageQueue.front().weight << "\n";
			cout << "Status: " << packageQueue.front().status << "\n";
			cout << "-------------------------------------\n";

			packageQueue.pop();
		}
	}
}

void printProcessedPackages(vector<Package> records)
{
	cout << "\nProcessed Packages\n";
	cout << "--------------------\n";

	for (int i = 0; i < records.size(); i++)
	{
		if (records.at(i).status == "Processed")
		{
			cout << "Package " << i << ":\n";
			cout << "Tracking number: " << records.at(i).trackingNumber << "\n";
			cout << "Recipient: " << records.at(i).recipient << "\n";
			cout << "Destination: " << records.at(i).destination << "\n";
			cout << "Weight: " << records.at(i).weight << "\n";
		}
	}
}

void printInTransitPackages(vector<Package> records)
{
	cout << "\nIn Transit Packages\n";
	cout << "---------------------\n";

	for (int i = 0; i < records.size(); i++)
	{
		if (records.at(i).status == "In Transit")
		{
			cout << "Package " << i << ":\n";
			cout << "Tracking number: " << records.at(i).trackingNumber << "\n";
			cout << "Recipient: " << records.at(i).recipient << "\n";
			cout << "Destination: " << records.at(i).destination << "\n";
			cout << "Weight: " << records.at(i).weight << "\n";
		}
	}
}

void printDeliveredPackages(vector<Package> records)
{
	cout << "\nDelivered Packages\n";
	cout << "--------------------\n";

	for (int i = 0; i < records.size(); i++)
	{
		if (records.at(i).status == "Delivered")
		{
			cout << "Package " << i << ":\n";
			cout << "Tracking number: " << records.at(i).trackingNumber << "\n";
			cout << "Recipient: " << records.at(i).recipient << "\n";
			cout << "Destination: " << records.at(i).destination << "\n";
			cout << "Weight: " << records.at(i).weight << "\n";
		}
	}
}

void printPackageRecords(vector<Package> records)
{
	if (records.size() != 0)
	{
		for (int i = 0; i < records.size(); i++)
		{
			printPackageDetails(records.at(i));
		}
	}
}

void editPackageStatus(vector<Package>& records, string status, string trackingNumber)
{
	for (int i = 0; i < records.size(); i++)
	{
		if (records.at(i).trackingNumber == trackingNumber)
		{
			records.at(i).status = status;
			break;
		}
	}
}

bool hashtableLookup(string trackingNumber, unordered_map<string, Package> hashtable)
{
	bool validNumber = false;

	if (trackingNumber == "")
	{
		cout << "Error: Cannot enter empty tracking number.\n";
		cout << "-------------------------------------\n";

		validNumber = false;
	}
	else if (checkForInvalidNumber(trackingNumber) == true)
	{
		cout << "Error: Must enter a valid tracking number.\n";
		cout << "-------------------------------------\n";

		validNumber = false;
	}
	else if (hashtable.empty() == true)
	{
		cout << "Error: No packages available for display.\n";
		cout << "-------------------------------------\n";

		validNumber = false;
	}
	else if (!hashtable.contains(trackingNumber))
	{
		cout << "No package found with that tracking number.\n";
		cout << "-------------------------------------\n";

		validNumber = false;
	}
	else if (hashtable.contains(trackingNumber))
	{
		cout << "Package information\n";

		printPackageDetails(hashtable[trackingNumber]);

		validNumber = true;
	}

	return validNumber;
}

void linearSearchByTrackingNumber(string trackingNumber, vector<Package> packages)
{
	bool found = false;
	
	if (packages.size() == 0)
	{
		cout << "Error: No packages available for display.\n";
		cout << "-------------------------------------\n";
	}
	else
	{
		for (int i = 0; i < packages.size(); i++)
		{
			if (packages.at(i).trackingNumber == trackingNumber)
			{
				printPackageDetails(packages.at(i));

				found = true;

				break;
			}
		}
	}

	if (!found)
	{
		cout << "No package found with that tracking number.\n";
		cout << "-------------------------------------\n";
	}
}

int main()
{
	vector<Package> packageRecords;
	queue<Package> enqueuedPackages;
	unordered_map<string, Package> packageLookup;
	Package package;
	int choice = 0;
	string input;

	while (choice != 9)
	{
		cout << "PACKAGE DELIVERY TRACKING SYSTEM\n";
		cout << "--------------------------------\n";
		cout << "1. Add Package\n";
		cout << "2. Process Next Package\n";
		cout << "3. Find Package by Tracking Number\n";
		cout << "4. Update Package Status\n";
		cout << "5. Display Waiting Packages\n";
		cout << "6. Display All Packages\n";
		cout << "7. Display Sorted Package Report\n";
		cout << "8. Display System Summary\n";
		cout << "9. Exit\n";
		cout << "Selection (or 9 to exit): ";
		cin >> input;
		cout << "-------------------------------------\n";

		if (input.length() != 1)
		{
			cout << "Error: Please select a number from the list.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		choice = input[0] - '0';

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice)
		{
			case 1:
			{
				bool validNumber = false;
				bool validRecipient = false;
				bool validDestination = false;
				bool validWeight = false;

				while (validNumber != true)
				{
					cout << "Enter tracking number (no spaces): ";
					getline(cin, package.trackingNumber);

					if (package.trackingNumber == "")
					{
						cout << "Error: Cannot enter empty tracking number.\n";
						cout << "-------------------------------------\n";
							
						validNumber = false;
					}
					else if (checkForInvalidNumber(package.trackingNumber) == true)
					{
						cout << "Error: Must enter a valid tracking number.\n";
						cout << "-------------------------------------\n";

						validNumber = false;
					}
					else if (checkForDuplicate(package.trackingNumber, packageLookup) == true)
					{
						cout << "Error: Cannot enter duplicate tracking number.\n";
						cout << "-------------------------------------\n";

						validNumber = false;
					}
					else
					{
						cout << "Tracking number entered successfully.\n";
						cout << "-------------------------------------\n";

						validNumber = true;
					}
				}

				while (validRecipient != true)
				{
					cout << "Enter recipient's name: ";
					getline(cin, package.recipient);

					if (package.recipient == "" || checkForInvalidRecipient(package.recipient) == true)
					{
						cout << "Error: Recipient name must not be blank or contain only initials.\n";
						cout << "-------------------------------------\n";
							
						validRecipient = false;
					}
					else
					{
						cout << "Recipient name entered successfully.\n";
						cout << "-------------------------------------\n";

						validRecipient = true;
					}
				}

				while (validDestination != true)
				{
					cout << "Enter destination: ";
					getline(cin, package.destination);

					if (package.destination == "" || checkForInvalidDestination(package.destination) == true)
					{
						cout << "Error: Destination must not be blank.\n";
						cout << "-------------------------------------\n";

						validDestination = false;
					}
					else
					{
						cout << "Destination entered successfully.\n";
						cout << "-------------------------------------\n";

						validDestination = true;
					}
				}

				while (validWeight != true)
				{
					cout << "Enter package weight (lbs): ";
					cin >> package.weight;
						
					if (cin.fail())
					{
						cout << "Error: Enter a numeric value.\n";
						cout << "-------------------------------------\n";

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						validWeight = false;
					}
					else if (package.weight <= 0)
					{
						cout << "Error: Enter a valid weight.\n";
						cout << "-------------------------------------\n";

						validWeight = false;
					}
					else
					{
						cout << "Weight entered successfully.\n";
						cout << "-------------------------------------\n";

						validWeight = true;
					}
				}

				package.status = "Waiting";
				packageRecords.push_back(package);
				enqueuedPackages.push(package);
				packageLookup[package.trackingNumber] = package;

				break;
			}
			case 2:
			{
				if (enqueuedPackages.empty())
				{
					cout << "Error: There are no packages to process.\n";
					cout << "-------------------------------------\n";
				}
				else
				{
					Package processedPackage = enqueuedPackages.front();

					processedPackage.status = "Processed";

					enqueuedPackages.pop();

					packageLookup[processedPackage.trackingNumber].status = "Processed";
					
					editPackageStatus(packageRecords, processedPackage.status, processedPackage.trackingNumber);

					printPackageDetails(processedPackage);

				}
				break;
			}
			case 3:
			{
				string trackingNum;
				bool validNumber = false;

				while (validNumber != true)
				{
					cout << "Enter the tracking number of the package you want to locate: ";
					getline(cin, trackingNum);

					cout << "Hashtable Lookup:\n";
					validNumber = hashtableLookup(trackingNum, packageLookup);

					cout << "Linear Search:\n";
					linearSearchByTrackingNumber(trackingNum, packageRecords);
				}
				break;
			}
			case 4:
			{
				string trackingNum;
				bool validNumber = false;

				while (validNumber != true)
				{
					cout << "Enter tracking number of package to update: ";
					getline(cin, trackingNum);
					cout << "\n";

					if (trackingNum == "")
					{
						cout << "Error: Cannot enter empty tracking number.\n";
						cout << "-------------------------------------\n";

						validNumber = false;
					}
					else if (checkForInvalidNumber(trackingNum) == true)
					{
						cout << "Error: Must enter a valid tracking number.\n";
						cout << "-------------------------------------\n";

						validNumber = false;
					}
					else if (packageLookup.empty() == true)
					{
						cout << "Error: No packages available to update status.\n";
						cout << "-------------------------------------\n";

						validNumber = false;
					}
					else if (!packageLookup.contains(trackingNum))
					{
						cout << "No package found with that tracking number.\n";
						cout << "-------------------------------------\n";

						validNumber = false;
					}
					else if (packageLookup.contains(trackingNum))
					{
						string currentStatus = packageLookup[trackingNum].status;
						char confirm;

						cout << "Current status: " << currentStatus << "\n";

						if (currentStatus == "Waiting")
						{
							cout << "Cannot change status until package is processed.\n";
						}
						else if (currentStatus == "Processed")
						{
							cout << "Type y to confirm package is now in transit or n to exit: ";
							cin >> confirm;
							cout << "\n";

							if (confirm == 'y' || confirm == 'Y')
							{
								packageLookup[trackingNum].status = "In Transit";

								editPackageStatus(packageRecords, packageLookup[trackingNum].status, trackingNum);

								cout << "Package status changed to " << packageLookup[trackingNum].status << "\n";
							}
							else if (confirm == 'n' || confirm == 'N')
							{
								cout << "Exiting now.\n";
								break;
							}
							else
							{
								cout << "Error: Please enter a valid response.\n";
							}
						}
						else if (currentStatus == "In Transit")
						{
							cout << "Type y to confirm package is now delivered or n to exit: ";
							cin >> confirm;
							cout << "\n";

							if (confirm == 'y' || confirm == 'Y')
							{
								packageLookup[trackingNum].status = "Delivered";

								editPackageStatus(packageRecords, packageLookup[trackingNum].status, trackingNum);
								
								cout << "Package status changed to " << packageLookup[trackingNum].status << "\n";
							}
							else if (confirm == 'n' || confirm == 'N')
							{
								cout << "Exiting now.\n";
							}
							else
							{
								cout << "Error: Please enter a valid response.\n";
							}
						}
						else if (currentStatus == "Delivered")
						{
							cout << "Package is with recipient.\n";
						}
						validNumber = true;
					}
				}
				break;
			}
			case 5:
			{
				queue<Package> waitingPackages(enqueuedPackages);

				printWaitingPackages(waitingPackages);

				break;
			}
			case 6:
			{
				queue<Package> waitingPackages(enqueuedPackages);

				printWaitingPackages(waitingPackages);

				printProcessedPackages(packageRecords);

				printInTransitPackages(packageRecords);

				printDeliveredPackages(packageRecords);

				break;
			}
			case 7:
			{
				int sortingOption;
				vector<Package> sortedRecords;

				cout << "Select sorting option for package display.\n";
				cout << "1. Tracking Number\n";
				cout << "2. Recipient\n";
				cout << "3. Weight\n";
				cout << "4. Destination\n";
				cout << "Enter choice: ";
				cin >> sortingOption;
				cout << "\n";

				if (sortingOption < 1 || sortingOption > 4)
				{
					cout << "Error: Please select from the list of options.\n";
					cout << "-------------------------------------\n";
				}
				else if (sortingOption == 1)
				{
					sortedRecords = sortByTrackingNumber(packageRecords);
					printPackageRecords(sortedRecords);
				}
				else if (sortingOption == 2)
				{
					sortedRecords = sortByRecipient(packageRecords);
					printPackageRecords(sortedRecords);
				}
				else if (sortingOption == 3)
				{
					sortedRecords = sortByWeight(packageRecords);
					printPackageRecords(sortedRecords);
				}
				else if (sortingOption == 4)
				{
					sortedRecords = sortByDestination(packageRecords);
					printPackageRecords(sortedRecords);
				}

				break;
			}
			case 8:
			{
				int numProcessed = processedPackagesCount(packageRecords);
				int numInTransit = inTransitPackagesCount(packageRecords);
				int numDelivered = deliveredPackagesCount(packageRecords);
				double totalWeight = totalPackageWeight(packageRecords);
				double averageWeight = averagePackageWeight(packageRecords);
				double heaviest = heaviestPackage(packageRecords);

				cout << "SYSTEM SUMMARY\n";
				cout << "-------------------------------------\n";
				cout << "|" << setw(25) << "Total Packages" << "|" << setw(8) << packageRecords.size() << "| \n";
				cout << "|" << setw(25) << "Waiting Packages" << "|" << setw(8) << enqueuedPackages.size() << "| \n";
				cout << "|" << setw(25) << "Processed Packages" << "|" << setw(8) << numProcessed << "| \n";
				cout << "|" << setw(25) << "In Transit Packages" << "|" << setw(8) << numInTransit << "| \n";
				cout << "|" << setw(25) << "Delivered Packages" << "|" << setw(8) << numDelivered << "| \n";
				cout << "|" << setw(25) << "Total Package Weight" << "|" << setw(8) << totalWeight << "|\n";
				cout << "|" << setw(25) << "Average Package Weight" << "|" << setw(8) << averageWeight << "|\n";
				cout << "|" << setw(25) << "Heaviest Package" << "|" << setw(8) << heaviest << "|\n";
				cout << "-------------------------------------\n";

				break;
			}
			case 9:
				cout << "Exiting system.";
				break;
			default:
				cout << "Error: Please select from the list or type -1 to exit.\n";
				break;
		}
	}

	return 0;
}