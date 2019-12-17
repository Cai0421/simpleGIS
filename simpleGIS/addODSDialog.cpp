#include "addODSDialog.h"

addODSDialog::addODSDialog(QWidget* parent)
	:QDialog(parent)
{
	this->resize(400, 400);
	//ȷ�ϰ�ť
	QPushButton* ok_button = new QPushButton(tr("&OK"));
	QVBoxLayout* v_main_layout = new QVBoxLayout;
	//�û�
	QHBoxLayout* h1_layout = new QHBoxLayout;
	QLabel* user_label = new QLabel();
	user_label->setText(QStringLiteral("�û�"));
	user_lineEdit = new QLineEdit();
	h1_layout->addWidget(user_label, 1);
	h1_layout->addWidget(user_lineEdit, 3);
	//����
	QHBoxLayout* h2_layout = new QHBoxLayout;
	QLabel* password_label = new QLabel();
	password_label->setText(QStringLiteral("����"));
	password_lineEdit = new QLineEdit();
	h2_layout->addWidget(password_label, 1);
	h2_layout->addWidget(password_lineEdit, 3);
	//�˿�
	QHBoxLayout* h3_layout = new QHBoxLayout;
	QLabel* port_label = new QLabel();
	port_label->setText(QStringLiteral("�˿�"));
	port_lineEdit = new QLineEdit();
	h3_layout->addWidget(port_label, 1);
	h3_layout->addWidget(port_lineEdit, 3);
	//����
	QHBoxLayout* h4_layout = new QHBoxLayout;
	QLabel* db_label = new QLabel();
	db_label->setText(QStringLiteral("���ݿ�"));
	db_lineEdit = new QLineEdit();
	h4_layout->addWidget(db_label, 1);
	h4_layout->addWidget(db_lineEdit, 3);
	//ͼ����
	QHBoxLayout* h5_layout = new QHBoxLayout;
	QLabel* layer_label = new QLabel();
	layer_label->setText(QStringLiteral("����"));
	layer_lineEdit = new QLineEdit();
	h5_layout->addWidget(layer_label, 1);
	h5_layout->addWidget(layer_lineEdit, 3);

	v_main_layout->addLayout(h1_layout);
	v_main_layout->addLayout(h2_layout);
	v_main_layout->addLayout(h3_layout);
	v_main_layout->addLayout(h4_layout);
	v_main_layout->addLayout(h5_layout);
	v_main_layout->addWidget(ok_button);
	this->setLayout(v_main_layout);

	//Ĭ���ı�
	this->user_lineEdit->setText( QString("postgres"));
	this->password_lineEdit->setText(QString("19990421391614"));
	this->port_lineEdit->setText(QString("5432"));
	this->db_lineEdit->setText(QString("Geo_shp"));
	this->layer_lineEdit->setText(QString("bou2_4p"));
	this->password_lineEdit->setEchoMode(QLineEdit::Password);
	//��ť�ź����Ӳ���
	this->connect(ok_button, SIGNAL(clicked()), this, SLOT(ok_button_triggered()));
}

void addODSDialog::ok_button_triggered()
{
	//��ȡÿ���ı���������ľ�����������

	QString user = this->user_lineEdit->text();
	QString passord = this->password_lineEdit->text();
	QString port = this->port_lineEdit->text();
	QString db = this->db_lineEdit->text();
	QString layer = this->layer_lineEdit->text();
	//obs_path����
	QString obs_path = "PG:dbname=" + db +
		" host=localhost" + " port=" + port +
		" user=" + user +
		" password=" + passord;
	//�źŴ���
	emit emit_ods_settings(obs_path, layer);
}

