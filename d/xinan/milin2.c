#include <room.h>
inherit ROOM;


void create()
{
        set("short", "����");
        set("long", @LONG
��������ӳ����쳣ï�ܣ����������У����ò���������������ǰ����Ҷ��
֦��ͷ�������ܲ�͸������֣���������ϥ��ĳ��ݣ��������߷��ڲݴ��С�ǰ
��̤����·�ܿ�ͱ��³�����֦Ҷ��ס�ˡ�
    ���ܵ��ó�ܶ࣬��ʱ������Χ���衣
LONG
        );
        set("exits", ([
                "west"     : __DIR__"milin1",
                "east"     : __DIR__"milin2",
                "north"    : __DIR__"milin3",
                "south"    : __DIR__"milin2",
        ]));
        setup();
}
