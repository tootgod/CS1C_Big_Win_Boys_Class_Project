#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderarea.h"
#include <QString>
#include <QInputDialog>
#include <QDir>
#include <QPainter>

int admin = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    RenderArea * renderArea = new RenderArea();
    QVBoxLayout *mainLayout = new QVBoxLayout();
    
    mainLayout->addWidget(renderArea);
    ui->centralWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeMode(int a)
{
    adminMode = a;
    return;
}

bool MainWindow::checkMode()
{
    return adminMode;
}

void MainWindow::on_pushButton_clicked()
{
    test->show();
}

void MainWindow::on_generateReport_clicked()
{
    gene->show();
}

void MainWindow::on_logout_clicked()
{
    ui->WholeScreen->setCurrentIndex(1);
    admin = 0;

}

void MainWindow::on_selectShape_windowTitleChanged(const QString &title)
{

}

void MainWindow::on_selectShape_activated(const QString &arg1)
{

}

void MainWindow::on_selectShape_activated(int index)
{

}

void MainWindow::on_selectShape_currentIndexChanged(int index)
{
    ui->shapeMenu->setCurrentIndex(index);
}

void MainWindow::on_adminLogin_clicked()
{
    bool ok;
       QString text = QInputDialog::getText(this, tr("Enter Admin Password"),
                                            tr("Password:"), QLineEdit::Normal,
                                            QDir::home().dirName(), &ok);
       if (ok && !text.isEmpty())
           if(text == "admin")
           {
               admin = 1;
               ui->WholeScreen->setCurrentIndex(0);
           }
}

void MainWindow::on_guestLogin_clicked()
{
    admin = 0;
    ui->WholeScreen->setCurrentIndex(0);
}

void MainWindow::on_CreateShape_clicked()
{
   /* int h = ui->shapeMenu->currentIndex();
    RenderArea * renderArea = new RenderArea();
    switch (h) {
    case 4:

        break;
    default:
        break;
    }*/
}


