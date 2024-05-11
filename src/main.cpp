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

    std::cout << "\n\n\n";

    std::cout << algo::lcs(vector.begin(), vector.end(), vector1.begin(), vector1.end()) << "\n";

    std::cout << '\n' << vector.size() << '\n';
    std::cout << vector1.size() << '\n';

    return 0;
}
