// Room: d/kyoto/yuqiao
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "����");
set("long", @LONG
���Ǿ������Ǻ��ϵĽ��ţ��������ɺ������Ƴɣ��ʳ������ţ�������
�Ƶľ��ǣ۾��������ݣ���������ʵ��й����������ž������������ŵ��
�ž�����ͼ�������˲���ȥ�������������յ��黳�����Ǻӻ�������������
�������ľ�����һ���£���ˮ�£ݡ�
LONG );
set("exits",  ([
        "south"  : __DIR__"huchenghe3",
        "north"  : __DIR__"huchenghe1",
        "east"  : __DIR__"yusuogate",
        "west"  : __DIR__"gaoye",
      ]));
        setup();
        replace_program(ROOM);
}