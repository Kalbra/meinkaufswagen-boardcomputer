#ifndef DEBUG_H
#define DEBUG_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include "backend.h"

class Debug : public QWidget
{
    Q_OBJECT
public:
    Debug(BackEnd *backend);

signals:

public slots:
};

#endif // DEBUG_H
