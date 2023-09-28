** Никакие файлы из проектов не были удалены, поэтому дополнительные установки в проекты не требуются.

* Установка Drogon.
	Видео: https://www.youtube.com/watch?v=0ojHvu0Is6A
	На моменте установки через vcpkg использовать команды:
		vcpkg install drogon:x64-windows
		vcpkg install jsoncpp:x64-windows zlib:x64-windows openssl:x64-windows sqlite3:x64-windows libpq:x64-windows libpqxx:x64-windows drogon[core,ctl,sqlite3,postgres,orm]:x64-windows
		
		
* Backend-проект.
	Находится в директории backend/, изначально скомпилированный в build/Release/.
	Для компиляции используется VSCode с расширением CMake (сам CMake должен быть установлен в системе).
		Компиляция:
		1) При добавлении новых модулей в проект ввести команды (не обязательно, если новые модули с прошлой компиляции не были добавлены):
			cd build
			cmake ..
		2) В VSCode в нижнем меню выбрать Release-вариант сборки и компилятор в зависимости от архитектуры.
		3) Нажать Build для сборки.
		4) Собраный файл сохранится в build/Release/.
	Адрес и порт сервера, а также настройки подключения к базе данных можно изменить в main.cc.
	Медиа-файлы находятся в build/Release/static/images/.
	
	
* База данных.
	Запросы на создание базы данных и таблицы находятся в source/db.sql.
	Для заполнения базы данных разработано Python-приложение, которое находится в filldb/, в котором можно изменить количество записей на добавление и параметры подключения. Для запуска использовался PyCharm.
	
	
* Frontend-проект.
	Находится в директории frontend/.
	Для сборки Svelte-проекта необходимо выполнить команду: npm run build
	Результат сборки сохраняется в папку build/.

* Связь frontend и backend.
	1) Скопировать все содержимое директории frontend/build/ в backend/build/Release/, кроме файла index.html.
	2) Файл index.html скопировать в backend/views/ под названием CardsView.csp.
	3) В файл CardsView.csp в начало body добавть строчку: 
		<%view StaticHtml.csp %>
	а в начало script добавить:
		<%view StaticJs.csp %>
	4) Собрать Drogon-проект.