//create by smile 12/8/98
// room: /d/qujing/baigudong/shanshipo.c

inherit ROOM;

void create ()
{
  set ("short", "ɽʯ��");
  set ("long", @LONG

    �����߳���ɽʯ·�����۶�ȥ��һƬ�����ƽ��ɽ���
����ԶԶ����ɽ�ͣ�ɽ���¶Ȳ������ߵ�ɽ���ﶼ�Ѹ�
�ѣ�����ȷʵ���ȡ�����ɽ���Ͼ����ģ��������գ�����
�ĸ�����,��Լ�������˺�������

LONG);

  set("exits", ([
        "east"  : "/d/qujing/huangfeng/huangfeng8",
        "westdown"       : __DIR__"xiapolu1",
        "northeast"  : __DIR__"sroad7",
      ]));
  set("objects", ([
        __DIR__"obj/baigu"   : 1,
      ]));
  set("outdoors",__DIR__"");

  setup();
}

