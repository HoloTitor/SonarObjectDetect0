#include "hi_opencv20.h"
#include <QtWidgets/QApplication>

#include <QSplashScreen>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QPixmap pixmap(":/hi_opencv20/screen.bmp");
	QSplashScreen screen(pixmap);
	screen.show();

	hi_opencv20 w;
	w.show();
	screen.finish(&w);

	QFile styleFile(":/hi_opencv20/Resources/stylesheet.qss");
	styleFile.open(QIODevice::ReadOnly);
	QString setStyleSheet(styleFile.readAll());
	a.setStyleSheet(setStyleSheet);
	return a.exec();
}
