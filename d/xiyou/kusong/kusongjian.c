//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "���ɽ�");
  set ("long", @LONG

���ֱ�����һƬС��ʯ�£�������һ��ɽ�����ƺ�����������ˮ
��������������һ��С��ʯ�ţ�Զ���ź���һ���ߵĹ�ʯ�£���
����Ӱ�ܶ���
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"songlin4",
  "north" : __DIR__"guaishiya",
  "east" : __DIR__"qingcao1",
]));
  set("outdoors", "xy14");


  setup();
}

