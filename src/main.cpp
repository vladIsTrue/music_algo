#include "utils.h"

int main()
{
    auto [vector, min] = test::mid_to_vector("no_name.mid");
    auto [vector1, min1] = test::mid_to_vector("no_name3.mid", min);

    for (auto item : vector)
        std::cout << item << " ";

    std::cout << "\n\n\n";

    for (auto item : vector1)
        std::cout << item << " ";


    std::cout << "\n\n\n";

    std::cout << algo::lcs(vector.begin(), vector.end(), vector1.begin(), vector1.end()) << "\n";

    return 0;
}
