import os
import random
import psycopg2

count = 100
sql_path = 'sql'
dbConfig = {
    'host': '127.0.0.1',
    'port': 5432,
    'database': 'CardsView',
    'user': 'postgres',
    'password': 'admin'
}

sqls = []

def loadsqls():
    for filename in os.listdir(sql_path):
        file_path = os.path.join(sql_path, filename)
        if os.path.isfile(file_path):
            with open(file_path, 'r', encoding='utf-8') as file:
                content = file.read()
                sqls.append(content)


def filldb():
    connection = psycopg2.connect(**dbConfig)
    cursor = connection.cursor()

    cursor.execute("DELETE FROM cards_view;")

    sqlsRandomOrder = sqls.copy()
    remainToLoad = count

    while remainToLoad > 0:
        random.shuffle(sqlsRandomOrder)

        if remainToLoad > len(sqlsRandomOrder):
            toLoad = len(sqlsRandomOrder)
        else:
            toLoad = remainToLoad

        for i in range(toLoad):
            sql = sqlsRandomOrder[i]
            cursor.execute(sql)

        remainToLoad -= toLoad

    connection.commit()

    cursor.close()
    connection.close()


if __name__ == '__main__':
    loadsqls()
    filldb()
