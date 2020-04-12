#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QTranslator>
#include "widgets/title_widget.h"
#include "widgets/main_menu.h"
#include "widgets/system_tray.h"
#include "setting_dialog.h"
#include "skin_widget.h"
#include "content_widget.h"
#include "about_us.h"


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

public slots:
    void showWidget();
    void setTranslator(QTranslator* translator);
    void translateLanguage();

private slots:
    void showMax();
    void showMainMenu();
    void showAboutUs();
    void changeSkin(QString skin_name);
    void showSkinWidget();
    void showSettingDialog();
    void iconIsActived(QSystemTrayIcon::ActivationReason reason);
    void changeLanguage(LANGUAGE language);

private:
    QRect location;
    TitleWidget *title_widget; //标题栏
    QString skin_name;//主窗口背景图片的名称
    ContentWidget *content_widget; //主界面内容
    MainMenu *main_menu; //主菜单
    SystemTray *system_tray; //托盘项
    AboutUsDialog *about_us_dialog; //关于我们界面
    SkinWidget *skin_widget; //显示皮肤界面
    SettingDialog *setting_dialog; //设置界面

    QTranslator* translator; //翻译器
    LANGUAGE current_language; //当前语言

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAIN_WIDGET_H
