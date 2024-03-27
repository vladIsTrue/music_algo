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
