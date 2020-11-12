#ifndef POID_H
#define POID_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class poid; }
QT_END_NAMESPACE

class poid : public QWidget
{
    Q_OBJECT

public:
    poid(QWidget *parent = nullptr);
    ~poid();

private slots:
    void on_pushButton_suite_clicked();


    void on_pushButton_deivne_clicked();

    void on_pushButton_lorentz_clicked();

    void on_pushButton_sansage_clicked();

private:
    void formulDevine();
    void formulLorentz();
    void formulLorentzAge();

    void afficherInfos();

    double poids;
    double taille;
    QString nom;
    QString prenom;
    int age;
    static const int NBIMC=6;
    static const int NBCORPULENCE=7;
    Ui::poid *ui;
};
#endif // POID_H
