#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", BLK"����"NOR);
        set("long", @LONG
�������ر���ر�ߣ��ıڿտգ�ʲôҲû�У�һ����վ����
�棬�ͺ���վ�ڿ�Ұ���Ƶġ�������տ�����ɭ���������룬������
��վ���������ã����߲Ұ�ɫ�����ã�����ӵ����һ�����˵�Ѫ��
�ѻ����������������������������Ű��������Ͼ�Ȼ������Щ��ī��
��ᡣ
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
                __DIR__"npc/maskman_i" : 1,
                __DIR__"obj/table" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}    
