
#include "opencv2/text.hpp"

#include  "opencv2/highgui.hpp"
#include  "opencv2/imgproc.hpp"
#include "hi_opencv20.h"
#include  <vector>
#include  <iostream>
#include  <iomanip>
#include <QSplashScreen>

using namespace std;
using namespace cv;
using namespace cv::text;


#pragma region //函数声明by WFL
//边缘检测
void m_Sobel(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui);
void m_Laplace(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui);
void m_Canny(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui);
void m_HoughLines(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui);
void m_HoughCircles(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui);
void m_findContours(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui);
//其他（阈值操作、添加边界）
//void m_copyMakeBorder(int ot, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui);
#pragma endregion

void w_convexHull(int j,Mat image,Mat image1,QLabel *label_2, Ui::hi_opencv20Class ui);
void w_rectcircle(int j, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui);
void w_fitEllipse(int j, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui);

//函数声明
//Mat flawDetecting(int size, int area, Mat imgOringin);


hi_opencv20::hi_opencv20(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	QBrush myBrush;
	QPalette palette;
	myBrush = QBrush(Qt::green, Qt::DiagCrossPattern);
	palette.setBrush(QPalette::Text, myBrush);
	ui.textEdit->setPalette(palette);
	ui.textEdit->setStyleSheet("background:black");
	//myBrush = QBrush(Qt::black, Qt::DiagCrossPattern);
	//palette.setBrush(QPalette::background, myBrush);
	//ui.textEdit->setPalette(palette);

	setWindowState(Qt::WindowMaximized);
	setWindowIcon(QIcon(":/hi_opencv20/logo.ico"));
	ui.slider_1->hide();
	ui.slider_2->hide();
	ui.spinBox_1->hide();
	ui.spinBox_2->hide();
	ui.toolBox->hide();
	open2 = new Open2;
	connect(open2, SIGNAL(sendsignal(QString)), this, SLOT(on_receive(QString)));
}

int hi_opencv20::image_fit(Mat a, double m, double n)
{
	double h = a.rows;
	double w = a.cols;
	double p = h / w;
	double q = m / n;
	if (p > q)
	{
		t = m / h;
	}
	else
	{
		t = n / w;
	}
	return t;
}

String qstr2str(QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return String(cdata);
}
QString str2qstr(string str)
{
	return QString::fromLocal8Bit(str.data());
}

void hi_opencv20::open()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{

		//String str  filename.toStdString();//QString字符串中有中文转化成String会有乱码
		String str = qstr2str(filename);//写了一个qstr2str函数用于转化
		fPth = str;
		image = imread(str);
		cvtColor(image, image, COLOR_BGR2RGB);

		image2 = image.clone();

		double m = ui.input->height();
		double n = ui.input->width();
		image_fit(image, m, n);
		h1 = image.rows * t;
		w1 = image.cols* t;
		cv::resize(image, image, Size(w1, h1));
	}
	ui.toolBox->show();
	QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, image.cols*image.channels(), QImage::Format_RGB888);
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(img));
	label->resize(QSize(img.width(), img.height()));
	ui.input->setWidget(label);

	label_2 = new QLabel();
	ui.output->setWidget(label_2);

	ui.actionsave->setEnabled(true);

}

void hi_opencv20::save() {
	//Mat img = imread("D:/1.jpg", 1);
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)")); //选择路径
	string fileAsSave = filename.toStdString();
	cvtColor(image, image, COLOR_RGB2BGR);
	imwrite(fileAsSave, image1);
}

void hi_opencv20::on_slider_1()
{
	int change = 0;
	switch (i)
	{
	case 11:
	{
		int j = ui.slider_1->value();
		int k = ui.slider_2->value();
		cv::blur(image, image1, Size(j, k));
		break;
	}
	case 12:
	{
		int j = ui.slider_1->value();
		cv::GaussianBlur(image, image1, Size(2*j+1, 2*j+1), 0, 0);
		break;
	}
	case 13:
	{
		int j = ui.slider_1->value();
		cv::medianBlur(image, image1, 2*j+1);
		break;
	}
	case 14:
	{
		int j = ui.slider_1->value();
		cv::bilateralFilter(image, image1, j, j * 2, j / 2);
		break;
	}

#pragma region //形态变换
	case 21:
	{
		int j = ui.slider_1->value();
		Mat element = getStructuringElement(MORPH_RECT, Size(2 * j + 1, 2 * j + 1), Point(j, j));
		cv::erode(image, image1, element);
		break;
	}
	case 22:
	{
		int j = ui.slider_1->value();
		Mat element = getStructuringElement(MORPH_RECT, Size(2 * j + 1, 2 * j + 1), Point(j, j));
		cv::dilate(image, image1, element);
		break;
	}
	case 23:
	{
		int j = ui.slider_1->value();
		Mat element = getStructuringElement(MORPH_RECT, Size(2 * j + 1, 2 * j + 1), Point(j, j));
		cv::morphologyEx(image, image1, MORPH_OPEN, element);
		break;
	}
	case 24:
	{
		int j = ui.slider_1->value();
		Mat element = getStructuringElement(MORPH_RECT, Size(2 * j + 1, 2 * j + 1), Point(j, j));
		cv::morphologyEx(image, image1, MORPH_CLOSE, element);
		break;
	}
	case 25:
	{
		int j = ui.slider_1->value();
		Mat element = getStructuringElement(MORPH_RECT, Size(2 * j + 1, 2 * j + 1), Point(j, j));
		cv::morphologyEx(image, image1, MORPH_GRADIENT, element);
		break;
	}
	case 26:
	{
		int j = ui.slider_1->value();
		Mat element = getStructuringElement(MORPH_RECT, Size(2 * j + 1, 2 * j + 1), Point(j, j));
		cv::morphologyEx(image, image1, MORPH_TOPHAT, element);
		break;
	}
	case 27:
	{
		int j = ui.slider_1->value();
		Mat element = getStructuringElement(MORPH_RECT, Size(2 * j + 1, 2 * j + 1), Point(j, j));
		cv::morphologyEx(image, image1, MORPH_BLACKHAT, element);
		break;
	}

#pragma endregion

#pragma region //图像变形
	case 41:
	{
		double jj, hh, ww;
		jj = ui.slider_1->value() / 100.0;
		hh = image2.rows * jj;
		ww = image2.cols * jj;
		cv::resize(image2, image1, Size(ww, hh));
		break;
	}
	case 42:
	{
		Mat rot_mat(2, 3, CV_32FC1);

		Point center = Point(image1.cols / 2, image1.rows / 2);
		//double angle = atof(ui.w3Linex1->text().toStdString().c_str());
		//float anglw1 = ui.w3Line1->text().toDouble();

		double angle = ui.slider_1->value();

		/// 通过上面的旋转细节信息求得旋转矩阵
		rot_mat = getRotationMatrix2D(center, angle, 1);

		/// 旋转已扭曲图像
		warpAffine(image, image1, rot_mat, image1.size());
		break;
	}
#pragma endregion
	
#pragma region //边缘检测
	case 51:
	{
		change = 1;
		i_by =(int)ui.slider_1->value();
		m_Sobel(i_by, image, image1, label_2, ui);
		break;
	}
	case 52:
	{
		change = 1;
		i_by = (int)ui.slider_1->value();
		m_Laplace(i_by, image, image1, label_2, ui);
		break;
	}
	case 53:
	{
		change = 1;
		i_by = (int)ui.slider_1->value();
		m_Canny(i_by, image, image1, label_2, ui);
		break;
	}
	case 54:
	{
		change = 1;
		i_by = (int)ui.slider_1->value();
		m_HoughLines(i_by, image, image1, label_2, ui);
		break;
	}
	case 55:
	{
		change = 1;
		i_by = (int)ui.slider_1->value();
		m_HoughCircles(i_by, image, image1, label_2, ui);
		break;
	}
	case 56:
	{
		change = 1;
		i_by = (int)ui.slider_1->value();
		m_findContours(i_by, image, image1, label_2, ui);
		break;
	}
	case 61:
	{
		change = 1;
		j = ui.slider_1->value();
		w_convexHull(j, image, image1,label_2,ui);
		break;
	}
	case 62:
	{
		change = 1;
		j = ui.slider_1->value();
		w_rectcircle(j, image, image1, label_2, ui);
		break;
	}
	case 63:
	{
		change = 1;
		j = ui.slider_1->value();
		w_fitEllipse(j, image, image1, label_2, ui);
		break;
	}

#pragma endregion
#pragma region //功能应用
	case 57:
	{
		int j = ui.slider_2->value();
		int k= ui.slider_1->value();
		threshold(image, image1, j, 255, k);
		break;
	}
	case 58:
	{
		//进度条1控制阈值操作的type,如果为设定value，则value默认为0；
		change = 1;
		j = ui.slider_1->value();
		//m_copyMakeBorder(j, image, image1, label_2, ui);
		break;
	}
	case 84:
	{
		int size = ui.slider_1->value();
		int area = ui.slider_2->value();
		//image1 = flawDetecting(size, area, image2);
		break;
	}
#pragma endregion


	default:
		break;
	}
	if (change == 0) {
		QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image.channels(), QImage::Format_RGB888);
		label_2 = new QLabel();
		label_2->setPixmap(QPixmap::fromImage(img));
		label_2->resize(QSize(img.width(), img.height()));
		ui.output->setWidget(label_2);
	}
}

void hi_opencv20::on_slider_2()
{
	int change = 0;
	switch (i)
	{
	case 11:
	{
		int j = ui.slider_1->value();
		int k = ui.slider_2->value();
		cv::blur(image, image1, Size(j, k));
		break;
	}
	case 12:
	{
		int j = ui.slider_1->value();
		cv::GaussianBlur(image, image1, Size(2 * j + 1, 2 * j + 1), 0, 0);
		break;
	}
	case 13:
	{
		int j = ui.slider_1->value();
		cv::medianBlur(image, image1, 2 * j + 1);
		break;
	}
	case 14:
	{
		int j = ui.slider_1->value();
		cv::bilateralFilter(image, image1, j, j * 2, j / 2);
		break;
	}
#pragma region //功能应用
	case 57:
	{
		int j = ui.slider_2->value();
		int k = ui.slider_1->value();
		threshold(image, image1, j, 255, k);
		break;
	}
	case 84:
	{
		int size = ui.slider_1->value();
		int area = ui.slider_2->value();
		//image1 = flawDetecting(size, area, image2);
		break;
	}
#pragma endregion
	default:
		break;
	}
	if (change == 0) {
		QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image.channels(), QImage::Format_RGB888);
		label_2 = new QLabel();
		label_2->setPixmap(QPixmap::fromImage(img));
		label_2->resize(QSize(img.width(), img.height()));
		ui.output->setWidget(label_2);
	}
}


#pragma region //图形平滑

void hi_opencv20::on_blur()
{
	i = 11;

	ui.slider_1->setValue(1);
	ui.slider_2->setValue(1);
	ui.slider_1->show();
	ui.slider_2->show();
	ui.spinBox_1->show();
	ui.spinBox_2->show();
	ui.slider_1->setMaximum(100);
}

void hi_opencv20::on_gaussian()
{
	i = 12;
	
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.slider_2->hide();
	ui.spinBox_1->show();
	ui.spinBox_2->hide();
	ui.slider_1->setMaximum(50);
}

void hi_opencv20::on_median()
{
	i = 13;

	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.slider_2->hide();
	ui.spinBox_1->show();
	ui.spinBox_2->hide();
	ui.slider_1->setMaximum(50);
	
	
}

void hi_opencv20::on_Bilateral()
{
	i = 14;

	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.slider_2->hide();
	ui.spinBox_1->show();
	ui.spinBox_2->hide();
	ui.slider_1->setMaximum(50);
}

#pragma endregion

#pragma region //形态变换by WDX
void hi_opencv20::on_erode()
{
	i = 21;
	//hideSlider();
	ui.slider_1->setMinimum(1);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.slider_1->setMaximum(100);

}
void hi_opencv20::on_dilate()
{
	i = 22;
	//hideSlider();
	ui.slider_1->setMinimum(1);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.slider_1->setMaximum(100);
}
void hi_opencv20::on_opening()
{
	i = 23;
	//hideSlider();
	ui.slider_1->setMinimum(1);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.slider_1->setMaximum(100);
}
void hi_opencv20::on_closing()
{
	i = 24;
	//hideSlider();
	ui.slider_1->setMinimum(1);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.slider_1->setMaximum(100);
}
void hi_opencv20::on_MG()
{
	i = 25;
	//hideSlider();
	ui.slider_1->setMinimum(1);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.slider_1->setMaximum(100);
}
void hi_opencv20::on_blackhat()
{
	i = 26;
	//hideSlider();
	ui.slider_1->setMinimum(1);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.slider_1->setMaximum(100);
}
void hi_opencv20::on_tophat()
{
	i = 27;
	//hideSlider();
	ui.slider_1->setMinimum(1);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.slider_1->setMaximum(100);
}

#pragma endregion

#pragma region //图像变形by WDX
void hi_opencv20::on_scale()
{
	i = 41;
	//hideSlider();
	ui.slider_1->setMinimum(1);
	ui.slider_1->setMaximum(500);
	double size;
	size = 1.0* image.cols / image2.cols * 100;
	ui.slider_1->setValue(size);

	ui.slider_1->show();
	ui.spinBox_1->show();
}
void hi_opencv20::on_rotate()
{
	i = 42;
	//hideSlider();
	image1 = image.clone();
	ui.slider_1->setMinimum(0);
	ui.slider_1->setMaximum(360);
	ui.slider_1->setValue(0);

	ui.slider_1->show();
	ui.spinBox_1->show();
}

//没有修改i

void hi_opencv20::on_L2R()
{
	//hideSlider();
	//i = 43;
	ui.slider_1->hide();
	ui.spinBox_1->hide();

	image1 = image.clone();

	Mat map1, map2;
	///dst.create(image.size(), image.type());
	map1.create(image1.size(), CV_32FC1);
	map2.create(image1.size(), CV_32FC1);


	int rows = image1.rows;
	int cols = image1.cols;
	//图像遍历
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < cols; i++)
		{
			map1.at<float>(j, i) = cols - i;
			map2.at<float>(j, i) = j;
		}
	}

	remap(image1, image1, map1, map2, INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));

	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}
void hi_opencv20::on_T2D()
{
	ui.slider_1->hide();
	ui.spinBox_1->hide();

	image1 = image.clone();

	Mat map1, map2;
	///dst.create(image.size(), image.type());
	map1.create(image1.size(), CV_32FC1);
	map2.create(image1.size(), CV_32FC1);

	int rows = image1.rows;
	int cols = image1.cols;
	//图像遍历
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < cols; i++)
		{
			map1.at<float>(j, i) = i;
			map2.at<float>(j, i) = rows - j;
		}
	}

	remap(image1, image1, map1, map2, INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}
void hi_opencv20::on_pyr()
{
	ui.slider_1->hide();
	ui.spinBox_1->hide();


	//hideSlider();
	Mat temp1, temp2, temp3;
	pyrDown(image, temp1, Size(image.cols / 2, image.rows / 2));
	pyrDown(temp1, temp2, Size(temp1.cols / 2, temp1.rows / 2));
	pyrDown(temp2, temp3, Size(temp2.cols / 2, temp2.rows / 2));

	image1 = cv::Mat::zeros(image.size(), image.type());

	//int ww = temp1.cols + temp2.cols;

	Mat imageROI1 = image1(Rect(0, 0, temp1.cols, temp1.rows));
	Mat imageROI2 = image1(Rect(temp1.cols, 0, temp2.cols, temp2.rows));
	Mat imageROI3 = image1(Rect(temp1.cols + temp2.cols, 0, temp3.cols, temp3.rows));
	//Mat imageROI3 = combine(Rect(500, 350, 800, 350));

	temp1(cv::Rect(0, 0, temp1.cols, temp1.rows)).copyTo(imageROI1);
	temp2(cv::Rect(0, 0, temp2.cols, temp2.rows)).copyTo(imageROI2);
	temp3(cv::Rect(0, 0, temp3.cols, temp3.rows)).copyTo(imageROI3);

	//image1(cv::Rect(0, 0, 500, 700)).copyTo(imageROI1);
	//image2(cv::Rect(0, 0, 800, 350)).copyTo(imageROI2);
	//image3(cv::Rect(0, 0, 800, 350)).copyTo(imageROI3);
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}

#pragma endregion

#pragma region//边缘检测by WFL
void hi_opencv20::on_Sobel() {
	i = 51;
	i_by = 3;
	ui.slider_1->setMinimum(1);
	ui.slider_1->setMaximum(50);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	m_Sobel(i_by, image, image1, label_2, ui);
}
void hi_opencv20::on_Laplace() {
	i = 52;
	i_by = 3;
	ui.slider_1->setMinimum(1);
	ui.slider_1->setMaximum(30);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	m_Laplace(i_by, image, image1, label_2, ui);
}
void hi_opencv20::on_Canny() {
	i = 53;
	i_by = 3;
	ui.slider_1->setMinimum(1);
	ui.slider_1->setMaximum(50);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	m_Canny(i_by, image, image1, label_2, ui);
}
void hi_opencv20::on_HoughLines() {
	i = 54;
	i_by = 3;
	ui.slider_1->setMinimum(1);
	ui.slider_1->setMaximum(50);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	m_HoughLines(i_by, image, image1, label_2, ui);
}
void hi_opencv20::on_HoughCircles() {
	i = 55;
	i_by = 3;
	ui.slider_1->setMinimum(1);
	ui.slider_1->setMaximum(50);
	ui.slider_1->setValue(1);
	ui.slider_1->hide();
	m_HoughCircles(i_by, image, image1, label_2, ui);
}
void hi_opencv20::on_findContours() {
	i = 56;
	i_by = 3;
	ui.slider_1->setMinimum(1);
	ui.slider_1->setMaximum(50);
	ui.slider_1->setValue(1);
	ui.slider_1->show();
	m_findContours(i_by, image, image1, label_2, ui);
}
void m_Sobel(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui) {
	Mat img1, src_gray, grad;
	GaussianBlur(image, img1, Size(3, 3), 0, 0, BORDER_DEFAULT);//对原图像进行降噪；
	cvtColor(img1, src_gray, COLOR_BGR2GRAY);
	Mat grad_x, grad_y;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	Mat abs_grad_x, abs_grad_y;
	/// 求 X方向梯度
	Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	/// 求 Y方向梯度
	Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	convertScaleAbs(grad_y, abs_grad_y);
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
	image1 = grad.clone();
	cvtColor(image1, image1, COLOR_GRAY2BGR);
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}
void m_Laplace(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui) {
	Mat src, src_gray, dst;
	int kernel_size = by * 2 - 1;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	int c;
	src = image.clone();
	/// 使用高斯滤波消除噪声
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
	/// 转换为灰度图
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	/// 使用Laplace函数
	Mat abs_dst;
	Laplacian(src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);
	image1 = abs_dst.clone();
	cvtColor(image1, image1, COLOR_GRAY2BGR);
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}
void m_Canny(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui) {
	Mat src, src_gray;
	Mat dst, detected_edges;
	int edgeThresh = 1;
	int lowThreshold;
	int const max_lowThreshold = 100;
	int ratio = 3;
	int kernel_size = 3;
	src = image.clone();
	dst.create(src.size(), src.type());
	/// 原图像转换为灰度图像
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	blur(src_gray, detected_edges, Size(3, 3));
	lowThreshold = by;
	/// 运行Canny算子
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
	/// 使用 Canny算子输出边缘作为掩码显示原图像
	dst = Scalar::all(0);
	src.copyTo(dst, detected_edges);
	image1 = dst.clone();
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}
void m_HoughLines(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui) {
	Mat src, src_gray;
	Mat dst, cdst;
	src = image.clone();
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	Canny(src_gray, dst, by, 200, 3);
	cvtColor(dst, cdst, COLOR_GRAY2BGR);
	vector<Vec4i> lines;
	HoughLinesP(dst, lines, 1, CV_PI / 180, by, 10, 10);
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
	}
	image1 = cdst.clone();
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}
void m_HoughCircles(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui) {
	Mat src, src_gray;
	//i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
	src = image.clone();
	cvtColor(src, src_gray, COLOR_BGR2GRAY);

	//GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);

	vector<Vec3f> circles;

	/// Apply the Hough Transform to find the circles
	HoughCircles(src_gray, circles, HOUGH_GRADIENT, 1, src_gray.rows / 8, 200, 100, 0, 0);

	for (int ii = 0; ii < circles.size(); ii++)
	{
		Point center(cvRound(circles[ii][0]), cvRound(circles[ii][1]));
		int radius = cvRound(circles[ii][2]);
		// circle center
		circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		// circle outline
		circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}

	image1 = src.clone();
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}
void m_findContours(int by, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui) {
	Mat src, src_gray, canny_output;
	RNG rng(12345);
	src = image.clone();
	/// 原图像转换为灰度图像
	cvtColor(src, src_gray, COLOR_BGR2GRAY);;
	/// 运行Canny算子
	Canny(src_gray, canny_output, by, 200, 3);

	/// 使用 Canny算子输出边缘作为掩码显示原图像
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	//计算矩：
	vector<Moments> mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}

	///  计算中心矩:
	vector<Point2f> mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}

	/// 绘出轮廓
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		circle(drawing, mc[i], 4, color, -1, 8, 0);
	}
	image1 = drawing.clone();
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}
#pragma endregion

#pragma region//功能应用
void hi_opencv20::objectDetect()
{
	on_init();
	ui.verticalWidget->setMaximumSize(QSize(16777215, 0));
	ui.textEdit->setMaximumSize(QSize(16777215, 200));

	QString displayString;
	QFile file("data/info.txt");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	while (!file.atEnd())
	{
		QByteArray line = file.readLine();
		QString str(line);
		//qDebug() << str;
		displayString.append(str);
	}
	displayString.append("\n");
	vector<vector<int>> rects;
	string str = fPth.substr(0, fPth.length() - 3);
	str = str + "txt";
	QString qstr = str2qstr(str);
	QFile file2(qstr);
	file2.open(QIODevice::ReadOnly | QIODevice::Text);
	
	while (!file2.atEnd())
	{
		QByteArray line = file2.readLine();
		QString rect(line);
		String info = qstr2str(rect);
		int mm = info.find(" ");
		info = info.substr(mm, info.length() - 1);
		vector<int> temp;
		int x;
		int i = 0;
		stringstream ss(info);
		while (ss >> x)
		{
			temp.push_back(x);
			i++;
		}
		rects.push_back(temp);
		displayString.append(rect);
	}

	ui.textEdit->setPlainText(displayString);

	image1 = image2.clone();
	for (int i = 0; i < rects.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		rectangle(image1, Point(rects[i][0], rects[i][1]), Point(rects[i][0] + rects[i][2], rects[i][1] + rects[i][3]), color, 2, 8, 0);
	}
	cv::resize(image1, image1, Size(w1, h1));
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);

	ui.textEdit->show();
}
#pragma endregion


/*
void hi_opencv20::on_threshold() {
	i = 57;
	//第一个滑块选择阈值类型
	//第二个滑块选择阈值大小
	ui.slider_1->setMinimum(0);
	ui.slider_1->setMaximum(4);
	ui.slider_1->setValue(0);
	ui.slider_1->show();
	ui.slider_2->setMinimum(0);
	ui.slider_2->setMaximum(255);
	ui.slider_2->setValue(0);
	ui.slider_2->show();
	ui.spinBox_1->show();
	ui.spinBox_2->show();
}
void hi_opencv20::on_copyMakeBorder() {
	i = 58;
	//第一个滑块选择阈值类型
	//第二个滑块选择阈值大小
	ui.slider_2->hide();
	ui.slider_1->setMinimum(0);
	ui.slider_1->setMaximum(1);
	ui.slider_1->setValue(0);
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.spinBox_2->hide();
}


void m_copyMakeBorder(int ot, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui) {
	//ot的取值为0或者1
	Mat src, dst;
	int top, bottom, left, right;
	Scalar value;
	RNG rng(12345);
	src = image;
	top = (int)(0.05*src.rows); bottom = (int)(0.05*src.rows);
	left = (int)(0.05*src.cols); right = (int)(0.05*src.cols);
	value = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
	int borderType = ot;
	copyMakeBorder(src, dst, top, bottom, left, right, borderType, value);
	image1 = dst;
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}


//文字检测
void groups_draw(Mat &src, vector<Rect> &groups)
{
	for (int i = (int)groups.size() - 1; i >= 0; i--)
	{
		if (src.type() == CV_8UC3)
			rectangle(src, groups.at(i).tl(), groups.at(i).br(), Scalar(0, 255, 255), 3, 8);
		else
			rectangle(src, groups.at(i).tl(), groups.at(i).br(), Scalar(255), 3, 8);
	}
}

void hi_opencv20::textDetect()
{
	Mat src = image.clone();

	// Extract channels to be processed individually
	vector<Mat> channels;
	computeNMChannels(src, channels);


	int cn = (int)channels.size();
	// Append negative channels to detect ER- (bright regions over dark background)
	for (int c = 0; c < cn - 1; c++)
		channels.push_back(255 - channels[c]);

	// Create ERFilter objects with the 1st and 2nd stage default classifiers
	Ptr<ERFilter> er_filter1 = createERFilterNM1(loadClassifierNM1("trained_classifierNM1.xml"), 16, 0.00015f, 0.13f, 0.2f, true, 0.1f);
	Ptr<ERFilter> er_filter2 = createERFilterNM2(loadClassifierNM2("trained_classifierNM2.xml"), 0.5);

	vector<vector<ERStat> > regions(channels.size());
	// Apply the default cascade classifier to each independent channel (could be done in parallel)
	//cout << "Extracting Class Specific Extremal Regions from " << (int)channels.size() << " channels ..." << endl;
	//cout << "    (...) this may take a while (...)" << endl << endl;


	for (int c = 0; c < (int)channels.size(); c++)
	{
		er_filter1->run(channels[c], regions[c]);
		er_filter2->run(channels[c], regions[c]);
	}


	// Detect character groups
	//cout << "Grouping extracted ERs ... ";
	vector< vector<Vec2i> > region_groups;
	vector<Rect> groups_boxes;
	erGrouping(src, channels, regions, region_groups, groups_boxes, ERGROUPING_ORIENTATION_HORIZ);
	//erGrouping(src, channels, regions, region_groups, groups_boxes, ERGROUPING_ORIENTATION_ANY, "./trained_classifier_erGrouping.xml", 0.5);

	// draw groups
	groups_draw(src, groups_boxes);
	//imshow("grouping", src);


	QImage img = QImage((const unsigned char*)(src.data), src.cols, src.rows, src.cols*image.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);

	er_filter1.release();
	er_filter2.release();
	regions.clear();

}

//瑕疵检测
void hi_opencv20::flawDetect()
{
	on_init();

	i = 84;

	ui.slider_1->setMaximum(20);
	ui.slider_1->setMinimum(0);
	ui.slider_1->setValue(0);
	ui.slider_1->show();
	ui.spinBox_1->show();

	ui.slider_2->setMaximum(20);
	ui.slider_2->setMinimum(0);
	ui.slider_2->setValue(0);
	ui.slider_2->show();
	ui.spinBox_2->show();
}

Mat flawDetecting(int size, int area, Mat imgOrigin)
{
	RNG rng;
	Mat imgClose, imgGray;//开运算，灰度图
	Mat imgDiff;//图片相减
	//灰度化
	cvtColor(imgOrigin, imgGray, CV_RGB2GRAY);
	//阈值化
	threshold(imgGray, imgGray, 200, 255, 0);
	imgClose = imgGray.clone();
	//闭运算
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * size + 1, 2 * size + 1), Point(size, size));
	cv::morphologyEx(imgClose, imgClose, MORPH_CLOSE, element);

	absdiff(imgGray, imgClose, imgDiff);
	//threshold(imgDiff, imgDiff, 100, 255, 1);

	vector<Mat> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDiff, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<vector<Point> > contours_poly(contours.size());
	//vector<Rect> boundRect(contours.size());//矩形
	vector<Point2f>center(contours.size());
	vector<float>radius(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		//boundRect[i] = boundingRect(Mat(contours_poly[i]));
		//float r = radius[i] + 10;
		//minEnclosingCircle(contours_poly[i], center[i], r);
		minEnclosingCircle(contours_poly[i], center[i], radius[i]);
	}
	//Mat drawing = Mat::zeros(imgDiff.size(), CV_8UC3);
	Mat drawing = imgOrigin.clone();

	double rr = 0;//半径
	double aa = 0;//面积
	drawing = imgOrigin.clone();
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		//rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
		rr = radius[i];
		aa = 3.14*rr*rr;
		if (aa >= area)
		{
			drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
			circle(drawing, center[i], (int)radius[i] + 10, color, 2, 8, 0);
		}
	}
	return drawing;
}
#pragma endregion
*/


#pragma region //直方图

void hi_opencv20::on_zhione_show()
{

	Mat src;
	// 1. 加载源图像
	image2.copyTo(src);

	// 2. 在R、G、B平面中分离源图像，把多通道图像分为多个单通道图像。使用OpenCV函数cv::split。
	vector<Mat> bgr_planes;
	split(src, bgr_planes);// 把多通道图像分为多个单通道图像

//	printf("channels=%d\n", bgr_planes.size());//3通道，所以size也是3

	// 3. 现在我们准备开始为每个平面配置直方图。 由于我们正在使用B，G和R平面，我们知道我们的值将在区间[0,255]范围内
	int histBins = 256;//建立箱数（5,10 ......）
	float range[] = { 0, 255 };//设置值的范围（在0到255之间）
	const float * histRanges = range;//注意：函数形参 float ** 与 const float ** 是两种不同数据类型。
	bool uniform = true, accumulate = false;//我们希望我们的箱子具有相同的尺寸（均匀）并在开头清除直方图
	Mat b_hist, g_hist, r_hist;//calcHist计算出来的Mat中元素的最大值可能上几千，所以最好归一化后再绘制直方图
	//使用OpenCV函数cv::calcHist计算直方图：
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histBins, &histRanges, uniform, accumulate);//计算直方图
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histBins, &histRanges, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histBins, &histRanges, uniform, accumulate);

	// 4. 归一化
	int hist_cols = 400;
	int hist_rows = 512;
	int bin_w = hist_rows / histBins;

	//请注意，在绘制之前，我们首先对直方图进行cv :: normalize，使其值落在输入参数指示的范围内：
	normalize(b_hist, b_hist, 0, hist_cols, NORM_MINMAX, -1, Mat());//b_hist中元素的值转换到 0-hist_cols 之间
	normalize(g_hist, g_hist, 0, hist_cols, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_cols, NORM_MINMAX, -1, Mat());//传参 0, hist_cols 或 hist_cols, 0 结果一致

	// 5. 绘制直方图
	Mat histImage(hist_rows, hist_cols, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 1; i < histBins; i++)
	{
		// cvRound 四舍五入，返回整型值
		line(histImage, Point((i - 1)*bin_w, hist_cols - cvRound(b_hist.at<float>(i - 1))),
			Point(i*bin_w, hist_cols - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, LINE_AA);
		line(histImage, Point((i - 1)*bin_w, hist_cols - cvRound(g_hist.at<float>(i - 1))),
			Point(i*bin_w, hist_cols - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, LINE_AA);
		line(histImage, Point((i - 1)*bin_w, hist_cols - cvRound(r_hist.at<float>(i - 1))),
			Point(i*bin_w, hist_cols - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, LINE_AA);
	}

	histImage.copyTo(image1);

	int m = image.rows;
	int n = image.cols;
	//image_fit(histImage, m, n);
	//h1 = histImage.rows * t;
	//w1 = histImage.cols* t;
	cv::resize(histImage, histImage, Size(n, m));

	QImage img1 = QImage((const unsigned char*)(histImage.data), histImage.cols, histImage.rows, histImage.cols*image.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img1));
	label_2->resize(QSize(img1.width(), img1.height()));
	ui.output->setWidget(label_2);



	QImage img = QImage((const unsigned char*)(image2.data), image2.cols, image2.rows, image2.cols*image.channels(), QImage::Format_RGB888);
	//ui.input->setPixmap(QPixmap::fromImage(img));

}


void hi_opencv20::on_zhitwo_show()
{

	
	Mat src, dst;

	char* source_window = (char*)"Source image";
	char* equalized_window = (char*)"Equalized Image";

	/// 加载源图像
	image2.copyTo(src);

	/// 转为灰度图
	cvtColor(src, src, CV_BGR2GRAY);

	/// 应用直方图均衡化
	equalizeHist(src, dst);

	/// 显示结果

/*显示彩色图*/
//	QImage img = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_RGB888);
//	ui.label_zhi_out->setPixmap(QPixmap::fromImage(img));
/*显示灰度图*/

	dst.copyTo(image1);

	double m = ui.input->height();
	double n = ui.input->width();
	image_fit(dst, m, n);
	h1 = dst.rows * t;
	w1 = dst.cols* t;
	cv::resize(dst, dst, Size(w1, h1));

	QImage img = QImage((const uchar*)dst.data, dst.cols, dst.rows, dst.cols*dst.channels(), QImage::Format_Indexed8);
	//ui.label_zhi_out->setPixmap(QPixmap::fromImage(img));
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);



	m = ui.input->height();
	n = ui.input->width();
	image_fit(src, m, n);
	h1 = src.rows * t;
	w1 = src.cols* t;
	cv::resize(src, src, Size(w1, h1));

	QImage img2 = QImage((const uchar*)src.data, src.cols, src.rows, src.cols*src.channels(), QImage::Format_Indexed8);
	//ui.label_zhi_in->setPixmap(QPixmap::fromImage(img2));
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(img2));
	label->resize(QSize(img2.width(), img2.height()));
	//ui.input->setWidget(label);


}

/// 全局变量
Mat src_zhi; Mat hsv_zhi; Mat hue_zhi; Mat dst_zhi;
int bins_zhi = 25;

/// 函数申明
void Hist_and_Backproj(int, void*);

/** @函数 main */

void hi_opencv20::on_zhithree_show()
{
	/// 读取图像
	image2.copyTo(src_zhi);

	/// 转换到 HSV 空间
	cvtColor(src_zhi, hsv_zhi, CV_BGR2HSV);

	/// 分离 Hue 通道
	hue_zhi.create(hsv_zhi.size(), hsv_zhi.depth());
	int ch[] = { 0, 0 };
	mixChannels(&hsv_zhi, 1, &hue_zhi, 1, ch, 1);

	/// 创建 Trackbar 来输入bin的数目
	//char* window_image = (char*)"Source image";
	//namedWindow(window_image, CV_WINDOW_AUTOSIZE);
	//createTrackbar("* Hue  bins: ", window_image, &bins_zhi, 180, Hist_and_Backproj);
	Hist_and_Backproj(0, 0);

	/// 现实图像
	//imshow(window_image, src_zhi);

	Mat backproj;
	dst_zhi.copyTo(backproj);

	dst_zhi.copyTo(image1);

	double m = ui.input->height();
	double n = ui.input->width();
	image_fit(backproj, m, n);
	h1 = backproj.rows * t;
	w1 = backproj.cols* t;
	cv::resize(backproj, backproj, Size(w1, h1));

	QImage img = QImage((const uchar*)backproj.data, backproj.cols, backproj.rows, backproj.cols*backproj.channels(), QImage::Format_Indexed8);
	//ui.label_zhi_out->setPixmap(QPixmap::fromImage(img));
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);


}


/**
 * @函数 Hist_and_Backproj
 * @简介：Trackbar事件的回调函数
 */

void Hist_and_Backproj(int, void*)
{
	MatND hist;
	int histSize = MAX(bins_zhi, 2);
	float hue_range[] = { 0, 180 };
	const float* ranges = { hue_range };

	/// 计算直方图并归一化
	calcHist(&hue_zhi, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false);
	normalize(hist, hist, 0, 255, NORM_MINMAX, -1, Mat());

	/// 计算反向投影
	MatND backproj;
	calcBackProject(&hue_zhi, 1, 0, hist, backproj, &ranges, 1, true);

	backproj.copyTo(dst_zhi);

	/// 显示反向投影
//	imshow("BackProj", backproj);



	/// 显示直方图
	int w = 400; int h = 400;
	int bin_w = cvRound((double)w / histSize);
	Mat histImg = Mat::zeros(w, h, CV_8UC3);

	for (int i = 0; i < bins_zhi; i++)
	{
		rectangle(histImg, Point(i*bin_w, h), Point((i + 1)*bin_w, h - cvRound(hist.at<float>(i)*h / 255.0)), Scalar(0, 0, 255), -1);
	}

	//	imshow("Histogram", histImg);
}
#pragma endregion


#pragma region//目标定位——模板匹配

void hi_opencv20::on_convexHull()
{
	label_2 = new QLabel();
	ui.output->setWidget(label_2);

	i = 61;
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.slider_1->setMaximum(255);
	ui.slider_1->setValue(10);

}

void hi_opencv20::on_rectcircle()
{
	label_2 = new QLabel();
	ui.output->setWidget(label_2);

	i = 62;
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.slider_1->setMaximum(255);
	ui.slider_1->setValue(10);
}

void hi_opencv20::on_fitEllipse()
{
	label_2 = new QLabel();
	ui.output->setWidget(label_2);

	i = 63;
	ui.slider_1->show();
	ui.spinBox_1->show();
	ui.slider_1->setMaximum(255);
	ui.slider_1->setValue(10);
}

void w_convexHull(int j, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui)
{
	RNG rng;
	Mat image_gray, threshold_output;
	cvtColor(image, image_gray, COLOR_BGR2GRAY);
	vector<Mat> contours;
	vector<Vec4i> hierarchy;

	threshold(image_gray, threshold_output, j, 255, THRESH_BINARY);
	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<vector<Point> >hull(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		convexHull(Mat(contours[i]), hull[i], false);
	}

	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		drawContours(drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point());
	}
	drawing.copyTo(image1);
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}

void w_rectcircle(int j, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui)
{
	RNG rng;
	Mat threshold_output, image_gray;
	cvtColor(image, image_gray, COLOR_BGR2GRAY);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	threshold(image_gray, threshold_output, j, 255, THRESH_BINARY);
	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// 多边形逼近轮廓 + 获取矩形和圆形边界框
	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundRect(contours.size());
	vector<Point2f>center(contours.size());
	vector<float>radius(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		boundRect[i] = boundingRect(Mat(contours_poly[i]));
		minEnclosingCircle(contours_poly[i], center[i], radius[i]);
	}


	/// 画多边形轮廓 + 包围的矩形框 + 圆形框
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
		circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);
	}
	drawing.copyTo(image1);
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}

void w_fitEllipse(int j, Mat image, Mat image1, QLabel *label_2, Ui::hi_opencv20Class ui)
{
	RNG rng;
	Mat threshold_output, image_gray;
	cvtColor(image, image_gray, COLOR_BGR2GRAY);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	threshold(image_gray, threshold_output, j, 255, THRESH_BINARY);
	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// 对每个找到的轮廓创建可倾斜的边界框和椭圆
	vector<RotatedRect> minRect(contours.size());
	vector<RotatedRect> minEllipse(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		minRect[i] = minAreaRect(Mat(contours[i]));
		if (contours[i].size() > 5)
		{
			minEllipse[i] = fitEllipse(Mat(contours[i]));
		}
	}

	/// 绘出轮廓及其可倾斜的边界框和边界椭圆
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		// contour
		drawContours(drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		// ellipse
		ellipse(drawing, minEllipse[i], color, 2, 8);
		// rotated rectangle
		Point2f rect_points[4]; minRect[i].points(rect_points);
		for (int m = 0; m < 4; m++)
			line(drawing, rect_points[m], rect_points[(m + 1) % 4], color, 1, 8);
	}
	drawing.copyTo(image1);
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}


void hi_opencv20::on_open2()
{

	this->hide();
	open2->show();
	open2->exec();
	this->show();
}

void hi_opencv20::on_receive(QString y)
{
	temple = y;
	String str = qstr2str(temple);
	image3 = imread(str);
	int h2 = image3.rows*t;
	int w2 = image3.cols*t;
	cv::resize(image3, image3, Size(w2, h2));
	cvtColor(image3, image3, COLOR_BGR2RGB);

	label_2 = new QLabel();
	ui.output->setWidget(label_2);
}

void hi_opencv20::match()
{

	Mat result, image_display;
	image.copyTo(image_display);

	int result_cols = image.cols - image3.cols + 1;
	int result_rows = image.rows - image3.rows + 1;

	result.create(result_cols, result_rows, CV_32FC1);
	matchTemplate(image, image3, result, match_method);
	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;

	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	if (match_method == TM_SQDIFF || match_method == TM_SQDIFF_NORMED)
	{
		matchLoc = minLoc;
	}
	else
	{
		matchLoc = maxLoc;
	}
	rectangle(image_display, matchLoc, Point(matchLoc.x + image3.cols, matchLoc.y + image3.rows), Scalar::all(0), 2, 8, 0);
	rectangle(result, matchLoc, Point(matchLoc.x + image3.cols, matchLoc.y + image3.rows), Scalar::all(0), 2, 8, 0);
	image_display.copyTo(image1);
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img));
	label_2->resize(QSize(img.width(), img.height()));
	ui.output->setWidget(label_2);
}

void hi_opencv20::on_match1()
{

	match_method = TM_SQDIFF;
	match();
}

void hi_opencv20::on_match2()
{
	match_method = TM_SQDIFF_NORMED;
	match();
}

void hi_opencv20::on_match3()
{
	match_method = TM_CCORR;
	match();
}

void hi_opencv20::on_match4()
{
	match_method = TM_CCORR_NORMED;
	match();

}

void hi_opencv20::on_match5()
{
	match_method = TM_CCOEFF;
	match();
}

void hi_opencv20::on_match6()
{
	match_method = TM_CCOEFF_NORMED;
	match();
}

#pragma endregion


void hi_opencv20::on_init()
{
	//label = new QLabel();
	//ui.output->setWidget(label);
	ui.slider_1->hide();
	ui.slider_2->hide();
	ui.spinBox_1->hide();
	ui.spinBox_2->hide();
	ui.textEdit->hide();
	i = -1;
	ui.verticalWidget->setMaximumSize(QSize(16777215, 140));
	ui.textEdit->setMaximumSize(QSize(16777215, 0));

	/*
	if (ui.toolBox->currentIndex() == 9)
	{
		label = new QLabel();
		ui.input->setWidget(label);
	}
	*/
}