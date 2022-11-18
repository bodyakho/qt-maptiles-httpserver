QT -= gui
QT += core httpserver sql

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
        Common/Constants.hpp \
        Common/Enumerations.hpp \
        Common/Logging.hpp \
        Common/ServerAPI.hpp \
        Core/FetchingManager.hpp \
        Core/SettingsManager.hpp \
        Core/TaskManager.hpp \
        Fetchers/SqlDBsTileFetcher.hpp \
        Interfaces/ITask.hpp \
        Interfaces/ITileFetcher.hpp \
        MapTileServer.hpp \
        Network/HttpRouter.hpp \
        Network/HttpServer.hpp \
        Tasks/TileFetchingTask.hpp \
        Types/RouteRule.hpp \
        Types/TileSpec.hpp


SOURCES += \
        Common/ServerAPI.cpp \
        Core/FetchingManager.cpp \
        Core/SettingsManager.cpp \
        Core/TaskManager.cpp \
        Fetchers/SqlDBsTileFetcher.cpp \
        MapTileServer.cpp \
        Network/HttpRouter.cpp \
        Network/HttpServer.cpp \
        Tasks/TileFetchingTask.cpp \
        Types/RouteRule.cpp \
        Types/TileSpec.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

