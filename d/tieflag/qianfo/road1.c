 inherit ROOM;
void create()
{
  set("short","���ش��");
  set("long",@LONG
����һ�������������ֱ�����������������͵����
������һƬ���֣�������һ��ɽ��������ɽ���ؽ硣
LONG
  );
  set("exits",([
         "east" :__DIR__"shanjiao",
         	"west" :"/d/laowu/road2",
               ])); 
        set("outdoors", "qianfo");
  set("coor/x",10);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
} 
