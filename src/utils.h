#include <cmath>
#include <memory>
#include <algorithm>

#include <iostream>

#include "../midi/include/MidiFile.h"

namespace test
{

std::tuple<std::vector<int>, double> mid_to_vector(const std::string& filename, double min_duration = INTMAX_MAX)
{
    using namespace smf;

    MidiFile midifile;

    midifile.readSmf(filename);

    midifile.doTimeAnalysis();
    midifile.linkNotePairs();

    int track = 1;
    double min = min_duration;  // потом можно "усложнить"
    for (int event = 0; event < midifile[track].size(); ++event) {
        if (midifile[track][event].isNoteOn()) {

            if (midifile[track][event].getDurationInSeconds() < min)
                min = midifile[track][event].getDurationInSeconds();
        }
    }

    std::vector<int> symbol_str;

    for (int event = 0; event < midifile[track].size(); ++event) {
        if (midifile[track][event].isNoteOn()) {

            int number = midifile[track][event].getDurationInSeconds() / min;

            for (int i = 0; i < number; ++i) {
                symbol_str.push_back((int)midifile[track][event][1]);
            }
        }
    }

    return {symbol_str, min};
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
