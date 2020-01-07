# Contest 170

## 1309. Decrypt String from Alphabet to Integer Mapping

Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

<p align = "center">   <img width = "500" src = "images/170th_Contest_2020-01-06-23-14-54.png "> </p>

### Constraints

- 1 <= s.length <= 1000
- s[i] only contains digits letters ('0'-'9') and '#' letter.
- s will be valid string such that mapping is always possible.

### idea

There will be 2 cases: 
1. 10# - 26# 
2. 1 - 9

So our program is going to check which case is above first then figure out the offset. 

1. 10# to 26#

i <= s.length() - 3 && 
(s[i] == '1' || s[i] == '2') && 
s[i+2] == '#'

The first condiction will make sure the s[i+2] not got an address access correct. 

2. else is 1 - 9 

### offest
- 10# - 26# -> 10 * (s[i] - '0') + s[i + 1] - '1' + 'a'; 
- 1 - 9 -> s[i] - '1' + 'a'; 

### code

```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        string result; 
        
        for (int i = 0; i < s.length(); ++i)
        {
            char ch; 
            if (i <= s.length() - 3 && (s[i] == '1' || s[i] == '2') && s[i+2] == '#')
            {
                ch = 10 * (s[i] - '0') + s[i+1] - '1' + 'a'; 
                i += 2; 
                
            } else 
            {
                ch = s[i] - '1' + 'a'; 
            }
            result += ch; 
        }
        return result; 
        
    }
};
```

