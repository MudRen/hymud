 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���ׯ��");
        set("long", @LONG
�����ǳ´��ĳ��ׯ�ĺ󷿣��ſڴ��Ű�͸����������������ڰ�������ľ�Σ�
�����輸����ֻ������������š�����������м䲢û�輸��ȴ����һ�ڰ�ͭ��
���裬��ɫ�Ļ��������������衣�´���ϲ������ˮ���ݣ����������Ͽ��ŵ����
���⡣
LONG
        );
        set("exits", ([ 
                "south": __DIR__"silkshop",
        ]));
        set("objects", ([
                __DIR__"npc/bosschen":  1,
        ]) );
        set("coor/x",-1120);
        set("coor/y",200);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
