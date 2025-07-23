#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } // forword declaration
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum enPlayer { Player1, Player2 };
    enum enWinner { Player1Win, Player2Win, Draw, GameInProgress };

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;


    struct stGameStatus
    {
        enWinner Winner = GameInProgress;
        bool GameOver = false;
        short PlayCount = 0;
    } GameStatus;

    enPlayer PlayerTurn = Player1;

    void CheckWinner();
    bool CheckValues(QPushButton *btn1, QPushButton *btn2, QPushButton *btn3);
    void EndGame();
    void ResetButton(QPushButton *btn);
    void RestartGame();
    void ChangeTextLabel(QPushButton *btn);

private slots:
    void on_btnRestart_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
};

#endif // MAINWINDOW_H
