#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAstroid_clicked()
{
    ui->renderArea->setShape(RenderArea::Astroid);
    ui->renderArea->repaint();

    update_ui();
}

void MainWindow::on_btnCycloid_clicked()
{
    ui->renderArea->setShape(RenderArea::Cycloid);
    ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHuygens_clicked()
{
    ui->renderArea->setShape(RenderArea::HuygensCycloid);
    ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHypo_clicked()
{
    ui->renderArea->setShape(RenderArea::HypoCycloid);
    ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnLine_clicked()
{
    ui->renderArea->setShape(RenderArea::Line);
    ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    ui->renderArea->setScale(scale);
}

void MainWindow::update_ui()
{
    ui->spinScale->setValue( ui->renderArea->scale() );
    ui->spinInterval->setValue(ui->renderArea->interval());
    ui->spinCount->setValue(ui->renderArea->stepCount());
}

void MainWindow::on_spinInterval_valueChanged(double interval)
{
    ui->renderArea->setInterval(interval);
}

void MainWindow::on_spinCount_valueChanged(int count)
{
    ui->renderArea->setStepCount(count);
}

void MainWindow::on_btnBackground_clicked()
{
    ui->renderArea->setBackgroundColor(QColorDialog::getColor(ui->renderArea->backgroundColor(), this, tr("Select Color")));
}

void MainWindow::on_btnLineColor_clicked()
{
    ui->renderArea->setShapeColor(QColorDialog::getColor(ui->renderArea->shapeColor(), this, tr("Select Color")));
}
