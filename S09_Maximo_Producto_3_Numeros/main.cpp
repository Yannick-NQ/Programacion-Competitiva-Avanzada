#include <iostream>
#include <vector>
#include <algorithm>

int maxProductOfThree(std::vector<int>& nums) {
    // Ordenar el vector
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    // Considerar el producto de los tres números más grandes
    int max1 = nums[n-1] * nums[n-2] * nums[n-3];

    // Considerar el producto de los dos números más pequeños y el número más grande
    int max2 = nums[0] * nums[1] * nums[n-1];

    // El máximo de los dos productos posibles
    return std::max(max1, max2);
}

int main() {
    std::vector<int> nums1 = {2, 3, 4, 6, 8, 1};
    std::cout << "Producto máximo de tres números diferentes: " << maxProductOfThree(nums1) << std::endl;

    std::vector<int> nums2 = {2, 3, 4, -6, -8, 1};
    std::cout << "Producto máximo de tres números diferentes: " << maxProductOfThree(nums2) << std::endl;

    std::vector<int> nums3 = {2, 3, 4, -6, -8, -1};
    std::cout << "Producto máximo de tres números diferentes: " << maxProductOfThree(nums3) << std::endl;

    std::vector<int> nums4 = {2, -1, 4, -3, 7};
    std::cout << "Producto máximo de tres números diferentes: " << maxProductOfThree(nums4) << std::endl;

    std::vector<int> nums5 = {-6, -4, -5, 1, 2};
    std::cout << "Producto máximo de tres números diferentes: " << maxProductOfThree(nums5) << std::endl;

    std::vector<int> nums6 = {-4, -6, -3, -5, 1};
    std::cout << "Producto máximo de tres números diferentes: " << maxProductOfThree(nums6) << std::endl;

    return 0;
}
