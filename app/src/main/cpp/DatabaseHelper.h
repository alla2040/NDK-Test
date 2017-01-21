#ifndef MYWEATHERNDK_DATABASEHELPER_H
#define MYWEATHERNDK_DATABASEHELPER_H

#include <jni.h>
#include <string>



class CityWeather{
private:
    int id;
    std::string name;
public:

    CityWeather() { }

    CityWeather(int id, const std::string &name) : id(id), name(name) {
    }

    // with const we guarantee that the method doesn't modify class fields
    // it shows that the method is constant
    int getId() const {
        return id;
    }

    void setId(int id) {
        CityWeather::id = id;
    }

    //1st const - Would allow you to return a constant reference to a member variable
    //& - This is useful if you do not wish a copy to be returned, and be
    // guaranteed that the value returned is non-null
    const std::string &getName() const {
        return name;
    }

    //const in method's parameter - переданный параметр не будет изменен
    void setName(const std::string &name) {
        // or this -> name = name;
        CityWeather::name = name;
    }
};

bool createTable();
bool insertToDb(CityWeather *cityWeather);
bool retrieveCityFromDb(int id);


#endif //MYWEATHERNDK_DATABASEHELPER_H
