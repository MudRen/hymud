// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�����ˮ��ܿ���һ����ȥ��ԶԶ���Լ�����Լ�Ķ԰�����
���ǰ��ϵ����֣������Ǻ��棬�ѽ��˺��ı��㣬������
�ش��ţ�����żȻ�ɼ����˻����ߡ�

LONG);

  set("exits", ([
        "north"   : __DIR__"hexi3",
        "east"   : __DIR__"bing3",
        "south"   : __DIR__"hexi5",
      ]));
  set("outdoors", "xy16");

  setup();
}


