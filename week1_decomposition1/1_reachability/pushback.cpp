// vector::push_back
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    myvector.push_back (myint);
  } while (myint);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
  
  for(unsigned int j = 0; j < myvector.size(); j++)
  {
    for(unsigned int k = 0; k < myvector[j].size(); k++)
    {
      std::cout<<myvector[j][k] << " ";
    }
  }

  return 0;
}