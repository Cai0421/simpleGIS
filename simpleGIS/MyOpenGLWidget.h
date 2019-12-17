#pragma once


#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
//#include <GL/gl.h>
#include <QMouseEvent>
//#include <qopengl.h>
//#include <qopenglfunctions.h>
#include <qopenglshaderprogram.h>
#include <QWheelEvent>
//ͼ�㲿��
#include "CGeoPolyline.h"
#include "CGeoLayer.h"
#include "CGeoObject.h"
#include "CGeoPolygon.h"
#include <qopenglwidget.h>
#include <qwidget.h>
#include <CGeoMap.h>

class MyOpenGLWidget :
	public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT
public:
	QOpenGLShaderProgram* program;
	GLuint programId;
	GLuint verVbo;
	GLuint indexVbo;
	GLuint colorVbo;
	GLuint  matrixLocation;
	GLuint vertexLocation;
	GLuint clorLocation;
	QMatrix4x4  projection;
	GLsizei vVerticesLen;
	GLsizei triIndexLen;
	GLsizei colorsLen;
	explicit MyOpenGLWidget(QWidget* parent = 0);
private:
	CGeoMap* map = NULL;
	bool draw_flag = false;
	int x_trans = 0;
	int y_trans = 0;
	int width;
	int height;
	float zoom = -40.0f;
	//����¼���������
	bool mouse_drag = false;
	QPointF start_point;
	QPointF end_point;

	double DCWidth;
	double DCHeight;
	double DCLeft;
	double DCBottom;
	double geo_minX, geo_minY, geo_maxX, geo_maxY;
protected:
	
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;

	void drawMap(CGeoMap* map);
	void drawLayer(CGeoLayer* layer);
	//void drawObject(CGeoObject* obj);
	void initVbo(GLfloat* vertex, GLuint* index, GLfloat* color, int size);
	void wheelEvent(QWheelEvent* event) override;
	//��ק���ֵĲ�������
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	//���ڱ仯��������һ�������⣨��Ҫ�޸ģ�
	void resizeEvent(QResizeEvent* e) override;
	
public slots:
	void receiveMapData(CGeoMap* map);

};

