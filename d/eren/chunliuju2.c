 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ش����");
        set("long", @LONG
����һ���������������͵��˺󷿡�������ĳ���ܼ��ӣ�����һ����齺�һ
��������Ͷ������ˣ��ıڶ�����ܣ���Ҳ���������ġ�����϶����������ʮ��
������ҩ����ҩ�䣬��ҽ�ڽ���������Ƶ��ھ���������ũ���ݾ��������˺��ۡ���
������Ҫ�ԡ���Ӧ�о��С�
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"chunliuju1",
        ]));
        set("objects", ([
        "/d/huanghe/yyd/npc/gaiyiming":1,
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
