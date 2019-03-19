#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAstroid_clicked()
{
    ui->renderArea->setShape(RenderArea::Astroid);
    ui->renderArea->repaint();
}

void MainWindow::on_btnCycloid_clicked()
{
    ui->renderArea->setShape(RenderArea::Cycloid);
    ui->renderArea->repaint();
}

void MainWindow::on_btnHuygens_clicked()
{
    ui->renderArea->setShape(RenderArea::HuygensCycloid);
    ui->renderArea->repaint();
}

void MainWindow::on_btnHypo_clicked()
{
    ui->renderArea->setShape(RenderArea::HypoCycloid);
    ui->renderArea->repaint();
}

void MainWindow::on_btnLine_clicked()
{
    ui->renderArea->setShape(RenderArea::Line);
    ui->renderArea->repaint();
}
