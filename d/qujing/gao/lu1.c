// gate.c

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

·���˲��Ǻܶ࣬ż���м������ͣ�ǰ����һ��С��������
һ�������˼ң�ȴ���ⷽԲ�������ص����ˣ�������ũ����
�ǿ���߼ҵ�����գ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu2",
  "north" : "/d/qujing/heifeng/shanlu1",
]));
  set("outdoors", "xy5");

  setup();
}
