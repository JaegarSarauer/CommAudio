#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <QAudioFormat>
#include <QObject>
#include <QFile>
#include <QThread>
#include <QAudioOutput>
#include <QDebug>

#include <inttypes.h>

#include "circularbuffer.h"
#include "audioplaythread.h"
#include "audiothread.h"

class AudioManager : public QObject
{
    Q_OBJECT
public:
    AudioManager(QObject * p) : parent(p) {
        audio = new QAudioOutput(QAudioFormat(), p);
    }

    QIODevice * playAudio();
    bool setupAudioPlayer(QFile * file);
    void setVolume(double volume);
    void stopAudio();
    void pauseAudio();
    void unpauseAudio();
    bool isPaused();
    bool isPlaying();

    ~AudioManager();


    QIODevice *device;

private:
    bool PAUSED = false;
    bool PLAYING = false;
    QAudioFormat format;
    QAudioOutput *audio;
    QObject *parent;
    QFile *file;
    double constantVolume = 1.0;
    CircularBuffer * audioBuf;
    AudioPlayThread * bufferListener;
    AudioThread *deviceListener;


signals:
    void finishedLoading();
    void finishedReading();
    void finishedWriting();

private slots:
    void loadDataIntoBuffer();
    void writeDataToDevice();
    void playNextSong();
};

typedef struct  WAV_HEADER
{
    /* RIFF Chunk Descriptor */
    uint8_t         RIFF[4];        // RIFF Header Magic header
    uint32_t        ChunkSize;      // RIFF Chunk Size
    uint8_t         WAVE[4];        // WAVE Header
    /* "fmt" sub-chunk */
    uint8_t         fmt[4];         // FMT header
    uint32_t        Subchunk1Size;  // Size of the fmt chunk
    uint16_t        AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
    uint16_t        NumOfChan;      // Number of channels 1=Mono 2=Sterio
    uint32_t        SamplesPerSec;  // Sampling Frequency in Hz
    uint32_t        bytesPerSec;    // bytes per second
    uint16_t        blockAlign;     // 2=16-bit mono, 4=16-bit stereo
    uint16_t        bitsPerSample;  // Number of bits per sample
    /* "data" sub-chunk */
    uint8_t         Subchunk2ID[4]; // "data"  string
    uint32_t        Subchunk2Size;  // Sampled data length
} wav_hdr;

#endif // AUDIOMANAGER_H
