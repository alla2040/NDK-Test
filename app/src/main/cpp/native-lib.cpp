#include <jni.h>
#include "DatabaseHelper.h"


extern "C"
bool Java_com_alla_myweatherndk_MainActivity_createTable(JNIEnv *env, jobject /* this */) {
    return createTable();
}

extern "C"
bool Java_com_alla_myweatherndk_MainActivity_insertCity(JNIEnv *env, jobject, jstring cityName) {
    CityWeather *pCityWeather = new CityWeather();
    const char *cityNameJni = env->GetStringUTFChars(cityName, NULL);
    pCityWeather->setName(cityNameJni);
    return insertToDb(pCityWeather);
}

extern "C"
bool Java_com_alla_myweatherndk_MainActivity_getCities(JNIEnv *env, jobject) {
    CityWeather *pCityWeather = new CityWeather();
    const char *cityNameJni = env->GetStringUTFChars(cityName, NULL);
    pCityWeather->setName(cityNameJni);
    return insertToDb(pCityWeather);
}
