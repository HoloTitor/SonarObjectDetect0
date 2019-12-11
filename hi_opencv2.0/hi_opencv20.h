#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_hi_opencv20.h"
#include <QtWidgets/QMainWindow>
#include <qlineedit.h>
#include<QGraphicsScene>  
#include<QGraphicsView>                 //graphicsview��
#include<opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>  //opencv����
#include <qfiledialog.h>                //getopenfilename ������
#include <qlabel.h>  //label��
#include <opencv2/highgui/highgui_c.h>
//#include "opencv2/text.hpp"
#include<vector>
#include <iostream>
#include <Open2.h>

class hi_opencv20 : public QMainWindow
{
	Q_OBJECT

public:
	hi_opencv20(QWidget *parent = Q_NULLPTR);
	double t, h1, w1;
	int i = -1, j = 1;
	RNG rng;
	QString temple;
	int match_method;
	//QLabel label;

	int image_fit(Mat a, double m, double n);
	void match();


private slots:
	void open();
	void save();

	void on_blur();
	void on_gaussian();
	void on_median();
	void on_Bilateral();

	void on_slider_1();
	void on_slider_2();


	//��̬�任
	void on_erode();
	void on_dilate();
	void on_opening();
	void on_closing();
	void on_MG();
	void on_blackhat();
	void on_tophat();

	//ͼ�����
	void on_scale();
	void on_rotate();
	void on_L2R();
	void on_T2D();
	void on_pyr();

	//��Ե���
	void on_Sobel();
	void on_Laplace();
	void on_Canny();
	void on_HoughLines();
	void on_HoughCircles();
	void on_findContours();


	//ֱ��ͼ
	void on_zhione_show();
	void on_zhitwo_show();
	void on_zhithree_show();

	//Ŀ�궨λ
	void on_convexHull();
	void on_rectcircle();
	void on_fitEllipse();
	//ģ��ƥ��
	void on_open2();
	void on_receive(QString);
	void on_match1();
	void on_match2();
	void on_match3();
	void on_match4();
	void on_match5();
	void on_match6();
	//����Ӧ��
	void objectDetect();
	/*
	void textDetect();
	void on_threshold();
	void on_copyMakeBorder();
	void flawDetect();
	//init
	*/

	

	void on_init();


private:
	String fPth;
	int portion;

	Ui::hi_opencv20Class ui;
	Mat image;//��ʾ�ڵ�һ����
	Mat image1;//��ʾ�ڵڶ�����
	Mat image2;//ԭͼ
	Mat image3;//ģ��ͼ
	QLabel *label, *label_2;
	//��Ե���Ĭ�ϲ���
	int i_by=3;

	Open2 *open2;
};
