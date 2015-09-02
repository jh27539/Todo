#include <QDebug>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QTextStream>
#include <QStringList>

int main(int argc, char* argv[]){

	void printError();

	int numLines = 0;
	QByteArray myList;
	QString inLine;
	QString addLine;


	QFile file("todo.txt");
	QTextStream out(&file);
	if (file.exists())
	{
		if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
			qDebug() << "File exists";
		else
 			qDebug() << "file not open";
	}

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
    	addLine = QString::number(numLines+1);
    	addLine += ":[ ] ";
    	for(int i=2; i<argc; i++)
    	{
    		addLine += argv[i];
    		addLine += " ";
    	}
    	addLine += "\n";
    	out << addLine;
	}
	else if (strcmp(argv[1], "list") == 0)
	{
		qDebug() << "Perform list on default file";
		QString line = file.readLine();
	    while (!file.atEnd())
	    {
	    	qDebug() << line;
	        line = file.readLine();
	    }

	}
	else if (strcmp(argv[1], "do") == 0)
	{
		qDebug() << "Perform do on default file";
		//Find number in QStringArray and modify
	} 
	else printError();	

	return 0;
}

void printError()
{
	qDebug() << "INCORRECT FORMAT!";
	qDebug() << "CORRECT FORMAT: ./todo <-f> <filename> <command> <\'task\'>";
	qDebug() << "CORRECT FORMAT: ./todo <command> <\'task\'>";
}
