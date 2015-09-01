#include <QDebug>
#include <QFile>
#include <QTextStream>


int main(int argc, char* argv[]){

	void printError();

	QTextStream out(&file);
	QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return 0;


	if (strcmp(argv[1], "-f") == 0)
	{
		if(argv[2]== NULL || argv[3]==NULL)
			printError();
		else
		{
			qDebug() << "Create file: " << argv[2];
			qDebug() << "Perform " << argv[3];
		}
	}
	else if (strcmp(argv[1], "add") == 0)
	{
		qDebug() << "Perform add on default file";
    	out << "The magic number is: " << 49 << "\n";
	}
	else if (strcmp(argv[1], "list") == 0)
	{
		qDebug() << "Perform list on default file";
	}
	else if (strcmp(argv[1], "do") == 0)
	{
		qDebug() << "Perform do on default file";
	} 
	else
	{
		printError();
	}

	return 0;
}

void printError(){
	qDebug() << "INCORRECT FORMAT!";
	qDebug() << "CORRECT FORMAT: ./todo <-f> <filename> <command> <\'task\'>";
	qDebug() << "CORRECT FORMAT: ./todo <command> <\'task\'>";
}
