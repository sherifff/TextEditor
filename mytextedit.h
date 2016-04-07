#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class MyTextEdit : public QWidget
{
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget *parent = 0);
    ~MyTextEdit();

signals:

public slots:
};

#endif // MYTEXTEDIT_H
