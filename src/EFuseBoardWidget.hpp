#ifndef EFUSEBOARDWIDGET_HPP
#define EFUSEBOARDWIDGET_HPP

#include <QtGui>
#include <boost/shared_ptr.hpp>


struct ChannelGroupBox
{
	QGroupBox 		*monit_group_box;
	QGroupBox 		*config_group_box;
	QLabel 			*label_channel;
	QLabel 			*label_current;
	QLabel 			*label_max_current;
	QLabel 			*label_power_up;
	QLabel 			*label_voltage;
	QLabel 			*label_led;
	QLabel 			*status_channel;
	QLabel 			*status_power_up;
	QLabel 			*status_voltage;
	QLabel 			*status_led;
	QLabel 			*value_current;
	QLabel 			*value_max_current;
	QProgressBar 	*progress_current;
	QString  	 	 chan_num;
};

class EFuseBoardWidget : public QWidget
{
    Q_OBJECT
public:
    EFuseBoardWidget(QWidget *parent = 0);
    virtual ~EFuseBoardWidget();
    void drawMonitChannel(ChannelGroupBox &channel, int x_pos, int y_pos);
    void drawConfigChannel(ChannelGroupBox &channel, int x_pos, int y_pos);

private:

    ChannelGroupBox ch1;
    ChannelGroupBox ch2;
    ChannelGroupBox ch3;
    ChannelGroupBox ch4;
    ChannelGroupBox ch5;
    ChannelGroupBox ch6;
    ChannelGroupBox ch7;
    ChannelGroupBox ch8;

    boost::shared_ptr<QTabWidget> 	tab_window;
    boost::shared_ptr<QWidget> 		config_tab;
    boost::shared_ptr<QWidget> 		monit_tab;

};

#endif /* EFUSEBOARDWIDGET_HPP */
