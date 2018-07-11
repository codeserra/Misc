//*****************************************************************************************************************
// Given a pattern containing only I’s and D’s. I for increasing and D for decreasing. Devise an algorithm to print
// the minimum number following that pattern. Digits from 1-9 and digits can’t repeat.
//*****************************************************************************************************************


#include <bits/stdc++.h>
using namespace std;

int printpattern(string str)
{
    int l = str.length();
    if(l>8)
        return -1;
    int i_count =0;
    int i_num =0; 
    int arr[9] ==0;
    int i_pos_max=0;
    for (auto &s:str)
    {
        if(s!="D" && s!="I")
            return -1;
            
        if (i_count==0)
        {
            if(s=="I")
            {
                arr[0] = 1;
                arr[1] = 2;
                i_count = 2;
                i_pos_max = 1;
            }
            else if(s=="D")
            {
                arr[0] = 2;
                arr[1] = 1;
                i_pos_max = 0;
                i_count=2;
            }
            continue;
        }
        
        if(s=="I")
        {
            int i_max =0;
            for (int i=0; i<i_count; i++)
                if(i_max<arr[i])
                    i_max = arr[i];
            arr[i_count] = i_max+1;
            i_pos_max= i_count;
        }
        else if(s=="D")
        {
            arr[i_count] = arr[i_count-1]-1;
            int dif = arr[i_pos_max] - arr[i_count];
            if(dif>0)
                for (int j = i_pos_max; j<=i_count; j++)
                     arr[i_count]+=dif;
        }
        i_count++;
    }
    
    for (int i =i_count; i>=0; i--)
    {
        i_num = arr[i] + i_num* 10;
    }
    
    return i_num;
}
int main() {
	//code
	int t=0; 
	cin<<t;
	
	for (int i=0; i<t; t++)
	{
	    string s_inp;
	    cin >> s_inp;
	    cout<< printpattern(s_inp)<<" ";
	}
	return 0;
}
