// rewritten by snowcat on 4/11/1997
// Room: huoyan

inherit ROOM;

int check_move(object me, string arg);

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

Խ����Խ���������̣����߱�������ɫ��Ļ���ɽ����ҰһƬ���
ɫ�Ļ����������ǿ��÷������ʯ��ɰ����

LONG);

  set("outdoors", "xy21");
  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"huoyan",
  "eastdown" : __DIR__"shalu",
]));

  setup();
}

void init()
{
  add_action("do_all", "",1);
}

int do_all(string arg)
{
    if (this_player()->query("obstacle/firemount")=="done")
      set("exits/westup", __DIR__"nofire");
    else set("exits/westup", __DIR__"huoyan");
    return 0;
}


