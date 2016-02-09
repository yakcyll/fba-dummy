#ifndef FBACONFIG_H
#define FBACONFIG_H

#include <QMap>

typedef unsigned char VKey;

class FBAGameInputConfigStore {
public:
    explicit FBAGameInputConfigStore();
    ~FBAGameInputConfigStore();

    void setFilePath(QString);
    bool parseInputConfig();

    bool setMapping(VKey, VKey);
    VKey operator[](const VKey);

private:
    QString filePath;
    QMap<VKey, VKey> playerMapping;
};

#endif // FBACONFIG_H
