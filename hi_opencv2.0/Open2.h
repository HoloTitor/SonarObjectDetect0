#pragma once

#include <QDialog>
#include "ui_Open2.h"
#include <qmessagebox.h>
#include <qlineedit.h>
#include<QGraphicsScene>  
#include<QGraphicsView>                 //graphicsview��
#include<opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>  //opencv����
#include <qfiledialog.h>                //getopenfilename ������
#include <qlabel.h>  //label��
#include <opencv2/highgui/highgui_c.h>
#include<vector>
#include <iostream>

using namespace std;
using namespace cv;


class Open2 : public QDialog
{
	Q_OBJECT

public:
	Open2(QWidget *parent = Q_NULLPTR);
	~Open2();

	int i = -1;

	QString filename;

private slots:
	void on_open();
	void on_send();

signals:
	void sendsignal(QString);

private:
	Ui::Open2 ui;
	Mat image;
};
