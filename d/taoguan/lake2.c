 inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
��ˮ�峺͸������ʱ���Կ�����β������ˮ�档��ˮ��ͷ
��һ�����ٲ�����������������ٲ���ɽ��ֱ����£�������
�������������ϡϡ�����վ�ż������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "west" : __DIR__"grassland2",
                "south" : __DIR__"lake1",
]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/reg_taoist" : 2,
                __DIR__"npc/shan" : 1,
                
]));
        set("resource/water",1);
        set("liquid", (["container":"��"]));
        set("outdoors", "taoguan");
        set("coor/x",-10);
        set("coor/y",2080);
        set("coor/z",80);
        setup();
}   
