#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QPalette>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QTextDocumentWriter>
#include <QMenuBar>
#include <QIcon>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
     bool saved;
     QColor foregroundColor;
     QColor backgroundColor;
     int colors [17][3]={{0, 0, 0},
     {64, 64, 64},
     {255, 0, 0},
     {255, 106, 0},
     {255, 216, 0},
     {182, 255, 0},
     {76, 255, 0},
     {0, 255, 33},
     {0, 255, 144},
     {0, 255, 255},
     {0, 148, 255},
     {0, 38, 255},
     {72, 0, 255},
     {178, 0, 255},
     {255, 0, 220},
     {255, 0, 110},
     {255, 255, 255}};
    QString fileName;


    ~MainWindow();
private slots:
    void enablePasteee();
    void setItalic();
    void setUnderline();
    void setBold();
    void setSize(int size);
    void setAlignLeft();
    void setAlignRight();
    void setAlignCenter();
    void setJustify();
    void colorHandle();
    void backColorHandle();
    void setFont(QFont f);
    void undo();
    void redo();
    void exit();
    void copy();
    void paste();
    void cut();
    void selectAll();
    void save();
    void load();

    void on_Find_clicked();

    void on_findButton_clicked();

    void on_findPreviousButton_clicked();

    void on_foregroundCombo_destroyed();

    void on_foregroundCombo_highlighted(const QString &arg1);

    void on_foregroundCombo_currentIndexChanged(int index);

    void on_backgroundCombo_currentIndexChanged(int index);

    void on_forecolor_clicked();

    void on_backcolor_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
