#include "EFuseBoardWidget.hpp"

EFuseBoardWidget::EFuseBoardWidget(QWidget *parent)
    : QWidget(parent)
{


//    frame = new QFrame(this);
//    frame->setObjectName(QString::fromUtf8("frame"));
//    frame->setGeometry(QRect(0, 0, 300, 550));
//    frame->raise();
//
//    group_box_ch1 = new QGroupBox(frame);
//    group_box_ch1->setObjectName(QString::fromUtf8("group_box_ch1"));
//    group_box_ch1->setGeometry(QRect(10, 30, 131, 91));
//
//    ch1_max_current = new QLabel(group_box_ch1);
//    ch1_max_current->setObjectName(QString::fromUtf8("ch1_max_current"));
//    ch1_max_current->setGeometry(QRect(90, 35, 31, 20));
//
//    ch1_power = new QLabel(group_box_ch1);
//    ch1_power->setObjectName(QString::fromUtf8("ch1_power"));
//    ch1_power->setGeometry(QRect(90, 5, 31, 17));
//
//    label_ch1_max_curr = new QLabel(group_box_ch1);
//    label_ch1_max_curr->setObjectName(QString::fromUtf8("label_ch1_max_curr"));
//    label_ch1_max_curr->setGeometry(QRect(0, 35, 81, 17));
//
//    label_ch1_actual_curr = new QLabel(group_box_ch1);
//    label_ch1_actual_curr->setObjectName(QString::fromUtf8("label_ch1_actual_curr"));
//    label_ch1_actual_curr->setGeometry(QRect(0, 70, 81, 17));
//
//    ch1_actual_current = new QLabel(group_box_ch1);
//    ch1_actual_current->setObjectName(QString::fromUtf8("ch1_actual_current"));
//    ch1_actual_current->setGeometry(QRect(90, 70, 31, 20));
//
//
//    MainWindow->setCentralWidget(this);
//    frame->raise();
//    menubar = new QMenuBar(MainWindow);
//    menubar->setObjectName(QString::fromUtf8("menubar"));
//    menubar->setGeometry(QRect(0, 0, 639, 25));
//    MainWindow->setMenuBar(menubar);
//    statusbar = new QStatusBar(MainWindow);
//    statusbar->setObjectName(QString::fromUtf8("statusbar"));
//    MainWindow->setStatusBar(statusbar);
//
//    retranslateUi(MainWindow);
//
//    QMetaObject::connectSlotsByName(MainWindow);

    resize(600, 1000);

//    label = new QLabel(this);
//    label->setObjectName(QString::fromUtf8("label"));
//    label->setGeometry(QRect(280, 250, 66, 17));
//    label->setText()

    int first_collumn = 10;
    int second_column = 150;
//    int second_column = 150;

    group_box_ch1 = new QGroupBox(this);
    group_box_ch1->setGeometry(400, 600, 200, 185);
    group_box_ch1->setStyleSheet("QGroupBox{border: 2px solid;}");

    /* CHANNEL LABEL */

    label_ch1 = new QLabel("CH 1",group_box_ch1);
    label_ch1->setObjectName(QString::fromUtf8("label_ch1"));
    label_ch1->setFont(QFont("Verdana", 10, 100));
    label_ch1->setGeometry(QRect(first_collumn, 10, 100, 25));
    label_ch1->setAlignment(Qt::AlignHCenter);

    /* CHANNEL STATUS */

    ch1_power = new QLabel("",group_box_ch1);
    ch1_power->setObjectName(QString::fromUtf8("ch1_power"));
    ch1_power->setAlignment(Qt::AlignHCenter);
    ch1_power->setGeometry(QRect(second_column-10, 10, 50, 15));
    ch1_power->setStyleSheet("background-color: red;");

    /* MAX CURRENT LABEL */

    label_ch1_max_curr = new QLabel("MC",group_box_ch1);
    label_ch1_max_curr->setObjectName(QString::fromUtf8("label_ch1_max_current"));
    label_ch1_max_curr->setFont(QFont("Verdana", 10));
    label_ch1_max_curr->setGeometry(QRect(first_collumn, 50, 140, 25));
    label_ch1_max_curr->setAlignment(Qt::AlignLeft);

    /* MAX CURRENT VALUE */

    ch1_max_curr = new QLabel("0",group_box_ch1);
    ch1_max_curr->setObjectName(QString::fromUtf8("ch1_max_current"));
    ch1_max_curr->setFont(QFont("Verdana", 10));
    ch1_max_curr->setGeometry(QRect(second_column, 50, 30, 25));
    ch1_max_curr->setAlignment(Qt::AlignHCenter);

    /* ACTUAL CURRENT LABEL */

    label_ch1_actual_curr = new QLabel("AC",group_box_ch1);
    label_ch1_actual_curr->setObjectName(QString::fromUtf8("label_ch1_actual_curr"));
    label_ch1_actual_curr->setFont(QFont("Verdana", 10));
    label_ch1_actual_curr->setGeometry(QRect(first_collumn, 75, 140, 25));
    label_ch1_actual_curr->setAlignment(Qt::AlignLeft);

    /* ACTUAL CURRENT VALUE */

    ch1_actual_curr = new QLabel("0",group_box_ch1);
    ch1_actual_curr->setObjectName(QString::fromUtf8("ch1_actual_curr"));
    ch1_actual_curr->setFont(QFont("Verdana", 10));
    ch1_actual_curr->setGeometry(QRect(second_column, 75, 30, 25));
    ch1_actual_curr->setAlignment(Qt::AlignHCenter);

    /* POWER UP LABEL */

    label_ch1_power_up = new QLabel("PUP",group_box_ch1);
    label_ch1_power_up->setObjectName(QString::fromUtf8("label_ch1_power_up"));
    label_ch1_power_up->setFont(QFont("Verdana", 10));
    label_ch1_power_up->setGeometry(QRect(first_collumn, 100, 140, 25));
    label_ch1_power_up->setAlignment(Qt::AlignLeft);

    /* POWER UP STATUS */

    ch1_power_up = new QLabel("",group_box_ch1);
    ch1_power_up->setObjectName(QString::fromUtf8("ch1_power_up"));
    ch1_power_up->setGeometry(QRect(second_column+10, 100, 20, 10));
    ch1_power_up->setAlignment(Qt::AlignHCenter);
    ch1_power_up->setStyleSheet("background-color: red;");

    /* VOLTAGE LABEL */

    label_ch1_check_voltage = new QLabel("V",group_box_ch1);
    label_ch1_check_voltage->setObjectName(QString::fromUtf8("label_ch1_check_voltage"));
    label_ch1_check_voltage->setFont(QFont("Verdana", 10));
    label_ch1_check_voltage->setGeometry(QRect(first_collumn, 125, 140, 25));
    label_ch1_check_voltage->setAlignment(Qt::AlignLeft);

    /* VOLTAGE STATUS */

    ch1_check_voltage = new QLabel("",group_box_ch1);
    ch1_check_voltage->setObjectName(QString::fromUtf8("ch1_check_voltage"));
    ch1_check_voltage->setGeometry(QRect(second_column+10, 125, 20, 10));
    ch1_check_voltage->setAlignment(Qt::AlignHCenter);
    ch1_check_voltage->setStyleSheet("background-color: red;");

    /* LED LABEL */

    label_ch1_check_led = new QLabel("LED:",group_box_ch1);
    label_ch1_check_led->setObjectName(QString::fromUtf8("label_ch1_check_led"));
    label_ch1_check_led->setFont(QFont("Verdana", 10));
    label_ch1_check_led->setGeometry(QRect(first_collumn, 150, 140, 25));
    label_ch1_check_led->setAlignment(Qt::AlignLeft);

    /* LED STATUS */

    ch1_check_led = new QLabel("",group_box_ch1);
    ch1_check_led->setObjectName(QString::fromUtf8("ch1_check_led"));
    ch1_check_led->setGeometry(QRect(second_column+10, 150, 20, 10));
    ch1_check_led->setAlignment(Qt::AlignHCenter);
    ch1_check_led->setStyleSheet("background-color: red;");





//    QVBoxLayout vbox(this);
//    vbox.addWidget(label);
//    vbox.setAlignment(Qt::AlignVCenter);

    show();


}

void EFuseBoardWidget::drawMonitoringTab(QGroupBox *group_box, QLabel *power, QLabel *actual_current,
		 	 	 	   QLabel *max_current, int x_pos, int y_pos)
{

}

EFuseBoardWidget::~EFuseBoardWidget()
{
}
