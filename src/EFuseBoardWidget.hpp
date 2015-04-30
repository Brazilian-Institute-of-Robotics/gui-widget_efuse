#ifndef EFUSEBOARDWIDGET_HPP
#define EFUSEBOARDWIDGET_HPP

#include <QtGui>
#include <boost/shared_ptr.hpp>
#include "efuse_board/DataTypes.hpp"


struct ChannelGroupBox
{
	QString  	 	 chan_num;

	/* Main Monit */
	QGroupBox 		*group_box1;
	QLabel 			*label_channel1;
	QLabel 			*label_current;
	QLabel 			*status_channel1;
	QLabel 			*value_current;
	QLabel 			*label_error;
	QProgressBar 	*progress_current;

	/* Full Monit */
	QGroupBox 		*group_box2;
	QLabel 			*label_channel2;
	QLabel 			*label_max_current;
	QLabel 			*label_power_up;
	QLabel 			*label_turn_on;
	QLabel 			*label_led;
	QLabel 			*value_max_current;
	QLabel 			*status_channel2;
	QLabel 			*status_power_up;
	QLabel 			*status_turn_on;
	QLabel 			*status_led;
};

class EFuseBoardWidget : public QWidget
{
    Q_OBJECT
public:
    EFuseBoardWidget(QWidget *parent = 0);
    virtual ~EFuseBoardWidget();

public slots:
    void setBoardStatus(efuse_board::StatusBoard status_board);

private:
    void setChannelStatus(efuse_board::StatusChannel &status_channel, ChannelGroupBox &channel);
    void drawMonitChannel(ChannelGroupBox &channel, int x_pos, int y_pos);
    void drawConfigChannel(ChannelGroupBox &channel, int x_pos, int y_pos);
    void deleteChannelPointers(ChannelGroupBox &channel);

private:

    ChannelGroupBox ch1;
    ChannelGroupBox ch2;
    ChannelGroupBox ch3;
    ChannelGroupBox ch4;
    ChannelGroupBox ch5;
    ChannelGroupBox ch6;
    ChannelGroupBox ch7;
    ChannelGroupBox ch8;

    QTabWidget 	*tab_window;
    QWidget 	*config_tab;
    QWidget 	*monit_tab;
    QLabel		*board_label1;
    QLabel		*board_label2;

};

#endif /* EFUSEBOARDWIDGET_HPP */
