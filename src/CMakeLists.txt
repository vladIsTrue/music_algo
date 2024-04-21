add_executable(src 
    AudioFile.h

    ../midi/include/Binasc.h
    ../midi/include/MidiEvent.h
    ../midi/include/MidiEventList.h
    ../midi/include/MidiFile.h
    ../midi/include/MidiMessage.h

    ../midi/src/Binasc.cpp
    ../midi/src/MidiEvent.cpp
    ../midi/src/MidiEventList.cpp
    ../midi/src/MidiFile.cpp
    ../midi/src/MidiMessage.cpp

    utils.h
    main.cpp
)
