// zhujiangong.c
// pian


inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������ѩͤ����������һֻ�޴������¯�������룬������
һ��һ�ң�����һֻһ�˶�ߵķ��䡣¯�еĻ������ŷ���Ľ���
�����š����������������������Ŵ���һ�Ѿ����ý���Ҳ��һԲ��
������Ľ����Ρ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"sstreet1",
]));
//        set("objects", ([
//                __DIR__"npc/foreman": 1,
//                __DIR__"npc/obj/crate": 3,
//        ]));
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}
