#include <cmath>

#include "AudioFile.h"

namespace test
{

template<class T>
std::tuple<AudioFile<T>, AudioFile<T>> long_short_test
(std::string input_file_path ="/home/fym/cpp/kursach/src/test-audio.wav");

template<class T>
std::tuple<AudioFile<T>, AudioFile<T>> long_speed_test
(std::string input_file_path ="/home/fym/cpp/kursach/src/test-audio.wav");

template<class T>
std::tuple<AudioFile<T>, AudioFile<T>> long_short_speed_test
(std::string input_file_path ="/home/fym/cpp/kursach/src/test-audio.wav");

}

namespace algo
{

template <class It>
int lcs(It x_begin, It x_end, It y_begin, It y_end);

}

namespace test
{
    template<class T>
    std::tuple<AudioFile<T>, AudioFile<T>> long_short_test(std::string input_file_path)
    {
        AudioFile<T> origin;
        bool loadedOK = origin.load(input_file_path);

        assert (loadedOK);

        AudioFile<T> origin_one_chanell, part;
        origin_one_chanell.setNumChannels(1);
        origin_one_chanell.setNumSamplesPerChannel(origin.getNumSamplesPerChannel());

        part.setNumChannels(1);
        part.setNumSamplesPerChannel(origin.getNumSamplesPerChannel() / 3.0);

        int chanell = 0;

        for (int i = 0, end = origin.getNumSamplesPerChannel(); i < end; ++i)
        {
            origin_one_chanell.samples[chanell][i] = origin.samples[chanell][i];
        }

        for (int i = origin.getNumSamplesPerChannel() / 3.0,
                 j = 0,
               iend = origin.getNumSamplesPerChannel() * 2.0 / 3.0,
               jend = origin.getNumSamplesPerChannel() / 3.0;
             i < iend && j < jend; ++i, ++j)
        {
            part.samples[chanell][j] = origin.samples[chanell][i];
        }

        return {origin_one_chanell, part};
    }

    template<class T>
    std::tuple<AudioFile<T>, AudioFile<T>> long_speed_test(std::string input_file_path)
    {
        AudioFile<T> origin;
        bool loadedOK = origin.load(input_file_path);

        assert (loadedOK);

        AudioFile<T> origin_one_chanell;

        origin_one_chanell.setNumChannels(1);
        origin_one_chanell.setNumSamplesPerChannel(origin.getNumSamplesPerChannel());

        int chanell = 0;

        for (int i = 0, end = origin.getNumSamplesPerChannel(); i < end; ++i)
        {
            origin_one_chanell.samples[chanell][i] = origin.samples[chanell][i];
        }

        AudioFile<T> speed(origin_one_chanell);
        speed.setSampleRate(origin_one_chanell.getSampleRate() * 2.0);

        return {origin_one_chanell, speed};
    }

    template<class T>
    std::tuple<AudioFile<T>, AudioFile<T>> long_short_speed_test(std::string input_file_path)
    {
        auto tuple = long_short_test<T>(input_file_path);

        AudioFile<T> speed(std::get<1>(tuple));

        speed.setSampleRate(std::get<1>(tuple).getSampleRate() * 2.0);

        return {std::get<0>(tuple), speed};
    }
}

namespace algo
{

template <class It>
int lcs(It x_begin, It x_end, It y_begin, It y_end)
{
    auto m = std::distance(x_begin, x_end);
    auto n = std::distance(y_begin, y_end);


    std::vector<std::vector<int>> L(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {

            if (i == 0 || j == 0)
                L[i][j] = 0;

            else
            {
                auto[x, y] = std::make_tuple(x_begin, y_begin);
                std::advance(x, i-1); std::advance(y, j-1);

                if ( *x == *y )
                    L[i][j] = std::max( std::max( L[i][j-1], L[i-1][j] ), L[i-1][j-1] ) + 1;
                else
                    L[i][j] = std::max( L[i-1][j], L[i][j-1] );
            }

        }
    }

    return L[m][n];
}

}
