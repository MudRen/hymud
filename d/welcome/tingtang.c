// Room: /d/pingan/tingtang
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
����ǹŴ��ջ�����ã����������ڸ��˵ĳ��Ŷ�������ʱ�в�ȭ����
������������Ķ��䣬�㾪��ķ���������Ȼ̸Ц������ȴ�о�����һ���
��¥���ֳ��ֵ����ա�
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guanshi" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kezhan",
]));
set("roomif","$botten#����:ask guan shi about panzi$#");

  set("pingan", 1);
  set("chatroom",1);
  set("pingan", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);

  setup();
  replace_program(ROOM);
}
