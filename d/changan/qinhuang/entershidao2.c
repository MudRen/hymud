
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
           "north":__DIR__"entershidao",
           "south":__DIR__"entershidao3",           	
]));
        set("objects", ([
                __DIR__"npc/bairenzhang": 2,  
                __DIR__"npc/qianrenzhang": 1,  

        ]));
        setup();
}


