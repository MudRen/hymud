// Room: d/kyoto/heyuanting2.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��ԭ�");
set("long", @LONG
������������ĺ�Դ�������͵������еĵط���������Ǻպ�����
�ļ������磬��˵����Ĵ�ʼ�߼���ѹ���ս��ʱ����������٣��ܺ��绽
�꣬��ʱ�����С����ֻ�ɽ��ս��֮����֮�Ƶ����������Ĵ��󽫡�ƾ��
�ٻ����ް�����������һͳ���е���������������������˲��ܺ��绽��
�����Ծ����������ǰ��Ͷʦѧ���߳�ǧ����
LONG );
set("exits",  ([
        "east"  : __DIR__"heyuanting3",
        "north"  : __DIR__"jitianshenshe",
        "west"  : __DIR__"heyuanting1",
      ]));
        setup();
        replace_program(ROOM);
}