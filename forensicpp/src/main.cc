#include <QApplication>
#include <QCommandLineParser>
#include <QStyleFactory>

#include "appversion.h"
#include "core.h"
#include "customstyle.h"
#include "macosapp.h"
#include "settings.h"
#include "sharedres.h"

#include "lib/action/manager.h"

#include "utils/inputmap.h"
#include "utils/actions.h"


int main(int argc, char *argv[]) {

    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR","0");

#ifdef __APPLE__
    MacOSApplication a(argc, argv);
    // default to "fusion" if available ("macos" has layout bugs, weird comboboxes etc)
    if(QStyleFactory::keys().contains("Fusion"))
        a.setStyle(QStyleFactory::create("Fusion"));
#else
    QApplication a(argc, argv);
    // Use our own style
    a.setStyle(new CustomStyle);
#endif


    QCoreApplication::setOrganizationName("Gabriel Mougard");
    QCoreApplication::setOrganizationDomain("https://github.com/gabrielmougard/forensicpp");
    QCoreApplication::setApplicationName("forensicpp");
    QCoreApplication::setApplicationVersion(appVersion.toString());
    QApplication::setEffectEnabled(Qt::UI_AnimateCombo, false);
    QGuiApplication::setDesktopFileName(QCoreApplication::applicationName() + ".desktop");

#ifdef __GLIBC__
    // default value of 128k causes memory fragmentation issues
    mallopt(M_MMAP_THRESHOLD, 64000);
#endif

    // use custom types in signals
    qRegisterMetaType<ScalerRequest>("ScalerRequest");
    qRegisterMetaType<Script>("Script");
    qRegisterMetaType<std::shared_ptr<Image>>("std::shared_ptr<Image>");
    qRegisterMetaType<std::shared_ptr<Thumbnail>>("std::shared_ptr<Thumbnail>");

    // global application objects
    inputMap = InputMap::getInstance();
    appActions = Actions::getInstance();
    settings = Settings::getInstance();
    scriptManager = ScriptManager::getInstance();
    actionManager = ActionManager::getInstance();
    shrRes = SharedResources::getInstance();

    atexit(saveSettings);

    // parse command args
    QCommandLineParser parser;
    QString appDescription = qApp->applicationName() + " - High Performance image analyser.";
    appDescription.append("\nVersion: " + qApp->applicationVersion());
    appDescription.append("\nLicense: GNU GPLv3");
    parser.setApplicationDescription(appDescription);
    parser.addHelpOption();
    parser.addVersionOption();

    parser.process(a);


    Core core;

#ifdef __APPLE__
    QObject::connect(&a, &MacOSApplication::fileOpened, &core, &Core::loadPath);
#endif

    // wait for event queue to catch up before showing window
    // this avoids white background flicker on windows (or not?)
    qApp->processEvents();
    
    core.showGui();
    return a.exec();
}