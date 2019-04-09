#include <stdio.h>
#include <X11/Xlib.h>

int main()
 {
  Display *ourDisplay;

  ourDisplay=XOpenDisplay(NULL);
  if (ourDisplay==NULL)
    {
      printf("Не удалось установить соединение с графическим терминалом.\n");
      return 1;
    };

  /* Получим предварительные сведения */
  int ourScreen=DefaultScreen(ourDisplay);          // Экран по-умолчанию
int rootWindow=RootWindow(ourDisplay, ourScreen); // Корневое окно
 int bgcolor=WhitePixel(ourDisplay, ourScreen);    // Белый цвет экрана

  /* Открываем окно */
int  myWindow=XCreateSimpleWindow(ourDisplay,rootWindow,100, 100, 320, 200,
    0, 0, bgcolor);

  /* Делаем окно видимым */
  XMapWindow(ourDisplay, myWindow);

  /* Все сформированные команды принудительно сбрасываем на сервер */
  XFlush(ourDisplay);

  getchar();
  /* Спим */

  /* Уничтожаем окно */
  XDestroyWindow(ourDisplay, myWindow);

  /* Закрываем соединение с сервером */
  XCloseDisplay(ourDisplay);

  return 0;
 };
