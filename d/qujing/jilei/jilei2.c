//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

����ɽ���絶��һ�㣬Ⱥ�������ι�״��Ȯ��������ɽ������
����һ�ɹ�Ũ�ҵ���������������Х���չȻ�����Ұ�޵ĺ�
�����Ѿ��ܽ��ˡ�

LONG);

  set("exits", ([
        "northeast"   : __DIR__"jilei1",
        "south"   : __DIR__"shidong",
      ]));
  set("outdoors", "xy22");

  setup();
}



