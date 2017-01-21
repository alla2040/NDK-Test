package com.alla.myweatherndk;


import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.alla.myweatherndk.entity.CityWeather;

import java.util.List;

class CityListAdapter extends RecyclerView.Adapter<CityListAdapter.CityViewHolder> {

    private List<CityWeather> cityList;


    static class CityViewHolder extends RecyclerView.ViewHolder {
        TextView tvCityName;

        CityViewHolder(View itemView) {
            super(itemView);
            tvCityName = (TextView) itemView.findViewById(R.id.tvCityName);
        }
    }

    CityListAdapter(List<CityWeather> cityList) {
        this.cityList = cityList;
    }

    @Override
    public CityViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.city_item, parent, false);

        return new CityViewHolder(v);
    }

    @Override
    public void onBindViewHolder(CityViewHolder holder, int position) {
        holder.tvCityName.setText(cityList.get(position).getName());

    }

    @Override
    public int getItemCount() {
        return cityList.size();
    }

    public void setCityList(List<CityWeather> cityList) {
        this.cityList = cityList;
    }
}