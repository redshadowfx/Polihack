import pymysql
import sys
date = sys.argv

#print(date[1] + " " + date[2] + " " + date[3])

conn = pymysql.connect(host = 'localhost', user = 'test', password = '12345', db = 'listapacienti')
cur = conn.cursor()

cur.execute("INSERT INTO `pacienti`(`Nume`, `Prenume`, `CNP`, `NumeDoctor`, `PrenumeDoctor`, `emailDoctor`, `telefonDoctor`) VALUES ('"+ date[1] + "','"+ date[2] +"'," +date[3]+",'"+date[4]+"','"+date[5]+"','"+date[6]+"',"+date[7]+")")
conn.commit()
conn.close()
