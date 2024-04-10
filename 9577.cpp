#include <iostream>
#include <vector>
#include <stack>
#include <bitset>
 
#define ull unsigned long long
 

using namespace std;

ull finder(ull n){
 
    
    bitset<64> bits(n);
    bool flag = false;
    string pieces = bits.to_string();
    pieces.erase(0, pieces.find('1'));
    int length = pieces.size();
    int halflength = length / 2 + length % 2;
    stack<int> OO;
   
    
    for (int i = 0; i < halflength; ++i)
    {
        int pair = length - i - 1;
        if (!bits[pair])
        {
          OO.push(i);
          if (bits[i]) flag = true;
        }
        else if (!bits[i]) flag = false;
    }

    if (OO.empty()) 
    {
        for (int i = length / 2; i < length; ++i) {
            pieces[i] = '1';
        }
    }
    
    else if (flag) 
    {
        int lastIndex = OO.top();
        pieces[lastIndex] = '1';
        pieces[length - lastIndex - 1] = '1';

        for (int i = 1; i < lastIndex; ++i) 
            pieces[length - i - 1] = pieces[i];
         
        for (int i = lastIndex + 1; i < halflength; ++i)
        { 
            pieces[i] = '0';
            pieces[length - i - 1] = '0';
        }
    } 
    else
    {
        for (int i = 0; i < halflength; ++i) 
            pieces[length - i - 1] = pieces[i];         
    }
    
    return bitset<64>(pieces).to_ullong();
}



int main() {
    ull n;
    cin >> n;
    cout << finder(n);
}
