// rewritten by snowcat on 4/11/1997
// Room: south3

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

������ɽ�ţ���·ʮ����Ţ���Ӳݴ����������Ǵ���ɽ����������һ
��Сɽ����ǻ���ɽ��

LONG);

  set("exits", ([
        "northeast" : __DIR__"xiaomiao",
        "south"     : __DIR__"cuiyun5",
        "northup"   : __DIR__"south2",
      ]));


  set("outdoors", "xy21");

  setup();
}
