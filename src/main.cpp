#include "utils.h"

int main()
{
//    auto tuple = test::long_short_test<double>();

//    std::get<0>(tuple).save ("1.wav", AudioFileFormat::Wave);
//    std::get<1>(tuple).save ("2.wav", AudioFileFormat::Wave);


//    tuple = test::long_speed_test<double>();

//    std::get<0>(tuple).save ("3.wav", AudioFileFormat::Wave);
//    std::get<1>(tuple).save ("4.wav", AudioFileFormat::Wave);


//    tuple = test::long_short_speed_test<double>();

//    std::get<0>(tuple).save ("5.wav", AudioFileFormat::Wave);
//    std::get<1>(tuple).save ("6.wav", AudioFileFormat::Wave);


    std::string first {"41516171"};
    std::string second {"4567"};

    std::cout << algo::lcs(first.begin(), first.end(), second.begin(), second.end());

    return 0;
}
