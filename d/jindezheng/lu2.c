// Room: /d/jindezheng/lu1
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
һƬ������,�������˺��һ����Ҷ.��һ��С����Լ��������,ǰ
���ƺ�������һ������.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest":__DIR__"to_qz",
  "northeast" :__DIR__"lu1",
]));
  set("outdoors", "/d/jindezheng");
  setup();
//  replace_program(ROOM);
}
