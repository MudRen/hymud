
// �������� /d/city/chuzhou/nanshi.c
// by lala, 1997-12-03

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", GRN"����"NOR);
    set("long", @LONG
�����Ǹ����̾���ʲô�˶����ĵط������ߵĲ�������������һЩ���ˣ���
�Ȳ�֮�࣬˵���żҳ���Ҷ̵ģ�������������Ȥ������Ķĳ����洫��ߺ��
�����Ķ�ɫ��Ѻ��С��������ʮ�ֵ����֡����ϵ���ƽ��ͨ�����ļ�Ժ������
һ�����˵���Ц����������ͨ���еĿ����š�
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "north"     : __DIR__"kuaxiaqiao",
        "west"      : __DIR__"chasi",
        "southeast" : __DIR__"shengping_jie",
//        "southwest" : __DIR__"duchang",
    ]));
    set("objects", ([
        __DIR__"npc/xunbu"  :   1,
        __DIR__"npc/south_seller" + random(5) : 1,
        __DIR__"npc/south_seller" + random(5) : 1,
        __DIR__"npc/south_seller" + random(5) : 1,        
    ]));
    setup();
}
