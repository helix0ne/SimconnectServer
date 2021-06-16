#include "../mainwindow.h"
#include "../ui_mainwindow.h"
#include "common/dataIdentifiers.h"

void MainWindow::newIncomingConnection()
{
    ui->clearFpButton->setDisabled(false);
    ui->readNewFpButton->setDisabled(false);

    tcpSocket->abort();

    tcpSocket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);
    tcpSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
    tcpSocket = tcpServer.nextPendingConnection();
    tcpSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);

    tcpServer.pauseAccepting();

    connect(tcpSocket, &QTcpSocket::disconnected, this, &MainWindow::clientDisconnected, Qt::UniqueConnection);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::receivedDataFromClient, Qt::UniqueConnection);

    setClientConnectionState(ConnectionState::CONNECTED);

    DataIdentifiers id = DataIdentifiers::SIMCONNECT_SERVER;
    tcpSocket->write(reinterpret_cast<char *>(&id), sizeof(id));
}