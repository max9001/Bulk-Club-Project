#include "global.h"

QString Path::getDBPath()
{
    QString curPath = QDir::currentPath();
    int pos = curPath.lastIndexOf(QChar('/'));
    
    return curPath.left(pos) + DB_PATH_RELATIVE;
}