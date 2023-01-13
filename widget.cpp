#include "widget.h"
#include "ui_widget.h"
#include <QList>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    i = 0;
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addItemBtn_clicked()
{
    i++;
    ui->listWidget->addItem("Item" + QString::number(i));
}


void Widget::on_deleteItemBtn_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}


void Widget::on_selecItemBtn_clicked()
{
    QList<QListWidgetItem *> listItem = ui->listWidget->selectedItems();
    for(size_t i = 0; i < listItem.size(); i++) {
        qDebug() << "Slected item: " << listItem.at(i) << ", the row id: "
                 << ui->listWidget->row(listItem.at(i));
    }
}

