#ifndef _DROPGRAPHICSVIEW_H_
#define _DROPGRAPHICSVIEW_H_

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QGraphicsView>
#include <QMimeData>
#include "dropgraphicsscene.h"

class dropGraphicsView : public QGraphicsView
{
	Q_OBJECT

	public:
		explicit dropGraphicsView(QWidget *parent = 0);
		void setImage(QString file);
		QString currentFile;
		~dropGraphicsView();

	private:
		dropGraphicsScene scene;

	protected:
		void dragEnterEvent(QDragEnterEvent *event);
		void dragMoveEvent(QDragMoveEvent *event);
		void dropEvent(QDropEvent *event);

	protected slots:

	public slots:
};

#endif /*_DROPGRAPHICSVIEW_H_*/
