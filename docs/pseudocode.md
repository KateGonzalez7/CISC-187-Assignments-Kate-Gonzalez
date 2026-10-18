# Pseudocode
### Adding Packages
```C++
variable package

while validNum != true
  cin package.trackingNumber
  if package.trackingNumber empty
    cout "Error cannot be empty"
    validNum = false
  else if tracking number is invalid using checkForInvalidNumber function
    cout "Error must be valid"
    validNum = false
  else if tracking number is duplicate using checkForDuplicate function
    cout "Error cannot enter duplicate"
    validNum = false
  else
    cout "Tracking number entered"
    validNum = true

while validRecipient != true
  cin package.recipient
  if package.recipient empty or recipient invalid using checkForInvalidRecipient function
    cout "Recipient cannot be empty or only initials"
    validRecipient = false
  else
    cout "Recipient entered"
    validRecipient = true

while validDestination != true
  cin package.destination
  if package.destination empty or invalid using checkForInvalidDestination function
    cout "Destination must not be blank"
    validDestination = false
  else
    cout "Destination entered"
    validDestination = true

while validWeight != true
  cin package.weight
  if package.weight <= 0
    cout "Error enter valid weight"
    validWeight = false
  else
    cout "Weight entered"
    validWeight = true

vectorForPackages.push_back(package)
queueForPackages.push(package)
hashtableForPackages[package.trackingNumber] = package
package.status = "Waiting"
```
### Duplicate Checks
```C++
bool checkForDuplicates(newTrackingNum, vectorForPackages)
  if vectorForPackages is empty
    return false
  if newTrackingNum has spaces between numbers
    remove spaces
  if vectorForPackages.contains(newTrackingNum)
    return true
  return false
```
### Enqueue/Dequeue
```C++
// Enqueue (see Adding Packages)
queueForPackages.push(package)
// Dequeue 
if queue is empty
  cout "Error no packages"
else
  Package processed = queueForPackages.front()
  queueForPackages.pop()
  change status of package in hashtableForPackages to "Processed"
  printPackageDetails(processed)
```
### Hash Lookup
```C++
bool hashtableLookup(trackingNum, hashtable)
validNumber = false
if trackingNumber is empty
  cout "Error tracking number cannot be empty"
  validNumber = false
else if trackingNumber is invalid
  cout "Error tracking number must be valid"
  validNumber = false
else if hashtable is empty
  cout "No packages available for search"
  validNumber = false
else if hashtable does not contain trackingNumber
  cout "No package with that tracking number"
  validNumber = false
else if hashtable contains trackingNumber
  cout package information
  validNumber = true
return validNumber
```
### Linear Search
```C++
void linearSearchByTrackingNumber(tracking, packages)
for i from 0 to packages size
  if packages.at(i).trackingNumber equals tracking
    print package details
    break
  i++
```
### Status Updates
```C++
string trackingNumber
bool validNumber is false
while validNumber != true
  cin trackingNumber
  if trackingNumber empty
    cout "Error tracking number cannot be empty"
    validNumber = false
  else if trackingNumber is invalid using checkForInvalidNumber function
    cout "Error tracking number must be valid"
    validNumber = false
  else if hashtable is empty
    cout "No packages available to update status"
    validNumber = false
  else if hashtable does not contain trackingNumber
    cout "No package found with that tracking number"
    validNUmber = false
  else if hashtable contains trackingNumber
    string currentStatus is hashtable[trackingNumber].status
    char confirm
    if currentStatus is "Waiting"
      cout "Cannot change until package is processed"
    else if currentStatus is "Processed"
      cout "Type y to confirm in transit or n to exit"
      cin comfirm
      if confirm == 'y' or 'Y'
        hashtable[trackingNumber].status = "In Transit"
      else if confirm == 'n' or 'N'
        cout "Exiting now."
      else
        cout "Error enter valid response"
    else if currentStatus is "In Transit"
      cout "Type y to confirm in transit or n to exit"
      cin comfirm
      if confirm == 'y' or 'Y'
        hashtable[trackingNumber].status = "Delivered"
      else if confirm == 'n' or 'N'
        cout "Exiting now."
      else
        cout "Error enter valid response"
    else if currentStatus is "Delivered"
      cout "Package is with recipient"
```
### Non-destructive Queue Qisplay
```C++
queue<Package> waitingPackages = queueForPackages
if waitingPackages size != 0
  for i from 0 to waitingPackages size
    cout tracking number using waitingPackages.front().trackingNumber
    cout recipient using waitingPackages.front().recipient
    cout destination using waitingPackages.front().destination
    cout weight using waitingPackages.front().weight
    cout status using waitingPackages.front().status
    waitingPackages.pop()
    i++
```
### Sorting Algorithm For Any Field
```C++
vector<Package> copyRecords is copy of original package records
if original records size is 0
  cout "No packages to sort."
else
  for int from 1 to copyRecords.size()
    key is package copyRecords.at(i)
    int j = i - 1
    while j >= 0 and key.field < copyRecords.at(j).field
      copyRecords.at(j + 1) = copyRecords.at(j)
      --j
    copyRecords.at(j + 1) = key
    i++
```
### Summary Calculations
```C++
total packages = vectorForPackages.size()
waiting packages = queueForPackages.size()

// Algorithm for processed, in transit, and delivered packages
int count = 0
for i from 0 to vectorForPackages.size()
  if status of vectorForPackages at i == "Processed" (or "In Transit" or "Delivered")
    count++
  i++
return count

// Algorithm for total package weight
totalWeight = 0
if vectorForPackages size is 0
  cout "No packages to weigh"
else
  for i from 0 to vectorForPackages size
    totalWeight += weight of vectorForPackages at i
    i++
return totalWeight

// Algorithm for average package weight
averagePackageWeight = 0
if vectorForPackages size is 0
  cout "No packages to weigh"
else
  averageWeight = totalWeight / vectorForPackages.size()
return averageWeight

// Algorithm for heaviest package
heaviest = 0
if vectorForPackages size is 0
  cout "No packages to weigh"
else
  heaviest = weight of vectorForPackages.at(0)
  for i from 0 to vectorForPackages size
    if heaviest < vectorForPackages weight at i
      heaviest = vectorForPackages weight at i
    i++
return heaviest
```
