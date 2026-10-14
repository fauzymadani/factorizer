#include <cmath>
#include <iostream>
#include <limits>
#include <string>

long long getInteger(const std::string &prompt) {
  int value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return value;
    }
    if (std::cin.eof())
      std::exit(1);
    std::cout << "invalid input. please enter an integer.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

int main() {
  long long P = getInteger("enter product target (a * c): ");
  long long S = getInteger("enter sum target (b): ");

  long long D = S * S - 4 * P;
  if (D >= 0) {
    long long r = std::llround(std::sqrt(static_cast<double>(D)));
    while (r * r > D)
      --r;
    while ((r + 1) * (r + 1) <= D)
      ++r;

    if (r * r == D && (S - r) % 2 == 0) {
      std::cout << "Pair: (" << (S - r) / 2 << ", " << (S + r) / 2 << ")\n";
      return 0;
    }
  }
  std::cout << "no integer pair satisfies the conditions.\n";
}
