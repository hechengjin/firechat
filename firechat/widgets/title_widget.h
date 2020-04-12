#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

//#include <QtGui>
#include "push_button.h"
#include "tool_button.h"

class QLabel;

class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWidget(QWidget *parent = 0);
	void translateLanguage();

signals:
	void showSkin();
    void showMin();
    void showMax();
	void showMainMenu();
	void closeWidget(); 

//public slots:

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

private:

    QPoint press_point;//鼠标按下去的点
    bool is_move;

    QLabel *title_icon_label; //标题图标
    QLabel *version_title; //标题
    PushButton *skin_button; //换肤
    PushButton *main_menu_button; //主菜单
    PushButton *min_button; //最小化
    PushButton *max_button; //最大化
    PushButton *close_button; //关闭
};

#endif // TITLEWIDGET_H
