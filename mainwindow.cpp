#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QString s = QString::number(colors[1][0]);
//    ui->textEdit->append(s);
//    colors = new int*[12];
//    for(int i = 0; i < 12; ++i){
//        colors[i] = new int[3];
//    }
    connect(ui->italic,SIGNAL(clicked()),this,SLOT(setItalic()));
    connect(ui->underline,SIGNAL(clicked()),this,SLOT(setUnderline()));
    connect(ui->bold,SIGNAL(clicked()),this,SLOT(setBold()));
    connect(ui->sizebox,SIGNAL(currentIndexChanged(int)),this,SLOT(setSize(int)));
    connect(ui->alignLeft,SIGNAL(clicked()),this,SLOT(setAlignLeft()));
    connect(ui->alignCenter,SIGNAL(clicked()),this,SLOT(setAlignCenter()));
    connect(ui->alignRight,SIGNAL(clicked()),this,SLOT(setAlignRight()));
    connect(ui->justify,SIGNAL(clicked()),this,SLOT(setJustify()));
   // connect(ui->foregroundCombo,SIGNAL(clicked()),this,SLOT(colorHandle()));
    //connect(ui->backColorChooser,SIGNAL(clicked()),this,SLOT(backColorHandle()));
    connect(ui->fontComboBox,SIGNAL(currentFontChanged(QFont)),this,SLOT(setFont(QFont)));
    connect(ui->menuEdit,SIGNAL(triggered()),this,SLOT(enablePasteee()));
    connect(ui->menuEdit,SIGNAL(clicked()),this,SLOT(enablePasteee()));
    connect(ui->menuEdit,SIGNAL(hovered()),this,SLOT(enablePasteee()));
    connect(ui->actionUndo,SIGNAL(triggered()),this,SLOT(undo()));
    connect(ui->actionREdo,SIGNAL(triggered()),this,SLOT(redo()));
    connect(ui->actionCopy,SIGNAL(triggered()),this,SLOT(copy()));
    connect(ui->actionCut,SIGNAL(triggered()),this,SLOT(cut()));
    connect(ui->actionPaste_2,SIGNAL(triggered()),this,SLOT(paste()));
    connect(ui->actionLoad,SIGNAL(triggered()),this,SLOT(load()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->actionSelectAll,SIGNAL(triggered()),this,SLOT(selectAll()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(exit()));
    QIcon *i0 = new QIcon(":/new/colors/0.png");
    QIcon *i1 = new QIcon(":/new/colors/1.png");
    QIcon *i2 = new QIcon(":/new/colors/2.png");
    QIcon *i3 = new QIcon(":/new/colors/3.png");
    QIcon *i4 = new QIcon(":/new/colors/4.png");
    QIcon *i5 = new QIcon(":/new/colors/5.png");
    QIcon *i6 = new QIcon(":/new/colors/6.png");
    QIcon *i7 = new QIcon(":/new/colors/7.png");
    QIcon *i8 = new QIcon(":/new/colors/8.png");
    QIcon *i9 = new QIcon(":/new/colors/9.png");
    QIcon *i10 = new QIcon(":/new/colors/10.png");
    QIcon *i11 = new QIcon(":/new/colors/11.png");
    QIcon *i12 = new QIcon(":/new/colors/12.png");
    QIcon *i13 = new QIcon(":/new/colors/13.png");
    QIcon *i14 = new QIcon(":/new/colors/14.png");
    QIcon *i15 = new QIcon(":/new/colors/15.png");
    QIcon *i16 = new QIcon(":/new/colors/16.png");
    ui->foregroundCombo->setItemIcon(0,*i0);
    ui->foregroundCombo->setItemIcon(1,*i1);
    ui->foregroundCombo->setItemIcon(2,*i2);
    ui->foregroundCombo->setItemIcon(3,*i3);
    ui->foregroundCombo->setItemIcon(4,*i4);
    ui->foregroundCombo->setItemIcon(5,*i5);
    ui->foregroundCombo->setItemIcon(6,*i6);
    ui->foregroundCombo->setItemIcon(7,*i7);
    ui->foregroundCombo->setItemIcon(8,*i8);
    ui->foregroundCombo->setItemIcon(9,*i9);
    ui->foregroundCombo->setItemIcon(10,*i10);
    ui->foregroundCombo->setItemIcon(11,*i11);
    ui->foregroundCombo->setItemIcon(12,*i12);
    ui->foregroundCombo->setItemIcon(13,*i13);
    ui->foregroundCombo->setItemIcon(14,*i14);
    ui->foregroundCombo->setItemIcon(15,*i15);
    ui->foregroundCombo->setItemIcon(16,*i16);
    //----------------------------------------------------
            ui->backgroundCombo->setItemIcon(0,*i16);
            ui->backgroundCombo->setItemIcon(1,*i0);
            ui->backgroundCombo->setItemIcon(2,*i1);
            ui->backgroundCombo->setItemIcon(3,*i2);
            ui->backgroundCombo->setItemIcon(4,*i3);
            ui->backgroundCombo->setItemIcon(5,*i4);
            ui->backgroundCombo->setItemIcon(6,*i5);
            ui->backgroundCombo->setItemIcon(7,*i6);
            ui->backgroundCombo->setItemIcon(8,*i7);
            ui->backgroundCombo->setItemIcon(9,*i8);
            ui->backgroundCombo->setItemIcon(10,*i9);
            ui->backgroundCombo->setItemIcon(11,*i10);
            ui->backgroundCombo->setItemIcon(12,*i11);
            ui->backgroundCombo->setItemIcon(13,*i12);
            ui->backgroundCombo->setItemIcon(14,*i13);
            ui->backgroundCombo->setItemIcon(15,*i14);
            ui->backgroundCombo->setItemIcon(16,*i15);

//    QPixmap pixmap3(":/Editing-Align-Left-icon.png");
//    QIcon leftIcon(pixmap3);
//    ui->alignLeft->setIcon(leftIcon);
//    ui->alignLeft->setIconSize(QSize(25,25));

    saved = false;
    foregroundColor=Qt::black;
    backgroundColor=Qt::white;
    QIcon *if0 = new QIcon(":/new/colors/0f.png");
    QIcon *ib0 = new QIcon(":/new/colors/16b.png");

    ui->forecolor->setIcon(*if0);
    ui->backcolor->setIcon(*ib0);
    fileName ="";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setItalic(){
    QTextCharFormat format;
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    QTextCharFormat d = ui->textEdit->currentCharFormat();

    if( !d.fontItalic()){
        format.setFontItalic(true);
    }else{
        format.setFontItalic(false);
    }
    cursor.mergeCharFormat(format );
    ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::setUnderline(){
    QTextCharFormat format;
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    QTextCharFormat d = ui->textEdit->currentCharFormat();


    if( !d.fontUnderline()){
        format.setFontUnderline(true);
    }else{
        format.setFontUnderline(false);
    }
    cursor.mergeCharFormat(format );
    ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::enablePasteee(){
    ui->textEdit->append("12312432");
    ui->actionPaste_2->setDisabled(ui->textEdit->canPaste());
}

void MainWindow::setBold(){
    QTextCharFormat format;
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    QTextCharFormat d = ui->textEdit->currentCharFormat();

    if( d.fontWeight() == 50){
        format.setFontWeight(99);
    }else{
        format.setFontWeight(50);    }
    cursor.mergeCharFormat(format );
    ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::setSize(int index){
 QString sizeString = ui->sizebox->itemText(index);
 int size = sizeString.toInt();

 QTextCharFormat format;
 QTextCursor cursor = ui->textEdit->textCursor();
 if(!cursor.hasSelection())
     cursor.select(QTextCursor::WordUnderCursor);

 format.setFontPointSize(size);
 cursor.mergeCharFormat(format );
 ui->textEdit->mergeCurrentCharFormat(format);


}

void MainWindow::setAlignLeft(){
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::setAlignCenter(){
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::setAlignRight(){
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::setJustify(){
    ui->textEdit->setAlignment(Qt::AlignJustify);
}

void MainWindow::colorHandle(){

//    if(!openColorFor){
//        foreground = new QColorDialog();
//        foreground->setCurrentColor(foregroundColor);
//        foreground->setOption(QColorDialog::NoButtons);
//        foreground->exec();
//        openColorFor=true;

//    }else{
//          foreground->hide();
//          foregroundColor =  foreground->selectedColor();
//         if( foregroundColor.isValid() ){
//            ui->textEdit->setTextColor(foregroundColor);
//        }
//         openColorFor=false;
//    }

}

void MainWindow::backColorHandle(){
    QColor color = QColorDialog::getColor(Qt::black,this);
    if( color.isValid() ){
        ui->textEdit->setTextBackgroundColor(color);
    }
}

void MainWindow::setFont(QFont font){
    QTextCharFormat format;
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);

    QTextCharFormat oldFormat = cursor.charFormat();
    format.setFont(font);
    format.setFontItalic(oldFormat.fontItalic());
    format.setFontUnderline(oldFormat.fontUnderline());
    format.setFontPointSize(oldFormat.fontPointSize());
    format.setFontWeight(oldFormat.fontWeight());
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::undo(){
   ui->textEdit->undo();
}

void MainWindow::redo(){
    ui->textEdit->redo();
}
void MainWindow::copy(){
    ui->textEdit->copy();
}

void MainWindow::paste(){
    ui->textEdit->paste();
}
void MainWindow::cut(){
    ui->textEdit->cut();
}
void MainWindow::save(){
  // save
    if( !saved ){
        QString fn = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                                      QString(), tr("SOK-Files (*.sok)"));
            if (fn.isEmpty())
                return ;
            if (! (fn.endsWith(".sok", Qt::CaseInsensitive) ) )
                fn += ".sok"; // default

            fileName= fn;
            saved=true;
    }
    if (fileName.isEmpty()){
        saved = false;
        save();
    }

    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
//        if(ui->textEdit->size()==0){

//        }
        stream<<ui->textEdit->toHtml()<<endl;
        file.close();
    }


//        QTextDocumentWriter writer(fileName);
//        bool success = writer.write(ui->textEdit->document());
//        if (success)
//            ui->textEdit->document()->setModified(false);
}
void MainWindow::selectAll(){
    ui->textEdit->selectAll();
}
void MainWindow::exit(){
    // exit
}
void MainWindow::load(){
    // load
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                                 QString(), tr("SOK-Files (*.sok);"));
    QFile file(fn);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    QString text = "";
    while(!in.atEnd()) {
        text.append(in.readLine());
    }
    file.close();
    ui->textEdit->setHtml(text);
}






void MainWindow::on_Find_clicked()
{
    ui->textEdit->append("aofmaklsmflska amdfaslkf");
}

void MainWindow::on_findButton_clicked()
{
    if(ui->findPreviousButton->isEnabled() == false)
          {
              ui->textEdit->moveCursor(QTextCursor::Start);
              ui->statusBar->showMessage("");
        }

          if(ui->textEdit->find(ui->findQuery->text()))
          {
              ui->findPreviousButton->setEnabled(true);
          }else{
              ui->textEdit->moveCursor(QTextCursor::Start);
              ui->findPreviousButton->setEnabled(false);
              ui->statusBar->showMessage("No further search result!");
          }
}

void MainWindow::on_findPreviousButton_clicked()
{
    ui->textEdit->find(ui->findQuery->text(),QTextDocument::FindBackward);
}

void MainWindow::on_foregroundCombo_destroyed()
{

}

void MainWindow::on_foregroundCombo_highlighted(const QString &arg1)
{
}

void MainWindow::on_foregroundCombo_currentIndexChanged(int index)
{
     QColor color(colors[index][0],colors[index][1],colors[index][2],255);
    foregroundColor = QColor(colors[index][0],colors[index][1],colors[index][2],255);
    if( color.isValid() ){
        ui->textEdit->setTextColor(color);
        QString t1=QString::number(index);
        QString t2="f.png";
        QString total=":/new/colors/"+t1+t2;
        QIcon *i = new QIcon(total);
        ui->forecolor->setIcon(*i);
    }
}

void MainWindow::on_backgroundCombo_currentIndexChanged(int index)
{
    int index2=(index+16)%17;
    QColor color(colors[index2][0],colors[index2][1],colors[index2][2],255);
   foregroundColor = QColor(colors[index2][0],colors[index2][1],colors[index2][2],255);
   if( color.isValid() ){
       ui->textEdit->setTextBackgroundColor(color);
       QString t1=QString::number(index2);
       QString t2="b.png";
       QString total=":/new/colors/"+t1+t2;
       QIcon *i = new QIcon(total);
       ui->backcolor->setIcon(*i);
   }

}

void MainWindow::on_forecolor_clicked()
{
     ui->textEdit->setTextColor(foregroundColor);
}

void MainWindow::on_backcolor_clicked()
{
    ui->textEdit->setTextBackgroundColor(backgroundColor);
}
