 inherit ROOM;
void create()
{
        object con,item;
        set("short", "������");
        set("long", @LONG
����һ�䴢���ң����߰���Ķ����ѳ���ɽ���������ӹ�������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room6",
  "east" :__DIR__"dating",
]));
    set("objects", ([
      __DIR__"obj/woodcase": 1,
      __DIR__"obj/qidrug" : 1,
  ]) );
      set("coor/x",3260);
        set("coor/y",30);
        set("coor/z",-30);
        setup();
      con = present("woodcase",this_object());
      item = present("bat drug",this_object());
      item->set_amount(3);
      item->move(con);
}  
