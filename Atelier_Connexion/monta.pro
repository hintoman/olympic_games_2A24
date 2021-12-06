QT       += core gui sql network charts multimedia multimediawidgets
QT       += core gui sql \
    quick
QT += sql
QT += core
QT += serialport
QT += charts

QT += printsupport
QT += svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    athlete.cpp \
    connexion.cpp \
    dialog_sponsor.cpp \
    employes.cpp \
    evenement.cpp \
    exportexcelobject.cpp \
    gestion_amira.cpp \
    gestion_fatma.cpp \
    gestion_mahdi.cpp \
    gestion_montasar.cpp \
    gestion_yessin.cpp \
    historique.cpp \
    historique1.cpp \
    mailing.cpp \
    main.cpp \
    mainwindow.cpp \
    maps.cpp \
    notif.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    reclamation.cpp \
    smtp.cpp \
    sponsor.cpp \
    stat_combo.cpp \
    terrain.cpp \
    video.cpp

HEADERS += \
    arduino.h \
    athlete.h \
    connexion.h \
    dialog_sponsor.h \
    employes.h \
    evenement.h \
    exportexcelobject.h \
    gestion_amira.h \
    gestion_fatma.h \
    gestion_mahdi.h \
    gestion_montasar.h \
    gestion_yessin.h \
    historique.h \
    historique1.h \
    mailing.h \
    mainwindow.h \
    maps.h \
    notif.h \
    qcustomplot.h \
    qrcode.hpp \
    reclamation.h \
    smtp.h \
    sponsor.h \
    stat_combo.h \
    terrain.h \
    video.h

FORMS += \
    dialog_sponsor.ui \
    form.ui \
    gestion_amira.ui \
    gestion_fatma.ui \
    gestion_mahdi.ui \
    gestion_montasar.ui \
    gestion_yessin.ui \
    mainwindow.ui \
    maps.ui \
    stat_combo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


