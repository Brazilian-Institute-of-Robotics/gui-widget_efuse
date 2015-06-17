#include "EFuseBoardWidget.hpp"

EFuseBoardWidget::EFuseBoardWidget(QWidget *parent)
    : QWidget(parent)
{

    setFixedSize(520, 705);

    /* Creates a tab window with two tabs */
    tab_window = new QTabWidget(this);
    monit_tab = new QWidget(tab_window);
    config_tab = new QWidget(tab_window);
    tab_window->setGeometry(QRect(0, 0, 520, 705));
    tab_window->addTab(monit_tab, "Main Monit");
    tab_window->addTab(config_tab, "Full Monit");

    /* Board name label */
    board_label1 = new QLabel(QString("Board 1").toUpper(), monit_tab);
    board_label1->setFont(QFont("Verdana", 20, 100));
    board_label1->setGeometry(QRect(0, 20, 520, 50));
    board_label1->setAlignment(Qt::AlignCenter);
//    board_label1->setStyleSheet("border: 2px solid;");

    board_label2 = new QLabel(QString("Board 1").toUpper(), config_tab);
    board_label2->setFont(QFont("Verdana", 20, 100));
    board_label2->setGeometry(QRect(0, 20, 520, 50));
    board_label2->setAlignment(Qt::AlignCenter);
//    board_label2->setStyleSheet("border: 2px solid;");

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
	drawMonitChannel(ch1, 10, 90);
	drawMonitChannel(ch2, 10, 230);
	drawMonitChannel(ch3, 10, 380);
	drawMonitChannel(ch4, 10, 530);
	drawMonitChannel(ch5, 300, 90);
	drawMonitChannel(ch6, 300, 230);
	drawMonitChannel(ch7, 300, 380);
	drawMonitChannel(ch8, 300, 530);

    /* Draws Configuration Tab */
	drawConfigChannel(ch1, 10, 90);
	drawConfigChannel(ch2, 10, 230);
	drawConfigChannel(ch3, 10, 380);
	drawConfigChannel(ch4, 10, 530);
	drawConfigChannel(ch5, 300, 90);
	drawConfigChannel(ch6, 300, 230);
	drawConfigChannel(ch7, 300, 380);
	drawConfigChannel(ch8, 300, 530);

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

	delete board_label1;
	delete board_label2;
	delete config_tab;
	delete monit_tab;
	delete tab_window;
}

void EFuseBoardWidget::setBoardStatus(efuse_board::StatusBoard status_board)
{
	if(status_board.name != "")
	{
		board_label1->setText(QString::fromStdString((status_board.name)).toUpper());
		board_label2->setText(QString::fromStdString((status_board.name)).toUpper());
	}

	if(status_board.status_channel[0].name != "")
	{
		ch1.label_channel1->setText(QString::fromStdString((status_board.status_channel[0].name)));
		ch1.label_channel2->setText(QString::fromStdString((status_board.status_channel[0].name)));
	}

	if(status_board.status_channel[1].name != "")
	{
		ch2.label_channel1->setText(QString::fromStdString((status_board.status_channel[1].name)));
		ch2.label_channel2->setText(QString::fromStdString((status_board.status_channel[1].name)));
	}

	if(status_board.status_channel[2].name != "")
	{
		ch3.label_channel1->setText(QString::fromStdString((status_board.status_channel[2].name)));
		ch3.label_channel2->setText(QString::fromStdString((status_board.status_channel[2].name)));
	}

	if(status_board.status_channel[3].name != "")
	{
		ch4.label_channel1->setText(QString::fromStdString((status_board.status_channel[3].name)));
		ch4.label_channel2->setText(QString::fromStdString((status_board.status_channel[3].name)));
	}

	if(status_board.status_channel[4].name != "")
	{
		ch5.label_channel1->setText(QString::fromStdString((status_board.status_channel[4].name)));
		ch5.label_channel2->setText(QString::fromStdString((status_board.status_channel[4].name)));
	}

	if(status_board.status_channel[5].name != "")
	{
		ch6.label_channel1->setText(QString::fromStdString((status_board.status_channel[5].name)));
		ch6.label_channel2->setText(QString::fromStdString((status_board.status_channel[5].name)));
	}

	if(status_board.status_channel[6].name != "")
	{
		ch7.label_channel1->setText(QString::fromStdString((status_board.status_channel[6].name)));
		ch7.label_channel2->setText(QString::fromStdString((status_board.status_channel[6].name)));
	}

	if(status_board.status_channel[7].name != "")
	{
		ch8.label_channel1->setText(QString::fromStdString((status_board.status_channel[7].name)));
		ch8.label_channel2->setText(QString::fromStdString((status_board.status_channel[7].name)));
	}


//	if(status_board.chan_names.size() == 8)
//	{
//		ch1.label_channel1->setText(QString::fromStdString((status_board.chan_names[0])));
//		ch1.label_channel2->setText(QString::fromStdString((status_board.chan_names[0])));
//		ch2.label_channel1->setText(QString::fromStdString((status_board.chan_names[1])));
//		ch2.label_channel2->setText(QString::fromStdString((status_board.chan_names[1])));
//		ch3.label_channel1->setText(QString::fromStdString((status_board.chan_names[2])));
//		ch3.label_channel2->setText(QString::fromStdString((status_board.chan_names[2])));
//		ch4.label_channel1->setText(QString::fromStdString((status_board.chan_names[3])));
//		ch4.label_channel2->setText(QString::fromStdString((status_board.chan_names[3])));
//		ch5.label_channel1->setText(QString::fromStdString((status_board.chan_names[4])));
//		ch5.label_channel2->setText(QString::fromStdString((status_board.chan_names[4])));
//		ch6.label_channel1->setText(QString::fromStdString((status_board.chan_names[5])));
//		ch6.label_channel2->setText(QString::fromStdString((status_board.chan_names[5])));
//		ch7.label_channel1->setText(QString::fromStdString((status_board.chan_names[6])));
//		ch7.label_channel2->setText(QString::fromStdString((status_board.chan_names[6])));
//		ch8.label_channel1->setText(QString::fromStdString((status_board.chan_names[7])));
//		ch8.label_channel2->setText(QString::fromStdString((status_board.chan_names[7])));
//	}

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

	if(status_channel.check_voltage == true)
	{
		channel.status_channel1->setStyleSheet("background-color: green;");
		channel.status_channel2->setStyleSheet("background-color: green;");

	}
	else
	{
		channel.status_channel1->setStyleSheet("background-color: gray;");
		channel.status_channel2->setStyleSheet("background-color: gray;");
	}

	if(status_channel.default_on == true)
	{
		channel.status_power_up->setStyleSheet("background-color: green;");
	}
	else
	{
		channel.status_power_up->setStyleSheet("background-color: gray;");
	}

	if(status_channel.channel_on == true)
	{
		channel.status_turn_on->setStyleSheet("background-color: green;");
	}
	else
	{
		channel.status_turn_on->setStyleSheet("background-color: gray;");
	}

	if(status_channel.check_voltage == true &&
	   status_channel.channel_on == true    &&
	   status_channel.error_led == false)
	{
		channel.status_led->setStyleSheet("background-color: green;");
		channel.label_error->setVisible(false);
	}
	else if(status_channel.check_voltage == true &&
		    status_channel.channel_on == false   &&
			status_channel.error_led == false)
	{
		channel.status_led->setStyleSheet("background-color: red;");
		channel.label_error->setVisible(true);
	}
	else if(status_channel.ret_msg != 1)
	{
		channel.status_led->setStyleSheet("background-color: red;");
		channel.label_error->setVisible(true);
	}
	else
	{
		channel.status_led->setStyleSheet("background-color: gray;");
		channel.label_error->setVisible(false);
	}


	channel.value_current->setText(QString::number(status_channel.current));
	channel.value_max_current->setText(QString::number(status_channel.max_current));
	channel.progress_current->setValue((status_channel.current*10));
	channel.progress_current->setMaximum(status_channel.max_current*10);
}

void EFuseBoardWidget::drawMonitChannel(ChannelGroupBox &channel, int x_pos, int y_pos)
{

    int first_collumn = 10;
    int second_column = 140;
    int first_row = 10;
    int error_row = 32.5;
    int second_row = 55;
    int third_row = 85;
    int max_current = 10.5;

	channel.group_box1 = new QGroupBox(monit_tab);
	channel.group_box1->setGeometry(x_pos, y_pos, 200, 120);
	channel.group_box1->setStyleSheet("QGroupBox{border: 2px solid;}");

    /* CHANNEL LABEL */

	channel.label_channel1 = new QLabel("CH "+channel.chan_num,channel.group_box1);
	channel.label_channel1->setObjectName("monit_label_ch"+channel.chan_num);
	channel.label_channel1->setFont(QFont("Verdana", 10, 100));
	channel.label_channel1->setGeometry(QRect(first_collumn, first_row, 120, 42.5));
	channel.label_channel1->setAlignment(Qt::AlignHCenter);
	channel.label_channel1->setWordWrap(true);

    /* CHANNEL STATUS */

	channel.status_channel1 = new QLabel("",channel.group_box1);
	channel.status_channel1->setObjectName("monit_ch"+channel.chan_num+"_power");
	channel.status_channel1->setAlignment(Qt::AlignHCenter);
	channel.status_channel1->setGeometry(QRect(second_column, first_row+2.5, 50, 15));
	channel.status_channel1->setStyleSheet("background-color: gray;");

    /* ERROR LABEL */

	channel.label_error = new QLabel("ERROR",channel.group_box1);
	channel.label_error->setObjectName("label_ch"+channel.chan_num+"_error");
	channel.label_error->setFont(QFont("Verdana", 8, 100));
	channel.label_error->setGeometry(QRect(second_column, error_row, 50, 20));
	channel.label_error->setAlignment(Qt::AlignHCenter);
	channel.label_error->setStyleSheet("color: red;");
	channel.label_error->setVisible(false);

	/* ACTUAL CURRENT LABEL */

	channel.label_current = new QLabel("Current [A]",channel.group_box1);
	channel.label_current->setObjectName("label_ch"+channel.chan_num+"_actual_curr");
	channel.label_current->setFont(QFont("Verdana", 10));
	channel.label_current->setGeometry(QRect(first_collumn, second_row, 115, 25));
	channel.label_current->setAlignment(Qt::AlignHCenter);

	/* ACTUAL CURRENT VALUE */

	channel.value_current = new QLabel("0",channel.group_box1);
	channel.value_current->setObjectName("ch"+channel.chan_num+"_actual_curr");
	channel.value_current->setFont(QFont("Verdana", 10));
	channel.value_current->setGeometry(QRect(second_column, second_row, 50, 25));
	channel.value_current->setAlignment(Qt::AlignHCenter);

	/* PROGRESS BAR CURRENT */

	channel.progress_current = new QProgressBar(channel.group_box1);
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

	channel.group_box2 = new QGroupBox(config_tab);
	channel.group_box2->setGeometry(x_pos, y_pos, 200, 120);
	channel.group_box2->setStyleSheet("QGroupBox{border: 2px solid;}");

    /* CHANNEL LABEL */

	channel.label_channel2 = new QLabel("CH "+channel.chan_num,channel.group_box2);
	channel.label_channel2->setObjectName("config_label_ch"+channel.chan_num);
	channel.label_channel2->setFont(QFont("Verdana", 10, 100));
	channel.label_channel2->setGeometry(QRect(first_collumn, first_row, 120, 20));
	channel.label_channel2->setAlignment(Qt::AlignHCenter);

    /* CHANNEL ON */

	channel.status_channel2 = new QLabel("",channel.group_box2);
	channel.status_channel2->setObjectName("config_ch"+channel.chan_num+"_power");
	channel.status_channel2->setAlignment(Qt::AlignHCenter);
	channel.status_channel2->setGeometry(QRect(second_column, first_row+2.5, 50, 15));
	channel.status_channel2->setStyleSheet("background-color: gray;");

	/* MAXIMUM CURRENT LABEL */

	channel.label_max_current = new QLabel("Max. Cur. [A]",channel.group_box2);
	channel.label_max_current->setObjectName("label_ch"+channel.chan_num+"_max_curr");
	channel.label_max_current->setFont(QFont("Verdana", 10));
	channel.label_max_current->setGeometry(QRect(first_collumn, second_row, 100, 20));
	channel.label_max_current->setAlignment(Qt::AlignLeft);

	/* MAXIMUM CURRENT VALUE */

	channel.value_max_current = new QLabel("10.5",channel.group_box2);
	channel.value_max_current->setObjectName("ch"+channel.chan_num+"_max_curr");
	channel.value_max_current->setFont(QFont("Verdana", 10));
	channel.value_max_current->setAlignment(Qt::AlignHCenter);
	channel.value_max_current->setGeometry(QRect(second_column, second_row, 50, 20));

	/* DEFAULT ON LABEL */

	channel.label_power_up = new QLabel("Default On",channel.group_box2);
	channel.label_power_up->setObjectName("label_ch"+channel.chan_num+"_power_up");
	channel.label_power_up->setFont(QFont("Verdana", 10));
	channel.label_power_up->setGeometry(QRect(first_collumn, third_row, 100, 20));
	channel.label_power_up->setAlignment(Qt::AlignLeft);

	/* DEFAULT ON STATUS */

	channel.status_power_up = new QLabel("",channel.group_box2);
	channel.status_power_up->setObjectName("ch"+channel.chan_num+"_power_up");
	channel.status_power_up->setGeometry(QRect(second_column+15, third_row+5, 20, 10));
	channel.status_power_up->setAlignment(Qt::AlignRight);
	channel.status_power_up->setStyleSheet("background-color: gray;");

	/* VOLTAGE LABEL */

	channel.label_turn_on = new QLabel("Turn ON",channel.group_box2);
	channel.label_turn_on->setObjectName("label_ch"+channel.chan_num+"_voltage");
	channel.label_turn_on->setFont(QFont("Verdana", 10));
	channel.label_turn_on->setGeometry(QRect(first_collumn, fourth_row, 100, 20));
	channel.label_turn_on->setAlignment(Qt::AlignLeft);

	/* VOLTAGE STATUS */

	channel.status_turn_on = new QLabel("",channel.group_box2);
	channel.status_turn_on->setObjectName("ch"+channel.chan_num+"_voltage");
	channel.status_turn_on->setGeometry(QRect(second_column+15, fourth_row+5, 20, 10));
	channel.status_turn_on->setAlignment(Qt::AlignRight);
	channel.status_turn_on->setStyleSheet("background-color: gray;");

	/* ERROR LED LABEL */

	channel.label_led = new QLabel("LED",channel.group_box2);
	channel.label_led->setObjectName("label_ch"+channel.chan_num+"_check_led");
	channel.label_led->setFont(QFont("Verdana", 10));
	channel.label_led->setGeometry(QRect(first_collumn, fith_row, 100, 20));
	channel.label_led->setAlignment(Qt::AlignLeft);

	/* ERROR LED STATUS */

	channel.status_led = new QLabel("",channel.group_box2);
	channel.status_led->setObjectName("ch"+channel.chan_num+"_check_led");
	channel.status_led->setGeometry(QRect(second_column+15, fith_row+5, 20, 10));
	channel.status_led->setAlignment(Qt::AlignRight);
	channel.status_led->setStyleSheet("background-color: gray;");
}

void EFuseBoardWidget::deleteChannelPointers(ChannelGroupBox &channel)
{
	/* Deletes first the child pointers, otherwise the Qt Cretor crashes  */

	/* Main Monit */
	delete channel.label_channel1;
	delete channel.label_current;
	delete channel.status_channel1;
	delete channel.value_current;
	delete channel.progress_current;

	/* Full Monit */
	delete channel.label_channel2;
	delete channel.label_max_current;
	delete channel.label_power_up;
	delete channel.label_turn_on;
	delete channel.label_led;
	delete channel.status_channel2;
	delete channel.status_power_up;
	delete channel.status_turn_on;
	delete channel.status_led;
	delete channel.value_max_current;


	/* Deletes the parents pointer*/
	delete channel.group_box1;
	delete channel.group_box2;

}

