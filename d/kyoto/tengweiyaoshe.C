// Room: d/kyoto/tengweiyaoshe
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��βҩ��");
set("long", @LONG
������һ�����ֺŵ�ҩ�磬��β��������ս��ʱ�ڵ���ҽ��ҽ������
�ഫ�������ϰ���β��һ���������ֵ�������������ҩ����Ҳ��������
ҩƷ����ϣ�����������Ǯ��ʲô��ҩ�����򵽡������ϰ���β��һ��
���������ѣ�����кõ�ҩ�ģ�������൱���˵ļ�Ǯ�����һ������һ
Щ��Ϊ��֪�Ľ������ܡ�
LONG );
set("exits",  ([
        "south"  : __DIR__"qianbending5",
      ]));
        setup();
        replace_program(ROOM);
}