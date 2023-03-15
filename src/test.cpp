#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> vec2;

    std::remove_copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
                        [](int val) { return (val == 4 || val == 6); });

    // Print the new vector
    for (int val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
