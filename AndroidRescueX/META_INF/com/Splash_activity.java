package com.rescueX.Sanidhya;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import androidx.appcompat.app.AppCompatActivity;

public class SplashActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        // Display the splash screen for a few seconds
        new Handler().postDelayed(() -> {
            // Start the MainActivity after the splash screen
            Intent intent = new Intent(SplashActivity.this, MainActivity.class);
            startActivity(intent);
            finish(); // Close the splash activity
        }, 3000); // Delay in milliseconds (e.g., 3000ms = 3 seconds)
    }
}
