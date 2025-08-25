#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget ventana;
    ventana.setWindowTitle("Calculadora Simple");

    // Layout principal
    QVBoxLayout *layoutPrincipal = new QVBoxLayout(&ventana);

    // Campos de texto
    QHBoxLayout *layoutNum1 = new QHBoxLayout();
    QLabel *label1 = new QLabel("Primer número:");
    QLineEdit *input1 = new QLineEdit();
    layoutNum1->addWidget(label1);
    layoutNum1->addWidget(input1);

    QHBoxLayout *layoutNum2 = new QHBoxLayout();
    QLabel *label2 = new QLabel("Segundo número:");
    QLineEdit *input2 = new QLineEdit();
    layoutNum2->addWidget(label2);
    layoutNum2->addWidget(input2);

    // Botones
    QHBoxLayout *layoutBotones = new QHBoxLayout();
    QPushButton *btnSuma = new QPushButton("Sumar");
    QPushButton *btnResta = new QPushButton("Restar");
    QPushButton *btnMultiplicacion = new QPushButton("Multiplicar");
    layoutBotones->addWidget(btnSuma);
    layoutBotones->addWidget(btnResta);
    layoutBotones->addWidget(btnMultiplicacion);

    // Resultado
    QLabel *resultado = new QLabel("Resultado: ");

    // Agregar todo al layout principal
    layoutPrincipal->addLayout(layoutNum1);
    layoutPrincipal->addLayout(layoutNum2);
    layoutPrincipal->addLayout(layoutBotones);
    layoutPrincipal->addWidget(resultado);

    // Conectar botones
    QObject::connect(btnSuma, &QPushButton::clicked, [&](){
        double num1 = input1->text().toDouble();
        double num2 = input2->text().toDouble();
        resultado->setText("Resultado: " + QString::number(num1 + num2));
    });

    QObject::connect(btnResta, &QPushButton::clicked, [&](){
        double num1 = input1->text().toDouble();
        double num2 = input2->text().toDouble();
        resultado->setText("Resultado: " + QString::number(num1 - num2));
    });

    QObject::connect(btnMultiplicacion, &QPushButton::clicked, [&](){
        double num1 = input1->text().toDouble();
        double num2 = input2->text().toDouble();
        resultado->setText("Resultado: " + QString::number(num1 * num2));
    });

    ventana.show();
    return app.exec();
}
