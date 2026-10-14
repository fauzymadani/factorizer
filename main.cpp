#include <chrono>
#include <cmath>
#include <iomanip>
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

  auto start = std::chrono::steady_clock::now();

  bool found = false;
  long long p = 0, q = 0;
  long long D = S * S - 4 * P;

  if (D >= 0) {
    long long r = std::llround(std::sqrt(static_cast<double>(D)));
    while (r * r > D)
      --r;
    while ((r + 1) * (r + 1) <= D)
      ++r;

    if (r * r == D && (S - r) % 2 == 0) {
      found = true;
      p = (S - r) / 2;
      q = (S + r) / 2;
    }
  }

  // hence the saying: “Eureka!"
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> ms = end - start;

  if (found) {
    std::cout << "\nsolutions found:\n";
    std::cout << "  (" << p << ", " << q << ")\n";
    if (p != q)
      std::cout << "  (" << q << ", " << p << ")\n";
  } else {
    std::cout << "\nno integer pair satisfies the conditions.\n";
  }

  std::cout << std::fixed << std::setprecision(6) << "time: " << ms.count()
            << " ms\n";
  return 0;
}
