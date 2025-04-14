#include <iostream>
#include <string>
using namespace std;

int getSuperDigit(long long num)
{
  if (num < 10)
  {
    return num;
  }

  int sum = 0;
  while (num > 0)
  {
    sum += num % 10;
    num /= 10;
  }

  return getSuperDigit(sum);
}

int main()
{
  string s;
  cout << "Enter the number: ";
  cin >> s;

  int l1 = s.size();
  cout << "Total length of your number is: " << l1 << endl;

  string s1 = s;
  for (int i = 0; i < l1 - 1; i++)
  {
    s1 += s;
  }

  cout << "Your concatenated string is: " << s1 << endl;

  long long l2 = stoll(s1);  //string to link
  
  int superDigit = getSuperDigit(l2);

  cout << "Super digit is: " << superDigit << endl;

  return 0;
}
