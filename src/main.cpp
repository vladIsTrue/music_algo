#include "utils.h"

int main(int argc, char* argv[])
{
    // мб докрутить мануал сюда
    // сначал передаем, что ищем, потом то, где ищем, вот и все
    // нужно смотреть, чтобы коэффициент располагался в интервале от 1 до 2, чем ближе к двум, тем лучше
    // , он может немного вылазить, но это нужно обработать

    if (argc < 3)
    {
        std::cout << "Enter the names of the two files\n";
        return 0;
    }

    auto [vector, min] = test::mid_to_vector(argv[1]);
    auto [vector1, min1] = test::mid_to_vector(argv[2], min);

    //std::cout << algo::lcs(vector.begin(), vector.end(), vector1.begin(), vector1.end()) << "\n";
    double lcs_mod = algo::lcs_mod(vector.begin(), vector.end(), vector1.begin(), vector1.end());

    double coeff = lcs_mod / vector.size();

    std::cout << lcs_mod << "\n";
    std::cout << '\n' << vector.size() << '\n';
    std::cout << coeff << "\n";

    double error = 0.05;
    const double left = 1, right = 2;

    if (coeff >= left + error && coeff <= right + error)
        std::cout << "Match found!!!\n";
    else
        std::cout << "No match found\n";

    return 0;
}
