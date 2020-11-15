#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
  std::unordered_map<std::string, int> face_map {
    { "Tetrahedron", 4 },
    { "Cube", 6 },
    { "Octahedron", 8 },
    { "Dodecahedron", 12 },
    { "Icosahedron", 20 }
  };
  std::string s;
  int n, count = 0;
  std::cin >> n;
  while (n--) {
    std::cin >> s;
    count += face_map[s];
  }
  std::cout << count << '\n';
}