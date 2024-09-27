package com.rescueX.Sanidhya; // Update this to your package name

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib"); // Load the native library
    }

    // Declare native methods
    public native String getKernelInfo();
    public native void flashZip(String zipPath);
    public native void mountPartition(String partition, String mountPoint);

    private TextView kernelInfoTextView;
    private EditText zipFileInput, partitionInput, mountPointInput;
    private Button flashZipButton, mountPartitionButton, getKernelInfoButton;

    private boolean isFlashed = false; // Track if ZIP has been flashed

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // Set the layout

        initializeUI(); // Initialize UI components
        setupListeners(); // Set up button click listeners
    }

    // Initialize UI components
    private void initializeUI() {
        kernelInfoTextView = findViewById(R.id.kernel_info);
        zipFileInput = findViewById(R.id.zip_file_input);
        partitionInput = findViewById(R.id.partition_input);
        mountPointInput = findViewById(R.id.mount_point_input);
        flashZipButton = findViewById(R.id.flash_zip_button);
        mountPartitionButton = findViewById(R.id.mount_partition_button);
        getKernelInfoButton = findViewById(R.id.get_kernel_info_button);
    }

    // Set up listeners for buttons
    private void setupListeners() {
        flashZipButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                handleFlashZip();
            }
        });

        mountPartitionButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                handleMountPartition();
            }
        });

        getKernelInfoButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                handleGetKernelInfo();
            }
        });
    }

    // Handle flashing ZIP file
    private void handleFlashZip() {
        String zipPath = zipFileInput.getText().toString().trim();
        if (!zipPath.isEmpty()) {
            flashZip(zipPath);
            isFlashed = true;
            kernelInfoTextView.setText("Flashed: " + zipPath);
        } else {
            kernelInfoTextView.setText("Please enter a ZIP file path.");
        }
    }

    // Handle mounting partition
    private void handleMountPartition() {
        if (isFlashed) {
            String partition = partitionInput.getText().toString().trim();
            String mountPoint = mountPointInput.getText().toString().trim();
            if (!partition.isEmpty() && !mountPoint.isEmpty()) {
                mountPartition(partition, mountPoint);
                kernelInfoTextView.setText("Mounted " + partition + " to " + mountPoint);
            } else {
                kernelInfoTextView.setText("Please enter both partition and mount point.");
            }
        } else {
            kernelInfoTextView.setText("Please flash a ZIP file first.");
        }
    }

    // Handle getting kernel info
    private void handleGetKernelInfo() {
        String kernelInfo = getKernelInfo();
        kernelInfoTextView.setText("Kernel Info: " + kernelInfo);
    }
}
