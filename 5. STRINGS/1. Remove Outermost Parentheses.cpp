/*
Remove Outermost Parentheses
You're given a valid parentheses string s (made of only ( and ))
Break it into primitive valid parts (i.e., the smallest possible valid groups)
From each primitive part, remove the outermost pair of parentheses
Return the final string formed by joining all the modified parts

Primitive valid parentheses string is one that:
Is not empty & Cannot be split further into two non-empty valid strings

From the input, remove the first and last bracket from each primitive group
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0)
                    result += ch;
                depth++;
            } else {
                depth--;
                if (depth > 0)
                    result += ch;
            }
        }
        return result;
    }
};

/*
If character is '(':
If we're already inside (if depth > 0), it's not the outermost, so we add it to result
Increase depth by 1

If character is ')':
Decrease depth by 1 first
If we’re still inside after decreasing (if depth > 0), it’s not the outermost, so we add it to result
*/

