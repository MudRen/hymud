// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽ����һƬ�㳡�����������������������һ���ڣ���ɭɭ��
֪��ʲôȥ���������ɽ���ϳ�����̦�£��Ĵ����ͣ�����
����·�ļ���

LONG);

  set("exits", ([
        "northwest"   : __DIR__"hukou",
        "down"   : __DIR__"shanlu1",
      ]));
  set("outdoors", "xy34");

  setup();
}



