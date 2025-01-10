#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"
#include "tests.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

bool body_contains_isgreen()
{
    Candle first = {21, 0, 0, 40};

    return first.body_contains(21)
     && first.body_contains(37) 
     && first.body_contains(40);
}

bool body_contains_isred()
{
  Candle second = {40, 0 , 0 , 21};

  return second.body_contains(40)
  && second.body_contains(34)
  && second.body_contains(21);
}

bool body_contains_not_in_green()
{
  Candle third = {13, 0, 0, 20};

  return !third.body_contains(12.8)
  && !third.body_contains(21.2)
  && !third.body_contains(1);
}



void initTests()
{
  tests.push_back(body_contains_isgreen);
  tests.push_back(body_contains_isred);
  tests.push_back(body_contains_not_in_green);

}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  launchTests();

  return 0;
}
