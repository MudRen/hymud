// Room: d/kyoto/hongqiao
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "����");
set("long", @LONG
���Ǿ������Ǻ��ϵĺ��ţ����������߲�ʯ�Ƴɣ����Ʋʺ磬�ʳ������ţ�
�Ǿ�������������������һ���ţ�������ߵĲʺ罵���˼䡣������֮ʱ��
��߲ʺ���ӳ�ɻԣ����˷ֲ������˼仹���ɾ���
LONG );
set("exits",  ([
        "north"  : __DIR__"huchenghe2",
        "south"  : __DIR__"huchenghe4",
        "west"  : __DIR__"yusuogate",
        "east"  : __DIR__"juechuan",
      ]));
        setup();
        replace_program(ROOM);
}