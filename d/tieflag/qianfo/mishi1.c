 inherit ROOM;
void create()
{
  set("short","�ؾ���");
  set("long",@LONG
����ֻ���飬��ʽ�������飮������
LONG
  );
  set("exits",([
         "south":__DIR__"yezhang.c",
               ]));
          set("objects", ([
                __DIR__"obj/book1" : 1,
                __DIR__"obj/book2" : 1,
                __DIR__"obj/book3" : 1,
                __DIR__"obj/book4" : 1,
                __DIR__"obj/book5" : 1, 
       ]) );
//      create_door("south","ʯ��","north",DOOR_CLOSED);
        set("coor/x",51);
        set("coor/y",2110);
        set("coor/z",30);
        set("refresh_all_items", 1);
        setup();
}   
