#include "microphonemanager.h"
#include <stdio.h>


void MicrophoneManager::RecordAudio()
{
    destinationFile.setFileName("testrec.raw");
    destinationFile.open( QIODevice::WriteOnly | QIODevice::Truncate );

    QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);
    }

    audio = new QAudioInput(format, parent);
    //connect(audio, SIGNAL(stateChanged(QAudio::State)), parent, SLOT(handleStateChanged(QAudio::State)));
    audio->start(&destinationFile);
}

int MicrophoneManager::RawToWavConvert(const char *rawfn, const char *wavfn, long frequency) {
   long chunksize=0x10;

   struct
   {
       unsigned short    wFormatTag;
       unsigned short    wChannels;
       unsigned long     dwSamplesPerSec;
       unsigned long     dwAvgBytesPerSec;
       unsigned short    wBlockAlign;
       unsigned short    wBitsPerSample;
   } fmt;

   FILE *raw = fopen(rawfn,"rb");
   if(!raw)
       return -2;

   fseek(raw, 0, SEEK_END);
   long bytes = ftell(raw);
   fseek(raw, 0, SEEK_SET);

   long samplecount = bytes/2;
   long riffsize    = samplecount*2+0x24;
   long datasize    = samplecount*2;

   FILE *wav=fopen(wavfn,"wb");
   if(!wav)
   {
       fclose(raw);
       return -3;
   }

   fwrite( "RIFF",     1, 4, wav );
   fwrite( &riffsize,  4, 1, wav );
   fwrite( "WAVEfmt ", 1, 8, wav );
   fwrite( &chunksize, 4, 1, wav );

   fmt.wFormatTag = 1;      // PCM
   fmt.wChannels  = 1;      // MONO
   fmt.dwSamplesPerSec  = frequency*1;
   fmt.dwAvgBytesPerSec = frequency*1*2; // 16 bit
   fmt.wBlockAlign      = 2;
   fmt.wBitsPerSample   = 8;

   fwrite( &fmt,      sizeof(fmt), 1, wav );
   fwrite( "data",    1,           4, wav );
   fwrite( &datasize, 4,           1, wav );
   short buff[1024];
   while( !feof(raw) )
   {
         int cnt=fread(buff,2,1024,raw);
         if( cnt == 0 )
             break;
         fwrite(buff,2,cnt,wav);
   }
   fclose( raw );
   fclose( wav );
}

void MicrophoneManager::stopRecording()
{
    audio->stop();
    destinationFile.close();
    delete audio;
    RawToWavConvert("testrec.raw", "testrec.wav", 8000);
}
