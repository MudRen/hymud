
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ǰ������һ���������Ʒ����������ɷ����д�š����ء�
������ɫ���֡����������ĸ����������͵������ˡ��Ա�վ
��һ����Ŀ��䣬��̬ΰ���Ľ����ʿ������Ŀ�⾼��������
���㣬������һ�����顣

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 1,
]));
  set("outdoors", "dntg");
  set("magicroom",1);set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"wmj6",
  "north" : __DIR__"donglang",
]));

  setup();
}

int valid_leave(object me, string dir)
{
    if ( dir == "north" && me->query_temp("yaochi_pass") <= 0 )
            return notify_fail("�����صأ��������룡\n");
    if (me->query_temp("yaochi_pass") > 0)
    me->set_temp("yaochi_pass",me->query_temp("yaochi_pass")-1);
  return 1;
}
