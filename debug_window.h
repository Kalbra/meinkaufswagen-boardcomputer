#ifndef DEBUG_H
#define DEBUG_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>
#include "backend.h"

class Debug : public QWidget
{
    Q_OBJECT
public:
    Debug(BackEnd *backend);

private:

};

#endif // DEBUG_H
