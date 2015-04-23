#ifndef EFUSEBOARDWIDGET_HPP
#define EFUSEBOARDWIDGET_HPP

#include <QtGui>

struct ChannelGroupBox
{
	QGroupBox 		*group_box;
	QLabel 			*label_channel;
	QLabel 			*status_channel;
	QLabel 			*label_current;
	QLabel 			*value_current;
	QProgressBar 	*progress_current;
	QString  	 	 chan_num;
	int				 max_current;
};

class EFuseBoardWidget : public QWidget
{
    Q_OBJECT
public:
    EFuseBoardWidget(QWidget *parent = 0);
    virtual ~EFuseBoardWidget();
    void drawMonitoringTab();
    void drawChannel(ChannelGroupBox &channel, int x_pos, int y_pos);
    void drawConfigurationTab();

private:

    ChannelGroupBox ch1;
    ChannelGroupBox ch2;
    ChannelGroupBox ch3;
    ChannelGroupBox ch4;
    ChannelGroupBox ch5;
    ChannelGroupBox ch6;
    ChannelGroupBox ch7;
    ChannelGroupBox ch8;

    QTabWidget *tab_window;
    QWidget *config_tab;
    QWidget *monit_tab;

};

#endif /* EFUSEBOARDWIDGET_HPP */
