#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif
   unsigned int n, a, b;
   std::cin >> n >> a >> b;

   unsigned int sulfidNano = 2 * n * a * b;
   std::cout << sulfidNano << std::endl;
}