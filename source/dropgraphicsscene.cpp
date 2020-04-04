#include <QDebug>
#include <QUrl>
#include "dropgraphicsscene.h"

dropGraphicsScene::dropGraphicsScene(QObject* parent) : QGraphicsScene(parent)
{}

void dropGraphicsScene::dragEnterEvent(QDragEnterEvent *event)
{
event->acceptProposedAction();
}

void dropGraphicsScene::dragMoveEvent(QDragMoveEvent *event)
{
//	event->acceptProposedAction();
}

void dropGraphicsScene::dropEvent(QDropEvent *event)
{
	
	const QMimeData* mimeData = event->mimeData();

	// check if it is an image file
	if (mimeData->hasUrls())
		{
		clear();
		addPixmap(QPixmap(QUrl(mimeData->text()).toLocalFile()).scaled(this->width(), this->height(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
		event->acceptProposedAction();
		}
}

dropGraphicsScene::~dropGraphicsScene()
{}

