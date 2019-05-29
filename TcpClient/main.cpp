#include <QtWidgets/QApplication>
//#include "MainWin.h"
#include "TcpClient.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");

	/*MainWin *M=nullptr;
	M = new MainWin();
	M->show();*/

	TcpClient *T = new TcpClient();
	T->show();
	return a.exec();
}
