#include "fba_game_input_config_store.h"

//== Method definition


FBAGameInputConfigStore::FBAGameInputConfigStore()
{

}

FBAGameInputConfigStore::FBAGameInputConfigStore(QString filePath)
{
    this->filePath = filePath;
}

FBAGameInputConfigStore::~FBAGameInputConfigStore()
{

}

void FBAGameInputConfigStore::setFilePath(QString filePath)
{
    this->filePath = filePath;
}

int FBAGameInputConfigStore::parseInputConfig()
{

}

bool FBAGameInputConfigStore::setMapping(VKey p1k, VKey p2k)
{
    this->playerMapping.insert(p1k, p2k);
}

VKey FBAGameInputConfigStore::operator[](const VKey p1k)
{
    if (this->playerMapping.contains(p1k)) return this->playerMapping[p1k];
    else return 0x0;
}

VKey FBAGameInputConfigStore::operator()(const VKey p2k)
{
    if (this->playerMapping.values.contains(p2k)) return this->playerMapping.key(p2k);
    else return 0x0;
}
