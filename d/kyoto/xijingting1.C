// Room: d/kyoto/xijingting1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "�����");
set("long", @LONG
���Ǿ�������Ǿ�������Ҫ��ס�����Դ�����ά��֮��ʮ�꣬�����
��������ƽ���Ҹ��������Ҳ���û̶̻��ա�������һ���ӻ��ݣ������
���򵽸�ʽ��������Ʒ�������Ǻ�ԭ���Ǿ����Ľ�ͨ����֮һ��
LONG );
set("exits",  ([
        "north"  : __DIR__"zahuowu",
        "west"  : __DIR__"xijingting2",
        "east"  : __DIR__"heyuan1",
      ]));
        setup();
        replace_program(ROOM);
}