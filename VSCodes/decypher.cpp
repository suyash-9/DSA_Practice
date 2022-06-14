#include <bits/stdc++.h>
using namespace std;

 typedef long long int ll;


string encrypt(char text[], ll s,ll n)
{
	string result="";

	for(int i=0;i<n;i++)
	{
                if((text[i]-'a'>=0 && text[i]-'z'<=0)|| (text[i]-'A'>=0 && text[i]-'Z'<=0)){
                if(isupper(text[i]))
                    result+=char(int(text[i]+s-65)%26 +65);
            //Encrypt Lowercase letters
            else
                result+=char(int(text[i]+s-97)%26 +97);
            }
            else {
                result+=text[i];
            }
    }
	
	return result;
}


int main()
{
	int s = 4;

     ll n=100;
   // cin>>n;
	char text[n];
    cin.getline(text,n);

	
	cout<<"Text :"<<text;
	cout<<"\nShift:" << s;
	s = s%26; // ensuring that s lies between 0-25
	cout<<"\nCipher:"<<encrypt(text, 26-s,n);
	return 0;
}
