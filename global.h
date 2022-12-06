#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QDir>

using namespace std;

namespace Path
{
    // Global Absolute path
    const QString DB_PATH = "C:/Users/jaspl/VS Projects/Bulk-Club-Project/BulkClubProject.db";

    // Relative path
    const QString DB_PATH_RELATIVE = "/Bulk-Club-Project/BulkClubProject.db";

    // Truncate path build into working directory
    QString getDBPath();
};

#endif
