#include "setting_dialog.h"
//#include "util.h"
#include "util/util.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QTabWidget>
#include <QComboBox>
SettingDialog::SettingDialog(QWidget *parent)
	: QDialog(parent)
{
	resize(560, 400);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->initTitle();
    this->initCenter();
    this->initTabUserSet();
	this->initBottom();

	QVBoxLayout *main_layout = new QVBoxLayout();
	main_layout->addLayout(title_layout);
    main_layout->addWidget(tab_widget); //999999999999999999999
	main_layout->addLayout(bottom_layout);
	main_layout->addStretch();
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(0, 0, 0, 0);

	setLayout(main_layout);
	mouse_press = false;
	this->translateLanguage();
}

void SettingDialog::initTitle()
{
	title_label = new QLabel();
	title_icon_label = new QLabel();
	close_button = new PushButton();
	close_button->loadPixmap(":/sysButton/close");

	title_label->setStyleSheet("color:white;");
    QPixmap pixmap(":/img/firechat");
	title_icon_label->setPixmap(pixmap);
	title_icon_label->setFixedSize(16, 16);
	title_icon_label->setScaledContents(true);
	
	title_layout = new QHBoxLayout();
	title_layout->addWidget(title_icon_label, 0, Qt::AlignVCenter);
	title_layout->addWidget(title_label, 0, Qt::AlignVCenter);
	title_layout->addStretch();
	title_layout->addWidget(close_button, 0, Qt::AlignTop);
	title_layout->setSpacing(5);
	title_layout->setContentsMargins(10, 0, 5, 10);

	connect(close_button, SIGNAL(clicked()), this, SLOT(hide()));
}

void SettingDialog::initTabUserSet()
{
    tab_userset_group_box = new QGroupBox();
    tray_quit_check_box = new QCheckBox();
	rise_remind_check_box = new QCheckBox();

    language_label = new QLabel();
    language_combo_box = new QComboBox();

    language_combo_box->addItem("chinese", UI_ZH);
    language_combo_box->addItem("english", UI_EN);
    language_label->setBuddy(language_combo_box);
    language_combo_box->setFixedWidth(70);

    QHBoxLayout *language_layout = new QHBoxLayout();
    language_layout->addWidget(language_label);
    language_layout->addStretch(1);
    language_layout->addWidget(language_combo_box);
    language_layout->addStretch(10);

    tab_userset_group_box->setStyleSheet("QGroupBox::title{color:green;}");
    QFont group_box_font = tab_userset_group_box->font();
	group_box_font.setBold(true);
    tab_userset_group_box->setFont(group_box_font);
    tab_userset_group_box->setFixedSize(480, 180);

    QVBoxLayout *group_layout = new QVBoxLayout();
    group_layout->addWidget(tray_quit_check_box);
	group_layout->addWidget(rise_remind_check_box);
    group_layout->addLayout(language_layout);
	group_layout->setSpacing(0);
	group_layout->setContentsMargins(30, 0, 0, 0);
    tab_userset_group_box->setLayout(group_layout);

    QVBoxLayout *tab_userSet_layout = new QVBoxLayout();
    tab_userSet_layout->addWidget(tab_userset_group_box, 0 , Qt::AlignCenter);
    tab_userSet_layout->addStretch();
    tab_userSet_layout->setSpacing(0);
    tab_userSet_layout->setContentsMargins(0, 20, 0, 0);
    userSet->setLayout(tab_userSet_layout);
}



void SettingDialog::initCenter()
{
	tab_widget = new QTabWidget();
    tab_widget->setFixedSize(this->width(), 320);
    userSet = new QWidget();

	tab_widget->setStyleSheet("QTabWidget::pane{border: 0px;}"
        "QTabWidget::tab-bar{alignment:left;}"
		"QTabBar::tab{background:transparent; color:white; min-width:30ex; min-height:10ex;}"
		"QTabBar::tab:hover{background:rgb(255, 255, 255, 100);}"
		"QTabBar::tab:selected{border-color: white;background:white;color:green;}");
}

void SettingDialog::initBottom()
{
	ok_button = new QPushButton();
	cancel_button = new QPushButton();

	ok_button->setFixedSize(75, 25);
	cancel_button->setFixedSize(75, 25);
	ok_button->setStyleSheet("QPushButton{border:1px solid lightgray; background:rgb(230,230,230);}"
		"QPushButton:hover{border-color:green; background:transparent;}");
	cancel_button->setStyleSheet("QPushButton{border:1px solid lightgray; background:rgb(230,230,230);}"
		"QPushButton:hover{border-color:green; background:transparent;}");

	bottom_layout = new QHBoxLayout();
	bottom_layout->addStretch();
	bottom_layout->addWidget(ok_button);
	bottom_layout->addWidget(cancel_button);
	bottom_layout->setSpacing(20);
	bottom_layout->setContentsMargins(0, 10, 20, 0);

    connect(ok_button, SIGNAL(clicked()), this, SLOT(updateConfig()));
	connect(cancel_button, SIGNAL(clicked()), this, SLOT(hide()));
}

SettingDialog::~SettingDialog()
{

}

void SettingDialog::translateLanguage()
{
	QString space_str = QString("    ");
    title_label->setText(tr("setting"));
    close_button->setToolTip(tr("close"));

    tab_widget->addTab(userSet, tr("user setting"));

    tab_userset_group_box->setTitle(tr("common setting"));
    tray_quit_check_box->setText(tr("tray quit"));
	rise_remind_check_box->setText(tr("rise remind"));
    language_label->setText(tr("language"));
    language_combo_box->setItemText(0, tr("chinese"));
    language_combo_box->setItemText(1, tr("english"));


	ok_button->setText(tr("ok"));
	cancel_button->setText(tr("cancel"));
}

void SettingDialog::paintEvent(QPaintEvent *)
{
	QString skin_name;
	bool is_read = Util::readInit(QString("./user.ini"), QString("skin"), skin_name);
	if(is_read)
	{
		if(skin_name.isEmpty())
        {
            skin_name = QString(":/skin/default_big");
		}
	}
	else
	{
        skin_name = QString(":/skin/default_big");
	}

	QPainter painter(this);
	painter.drawPixmap(rect(), QPixmap(skin_name));

	QPainter painter2(this);
	QLinearGradient linear2(rect().topLeft(), rect().bottomLeft());
	linear2.setColorAt(0, Qt::white);
	linear2.setColorAt(0.5, Qt::white);
	linear2.setColorAt(1, Qt::white);
	painter2.setPen(Qt::white); //设定画笔颜色，到时侯就是边框颜色
	painter2.setBrush(linear2);
	painter2.drawRect(QRect(0, 60, this->width(), this->height()-60));

	QPainter painter3(this);
	painter3.setPen(Qt::gray);
	static const QPointF points[4] = {QPointF(0, 60), QPointF(0, this->height()-1), QPointF(this->width()-1, this->height()-1), QPointF(this->width()-1, 60)};
	painter3.drawPolyline(points, 4);
}

void SettingDialog::mousePressEvent( QMouseEvent * event )
{
	//只能是鼠标左键移动和改变大小
	if(event->button() == Qt::LeftButton) 
	{
		mouse_press = true;
	}

	//窗口移动距离
	move_point = event->globalPos() - pos(); 
}

void SettingDialog::mouseReleaseEvent(QMouseEvent *)
{
	mouse_press = false;
}

void SettingDialog::mouseMoveEvent(QMouseEvent *event)
{
	//移动窗口
	if(mouse_press)   
	{
		QPoint move_pos = event->globalPos();
		move(move_pos - move_point);
	}
}

void SettingDialog::updateConfig()
{
    int index = language_combo_box->currentIndex();
    LANGUAGE ui_language = (LANGUAGE)language_combo_box->itemData(index).toInt();
    emit changeLanguage(ui_language);
    this->hide();
}
