#include <bits/stdc++.h>
using namespace std;
vector<string> keypadHelper(int num, vector<string> &options)
{
    if (num <= 1){
      vector<string> output;
      output.push_back("");
      return output;
    }
    int lastDigit = num % 10;
    int smallNumber = num / 10;
    vector<string> smallOutput;
    vector<string> output;
    smallOutput = keypadHelper(smallNumber, options);
    string op = options[lastDigit];
    for (int i = 0; i < op.length(); i++){
        for (int j = 0; j < int(smallOutput.size()); j++){
                output.push_back(smallOutput[j] + op[i]);
        }
    }
    return output;
}
vector<string> keypad(int num){
   
    vector<string> options = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> output;

    output = keypadHelper(num, options);

    return output;
}
int main()
{
int t;
cin >> t;
    while (t--){
    int n;
    cin >> n;
    vector<string> output = keypad(n);
    for (int i = 0; i < int(output.size()); i++){
        cout << output[i] << endl;
    }
    }
return 0;
}