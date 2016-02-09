#ifndef FBACONFIG_H
#define FBACONFIG_H

#include <QMap>

typedef unsigned char VKey;

class FBAGameInputConfigStore {
public:
    explicit FBAGameInputConfigStore();
    explicit FBAGameInputConfigStore(QString filePath);
    ~FBAGameInputConfigStore();

    void setFilePath(QString filePath);
    int parseInputConfig();

    bool setMapping(VKey p1k, VKey p2k);
    VKey operator[](const VKey p1k);
    VKey operator()(const VKey p2k); // this is gonna be super confusing LOL

private:
    QString filePath;
    QMap<VKey, VKey> playerMapping;
};

#endif // FBACONFIG_H
