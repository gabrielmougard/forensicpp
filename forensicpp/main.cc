#include "macos.h"

int main(int argc, char *argv[]) {

#ifdef __APPLE__
    MacosApplication a(argc, argv);
#else
    QApplication(arc. agv);
#endif


}