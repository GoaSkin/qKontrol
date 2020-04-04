#ifndef _DROPGRAPHICSSCENE_H_
#define _DROPGRAPHICSSCENE_H_

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QGraphicsScene>
#include <QMimeData>

class dropGraphicsScene : public QGraphicsScene
{
	Q_OBJECT

	public:
		explicit dropGraphicsScene(QObject *parent = 0);
		~dropGraphicsScene();

	private:
		QGraphicsScene scene;

	protected:
		void dragEnterEvent(QDragEnterEvent *event);
		void dragMoveEvent(QDragMoveEvent *event);
		void dropEvent(QDropEvent *event);

	protected slots:

	public slots:
};

#endif /*_DROPGRAPHICSSCENE_H_*/
