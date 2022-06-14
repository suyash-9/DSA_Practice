
#include <bits/stdc++.h>
using namespace std;

 typedef long long int ll;


string encrypt(char text[], ll s,ll n)
{
	string result = "";


	for (ll i=0;i<n;i++)
	{
		if(text[i]==' ')continue;
		if((text[i]-'a'>=0 && text[i]-'z'<=0)|| (text[i]-'A'>=0 && text[i]-'Z'<=0)){
                    // Encrypt Uppercase letters
                if (isupper(text[i]))
                    result += char(int(text[i]+s-65)%26 +65);
        
            // Encrypt Lowercase letters
            else
                result += char(int(text[i]+s-97)%26 +97);
            }

            else {
                result+=text[i];
            }
        }
        

	// Return the resulting string
	return result;
}

// Driver program to test the above function
int main()
{
    ll n=100;
   // cin>>n;
	char text[n];
    cin.getline(text,n);
	ll s = 4;
	cout << "Text : " << text;
	cout << "\nShift: " << s;
	cout << "\nCipher: " << encrypt(text, s,n);
	return 0;
}
