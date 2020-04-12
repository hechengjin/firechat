#ifndef SETTINGDIALOG_H 
#define  SETTINGDIALOG_H

//#include <QtGui>
#include <QDialog>
#include "widgets/push_button.h"
#include "util/common.h"
class QHBoxLayout;
class QLabel;
class QTabWidget;
class QGroupBox;
class QRadioButton;
class QCheckBox;
class QComboBox;


class SettingDialog : public QDialog
{
	Q_OBJECT

public:

	explicit SettingDialog(QWidget *parent = 0);
	~SettingDialog();
	void translateLanguage();


signals:

    void changeLanguage(LANGUAGE ui_language);

private slots:

    void updateConfig();

protected:

	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);

private:

	void initTitle();
	void initCenter();
    void initBottom();
    void initTabUserSet();

private:

	QPoint move_point; //移动的距离
	bool mouse_press; //按下鼠标左键

	QHBoxLayout *title_layout; //标题布局
	QLabel *title_icon_label; //标题图标
	QLabel *title_label; //标题
	PushButton *close_button; //关闭按钮

	QHBoxLayout *bottom_layout; //底部布局
	QPushButton *ok_button; //确定按钮
	QPushButton *cancel_button; //取消按钮

	QTabWidget *tab_widget; 


    QWidget *userSet; //用户设置
    QGroupBox *tab_userset_group_box;
    QCheckBox *tray_quit_check_box; //托盘退出登录后显示提示窗口
	QCheckBox *rise_remind_check_box; //升级提醒通知窗口
    QLabel *language_label; //语言标签
    QComboBox *language_combo_box; //语言下拉框


};

#endif SETTINGDIALOG_H
