# Testing Package & Delivery System
| Action | Input  | Expected Result | Actual Result | Pass or Fail? |
| ------ | ------ | --------------- | ------------- | ------------- |
| Add 1st valid package | 123<br>Jane Doe<br>Los Angeles, CA<br>4 | Tracking number entered successfully.<br>-------------------------------------<br>Recipient name entered successfully.<br>-------------------------------------<br>Destination entered successfully.<br>-------------------------------------<br>Weight entered successfully.<br>------------------------------------- |<img width="276" height="167" alt="Test1" src="https://github.com/user-attachments/assets/27d4606e-7a72-4ec3-b646-eef092a5ef54" />| Pass|
| Add several packages and verify FIFO order | 234<br>Alice Anderson<br>San Francisco, CA<br>11<br>1<br>345<br>Bob Baker<br>Sacramento, CA<br>9<br>1<br>456<br>Candace Carlson<br>Fresno, CA<br>15<br>5 | Waiting Packages<br>------------------<br>Package 1<br>Tracking number: 123<br>Recipient: Jane Doe<br>Destination: Los Angeles, CA<br>Weight: 4<br>Status: Waiting<br>-------------------------------------<br>Package 2<br>Tracking number: 234<br>Recipient: Alice Anderson<br>Destination: San Francisco, CA<br>Weight: 11<br>Status: Waiting<br>-------------------------------------<br>Package 3<br>Tracking number: 345<br>Recipient: Bob Baker<br>Destination: Sacramento, CA<br>Weight: 9<br>Status: Waiting<br>-------------------------------------<br>Package 4<br>Tracking number: 456<br>Recipient: Candace Carlson<br>Destination: Fresno, CA<br>Weight: 15<br>Status: Waiting<br>-------------------------------------|<img width="272" height="464" alt="Test2" src="https://github.com/user-attachments/assets/dbec8238-11de-4e63-ac2b-23a9769f3a71" />| Pass |
| Reject duplicate tracking number | 345 | Error: Cannot enter duplicate tracking number<br>------------------------------------- |<img width="352" height="68" alt="Test3" src="https://github.com/user-attachments/assets/c282c546-f56b-43d1-8866-9264abbd3304" />| Pass |
| Reject an invalid weight | abc<br>-987 | Error: Enter a numeric value<br>-------------------------------------<br>Error: Enter a valid weight<br>------------------------------------- |<img width="274" height="83" alt="Test4" src="https://github.com/user-attachments/assets/7423b253-01e7-4f64-9137-d80367b04b15" />| Pass |
| Process the next package and verify its status changes | 2<br>3<br>123 | 















