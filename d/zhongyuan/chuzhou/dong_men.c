// ���ݶ��� /d/city/chuzhou/dong_men.c 
// by lala 1997-12-03

inherit ROOM;
#include <ansi.h>
#include <men.h>

void create()
{
    set("short", CYN"���ݶ���"NOR);
    set("long", @LONG
����λ���ϱ����˺�ͬ��ˮ�Ľ��㴦�����λ��ʮ����Ҫ��ÿ�궼��������
�ֳ̼˴��������������Ϊ����˺ӵı������ܿ�ͷ�չ��Ϊһ����Ҫ����
ҵ���С������ǳ��еĶ��ţ����������ĳ��ţ���������ǵ���Ҫ�ٵö࣬��Ϊ
���˶���û��ʲô��Ҫ�ĳ��У�ֻ��Щ���ߵ�С��壬ż����Щ��˽�������˵�
���ȥ�ʹ��º�����ȴӳ�����ͷ�Ϲ͹ٴ�����ö࣬���Ҳ����ܵ���飬����
��Ϊ�洬һ��Ƚ�С����Զ���Ǻ�Σ�յġ����ſ��м���ʿ����վ�ڣ������Ե�
ʮ����и���������Ϊ����һ������ս�ҵ�Ե�ʡ��Ŷ��������Ű��ģ������к�
����Χ�ۡ�
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "east"     :  "/d/zhongyuan/tulu",
        "west"     :  __DIR__"yanxing_jie",
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
    && dir == "east" )
        return notify_fail("�����ڲ����뿪���ݡ�\n");
    return ::valid_leave( me, dir );
}
