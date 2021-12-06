QT       += core gui multimedia sql printsupport serialport network
QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DuMesengerConnectionDialog.cpp \
    EMPLOYE.cpp \
    arduino.cpp \
    connection.cpp \
    contrat.cpp \
    don.cpp \
    donneur.cpp \
    dossiermedical.cpp \
    emploi_du_temps.cpp \
    gestion_fatma.cpp \
    health.cpp \
    machine.cpp \
 main.cpp \
    mainwindow.cpp \
    medicaments.cpp \
    partenaire.cpp \
    patient.cpp \
    qcustomplot.cpp \
    reservation.cpp \
    smtp.cpp \
    tableprinter.cpp \
    tache.cpp \
    widget.cpp

HEADERS += \
    gestion_fatma.h \
    reservation.h \
    DuMesengerConnectionDialog.h \
    EMPLOYE.h \
    arduino.h \
    connection.h \
    contrat.h \
    don.h \
    donneur.h \
    dossiermedical.h \
    emploi_du_temps.h \
    health.h \
    machine.h \
    mainwindow.h \
    medicaments.h \
    partenaire.h \
    patient.h \
    qcustomplot.h \
    reservation.h \
    smtp.h \
    tableprinter.h \
    tache.h \
    widget.h

FORMS += \
    DuMesengerConnectionDialog.ui \
    gestion_fatma.ui \
    health.ui \
    mainwindow.ui \
    widget.ui

QMAKE_CXXFLAGS += -std=gnu++11

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressource.qrc \
    tanslate.qrc

DISTFILES += \
    fermlia.png
