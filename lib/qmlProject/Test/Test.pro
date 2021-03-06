# Add more folders to ship with the application, here
folder_01.source = qml/Test
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    qml/Test/ColorPicker.qml \
    qml/Test/HelloWorld.qml \
    qml/Test/SmartHome/HTabBarLearn.qml \
    qml/Test/voicecall/ActiveCallPortrait.qml \
    qml/Test/Test/EPDelegate_1.qml


