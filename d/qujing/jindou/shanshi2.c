// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽʯ��");
  set ("long", @LONG

ɽʯ���Ĵ�����ʯ�飬ʯ��ķ�϶�ﳤ��һЩ�Ӳݡ�·������
Ϊ��ɫ��ɽ�ң�������С�ʯ��ԶԶ�����س���һЩ��������
ɽ����ҡҷ��

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shanshi1",
        "southeast"   : __DIR__"jindou2",
        "southwest"   : __DIR__"shidong",
      ]));
  set("outdoors", "xy17");

  setup();
}

void init()
{
  add_action("do_all", "",1);
}

int do_all(string arg)
{


  if (random(8)==0)
    set("exits/southwest", __DIR__"shidong");
  else
    set("exits/southwest", __DIR__"shanshi1");
  return 0;
}


