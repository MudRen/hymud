#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "������"); 
        set("long", @LONG
�����ڵľ��������þ޴����ľ�ǳɵģ���Ȼ�ֲڼ�ª��ȴ������ԭʼ�Ĵ���
���ӣ���������һ�������������׳���ơ��������Ҳһ����Ұ�������������ͣ�
�����Ǻ��ʱ��Ұ�ޡ�
LONG); 
        set("type","street");
    set("coor/x",200);
    set("coor/y",-230);
    set("coor/z",80);
        set("exits",([
                "westdown":__DIR__"andao2",
                "northdown":__DIR__"shanlu4",
        ]) );
        set("objects",([
                __DIR__"npc/gui":1,
                __DIR__"npc/ding_xi":1,
                __DIR__"npc/wang_ruo_lan":1,
                ]) ); 
        setup();
        create_door("westdown", "ľǽ", "eastup", DOOR_CLOSED);
}       
