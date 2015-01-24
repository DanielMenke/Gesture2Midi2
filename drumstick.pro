
HEADERS += \
    midiinput.h \
    midioutput.h


win32 {
    SOURCES += \
        winmidiinput.cpp \
        winmidioutput.cpp
    LIBS += -lwinmm
}
macx {
    HEADERS += maccommon.h # ../drumstick/macmidiinput.h ../drumstick/macmidioutput.h
    SOURCES += \
        macmidiinput.cpp \
        macmidioutput.cpp \
        maccommon.cpp

    LIBS += -framework CoreMidi -framework CoreFoundation
}
