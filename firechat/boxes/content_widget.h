#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QObject>
#include <QWidget>

class ContentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ContentWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // CONTENTWIDGET_H