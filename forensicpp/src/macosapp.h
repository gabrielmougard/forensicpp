#pragma once

#include <QApplication>
#include <QFileOpenEvent>

class MacosApplication : public QApplication {
    Q_OBJECT
public:
    MacosApplication(int &argc, char *argv[]) : QApplication(argc, argv) {};
protected:
    bool event(QEvent *event) {
        if (event->type() == QEvent::FileOpen) {
            QString filePath = static_cast<QFileOpenEvent *> (event)->file();
            emit fileOpened(filePath);
        } else {
            return QApplication::event (event);
        }
        return true;
    }
signals:
    void fileOpened(QString filePath);

};