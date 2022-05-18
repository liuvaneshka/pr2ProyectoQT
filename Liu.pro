QT       += core gui

TARGET = main
TEMPLATE = app

SOURCES += main.cpp\
    GUI/mainwindow.cpp \
    Class/cliente.cpp \
    GUI/formdatoscliente.cpp \
    File/archivocliente.cpp \
    GUI/formcedulacliente.cpp \
    GUI/formregistrarprendas.cpp \
    Class/prenda.cpp \
    GUI/formnuevaprenda.cpp \
    File/archivoprenda.cpp \
    GUI/formseleccionprenda.cpp \
    Class/factura.cpp \
    File/archivofactura.cpp \
    GUI/formbuscarfactura.cpp \
    GUI/visorfactura.cpp \
    GUI/formedicionfacturas.cpp

HEADERS  += GUI/mainwindow.h \
    Class/cliente.h \
    GUI/formdatoscliente.h \
    File/archivotexto.h \
    File/archivocliente.h \
    GUI/formcedulacliente.h \
    GUI/formregistrarprendas.h \
    Class/prenda.h \
    GUI/formnuevaprenda.h \
    File/archivoprenda.h \
    GUI/formseleccionprenda.h \
    Class/factura.h \
    iva.h \
    File/archivofactura.h \
    GUI/formbuscarfactura.h \
    GUI/visorfactura.h \
    GUI/formedicionfacturas.h

FORMS    += GUI/mainwindow.ui \
    GUI/formdatoscliente.ui \
    GUI/formcedulacliente.ui \
    GUI/formregistrarprendas.ui \
    GUI/formnuevaprenda.ui \
    GUI/formseleccionprenda.ui \
    GUI/formbuscarfactura.ui \
    GUI/visorfactura.ui \
    GUI/formedicionfacturas.ui

OTHER_FILES += \
    PendientePorHacer.txt \
    formato_factura.html

RESOURCES += \
    recursos.qrc














