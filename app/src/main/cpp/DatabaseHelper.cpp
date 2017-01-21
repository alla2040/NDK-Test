#include <jni.h>
#include <vector>
#include <sstream>
#include "sqlite/sqlite3.h"

#include "DatabaseHelper.h"

using namespace std;

const char *databaseName = "weather.db";
const char* tableName = "cities";

#define DB_FILE "/data/data/com.alla.myweatherndk/weather.db"

vector<CityWeather> citiesFromDb;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


static int callbackSelect(void *NotUsed, int numberOfColumns, char **arrayOfFields, char **columnNames) {
    std::vector<CityWeather>::iterator it;
    for (int i = 0; i < numberOfColumns; i++) {
        CityWeather cityWeather(*arrayOfFields[0], arrayOfFields[1]);
        citiesFromDb.insert(it, cityWeather);
        printf("%s = %s\n", columnNames[i], arrayOfFields[i] ? arrayOfFields[i] : "NULL");
    }
    return 0;
}


bool createTable() {

    /* Open database */
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_open(databaseName, &db);
    if (rc != SQLITE_OK) {
        //Can't open database/
        sqlite3_open_v2(DB_FILE, &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
    }

    /* Create SQL statement */
    const char *createQuery =
            "CREATE TABLE IF NOT EXISTS cities (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT);";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, createQuery, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        sqlite3_free(zErrMsg);
        return false;
    }
    sqlite3_close(db);
    return true;
}

bool insertToDb(CityWeather *pCityWeather) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    /* Open database */
    rc = sqlite3_open(databaseName, &db);
    if (rc) {
        sqlite3_open_v2(DB_FILE, &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
    }

    const char *pCityName = pCityWeather->getName().c_str();
    char insertQuery[50];
    strcpy (insertQuery,"INSERT INTO cities (name) VALUES ('");
    strcat (insertQuery, pCityName);
    strcat (insertQuery, "');");
    puts (insertQuery);

    delete pCityWeather;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, insertQuery, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return true;
}

bool retrieveCityFromDb(int id) {

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char *data = "Callback function called";

    /* Open database */
    rc = sqlite3_open(databaseName, &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return false;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sql = (char *) "SELECT * from COMPANY";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callbackSelect, (void *) data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return false;
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);

    return true;
}

vector<CityWeather> getCities(){
    return citiesFromDb;
}





