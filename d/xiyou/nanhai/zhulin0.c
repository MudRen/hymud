//Cracked by Roath
// Room: /d/xiyou/nanhai/zhulin.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���Ӻ�ɽ�������֡�Ҳ�ǹ��������������������ڡ�����ϸ�裬
���΢���������ڴˣ�����֮���Ŷ�ʱ������ɢ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"zhulin"+sprintf("%d", random(6)),
  "northwest" : __DIR__"zhulin"+sprintf("%d", random(6)),
  "south" : __DIR__"road4",
]));

  setup();
  replace_program(ROOM);
}