
#include <command.h>
inherit ROOM;

void create()
{
        set("short", "�ڹ�ͨ��");
        set("long", @LONG
ͨ�����࣬�Զ���������������ʨ��ⳡ����ա������������
��ʯ����ޣ�����������������ʮ���Զ�ʮ����������������������
����ʹ���������˴�˵���ɽ硣�ڵ����������£���ʯ�޻�׻�����
��η��˪��ѩ��
LONG );

        set("exits", ([
           "north":__DIR__"shidao2",
           "south":__DIR__"entershidao2",           	
]));
        set("objects", ([
                __DIR__"npc/bingshi": 2,  
                __DIR__"npc/bairenzhang": 1,  

        ]));
        setup();
}


