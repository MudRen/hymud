#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", YEL"ͭ��"NOR);
        set("long", @LONG
��ʽ�����ı��������и�ʽ�����İ���������֮������������ɭɭ
�ĺ��⣬���ıڶ��ճ�������ɫ��ǹ����ĳ����ɰˣ���̵ĲŲ�����
�ߣ�������������ľ������С�ľ�������ӡ���ǹ�̽�������������ţ�
������Ȼû��������ȴ�����̺���ɱ�������˵�����ɱ����
    ����֮�£����е���ɱ֮����ֻ�¾����������
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
                __DIR__"npc/maskman_c" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
