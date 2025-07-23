#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("Images/Tic-Tac-Toe-Game-red.png"));

    //Music
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/Music/playground-fun-playful-kids-music-246604.mp3"));


    player->setLoops(QMediaPlayer::Infinite);
    audioOutput->setVolume(50);

    player->play();

      RestartGame();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangeTextLabel(QPushButton *btn)
{
    if (btn->text() == "?") {
        if (PlayerTurn == Player1) {
            btn->setText("X");
            PlayerTurn = Player2;
            ui->lblTurn->setText("Player 2");
        } else {
            btn->setText("O");
            PlayerTurn = Player1;
            ui->lblTurn->setText("Player 1");
        }

        GameStatus.PlayCount++;
        CheckWinner();

        if (GameStatus.PlayCount == 9 && !GameStatus.GameOver) {
            GameStatus.Winner = Draw;
            GameStatus.GameOver = true;
            EndGame();
        }

    } else {
        QMessageBox::information(this, "Wrong Choice", "Choose another one", QMessageBox::Ok);
    }
}

bool MainWindow::CheckValues(QPushButton *btn1, QPushButton *btn2, QPushButton *btn3)
{
    if (btn1->text() != "?" && btn1->text() == btn2->text() && btn1->text() == btn3->text()) {
        btn1->setStyleSheet("background: red;");
        btn2->setStyleSheet("background: red;");
        btn3->setStyleSheet("background: red;");

        if (btn1->text() == "X")
            GameStatus.Winner = Player1Win;
        else
            GameStatus.Winner = Player2Win;

        GameStatus.GameOver = true;
        EndGame();
        return true;
    }
    return false;
}

void MainWindow::CheckWinner()
{
    if (CheckValues(ui->btn1, ui->btn2, ui->btn3)) return;
    if (CheckValues(ui->btn4, ui->btn5, ui->btn6)) return;
    if (CheckValues(ui->btn7, ui->btn8, ui->btn9)) return;
    if (CheckValues(ui->btn1, ui->btn4, ui->btn7)) return;
    if (CheckValues(ui->btn2, ui->btn5, ui->btn8)) return;
    if (CheckValues(ui->btn3, ui->btn6, ui->btn9)) return;
    if (CheckValues(ui->btn1, ui->btn5, ui->btn9)) return;
    if (CheckValues(ui->btn3, ui->btn5, ui->btn7)) return;
}

void MainWindow::EndGame()
{
    ui->lblTurn->setText("Game Over");

    switch (GameStatus.Winner) {
    case Player1Win:
        ui->lblWinner->setText("Player 1 Wins!");
        break;
    case Player2Win:
        ui->lblWinner->setText("Player 2 Wins!");
        break;
    default:
        ui->lblWinner->setText("Draw!");
        break;
    }

    for (QPushButton *btn : { ui->btn1, ui->btn2, ui->btn3, ui->btn4, ui->btn5, ui->btn6, ui->btn7, ui->btn8, ui->btn9 })
        btn->setEnabled(false);
}

void MainWindow::ResetButton(QPushButton *btn)
{
    btn->setText("?");
    btn->setStyleSheet(R"(
        QPushButton {
            border: 2px solid transparent;
            color: #FFFFFF;
            background: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1,
                                        stop:0 #84afe5, stop:1 #1168e4);
        }
    )");
    btn->setEnabled(true);
}

void MainWindow::RestartGame()
{
    for (QPushButton *btn : { ui->btn1, ui->btn2, ui->btn3, ui->btn4, ui->btn5, ui->btn6, ui->btn7, ui->btn8, ui->btn9 })
        ResetButton(btn);

    PlayerTurn = Player1;
    GameStatus = stGameStatus{};
    ui->lblTurn->setText("Player 1");
    ui->lblWinner->setText("In Progress");
}

void MainWindow::on_btnRestart_clicked() { RestartGame(); }
void MainWindow::on_btn1_clicked() { ChangeTextLabel(ui->btn1); }
void MainWindow::on_btn2_clicked() { ChangeTextLabel(ui->btn2); }
void MainWindow::on_btn3_clicked() { ChangeTextLabel(ui->btn3); }
void MainWindow::on_btn4_clicked() { ChangeTextLabel(ui->btn4); }
void MainWindow::on_btn5_clicked() { ChangeTextLabel(ui->btn5); }
void MainWindow::on_btn6_clicked() { ChangeTextLabel(ui->btn6); }
void MainWindow::on_btn7_clicked() { ChangeTextLabel(ui->btn7); }
void MainWindow::on_btn8_clicked() { ChangeTextLabel(ui->btn8); }
void MainWindow::on_btn9_clicked() { ChangeTextLabel(ui->btn9); }
