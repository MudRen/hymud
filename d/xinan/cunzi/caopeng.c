//Writen by lnwm
//caopeng.c

inherit ROOM;

void create()
{
    set("short", "С����");
    set("long", @LONG
·����ʱ���С�����Ϊɽ�ﳣ�����꣬���Դ����Ǿʹ������
С���ӡ��������죬����;�������һ��������Ļ�е����ɽ��һ�ߴ��
�������м���������������ˣ��һ���ӻ���������Ъ�š�
LONG
    );
    set("exits", ([
        "west"      :    __DIR__ "lroad4",
        ]));
    set("objects", ([           
         __DIR__ "npc/xiaofan" : 1,
    ]) );
    set("outdoors","lnwm");
    setup();
}


