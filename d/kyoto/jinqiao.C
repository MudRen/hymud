 // Room: d/kyoto/jinqiao
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "����");
set("long", @LONG
���Ǿ������Ǻ��ϵĽ��ţ��������ɺ����Ľ�ɫ����ʯ���ɣ�ɢ������
����⣬�յ���������˫�ۣ������ϵ�̾��������ƿ������������Ǻӻ���
�ľ��ǣ۾��������ݣ���������ʵ��й���
LONG );
set("exits",  ([
        "north"  : __DIR__"heyuan1",
        "east"  : __DIR__"huchenghe2",
        "west"  : __DIR__"huchenghe1",
      ]));
        setup();
        replace_program(ROOM);
}