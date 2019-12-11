/********************************************************************************
** Form generated from reading UI file 'hi_opencv20.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HI_OPENCV20_H
#define UI_HI_OPENCV20_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hi_opencv20Class
{
public:
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionopen_2;
    QAction *actionsave_2;
    QAction *action1;
    QAction *action1_2;
    QAction *action1_3;
    QAction *action1_4;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QToolBox *toolBox;
    QWidget *page1;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnErode;
    QPushButton *btnDilate;
    QPushButton *btnOpening;
    QPushButton *btnClosing;
    QPushButton *btnMG;
    QPushButton *btnTopHat;
    QPushButton *btnBlackHat;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_zhi_1;
    QPushButton *pushButton_zhi_2;
    QPushButton *pushButton_zhi_3;
    QWidget *page;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnScale;
    QPushButton *btnRotate;
    QPushButton *btnL2R;
    QPushButton *btnT2D;
    QPushButton *btnpyr;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_8;
    QPushButton *btnScale_2;
    QPushButton *btnScale_3;
    QPushButton *btnScale_4;
    QPushButton *btnScale_5;
    QPushButton *btnScale_7;
    QPushButton *btnScale_8;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QWidget *page_7;
    QVBoxLayout *verticalLayout_10;
    QPushButton *btnObjectDetect;
    QWidget *page_8;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *input;
    QWidget *scrollAreaWidgetContents;
    QSpacerItem *horizontalSpacer;
    QScrollArea *output;
    QWidget *scrollAreaWidgetContents_2;
    QTextEdit *textEdit;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBox_1;
    QSlider *slider_1;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spinBox_2;
    QSlider *slider_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *hi_opencv20Class)
    {
        if (hi_opencv20Class->objectName().isEmpty())
            hi_opencv20Class->setObjectName(QStringLiteral("hi_opencv20Class"));
        hi_opencv20Class->resize(872, 617);
        hi_opencv20Class->setMinimumSize(QSize(0, 10));
        hi_opencv20Class->setStyleSheet(QStringLiteral(""));
        actionopen = new QAction(hi_opencv20Class);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionsave = new QAction(hi_opencv20Class);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionsave->setEnabled(false);
        actionopen_2 = new QAction(hi_opencv20Class);
        actionopen_2->setObjectName(QStringLiteral("actionopen_2"));
        actionsave_2 = new QAction(hi_opencv20Class);
        actionsave_2->setObjectName(QStringLiteral("actionsave_2"));
        action1 = new QAction(hi_opencv20Class);
        action1->setObjectName(QStringLiteral("action1"));
        action1_2 = new QAction(hi_opencv20Class);
        action1_2->setObjectName(QStringLiteral("action1_2"));
        action1_3 = new QAction(hi_opencv20Class);
        action1_3->setObjectName(QStringLiteral("action1_3"));
        action1_4 = new QAction(hi_opencv20Class);
        action1_4->setObjectName(QStringLiteral("action1_4"));
        centralWidget = new QWidget(hi_opencv20Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMinimumSize(QSize(180, 550));
        toolBox->setMaximumSize(QSize(180, 550));
        toolBox->setStyleSheet(QStringLiteral(""));
        toolBox->setFrameShape(QFrame::NoFrame);
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        page1->setGeometry(QRect(0, 0, 180, 316));
        verticalLayout_3 = new QVBoxLayout(page1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton = new QPushButton(page1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(page1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(page1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(page1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_3->addWidget(pushButton_4);

        toolBox->addItem(page1, QString::fromUtf8("\345\233\276\345\203\217\345\271\263\346\273\221"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 180, 316));
        verticalLayout_4 = new QVBoxLayout(page_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        btnErode = new QPushButton(page_3);
        btnErode->setObjectName(QStringLiteral("btnErode"));

        verticalLayout_4->addWidget(btnErode);

        btnDilate = new QPushButton(page_3);
        btnDilate->setObjectName(QStringLiteral("btnDilate"));

        verticalLayout_4->addWidget(btnDilate);

        btnOpening = new QPushButton(page_3);
        btnOpening->setObjectName(QStringLiteral("btnOpening"));

        verticalLayout_4->addWidget(btnOpening);

        btnClosing = new QPushButton(page_3);
        btnClosing->setObjectName(QStringLiteral("btnClosing"));

        verticalLayout_4->addWidget(btnClosing);

        btnMG = new QPushButton(page_3);
        btnMG->setObjectName(QStringLiteral("btnMG"));

        verticalLayout_4->addWidget(btnMG);

        btnTopHat = new QPushButton(page_3);
        btnTopHat->setObjectName(QStringLiteral("btnTopHat"));

        verticalLayout_4->addWidget(btnTopHat);

        btnBlackHat = new QPushButton(page_3);
        btnBlackHat->setObjectName(QStringLiteral("btnBlackHat"));

        verticalLayout_4->addWidget(btnBlackHat);

        toolBox->addItem(page_3, QString::fromUtf8("\345\275\242\346\200\201\345\217\230\346\215\242"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 180, 316));
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_zhi_1 = new QPushButton(page_2);
        pushButton_zhi_1->setObjectName(QStringLiteral("pushButton_zhi_1"));

        verticalLayout_5->addWidget(pushButton_zhi_1);

        pushButton_zhi_2 = new QPushButton(page_2);
        pushButton_zhi_2->setObjectName(QStringLiteral("pushButton_zhi_2"));

        verticalLayout_5->addWidget(pushButton_zhi_2);

        pushButton_zhi_3 = new QPushButton(page_2);
        pushButton_zhi_3->setObjectName(QStringLiteral("pushButton_zhi_3"));

        verticalLayout_5->addWidget(pushButton_zhi_3);

        toolBox->addItem(page_2, QString::fromUtf8("\347\233\264\346\226\271\345\233\276"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 180, 316));
        verticalLayout_6 = new QVBoxLayout(page);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btnScale = new QPushButton(page);
        btnScale->setObjectName(QStringLiteral("btnScale"));

        verticalLayout_6->addWidget(btnScale);

        btnRotate = new QPushButton(page);
        btnRotate->setObjectName(QStringLiteral("btnRotate"));

        verticalLayout_6->addWidget(btnRotate);

        btnL2R = new QPushButton(page);
        btnL2R->setObjectName(QStringLiteral("btnL2R"));

        verticalLayout_6->addWidget(btnL2R);

        btnT2D = new QPushButton(page);
        btnT2D->setObjectName(QStringLiteral("btnT2D"));

        verticalLayout_6->addWidget(btnT2D);

        btnpyr = new QPushButton(page);
        btnpyr->setObjectName(QStringLiteral("btnpyr"));

        verticalLayout_6->addWidget(btnpyr);

        toolBox->addItem(page, QString::fromUtf8("\345\233\276\345\203\217\345\217\230\345\275\242"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 180, 316));
        verticalLayout_8 = new QVBoxLayout(page_4);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        btnScale_2 = new QPushButton(page_4);
        btnScale_2->setObjectName(QStringLiteral("btnScale_2"));

        verticalLayout_8->addWidget(btnScale_2);

        btnScale_3 = new QPushButton(page_4);
        btnScale_3->setObjectName(QStringLiteral("btnScale_3"));

        verticalLayout_8->addWidget(btnScale_3);

        btnScale_4 = new QPushButton(page_4);
        btnScale_4->setObjectName(QStringLiteral("btnScale_4"));

        verticalLayout_8->addWidget(btnScale_4);

        btnScale_5 = new QPushButton(page_4);
        btnScale_5->setObjectName(QStringLiteral("btnScale_5"));

        verticalLayout_8->addWidget(btnScale_5);

        btnScale_7 = new QPushButton(page_4);
        btnScale_7->setObjectName(QStringLiteral("btnScale_7"));

        verticalLayout_8->addWidget(btnScale_7);

        btnScale_8 = new QPushButton(page_4);
        btnScale_8->setObjectName(QStringLiteral("btnScale_8"));

        verticalLayout_8->addWidget(btnScale_8);

        toolBox->addItem(page_4, QString::fromUtf8("\350\276\271\347\274\230\346\243\200\346\265\213"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 180, 316));
        verticalLayout_7 = new QVBoxLayout(page_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton_5 = new QPushButton(page_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_7->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(page_5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_7->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(page_5);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout_7->addWidget(pushButton_7);

        toolBox->addItem(page_5, QString::fromUtf8("\347\233\256\346\240\207\345\256\232\344\275\215"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setGeometry(QRect(0, 0, 180, 316));
        verticalLayout_9 = new QVBoxLayout(page_6);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        pushButton_8 = new QPushButton(page_6);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout_9->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(page_6);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        verticalLayout_9->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(page_6);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        verticalLayout_9->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(page_6);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        verticalLayout_9->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(page_6);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        verticalLayout_9->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(page_6);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        verticalLayout_9->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(page_6);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        verticalLayout_9->addWidget(pushButton_14);

        toolBox->addItem(page_6, QString::fromUtf8("\346\250\241\346\235\277\345\214\271\351\205\215"));
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        page_7->setGeometry(QRect(0, 0, 180, 316));
        verticalLayout_10 = new QVBoxLayout(page_7);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        btnObjectDetect = new QPushButton(page_7);
        btnObjectDetect->setObjectName(QStringLiteral("btnObjectDetect"));

        verticalLayout_10->addWidget(btnObjectDetect);

        toolBox->addItem(page_7, QString::fromUtf8("\345\212\237\350\203\275\345\272\224\347\224\250"));
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        page_8->setGeometry(QRect(0, 0, 180, 316));
        verticalLayout_11 = new QVBoxLayout(page_8);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        toolBox->addItem(page_8, QString::fromUtf8("\345\205\263\351\227\255"));

        horizontalLayout_2->addWidget(toolBox, 0, Qt::AlignTop);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalWidget = new QWidget(centralWidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        input = new QScrollArea(horizontalWidget);
        input->setObjectName(QStringLiteral("input"));
        input->setMouseTracking(true);
        input->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        input->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        input->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 311, 406));
        input->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(input);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        output = new QScrollArea(horizontalWidget);
        output->setObjectName(QStringLiteral("output"));
        output->setMouseTracking(true);
        output->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 311, 406));
        output->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(output);


        verticalLayout_2->addWidget(horizontalWidget);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setMaximumSize(QSize(16777215, 10));
        textEdit->setStyleSheet(QLatin1String("\n"
"border:0px;\n"
""));
        textEdit->setReadOnly(true);

        verticalLayout_2->addWidget(textEdit);

        verticalWidget = new QWidget(centralWidget);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setMaximumSize(QSize(16777215, 140));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalWidget1 = new QWidget(verticalWidget);
        horizontalWidget1->setObjectName(QStringLiteral("horizontalWidget1"));
        horizontalWidget1->setMaximumSize(QSize(600, 16777215));
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        spinBox_1 = new QSpinBox(horizontalWidget1);
        spinBox_1->setObjectName(QStringLiteral("spinBox_1"));
        spinBox_1->setMinimumSize(QSize(60, 20));
        spinBox_1->setMaximumSize(QSize(60, 20));
        spinBox_1->setMaximum(500);

        horizontalLayout_4->addWidget(spinBox_1);

        slider_1 = new QSlider(horizontalWidget1);
        slider_1->setObjectName(QStringLiteral("slider_1"));
        slider_1->setMinimumSize(QSize(300, 0));
        slider_1->setMaximumSize(QSize(300, 16777215));
        slider_1->setMinimum(1);
        slider_1->setValue(1);
        slider_1->setOrientation(Qt::Horizontal);
        slider_1->setTickPosition(QSlider::NoTicks);

        horizontalLayout_4->addWidget(slider_1);


        verticalLayout->addWidget(horizontalWidget1, 0, Qt::AlignHCenter);

        horizontalWidget_2 = new QWidget(verticalWidget);
        horizontalWidget_2->setObjectName(QStringLiteral("horizontalWidget_2"));
        horizontalWidget_2->setMaximumSize(QSize(600, 16777215));
        horizontalLayout_5 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        spinBox_2 = new QSpinBox(horizontalWidget_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimumSize(QSize(60, 20));
        spinBox_2->setMaximumSize(QSize(60, 20));
        spinBox_2->setMaximum(255);

        horizontalLayout_5->addWidget(spinBox_2);

        slider_2 = new QSlider(horizontalWidget_2);
        slider_2->setObjectName(QStringLiteral("slider_2"));
        slider_2->setMinimumSize(QSize(300, 0));
        slider_2->setMaximumSize(QSize(300, 16777215));
        slider_2->setMinimum(1);
        slider_2->setValue(1);
        slider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(slider_2);


        verticalLayout->addWidget(horizontalWidget_2, 0, Qt::AlignHCenter);


        verticalLayout_2->addWidget(verticalWidget);


        horizontalLayout_2->addLayout(verticalLayout_2);

        hi_opencv20Class->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(hi_opencv20Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QLatin1String("font: 75 10pt \"Agency FB\";\n"
"color:#ffffff;"));
        hi_opencv20Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(hi_opencv20Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        hi_opencv20Class->setStatusBar(statusBar);

        mainToolBar->addAction(action1_4);
        mainToolBar->addAction(actionsave);

        retranslateUi(hi_opencv20Class);
        QObject::connect(pushButton, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_blur()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_gaussian()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_median()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_Bilateral()));
        QObject::connect(action1_4, SIGNAL(triggered()), hi_opencv20Class, SLOT(open()));
        QObject::connect(btnErode, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_erode()));
        QObject::connect(btnDilate, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_dilate()));
        QObject::connect(btnOpening, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_opening()));
        QObject::connect(btnClosing, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_closing()));
        QObject::connect(btnMG, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_MG()));
        QObject::connect(btnTopHat, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_tophat()));
        QObject::connect(btnBlackHat, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_blackhat()));
        QObject::connect(btnScale, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_scale()));
        QObject::connect(btnRotate, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_rotate()));
        QObject::connect(btnL2R, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_L2R()));
        QObject::connect(btnT2D, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_T2D()));
        QObject::connect(btnpyr, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_pyr()));
        QObject::connect(pushButton_zhi_1, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_zhione_show()));
        QObject::connect(pushButton_zhi_2, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_zhitwo_show()));
        QObject::connect(pushButton_zhi_3, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_zhithree_show()));
        QObject::connect(slider_1, SIGNAL(valueChanged(int)), hi_opencv20Class, SLOT(on_slider_1()));
        QObject::connect(slider_2, SIGNAL(valueChanged(int)), hi_opencv20Class, SLOT(on_slider_2()));
        QObject::connect(actionsave, SIGNAL(triggered()), hi_opencv20Class, SLOT(save()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_convexHull()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_rectcircle()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_fitEllipse()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_open2()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_match1()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_match2()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_match3()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_match4()));
        QObject::connect(pushButton_13, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_match5()));
        QObject::connect(pushButton_14, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_match6()));
        QObject::connect(slider_1, SIGNAL(valueChanged(int)), spinBox_1, SLOT(setValue(int)));
        QObject::connect(slider_2, SIGNAL(valueChanged(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(spinBox_1, SIGNAL(valueChanged(int)), slider_1, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), slider_2, SLOT(setValue(int)));
        QObject::connect(toolBox, SIGNAL(currentChanged(int)), hi_opencv20Class, SLOT(on_init()));
        QObject::connect(btnScale_2, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_Sobel()));
        QObject::connect(btnScale_3, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_Laplace()));
        QObject::connect(btnScale_4, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_Canny()));
        QObject::connect(btnScale_5, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_HoughLines()));
        QObject::connect(btnScale_7, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_HoughCircles()));
        QObject::connect(btnScale_8, SIGNAL(clicked()), hi_opencv20Class, SLOT(on_findContours()));
        QObject::connect(btnObjectDetect, SIGNAL(clicked()), hi_opencv20Class, SLOT(objectDetect()));

        toolBox->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(hi_opencv20Class);
    } // setupUi

    void retranslateUi(QMainWindow *hi_opencv20Class)
    {
        hi_opencv20Class->setWindowTitle(QApplication::translate("hi_opencv20Class", "\345\243\260\345\221\220\347\233\256\346\240\207\346\243\200\346\265\213\344\270\216\350\257\206\345\210\253\347\263\273\347\273\237", Q_NULLPTR));
        actionopen->setText(QApplication::translate("hi_opencv20Class", "open", Q_NULLPTR));
        actionsave->setText(QApplication::translate("hi_opencv20Class", "\344\277\235\345\255\230", Q_NULLPTR));
        actionopen_2->setText(QApplication::translate("hi_opencv20Class", "open", Q_NULLPTR));
        actionsave_2->setText(QApplication::translate("hi_opencv20Class", "save", Q_NULLPTR));
        action1->setText(QApplication::translate("hi_opencv20Class", "1", Q_NULLPTR));
        action1_2->setText(QApplication::translate("hi_opencv20Class", "1", Q_NULLPTR));
        action1_3->setText(QApplication::translate("hi_opencv20Class", "1", Q_NULLPTR));
        action1_4->setText(QApplication::translate("hi_opencv20Class", "\346\211\223\345\274\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        page1->setToolTip(QApplication::translate("hi_opencv20Class", "\346\261\237\345\215\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("hi_opencv20Class", "\345\275\222\344\270\200\345\214\226\345\235\227\346\273\244\346\263\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("hi_opencv20Class", "\351\253\230\346\226\257\346\273\244\346\263\242", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("hi_opencv20Class", "\344\270\255\345\200\274\346\273\244\346\263\242", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("hi_opencv20Class", "\345\217\214\350\276\271\346\273\244\346\263\242", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page1), QApplication::translate("hi_opencv20Class", "\345\233\276\345\203\217\345\271\263\346\273\221", Q_NULLPTR));
        btnErode->setText(QApplication::translate("hi_opencv20Class", "\350\205\220\350\232\200\345\217\230\346\215\242", Q_NULLPTR));
        btnDilate->setText(QApplication::translate("hi_opencv20Class", "\350\206\250\350\203\200\345\217\230\346\215\242", Q_NULLPTR));
        btnOpening->setText(QApplication::translate("hi_opencv20Class", "\345\274\200\350\277\220\347\256\227", Q_NULLPTR));
        btnClosing->setText(QApplication::translate("hi_opencv20Class", "\351\227\255\350\277\220\347\256\227", Q_NULLPTR));
        btnMG->setText(QApplication::translate("hi_opencv20Class", "\345\275\242\346\200\201\346\242\257\345\272\246", Q_NULLPTR));
        btnTopHat->setText(QApplication::translate("hi_opencv20Class", "\351\241\266\345\270\275", Q_NULLPTR));
        btnBlackHat->setText(QApplication::translate("hi_opencv20Class", "\351\273\221\345\270\275", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("hi_opencv20Class", "\345\275\242\346\200\201\345\217\230\346\215\242", Q_NULLPTR));
        pushButton_zhi_1->setText(QApplication::translate("hi_opencv20Class", "\350\256\241\347\256\227\345\233\276\345\203\217\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        pushButton_zhi_2->setText(QApplication::translate("hi_opencv20Class", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226", Q_NULLPTR));
        pushButton_zhi_3->setText(QApplication::translate("hi_opencv20Class", "\345\217\215\345\220\221\346\212\225\345\275\261", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("hi_opencv20Class", "\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        btnScale->setText(QApplication::translate("hi_opencv20Class", "\346\224\276\347\274\251", Q_NULLPTR));
        btnRotate->setText(QApplication::translate("hi_opencv20Class", "\346\227\213\350\275\254", Q_NULLPTR));
        btnL2R->setText(QApplication::translate("hi_opencv20Class", "\346\260\264\345\271\263\347\275\256\346\215\242", Q_NULLPTR));
        btnT2D->setText(QApplication::translate("hi_opencv20Class", "\345\236\202\347\233\264\347\275\256\346\215\242", Q_NULLPTR));
        btnpyr->setText(QApplication::translate("hi_opencv20Class", "\345\233\276\345\203\217\351\207\221\345\255\227\345\241\224", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("hi_opencv20Class", "\345\233\276\345\203\217\345\217\230\345\275\242", Q_NULLPTR));
        btnScale_2->setText(QApplication::translate("hi_opencv20Class", "Sobel\345\257\274\346\225\260", Q_NULLPTR));
        btnScale_3->setText(QApplication::translate("hi_opencv20Class", "Laplace\347\256\227\345\255\220", Q_NULLPTR));
        btnScale_4->setText(QApplication::translate("hi_opencv20Class", "Canny\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
        btnScale_5->setText(QApplication::translate("hi_opencv20Class", "\351\234\215\345\244\253\347\272\277\345\217\230\346\215\242", Q_NULLPTR));
        btnScale_7->setText(QApplication::translate("hi_opencv20Class", "\351\234\215\345\244\253\345\234\206\345\217\230\346\215\242", Q_NULLPTR));
        btnScale_8->setText(QApplication::translate("hi_opencv20Class", "\345\233\276\345\203\217\350\275\256\345\273\223", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("hi_opencv20Class", "\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("hi_opencv20Class", "\345\207\270\345\214\205", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("hi_opencv20Class", "\345\210\233\345\273\272\347\237\251\345\275\242\345\222\214\345\234\206\345\275\242\346\241\206", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("hi_opencv20Class", "\345\210\233\345\273\272\345\200\276\346\226\234\347\232\204\346\244\255\345\234\206\350\276\271\347\225\214\346\241\206", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("hi_opencv20Class", "\347\233\256\346\240\207\345\256\232\344\275\215", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("hi_opencv20Class", "\346\211\223\345\274\200\346\250\241\346\235\277\345\233\276\345\275\242", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("hi_opencv20Class", "\345\214\271\351\205\215\346\226\271\346\263\225\344\270\200", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("hi_opencv20Class", "\345\214\271\351\205\215\346\226\271\346\263\225\344\272\214", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("hi_opencv20Class", "\345\214\271\351\205\215\346\226\271\346\263\225\344\270\211", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("hi_opencv20Class", "\345\214\271\351\205\215\346\226\271\346\263\225\345\233\233", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("hi_opencv20Class", "\345\214\271\351\205\215\346\226\271\346\263\225\344\272\224", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("hi_opencv20Class", "\345\214\271\351\205\215\346\226\271\346\263\225\345\205\255", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("hi_opencv20Class", "\346\250\241\346\235\277\345\214\271\351\205\215", Q_NULLPTR));
        btnObjectDetect->setText(QApplication::translate("hi_opencv20Class", "\347\233\256\346\240\207\346\243\200\346\265\213", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_7), QApplication::translate("hi_opencv20Class", "\345\212\237\350\203\275\345\272\224\347\224\250", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_8), QApplication::translate("hi_opencv20Class", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class hi_opencv20Class: public Ui_hi_opencv20Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HI_OPENCV20_H
