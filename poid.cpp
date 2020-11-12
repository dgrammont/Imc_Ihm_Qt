#include "poid.h"
#include "ui_poid.h"
#include <QDebug>

poid::poid(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::poid)
{
    ui->setupUi(this);
     ui->tabWidget->setTabEnabled(1,false);
}

poid::~poid()
{
    delete ui;
}



void poid::on_pushButton_suite_clicked()
{
    afficherInfos();
    ui->tabWidget->setTabEnabled(1,true);
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->widget(1)->setVisible(true);

}

void poid::formulDevine()
{

    double poidsIdeal = 0;
    double ecart =0;
    if (ui->radioButton_femme->isChecked()) {

        poidsIdeal = 45.5 + 2.3 * ( ui->doubleSpinBox_taille->value() / 0.0254 - 60.0);
    }
    if (ui->radioButton_homme->isChecked()) {

        poidsIdeal = 50.0 + 2.3 * (ui->doubleSpinBox_taille->value() / 0.0254 - 60.0);
    }
    if (poidsIdeal > 0) {
        ui->textEdit->append("\nVotre poids ideal avec la formule de devine : " + QString::number(poidsIdeal) + " kg\n");
         ecart = ui->doubleSpinBox_poid->value()-poidsIdeal;
        if (ecart >= 0) {
          ui->textEdit->append("\nVous devez perdre "+QString::number(ecart)+" kg\n");
        }
        else {
          ui->textEdit->append("\nVous devez prendre "+QString::number(-ecart)+" kg\n");
        }
    }
    qDebug() << poidsIdeal;

}

void poid::formulLorentz()
{
    double poidsIdeal =0;
    double ecart =0;
    if (ui->radioButton_femme->isChecked()) {

        poidsIdeal = ui->doubleSpinBox_taille->value() *100 - 100 - (ui->doubleSpinBox_taille->value() *100 -150)/2.5;
    }
    if (ui->radioButton_homme->isChecked()) {

         poidsIdeal = ui->doubleSpinBox_taille->value() *100 - 100 - (ui->doubleSpinBox_taille->value() *100 -150)/4;
    }
    if (poidsIdeal > 0) {
        ui->textEdit->append("\nVotre poids ideal avec la formule de Lorentz : " + QString::number(poidsIdeal) + " kg\n");
         ecart = ui->doubleSpinBox_poid->value()-poidsIdeal;
        if (ecart >= 0) {
          ui->textEdit->append("\nVous devez perdre "+QString::number(ecart)+" kg\n");
        }
        else {
          ui->textEdit->append("\nVous devez prendre "+QString::number(-ecart)+" kg\n");
        }
    }

}

void poid::formulLorentzAge()
{
    double poidsIdeal =0;
    double ecart =0;


        poidsIdeal = 50+(ui->doubleSpinBox_taille->value() *100 - 150)/4 + (ui->spinBox_age->value() -20)/4;

        if (poidsIdeal > 0) {
            ui->textEdit->append("\nVotre poids ideal avec la formule de Lorentz en prenez compte de l'age : " + QString::number(poidsIdeal) + " kg\n");
             ecart = ui->doubleSpinBox_poid->value()-poidsIdeal;
            if (ecart >= 0) {
              ui->textEdit->append("\nVous devez perdre "+QString::number(ecart)+" kg\n");
            }
            else {
              ui->textEdit->append("\nVous devez prendre "+QString::number(-ecart)+" kg\n");
            }
        }


}


void poid::afficherInfos()
{
   double imcs[NBIMC] = {16.5, 18.5, 25, 30, 35, 40};
   QString corpulences[NBCORPULENCE] = {"Famine", "Maigreur", "Normale", "Surpoids", "Obésité modérée", "Obésité sévère", "Obésité morbide"};
   double imc=0;
   nom = ui->lineEdit_nom->text();
   prenom = ui->lineEdit_prenom->text();
   poids = ui->doubleSpinBox_poid->value();
   taille = ui->doubleSpinBox_taille->value();
   age = ui->spinBox_age->value();

   imc = poids/(taille * taille);

   ui->textEdit->setText("Bonjour "+prenom+" "+nom);
   ui->textEdit->append("Votre indice de masse corporel est de : "+QString::number(imc));
   int indiceCorpulence = 0;
   for (int i = 0; i < NBIMC - 1; i++) {
       if (imc > imcs[i] && imc <= imcs[i + 1]) {
           indiceCorpulence = i + 1;
       }
   }
   // cas extreme
   if (imc < 16.5) {
       indiceCorpulence = 0;
   }
   if (imc > 40) {
      indiceCorpulence = NBCORPULENCE - 1;
   }

   ui->textEdit->append("votre corpulence est de categorie : "+ corpulences[indiceCorpulence]);
}

void poid::on_pushButton_deivne_clicked()
{

    formulDevine();
}

void poid::on_pushButton_lorentz_clicked()
{
    formulLorentz();
}

void poid::on_pushButton_sansage_clicked()
{
    formulLorentzAge();
}
