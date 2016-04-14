#include "filereader.h"

void FileReader::startReading()
{
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        data[0] = 1;
        emit error(data, 1);
        return;
    }
    int t = 0;
    for(;;)
    {
        data[0] = 3;
        t = fread(&data[1], 1, DATA_BUFSIZE - 1, fp);
        if (t == 0)
        {
            fclose(fp);
            emit fileDone();
            return;
        }
        emit sendPacket(data, t);
    }
}
