// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ�һ���������������䣬���̵��գ���������һЩ�޾����
�Ĺ��ˣ��Լ�����ɢɢ����Ƽ��ݵļ������������ڵ���ؤ��
�����е�Ҳ��̶á�

LONG);

  set("exits", ([
        "north"    : __DIR__"guanmao",
        "south"    : __DIR__"jiedao12",
        "east"    : __DIR__"jiedao6",
        "west"    : __DIR__"shikou",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 1,
      ]));
  set("outdoors", "xy33");
  setup();
}
