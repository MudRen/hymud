// Room: d/kyoto/jitianshenshe
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��������");
set("long", @LONG
������Ǻպ������ļ������磬��˵����Ĵ�ʼ�߼���ѹ���ս��ʱ��
��������٣��ܺ��绽�꣬��ʱ�����С����ֻ�ɽ��ս��֮����֮�Ƶ�����
�����Ĵ��󽫡�ƾ���ٻ����ް�����������һͳ���е�����������������
������˲��ܺ��绽�꣬���Ծ����������ǰ��Ͷʦѧ���߳�ǧ������
�ڷ���һ�Ѿ�ʯ�����顰��Ե�������ĸ����֣����Ҹ������ĸ���ľ������
����������ž��ĺ����ġ�

LONG );
set("exits",  ([
        "south"  : __DIR__"heyuanting2",
      ]));
        setup();
        replace_program(ROOM);
}