#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include "ui_simpleGIS.h"
#include "docParser.h"
#include "addODSDialog.h"
#include "qopenglfunctions.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = Q_NULLPTR);
	//ȫ�ֱ��� 
	CGeoMap* map;

private:
	Ui::MainWindow* ui;
	//�Ի���
	addODSDialog* ods_dialog = new addODSDialog();
	MyOpenGLWidget* mapWidget;
private slots:
	void action_geojson_J();//��JSON�ļ�������Ӧ�Ĳۺ���
	void action_Shape_S();//��shape�ļ�������Ӧ�Ĳۺ���
	void action_postgis_P();//��postgis�ļ�������Ӧ�Ĳۺ���
	void receive_ods_data(QString obs_path, QString layer_name);
signals:
	void emitMapData(CGeoMap* map);
};
