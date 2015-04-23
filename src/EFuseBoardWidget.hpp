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
//    QMainWindow *MainWindow;
//    QLabel *label;
//    QMenuBar *menubar;
//    QStatusBar *statusbar;
//    QFrame *frame;
//    QGroupBox *group_box_ch1;
//    QLabel *label_ch1;
//    QLabel *label_ch1_max_curr;
//    QLabel *label_ch1_actual_curr;
//    QLabel *label_ch1_power_up;
//    QLabel *label_ch1_check_voltage;
//    QLabel *label_ch1_check_led;
//
//    QLabel *ch1_power;
//    QLabel *ch1_max_curr;
//    QLabel *ch1_actual_curr;
//    QLabel *ch1_power_up;
//    QLabel *ch1_check_voltage;
//    QLabel *ch1_check_led;

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


//    QGroupBox *group_box_ch1;
//    QFormLayout *flay;
//    QFormLayout *flay2;
};

#endif /* EFUSEBOARDWIDGET_HPP */
