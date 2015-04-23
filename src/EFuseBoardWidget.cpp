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

    resize(520, 600);

//    tab_window = new QTabWidget(this);
//    tab_window->setGeometry(QRect(0, 0, 100, 25));
//    tab_window->

    ch1.chan_num = "1";
    drawChannel(ch1, 300, 450);

    ch2.chan_num = "2";
    drawChannel(ch2, 300, 300);

    ch3.chan_num = "3";
    drawChannel(ch3, 300, 150);

    ch4.chan_num = "4";
    drawChannel(ch4, 300, 10);

    ch5.chan_num = "5";
    drawChannel(ch5, 10, 450);

    ch6.chan_num = "6";
    drawChannel(ch6, 10, 300);

    ch7.chan_num = "7";
    drawChannel(ch7, 10, 150);

    ch8.chan_num = "8";
    drawChannel(ch8, 10, 10);



//    /* MAX CURRENT LABEL */
//
//    label_ch1_max_curr = new QLabel("MC",group_box_ch1);
//    label_ch1_max_curr->setObjectName(QString::fromUtf8("label_ch1_max_current"));
//    label_ch1_max_curr->setFont(QFont("Verdana", 10));
//    label_ch1_max_curr->setGeometry(QRect(first_collumn, 50, 140, 25));
//    label_ch1_max_curr->setAlignment(Qt::AlignLeft);
//
//    /* MAX CURRENT VALUE */
//
//    ch1_max_curr = new QLabel("0",group_box_ch1);
//    ch1_max_curr->setObjectName(QString::fromUtf8("ch1_max_current"));
//    ch1_max_curr->setFont(QFont("Verdana", 10));
//    ch1_max_curr->setGeometry(QRect(second_column, 50, 30, 25));
//    ch1_max_curr->setAlignment(Qt::AlignHCenter);
//
//
//    /* POWER UP LABEL */
//
//    label_ch1_power_up = new QLabel("PUP",group_box_ch1);
//    label_ch1_power_up->setObjectName(QString::fromUtf8("label_ch1_power_up"));
//    label_ch1_power_up->setFont(QFont("Verdana", 10));
//    label_ch1_power_up->setGeometry(QRect(first_collumn, 100, 140, 25));
//    label_ch1_power_up->setAlignment(Qt::AlignLeft);
//
//    /* POWER UP STATUS */
//
//    ch1_power_up = new QLabel("",group_box_ch1);
//    ch1_power_up->setObjectName(QString::fromUtf8("ch1_power_up"));
//    ch1_power_up->setGeometry(QRect(second_column+10, 100, 20, 10));
//    ch1_power_up->setAlignment(Qt::AlignHCenter);
//    ch1_power_up->setStyleSheet("background-color: red;");
//
//    /* VOLTAGE LABEL */
//
//    label_ch1_check_voltage = new QLabel("V",group_box_ch1);
//    label_ch1_check_voltage->setObjectName(QString::fromUtf8("label_ch1_check_voltage"));
//    label_ch1_check_voltage->setFont(QFont("Verdana", 10));
//    label_ch1_check_voltage->setGeometry(QRect(first_collumn, 125, 140, 25));
//    label_ch1_check_voltage->setAlignment(Qt::AlignLeft);
//
//    /* VOLTAGE STATUS */
//
//    ch1_check_voltage = new QLabel("",group_box_ch1);
//    ch1_check_voltage->setObjectName(QString::fromUtf8("ch1_check_voltage"));
//    ch1_check_voltage->setGeometry(QRect(second_column+10, 125, 20, 10));
//    ch1_check_voltage->setAlignment(Qt::AlignHCenter);
//    ch1_check_voltage->setStyleSheet("background-color: red;");
//
//    /* LED LABEL */
//
//    label_ch1_check_led = new QLabel("LED:",group_box_ch1);
//    label_ch1_check_led->setObjectName(QString::fromUtf8("label_ch1_check_led"));
//    label_ch1_check_led->setFont(QFont("Verdana", 10));
//    label_ch1_check_led->setGeometry(QRect(first_collumn, 150, 140, 25));
//    label_ch1_check_led->setAlignment(Qt::AlignLeft);
//
//    /* LED STATUS */
//
//    ch1_check_led = new QLabel("",group_box_ch1);
//    ch1_check_led->setObjectName(QString::fromUtf8("ch1_check_led"));
//    ch1_check_led->setGeometry(QRect(second_column+10, 150, 20, 10));
//    ch1_check_led->setAlignment(Qt::AlignHCenter);
//    ch1_check_led->setStyleSheet("background-color: red;");





//    QVBoxLayout vbox(this);
//    vbox.addWidget(label);
//    vbox.setAlignment(Qt::AlignVCenter);

    show();


}

void EFuseBoardWidget::drawChannel(ChannelGroupBox &channel, int x_pos, int y_pos)
{

    int first_collumn = 10;
    int second_column = 150;
    int first_row = 10;
    int second_row = 55;
    int third_row = 85;
    channel.max_current = 10.5;

	channel.group_box = new QGroupBox(this);
	channel.group_box->setGeometry(x_pos, y_pos, 200, 120);
	channel.group_box->setStyleSheet("QGroupBox{border: 2px solid;}");

    /* CHANNEL LABEL */

	channel.label_channel = new QLabel("CH "+channel.chan_num,channel.group_box);
	channel.label_channel->setObjectName("label_ch"+channel.chan_num);
	channel.label_channel->setFont(QFont("Verdana", 10, 100));
	channel.label_channel->setGeometry(QRect(first_collumn, first_row, 100, 25));
	channel.label_channel->setAlignment(Qt::AlignHCenter);

    /* CHANNEL STATUS */

	channel.status_channel = new QLabel("",channel.group_box);
	channel.status_channel->setObjectName("ch"+channel.chan_num+"_power");
	channel.status_channel->setAlignment(Qt::AlignHCenter);
	channel.status_channel->setGeometry(QRect(second_column-10, first_row, 50, 15));
	channel.status_channel->setStyleSheet("background-color: red;");

	/* ACTUAL CURRENT LABEL */

	channel.label_current = new QLabel("Actual Current",channel.group_box);
	channel.label_current->setObjectName("label_ch"+channel.chan_num+"_actual_curr");
	channel.label_current->setFont(QFont("Verdana", 10));
	channel.label_current->setGeometry(QRect(first_collumn, second_row, 140, 25));
	channel.label_current->setAlignment(Qt::AlignLeft);

	/* ACTUAL CURRENT VALUE */

	channel.value_current = new QLabel("0",channel.group_box);
	channel.value_current->setObjectName("ch"+channel.chan_num+"_actual_curr");
	channel.value_current->setFont(QFont("Verdana", 10));
	channel.value_current->setGeometry(QRect(second_column, second_row, 30, 25));
	channel.value_current->setAlignment(Qt::AlignHCenter);

	/* PROGRESS BAR CURRENT */

	channel.progress_current = new QProgressBar(channel.group_box);
	channel.progress_current->setMaximum(channel.max_current);
	channel.progress_current->setTextVisible(true);
	channel.progress_current->setValue(0);
	channel.progress_current->setFormat("%p%");
	channel.progress_current->setObjectName("ch"+channel.chan_num+"_prog_curr");
	channel.progress_current->setGeometry(QRect(first_collumn, third_row, 180, 20));
	channel.progress_current->setAlignment(Qt::AlignHCenter);

}

EFuseBoardWidget::~EFuseBoardWidget()
{
}
