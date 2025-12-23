## 💧 Smart Water Leakage Detection System

This Arduino-based project is a Smart Water Leakage Detection System that identifies water leakage in real-time and provides timing details and severity indication using LEDs.

🚀 Features

Real-time water leakage detection using an analog water sensor.

Measures how long the leak has been active using microsecond-level precision.

Severity indicator using two LEDs:

🔴 High Severity (strong leakage signal)

🟡 Low Severity (weaker signal)

Serial interface for command input and status display:

r → Reset system state

t → Show current threshold

🧰 Components Used

Arduino Uno

Water Sensor (analog, connected to A0)

Control Pin (Digital Pin 3)

Red and Yellow LEDs (Pins 13 and 12)

1kΩ Resistor (for voltage divider setup)

Serial Monitor for interaction and debugging

⚙️ How It Works

The system continuously powers and reads from the analog water sensor.

If the sensor value falls below a defined threshold, it marks the start of a leakage.

The system logs how long the leakage is active.

LED indicators:

🔴 Red LED: Sensor value is below 600 (high severity)

🟡 Yellow LED: Sensor value is between 600 and 1000 (moderate severity)

When no leak is detected, both LEDs remain OFF.

📟 Command Interface

Open the Serial Monitor (9600 baud) and use:

r → Resets the flags and leak duration timer.

t → Displays the current analog threshold value.

🧪 Threshold Tuning

Default threshold is set to 1000. Adjust this in the code if your sensor needs calibration.

