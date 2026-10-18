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
### Enqueue/Dequeue
### Hash Lookup
### Linear Search
### Status Updates
### Non-destructive Queue Qisplay
### Sorting
#### 
### Summary Calculations
