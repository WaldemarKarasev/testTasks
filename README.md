# testTasks
1. cities
1.1. Вид приложения при начальной подгрузке БД cities.db3
![initView](https://github.com/WaldemarKarasev/testTasks/assets/95939606/ad84f276-d74e-4777-9c0f-78a5da41ad65)

1.2. Сортировка по столбцам. Сортируем по столбцу alt
![sortedColumn](https://github.com/WaldemarKarasev/testTasks/assets/95939606/85ae0a36-4ccc-40bc-af69-7ff16fee9e79)

1.3. Изменение параметра в ячейке
![changes](https://github.com/WaldemarKarasev/testTasks/assets/95939606/57701715-5b19-41b8-bc86-30018c596020)

1.4. Вывод отфильтрованных данных
![filtered](https://github.com/WaldemarKarasev/testTasks/assets/95939606/db43ff69-2200-4247-bb69-001c8101d40d)

1.5. Добавление новой строки в БД
![newrow](https://github.com/WaldemarKarasev/testTasks/assets/95939606/9390bc0a-73df-4c90-9fdd-d5480b685b91)


   
2. multithreadedCalc
2.1.1. Индикация вычислений во время имитации вычислений в отдельных потоках
![Screenshot from 2023-08-20 18-30-07](https://github.com/WaldemarKarasev/testTasks/assets/95939606/3f455162-ec05-4b30-b2f4-2f677102f7c6)
2.1.2. Так как в GUI не сильно заметно, что потоки выполняются асинхронно, привожу вывод отладочной информации из консоли
![Screenshot from 2023-08-20 18-32-03](https://github.com/WaldemarKarasev/testTasks/assets/95939606/fb16664d-9968-43af-82ef-e4f3bce0a1e4)

2.2. Завершение имитации вычислений в отдельных потоках
![Screenshot from 2023-08-20 18-30-13](https://github.com/WaldemarKarasev/testTasks/assets/95939606/1f223526-0c42-4c87-b903-d3e2df1ad80f)


   
3. TcpServer
3.1. Вид приложения при отсутствии подключений к серверу
![empty](https://github.com/WaldemarKarasev/testTasks/assets/95939606/4e3a8569-ab12-46e2-9470-3ad02e4b1a02)

3.2. Вид приложения при подключении трех клиентов
![connections](https://github.com/WaldemarKarasev/testTasks/assets/95939606/b2a258fb-cf56-4002-998b-242b20cf23cd)

3.3.1. Вывод сообщений в GUI, полученных от клиентов  
3.3.2. Для тестирования работы сервера была использована утилита nc. 
       Запустим ее в терминале со следующими параметрами:
       nc -v localhost 1234
![terminal](https://github.com/WaldemarKarasev/testTasks/assets/95939606/0939bee9-0d0d-49a5-951c-ae77e6c10288)

3.4. Завершение соединения из терминала
![quitfromterminalgui](https://github.com/WaldemarKarasev/testTasks/assets/95939606/c2eb8788-c2d4-4c38-aec8-e3acd83e7488)
![quitfromterminal](https://github.com/WaldemarKarasev/testTasks/assets/95939606/bd395a24-9bd7-4cf2-be57-5f31e91782a9)

3.5. Принудительное завершение соединения
![forcedquitgui](https://github.com/WaldemarKarasev/testTasks/assets/95939606/750b485d-128d-4af3-b3d9-2f918baba236)
В терминале связь разорвана. Нет возможности передать сообщение на сервер.
![forcedquitterminal](https://github.com/WaldemarKarasev/testTasks/assets/95939606/08656fab-bef0-4e44-af9b-324172df3d33)





