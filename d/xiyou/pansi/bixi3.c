// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ϫ");
  set ("long", @LONG

ֻ��������Ϫ�������������졣Ϫˮ��������������������ʯ
�ݡ�Ҳ����Ұ����������Ҳ������¹�����졣�����Ǹ��ɼ�ȥ
�������������Ѱ�õ���

LONG);

  set("exits", ([
        "northwest"    : __DIR__"bixi2",
        "south"    : __DIR__"bixi6",
      ]));
  set("outdoors", "xy27");
  setup();
}

void init ()
{
  object who = this_player();

  who->set_temp("obstacle/pansi_bixi",1);
}
