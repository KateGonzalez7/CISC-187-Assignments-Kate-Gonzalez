# Pseudocode
### Adding Packages
```C++
global variable package

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
```
### Status Updates
```C++

```
### Non-destructive Queue Qisplay

### Sorting

### Summary Calculations
