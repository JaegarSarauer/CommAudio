#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include "networkmanager.h"

class FileManager : public QObject
{
    Q_OBJECT
public:
    FileManager(NetworkManager * nManager);
    bool requestFile(const char * fileName);

public slots:
    void writeToFile(char * data, int length);
    void checkBuffer();
private:
    NetworkManager * networkManager;
    FILE * fp;
};

#endif // FILEMANAGER_H
