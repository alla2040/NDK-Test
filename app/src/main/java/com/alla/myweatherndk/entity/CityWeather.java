package com.alla.myweatherndk.entity;


public class CityWeather {
    private int id;
    private String name;

    public CityWeather() {
    }

    public CityWeather(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
