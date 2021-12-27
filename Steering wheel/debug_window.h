#ifndef DEBUG_H
#define DEBUG_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QApplication>
#include "backend.h"

class Debug : public QWidget
{
    Q_OBJECT
public:
    Debug(BackEnd *backend);

private slots:
    void enterGas();

private:
    BackEnd *backend;
    QLineEdit *gas_input;

};

#endif // DEBUG_H
