# Homework 5 1/1: Hash Tables
### Part 1.
|  Key  |  Digit Sum  |  Table Index  |
| ----- | ----------- | ------------- |
| 555223|     22      |       2       |
| 555980|     32      |       2       |
| 555000|     15      |       5       |
| 555890|     32      |       2       |
#### Analysis: Three keys produced the exact same table index using the hash function. This is known as hash collision. Considering that the only remainders of module $10$ can be $0$ through $9$ and the hash table is assumed to contain $10$ slots, any result of this hash function can only be a valid index. Increasing the table size will not reduce the chance of hash collisions. The probability of hash collisions is dependent on the type of hash function implemented. If it produces a small number of hash values, say $0$ through $9$, those values will only take up a small portion of memory and result in a higher likelihood of collisions. Even if the table size were to increase, it may potentially decrease that likelihood but it will not guarantee that hash collisions will never occur. 
