#include "EFuseBoardWidget.hpp"

EFuseBoardWidget::EFuseBoardWidget(QWidget *parent)
    : QWidget(parent)
{

    setFixedSize(520, 625);

    /* Creates a tab window with two tabs */
    tab_window = new QTabWidget(this);
    monit_tab = new QWidget(tab_window);
    config_tab = new QWidget(tab_window);
    tab_window->setGeometry(QRect(0, 0, 520, 625));
    tab_window->addTab(monit_tab, "Main Monit");
    tab_window->addTab(config_tab, "Full Monit");

    /* Initializes channels' number variable */
	ch1.chan_num = "1";
	ch2.chan_num = "2";
	ch3.chan_num = "3";
	ch4.chan_num = "4";
	ch5.chan_num = "5";
	ch6.chan_num = "6";
	ch7.chan_num = "7";
	ch8.chan_num = "8";

    /* Draws Monitoring Tab */
	drawMonitChannel(ch8, 300, 450);
	drawMonitChannel(ch7, 300, 300);
	drawMonitChannel(ch6, 300, 150);
	drawMonitChannel(ch5, 300, 10);
	drawMonitChannel(ch4, 10, 450);
	drawMonitChannel(ch3, 10, 300);
	drawMonitChannel(ch2, 10, 150);
	drawMonitChannel(ch1, 10, 10);

    /* Draws Configuration Tab */
	drawConfigChannel(ch8, 300, 450);
	drawConfigChannel(ch7, 300, 300);
	drawConfigChannel(ch6, 300, 150);
	drawConfigChannel(ch5, 300, 10);
	drawConfigChannel(ch4, 10, 450);
	drawConfigChannel(ch3, 10, 300);
	drawConfigChannel(ch2, 10, 150);
	drawConfigChannel(ch1, 10, 10);

    show();

}

EFuseBoardWidget::~EFuseBoardWidget()
{
	deleteChannelPointers(ch1);
	deleteChannelPointers(ch2);
	deleteChannelPointers(ch3);
	deleteChannelPointers(ch4);
	deleteChannelPointers(ch5);
	deleteChannelPointers(ch6);
	deleteChannelPointers(ch7);
	deleteChannelPointers(ch8);

	delete config_tab;
	delete monit_tab;
	delete tab_window;
}

void EFuseBoardWidget::setBoardStatus(efuse_board::StatusBoard status_board)
{
	setChannelStatus(status_board.status_channel[0], ch1);
	setChannelStatus(status_board.status_channel[1], ch2);
	setChannelStatus(status_board.status_channel[2], ch3);
	setChannelStatus(status_board.status_channel[3], ch4);
	setChannelStatus(status_board.status_channel[4], ch5);
	setChannelStatus(status_board.status_channel[5], ch6);
	setChannelStatus(status_board.status_channel[6], ch7);
	setChannelStatus(status_board.status_channel[7], ch8);
}

void EFuseBoardWidget::setChannelStatus(efuse_board::StatusChannel &status_channel, ChannelGroupBox &channel)
{
	if(status_channel.channel_on == true)
	{
		channel.status_channel->setStyleSheet("background-color: green;");
		channel.monit_status_channel->setStyleSheet("background-color: green;");

	}
	else
	{
		channel.status_channel->setStyleSheet("background-color: red;");
		channel.monit_status_channel->setStyleSheet("background-color: red;");
	}

	if(status_channel.default_on == true)
	{
		channel.status_power_up->setStyleSheet("background-color: green;");
	}
	else
	{
		channel.status_power_up->setStyleSheet("background-color: red;");
	}

	if(status_channel.check_voltage == true)
	{
		channel.status_voltage->setStyleSheet("background-color: green;");
	}
	else
	{
		channel.status_voltage->setStyleSheet("background-color: red;");
	}

	if(status_channel.error_led == true)
	{
		channel.status_led->setStyleSheet("background-color: red;");
	}
	else
	{
		channel.status_led->setStyleSheet("background-color: green;");
	}


	channel.value_current->setText(QString::number(status_channel.current));
	channel.value_max_current->setText(QString::number(status_channel.max_current));
	channel.progress_current->setMaximum(status_channel.max_current);
}

void EFuseBoardWidget::drawMonitChannel(ChannelGroupBox &channel, int x_pos, int y_pos)
{

    int first_collumn = 10;
    int second_column = 140;
    int first_row = 10;
    int second_row = 55;
    int third_row = 85;
    int max_current = 10.5;

	channel.monit_group_box = new QGroupBox(monit_tab);
	channel.monit_group_box->setGeometry(x_pos, y_pos, 200, 120);
	channel.monit_group_box->setStyleSheet("QGroupBox{border: 2px solid;}");

    /* CHANNEL LABEL */

	channel.label_channel = new QLabel("CH "+channel.chan_num,channel.monit_group_box);
	channel.label_channel->setObjectName("monit_label_ch"+channel.chan_num);
	channel.label_channel->setFont(QFont("Verdana", 10, 100));
	channel.label_channel->setGeometry(QRect(first_collumn, first_row, 100, 20));
	channel.label_channel->setAlignment(Qt::AlignHCenter);

    /* CHANNEL STATUS */

	channel.status_channel = new QLabel("",channel.monit_group_box);
	channel.status_channel->setObjectName("monit_ch"+channel.chan_num+"_power");
	channel.status_channel->setAlignment(Qt::AlignHCenter);
	channel.status_channel->setGeometry(QRect(second_column, first_row+2.5, 50, 15));
	channel.status_channel->setStyleSheet("background-color: red;");

	/* ACTUAL CURRENT LABEL */

	channel.label_current = new QLabel("Actual Current [A]",channel.monit_group_box);
	channel.label_current->setObjectName("label_ch"+channel.chan_num+"_actual_curr");
	channel.label_current->setFont(QFont("Verdana", 10));
	channel.label_current->setGeometry(QRect(first_collumn, second_row, 115, 25));
	channel.label_current->setAlignment(Qt::AlignHCenter);

	/* ACTUAL CURRENT VALUE */

	channel.value_current = new QLabel("0",channel.monit_group_box);
	channel.value_current->setObjectName("ch"+channel.chan_num+"_actual_curr");
	channel.value_current->setFont(QFont("Verdana", 10));
	channel.value_current->setGeometry(QRect(second_column, second_row, 50, 25));
	channel.value_current->setAlignment(Qt::AlignHCenter);

	/* PROGRESS BAR CURRENT */

	channel.progress_current = new QProgressBar(channel.monit_group_box);
	channel.progress_current->setMaximum(max_current);
	channel.progress_current->setTextVisible(true);
	channel.progress_current->setValue(0);
	channel.progress_current->setFormat("%p%");
	channel.progress_current->setObjectName("ch"+channel.chan_num+"_prog_curr");
	channel.progress_current->setGeometry(QRect(first_collumn, third_row, 180, 20));
	channel.progress_current->setAlignment(Qt::AlignHCenter);

}


void EFuseBoardWidget::drawConfigChannel(ChannelGroupBox &channel, int x_pos, int y_pos)
{
	int first_collumn = 10;
	int second_column = 140;
	int first_row = 10;
	int second_row = 35;
	int third_row = 55;
	int fourth_row = 75;
	int fith_row = 95;

	channel.config_group_box = new QGroupBox(config_tab);
	channel.config_group_box->setGeometry(x_pos, y_pos, 200, 120);
	channel.config_group_box->setStyleSheet("QGroupBox{border: 2px solid;}");

    /* CHANNEL LABEL */

	channel.label_channel = new QLabel("CH "+channel.chan_num,channel.config_group_box);
	channel.label_channel->setObjectName("config_label_ch"+channel.chan_num);
	channel.label_channel->setFont(QFont("Verdana", 10, 100));
	channel.label_channel->setGeometry(QRect(first_collumn, first_row, 100, 20));
	channel.label_channel->setAlignment(Qt::AlignHCenter);

    /* CHANNEL ON */

	channel.monit_status_channel = new QLabel("",channel.config_group_box);
	channel.monit_status_channel->setObjectName("config_ch"+channel.chan_num+"_power");
	channel.monit_status_channel->setAlignment(Qt::AlignHCenter);
	channel.monit_status_channel->setGeometry(QRect(second_column, first_row+2.5, 50, 15));
	channel.monit_status_channel->setStyleSheet("background-color: red;");

	/* MAXIMUM CURRENT LABEL */

	channel.label_max_current = new QLabel("Max. Cur. [A]",channel.config_group_box);
	channel.label_max_current->setObjectName("label_ch"+channel.chan_num+"_max_curr");
	channel.label_max_current->setFont(QFont("Verdana", 10));
	channel.label_max_current->setGeometry(QRect(first_collumn, second_row, 100, 20));
	channel.label_max_current->setAlignment(Qt::AlignLeft);

	/* MAXIMUM CURRENT VALUE */

	channel.value_max_current = new QLabel("10.5",channel.config_group_box);
	channel.value_max_current->setObjectName("ch"+channel.chan_num+"_max_curr");
	channel.value_max_current->setFont(QFont("Verdana", 10));
	channel.value_max_current->setAlignment(Qt::AlignHCenter);
	channel.value_max_current->setGeometry(QRect(second_column, second_row, 50, 20));

	/* DEFAULT ON LABEL */

	channel.label_power_up = new QLabel("Default On",channel.config_group_box);
	channel.label_power_up->setObjectName("label_ch"+channel.chan_num+"_power_up");
	channel.label_power_up->setFont(QFont("Verdana", 10));
	channel.label_power_up->setGeometry(QRect(first_collumn, third_row, 100, 20));
	channel.label_power_up->setAlignment(Qt::AlignLeft);

	/* DEFAULT ON STATUS */

	channel.status_power_up = new QLabel("",channel.config_group_box);
	channel.status_power_up->setObjectName("ch"+channel.chan_num+"_power_up");
	channel.status_power_up->setGeometry(QRect(second_column+15, third_row+5, 20, 10));
	channel.status_power_up->setAlignment(Qt::AlignRight);
	channel.status_power_up->setStyleSheet("background-color: red;");

	/* VOLTAGE LABEL */

	channel.label_voltage = new QLabel("Check Voltage",channel.config_group_box);
	channel.label_voltage->setObjectName("label_ch"+channel.chan_num+"_voltage");
	channel.label_voltage->setFont(QFont("Verdana", 10));
	channel.label_voltage->setGeometry(QRect(first_collumn, fourth_row, 100, 20));
	channel.label_voltage->setAlignment(Qt::AlignLeft);

	/* VOLTAGE STATUS */

	channel.status_voltage = new QLabel("",channel.config_group_box);
	channel.status_voltage->setObjectName("ch"+channel.chan_num+"_voltage");
	channel.status_voltage->setGeometry(QRect(second_column+15, fourth_row+5, 20, 10));
	channel.status_voltage->setAlignment(Qt::AlignRight);
	channel.status_voltage->setStyleSheet("background-color: red;");

	/* ERROR LED LABEL */

	channel.label_led = new QLabel("LED",channel.config_group_box);
	channel.label_led->setObjectName("label_ch"+channel.chan_num+"_check_led");
	channel.label_led->setFont(QFont("Verdana", 10));
	channel.label_led->setGeometry(QRect(first_collumn, fith_row, 100, 20));
	channel.label_led->setAlignment(Qt::AlignLeft);

	/* ERROR LED STATUS */

	channel.status_led = new QLabel("",channel.config_group_box);
	channel.status_led->setObjectName("ch"+channel.chan_num+"_check_led");
	channel.status_led->setGeometry(QRect(second_column+15, fith_row+5, 20, 10));
	channel.status_led->setAlignment(Qt::AlignRight);
	channel.status_led->setStyleSheet("background-color: red;");
}

void EFuseBoardWidget::deleteChannelPointers(ChannelGroupBox &channel)
{
	/* Deletes first the child pointers, otherwise the Qt Cretor crashes  */
	delete channel.label_channel;
	delete channel.label_current;
	delete channel.label_max_current;
	delete channel.label_power_up;
	delete channel.label_voltage;
	delete channel.label_led;
	delete channel.status_channel;
	delete channel.status_power_up;
	delete channel.status_voltage;
	delete channel.status_led;
	delete channel.value_current;
	delete channel.value_max_current;
	delete channel.progress_current;

	/* Deletes the parents pointer*/
	delete channel.monit_group_box;
	delete channel.config_group_box;

}

