// Room: d/kyoto/gaoye
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��Ұ");
set("long", @LONG
����һ�������ĵ�·�ϣ�һ�������շ����ģ������й��ݣ���һ������
���������ľ�����һ���£���ˮ�£ݡ��������徲֮�����Ų�Զ�ľ��룬��
��ȴ����ʱ�ձ�������һ����������ã��

LONG );
set("exits",  ([
        "west"  : __DIR__"qingshuisi",
        "east"  : __DIR__"yuqiao",
      ]));
        setup();
        replace_program(ROOM);
}