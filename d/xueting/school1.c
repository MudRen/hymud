// Room: /d/snow/school1.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������ݴ���");
        set("long", @LONG
��������վ��һ���լԺ����ڣ���ֻ�޴��ʯʨ�����ڴ���
�����࣬һ����ߺ���뵶����ײ��������Ժ���д�����ͨ��������
������������������µĺ������ڲ�����
LONG
        );
       set("no_beg",1);
       set("no_sleep_room",1);
       //set(SAFE_ENV, 1);
       set("exits", ([ /* sizeof() == 2 */
       "west" : __DIR__"guangchang_n",
       "east" : __DIR__"school2",
]));
        set("outdoors", "xueting");
        
        set("objects", ([
        	__DIR__"npc/cleaner":1,
                __DIR__"npc/liuanlu": 1 ,
                ]) );
        create_door("east", "�������", "west", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}
