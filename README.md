# Traffic Light Controller Project
This project is a simple Traffic Light Controller application created to explore and understand the Qt framework and its integration with CMake. The application simulates a traffic light sequence with the following behavior:

* Normal Sequence:
  - 30 seconds red light.
  - 2 seconds yellow light (to green).
  - 30 seconds green light.
  - 5 seconds yellow light (to red).
  - Repeats the sequence.

 * Trigger Behavior:
    - If triggered during green, the light immediately switches to yellow, then resumes the normal sequence.
    - If triggered during yellow, it completes the yellow phase before turning red.
    - If triggered during or after red, the light stays red until triggered again, after which the normal sequence resumes.

 ## Goals of the Project    
 * Learn Qt Framework: Gain hands-on experience with Qt for GUI development and signal-slot mechanisms.
 * Understand CMake: Configure and build a Qt project using CMake, exploring the build process.
 * Integrate C++ and QML: Use C++ for the logic (traffic light control) and QML for the user interface.
 * Event Handling: Implement custom event handling (trigger logic) and timer-based state transitions.

 ## Features
 * A clean and simple user interface created using QML.
 * A traffic light visualization with changing colors (red, yellow, green).
 * A trigger button to interrupt the normal light sequence.

 ## Requirements
 * Qt 6.8.1 or newer.
 * CMake 3.19 or newer.
 * A compatible compiler (e.g., MinGW or MSVC on Windows, GCC on Linux).

 This project is a beginner-friendly exploration of Qt and CMake and serves as a foundation for understanding how to build GUI applications with event-driven behavior.  
