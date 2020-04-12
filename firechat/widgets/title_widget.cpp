#include "title_widget.h"
//#include "tool_button.h"

#include "tool_button.h"
#include <QLabel>
#include <QHBoxLayout>
TitleWidget::TitleWidget(QWidget *parent)
	:QWidget(parent)
{
    title_icon_label = new QLabel();
    version_title = new QLabel();
    skin_button = new PushButton();
    main_menu_button = new PushButton();
    min_button = new PushButton();
    max_button = new PushButton();
    close_button = new PushButton();


    QPixmap title_pixmap(":/img/firechat");
    title_icon_label->setPixmap(title_pixmap);
    title_icon_label->setFixedSize(16, 16);
    title_icon_label->setScaledContents(true);

	version_title->setStyleSheet("color:white;");



	//设置图片

	skin_button->loadPixmap(":/sysButton/skin_button");
	main_menu_button->loadPixmap(":/sysButton/main_menu");
	min_button->loadPixmap(":/sysButton/min_button");
	max_button->loadPixmap(":/sysButton/max_button");
	close_button->loadPixmap(":/sysButton/close_button");



	connect(skin_button, SIGNAL(clicked()), this, SIGNAL(showSkin()));
	connect(main_menu_button, SIGNAL(clicked()), this, SIGNAL(showMainMenu()));
	connect(min_button, SIGNAL(clicked()), this, SIGNAL(showMin()));
	connect(max_button, SIGNAL(clicked()), this, SIGNAL(showMax()));
    connect(close_button, SIGNAL(clicked()), this, SIGNAL(closeWidget()));

    QHBoxLayout *title_layout = new QHBoxLayout();
    title_layout->addWidget(title_icon_label,0,Qt::AlignVCenter);
    title_layout->addWidget(version_title,0,Qt::AlignVCenter);
    title_layout->addStretch();
    title_layout->addWidget(skin_button, 0, Qt::AlignTop);
    title_layout->addWidget(main_menu_button, 0, Qt::AlignTop);
    title_layout->addWidget(min_button, 0, Qt::AlignTop);
    title_layout->addWidget(max_button, 0, Qt::AlignTop);
    title_layout->addWidget(close_button, 0, Qt::AlignTop);
	title_layout->setSpacing(0);
    title_layout->setContentsMargins(5, 0, 5, 0);
    version_title->setContentsMargins(5, 0, 0, 0);
	skin_button->setContentsMargins(0, 0, 10, 0);

	QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addLayout(title_layout);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(0, 0, 0, 0);

	this->translateLanguage();

    setLayout(main_layout);
    setFixedHeight(20);
    is_move = false;
}

void TitleWidget::translateLanguage()
{
	version_title->setText(tr("title"));
	skin_button->setToolTip(tr("change skin"));
	main_menu_button->setToolTip(tr("main menu"));
	min_button->setToolTip(tr("minimize"));
	max_button->setToolTip(tr("maximize"));
	close_button->setToolTip(tr("close"));
}

void TitleWidget::mousePressEvent(QMouseEvent *e)
{
    press_point = e->pos();
    is_move = true;
}

void TitleWidget::mouseMoveEvent(QMouseEvent *e)
{
    if((e->buttons() == Qt::LeftButton) && is_move)
    {
        static QWidget* parent_widget = this->parentWidget();
        QPoint parent_point = parent_widget->pos();
        parent_point.setX(parent_point.x() + e->x() - press_point.x());
        parent_point.setY(parent_point.y() + e->y() - press_point.y());
        parent_widget->move(parent_point);
    }
}

void TitleWidget::mouseReleaseEvent(QMouseEvent *)
{
    if(is_move)
	{
		is_move = false;
	}
}

void TitleWidget::mouseDoubleClickEvent(QMouseEvent *)
{
    emit showMax();
}


