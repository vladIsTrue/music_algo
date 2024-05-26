#include "utils.h"

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cout << "Enter the names of the two files\n";
        return 0;
    }

    auto [vector, min] = test::mid_to_vector(argv[1]);
    auto [vector1, min1] = test::mid_to_vector(argv[2], min);

    double lcs_mod = algo::lcs_mod(vector.begin(), vector.end(), vector1.begin(), vector1.end());

    double coeff = lcs_mod / vector.size();

    double error = 0.05;
    const double left = 1, right = 2;

    if (coeff >= left + error && coeff <= right + error)
        std::cout << "Match found!!!\n";
    else
        std::cout << "No match found\n";

    return 0;
}
