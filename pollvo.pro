#-------------------------------------------------
#
# Project created by QtCreator 2015-03-26T13:36:39
#
#-------------------------------------------------

#QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets gui core sql network
TARGET = pollvo
TEMPLATE = app


SOURCES += main.cpp\
        d_main.cpp \
    signup.cpp \
    login.cpp \
    finaldialog.cpp \
    imagedialog.cpp \
    textdialog.cpp \
    welcomepage.cpp \
    final_image.cpp \
    httprequestworker.cpp \
    generapage.cpp \
    sql.cpp \
    models/model.cpp \
    models/usermodel.cpp

HEADERS  += d_main.h \
    signup.h \
    login.h \
    finaldialog.h \
    imagedialog.h \
    textdialog.h \
    welcomepage.h \
    final_image.h \
    httprequestworker.h \
    generapage.h \
    sql.h \
    models/model.h \
    models/usermodel.h

FORMS    += d_main.ui \
    signup.ui \
    login.ui \
    finaldialog.ui \
    imagedialog.ui \
    textdialog.ui \
    welcomepage.ui \
    final_image.ui \
    generapage.ui

DISTFILES += \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat

RESOURCES += \
    pollvogue.qrc

CONFIG += mobility c++11
MOBILITY =

#QMAKE_CXXFLAGS +=  -std=gnu++ll

#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

#contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
#    ANDROID_EXTRA_LIBS =
#}
