# 68. Text Justification

>Given an array of words and a width *maxWidth*, format the text such that each line has exactly *maxWidth* characters and is fully (left and right) justified.
>
>You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces `' '` when necessary so that each line has exactly *maxWidth* characters.
>
>Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
>
>For the last line of text, it should be left justified and no **extra** space is inserted between words.
>
>**Note:**
>
>- A word is defined as a character sequence consisting of non-space characters only.
>- Each word's length is guaranteed to be greater than 0 and not exceed *maxWidth*.
>- The input array `words` contains at least one word.
>
>**Example 1:**
>
>```
>Input:
>words = ["This", "is", "an", "example", "of", "text", "justification."]
>maxWidth = 16
>Output:
>[
>   "This    is    an",
>   "example  of text",
>   "justification.  "
>]
>```
>
>**Example 2:**
>
>```
>Input:
>words = ["What","must","be","acknowledgment","shall","be"]
>maxWidth = 16
>Output:
>[
>  "What   must   be",
>  "acknowledgment  ",
>  "shall be        "
>]
>Explanation: Note that the last line is "shall be    " instead of "shall     be",
>             because the last line must be left-justified instead of fully-justified.
>             Note that the second line is also left-justified becase it contains only one word.
>```
>
>**Example 3:**
>
>```
>Input:
>words = ["Science","is","what","we","understand","well","enough","to","explain",
>         "to","a","computer.","Art","is","everything","else","we","do"]
>maxWidth = 20
>Output:
>[
>  "Science  is  what we",
>  "understand      well",
>  "enough to explain to",
>  "a  computer.  Art is",
>  "everything  else  we",
>  "do                  "
>]
>```

**Solution**

// TODO

```C++
class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> text;
    stack<string> stack;
    int length = 0;
    for (auto &word: words) {
      if (length + word.length() + stack.size() - 1 < maxWidth) {
        length += word.length();
        stack.push(word);
      } else {
        int spaces = maxWidth - length - stack.size() + 1;
        string line = "";
        while (!stack.empty()) {
          int avgSpaces = stack.size() == 1 ? 0 : spaces / (stack.size() - 1) + 1;
          line = string(avgSpaces, ' ') + stack.top() + line;
          stack.pop();
          spaces -= avgSpaces - 1;
        }
        line += string(maxWidth - line.length(), ' ');
        text.push_back(line);
        length = word.length();
        stack.push(word);
      }
    }
    if (!stack.empty()) {
      string line = "";
      while (!stack.empty()) {
        int space = stack.size() == 1 ? 0 : 1;
        line = string(space, ' ') + stack.top() + line;
        stack.pop();
      }
      line += string(maxWidth - line.length(), ' ');
      text.push_back(line);
    }
    return text;
  }
};
```

