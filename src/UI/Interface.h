/*=======================================================================
*
*   Copyright (C) 2013-2015 Lysine.
*
*   Filename:    Interface.h
*   Time:        2013/03/18
*   Author:      Lysine
*   Contributor: Chaserhkj
*
*   Lysine is a student majoring in Software Engineering
*   from the School of Software, SUN YAT-SEN UNIVERSITY.
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.

*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
=========================================================================*/

#pragma once

#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>

class Post;
class List;
class Load;
class APlayer;
class Danmaku;
class ARender;

namespace UI
{
	class Menu;
	class Info;
	class Jump;
	class Type;
}

class Interface :public QWidget
{
	Q_OBJECT
public:
	explicit Interface(QWidget *parent = 0);

private:
	QTimer *timer;
	QTimer *delay;

	QAction *quitA;
	QAction *fullA;
	QAction *confA;
	QAction *toggA;
	QAction *listA;
	QAction *postA;
	QMenu *rat;
	QMenu *sca;
	QMenu *spd;
	QPointer<QDialog> msg;

	UI::Menu *menu;
	UI::Info *info;
	UI::Jump *jump;
	UI::Type *type;
	Post *post;
	List *list;
	Load *load;
	APlayer *aplayer;
	Danmaku *danmaku;
	ARender *arender;

	QPoint sta;
	QPoint wgd;
	QByteArray geo;

	bool showprg;
	bool sliding;

	void closeEvent(QCloseEvent *e);
	void dragEnterEvent(QDragEnterEvent *e);
	void dropEvent(QDropEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void resizeEvent(QResizeEvent *e);

signals:
	void windowFlagsChanged(QFlags<Qt::WindowType>);

public slots:
	void tryLocal(QString path);
	void tryLocal(QStringList paths);
	void setWindowFlags();
	void percent(double degree);
	void warning(QString title, QString text);

private slots:
	void checkForUpdate();
	void setCenter(QSize s, bool f);
	void showContextMenu(QPoint p);
};
