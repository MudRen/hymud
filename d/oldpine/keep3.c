 // Room: /d/oldpine/keep3.c
inherit ROOM; 
void create()
{
        set("short", "����կ");
        set("long", @LONG
�����������կ�Ĵ����ˣ������ߵĵ���������һ�ž޴����Ƥ��
��������������ӣ���������ɢ��������ȡů�õĻ��裬������������
ľ���ӣ��Ƚ����ص����������һ����ӣ����������ͷ�ǽ���һ�ַ�
������Ļ�ˮ֮�С�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"keep2",
        ]));
        set("objects", ([
                __DIR__"npc/bandit_leader": 3,
                __DIR__"npc/bandit_commander":1
        ]) ); 
        set("no_clean_up", 0); 
        set("coor/x",600);
        set("coor/y",2350);
        set("coor/z",90);
        setup();
        replace_program(ROOM);
}      
