#include "Open2.h"

Open2::Open2(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.label->setStyleSheet("border:2px solid black;");
}

String qstr2str1(QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return String(cdata);
}

void Open2::on_open()
{
	//QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{

		//String str  filename.toStdString();//QString字符串中有中文转化成String会有乱码
		String str2 = qstr2str1(filename);//写了一个qstr2str函数用于转化
		image = imread(str2);
		/*double m = image.rows;
		double n = image.cols;*/
		cv::resize(image, image, Size(300,200));
		cvtColor(image, image, COLOR_BGR2RGB);
	}

	QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, image.cols*image.channels(), QImage::Format_RGB888);
	ui.label->setPixmap(QPixmap::fromImage(img));
	ui.label->resize(QSize(img.width(), img.height()));

	i = 1;

}
void Open2::on_send()
{
	if (i == 1)
	{
		emit sendsignal(filename);
		ui.label->clear();
		this->close();
	}
	else
	{
		QMessageBox::warning(this, "warning", "Please open the template picture");
		return;
	}
	i = -1;
}

Open2::~Open2()
{

}
