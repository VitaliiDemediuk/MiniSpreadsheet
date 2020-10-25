QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    expression_nodes/celllinknode.cpp \
    expression_nodes/binarydividenode.cpp \
    expression_nodes/binaryminusnode.cpp \
    expression_nodes/binarymultiplynode.cpp \
    expression_nodes/binaryoperatornode.cpp \
    expression_nodes/binaryplusnode.cpp \
    expression_nodes/binarypowernode.cpp \
    expression_nodes/decfunctionnode.cpp \
    expression_nodes/incfunctionnode.cpp \
    expression_nodes/numbernode.cpp \
    expression_nodes/unaryminusnode.cpp \
    expression_nodes/unaryoperatornode.cpp \
    expression_nodes/unaryplusnode.cpp \
    lexer/lexer.cpp \
    lexer/token.cpp \
    main.cpp \
    mainwindow.cpp \
    parser/parser.cpp

HEADERS += \
    expression_nodes/celllinknode.h \
    expression_nodes/binarydividenode.h \
    expression_nodes/binaryminusnode.h \
    expression_nodes/binarymultiplynode.h \
    expression_nodes/binaryoperatornode.h \
    expression_nodes/binaryplusnode.h \
    expression_nodes/binarypowernode.h \
    expression_nodes/decfunctionnode.h \
    expression_nodes/functionnode.h \
    expression_nodes/incfunctionnode.h \
    expression_nodes/numbernode.h \
    expression_nodes/node.h \
    expression_nodes/unaryminusnode.h \
    expression_nodes/unaryoperatornode.h \
    expression_nodes/unaryplusnode.h \
    lexer/lexer.h \
    lexer/token.h \
    mainwindow.h \
    parser/parser.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

INCLUDEPATH += \
    lexer \
    expression_nodes \
    parser
