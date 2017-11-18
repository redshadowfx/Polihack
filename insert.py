import pymysql
import sys
nr = sys.argv[1]
temp = sys.argv[2]

conn = pymysql.connect(host = "localhost", user = "test", password = "12345", db = "listapacienti")
myCursor = conn.cursor()

myCursor.execute("INSERT INTO `temperaturi`(`ID`, `Temperatura`, `Data Inregistrarii`) VALUES ("+ nr + ","+ temp +",CURRENT_TIMESTAMP)")


conn.commit()
conn.close()
