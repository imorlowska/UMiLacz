# Add more folders to ship with the application, here
folder_01.source = qml/UML
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

QMAKE_CXXFLAGS += -std=c++11

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    qobjectlistmodel.cpp \
    functionsmodel.cpp \
    ../umlType.cpp \
    ../umlFunction.cpp \
    ../umlClass.cpp \
    ../umlAttribute.cpp \
    ../typedefs.cpp \
    qfunction.cpp \
    qclass.cpp \
    attributesmodel.cpp \
    qattribute.cpp \
    qdiagram.cpp \
    classesmodel.cpp \
    ../umlDiagram.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    qobjectlistmodel.h \
    functionsmodel.h \
    ../umlType.h \
    ../umlFunction.h \
    ../umlClass.h \
    ../umlAttribute.h \
    ../typedefs.h \
    qfunction.h \
    qclass.h \
    attributesmodel.h \
    qattribute.h \
    qdiagram.h \
    classesmodel.h \
    ../umlDiagram.h


