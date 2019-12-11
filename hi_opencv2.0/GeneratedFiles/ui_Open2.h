/********************************************************************************
** Form generated from reading UI file 'Open2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPEN2_H
#define UI_OPEN2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Open2
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *Open2)
    {
        if (Open2->objectName().isEmpty())
            Open2->setObjectName(QStringLiteral("Open2"));
        Open2->resize(716, 553);
        Open2->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(Open2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 551, 501));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(90, 16777215));
        pushButton->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(90, 16777215));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(300, 200));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(Open2);
        QObject::connect(pushButton, SIGNAL(clicked()), Open2, SLOT(on_open()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Open2, SLOT(on_send()));

        QMetaObject::connectSlotsByName(Open2);
    } // setupUi

    void retranslateUi(QDialog *Open2)
    {
        Open2->setWindowTitle(QApplication::translate("Open2", "Open2", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Open2", "\346\211\223\345\274\200", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Open2", "\347\241\256\345\256\232", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Open2: public Ui_Open2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPEN2_H
