// ���ݱ��� /d/city/chuzhou/bei_men.c 
// by lala 1997-12-03

inherit ROOM;
#include <ansi.h>
#include <men.h>

void create()
{
    set("short", CYN"���ݱ���"NOR);
    set("long", @LONG
����λ���ϱ����˺�ͬ��ˮ�Ľ��㴦�����λ��ʮ����Ҫ��ÿ�궼��������
�ֳ̼˴��������������Ϊ����˺ӵı������ܿ�ͷ�չ��Ϊһ����Ҫ����
ҵ���С������ǳ��еı��ţ���౱�����˶��Ǵ�������ǻ��ߴ�������ǵ���
�ڹ���ˮ��ɽ���ġ����ſ��м���ʿ����վ�ڣ������Ե�ʮ����и���������Ϊ
����һ������ս�ҵ�Ե�ʡ��Ŷ��������Ű��ģ������к�����Χ�ۡ�
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
//        "north"    :  "/u/lala/map/diaotai",
        "south"    :  __DIR__"tianbao_lu",
    ]) );
    set("objects", ([
        __DIR__"npc/xiaowei"    :   2,
        __DIR__"npc/shibing1"   :   1,
        __DIR__"npc/shibing2"   :   1,
    ]) );

    
    setup();
}
                               
int valid_leave( object me, string dir )
{
    if( me->query("no_leave_chuzhou")
    && dir == "north" )
        return notify_fail("�����ڲ����뿪���ݡ�\n");
    return ::valid_leave( me, dir );
}
