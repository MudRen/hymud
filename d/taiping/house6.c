#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���˾�");
        set("long", @LONG
�ſ�ɹ��һ�����������µ��ż������㡣��������·�Ǹ����ˣ���������㣬
����ɹ������仰����������ʱ��ȷ�в�����Ȼ������·�ı��¾��ǣ�ÿ��������
�������ض��飬����Χ���ھ��ۺ첻�ѡ�̫ƽ����Χ������أ�������·�Ļ�˵��
ÿ��һ����͵�����һ����ݲ��С�
LONG
        );
        set("exits", ([ 
        //����ȥ̫ƽ��·����ӵ������·
//                "east" : __DIR__"mroad6",
		"west" : __DIR__"swamp2",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                
        ]));
        set("objects", ([
                __DIR__"npc/fishman": 1,
        ]));
        set("coor/x",-980);
        set("coor/y",150);
        set("coor/z",0);
        setup();
}     
