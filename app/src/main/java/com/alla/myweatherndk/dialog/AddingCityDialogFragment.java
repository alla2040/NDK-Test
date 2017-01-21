package com.alla.myweatherndk.dialog;


import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v4.app.DialogFragment;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.EditText;

import com.alla.myweatherndk.R;

public class AddingCityDialogFragment extends DialogFragment {

    private IOnCityAdded onCityAddedListener;

    public interface IOnCityAdded {
        void onCityAdded(String cityName);
    }

    public static AddingCityDialogFragment newInstance() {
        return new AddingCityDialogFragment();
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        onCityAddedListener = (IOnCityAdded) context;
    }

    @NonNull
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        final AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
        builder.setTitle("New city");
        LayoutInflater inflater = getActivity().getLayoutInflater();
        View container = inflater.inflate(R.layout.city_add_dialog_fragment, null);
        final EditText etCityName = (EditText) container.findViewById(R.id.etCityName);

        builder.setView(container);

        builder.setPositiveButton(R.string.ok, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
                onCityAddedListener.onCityAdded(etCityName.getText().toString());
            }
        });

        builder.setNegativeButton(R.string.action_cancel, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        });


        return builder.create();
    }
}
