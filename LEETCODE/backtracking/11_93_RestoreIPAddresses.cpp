/*
https://leetcode.com/problems/restore-ip-addresses/

93_RestoreIPAddresses

Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

*/



class Solution {
public:

    bool isValid(string s1)
    {

       if(s1.size()>3||s1.size()==0) return false;

       if(s1.size()>1 && s1[0]=='0') return false;

       if(s1.size() && stoi(s1)>255) return false;

       return true;
    }

    void recur(int i, int dots, string temp, vector<string>& ans, string s)
    {

        if(dots==3)
        {

            if(isValid(s.substr(i)))
            {

                ans.push_back(temp+s.substr(i));

            }
            return;
        }


        for(int j=i; j<s.size() ;j++)
        {

        if( isValid(s.substr(i, j-i+1)))
        {
            temp.push_back(s[j]);
            temp.push_back('.');

            recur(j+1, dots+1, temp, ans, s);
            
            temp.pop_back();


            }
        }

        return;

    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> ans;

        if(s.size()<4) return ans;

        recur(0, 0, "", ans, s);

        return ans;
    }
};