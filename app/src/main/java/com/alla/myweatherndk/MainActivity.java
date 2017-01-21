package com.alla.myweatherndk;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Toast;

import com.alla.myweatherndk.dialog.AddingCityDialogFragment;
import com.alla.myweatherndk.entity.CityWeather;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity implements AddingCityDialogFragment.IOnCityAdded{

    static {
        System.loadLibrary("native-lib");
    }

    private RecyclerView rvCityList;
    private List<CityWeather> cities;
    private CityListAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        if (createTable()){
            Toast.makeText(this, "Table is created", Toast.LENGTH_LONG).show();
        } else {
            Toast.makeText(this, "Table failed to create", Toast.LENGTH_LONG).show();
        }

        rvCityList = (RecyclerView) findViewById(R.id.rvCityList);

        cities = new ArrayList<>();
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        rvCityList.setLayoutManager(layoutManager);
        adapter = new CityListAdapter(cities);
        rvCityList.setAdapter(adapter);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AddingCityDialogFragment.newInstance().show(getSupportFragmentManager(),
                        AddingCityDialogFragment.class.getSimpleName());
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();

    }

    @Override
    public void onCityAdded(String cityName) {
        insertCity(cityName);

    }


    public native boolean createTable();
    public native boolean insertCity(String cityName);
    public native boolean insertCity(String cityName);
}
