#pragma once

#include <QDialog>
#include "ui_Open2.h"
#include <qmessagebox.h>
#include <qlineedit.h>
#include<QGraphicsScene>  
#include<QGraphicsView>                 //graphicsview类
#include<opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>  //opencv申明
#include <qfiledialog.h>                //getopenfilename 类申明
#include <qlabel.h>  //label类
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
