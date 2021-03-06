/**
 * 剧本 bucket 编辑器类
 */

#ifndef DIALOGUEEDITOR_H
#define DIALOGUEEDITOR_H

#include <QObject>
#include <QWidget>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QFileDialog>
#include <QSettings>
#include <QPainter>
#include "dialoguebucket.h"
#include "qsshighlighteditor.h"

class DialogueEditor : public QWidget
{
    Q_OBJECT
public:
    DialogueEditor(QWidget *parent = nullptr);

    void initView();
    void initStyle();
    void setBucket(QList<DialogueBucket*>buckets, DialogueBucket* bucket);

    void setDataDir(QString dir);

private:
    QSize getAvatarSize(QSize size);

signals:
    void signalDelete();
    void signalSaveToFile();
    void signalSaveFigure(DialogueBucket* bucket);

public slots:
    void focusSaid();

private:
    QString data_dir;
    DialogueBucket* current_bucket = nullptr; // 正在编辑的 bucket
    QList<DialogueBucket*> selected_buckets; // 选中（包括正在编辑）的bucket

    QPushButton *avatar_btn;
    QPushButton *circle_btn, *rounded_btn;
    QLabel *name_label, *said_label, *style_label;
    QPlainTextEdit *said_edit;
    QSSHighlightEditor *style_edit;
    QLineEdit *name_edit;
    QCheckBox *name_check;

    QPushButton *save_figure_button;
    QPushButton *export_picture_button;
    QPushButton *delete_bucket_button;

    bool _loading_bucket = false;
};

#endif // DIALOGUEEDITOR_H
