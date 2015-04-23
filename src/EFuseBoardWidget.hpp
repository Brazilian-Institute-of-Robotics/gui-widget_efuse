#ifndef EFUSEBOARDWIDGET_HPP
#define EFUSEBOARDWIDGET_HPP

#include <QtGui>

class EFuseBoardWidget : public QWidget
{
    Q_OBJECT
public:
    EFuseBoardWidget(QWidget *parent = 0);
    virtual ~EFuseBoardWidget();
    void drawMonitoringTab(QGroupBox *group_box, QLabel *power, QLabel *actual_current,
			 	 	 	   QLabel *max_current, int x_pos, int y_pos);
    void drawConfigurationTab();

private:
//    QMainWindow *MainWindow;
//    QLabel *label;
//    QMenuBar *menubar;
//    QStatusBar *statusbar;
//    QFrame *frame;
//    QGroupBox *group_box_ch1;
    QLabel *label_ch1;
    QLabel *label_ch1_max_curr;
    QLabel *label_ch1_actual_curr;
    QLabel *label_ch1_power_up;
    QLabel *label_ch1_check_voltage;
    QLabel *label_ch1_check_led;

    QLabel *ch1_power;
    QLabel *ch1_max_curr;
    QLabel *ch1_actual_curr;
    QLabel *ch1_power_up;
    QLabel *ch1_check_voltage;
    QLabel *ch1_check_led;

    QGroupBox *group_box_ch1;
    QFormLayout *flay;
    QFormLayout *flay2;
};

#endif /* EFUSEBOARDWIDGET_HPP */
