// created by snowcat.c 4/4/1997
// room: /d/nuerguo/xiaolu3.c

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

����һ����ϸ�ֳ���ɽ��С����һ����ߣ�һ����͡�·��
�����ǲ�֪����Ұ��Ұ�ݡ�����ٵ����ţ�����ɽ����һ��
���͡�

LONG);

  set("exits", ([
    "southup"   : __DIR__"xiaolu2",
    "northup"   : __DIR__"xiaolu4",
  ]));


  set("outdoors", "xy18");

  setup();
}






