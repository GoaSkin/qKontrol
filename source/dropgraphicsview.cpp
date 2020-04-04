#include <QDebug>
#include <QUrl>
#include "dropgraphicsview.h"

dropGraphicsView::dropGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
this->setFrameShape(QFrame::Box);
this->setFrameShadow(QFrame::Plain);
this->setScene(&scene);
scene.clear();
scene.addRect(QRect(0, 0, this->width(), this->height()), QPen(Qt::black), QBrush(Qt::SolidPattern));
}

void dropGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
event->acceptProposedAction();
}

void dropGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
event->acceptProposedAction();
}

void dropGraphicsView::dropEvent(QDropEvent *event)
{
 const QMimeData* mimeData = event->mimeData();
scene.clear();
currentFile = QUrl(mimeData->text()).toLocalFile().trimmed();
scene.addPixmap(QPixmap(currentFile).scaled(this->width()-4, this->height()-4, Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
event->acceptProposedAction();
}

void dropGraphicsView::setImage(QString file)
{
scene.clear();
currentFile = file;
scene.addPixmap(QPixmap(currentFile).scaled(this->width()-4, this->height()-4, Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

dropGraphicsView::~dropGraphicsView()
{}

